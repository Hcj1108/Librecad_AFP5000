//#pragma once
//
//#include <QWidget>
//#include "ui_ImageViewer.h"
//
//class ImageViewer : public QWidget
//{
//	Q_OBJECT
//
//public:
//	ImageViewer(QWidget *parent = nullptr);
//	~ImageViewer();
//
//
//private:
//	Ui::ImageViewerClass ui;
//};
#pragma once

#include <QWidget>
#include "ui_ImageViewer.h"
#include <QFileSystemModel>

class ImageViewer : public QWidget
{
	Q_OBJECT

public:
	explicit ImageViewer(QWidget* parent = nullptr);
	~ImageViewer();
	void SetQSS();

private slots:
	void onDirectoryChanged(const QModelIndex& index);  // 文件夹/图片选择槽
	void showNextImage();  // 显示下一张图片
	void showPreviousImage();  // 显示上一张图片
	void rotateImage();  // 旋转图片
	void goUpOneLevel();  // 返回上一级目录

private:
	Ui::ImageViewerClass ui;

	QFileSystemModel* fileModel;  // 文件系统模型
	QStringList imageList;  // 当前文件夹中的图片列表
	QString currentPath;  // 当前文件夹路径
	QString rootPath;  // 当前文件夹路径
	int currentIndex;  // 当前图片索引
	int rotationAngle;  // 图片旋转角度

	// 保存原始图片
	QPixmap originalPixmap;  // 用于保存最初加载的图片

	void loadImage(const QString& path);  // 加载图片
	void updateImageList(const QString& folderPath);  // 更新图片列表
};