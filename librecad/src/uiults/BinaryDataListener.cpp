#include "BinaryDataListener.h"
#include <QDebug>



BinaryDataListener::BinaryDataListener(quint16 listenPort, QObject* parent)
    : QObject(parent), m_port(listenPort), m_isRunning(false)
{
    m_socket = new QUdpSocket(this);
}

BinaryDataListener::~BinaryDataListener()
{
    stop();
}

void BinaryDataListener::start()
{
    if (m_isRunning) return;

    if (m_socket->bind(QHostAddress::Any, m_port)) {
        connect(m_socket, &QUdpSocket::readyRead, this, &BinaryDataListener::readPendingDatagrams);
        m_isRunning = true;
        qDebug() << "Listening for 256-bit binary data on port:" << m_port;
    }
    else {
        qCritical() << "Bind failed:" << m_socket->errorString();
    }
}

void BinaryDataListener::stop()
{
    if (m_isRunning) {
        m_socket->close();
        disconnect(m_socket, &QUdpSocket::readyRead, this, &BinaryDataListener::readPendingDatagrams);
        m_isRunning = false;
        qDebug() << "Stopped listening";
    }
}

bool BinaryDataListener::validateData(const QByteArray& data)
{
    const int requiredSize = 32; // 256 bits
    if (data.size() != requiredSize) {
        qWarning() << "Invalid data size:" << data.size() << "bytes (expected" << requiredSize << ")";
        return false;
    }
    return true;
}

QString BinaryDataListener::bitsToString(const QBitArray& bits, int startPos, int length) const
{
    if (length < 0) length = bits.size() - startPos;
    length = qMin(length, bits.size() - startPos);

    QString result;
    for (int i = startPos; i < startPos + length; ++i) {
        result.append(bits.testBit(i) ? '1' : '0');
    }
    return result;
}

void BinaryDataListener::readPendingDatagrams()
{
    while (m_socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;
        m_socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        if (validateData(datagram)) {
            // Convert bytes to 256 bits
            QBitArray bits(256);
            for (int i = 0; i < 32; ++i) {
                quint8 byte = static_cast<quint8>(datagram.at(i));
                for (int j = 0; j < 8; ++j) {
                    bits.setBit(i * 8 + j, byte & (1 << (7 - j)));
                }
            }

            emit dataReceived(bits, sender, senderPort);

            // Debug output
            qDebug().noquote()
                << "\n=== Received 256-bit data ==="
                << "\nFrom:" << sender.toString() << ":" << senderPort;  
        }
    }
}
/**
 * 从比特数组中提取指定范围的整数值
 * @param bits 比特数组
 * @param highBit 高位索引（包含）
 * @param lowBit 低位索引（包含）
 * @return 提取的整数值
 */
quint32 BinaryDataListener::extractBitsToUInt(const QBitArray& bits, int start, int end) {
    quint32 value = 0;
    int length = start - end + 1;

    for (int i = 0; i < length; ++i) {
        int bitPos = start - i;
        if (bits.testBit(bitPos)) {
            value |= (1 << i);
        }
    }

    return value;
}
// 简化状态解析
QString BinaryDataListener::parseSimpleStatus(quint32 data, const QStringList& descriptions) {
    QStringList states;
    for (int i = 0; i < descriptions.size(); ++i) {
        if (data & (1 << i)) {
            states << descriptions[i] + "y";
        }
        else {
            states << descriptions[i] + ":n";
        }
    }
    return states.join(", ");
}