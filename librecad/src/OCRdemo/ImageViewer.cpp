//#include "ImageViewer.h"
//
//ImageViewer::ImageViewer(QWidget *parent)
//	: QWidget(parent)
//{
//	ui.setupUi(this);
//}
//
//ImageViewer::~ImageViewer()
//{}

#include "ImageViewer.h"
#include <QDir>
#include <QPixmap>
#include <QFileInfo>
#include <QDebug>
#include<QDirIterator>
#include <QDate>
ImageViewer::ImageViewer(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    currentIndex = -1;
    rotationAngle = 0;

    // 设置默认路径为程序目录下的 NG_Pictures 文件夹
    QString appDir = QCoreApplication::applicationDirPath();
    rootPath = appDir + "/NG_Pictures";  // 根路径设为 NG_Pictures
    currentPath = rootPath;
    //currentPath = "./NG_Pictures";

    // 检查 NG_Pictures 文件夹是否存在
    if (!QDir(currentPath).exists()) {
        qWarning() << "The NG_Pictures folder does not exist at:" << currentPath;
        currentPath = appDir;  // 如果不存在，则使用程序目录
    }

    // 初始化 QFileSystemModel，并绑定到 QTreeView
    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(currentPath);  // 设置根路径
    // 显示所有文件夹和文件
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    fileModel->setNameFilters(QStringList() << "*.bmp");  // 只显示 .bmp 文件

    // 将模型绑定到 QTreeView，并设置 NG_Pictures 作为根路径
    ui.treeView->setModel(fileModel);
    ui.treeView->setRootIndex(fileModel->index(currentPath));

    // 只显示文件名列，隐藏其他列（例如：大小、类型、修改时间等）
    ui.treeView->setColumnHidden(1, true);  // 隐藏大小列
    ui.treeView->setColumnHidden(2, true);  // 隐藏类型列
    ui.treeView->setColumnHidden(3, true);  // 隐藏修改时间列

    // 排序：按修改时间降序排列（最新在上面）
    ui.treeView->sortByColumn(3, Qt::DescendingOrder);  // 按第 3 列（修改时间）降序排序

    // 更新图片列表，包含所有子文件夹中的图片
    updateImageList(currentPath);

    // 连接信号与槽
    connect(ui.treeView, &QTreeView::clicked, this, &ImageViewer::onDirectoryChanged);
    connect(ui.toolButton_2, &QToolButton::clicked, this, &ImageViewer::showPreviousImage);
    connect(ui.toolButton_4, &QToolButton::clicked, this, &ImageViewer::showNextImage);
    connect(ui.toolButton_3, &QToolButton::clicked, this, &ImageViewer::rotateImage);
    connect(ui.toolButton_5, &QToolButton::clicked, this, &ImageViewer::hide);
    connect(ui.toolButton, &QToolButton::clicked, this, &ImageViewer::goUpOneLevel);

    SetQSS();
}

ImageViewer::~ImageViewer()
{
    //delete fileModel;
}

void ImageViewer::SetQSS()
{
    setWindowFlags(Qt::WindowSystemMenuHint);
    setWindowTitle(QString::fromLocal8Bit("查看图像记录 "));
    this->setFixedSize(921, 621);

    ui.label->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
    ui.label_2->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
}

// 文件夹或图片选择的槽函数
void ImageViewer::onDirectoryChanged(const QModelIndex& index) {
    QString path = fileModel->filePath(index);
    QFileInfo fileInfo(path);

    if (fileInfo.isDir()) {
        // 如果是目录，更新路径并刷新图片列表
        if (!path.startsWith(rootPath)) {
            qWarning() << "Access denied: Cannot navigate outside of NG_Pictures.";
            return;  // 禁止导航到根目录以上
        }
        // 更新当前路径，并刷新图片列表
        currentPath = path;
        updateImageList(currentPath);
        ui.treeView->setRootIndex(fileModel->index(path));
    }
    else if (fileInfo.suffix().toLower() == "bmp") {
        // 加载图片
        loadImage(path);
        //qDebug() << "Last Modified:" << fileInfo.lastModified().toString(Qt::ISODate);
        ui.label_2->setText(fileInfo.lastModified().toString(Qt::ISODate));
    }
}

// 加载并显示图片
void ImageViewer::loadImage(const QString& path) {
    QPixmap pixmap;
    if (pixmap.load(path)) {
        originalPixmap = pixmap;  // 保存原始图片
        rotationAngle = 0;  // 每次加载新图片时重置旋转角度

        // 显示图片，并保持比例
        ui.label->setPixmap(pixmap.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        currentIndex = imageList.indexOf(path);
    }
    else {
        ui.label->setText("Failed to load image.");
    }
}

// 更新图片列表
void ImageViewer::updateImageList(const QString& folderPath) {
    imageList.clear();  // 清空之前的图片列表

    // 使用 QDirIterator 递归遍历所有子文件夹中的 .bmp 文件
    QDirIterator it(folderPath, QStringList() << "*.bmp",
        QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        imageList << it.next();
    }

    currentIndex = -1;  // 重置图片索引
}

// 显示上一张图片
void ImageViewer::showPreviousImage() {
    if (currentIndex > 0) {
        --currentIndex;
        loadImage(imageList[currentIndex]);

        QFileInfo fileInfo(imageList[currentIndex]);
        ui.label_2->setText(fileInfo.lastModified().toString(Qt::ISODate));
    }
}

// 显示下一张图片
void ImageViewer::showNextImage() {
    if (currentIndex < imageList.size() - 1) {
        ++currentIndex;
        loadImage(imageList[currentIndex]);

        QFileInfo fileInfo(imageList[currentIndex]);
        ui.label_2->setText(fileInfo.lastModified().toString(Qt::ISODate));
    }
}

// 旋转图片
void ImageViewer::rotateImage() {
    if (originalPixmap.isNull()) return;  // 检查图片是否有效

    // 增加旋转角度，并确保角度在 0 到 360 度之间
    rotationAngle = (rotationAngle + 90) % 360;

    // 使用 QTransform 旋转图片
    QPixmap rotatedPixmap = originalPixmap.transformed(QTransform().rotate(rotationAngle));

    // 将旋转后的图片显示在 QLabel 中，并保持比例
    ui.label->setPixmap(rotatedPixmap.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

// 返回上一级目录
void ImageViewer::goUpOneLevel() {
    QDir dir(currentPath);

    // 检查是否已经到达根路径，禁止返回到更高的路径
    if (currentPath == rootPath) {
        //qWarning() << "Already at the root directory. Cannot go up.";
        return;  // 不执行任何操作
    }

    // 返回上一级目录
    if (dir.cdUp()) {
        currentPath = dir.absolutePath();
        updateImageList(currentPath);
        ui.treeView->setRootIndex(fileModel->index(currentPath));
    }
}