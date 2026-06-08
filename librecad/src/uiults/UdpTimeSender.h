#ifndef UDPTIMESENDER_H
#define UDPTIMESENDER_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QThread>

class UdpTimeSender : public QObject
{
    Q_OBJECT
public:
    explicit UdpTimeSender(QObject* parent = nullptr);
    ~UdpTimeSender();
    //192.168.1.10
    void startSending(const QString& ip = "192.168.1.10", quint16 port = 1234);
    void stopSending();

private slots:
    void sendTime();

private:
    QThread* m_thread;
    QUdpSocket* m_udpSocket;
    QTimer* m_timer;
    QString m_targetIp;
    quint16 m_targetPort;
};

#endif // UDPTIMESENDER_H