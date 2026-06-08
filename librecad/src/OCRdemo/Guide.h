#pragma once

#include <QWidget>
#include "ui_Guide.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QDesktopServices>

class Guide : public QWidget
{
    Q_OBJECT

public:
    Guide(QWidget* parent = nullptr);
    ~Guide();

    void openPdf();
    void SetQSS();
    QString videoFilePath;

private slots:
    void replayVideo();
    void togglePausePlay();
    void rewindVideo();
    void fastForwardVideo();
    void closeGuide();

private:
    Ui::GuideClass ui;
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
};
