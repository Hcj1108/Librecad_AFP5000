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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_8;
    QGroupBox *groupBox_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_17;
    QGroupBox *groupBox_6;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_3;
    QGroupBox *groupBox_8;
    QToolButton *toolButton_6;
    QWidget *page_2;
    QGroupBox *groupBox_4;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_18;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QLabel *label;
    QToolButton *MIN;
    QToolButton *BACK;
    QFrame *line_3;
    QFrame *line_4;

    void setupUi(QMainWindow *userClass)
    {
        if (userClass->objectName().isEmpty())
            userClass->setObjectName(QString::fromUtf8("userClass"));
        userClass->resize(841, 621);
        userClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        centralWidget = new QWidget(userClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(5, 90, 831, 501));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 791, 501));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 30, 161, 281));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        groupBox_3->setFont(font1);
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 30, 121, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        comboBox_2->setFont(font2);
        comboBox_2->setMinimumContentsLength(0);
        toolButton = new QToolButton(groupBox_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(20, 100, 110, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setItalic(false);
        toolButton->setFont(font3);
        toolButton->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/adduser.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolButton_2 = new QToolButton(groupBox_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(20, 190, 110, 40));
        toolButton_2->setFont(font3);
        toolButton_2->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PNG/Resources/PNG/SCuser.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 30, 201, 461));
        groupBox_2->setFont(font1);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        groupBox_2->setChecked(false);
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(30, 270, 111, 31));
        checkBox_2->setFont(font2);
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(30, 170, 111, 31));
        checkBox_3->setFont(font2);
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(30, 220, 111, 31));
        checkBox_4->setFont(font2);
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(30, 320, 111, 31));
        checkBox_5->setFont(font2);
        checkBox_5->setChecked(false);
        checkBox_5->setAutoRepeat(false);
        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(30, 370, 111, 41));
        checkBox_8->setFont(font2);
        checkBox_8->setChecked(false);
        checkBox_8->setAutoRepeat(false);
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 20, 161, 141));
        groupBox_7->setCheckable(false);
        checkBox = new QCheckBox(groupBox_7);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 20, 111, 31));
        checkBox->setFont(font2);
        checkBox->setMouseTracking(true);
        checkBox->setCheckable(true);
        checkBox->setChecked(false);
        checkBox->setAutoRepeat(false);
        checkBox->setAutoExclusive(false);
        checkBox->setTristate(false);
        checkBox_6 = new QCheckBox(groupBox_7);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(20, 60, 111, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(12);
        font4.setBold(false);
        checkBox_6->setFont(font4);
        checkBox_7 = new QCheckBox(groupBox_7);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(20, 100, 121, 31));
        checkBox_7->setFont(font2);
        checkBox_17 = new QCheckBox(groupBox_2);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setGeometry(QRect(30, 420, 111, 31));
        checkBox_17->setFont(font2);
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(420, 30, 161, 161));
        groupBox_6->setFont(font1);
        lineEdit_2 = new QLineEdit(groupBox_6);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 30, 111, 41));
        lineEdit_2->setFont(font2);
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        toolButton_3 = new QToolButton(groupBox_6);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(20, 100, 110, 40));
        toolButton_3->setFont(font3);
        toolButton_3->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PNG/Resources/PNG/XGMM.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(40, 40));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(600, 30, 151, 111));
        groupBox_8->setFont(font1);
        toolButton_6 = new QToolButton(groupBox_8);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(20, 30, 110, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(8);
        font5.setBold(true);
        toolButton_6->setFont(font5);
        toolButton_6->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PNG/Resources/PNG/Gengxing.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon3);
        toolButton_6->setIconSize(QSize(40, 40));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox_4 = new QGroupBox(page_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 0, 791, 501));
        groupBox_4->setFont(font);
        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 40, 113, 31));
        lineEdit_3->setFont(font2);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 40, 81, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 110, 81, 31));
        label_4->setFont(font2);
        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 110, 113, 31));
        lineEdit_4->setFont(font2);
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(290, 20, 221, 471));
        groupBox_5->setFont(font1);
        groupBox_5->setFlat(false);
        groupBox_5->setCheckable(false);
        groupBox_5->setChecked(false);
        checkBox_9 = new QCheckBox(groupBox_5);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(50, 28, 101, 31));
        checkBox_9->setFont(font2);
        checkBox_9->setMouseTracking(true);
        checkBox_9->setCheckable(true);
        checkBox_9->setChecked(false);
        checkBox_9->setAutoRepeat(false);
        checkBox_9->setAutoExclusive(false);
        checkBox_9->setTristate(false);
        checkBox_10 = new QCheckBox(groupBox_5);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(50, 270, 101, 31));
        checkBox_10->setFont(font2);
        checkBox_11 = new QCheckBox(groupBox_5);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setGeometry(QRect(50, 170, 101, 31));
        checkBox_11->setFont(font2);
        checkBox_12 = new QCheckBox(groupBox_5);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setGeometry(QRect(50, 220, 101, 31));
        checkBox_12->setFont(font2);
        checkBox_13 = new QCheckBox(groupBox_5);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setGeometry(QRect(50, 70, 101, 31));
        checkBox_13->setFont(font2);
        checkBox_14 = new QCheckBox(groupBox_5);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setGeometry(QRect(50, 120, 101, 31));
        checkBox_14->setFont(font2);
        checkBox_15 = new QCheckBox(groupBox_5);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setGeometry(QRect(50, 330, 101, 31));
        checkBox_15->setFont(font2);
        checkBox_15->setChecked(false);
        checkBox_15->setAutoRepeat(false);
        checkBox_16 = new QCheckBox(groupBox_5);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setGeometry(QRect(50, 380, 101, 31));
        checkBox_16->setFont(font2);
        checkBox_16->setChecked(false);
        checkBox_16->setAutoRepeat(false);
        checkBox_18 = new QCheckBox(groupBox_5);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setGeometry(QRect(50, 430, 111, 31));
        checkBox_18->setFont(font2);
        toolButton_5 = new QToolButton(groupBox_4);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(520, 30, 110, 40));
        toolButton_5->setFont(font3);
        toolButton_5->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setIconSize(QSize(40, 40));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolButton_4 = new QToolButton(groupBox_4);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(520, 130, 110, 40));
        toolButton_4->setFont(font3);
        toolButton_4->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PNG/Resources/PNG/YHGL.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon5);
        toolButton_4->setIconSize(QSize(40, 40));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        stackedWidget->addWidget(page_2);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 10, 191, 54));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(20);
        font6.setBold(true);
        label->setFont(font6);
        label->setStyleSheet(QString::fromUtf8("opacity: 1;\n"
"border-radius: 15px;  \n"
"border: 2px solid #4CAF50;\n"
"padding: 5px 15px;\n"
"min-width: 100px;\n"
"min-height: 40px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MIN = new QToolButton(centralWidget);
        MIN->setObjectName(QString::fromUtf8("MIN"));
        MIN->setGeometry(QRect(740, 20, 40, 40));
        MIN->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PIC/Resources/PICs/branch_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        MIN->setIcon(icon6);
        MIN->setIconSize(QSize(16, 16));
        BACK = new QToolButton(centralWidget);
        BACK->setObjectName(QString::fromUtf8("BACK"));
        BACK->setGeometry(QRect(791, 20, 40, 40));
        BACK->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/PIC/Resources/PICs/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        BACK->setIcon(icon7);
        BACK->setIconSize(QSize(16, 16));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 600, 811, 20));
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(20, 70, 801, 20));
        line_4->setLineWidth(3);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        userClass->setCentralWidget(centralWidget);

        retranslateUi(userClass);

        stackedWidget->setCurrentIndex(1);
        comboBox_2->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(userClass);
    } // setupUi

    void retranslateUi(QMainWindow *userClass)
    {
        userClass->setWindowTitle(QCoreApplication::translate("userClass", "user", nullptr));
        groupBox->setTitle(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\345\210\227\350\241\250", nullptr));
        toolButton->setText(QCoreApplication::translate("userClass", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        toolButton_2->setText(QCoreApplication::translate("userClass", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("userClass", "\346\235\203\351\231\220\350\256\276\347\275\256", nullptr));
        checkBox_2->setText(QCoreApplication::translate("userClass", "\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        checkBox_3->setText(QCoreApplication::translate("userClass", "\344\273\277\347\234\237\350\256\276\347\275\256", nullptr));
        checkBox_4->setText(QCoreApplication::translate("userClass", "\351\205\215\346\226\271\347\256\241\347\220\206", nullptr));
        checkBox_5->setText(QCoreApplication::translate("userClass", "\350\217\234\345\215\225\346\240\217\350\256\276\347\275\256", nullptr));
        checkBox_8->setText(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\346\235\203\351\231\220", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("userClass", "\346\211\223\345\215\260\345\217\202\346\225\260", nullptr));
        checkBox->setText(QCoreApplication::translate("userClass", "\345\226\267\347\240\201\345\217\202\346\225\260", nullptr));
        checkBox_6->setText(QCoreApplication::translate("userClass", "\346\265\201\346\260\264\347\272\277\350\256\276\347\275\256", nullptr));
        checkBox_7->setText(QCoreApplication::translate("userClass", "\346\211\223\347\240\201\350\247\246\345\217\221\344\274\230\345\214\226", nullptr));
        checkBox_17->setText(QCoreApplication::translate("userClass", "\347\212\266\346\200\201", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("userClass", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        toolButton_3->setText(QCoreApplication::translate("userClass", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("userClass", "\345\233\272\344\273\266\345\215\207\347\272\247", nullptr));
        toolButton_6->setText(QCoreApplication::translate("userClass", "\345\233\272\344\273\266\345\215\207\347\272\247", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("userClass", "\345\242\236\345\212\240\347\224\250\346\210\267", nullptr));
        label_3->setText(QCoreApplication::translate("userClass", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("userClass", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("userClass", "\350\256\276\347\275\256\346\235\203\351\231\220", nullptr));
        checkBox_9->setText(QCoreApplication::translate("userClass", "\345\226\267\347\240\201\345\217\202\346\225\260", nullptr));
        checkBox_10->setText(QCoreApplication::translate("userClass", "\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        checkBox_11->setText(QCoreApplication::translate("userClass", "\344\273\277\347\234\237\350\256\276\347\275\256", nullptr));
        checkBox_12->setText(QCoreApplication::translate("userClass", "\351\205\215\346\226\271\347\256\241\347\220\206", nullptr));
        checkBox_13->setText(QCoreApplication::translate("userClass", "\346\265\201\346\260\264\347\272\277\350\256\276\347\275\256", nullptr));
        checkBox_14->setText(QCoreApplication::translate("userClass", "\350\247\246\345\217\221\344\274\230\345\214\226", nullptr));
        checkBox_15->setText(QCoreApplication::translate("userClass", "\350\217\234\345\215\225\346\240\217\350\256\276\347\275\256", nullptr));
        checkBox_16->setText(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\346\235\203\351\231\220", nullptr));
        checkBox_18->setText(QCoreApplication::translate("userClass", "\347\212\266\346\200\201", nullptr));
        toolButton_5->setText(QCoreApplication::translate("userClass", "\350\277\224\345\233\236", nullptr));
        toolButton_4->setText(QCoreApplication::translate("userClass", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("userClass", "\347\224\250\346\210\267\346\235\203\351\231\220", nullptr));
        MIN->setText(QCoreApplication::translate("userClass", "MIN", nullptr));
        BACK->setText(QCoreApplication::translate("userClass", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userClass: public Ui_userClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
