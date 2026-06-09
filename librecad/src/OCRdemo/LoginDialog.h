#pragma once

#include <QDialog>
#include <string>
#include <vector>
#include "ui_LoginDialog.h"

/**
 * @struct LoginResult
 * @brief 登录操作的结果数据
 */
struct LoginResult {
    bool accepted = false;      // 对话框是否被接受（登录/注销）
    bool isLoggedIn = false;    // true=登录成功, false=注销
    int userIndex = 0;
    std::string userName;

    // 权限字段（isLoggedIn=true 时有效）
    int PenMa = 0;
    int LiuShuixian = 0;
    int Chufa = 0;
    int FangZhen = 0;
    int PeiFang = 0;
    int xiangJi = 0;
    int CDL = 0;
    int YongHu = 0;
    int BianJi = 0;
};

/**
 * @class LoginDialog
 * @brief 用户登录/注销对话框
 *
 * 封装了用户登录/注销的完整交互流程：
 * - 显示用户名选择/输入、密码输入界面
 * - 验证用户身份
 * - 处理注销操作
 * - 通过 getResult() 返回登录结果
 *
 * 全局状态（USERname, m_isLoggedIn, 权限变量等）由对话框直接更新，
 * 主窗口只需根据 LoginResult 同步 UI 即可。
 */
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent = nullptr);
    ~LoginDialog() override;

    /** 获取登录/注销结果 */
    LoginResult getResult() const { return m_result; }

private:
    void initConnections();
    void doLogin();
    void doLogout();
    void syncResultToGlobals();
    void refreshUserList();

    Ui::LoginDialogClass ui;
    LoginResult m_result;
};
