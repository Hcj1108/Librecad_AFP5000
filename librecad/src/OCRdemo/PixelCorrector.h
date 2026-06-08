#ifndef PIXELCORRECTOR_H
#define PIXELCORRECTOR_H

#include <QVector>
#include <QPointF>
#include <Eigen/Dense>

class PixelCorrector
{
public:
    // 构造函数
    PixelCorrector(const QVector<QPointF>& modelCoords,
        const QVector<QPointF>& modelMmCoords,
        const QVector<QPointF>& pixelCoords,
        const QVector<QPointF>& measuredMmCoords);

    // 点补偿函数
    QPointF compensatePoint(double x, double y) const;
    QVector<QPointF> compensatePoints(const QVector<QPointF>& points) const;

    // 获取网格数据（调试用）
    Eigen::Matrix3d deltaX() const { return delta_x; }
    Eigen::Matrix3d deltaY() const { return delta_y; }
    Eigen::Matrix3d pixelX() const { return pixel_x; }
    Eigen::Matrix3d pixelY() const { return pixel_y; }

public:
    // 仿射变换相关
    Eigen::Matrix<double, 2, 3> fitAffine(const Eigen::MatrixXd& src_pts,
        const Eigen::MatrixXd& dst_pts);
    Eigen::Vector2d applyAffine(const Eigen::Vector2d& pt) const;
    Eigen::MatrixXd applyAffine(const Eigen::MatrixXd& pts) const;
    Eigen::Vector2d applyAffineWithParams(const Eigen::Vector2d& pt,
        const Eigen::Matrix<double, 2, 3>& params) const;

    // 插值相关
    double bilinearInterpolation(const Eigen::Matrix3d& delta, double x, double y) const;
    double calculateMedianScale(const Eigen::MatrixXd& matrix);

    // 辅助函数
    bool checkPointOrder(const QVector<QPointF>& pts, bool isPixel) const;
    bool isApproxEqual(double a, double b, double eps = 1e-6) const;
    void validateGrid() const;

    void compensatePoints(const QVector<QVector<QPoint>>& inputPaths, QVector<QVector<QPointF>>& optimizedPaths) const;

	void compensatePoints(QVector<QVector<QPoint>>& inputPaths)const; 

    // 成员变量
    Eigen::Matrix<double, 2, 3> affine_params;  // 仿射变换参数
    Eigen::MatrixXd measured_coords;            // 测量坐标

    // 3x3网格数据
    Eigen::Matrix3d delta_x;  // X方向误差网格
    Eigen::Matrix3d delta_y;  // Y方向误差网格
    Eigen::Matrix3d pixel_x;  // X方向像素坐标网格
    Eigen::Matrix3d pixel_y;  // Y方向像素坐标网格

    Eigen::Vector3d grid_x;   // X方向网格轴
    Eigen::Vector3d grid_y;   // Y方向网格轴
};

#endif // PIXELCORRECTOR_H
