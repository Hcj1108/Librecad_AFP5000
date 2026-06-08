#pragma once

#include <QMainWindow>
#include "ui_SenderBinUdp.h"
#include <QObject>
#include <QUdpSocket>
#include <QFile>
#include <QTimer>
#include <QFileInfo>
#include <QDebug>
#include<QPainter>
#include <QElapsedTimer>
#include<string>
#include<iostream>
class SenderBinUdp : public QMainWindow
{
	Q_OBJECT

public:
    QUdpSocket socket;
    QFile file;
    QString ip = "192.168.1.10";
    quint16 port = 1234;
    bool sending = false;
    qint64 total = 0;
    qint64 sent = 0;
    int packetSize = 256;  // 改为2字节每个包
    int intervalMs = 1;   // 发送间隔1毫秒
    QString openBinFilePath;//Bin文件地址
    QString fileName;
    QString destPath;//rec文件夹路经
    QString openFilePath;//模型文件地址


   
	SenderBinUdp(QWidget *parent = nullptr);
	~SenderBinUdp();
    void SetQSS();
    void paintEvent(QPaintEvent* event) override;
    bool eventFilter(QObject* obj, QEvent* evt);
    // 发送bin文件
    bool sendFile(const QString& filePath,
        const QString& ip,
        quint16 port);

    void setSendParams(int bytesPerPacket, int intervalMs);

    void stop();
    bool isSending() const;

    static bool checkBinFile(const QString& filePath);
    static qint64 getFileSize(const QString& filePath);
    void sendPacket();
    bool copyFilesOnly(const QString& sourcePath, const QString& destPath);
    void onToolButtonClicked();
    void saveFolderPath();
    void getFolderContentsInfo(const QString& filePath);
    int SendBKBK(QString positionCommandHeader, QString cmdHex, int ParamValue);
    void eraseCompleteSignal();
    void writeCompleteSignal();
private:
	Ui::SenderBinUdpClass ui;

signals:
    void progress(int percent);
    void finished();
    void error(const QString& msg);
    void stopSend();
    void startSend();
};

