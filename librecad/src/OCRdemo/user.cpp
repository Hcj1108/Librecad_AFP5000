#include "user.h"
#include "Config.h"
#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QDir>

using namespace std;

/**
 * @brief 构造函数
 *
 * 初始化用户管理界面：
 * - 设置 UI 布局
 * - 绑定按钮事件
 * - 配置系统标题栏（含关闭按钮）
 * - 固定窗口大小
 */
user::user(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    timeSender.startSending();

    // SenderBinUdp 信号转发
    connect(&senderBinUdp, &SenderBinUdp::startSend, this, [this]() {
        timeSender.startSending();
    });
    connect(&senderBinUdp, &SenderBinUdp::stopSend, this, [this]() {
        timeSender.stopSending();
    });
    connect(this, &user::usereraseCompleteSignal, &senderBinUdp, &SenderBinUdp::eraseCompleteSignal);
    connect(this, &user::userwriteCompleteSignal, &senderBinUdp, &SenderBinUdp::writeCompleteSignal);
    connect(this, &user::userreadCompleteSignal, &senderBinUdp, &SenderBinUdp::writeCompleteSignal);

    // 按钮：切换到增加用户页面
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

    // 删除用户
    connect(ui.toolButton_2, &QPushButton::clicked, this, [=] {
        delUser();
    });

    // 修改密码
    connect(ui.toolButton_3, &QPushButton::clicked, this, [=] {
        alterpassword();
    });

    // 添加用户
    connect(ui.toolButton_4, &QPushButton::clicked, this, [=] {
        addUser();
    });

    // 返回用户列表页
    connect(ui.toolButton_5, &QPushButton::clicked, this, [=] {
        ui.stackedWidget->setCurrentIndex(0);
    });

    // 固件升级
    connect(ui.toolButton_6, &QPushButton::clicked, &senderBinUdp, &SenderBinUdp::show);

    // 用户切换
    connect(ui.comboBox_2, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        string username = ui.comboBox_2->currentText().toLocal8Bit();
        SelectUser(username);
        setSwitchUser(userinfo.PenMa, userinfo.LiuShuixian, userinfo.Chufa,
            userinfo.FangZhen, userinfo.PeiFang, userinfo.xiangJi,
            userinfo.CDL, userinfo.YongHu, userinfo.BianJi);
    });

    // 窗口样式：标准系统标题栏（含关闭按钮）
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
   
}

user::~user() = default;

/**
 * @brief 重写关闭事件
 *
 * 点击窗口标题栏的关闭按钮时，隐藏窗口并发射 showmain 信号，
 * 通知主窗口重新显示，而非销毁窗口。
 */
void user::closeEvent(QCloseEvent* event)
{
    this->hide();
    emit showmain();
    event->ignore();
}

/**
 * @brief 设置当前选中用户的权限显示及用户列表
 *
 * 更新面板 page 的权限勾选框、刷新用户列表、定位到当前用户。
 */
void user::setUser(int userindex, int PenMa, int LiuShuixian, int Chufa,
    int FangZhen, int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi,
    int TraverseUsernum, std::vector<std::string> Name)
{
    ui.checkBox->setChecked(PenMa);          // 喷码参数
    ui.checkBox_6->setChecked(LiuShuixian);  // 流水线设置
    ui.checkBox_7->setChecked(Chufa);        // 打码触发优化
    ui.checkBox_3->setChecked(FangZhen);     // 仿真设置
    ui.checkBox_4->setChecked(PeiFang);      // 配方管理
    ui.checkBox_2->setChecked(xiangJi);      // 相机参数
    ui.checkBox_5->setChecked(OCR);          // 菜单栏设置
    ui.checkBox_8->setChecked(YongHu);       // 用户权限
    ui.checkBox_17->setChecked(BianJi);      // 状态

    ui.stackedWidget->setCurrentIndex(0);
    ui.lineEdit_2->clear();
    ui.lineEdit_3->clear();
    ui.lineEdit_4->clear();

    // 刷新用户列表
    ui.comboBox_2->blockSignals(true);
    ui.comboBox_2->clear();
    for (int i = 0; i < TraverseUsernum; i++) {
        ui.comboBox_2->addItem(QString::fromLocal8Bit(Name[i].c_str()));
    }
    ui.comboBox_2->blockSignals(false);
    ui.comboBox_2->setCurrentIndex(userindex);
}

/**
 * @brief 切换用户时更新权限勾选状态
 */
void user::setSwitchUser(int PenMa, int LiuShuixian, int Chufa, int FangZhen,
    int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi)
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

// ====================== 当前用户权限读取 ======================
int user::getPenMa()         { return ui.checkBox->isChecked(); }
int user::getLiuShuixian()   { return ui.checkBox_6->isChecked(); }
int user::getChufa()         { return ui.checkBox_7->isChecked(); }
int user::getFangZhen()      { return ui.checkBox_3->isChecked(); }
int user::getPeiFang()       { return ui.checkBox_4->isChecked(); }
int user::getXiangJi()       { return ui.checkBox_2->isChecked(); }
int user::getOCR()           { return ui.checkBox_5->isChecked(); }
int user::getYongHu()        { return ui.checkBox_8->isChecked(); }
int user::getZhuangTai()     { return ui.checkBox_17->isChecked(); }
std::string user::getTraverseUsername() {
    return ui.comboBox_2->currentText().toLocal8Bit().constData();
}
std::string user::getpassword() {
    return ui.lineEdit_2->text().toLocal8Bit().constData();
}

// ====================== 新增用户权限读取 ======================
int user::getPenMa1()        { return ui.checkBox_9->isChecked(); }
int user::getLiuShuixian1()  { return ui.checkBox_13->isChecked(); }
int user::getChufa1()        { return ui.checkBox_14->isChecked(); }
int user::getFangZhen1()     { return ui.checkBox_11->isChecked(); }
int user::getPeiFang1()      { return ui.checkBox_12->isChecked(); }
int user::getXiangJi1()      { return ui.checkBox_10->isChecked(); }
int user::getOCR1()          { return ui.checkBox_15->isChecked(); }
int user::getYongHu1()       { return ui.checkBox_16->isChecked(); }
int user::getZhuangTai1()    { return ui.checkBox_18->isChecked(); }
std::string user::getTraverseUsername1() {
    return ui.lineEdit_3->text().toLocal8Bit().constData();
}
std::string user::getpassword1() {
    return ui.lineEdit_4->text().toLocal8Bit().constData();
}

/**
 * @brief 打开二进制文件（用于固件升级）
 */
void user::openBinFile()
{
    QString fileName = QFileDialog::getOpenFileName(
        nullptr,
        QString::fromLocal8Bit("\xd1\xa1\xd4\xf1\xb9\xcc\xbc\xfe\xce\xc4\xbc\xfe"),
        QDir::homePath(),
        QString::fromLocal8Bit("\xb9\xcc\xbc\xfe\xce\xc4\xbc\xfe (*.bin)")
    );
    openBinFilePath = fileName;
    if (!fileName.isEmpty()) {
        qDebug() << "\xd2\xd1\xd1\xa1\xd4\xf1\xce\xc4\xbc\xfe:" << fileName;
    } else {
        qDebug() << "\xce\xb4\xd1\xa1\xd4\xf1\xce\xc4\xbc\xfe";
    }
}
