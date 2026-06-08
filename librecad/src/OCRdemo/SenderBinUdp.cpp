#include "SenderBinUdp.h"
#include<QPushButton>
#include <QFileDialog>
#include<QMouseEvent>
#include<QHBoxLayout>
#include <QComboBox>
#include <QDateTime>
#include <QThread>
SenderBinUdp::SenderBinUdp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.spinBox->setValue(packetSize);
    ui.spinBox_2->setValue(intervalMs);
    ui.lineEdit_2->setText(QString::fromLocal8Bit("无模型路径"));
    ui.textEdit_2->setText(QString::fromLocal8Bit("请选择模型"));
    ui.textEdit_3->clear();

    QString appDir = QCoreApplication::applicationDirPath();
    QString modelsPath = appDir + "/models";
    destPath = appDir + "/models/rec";

    connect(ui.toolButton_6, &QToolButton::clicked, this, [=] {
        ui.toolButton_2->setEnabled(false);
        startSend();
        hide();
        });
    connect(ui.toolButton_3, &QPushButton::clicked, this,&SenderBinUdp::onToolButtonClicked);
    connect(ui.toolButton_4, &QPushButton::clicked, this,&SenderBinUdp::saveFolderPath);
    connect(ui.toolButton_5, &QPushButton::clicked, this, [=] {
        getFolderContentsInfo(destPath);
        });
    connect(ui.toolButton, &QPushButton::clicked, this, [=] {
            fileName = QFileDialog::getOpenFileName(
            nullptr,
            QString::fromLocal8Bit("选择升级文件"),
            QDir::homePath(),  // 默认从用户主页目录开始
            //targetDirectory,  // 直接在指定文件夹开始
            QString::fromLocal8Bit("升级文件 (*.bin)")
        );
        openBinFilePath = fileName;
        ui.lineEdit->setText(openBinFilePath);
       

        });
    connect(ui.toolButton_2, &QPushButton::clicked, this, [=] {
    
        // 检查用户是否选择了文件
        if (!fileName.isEmpty()) {
            file.setFileName(openBinFilePath);
            if (!file.open(QIODevice::ReadOnly)) {
                error(QString::fromLocal8Bit("无法打开文件"));
                ui.textEdit->setText(QString::fromLocal8Bit("无法打开文件"));
                return;
            }
            else {
                total = file.size();              // 获取要发送的文件总大小（字节数）
                //int s = (total + 65536 - 1) / 65536;
                int s = total / 65536;
                // SendBKBK("00", "00", s);
                SendBKBK("00", "01", s);
                sendFile(openBinFilePath, "192.168.1.10", 1234);
            }
        }
        else {
            // 用户取消选择时的处理（可选）
            qDebug() << QString::fromLocal8Bit("未选择文件");
            ui.textEdit->setText(QString::fromLocal8Bit("未选择文件"));
        }
        });
    connect(ui.toolButton_7, &QPushButton::clicked, this, [=] {

        // 检查用户是否选择了文件
        if (!fileName.isEmpty()) {
            file.setFileName(openBinFilePath);
            if (!file.open(QIODevice::ReadOnly)) {
                error(QString::fromLocal8Bit("无法打开文件"));
                ui.textEdit->setText(QString::fromLocal8Bit("无法打开文件"));
                return;
            }
            else {
              
                total = file.size();              // 获取要发送的文件总大小（字节数）
                //int s = (total + 65536 - 1) / 65536;
                int s = total / 65536;
                SendBKBK("00", "00", s);
            }
        }
        else {
            // 用户取消选择时的处理（可选）
            qDebug() << QString::fromLocal8Bit("未选择文件");
            ui.textEdit->setText(QString::fromLocal8Bit("未选择文件"));
        }
        });
    SetQSS();
}

SenderBinUdp::~SenderBinUdp()
{}
void SenderBinUdp::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // 设置边框颜色和宽度
    QPen pen;
    pen.setColor(Qt::black);  // 设置边框颜色为蓝色
    pen.setWidth(4);         // 设置边框宽度为5px
    painter.setPen(pen);

    // 绘制自定义边框（窗体的边框）
    painter.drawRect(0, 0, this->width() - 1, this->height() - 1);
}
//设置页面样式
void  SenderBinUdp::SetQSS()
{
    // 去掉最小化和关闭按钮
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    // 设置窗体的初始大小
    qApp->installEventFilter(this);                   //给自己加事件过滤器,用来实现拖动窗口
    ui.toolButton_2->setEnabled(false);
}
bool SenderBinUdp::eventFilter(QObject* obj, QEvent* evt)
{
    QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(evt);
    if (obj == this && mouse)                 //判断拖动
    {
        if (this->isMaximized())
        {
            return true;
        }
        static bool dragFlag = false;
        static QPoint dragPoint(0, 0);
        if (mouse->button() == Qt::LeftButton && mouse->type() == QEvent::MouseButtonPress)    //按下
        {
            dragFlag = true;
            dragPoint = mouse->pos();                                  //记录鼠标所在的界面位置
            return true;
        }
        else if (dragFlag && mouse->type() == QEvent::MouseMove)     //拖动
        {
            this->move(mouse->globalPos() - dragPoint);
            return true;
        }
        else if (mouse->type() == QEvent::MouseButtonRelease)
        {
            dragFlag = false;
            return true;
        }
    }

    return QWidget::eventFilter(obj, evt);
}
bool SenderBinUdp::sendFile(const QString& filePath, const QString& ip, quint16 port)
{

   
    if (sending) {
        emit error(QString::fromLocal8Bit("正在发送中"));
        ui.textEdit->setText(QString::fromLocal8Bit("正在发送中"));
        return false;
    }

    if (!checkBinFile(filePath)) {
        emit error(QString::fromLocal8Bit("请选择.bin文件"));
        ui.textEdit->setText(QString::fromLocal8Bit("请选择.bin文件"));
        return false;
    }

 /*   file.setFileName(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        emit error(QString::fromLocal8Bit("无法打开文件"));
        ui.textEdit->setText(QString::fromLocal8Bit("无法打开文件"));
        return false;
    }*/
   
   
   
    sent = 0;                         // 已发送字节数初始化为0
    sending = true;                   // 设置发送状态为正在发送
    // 从UI控件获取发送参数
    packetSize = ui.spinBox->value();     // 从界面上的spinBox控件获取每个数据包的大小（字节）
    intervalMs = ui.spinBox_2->value();   // 从界面上的spinBox_2控件获取发送间隔时间（毫秒）

    // --- 文件有效性检查 ---
    if (total == 0) {
        file.close();  // 关闭文件句柄

        // 发送错误信号并更新UI
        emit error(QString::fromLocal8Bit("文件为空"));  // 发射错误信号
        ui.textEdit->setText(QString::fromLocal8Bit("文件为空"));  // 在文本框中显示错误信息

        sending = false;  // 设置发送状态为停止
        return false;     // 返回失败状态
    }


    qDebug() << QString::fromLocal8Bit("开始发送文件:") << filePath
        << QString::fromLocal8Bit("大小:") << total << QString::fromLocal8Bit("字节")
        << QString::fromLocal8Bit("包大小:") << packetSize << QString::fromLocal8Bit("字节")
        << QString::fromLocal8Bit("间隔:") << intervalMs << QString::fromLocal8Bit("毫秒");
   
    qint64 totalPackets = (total + packetSize - 1) / packetSize;  // 向上取整
    qint64 totalTimeMs = totalPackets * intervalMs;
    qDebug() << QString::fromLocal8Bit("预计发送时间:") << totalTimeMs << QString::fromLocal8Bit("毫秒")
        << QString::fromLocal8Bit("约") << totalTimeMs / 1000.0 << QString::fromLocal8Bit("秒");
   
    // 开始发送
    QTimer::singleShot(0, this, [this]() {
        sendPacket();
        });

    return true;
}

void SenderBinUdp::sendPacket()
{
    if (!sending) return;

    // 检查是否发送完成
    if (sent >= total) {
        sending = false;
        file.close();
        emit progress(100);
        emit finished();
        qDebug() << QString::fromLocal8Bit("发送完成");
        ui.textEdit->setText(QString::fromLocal8Bit("发送完成"));
        startSend();
        return;
    }

    // 计算当前块的大小
    qint64 remainingTotal = total - sent;  // 总剩余字节数
    qint64 blockSize = qMin(remainingTotal, static_cast<qint64>(65536));  // 当前块大小，最大65536字节

    // 读取整个块的数据
    file.seek(sent);  // 定位到当前发送位置
    QByteArray blockData = file.read(blockSize);

    if (blockData.isEmpty()) {
        emit error(QString::fromLocal8Bit("读取块失败"));
        ui.textEdit->setText(QString::fromLocal8Bit("读取块失败"));
        stop();
        return;
    }

    // 如果块数据不足65536字节，补充0xFF
    if (blockData.size() < 65536) {
        blockData.append(QByteArray(65536 - blockData.size(), 0xFF));
    }

    // 将块分割成256字节的小包发送
    for (int offset = 0; offset < blockData.size(); offset += 256) {
        int currentPacketSize = qMin(256, blockData.size() - offset);
        QByteArray packetData = blockData.mid(offset, currentPacketSize);

        // 如果包大小不足256字节，补充0x11
        if (packetData.size() < 256) {
            packetData.append(QByteArray(256 - packetData.size(), 0x11));
        }

        // 发送UDP数据包
        qint64 bytesWritten = socket.writeDatagram(packetData, QHostAddress(ip), port);
        if (bytesWritten == -1) {
            emit error(socket.errorString());
            stop();
            return;
        }
        // 每发送一个小包后延迟
        QThread::msleep(1);  // 短暂延迟，避免发送过快
    }

    // 更新已发送字节数（整个块的大小）
    sent += blockSize;

    // 计算进度
    int percent = 0;
    if (total > 0) {
        percent = static_cast<int>((sent * 100) / total);
        if (percent > 100) percent = 100;  // 防止超过100%
    }

    // 每发送1%或每发送一个块报告一次进度
    static int lastPercent = -1;
    static int blockCount = 0;
    blockCount++;

    if (percent != lastPercent || blockCount % 1 == 0) {  // 每个块都报告进度
        emit progress(percent);
        if (percent != lastPercent) {
            qDebug() << QString::fromLocal8Bit("发送进度:") << percent << "%"
                << QString::fromLocal8Bit("已发送:") << sent << "/" << total
                << QString::fromLocal8Bit("字节");

            QString progressText = QString::fromLocal8Bit("发送进度: %1%\n已发送: %2/%3 字节")
                .arg(percent)
                .arg(sent)
                .arg(total);
            ui.textEdit->setText(progressText);
            lastPercent = percent;
        }
    }

    // 延迟后发送下一个块
    QTimer::singleShot(intervalMs, this, &SenderBinUdp::sendPacket);
}


// 新增：设置发送参数
void  SenderBinUdp::setSendParams(int bytesPerPacket, int intervalMs)
{
    if (sending) {
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

    packetSize = bytesPerPacket;
    intervalMs = intervalMs;

    qDebug() << QString::fromLocal8Bit("发送参数已设置:")
        << QString::fromLocal8Bit("包大小:") << packetSize << QString::fromLocal8Bit("字节,")
        << QString::fromLocal8Bit("间隔:") << intervalMs << QString::fromLocal8Bit("毫秒");
}
void  SenderBinUdp::stop()
{
    sending = false;
    file.close();
}

bool  SenderBinUdp::isSending() const
{
    return sending;
}

bool  SenderBinUdp::checkBinFile(const QString& filePath)
{
    return QFileInfo(filePath).suffix().toLower() == "bin";
}

qint64  SenderBinUdp::getFileSize(const QString& filePath)
{
    QFileInfo info(filePath);
    return info.exists() ? info.size() : -1;
}


/**
 * @brief 复制源文件夹的所有文件（不包含子文件夹）
 * @param sourcePath 源文件夹路径
 * @param destPath 目标文件夹路径
 * @return 是否复制成功
 */
bool SenderBinUdp::copyFilesOnly(const QString& sourcePath, const QString& destPath) {
    QDir sourceDir(sourcePath);
    if (!sourceDir.exists()) {
        qDebug() << "源文件夹不存在:" << sourcePath;
        return false;
    }

    QDir destDir(destPath);
    if (!destDir.exists() && !destDir.mkpath(".")) {
        qDebug() << "无法创建目标文件夹:" << destPath;
        return false;
    }

    // 获取所有文件
    QStringList files = sourceDir.entryList(QDir::Files);

    for (const QString& file : files) {
        QString srcFile = sourcePath + "/" + file;
        QString dstFile = destPath + "/" + file;

        if (QFile::exists(dstFile)) {
            QFile::remove(dstFile);
        }

        if (!QFile::copy(srcFile, dstFile)) {
            qDebug() << "复制失败:" << file;
            return false;
        }

        qDebug() << "已复制:" << file;
    }

    return true;
}

void SenderBinUdp::onToolButtonClicked() {
    // 获取程序目录
    QString appDir = QCoreApplication::applicationDirPath();
    QString modelsPath = appDir + "/models";
   

    // 检查models目录是否存在
    QDir modelsDir(modelsPath);
    if (!modelsDir.exists()) {
        ui.textEdit_2->setText(QString::fromLocal8Bit("错误：找不到models目录"));
        return;
    }

    // 扫描所有包含"en_SQ"的文件夹
    QStringList enSqFolders;
    QStringList allFolders = modelsDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QString& folder : allFolders) {
        if (folder.contains("en_SQ", Qt::CaseInsensitive)) {
            enSqFolders.append(folder);
        }
    }

    if (enSqFolders.isEmpty()) {
        ui.textEdit_2->setText(QString::fromLocal8Bit("未找到包含'en_SQ'的文件夹"));
        return;
    }

    // 对文件夹进行排序（按时间或名称）
    enSqFolders.sort();

    // 创建选择对话框
    QDialog dialog(this);
    dialog.setWindowTitle("OCRdemo");  // 添加窗口标题
    dialog.setFixedSize(300, 150);  // 固定大小

    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);
    // 添加标签
    QLabel* label = new QLabel(QString::fromLocal8Bit("请选择en_SQ文件夹:"), &dialog);
    label->setStyleSheet("font-weight: bold; font-size: 11pt;");
    layout->addWidget(label);

    // 创建组合框显示文件夹列表
    QComboBox* comboBox = new QComboBox(&dialog);
    comboBox->setFixedHeight(30);
    comboBox->setStyleSheet(
        "QComboBox {"
        "    border: 1px solid #cccccc;"
        "    border-radius: 3px;"
        "    padding: 5px;"
        "    background-color: white;"
        "    font-size: 11pt;"
        "}"
        "QComboBox::drop-down {"
        "    border: none;"
        "}"
    );
    comboBox->addItems(enSqFolders);
    layout->addWidget(comboBox);

    // 添加按钮
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* okButton = new QPushButton(QString::fromLocal8Bit("确定"), &dialog);
    QPushButton* cancelButton = new QPushButton(QString::fromLocal8Bit("取消"), &dialog);

    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    // 连接信号
    QString selectedFolder;
    connect(okButton, &QPushButton::clicked, &dialog, [&]() {
        selectedFolder = comboBox->currentText();
        dialog.accept();
        });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // 双击快速选择
    connect(comboBox, QOverload<int>::of(&QComboBox::activated), &dialog, [&](int index) {
        if (index >= 0) {
            selectedFolder = comboBox->itemText(index);
            dialog.accept();
        }
        });

    // 显示对话框
    if (dialog.exec() == QDialog::Accepted && !selectedFolder.isEmpty()) {
        openFilePath = modelsPath + "/" + selectedFolder;
        ui.lineEdit_2->setText(openFilePath);
        ui.textEdit_2->setText(QString::fromLocal8Bit("已选择: %1\n请点击确认替换！")
            .arg(selectedFolder));
    }
    else {
        ui.textEdit_2->setText(QString::fromLocal8Bit("已取消选择"));
    }
}
void SenderBinUdp::saveFolderPath() {
    // 检查用户是否选择了文件
    if (ui.lineEdit_2->text().isEmpty()) {
        ui.textEdit_2->setText(QString::fromLocal8Bit("请先选择源文件夹！ "));
    }
    else {
        int finalizeModelTransfer = copyFilesOnly(openFilePath, destPath);
        if (finalizeModelTransfer) {
            ui.textEdit_2->setText(QString::fromLocal8Bit("替换完成！请重新启动软件 "));
            ui.lineEdit_2->clear();
        }
        else {
            ui.textEdit_2->setText(QString::fromLocal8Bit("替换失败！ "));
        }

    }


}
// 通用的文件夹信息获取函数
void SenderBinUdp::getFolderContentsInfo(const QString& folderPath) {
    QDir dir(folderPath);

    if (!dir.exists()) {
        ui.textEdit_3->setText(QString::fromLocal8Bit("文件夹不存在"));
        return;
    }

    // 获取所有文件
    QFileInfoList files = dir.entryInfoList(QDir::Files);
    QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    if (files.isEmpty()) {
        ui.textEdit_3->setText(QString::fromLocal8Bit("没有找到文件"));

    }
    else {
        // 构建显示文本
        QString displayText = "";

        for (const QFileInfo& file : files) {
            QString fileName = file.fileName();
            QString modifyTime = file.lastModified().toString("yyyy/MM/dd h:mm");
            qint64 sizeKB = file.size() / 1024;
            QString sizeStr = QString::number(sizeKB);

            // 添加千位分隔符
            for (int i = sizeStr.length() - 3; i > 0; i -= 3) {
                sizeStr.insert(i, ',');
            }
            sizeStr += " KB";

            // 添加到显示文本
            displayText += QString("%1\n%2 %3\n")
                .arg(fileName)  // 文件名左对齐，40字符宽度
                .arg(modifyTime)  // 时间
                .arg(sizeStr);    // 大小右对齐

        }

        // 显示在textEdit_3中
        ui.textEdit_3->setText(displayText);
    }
}
//发送############################################################################
int SenderBinUdp::SendBKBK(QString positionCommandHeader, QString cmdHex, int ParamValue)
{
    QString ip = "192.168.1.10";
    quint16 port = 1234;
    //QString cmdHex = QString::number(ParamType, 16).toUpper(); // 转换为"5E"

    QUdpSocket udpSocket;

    // 构建参数发送列表（与结构体成员对应）
    QVector<QPair<QString, int>> params = {
        {cmdHex, ParamValue},
    };
    // 发送所有参数
    for (const auto& param : params) {
        // 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
        QString headerStr = positionCommandHeader + param.first + "000000000000";
        QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

        // 固定值 hl 和 lh (各8字节，全0)
        quint64 hl = 0;
        quint64 lh = 0;

        // ll 参数值 (8字节，低4字节为参数值，大端序)
        //quint64 ll = qToBigEndian(static_cast<quint64>(param.second));
        QString headerStr11 = "0000000055F080" + QString("%1").arg(param.second, 2, 16, QLatin1Char('0')).toUpper();
        QByteArray header11 = QByteArray::fromHex(headerStr11.toUtf8());

        // 构建完整数据包 (32字节)
        QByteArray packet;
        packet.append(header); // 8字节
        packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
        packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
        packet.append(header11);
        // 发送UDP数据包
        if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
            qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
        }
        else {
            qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
                << QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
        }
    }
    return 0; // 成功返回0
}
void SenderBinUdp::eraseCompleteSignal()
{
    stopSend();
    ui.toolButton_2->setEnabled(true);
}
void SenderBinUdp::writeCompleteSignal()
{
    ui.toolButton_2->setEnabled(false);
}