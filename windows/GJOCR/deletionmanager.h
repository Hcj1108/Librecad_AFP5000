#ifndef DELETIONMANAGER_H
#define DELETIONMANAGER_H

#include <QObject>
#include <QMutex>
#include <QThread>

// 删除线程类，后台执行文件夹查找和删除
class DeletionWorker : public QThread {
    Q_OBJECT

public:
    explicit DeletionWorker(const QString& directoryPath)
        : path(directoryPath) {
    }

protected:
    void run() override;  // 线程的任务

signals:
    void finished(bool success);

public:
    QString OldestFolderPath;
private:
    QString path;  // 需要处理的目录路径
};

// 管理删除操作的类，确保同一时间只有一个删除线程在运行
class DeletionManager : public QObject {
    Q_OBJECT

public:
    QString OldestFolderPath;

    explicit DeletionManager(QObject* parent = nullptr);
    void startDeletion(const QString& path);  // 启动删除操作

signals:
    void deletionCompleted(bool success);  // 删除完成信号

private:
    QMutex mutex;            // 互斥锁，用于保护并发访问
    bool isDeletionRunning;  // 标志变量，是否有删除线程在运行
};

#endif // DELETIONMANAGER_H
