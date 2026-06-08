#include "ImageProcessor.h"
#include "ui_ImageProcessorWidget.h" // 由UI文件生成的头文件

#include <QFileDialog>
#include <QDir>
#include <QImageReader>
#include <QMessageBox>
#include <QStandardPaths>

ImageProcessor::ImageProcessor(QObject* parent)
    : QObject(parent),
    m_widget(new QWidget()),
    m_ui(new Ui::ImageProcessorWidget())
{
    // 设置UI
    m_ui->setupUi(m_widget);

    // 初始化UI状态
    updateUiState();

    // 建立信号槽连接
    setupConnections();
}

ImageProcessor::~ImageProcessor()
{
    delete m_ui;
    delete m_widget;
}

QWidget* ImageProcessor::widget() const
{
    return m_widget;
}

void ImageProcessor::setupConnections()
{
    // UI按钮连接
    connect(m_ui->btnSelectFolder, &QPushButton::clicked,
        this, &ImageProcessor::loadImagesFromFolder);
    connect(m_ui->btnProcess, &QPushButton::clicked,
        this, &ImageProcessor::processCurrentImage);
    connect(m_ui->btnSave, &QPushButton::clicked,
        this, &ImageProcessor::saveProcessedImage);

    // 参数变化连接
    connect(m_ui->sliderBrightness, &QSlider::valueChanged,
        this, &ImageProcessor::onProcessingParameterChanged);
    connect(m_ui->sliderContrast, &QSlider::valueChanged,
        this, &ImageProcessor::onProcessingParameterChanged);

    // 内部信号连接
    connect(this, &ImageProcessor::imageLoaded,
        [this](const QImage& img, const QString& name) {
        m_ui->lblOriginal->setPixmap(QPixmap::fromImage(img));
        m_ui->lblStatus->setText(tr("Loaded: %1").arg(name));
    });

    connect(this, &ImageProcessor::imageProcessed,
        [this](const QImage& img) {
        m_ui->lblProcessed->setPixmap(QPixmap::fromImage(img));
    });
}

void ImageProcessor::updateUiState()
{
    const bool hasImage = !m_currentImage.isNull();
    m_ui->btnProcess->setEnabled(hasImage);
    m_ui->btnSave->setEnabled(hasImage && !m_processedImage.isNull());

    // 更新参数显示
    //m_ui->lblBrightnessValue->setText(QString::number(m_ui->sliderBrightness->value()));
    //m_ui->lblContrastValue->setText(QString::number(m_ui->sliderContrast->value()));
}

void ImageProcessor::loadImagesFromFolder()
{
    QString folder = QFileDialog::getExistingDirectory(
        m_widget,
        tr("Select Image Folder"),
        m_currentFolder.isEmpty() ? QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) : m_currentFolder
    );

    if (!folder.isEmpty()) {
        m_currentFolder = folder;
        onFolderSelected(folder);
    }
}

void ImageProcessor::onFolderSelected(const QString& path)
{
    QDir dir(path);
    QStringList filters;
    for (const QByteArray& format : QImageReader::supportedImageFormats()) {
        filters << "*." + format;
    }

    QStringList imageFiles = dir.entryList(filters, QDir::Files | QDir::Readable);
    if (imageFiles.isEmpty()) {
        QMessageBox::warning(m_widget, tr("No Images"),
            tr("No supported images found in the selected folder."));
        return;
    }

    // 加载第一张图片作为示例
    QString firstImagePath = dir.absoluteFilePath(imageFiles.first());
    QImage image(firstImagePath);

    if (image.isNull()) {
        QMessageBox::warning(m_widget, tr("Load Failed"),
            tr("Failed to load image: %1").arg(imageFiles.first()));
        return;
    }

    m_currentImage = image;
    m_processedImage = QImage();

    emit imageLoaded(image, imageFiles.first());
    updateUiState();
}

void ImageProcessor::processCurrentImage()
{
    if (m_currentImage.isNull()) {
        return;
    }

    // 获取处理参数
    int brightness = m_ui->sliderBrightness->value();
    int contrast = m_ui->sliderContrast->value();

    // 处理图像 (这里只是示例)
    m_processedImage = m_currentImage;
    // 实际处理代码...

    emit imageProcessed(m_processedImage);
    updateUiState();
}

void ImageProcessor::onProcessingParameterChanged()
{
    updateUiState();

    // 如果启用实时预览
    if (m_ui->chkLivePreview->isChecked()) {
        processCurrentImage();
    }
}

void ImageProcessor::saveProcessedImage()
{
    if (m_processedImage.isNull()) {
        return;
    }

    QString savePath = QFileDialog::getSaveFileName(
        m_widget,
        tr("Save Processed Image"),
        QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
        tr("Images (*.png *.jpg *.bmp)")
    );

    if (!savePath.isEmpty()) {
        if (!m_processedImage.save(savePath)) {
            QMessageBox::warning(m_widget, tr("Save Failed"),
                tr("Failed to save image to: %1").arg(savePath));
        }
    }
}