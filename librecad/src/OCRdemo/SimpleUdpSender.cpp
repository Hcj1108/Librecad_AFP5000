#include "SimpleUdpSender.h"
#include <QUdpSocket>
#include <QFile>
#include <QTimer>
#include <QFileInfo>
#include <QDebug>

struct SimpleUdpSender::Private
{
    QUdpSocket socket;
    QFile file;
    QString ip = "192.168.1.10";
    quint16 port = 1234;
    bool sending = false;
    qint64 total = 0;
    qint64 sent = 0;
    int packetSize = 1024;  // 改为2字节每个包
    int intervalMs = 1;   // 发送间隔1毫秒
};

SimpleUdpSender* SimpleUdpSender::instance()
{
    static SimpleUdpSender sender;
    return &sender;
}

SimpleUdpSender::SimpleUdpSender(QObject* parent)
    : QObject(parent)
    , p(new Private)
{
}

bool SimpleUdpSender::sendFile(const QString& filePath, const QString& ip, quint16 port)
{
    stopSend();
    if (p->sending) {
        emit error(QString::fromLocal8Bit("正在发送中"));
        return false;
    }

    if (!checkBinFile(filePath)) {
        emit error(QString::fromLocal8Bit("请选择.bin文件"));
        return false;
    }

    p->file.setFileName(filePath);
    if (!p->file.open(QIODevice::ReadOnly)) {
        emit error(QString::fromLocal8Bit("无法打开文件"));
        return false;
    }

    p->ip = ip;
    p->port = port;
    p->total = p->file.size();
    p->sent = 0;
    p->sending = true;

    if (p->total == 0) {
        p->file.close();
        emit error(QString::fromLocal8Bit("文件为空"));
        p->sending = false;
        return false;
    }

    qDebug() << QString::fromLocal8Bit("开始发送文件:") << filePath
        << QString::fromLocal8Bit("大小:") << p->total << QString::fromLocal8Bit("字节")
        << QString::fromLocal8Bit("包大小:") << p->packetSize << QString::fromLocal8Bit("字节")
        << QString::fromLocal8Bit("间隔:") << p->intervalMs << QString::fromLocal8Bit("毫秒");
    // 计算总时间
    qint64 totalPackets = (p->total + p->packetSize - 1) / p->packetSize;  // 向上取整
    qint64 totalTimeMs = totalPackets * p->intervalMs;
    qDebug() << QString::fromLocal8Bit("预计发送时间:") << totalTimeMs << QString::fromLocal8Bit("毫秒")
        << QString::fromLocal8Bit("约") << totalTimeMs / 1000.0 << QString::fromLocal8Bit("秒");

    // 开始发送
    QTimer::singleShot(0, this, [this]() {
        sendPacket();
        });

    return true;
}

void SimpleUdpSender::sendPacket()
{
    if (!p->sending) return;

    if (p->sent >= p->total) {
        p->sending = false;
        p->file.close();
        emit progress(100);
        emit finished();
        qDebug() << QString::fromLocal8Bit("发送完成");
        startSend();
        return;
    }

    // 读取2字节数据
    qint64 remaining = p->total - p->sent;
    qint64 toRead = (remaining < p->packetSize) ? remaining : p->packetSize;
    QByteArray data = p->file.read(toRead);

    if (data.isEmpty()) {
        emit error(QString::fromLocal8Bit("读取失败"));
        stop();
        return;
    }

    // 如果数据不足2字节，补1
    if (data.size() < p->packetSize) {
        data.append(QByteArray(p->packetSize - data.size(), 0x11));
    }
    // 发送
    qint64 sent = p->socket.writeDatagram(data, QHostAddress(p->ip), p->port);
    if (sent == -1) {
        emit error(p->socket.errorString());
        stop();
        return;
    }

    p->sent += p->packetSize;  // 每次固定增加2字节

    // 计算进度
    int percent = 0;
    if (p->total > 0) {
        percent = static_cast<int>((p->sent * 100) / p->total);
        if (percent > 100) percent = 100;  // 防止超过100%
    }

    // 每发送1%或每100个包报告一次进度
    static int lastPercent = -1;
    static int packetCount = 0;
    packetCount++;

    if (percent != lastPercent || packetCount % 100 == 0) {
        emit progress(percent);
        if (percent != lastPercent) {
            qDebug() << QString::fromLocal8Bit("发送进度:") << percent << "%"
                << QString::fromLocal8Bit("已发送:") << p->sent << "/" << p->total
                << QString::fromLocal8Bit("字节");
            lastPercent = percent;
        }
    }

    // 延迟1毫秒后发送下一个包
    QTimer::singleShot(p->intervalMs, this, &SimpleUdpSender::sendPacket);
}
// 新增：设置发送参数
void SimpleUdpSender::setSendParams(int bytesPerPacket, int intervalMs)
{
    if (p->sending) {
        qDebug() << QString::fromLocal8Bit("正在发送中，不能修改参数");
        return;
    }

    if (bytesPerPacket <= 0 || bytesPerPacket > 65507) {  // UDP最大包大小
        qDebug() << QString::fromLocal8Bit("包大小必须在1-65507之间");
        return;
    }

    if (intervalMs < 0 || intervalMs > 1000) {
        qDebug() << QString::fromLocal8Bit("间隔时间必须在0-1000毫秒之间");
        return;
    }

    p->packetSize = bytesPerPacket;
    p->intervalMs = intervalMs;

    qDebug() << QString::fromLocal8Bit("发送参数已设置:")
        << QString::fromLocal8Bit("包大小:") << p->packetSize << QString::fromLocal8Bit("字节,")
        << QString::fromLocal8Bit("间隔:") << p->intervalMs << QString::fromLocal8Bit("毫秒");
}
void SimpleUdpSender::stop()
{
    p->sending = false;
    p->file.close();
}

bool SimpleUdpSender::isSending() const
{
    return p->sending;
}

bool SimpleUdpSender::checkBinFile(const QString& filePath)
{
    return QFileInfo(filePath).suffix().toLower() == "bin";
}

qint64 SimpleUdpSender::getFileSize(const QString& filePath)
{
    QFileInfo info(filePath);
    return info.exists() ? info.size() : -1;
}