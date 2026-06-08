#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>
#include <QWidget>
#include <QImage>

// 前置声明
namespace Ui {
    class ImageProcessorWidget;
}

class ImageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor(QObject* parent = nullptr);
    ~ImageProcessor();

    // 获取UI控件
    QWidget* widget() const;

public slots:
    void loadImagesFromFolder();
    void processCurrentImage();
    void saveProcessedImage();

signals:
    void imageLoaded(const QImage& image, const QString& name);
    void imageProcessed(const QImage& result);
    void progressChanged(int percent);
    void statusMessage(const QString& message);

private slots:
    void onFolderSelected(const QString& path);
    void onProcessingParameterChanged();

private:
    // UI相关
    QWidget* m_widget;
    Ui::ImageProcessorWidget* m_ui;

    // 数据处理
    QImage m_currentImage;
    QImage m_processedImage;
    QString m_currentFolder;

    // 初始化UI连接
    void setupConnections();
    void updateUiState();
};

#endif // IMAGEPROCESSOR_H