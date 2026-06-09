#include "LoginDialog.h"
#include "Config.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    refreshUserList();
    initConnections();
}

LoginDialog::~LoginDialog() = default;

void LoginDialog::refreshUserList()
{
    TraverseUsernum = TraverseUser();
    ui.usernameCombo->clear();
    ui.usernameCombo->setPlaceholderText(QString::fromLocal8Bit("\xd1\xa1\xd4\xf1\xbb\xf2\xca\xe4\xc8\xeb\xd3\xc3\xbb\xa7\xc3\xfb"));
    for (int i = 0; i < TraverseUser(); i++) {
        ui.usernameCombo->addItem(QString::fromLocal8Bit(Name[i].c_str()));
    }

    // 默认选中第一个用户（通常是管理员）
    if (ui.usernameCombo->count() > 0) {
        ui.usernameCombo->setCurrentIndex(0);
    }
    ui.passwordEdit->setFocus();

    // 根据登录状态切换按钮显示
    ui.loginBtn->setVisible(!m_isLoggedIn);
    ui.logoutBtn->setVisible(m_isLoggedIn);
    ui.passwordEdit->setVisible(!m_isLoggedIn);
    ui.labelPass->setVisible(!m_isLoggedIn);
}

void LoginDialog::initConnections()
{
    connect(ui.loginBtn, &QPushButton::clicked, this, &LoginDialog::doLogin);
    connect(ui.logoutBtn, &QPushButton::clicked, this, &LoginDialog::doLogout);
    connect(ui.cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    // 回车键登录
    connect(ui.passwordEdit, &QLineEdit::returnPressed, this, &LoginDialog::doLogin);
}

void LoginDialog::doLogin()
{
    std::string username = ui.usernameCombo->currentText().toLocal8Bit().constData();
    std::string password = ui.passwordEdit->text().toStdString();

    if (username.empty()) {
        QMessageBox::warning(this,
            QString::fromLocal8Bit("\xca\xe4\xc8\xeb\xb4\xed\xce\xf3"),
            QString::fromLocal8Bit("\xc7\xeb\xca\xe4\xc8\xeb\xd3\xc3\xbb\xa7\xc3\xfb"));
        return;
    }

    if (password.empty()) {
        QMessageBox::warning(this,
            QString::fromLocal8Bit("\xca\xe4\xc8\xeb\xb4\xed\xce\xf3"),
            QString::fromLocal8Bit("\xc7\xeb\xca\xe4\xc8\xeb\xc3\xdc\xc2\xeb"));
        return;
    }

    SelectUser(username);

    if (password != userinfo.password) {
        QMessageBox::warning(this,
            QString::fromLocal8Bit("\xca\xe4\xc8\xeb\xb4\xed\xce\xf3"),
            QString::fromLocal8Bit("\xc3\xdc\xc2\xeb\xb4\xed\xce\xf3"));
        return;
    }

    // 登录成功
    m_isLoggedIn = true;

    // 查找用户索引
    m_result.userIndex = 0;
    for (int i = 0; i < TraverseUser(); i++) {
        if (Name[i] == username) {
            m_result.userIndex = i;
            break;
        }
    }

    // 填充结果
    m_result.accepted = true;
    m_result.isLoggedIn = true;
    m_result.userName = userinfo.USERname;
    m_result.PenMa = userinfo.PenMa;
    m_result.LiuShuixian = userinfo.LiuShuixian;
    m_result.Chufa = userinfo.Chufa;
    m_result.FangZhen = userinfo.FangZhen;
    m_result.PeiFang = userinfo.PeiFang;
    m_result.xiangJi = userinfo.xiangJi;
    m_result.CDL = userinfo.CDL;
    m_result.YongHu = userinfo.YongHu;
    m_result.BianJi = userinfo.BianJi;

    syncResultToGlobals();
    accept();
}

void LoginDialog::doLogout()
{
    m_isLoggedIn = false;

    m_result.accepted = true;
    m_result.isLoggedIn = false;
    m_result.userName = "\xce\xb4\xb5\xc7\xc2\xbc";
    m_result.PenMa = 0;
    m_result.LiuShuixian = 0;
    m_result.Chufa = 0;
    m_result.FangZhen = 0;
    m_result.PeiFang = 0;
    m_result.xiangJi = 0;
    m_result.CDL = 0;
    m_result.YongHu = 0;
    m_result.BianJi = 0;

    syncResultToGlobals();
    accept();
}

void LoginDialog::syncResultToGlobals()
{
    USERname = m_result.userName;
    PenMa = m_result.PenMa;
    LiuShuixian = m_result.LiuShuixian;
    Chufa = m_result.Chufa;
    FangZhen = m_result.FangZhen;
    PeiFang = m_result.PeiFang;
    xiangJi = m_result.xiangJi;
    CDL = m_result.CDL;
    YongHu = m_result.YongHu;
    BianJi = m_result.BianJi;
}
