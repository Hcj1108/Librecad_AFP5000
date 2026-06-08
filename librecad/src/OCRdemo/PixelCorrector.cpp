#include "pixelcorrector.h"
#include <QDebug>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

// 构造函数实现
PixelCorrector::PixelCorrector(const QVector<QPointF>& modelCoords,//模型坐标点(像素坐标系中的参考点)
    const QVector<QPointF>& modelMmCoords,      //模型坐标对应的实际物理坐标(mm)
    const QVector<QPointF>& pixelCoords,        //像素坐标系中的测量点   实际像素坐标与模型一致
    const QVector<QPointF>& measuredMmCoords)   //测量得到的实际物理坐标(mm)
{
    // 验证输入点数量
    if (modelCoords.size() != 9 || modelMmCoords.size() != 9 ||
        pixelCoords.size() != 9 || measuredMmCoords.size() != 9) {
        throw std::invalid_argument("所有输入点集必须包含9个点");
    }

    // 转换QVector<QPointF>到Eigen矩阵
    auto toEigenMatrix = [](const QVector<QPointF>& pts) {
        Eigen::MatrixXd mat(pts.size(), 2);
        for (int i = 0; i < pts.size(); ++i) {
            mat(i, 0) = pts[i].x();
            mat(i, 1) = pts[i].y();
        }
        return mat;
    };

    Eigen::MatrixXd model_mat = toEigenMatrix(modelCoords);
    Eigen::MatrixXd model_mm_mat = toEigenMatrix(modelMmCoords);
    Eigen::MatrixXd pixel_mat = toEigenMatrix(pixelCoords);
    Eigen::MatrixXd measured_mm_mat = toEigenMatrix(measuredMmCoords);

    // 拟合仿射变换
    affine_params = fitAffine(model_mm_mat, model_mat);

    // 应用仿射变换计算测量坐标
    measured_coords = applyAffine(measured_mm_mat);

    // 初始化网格（3x3）- 核心修正：X方向误差取反
    int grid_indices[3][3] = { {0,1,2}, {3,4,5}, {6,7,8} };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int idx = grid_indices[i][j];
            pixel_x(i, j) = pixel_mat(idx, 0);
            pixel_y(i, j) = pixel_mat(idx, 1);

            // 修正X方向误差计算符号（原来是pixel - measured，现在改为measured - pixel）
            delta_x(i, j) = measured_coords(idx, 0) - pixel_mat(idx, 0);
            delta_y(i, j) = pixel_mat(idx, 1) - measured_coords(idx, 1);
        }
    }

    // 提取网格轴
    grid_x = Eigen::Vector3d(measured_coords(0, 0), measured_coords(1, 0), measured_coords(2, 0));
    grid_y = Eigen::Vector3d(measured_coords(0, 1), measured_coords(3, 1), measured_coords(6, 1));

    // 验证网格
    validateGrid();
}

// 仿射变换拟合实现
Eigen::Matrix<double, 2, 3> PixelCorrector::fitAffine(const Eigen::MatrixXd& src_pts,
    const Eigen::MatrixXd& dst_pts)
{
    if (src_pts.rows() != dst_pts.rows() || src_pts.rows() < 3) {
        throw std::invalid_argument("源点和目标点数量必须相同且至少为3个");
    }

    // 数据归一化，解决数值范围差异导致的偏差
    Eigen::Vector2d src_mean = src_pts.colwise().mean();
    Eigen::Vector2d dst_mean = dst_pts.colwise().mean();

    Eigen::MatrixXd src_centered = src_pts.rowwise() - src_mean.transpose();
    Eigen::MatrixXd dst_centered = dst_pts.rowwise() - dst_mean.transpose();

    // 计算缩放因子（使用自定义中位数计算）
    double src_scale = calculateMedianScale(src_centered);
    double dst_scale = calculateMedianScale(dst_centered);

    const double epsilon = 1e-9;
    if (src_scale < epsilon) src_scale = 1.0;
    if (dst_scale < epsilon) dst_scale = 1.0;

    // 归一化处理
    src_centered /= src_scale;
    dst_centered /= dst_scale;

    int n = src_pts.rows();
    Eigen::MatrixXd A(2 * n, 6);
    Eigen::VectorXd b(2 * n);

    for (int i = 0; i < n; ++i) {
        double x = src_centered(i, 0);
        double y = src_centered(i, 1);
        double u = dst_centered(i, 0);
        double v = dst_centered(i, 1);

        A.row(2 * i) << x, y, 1, 0, 0, 0;
        A.row(2 * i + 1) << 0, 0, 0, x, y, 1;
        b(2 * i) = u;
        b(2 * i + 1) = v;
    }

    // 使用SVD求解，提高数值稳定性
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeFullU | Eigen::ComputeFullV);

    // 应用正则化处理
    double threshold = svd.singularValues()(0) * 1e-6;
    Eigen::VectorXd params = svd.solve(b);

    // 过滤小奇异值的影响
    for (int i = 0; i < svd.singularValues().size(); ++i) {
        if (svd.singularValues()(i) < threshold) {
            params -= svd.matrixV().col(i) * (svd.matrixV().col(i).transpose() * params);
        }
    }

    // 反归一化参数
    Eigen::Matrix<double, 2, 3> affine;
    affine << params[0] * dst_scale / src_scale,
        params[1] * dst_scale / src_scale,
        dst_mean[0] - (params[0] * dst_scale / src_scale * src_mean[0] +
            params[1] * dst_scale / src_scale * src_mean[1]) + params[2] * dst_scale,

        params[3] * dst_scale / src_scale,
        params[4] * dst_scale / src_scale,
        dst_mean[1] - (params[3] * dst_scale / src_scale * src_mean[0] +
            params[4] * dst_scale / src_scale * src_mean[1]) + params[5] * dst_scale;

    return affine;
}

// 计算基于中位数的缩放因子
double PixelCorrector::calculateMedianScale(const Eigen::MatrixXd& matrix)
{
    // 将矩阵转换为一维数组
    Eigen::VectorXd vec = matrix.array().square();
    std::vector<double> values(vec.data(), vec.data() + vec.size());

    // 排序并计算中位数
    std::sort(values.begin(), values.end());
    int n = values.size();

    if (n % 2 == 0) {
        return std::sqrt((values[n / 2 - 1] + values[n / 2]) / 2.0);
    }
    else {
        return std::sqrt(values[n / 2]);
    }
}

// 应用仿射变换（单个点，内部参数）
Eigen::Vector2d PixelCorrector::applyAffine(const Eigen::Vector2d& pt) const
{
    return applyAffineWithParams(pt, affine_params);
}

// 应用仿射变换（点集，内部参数）
Eigen::MatrixXd PixelCorrector::applyAffine(const Eigen::MatrixXd& pts) const
{
    Eigen::MatrixXd result(pts.rows(), 2);
    for (int i = 0; i < pts.rows(); ++i) {
        Eigen::Vector2d pt = pts.row(i);
        result.row(i) = applyAffine(pt);
    }
    return result;
}

// 应用仿射变换（单个点，外部参数）
Eigen::Vector2d PixelCorrector::applyAffineWithParams(const Eigen::Vector2d& pt,
    const Eigen::Matrix<double, 2, 3>& params) const
{
    return Eigen::Vector2d(
        params(0, 0) * pt.x() + params(0, 1) * pt.y() + params(0, 2),
        params(1, 0) * pt.x() + params(1, 1) * pt.y() + params(1, 2)
    );
}

// 修正双线性插值函数，确保网格使用正确
double PixelCorrector::bilinearInterpolation(const Eigen::Matrix3d& delta, double x, double y) const
{
    // 确保grid_x是单调递增的
    Eigen::Vector3d sorted_x = grid_x;
    std::sort(sorted_x.data(), sorted_x.data() + 3);

    // 确保grid_y是单调递增的
    Eigen::Vector3d sorted_y = grid_y;
    std::sort(sorted_y.data(), sorted_y.data() + 3);

/*
    grid_x: 8856.06   32767 56677.9
    grid_y : 57956.1   32767  7577.9

    sorted_x: 8856.06   32767 56677.9
    sorted_y : 7577.9  32767  57956.1


*/




    // 查找x所在区间
    int i = (x < sorted_x[1]) ? 0 : 1;
    // 查找y所在区间
    int j = (y < sorted_y[1]) ? 0 : 1;

    // 获取网格点坐标
    double x0 = sorted_x[i], x1 = sorted_x[i + 1];
    double y0 = sorted_y[j], y1 = sorted_y[j + 1];

    // 防止除零
    if (std::fabs(x1 - x0) < 1e-9 || std::fabs(y1 - y0) < 1e-9) {
        return delta(j, i);
    }

    // 计算插值权重（与Python的scipy.interpolate.RegularGridInterpolator保持一致）
    double wx = (x - x0) / (x1 - x0);
	qDebug() << "wx:" << wx;
    double wy = (y - y0) / (y1 - y0);
	qDebug()  << "wy:" << wy;


    // 双线性插值
    double q00 = delta(j, i);
    qDebug() << "q00"<<q00;
    double q01 = delta(j, i + 1);
    qDebug() << "q01" << q01;
    double q10 = delta(j + 1, i);
    qDebug() << "q10" << q10;
    double q11 = delta(j + 1, i + 1);
    qDebug() << "q11" << q11;

    double qx0 = q00 * (1 - wx) + q01 * wx;
	qDebug() << "qx0" << qx0;
    double qx1 = q10 * (1 - wx) + q11 * wx;
	qDebug() << "qx1" << qx1;

    return qx0 * (1 - wy) + qx1 * wy;
}

// 单个点补偿
// 修改补偿函数，确保与Python逻辑一致
// 修改补偿函数，反转X方向误差应用
QPointF PixelCorrector::compensatePoint(double x, double y) const
{
    double dx, dy;

	qDebug() << "dx" << dx;
    qDebug() << "dy" << dx;
    // 计算点到直线x=32767和y=32767的距离
    double dist_x = std::fabs(x - 32767.0)*0.4/32767;
    double dist_y = (std::fabs(y - 32767.0)+100)*1.2/32767;

    qDebug() << "dist_y " << dist_x;
    qDebug() << "dist_x" << dist_y;


    //double scale_factorY = dist_x / 32767;
    //double scale_factorX = dist_y / 32767;

    
    
    // 计算误差（保持与Python相同的插值逻辑）
    dx = bilinearInterpolation(delta_x, x, y)* dist_y;


    dy = bilinearInterpolation(delta_y, x, y)* dist_x;



    qDebug() << "dx" << dx;
    qDebug() << "dy" << dx;



    // 关键修正：Y方向也使用减法而非加法（与Python版本完全对齐）
    // 与Python版本公式保持一致：
    // x_cmd = target_x - delta_x
    // y_cmd = target_y - delta_y
    return QPointF(x - dx, y - dy);
}
// 多个点补偿
//QVector<QPointF> PixelCorrector::compensatePoints(const QVector<QPointF>& points) const
//{
//    QVector<QPointF> result;
//    for (const auto& pt : points) {
//        result.append(compensatePoint(pt.x(), pt.y()));
//    }
//    return result;
//}

// 检查点顺序是否符合3x3网格
bool PixelCorrector::checkPointOrder(const QVector<QPointF>& pts, bool isPixel) const
{
    // 检查点是否按3x3网格排列
    if (pts.size() != 9) return false;

    // 简单检查：中间点是否为(32767, 32767)
    if (!isApproxEqual(pts[4].x(), 32767) || !isApproxEqual(pts[4].y(), 32767)) {
        return false;
    }

    return true;
}

// 判断两个值是否近似相等
bool PixelCorrector::isApproxEqual(double a, double b, double eps) const
{
    return std::fabs(a - b) < eps;
}

// 验证网格合理性
void PixelCorrector::validateGrid() const
{
    // 检查网格X坐标范围
    if (grid_x.maxCoeff() - grid_x.minCoeff() < 1000) {
        qWarning() << "网格X坐标范围异常，可能导致插值错误";
    }

    // 检查网格Y坐标范围
    if (grid_y.maxCoeff() - grid_y.minCoeff() < 1000) {
        qWarning() << "网格Y坐标范围异常，可能导致插值错误";
    }

    // 检查误差范围
    double max_dx = delta_x.array().abs().maxCoeff();
    if (max_dx > 2000) {
        qWarning() << QString("X方向误差过大(%1)，可能存在计算错误").arg(max_dx);
    }
}


// 多个路径补偿 - 原地修改输入路径中的点
void PixelCorrector::compensatePoints(QVector<QVector<QPoint>>& inputPaths) const
{
    // 遍历所有路径
    for (auto& path : inputPaths) {
        // 遍历路径中的每个点
        for (auto& point : path) {
            // 将QPoint转换为double类型以进行补偿计算
            double x = static_cast<double>(point.x());
            double y = static_cast<double>(point.y());


			qDebug() << QString::fromLocal8Bit("补偿前点坐标: (%1, %2)").arg(x).arg(y);
            // 应用补偿算法
            QPointF compensatedPoint = compensatePoint(x, y);
			qDebug() << QString::fromLocal8Bit("补偿后点坐标: (%1, %2)")
				.arg(compensatedPoint.x(), 0, 'f', 2)
				.arg(compensatedPoint.y(), 0, 'f', 2);
            // 将补偿后的点坐标转换回QPoint并更新
            point.setX(static_cast<int>(std::round(compensatedPoint.x())));
            point.setY(static_cast<int>(std::round(compensatedPoint.y())));



        }
    }
}