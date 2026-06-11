#include "ImageViewer.h"
#include <QDir>
#include <QPixmap>
#include <QFileInfo>
#include <QDirIterator>
#include <QCloseEvent>
#include <QHeaderView>
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

/**
 * @brief 构造函数
 *
 * 初始化图片查看器：
 * - 设置 NG_Pictures 目录为根路径
 * - 初始化文件系统模型绑定到 QTreeView
 * - 配置标准系统标题栏（含关闭按钮）
 */
ImageViewer::ImageViewer(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // 设置默认路径
    QString appDir = QCoreApplication::applicationDirPath();
    rootPath = appDir + "/NG_Pictures";
    currentPath = rootPath;

    if (!QDir(currentPath).exists()) {
        qWarning() << "NG_Pictures folder not found at:" << currentPath;
        currentPath = appDir;
    }


    // 文件系统模型
    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(currentPath);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    fileModel->setNameFilters(QStringList() << "*.bmp");

    ui.treeView->setModel(fileModel);
    ui.treeView->setRootIndex(fileModel->index(currentPath));
    // 隐藏大小、类型、修改时间列，只保留文件名
    ui.treeView->setColumnHidden(1, true);
    ui.treeView->setColumnHidden(2, true);
    ui.treeView->setColumnHidden(3, true);
    // 按修改时间降序
    ui.treeView->sortByColumn(3, Qt::DescendingOrder);

    updateImageList(currentPath);

    // 信号连接
    connect(ui.treeView, &QTreeView::clicked, this, &ImageViewer::onDirectoryChanged);
    connect(ui.btnPrev, &QToolButton::clicked, this, &ImageViewer::showPreviousImage);
    connect(ui.btnNext, &QToolButton::clicked, this, &ImageViewer::showNextImage);
    connect(ui.btnRotate, &QToolButton::clicked, this, &ImageViewer::rotateImage);
    connect(ui.btnClose, &QToolButton::clicked, this, &ImageViewer::hide);
    connect(ui.btnUp, &QToolButton::clicked, this, &ImageViewer::goUpOneLevel);

    // 窗口样式
    setWindowTitle(QString::fromLocal8Bit("\xb2\xe9\xbf\xb4\xcd\xbc\xcf\xf1\xbc\xc7\xc2\xbc"));
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
}

ImageViewer::~ImageViewer() = default;

void ImageViewer::closeEvent(QCloseEvent* event)
{
    this->hide();
    emit showmain();
    event->ignore();
}

void ImageViewer::onDirectoryChanged(const QModelIndex& index)
{
    QString path = fileModel->filePath(index);
    QFileInfo fileInfo(path);

    if (fileInfo.isDir()) {
        if (!path.startsWith(rootPath)) {
            qWarning() << "Access denied: outside NG_Pictures.";
            return;
        }
        currentPath = path;
        updateImageList(currentPath);
        ui.treeView->setRootIndex(fileModel->index(path));
    }
    else if (fileInfo.suffix().toLower() == "bmp") {
        loadImage(path);
        ui.labelInfo->setText(fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
    }
}

void ImageViewer::loadImage(const QString& path)
{
    QPixmap pixmap;
    if (pixmap.load(path)) {
        originalPixmap = pixmap;
        rotationAngle = 0;
        ui.labelImage->setPixmap(
            pixmap.scaled(ui.labelImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        currentIndex = imageList.indexOf(path);
    }
}

void ImageViewer::updateImageList(const QString& folderPath)
{
    imageList.clear();
    QDirIterator it(folderPath, QStringList() << "*.bmp",
        QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        imageList << it.next();
    }
    currentIndex = -1;
}

void ImageViewer::showPreviousImage()
{
    if (currentIndex > 0) {
        --currentIndex;
        loadImage(imageList[currentIndex]);
        QFileInfo fi(imageList[currentIndex]);
        ui.labelInfo->setText(fi.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
    }
}

void ImageViewer::showNextImage()
{
    if (currentIndex < imageList.size() - 1) {
        ++currentIndex;
        loadImage(imageList[currentIndex]);
        QFileInfo fi(imageList[currentIndex]);
        ui.labelInfo->setText(fi.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
    }
}

void ImageViewer::rotateImage()
{
    if (originalPixmap.isNull()) return;

    rotationAngle = (rotationAngle + 90) % 360;
    QPixmap rotated = originalPixmap.transformed(QTransform().rotate(rotationAngle));
    ui.labelImage->setPixmap(
        rotated.scaled(ui.labelImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ImageViewer::goUpOneLevel()
{
    if (currentPath == rootPath) return;

    QDir dir(currentPath);
    if (dir.cdUp()) {
        currentPath = dir.absolutePath();
        updateImageList(currentPath);
        ui.treeView->setRootIndex(fileModel->index(currentPath));
    }
}
