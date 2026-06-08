#include "udptimesender.h"
#include <QDebug>
#include <QDateTime>
#include <qendian.h>
UdpTimeSender::UdpTimeSender(QObject* parent) : QObject(parent)
{
    // 创建专用线程（不设置父对象）
    m_thread = new QThread();

    // 将整个对象移动到新线程
    this->moveToThread(m_thread);
    // 当user发出startSending信号时，启动UDP发送
 
    // 在线程启动后初始化对象
    connect(m_thread, &QThread::started, [this]() {
        m_udpSocket = new QUdpSocket();
        m_timer = new QTimer();

        connect(m_timer, &QTimer::timeout, this, &UdpTimeSender::sendTime);
        m_timer->setTimerType(Qt::PreciseTimer); // 精确计时

        qDebug() << "UDP发送器初始化完成，线程ID:" << QThread::currentThreadId();
    });

    m_thread->start();
}

UdpTimeSender::~UdpTimeSender()
{
    stopSending();
    m_thread->quit();
    m_thread->wait();
    delete m_thread;
}

void UdpTimeSender::startSending(const QString& ip, quint16 port)
{
    QMetaObject::invokeMethod(this, [this, ip, port]() {
        m_targetIp = ip;
        m_targetPort = port;
        m_timer->start(1000);
        qDebug() << QString::fromLocal8Bit("UDP发送时间已启动 ->") << ip << ":" << port;
    });
}

void UdpTimeSender::stopSending()
{
    QMetaObject::invokeMethod(this, [this]() {
        if (m_timer->isActive()) {
            m_timer->stop();
            m_udpSocket->close();
            qDebug() << QString::fromLocal8Bit("UDP发送时间已停止");
        }
    });
}

void UdpTimeSender::sendTime()
{
    // 1. 固定头（8字节）
    const QByteArray header = QByteArray::fromHex("10F0000000000000");

    // 2. 获取当前时间
    const QDateTime currentDateTime = QDateTime::currentDateTime();
    const QTime time = currentDateTime.time();

    // 3. 时间编码（保持您的位操作）
    const quint64 ll =
        ((time.hour() / 10u) & 0xF) << 20 |
        ((time.hour() % 10u) & 0xF) << 16 |
        ((time.minute() / 10u) & 0xF) << 12 |
        ((time.minute() % 10u) & 0xF) << 8 |
        ((time.second() / 10u) & 0xF) << 4 |
        ((time.second() % 10u) & 0xF);

    // 4. 构造数据包
    QByteArray packet;
    packet.append(header);
    packet.append(8, '\0'); // hl
    packet.append(8, '\0'); // lh

    // 大端序处理
    const quint64 beLL = qToBigEndian(ll);
    packet.append(reinterpret_cast<const char*>(&beLL), sizeof(beLL));

    // 5. 发送数据
    if (m_udpSocket->writeDatagram(packet, QHostAddress(m_targetIp), m_targetPort) == -1) {
        qWarning() << "发送失败:" << m_udpSocket->errorString();
        return;
    }

    // 6. 调试输出（限频）
    static int counter = 0;
    if (++counter % 5 == 0) {
        qDebug().noquote()
            << "[" << currentDateTime.toString("HH:mm:ss") << "]"
            << QString::fromLocal8Bit("数据包:") << packet.toHex().left(16) << "..."
            << QString::fromLocal8Bit("LL字段:") << QString::number(ll, 16).rightJustified(16, '0');
    }
}