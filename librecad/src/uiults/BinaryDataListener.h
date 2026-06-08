// binarylistener.h
#ifndef BINARYLISTENER_H
#define BINARYLISTENER_H

#include <QObject>
#include <QUdpSocket>
#include <QBitArray>

class BinaryDataListener : public QObject
{
    Q_OBJECT
public:
    explicit BinaryDataListener(quint16 listenPort = 1234, QObject* parent = nullptr);
    ~BinaryDataListener();

    void start();
    void stop();
    bool isRunning() const { return m_isRunning; }
    quint32 extractBitsToUInt(const QBitArray& bits, int start, int end);
    QString parseSimpleStatus(quint32 data, const QStringList& descriptions);// 简化状态解析
    // 将方法改为public
    QString bitsToString(const QBitArray& bits, int startPos = 0, int length = -1) const;

signals:
    void dataReceived(const QBitArray& bits, const QHostAddress& sender, quint16 port);

private slots:
    void readPendingDatagrams();

private:
    QUdpSocket* m_socket;
    quint16 m_port;
    bool m_isRunning;

    bool validateData(const QByteArray& data);
};
#endif // BINARYLISTENER_H