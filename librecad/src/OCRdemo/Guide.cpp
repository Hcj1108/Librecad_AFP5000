#include "Guide.h"
#include <QFileDialog>

Guide::Guide(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // 初始化播放器
    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(ui.widget);
    videoWidget->setStyleSheet("background: black;");

    QVBoxLayout* layout = new QVBoxLayout(ui.widget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(videoWidget);

    mediaPlayer->setVideoOutput(videoWidget);

    if (QFile::exists(videoFilePath)) {
        mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(videoFilePath)));
    }

    // 按钮连接
    connect(ui.pushButton, &QPushButton::clicked, this, &Guide::replayVideo);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &Guide::togglePausePlay);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &Guide::rewindVideo);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &Guide::fastForwardVideo);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &Guide::openPdf);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &Guide::closeGuide);

    SetQSS();
}

Guide::~Guide()
{
}

void Guide::SetQSS()
{
    // 设置窗口标志：保留系统菜单、显示问号(?)按钮、显示关闭(X)按钮
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    setWindowTitle(QString::fromLocal8Bit("使用教程"));
    ui.widget_2->setStyleSheet("QWidget { border: 1px solid green; }");

}

void Guide::closeGuide()
{
    if (mediaPlayer->state() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
        ui.pushButton_3->setText(QString::fromLocal8Bit("继续"));
    }
    hide();
}

void Guide::openPdf()
{
    QString pdfFilePath = "./guidevideo/doc.pdf";
    if (QFile::exists(pdfFilePath)) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(pdfFilePath));
    } else {
        qDebug() << "PDF file not found at path:" << pdfFilePath;
    }
}

void Guide::replayVideo()
{
    mediaPlayer->stop();
    QString targetDirectory = "./guidevideo/";
    QString fileName = QFileDialog::getOpenFileName(
        nullptr,
        QString::fromLocal8Bit("选择视频文件"),
        targetDirectory,
        QString::fromLocal8Bit("视频文件 (*.mp4 *.avi *.mov *.mkv *.wmv *.flv *.webm)"));
    videoFilePath = fileName;

    if (!fileName.isEmpty()) {
        mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(videoFilePath)));
        mediaPlayer->play();
    }
}

void Guide::togglePausePlay()
{
    if (mediaPlayer->state() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
        ui.pushButton_3->setText(QString::fromLocal8Bit("继续"));
    } else {
        mediaPlayer->play();
        ui.pushButton_3->setText(QString::fromLocal8Bit("暂停"));
    }
}

void Guide::rewindVideo()
{
    qint64 pos = mediaPlayer->position();
    mediaPlayer->setPosition(qMax(qint64(0), pos - 5000));
}

void Guide::fastForwardVideo()
{
    qint64 pos = mediaPlayer->position();
    mediaPlayer->setPosition(pos + 5000);
}
