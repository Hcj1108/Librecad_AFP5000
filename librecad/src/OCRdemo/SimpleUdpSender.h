#ifndef SIMPLEUDPSENDER_H
#define SIMPLEUDPSENDER_H

#include <QObject>

class SimpleUdpSender : public QObject
{
    Q_OBJECT

public:
    static SimpleUdpSender* instance();

    // ·¢ËÍbinÎÄ¼þ
    bool sendFile(const QString& filePath,
        const QString& ip = "192.168.1.10",
        quint16 port = 1234);

    void setSendParams(int bytesPerPacket, int intervalMs);
   
    void stop();
    bool isSending() const;

    static bool checkBinFile(const QString& filePath);
    static qint64 getFileSize(const QString& filePath);
    void sendPacket();

signals:
    void progress(int percent);
    void finished();
    void error(const QString& msg);

private:
    SimpleUdpSender(QObject* parent = nullptr);
    
private:
    class Private;
    Private* p;

signals:

   
    void stopSend();
    void startSend();
};

#endif // SIMPLEUDPSENDER_H