#include "sample.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QDebug>
#include <QMap>
#include <QDir>
#include <QFileInfo>
#include <cmath>

#include "DLL.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
void processImage(const QString& input_path, const QString& output_dir, DLL& ocrDll) {
    auto start_time = std::chrono::high_resolution_clock::now();

    // 使用Qt加载图像
    QImage qImage(input_path);
    if (qImage.isNull()) {
        qDebug() << "Failed to load image:" << input_path;
        return;
    }

    // 转换为OpenCV格式
    cv::Mat image;
    if (qImage.format() == QImage::Format_RGB888) {
        image = cv::Mat(qImage.height(), qImage.width(), CV_8UC3,
            const_cast<uchar*>(qImage.bits()),
            static_cast<size_t>(qImage.bytesPerLine()));
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    }
    else {
        QImage converted = qImage.convertToFormat(QImage::Format_RGB888);
        image = cv::Mat(converted.height(), converted.width(), CV_8UC3,
            const_cast<uchar*>(converted.bits()),
            static_cast<size_t>(converted.bytesPerLine()));
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    }

    // === 直接对完整图像进行OCR处理 ===
    ocrDll.GetOcr(
        image,  // 使用完整图像
        &ocrDll.detection_results,
        &ocrDll.num_detection_results,
        &ocrDll.recognition_results,
        &ocrDll.num_recognition_results
    );

    // 处理识别结果
    cv::Mat result_image = image.clone();
    QStringList recognized_numbers;
    QSet<QString> displayed_results;

    for (int i = 0; i < ocrDll.num_detection_results; ++i) {
        if (!ocrDll.detection_results[i]->boxes.empty()) {
            const auto& box = ocrDll.detection_results[i]->boxes[0];
            std::vector<cv::Point> points;
            for (size_t j = 0; j < box.size(); j += 2) {
                // 直接使用检测框的全局坐标（无需ROI偏移）
                points.emplace_back(box[j], box[j + 1]);
            }

            // 绘制检测框（绿色）
            for (size_t j = 0; j < points.size(); ++j) {
                cv::line(result_image, points[j], points[(j + 1) % points.size()],
                    cv::Scalar(0, 255, 0), 2);
            }

            // 显示识别结果（红色数字）
            if (i < ocrDll.num_recognition_results) {
                std::string text = ocrDll.recognition_results[i]->text;
                QString number;
                for (char c : text) {
                    if (isdigit(c)) number += c;
                }
                if (!number.isEmpty() && !displayed_results.contains(number)) {
                    recognized_numbers.append(number);
                    displayed_results.insert(number);
                    cv::putText(result_image, number.toStdString(), points[0] - cv::Point(0, 10),
                        cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 0, 255), 2);
                }
            }
        }
    }

    // 保存结果图
    QFileInfo fileInfo(input_path);
    QString output_filename = "result_" + fileInfo.fileName();
    QString output_path = QDir(output_dir).filePath(output_filename);

    if (!cv::imwrite(output_path.toStdString(), result_image)) {
        qDebug() << "Failed to save result image:" << output_path;
    }

    // 输出处理信息
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    qDebug() << "Processed:" << fileInfo.fileName()
        << "| Numbers:" << recognized_numbers.join(" ")
        << "| Time:" << duration.count() << "ms";
}







namespace EntityParam {
    const int START = 0;
    const int END = 1;
    const int CENTER = 2;
    const int RADIUS = 3;
    const int STARTANGLE = 4;
    const int ENDANGLE = 5;
}

static inline double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// LC_Sample 类实现
QString LC_Sample::name() const {
    return tr("Sample plugin");
}

PluginCapabilities LC_Sample::getCapabilities() const {
    PluginCapabilities pluginCapabilities;
    pluginCapabilities.menuEntryPoints << PluginMenuLocation("plugins_menu", tr("Sample plugin"));
    return pluginCapabilities;
}

QMap<QString, QVector<QVector<QPointF>>> LC_Sample::getAllEntitiesPaths(Document_Interface* doc) const {
    QMap<QString, QVector<QVector<QPointF>>> allPaths;
    if (doc) {
        allPaths.insert("Lines", getEntityPaths(doc, "Line"));
        allPaths.insert("Circles", getEntityPaths(doc, "Circle"));
        allPaths.insert("Arcs", getEntityPaths(doc, "Arc"));
    }
    return allPaths;
}

QVector<QVector<QPointF>> LC_Sample::getEntityPaths(Document_Interface* doc, const QString& entityType) const {
    QVector<QVector<QPointF>> paths;
    if (!doc) return paths;

    QList<Plug_Entity*> entities;
    bool success = doc->getAllEntities(&entities, false);
    if (!success) return paths;

    foreach(Plug_Entity * entity, entities) {
        if (!entity) continue;

        QVector<QPointF> path;
        QHash<int, QVariant> data;
        entity->getData(&data);


        for (auto it = data.begin(); it != data.end(); ++it) {
            qDebug() << "   Key:" << it.key() << ", Value:" << it.value();
        }


        if (entityType == "Line" && data.contains(EntityParam::START) && data.contains(EntityParam::END)) {
            path << data.value(EntityParam::START).toPointF() << data.value(EntityParam::END).toPointF();
        }
        else if (entityType == "Circle" && data.contains(EntityParam::CENTER) && data.contains(EntityParam::RADIUS)) {
            path = generateCirclePath(data.value(EntityParam::CENTER).toPointF(),
                data.value(EntityParam::RADIUS).toDouble());
        }
        else if (entityType == "Arc" && data.contains(EntityParam::CENTER) && data.contains(EntityParam::RADIUS) &&
            data.contains(EntityParam::STARTANGLE) && data.contains(EntityParam::ENDANGLE)) {
            path = generateArcPath(data.value(EntityParam::CENTER).toPointF(),
                data.value(EntityParam::RADIUS).toDouble(),
                data.value(EntityParam::STARTANGLE).toDouble(),
                data.value(EntityParam::ENDANGLE).toDouble());
        }

        if (!path.isEmpty()) paths.append(path);
        delete entity;
    }

    qDebug() << QString::fromLocal8Bit("[调试] 请求实体类型:") << entityType;


    success = doc->getAllEntities(&entities, false);
    qDebug() << QString::fromLocal8Bit("[调试] 获取实体成功:") << success << QString::fromLocal8Bit(", 总数:") << entities.size();



    return paths;
}

QVector<QPointF> LC_Sample::generateCirclePath(const QPointF& center, double radius, int segments) {
    QVector<QPointF> path;
    if (radius <= 0) return path;

    const double angleStep = 2 * M_PI / segments;
    for (int i = 0; i <= segments; ++i) {
        double angle = i * angleStep;
        path.append(QPointF(center.x() + radius * cos(angle), center.y() + radius * sin(angle)));
    }
    return path;
}

QVector<QPointF> LC_Sample::generateArcPath(const QPointF& center, double radius,
    double startAngle, double endAngle, int segments) {
    QVector<QPointF> path;
    if (radius <= 0) return path;

    startAngle = degreesToRadians(startAngle);
    endAngle = degreesToRadians(endAngle);
    if (startAngle > endAngle) std::swap(startAngle, endAngle);

    const double angleStep = (endAngle - startAngle) / segments;
    for (int i = 0; i <= segments; ++i) {
        double angle = startAngle + i * angleStep;
        path.append(QPointF(center.x() + radius * cos(angle), center.y() + radius * sin(angle)));
    }
    return path;
}

void LC_Sample::execComm(Document_Interface* doc, QWidget* parent, QString cmd) {
    lc_Sampledlg dlg(parent);
    if (dlg.exec() == QDialog::Accepted) {


        if (cmd == "GET_ALL_ENTITIES") {
            dlg.getAllEntitiesAction(doc);
        }
        else {
            dlg.processAction(doc);


        }
    }







}

// lc_Sampledlg 类实现 ,点击后出现的对话框
lc_Sampledlg::lc_Sampledlg(QWidget* parent) : QDialog(parent) {
    setWindowTitle(tr("Draw line"));
    QGridLayout* mainLayout = new QGridLayout(this);

    mainLayout->addWidget(new QLabel(tr("Start X:")), 0, 0);
    startxedit = new QLineEdit();
    startxedit->setValidator(new QDoubleValidator());
    mainLayout->addWidget(startxedit, 1, 0);

    mainLayout->addWidget(new QLabel(tr("Start Y:")), 0, 1);
    startyedit = new QLineEdit();
    startyedit->setValidator(new QDoubleValidator());
    mainLayout->addWidget(startyedit, 1, 1);

    mainLayout->addWidget(new QLabel(tr("End X:")), 2, 0);
    endxedit = new QLineEdit();
    endxedit->setValidator(new QDoubleValidator());
    mainLayout->addWidget(endxedit, 3, 0);

    mainLayout->addWidget(new QLabel(tr("End Y:")), 2, 1);
    endyedit = new QLineEdit();
    endyedit->setValidator(new QDoubleValidator());
    mainLayout->addWidget(endyedit, 3, 1);

    QPushButton* acceptbut = new QPushButton(tr("Accept"));
    QPushButton* cancelbut = new QPushButton(tr("Cancel"));
    mainLayout->addWidget(acceptbut, 4, 0);
    mainLayout->addWidget(cancelbut, 4, 1);

    connect(cancelbut, &QPushButton::clicked, this, &QDialog::reject);
    connect(acceptbut, &QPushButton::clicked, this, &lc_Sampledlg::checkAccept);

    readSettings();
}

lc_Sampledlg::~lc_Sampledlg() {
    writeSettings();
}

void lc_Sampledlg::processAction(Document_Interface* doc) {
    if (!doc) return;

    //QPointF start(startxedit->text().toDouble(), startyedit->text().toDouble());
    //QPointF end(endxedit->text().toDouble(), endyedit->text().toDouble());
    //doc->addLine(&start, &end);

    //QPointF p1(0, 0);
    //QPointF p2(0, 65500);
    //QPointF p3(65500, 65500);
    //QPointF p4(65500, 0);

    //// 添加左边
    //doc->addLine(&p1, &p2);
    //// 添加上边
    //doc->addLine(&p2, &p3);
    //// 添加右边
    //doc->addLine(&p3, &p4);
    //// 添加下边
    //doc->addLine(&p4, &p1);

    try {
        // 记录总开始时间
        auto total_start_time = std::chrono::high_resolution_clock::now();

        // 1. 初始化DLL
        DLL ocrDll;

        // 2. 设置输入输出目录
        QString input_dir = "../input2";
        QString output_dir = "../result2";

        // 创建输出目录
        QDir outDir(output_dir);
        if (!outDir.exists() && !outDir.mkpath(".")) {
            qDebug() << "Failed to create output directory:" << output_dir;
            return;
        }

        // 3. 获取所有BMP文件
        QDir inputDir(input_dir);
        QStringList bmp_files = inputDir.entryList({ "*.bmp" }, QDir::Files);
        if (bmp_files.isEmpty()) {
            qDebug() << "No BMP files found in input directory!";
            return;
        }

        qDebug() << "Found" << bmp_files.size() << "BMP files to process.";

        // 4. 处理每个文件
        int processed_count = 0;
        for (const QString& file : bmp_files) {
            QString filePath = inputDir.filePath(file);
            processImage(filePath, output_dir, ocrDll);
            processed_count++;
        }

        // 5. 统计信息
        auto total_end_time = std::chrono::high_resolution_clock::now();
        auto total_duration = std::chrono::duration_cast<std::chrono::milliseconds>(total_end_time - total_start_time);

        qDebug() << "\nProcessing completed!";
        qDebug() << "Total files processed:" << processed_count << "/" << bmp_files.size();
        qDebug() << "Total processing time:" << total_duration.count() << "ms";
        qDebug() << "Average time per image:"
            << (processed_count > 0 ? total_duration.count() / processed_count : 0)
            << "ms";
    }
    catch (const std::exception& e) {
        qDebug() << "Error:" << e.what();
    }



}

void lc_Sampledlg::getAllEntitiesAction(Document_Interface* doc) {
    if (!doc) {
        QMessageBox::warning(this, tr("Error"), tr("Invalid document"));
        return;
    }

    LC_Sample plugin;
    QMap<QString, QVector<QVector<QPointF>>> allPaths = plugin.getAllEntitiesPaths(doc);

    // 创建详细路径信息字符串
    QString detailedInfo;
    QTextStream stream(&detailedInfo);

    stream << QString::fromLocal8Bit("========== 实体路径详情 ==========\n\n");

    // 遍历所有实体类型
    for (auto typeIt = allPaths.begin(); typeIt != allPaths.end(); ++typeIt) {
        stream << QString::fromLocal8Bit("实体类型: ") << typeIt.key() << "\n";
        stream << QString::fromLocal8Bit("数量: ") << typeIt.value().size() << "\n";

        // 遍历该类型的所有实体
        for (int i = 0; i < typeIt.value().size(); ++i) {
            stream << QString::fromLocal8Bit("  实体 ") << i + 1 << ":\n";

            // 打印该实体的所有点
            const QVector<QPointF>& path = typeIt.value()[i];
            for (int j = 0; j < path.size(); ++j) {
                stream << QString::fromLocal8Bit("    点 ") << j + 1 << ": ("
                    << QString::number(path[j].x(), 'f', 2) << ", "
                    << QString::number(path[j].y(), 'f', 2) << ")\n";
            }
        }
        stream << "--------------------------------\n";
    }

    // 在控制台打印
    qDebug().noquote() << detailedInfo;



    // 在消息框中显示(截断过长的内容)
    if (detailedInfo.length() > 1000) {
        detailedInfo = detailedInfo.left(1000) + "\n...\n(内容过长，已截断)";
    }

    QMessageBox::information(this, tr("实体路径详情"), detailedInfo);
}

void lc_Sampledlg::checkAccept() {
    errmsg.clear();
    if (failGUI(&errmsg)) {
        QMessageBox::critical(this, tr("Sample plugin"), errmsg);
        return;
    }
    accept();
}

bool lc_Sampledlg::failGUI(QString* msg) {
    if (startxedit->text().isEmpty()) { msg->append(tr("Start X is empty")); return true; }
    if (startyedit->text().isEmpty()) { msg->append(tr("Start Y is empty")); return true; }
    if (endxedit->text().isEmpty()) { msg->append(tr("End X is empty")); return true; }
    if (endyedit->text().isEmpty()) { msg->append(tr("End Y is empty")); return true; }
    return false;
}

QVector<QPointF> lc_Sampledlg::generateLinePath(const QPointF& start, const QPointF& end) const {
    return { start, end };
}

void lc_Sampledlg::readSettings() {
    QSettings settings("LibreCAD", "sample_plugin");
    resize(settings.value("size", QSize(430, 140)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    startxedit->setText(settings.value("startx", "0.5").toString());
    startyedit->setText(settings.value("starty", "0.5").toString());
    endxedit->setText(settings.value("endx", "3.5").toString());
    endyedit->setText(settings.value("endy", "3.5").toString());
}

void lc_Sampledlg::writeSettings() {
    QSettings settings("LibreCAD", "sample_plugin");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.setValue("startx", startxedit->text());
    settings.setValue("starty", startyedit->text());
    settings.setValue("endx", endxedit->text());
    settings.setValue("endy", endyedit->text());
}

void lc_Sampledlg::closeEvent(QCloseEvent* event) {
    writeSettings();
    QDialog::closeEvent(event);
}