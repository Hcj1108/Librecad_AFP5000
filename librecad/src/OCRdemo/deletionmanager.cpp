#include "deletionmanager.h"
#include <QDir>
#include <QFileInfoList>
#include <QDebug>

// 删除线程的任务实现
void DeletionWorker::run() {
    QDir dir(path);
    if (!dir.exists()) {
        emit finished(false);
        return;
    }

    // 获取路径下的所有文件夹（按时间排序）
    QFileInfoList folders = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Time);
    if (folders.isEmpty()) {
        emit finished(false);
        return;
    }

    // 找到修改时间最早的文件夹
    QString oldestFolderPath = folders.last().absoluteFilePath();
    OldestFolderPath = oldestFolderPath;
    qDebug() << "Oldest folder:" << oldestFolderPath;

    // 删除该文件夹及其所有内容
    bool success = QDir(oldestFolderPath).removeRecursively();
    emit finished(success);  // 发出完成信号
}

// 删除管理类的构造函数
DeletionManager::DeletionManager(QObject* parent)
    : QObject(parent), isDeletionRunning(false) {
}

// 启动删除操作
void DeletionManager::startDeletion(const QString& path) {
    QMutexLocker locker(&mutex);  // 锁定互斥锁，确保线程安全

    if (isDeletionRunning) {
        qDebug() << "Deletion already in progress. Please wait.";
        return;  // 已有线程在运行，退出
    }

    isDeletionRunning = true;  // 设置标志，表示删除线程正在运行

    // 创建删除线程
    DeletionWorker* worker = new DeletionWorker(path);

    // 连接线程完成后的信号槽
    connect(worker, &DeletionWorker::finished, this, [this, worker](bool success) {
        QMutexLocker locker(&mutex);  // 锁定互斥锁以重置标志
        isDeletionRunning = false;  // 重置标志

        if (success) {
            OldestFolderPath = worker->OldestFolderPath;
            //qDebug() << "Oldest folder deleted successfully.";
        }
        else {
            //qDebug() << "Failed to delete the folder or no folder found.";
        }

        worker->deleteLater();  // 安全删除线程对象
        emit deletionCompleted(success);  // 发出完成信号
    });

    worker->start();  // 启动删除线程
}
