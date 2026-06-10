#pragma once

#include <QMainWindow>
#include "ui_user.h"
#include "udptimesender.h"
#include "SenderBinUdp.h"

/**
 * @brief 用户管理界面
 *
 * 负责用户权限管理、添加/删除用户、修改密码、固件升级等功能。
 * 包含两个页面：用户设置（page）和增加用户（page_2），通过 QStackedWidget 切换。
 */
class user : public QMainWindow
{
    Q_OBJECT

public:
    explicit user(QWidget* parent = nullptr);
    ~user() override;

    /// 设置当前选中用户的权限显示及用户列表
    void setUser(int userindex, int PenMa, int LiuShuixian, int Chufa,
        int FangZhen, int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi,
        int TraverseUsernum, std::vector<std::string> Name);

    /// 切换用户时更新权限勾选状态
    void setSwitchUser(int PenMa, int LiuShuixian, int Chufa, int FangZhen,
        int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi);

    // === 当前选中用户的权限读取（page 页） ===
    int getPenMa();
    int getLiuShuixian();
    int getChufa();
    int getFangZhen();
    int getPeiFang();
    int getXiangJi();
    int getOCR();
    int getYongHu();
    int getZhuangTai();
    std::string getTraverseUsername();
    std::string getpassword();

    // === 新增用户的权限读取（page_2 页） ===
    int getPenMa1();
    int getLiuShuixian1();
    int getChufa1();
    int getFangZhen1();
    int getPeiFang1();
    int getXiangJi1();
    int getOCR1();
    int getYongHu1();
    int getZhuangTai1();
    std::string getTraverseUsername1();
    std::string getpassword1();

    QString openBinFilePath;
    UdpTimeSender timeSender;
    SenderBinUdp senderBinUdp;

    void openBinFile();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::userClass ui;

signals:
    void showmain();
    void addUser();
    void delUser();
    void SwitchUser();
    void alterpassword();
    void stopSend();
    void startSend();
    void usereraseCompleteSignal();
    void userwriteCompleteSignal();
    void userreadCompleteSignal();
};
