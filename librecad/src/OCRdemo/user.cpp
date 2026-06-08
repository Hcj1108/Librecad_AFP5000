#include "user.h"
#include<QMouseEvent>
#include<QMessageBox>
#include <QFileDialog>
#include<QTimer>
#include <vector>    // 必须包含vector头文件
#include <string>    // 必须包含string头文件

using namespace std;  // 使用std命名空间
user::user(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   timeSender.startSending(); // 默认发送到 192.168.1.10:1234
  // 正确连接信号
     // 连接SimpleUdpSender的startSend信号到timeSender的startSending
   connect(&senderBinUdp, &SenderBinUdp::startSend, this, [this]() {
       timeSender.startSending();  // 使用默认地址
       });

   // 连接SimpleUdpSender的stopSend信号到timeSender的stopSending
   connect(&senderBinUdp, &SenderBinUdp::stopSend, this, [this]() {
       timeSender.stopSending();
       });
    
   connect(this, &user::usereraseCompleteSignal, &senderBinUdp, &SenderBinUdp::eraseCompleteSignal);
   connect(this, &user::userwriteCompleteSignal, &senderBinUdp, &SenderBinUdp::writeCompleteSignal);
   connect(this, &user::userreadCompleteSignal, &senderBinUdp, &SenderBinUdp::writeCompleteSignal);
   connect(ui.MIN, &QPushButton::clicked, this, [=] {
        this->setWindowState(Qt::WindowMinimized);
        });

    connect(ui.BACK, &QPushButton::clicked, this, [=] {
        showmain();
        });
    connect(ui.toolButton, &QPushButton::clicked, this, [=] {
        ui.stackedWidget->setCurrentIndex(1);
        ui.lineEdit_3->clear();
        ui.lineEdit_4->clear();
        ui.checkBox_9->setChecked(false);
        ui.checkBox_13->setChecked(false);
        ui.checkBox_14->setChecked(false);
        ui.checkBox_11->setChecked(false);
        ui.checkBox_12->setChecked(false);
        ui.checkBox_10->setChecked(false);
        ui.checkBox_15->setChecked(false);
        ui.checkBox_16->setChecked(false);
       
        });
    connect(ui.toolButton_2, &QPushButton::clicked, this, [=] {
        delUser();
        });
    connect(ui.toolButton_3, &QPushButton::clicked, this, [=] {
        alterpassword();
        });
    connect(ui.toolButton_4, &QPushButton::clicked, this, [=] {
        addUser();
        });
    connect(ui.toolButton_5, &QPushButton::clicked, this, [=] {
        ui.stackedWidget->setCurrentIndex(0);
        });
    connect(ui.toolButton_6, &QPushButton::clicked, &senderBinUdp, &SenderBinUdp::show);
   
    connect(ui.comboBox_2, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        string username= ui.comboBox_2->currentText().toLocal8Bit();
        SelectUser(username);
        setSwitchUser(userinfo.PenMa, userinfo.LiuShuixian, userinfo.Chufa, userinfo.FangZhen, userinfo.PeiFang, userinfo.xiangJi, userinfo.CDL, userinfo.YongHu, userinfo.BianJi);
        });
    SetQSS();

}

user::~user()
{
}

void user::SetQSS()
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    qApp->installEventFilter(this);                   //给自己加事件过滤器,用来实现拖动窗口


}
bool user::eventFilter(QObject* obj, QEvent* evt)
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
void user::openBinFile()
{ 
    // 指定要操作的文件夹路径
   // QString targetDirectory = ""; // 或者您指定的其他路径
    QString fileName = QFileDialog::getOpenFileName(
        nullptr,
        QString::fromLocal8Bit("选择升级文件"),
        QDir::homePath(),  // 默认从用户主页目录开始
        //targetDirectory,  // 直接在指定文件夹开始
        QString::fromLocal8Bit("升级文件 (*.bin)")
    );
    openBinFilePath = fileName;
    // 检查用户是否选择了文件
    if (!fileName.isEmpty()) {
        //simpsender->sendFile(openBinFilePath, "192.168.50.192", 1234);
        //senderBinUdp.sendFile(openBinFilePath, "192.168.50.192", 1234);
        
    }
    else {
        // 用户取消选择时的处理（可选）
        qDebug() << "未选择文件";
    }
    
}

void user::setSwitchUser(int PenMa, int LiuShuixian, int Chufa, int FangZhen, int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi)
{
    ui.checkBox->setChecked(PenMa);
    ui.checkBox_6->setChecked(LiuShuixian);
    ui.checkBox_7->setChecked(Chufa);
    ui.checkBox_3->setChecked(FangZhen);
    ui.checkBox_4->setChecked(PeiFang);
    ui.checkBox_2->setChecked(xiangJi);
    ui.checkBox_5->setChecked(OCR);
    ui.checkBox_8->setChecked(YongHu);
    ui.checkBox_17->setChecked(BianJi);
}
void user::setUser(int userindex, int PenMa, int LiuShuixian, int Chufa, int FangZhen, int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi, int TraverseUsernum, std::vector<std::string> Name)
{
    ui.checkBox->setChecked(PenMa);
    ui.checkBox_6->setChecked(LiuShuixian);
    ui.checkBox_7->setChecked(Chufa);
    ui.checkBox_3->setChecked(FangZhen);
    ui.checkBox_4->setChecked(PeiFang);
    ui.checkBox_2->setChecked(xiangJi);
    ui.checkBox_5->setChecked(OCR);
    ui.checkBox_8->setChecked(YongHu);
    ui.checkBox_17->setChecked(BianJi);
    ui.stackedWidget->setCurrentIndex(0);
    ui.lineEdit_2->clear();
    ui.lineEdit_3->clear();
    ui.lineEdit_4->clear();
    ui.comboBox_2->clear();
    ui.comboBox_2->blockSignals(true);
    QString qstr;
    for (int i = 0; i < TraverseUsernum; i++)
    {
        qstr = QString::fromLocal8Bit(Name[i].c_str());
        ui.comboBox_2->addItem(qstr);
    }
    // 添加完成后恢复信号
    ui.comboBox_2->blockSignals(false);
    ui.comboBox_2->setCurrentIndex(userindex);
   

}
/*******************************************************保存数据库所须数据**********************************************************/
int user::getPenMa()
{
    return ui.checkBox->isChecked();
}
int user::getLiuShuixian()
{
    return ui.checkBox_6->isChecked();
}
int user::getChufa()
{
    return ui.checkBox_7->isChecked();
}
int user::getFangZhen()
{
    return ui.checkBox_3->isChecked();
}
int user::getPeiFang()
{
    return ui.checkBox_4->isChecked();
}
int user::getXiangJi()
{
    return ui.checkBox_2->isChecked();
}
int user::getOCR()
{
    return ui.checkBox_5->isChecked();
}
int user::getYongHu()
{
    return ui.checkBox_8->isChecked();
}
int user::getZhuangTai()
{
    return ui.checkBox_17->isChecked();
}
std::string user::getTraverseUsername()
{
    QByteArray bytes = ui.comboBox_2->currentText().toLocal8Bit();
    return std::string(bytes.constData());
}
std::string user::getpassword()
{
    QByteArray bytes = ui.lineEdit_2->text().toLocal8Bit();
    return std::string(bytes.constData());
}
/******************************************************新增用户所需数据************************************************************/
int user::getPenMa1()
{
    return ui.checkBox_9->isChecked();
}
int user::getLiuShuixian1()
{
    return ui.checkBox_13->isChecked();
}
int user::getChufa1()
{
    return ui.checkBox_14->isChecked();
}
int user::getFangZhen1()
{
    return ui.checkBox_11->isChecked();
}
int user::getPeiFang1()
{
    return ui.checkBox_12->isChecked();
}
int user::getXiangJi1()
{
    return ui.checkBox_10->isChecked();
}
int user::getOCR1()
{
    return ui.checkBox_15->isChecked();
}
int user::getYongHu1()
{
    return ui.checkBox_16->isChecked();
}
int user::getZhuangTai1()
{
    return ui.checkBox_18->isChecked();
}

std::string user::getTraverseUsername1()
{
    QByteArray bytes = ui.lineEdit_3->text().toLocal8Bit();
    return std::string(bytes.constData());
}
std::string user::getpassword1()
{
    QByteArray bytes = ui.lineEdit_4->text().toLocal8Bit();
    return std::string(bytes.constData());
}

