#pragma once

#include <QWidget>
#include "ui_ImageViewer.h"
#include <QFileSystemModel>

class ImageViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget* parent = nullptr);
    ~ImageViewer() override;

private slots:
    void onDirectoryChanged(const QModelIndex& index);
    void showNextImage();
    void showPreviousImage();
    void rotateImage();
    void goUpOneLevel();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::ImageViewerClass ui;

    QFileSystemModel* fileModel;
    QStringList imageList;
    QString currentPath;
    QString rootPath;
    int currentIndex = -1;
    int rotationAngle = 0;
    QPixmap originalPixmap;

    void loadImage(const QString& path);
    void updateImageList(const QString& folderPath);

signals:
    void showmain();
};
