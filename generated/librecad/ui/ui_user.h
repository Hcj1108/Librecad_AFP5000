/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *pageLayout;
    QGroupBox *groupBox;
    QHBoxLayout *userLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *userListLayout;
    QComboBox *comboBox_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *permLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_17;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *rightPanel;
    QGroupBox *groupBox_6;
    QVBoxLayout *passwdLayout;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_3;
    QGroupBox *groupBox_8;
    QVBoxLayout *firmwareLayout;
    QToolButton *toolButton_6;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnClose;
    QWidget *page_2;
    QVBoxLayout *page2Layout;
    QGroupBox *groupBox_4;
    QHBoxLayout *addUserLayout;
    QVBoxLayout *addFormPanel;
    QHBoxLayout *hl_username;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *hl_password;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *hl_buttons;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QSpacerItem *vSpacer6;
    QGroupBox *groupBox_5;
    QVBoxLayout *setPermLayout;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_18;
    QSpacerItem *vSpacer7;

    void setupUi(QMainWindow *userClass)
    {
        if (userClass->objectName().isEmpty())
            userClass->setObjectName(QString::fromUtf8("userClass"));
        userClass->resize(897, 502);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/YHGL.png"), QSize(), QIcon::Normal, QIcon::Off);
        userClass->setWindowIcon(icon);
        userClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        centralWidget = new QWidget(userClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pageLayout = new QVBoxLayout(page);
        pageLayout->setSpacing(0);
        pageLayout->setObjectName(QString::fromUtf8("pageLayout"));
        pageLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        userLayout = new QHBoxLayout(groupBox);
        userLayout->setSpacing(10);
        userLayout->setObjectName(QString::fromUtf8("userLayout"));
        userLayout->setContentsMargins(15, 25, 15, 15);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 6px; margin-top: 10px; padding-top: 12px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 8px; padding: 0 4px;}"));
        userListLayout = new QVBoxLayout(groupBox_3);
        userListLayout->setSpacing(8);
        userListLayout->setObjectName(QString::fromUtf8("userListLayout"));
        userListLayout->setContentsMargins(15, 22, 15, 15);
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(119, 36));
        comboBox_2->setMaximumSize(QSize(119, 36));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QComboBox:focus{border-color: #3498db;}\n"
"QComboBox::drop-down{width: 28px;}"));
        comboBox_2->setMinimumContentsLength(0);

        userListLayout->addWidget(comboBox_2);

        toolButton = new QToolButton(groupBox_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(119, 38));
        toolButton->setMaximumSize(QSize(119, 38));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PNG/Resources/PNG/adduser.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        userListLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(groupBox_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(119, 38));
        toolButton_2->setMaximumSize(QSize(119, 38));
        toolButton_2->setFont(font);
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #c0392b;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PNG/Resources/PNG/SCuser.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        userListLayout->addWidget(toolButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        userListLayout->addItem(verticalSpacer);


        userLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 6px; margin-top: 10px; padding-top: 12px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 8px; padding: 0 4px;}"));
        permLayout = new QVBoxLayout(groupBox_2);
        permLayout->setSpacing(4);
        permLayout->setObjectName(QString::fromUtf8("permLayout"));
        permLayout->setContentsMargins(12, 22, 12, 10);
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        checkBox->setFont(font1);

        permLayout->addWidget(checkBox);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font1);

        permLayout->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setFont(font1);

        permLayout->addWidget(checkBox_7);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font1);

        permLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setFont(font1);

        permLayout->addWidget(checkBox_4);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font1);

        permLayout->addWidget(checkBox_2);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setFont(font1);

        permLayout->addWidget(checkBox_5);

        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setFont(font1);

        permLayout->addWidget(checkBox_8);

        checkBox_17 = new QCheckBox(groupBox_2);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setFont(font1);

        permLayout->addWidget(checkBox_17);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        permLayout->addItem(verticalSpacer_5);


        userLayout->addWidget(groupBox_2);

        rightPanel = new QVBoxLayout();
        rightPanel->setSpacing(6);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setFont(font);
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 6px; margin-top: 10px; padding-top: 12px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 8px; padding: 0 4px;}"));
        passwdLayout = new QVBoxLayout(groupBox_6);
        passwdLayout->setSpacing(8);
        passwdLayout->setObjectName(QString::fromUtf8("passwdLayout"));
        passwdLayout->setContentsMargins(12, 22, 12, 12);
        lineEdit_2 = new QLineEdit(groupBox_6);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 36));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setBold(false);
        font2.setItalic(false);
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{font: 12px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);

        passwdLayout->addWidget(lineEdit_2);

        toolButton_3 = new QToolButton(groupBox_6);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(119, 38));
        toolButton_3->setMaximumSize(QSize(119, 38));
        toolButton_3->setFont(font);
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #f39c12; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #e67e22;}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PNG/Resources/PNG/XGMM.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(20, 20));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        passwdLayout->addWidget(toolButton_3);


        rightPanel->addWidget(groupBox_6);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setFont(font);
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 6px; margin-top: 10px; padding-top: 12px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 8px; padding: 0 4px;}"));
        firmwareLayout = new QVBoxLayout(groupBox_8);
        firmwareLayout->setSpacing(8);
        firmwareLayout->setObjectName(QString::fromUtf8("firmwareLayout"));
        firmwareLayout->setContentsMargins(12, 22, 12, 12);
        toolButton_6 = new QToolButton(groupBox_8);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(119, 38));
        toolButton_6->setMaximumSize(QSize(119, 38));
        toolButton_6->setFont(font);
        toolButton_6->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #27ae60; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #229954;}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PNG/Resources/PNG/Gengxing.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon4);
        toolButton_6->setIconSize(QSize(20, 20));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        firmwareLayout->addWidget(toolButton_6);


        rightPanel->addWidget(groupBox_8);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        rightPanel->addItem(verticalSpacer_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnClose = new QPushButton(groupBox);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(80, 36));
        btnClose->setMaximumSize(QSize(80, 36));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #c0392b;}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon5);
        btnClose->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btnClose);


        rightPanel->addLayout(horizontalLayout);


        userLayout->addLayout(rightPanel);


        pageLayout->addWidget(groupBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page2Layout = new QVBoxLayout(page_2);
        page2Layout->setSpacing(0);
        page2Layout->setObjectName(QString::fromUtf8("page2Layout"));
        page2Layout->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(page_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        addUserLayout = new QHBoxLayout(groupBox_4);
        addUserLayout->setSpacing(15);
        addUserLayout->setObjectName(QString::fromUtf8("addUserLayout"));
        addUserLayout->setContentsMargins(15, 25, 15, 15);
        addFormPanel = new QVBoxLayout();
        addFormPanel->setSpacing(10);
        addFormPanel->setObjectName(QString::fromUtf8("addFormPanel"));
        hl_username = new QHBoxLayout();
        hl_username->setObjectName(QString::fromUtf8("hl_username"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        hl_username->addWidget(label_3);

        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(150, 36));
        lineEdit_3->setFont(font2);
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{font: 12px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_username->addWidget(lineEdit_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_username->addItem(horizontalSpacer);


        addFormPanel->addLayout(hl_username);

        hl_password = new QHBoxLayout();
        hl_password->setObjectName(QString::fromUtf8("hl_password"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        hl_password->addWidget(label_4);

        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(150, 36));
        lineEdit_4->setFont(font2);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit{font: 12px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_password->addWidget(lineEdit_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_password->addItem(horizontalSpacer_2);


        addFormPanel->addLayout(hl_password);

        hl_buttons = new QHBoxLayout();
        hl_buttons->setObjectName(QString::fromUtf8("hl_buttons"));
        toolButton_4 = new QToolButton(groupBox_4);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(119, 38));
        toolButton_4->setMaximumSize(QSize(119, 38));
        toolButton_4->setFont(font);
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));
        toolButton_4->setIcon(icon);
        toolButton_4->setIconSize(QSize(20, 20));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        hl_buttons->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(groupBox_4);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(119, 38));
        toolButton_5->setMaximumSize(QSize(119, 38));
        toolButton_5->setFont(font);
        toolButton_5->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #7f8c8d;}"));
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(20, 20));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        hl_buttons->addWidget(toolButton_5);


        addFormPanel->addLayout(hl_buttons);

        vSpacer6 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addFormPanel->addItem(vSpacer6);


        addUserLayout->addLayout(addFormPanel);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 6px; margin-top: 10px; padding-top: 12px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 8px; padding: 0 4px;}"));
        setPermLayout = new QVBoxLayout(groupBox_5);
        setPermLayout->setSpacing(4);
        setPermLayout->setObjectName(QString::fromUtf8("setPermLayout"));
        setPermLayout->setContentsMargins(15, 22, 15, 10);
        checkBox_9 = new QCheckBox(groupBox_5);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setFont(font1);

        setPermLayout->addWidget(checkBox_9);

        checkBox_13 = new QCheckBox(groupBox_5);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setFont(font1);

        setPermLayout->addWidget(checkBox_13);

        checkBox_14 = new QCheckBox(groupBox_5);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setFont(font1);

        setPermLayout->addWidget(checkBox_14);

        checkBox_11 = new QCheckBox(groupBox_5);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setFont(font1);

        setPermLayout->addWidget(checkBox_11);

        checkBox_12 = new QCheckBox(groupBox_5);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setFont(font1);

        setPermLayout->addWidget(checkBox_12);

        checkBox_10 = new QCheckBox(groupBox_5);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setFont(font1);

        setPermLayout->addWidget(checkBox_10);

        checkBox_15 = new QCheckBox(groupBox_5);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setFont(font1);

        setPermLayout->addWidget(checkBox_15);

        checkBox_16 = new QCheckBox(groupBox_5);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setFont(font1);

        setPermLayout->addWidget(checkBox_16);

        checkBox_18 = new QCheckBox(groupBox_5);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setFont(font1);

        setPermLayout->addWidget(checkBox_18);

        vSpacer7 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        setPermLayout->addItem(vSpacer7);


        addUserLayout->addWidget(groupBox_5);


        page2Layout->addWidget(groupBox_4);

        stackedWidget->addWidget(page_2);

        mainLayout->addWidget(stackedWidget);

        userClass->setCentralWidget(centralWidget);

        retranslateUi(userClass);

        stackedWidget->setCurrentIndex(0);
        comboBox_2->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(userClass);
    } // setupUi

    void retranslateUi(QMainWindow *userClass)
    {
        userClass->setWindowTitle(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        groupBox->setTitle(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\345\210\227\350\241\250", nullptr));
        toolButton->setText(QCoreApplication::translate("userClass", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        toolButton_2->setText(QCoreApplication::translate("userClass", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("userClass", "\346\235\203\351\231\220\350\256\276\347\275\256", nullptr));
        checkBox->setText(QCoreApplication::translate("userClass", "\345\226\267\347\240\201\345\217\202\346\225\260", nullptr));
        checkBox_6->setText(QCoreApplication::translate("userClass", "\346\265\201\346\260\264\347\272\277\350\256\276\347\275\256", nullptr));
        checkBox_7->setText(QCoreApplication::translate("userClass", "\346\211\223\347\240\201\350\247\246\345\217\221\344\274\230\345\214\226", nullptr));
        checkBox_3->setText(QCoreApplication::translate("userClass", "\344\273\277\347\234\237\350\256\276\347\275\256", nullptr));
        checkBox_4->setText(QCoreApplication::translate("userClass", "\351\205\215\346\226\271\347\256\241\347\220\206", nullptr));
        checkBox_2->setText(QCoreApplication::translate("userClass", "\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        checkBox_5->setText(QCoreApplication::translate("userClass", "\350\217\234\345\215\225\346\240\217\350\256\276\347\275\256", nullptr));
        checkBox_8->setText(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\346\235\203\351\231\220", nullptr));
        checkBox_17->setText(QCoreApplication::translate("userClass", "\347\212\266\346\200\201", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("userClass", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        toolButton_3->setText(QCoreApplication::translate("userClass", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("userClass", "\345\233\272\344\273\266\345\215\207\347\272\247", nullptr));
        toolButton_6->setText(QCoreApplication::translate("userClass", "\345\233\272\344\273\266\345\215\207\347\272\247", nullptr));
        btnClose->setText(QCoreApplication::translate("userClass", "\345\205\263\351\227\255", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("userClass", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        label_3->setText(QCoreApplication::translate("userClass", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("userClass", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        toolButton_4->setText(QCoreApplication::translate("userClass", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        toolButton_5->setText(QCoreApplication::translate("userClass", "\350\277\224\345\233\236", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("userClass", "\350\256\276\347\275\256\346\235\203\351\231\220", nullptr));
        checkBox_9->setText(QCoreApplication::translate("userClass", "\345\226\267\347\240\201\345\217\202\346\225\260", nullptr));
        checkBox_13->setText(QCoreApplication::translate("userClass", "\346\265\201\346\260\264\347\272\277\350\256\276\347\275\256", nullptr));
        checkBox_14->setText(QCoreApplication::translate("userClass", "\350\247\246\345\217\221\344\274\230\345\214\226", nullptr));
        checkBox_11->setText(QCoreApplication::translate("userClass", "\344\273\277\347\234\237\350\256\276\347\275\256", nullptr));
        checkBox_12->setText(QCoreApplication::translate("userClass", "\351\205\215\346\226\271\347\256\241\347\220\206", nullptr));
        checkBox_10->setText(QCoreApplication::translate("userClass", "\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        checkBox_15->setText(QCoreApplication::translate("userClass", "\350\217\234\345\215\225\346\240\217\350\256\276\347\275\256", nullptr));
        checkBox_16->setText(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\346\235\203\351\231\220", nullptr));
        checkBox_18->setText(QCoreApplication::translate("userClass", "\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userClass: public Ui_userClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
