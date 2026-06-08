/********************************************************************************
** Form generated from reading UI file 'XJadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XJADMIN_H
#define UI_XJADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XJadminClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QSpinBox *spinBox_3;
    QLabel *label_9;
    QSpinBox *spinBox_4;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QToolButton *toolButton;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QSpinBox *spinBox_6;
    QLabel *label_12;
    QSpinBox *spinBox_7;
    QLabel *label_13;
    QSpinBox *spinBox_8;
    QLabel *label_15;
    QSpinBox *spinBox_9;
    QLabel *label_14;
    QSpinBox *spinBox_10;
    QLabel *label_101;
    QSpinBox *spinBox_14;
    QLabel *label_100;
    QSpinBox *spinBox_15;
    QGroupBox *groupBox_3;
    QLabel *label_23;
    QComboBox *comboBox_4;
    QLabel *label_22;
    QSpinBox *spinBox_17;
    QLabel *label_25;
    QSpinBox *spinBox_18;
    QLabel *label_43;
    QComboBox *comboBox_3;
    QLabel *label_48;
    QSpinBox *spinBox_23;
    QLabel *label_49;
    QSpinBox *spinBox_24;
    QLabel *label;
    QToolButton *MIN;
    QToolButton *BACK;
    QFrame *line_2;
    QFrame *line_3;

    void setupUi(QMainWindow *XJadminClass)
    {
        if (XJadminClass->objectName().isEmpty())
            XJadminClass->setObjectName(QString::fromUtf8("XJadminClass"));
        XJadminClass->resize(821, 420);
        XJadminClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);\n"
"\n"
""));
        centralWidget = new QWidget(XJadminClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 241, 311));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        groupBox->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 91, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(true);
        spinBox->setGeometry(QRect(110, 30, 71, 31));
        spinBox->setFont(font1);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMaximum(255);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 70, 91, 27));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setEnabled(true);
        spinBox_2->setGeometry(QRect(110, 70, 71, 31));
        spinBox_2->setFont(font1);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_2->setMaximum(255);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 110, 91, 27));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setEnabled(true);
        spinBox_3->setGeometry(QRect(110, 110, 71, 31));
        spinBox_3->setFont(font1);
        spinBox_3->setWrapping(false);
        spinBox_3->setReadOnly(false);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_3->setMaximum(255);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 150, 91, 27));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(110, 150, 71, 31));
        spinBox_4->setFont(font1);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_4->setMaximum(2000);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 190, 91, 28));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 190, 71, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(true);
        comboBox_2->setFont(font2);
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 230, 189, 46));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(true);
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
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/YSXZ.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 90, 221, 311));
        groupBox_2->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 30, 111, 31));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_6 = new QSpinBox(groupBox_2);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(120, 30, 71, 31));
        spinBox_6->setFont(font1);
        spinBox_6->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_6->setMinimum(1);
        spinBox_6->setMaximum(9999);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 70, 111, 31));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_7 = new QSpinBox(groupBox_2);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(120, 70, 71, 31));
        spinBox_7->setFont(font1);
        spinBox_7->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_7->setMinimum(1);
        spinBox_7->setMaximum(9999);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 110, 111, 31));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_8 = new QSpinBox(groupBox_2);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(120, 110, 71, 31));
        spinBox_8->setFont(font1);
        spinBox_8->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_8->setMinimum(1);
        spinBox_8->setMaximum(9999);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 150, 111, 31));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_9 = new QSpinBox(groupBox_2);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setGeometry(QRect(120, 150, 71, 31));
        spinBox_9->setFont(font1);
        spinBox_9->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_9->setMinimum(0);
        spinBox_9->setMaximum(30);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 190, 111, 31));
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_10 = new QSpinBox(groupBox_2);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setGeometry(QRect(120, 190, 71, 31));
        spinBox_10->setFont(font1);
        spinBox_10->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_10->setMinimum(1);
        spinBox_10->setMaximum(30);
        label_101 = new QLabel(groupBox_2);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setGeometry(QRect(10, 230, 111, 31));
        label_101->setFont(font1);
        spinBox_14 = new QSpinBox(groupBox_2);
        spinBox_14->setObjectName(QString::fromUtf8("spinBox_14"));
        spinBox_14->setGeometry(QRect(120, 230, 71, 31));
        spinBox_14->setFont(font1);
        spinBox_14->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_14->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_14->setMinimum(1);
        spinBox_14->setMaximum(999);
        label_100 = new QLabel(groupBox_2);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setGeometry(QRect(10, 270, 111, 31));
        label_100->setFont(font1);
        spinBox_15 = new QSpinBox(groupBox_2);
        spinBox_15->setObjectName(QString::fromUtf8("spinBox_15"));
        spinBox_15->setGeometry(QRect(120, 270, 71, 31));
        spinBox_15->setFont(font1);
        spinBox_15->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox_15->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_15->setMinimum(1);
        spinBox_15->setMaximum(9999);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(540, 90, 261, 311));
        groupBox_3->setFont(font);
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 30, 141, 31));
        label_23->setFont(font1);
        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(150, 30, 71, 31));
        comboBox_4->setFont(font2);
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 70, 141, 31));
        label_22->setFont(font1);
        spinBox_17 = new QSpinBox(groupBox_3);
        spinBox_17->setObjectName(QString::fromUtf8("spinBox_17"));
        spinBox_17->setGeometry(QRect(150, 70, 71, 31));
        spinBox_17->setFont(font3);
        spinBox_17->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_17->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_17->setMinimum(1);
        spinBox_17->setMaximum(9999);
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 110, 141, 31));
        label_25->setFont(font1);
        spinBox_18 = new QSpinBox(groupBox_3);
        spinBox_18->setObjectName(QString::fromUtf8("spinBox_18"));
        spinBox_18->setGeometry(QRect(150, 110, 71, 31));
        spinBox_18->setFont(font3);
        spinBox_18->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_18->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_18->setMinimum(1);
        spinBox_18->setMaximum(9999);
        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(10, 150, 141, 31));
        label_43->setFont(font1);
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(150, 150, 71, 31));
        comboBox_3->setFont(font2);
        label_48 = new QLabel(groupBox_3);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(10, 190, 141, 31));
        label_48->setFont(font1);
        spinBox_23 = new QSpinBox(groupBox_3);
        spinBox_23->setObjectName(QString::fromUtf8("spinBox_23"));
        spinBox_23->setGeometry(QRect(150, 190, 71, 31));
        spinBox_23->setFont(font3);
        spinBox_23->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_23->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_23->setMinimum(1);
        spinBox_23->setMaximum(9999);
        label_49 = new QLabel(groupBox_3);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 230, 141, 31));
        label_49->setFont(font1);
        spinBox_24 = new QSpinBox(groupBox_3);
        spinBox_24->setObjectName(QString::fromUtf8("spinBox_24"));
        spinBox_24->setGeometry(QRect(150, 230, 71, 31));
        spinBox_24->setFont(font3);
        spinBox_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_24->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_24->setMinimum(1);
        spinBox_24->setMaximum(9999);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 10, 191, 54));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(20);
        font4.setBold(true);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("opacity: 1;\n"
"border-radius: 15px;  \n"
"border: 2px solid #4CAF50;\n"
"padding: 5px 15px;\n"
"min-width: 100px;\n"
"min-height: 40px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MIN = new QToolButton(centralWidget);
        MIN->setObjectName(QString::fromUtf8("MIN"));
        MIN->setGeometry(QRect(720, 10, 40, 40));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/branch_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        MIN->setIcon(icon1);
        MIN->setIconSize(QSize(16, 16));
        BACK = new QToolButton(centralWidget);
        BACK->setObjectName(QString::fromUtf8("BACK"));
        BACK->setGeometry(QRect(770, 10, 40, 40));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/GB.png"), QSize(), QIcon::Normal, QIcon::Off);
        BACK->setIcon(icon2);
        BACK->setIconSize(QSize(16, 16));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 70, 801, 20));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 400, 801, 20));
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        XJadminClass->setCentralWidget(centralWidget);

        retranslateUi(XJadminClass);

        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(XJadminClass);
    } // setupUi

    void retranslateUi(QMainWindow *XJadminClass)
    {
        XJadminClass->setWindowTitle(QCoreApplication::translate("XJadminClass", "XJadmin", nullptr));
        groupBox->setTitle(QCoreApplication::translate("XJadminClass", "\345\205\211\346\272\220\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("XJadminClass", "R\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("XJadminClass", "G\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("XJadminClass", "B\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("XJadminClass", "RGBTime\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("XJadminClass", "RGBMode\357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("XJadminClass", "\351\242\221\351\227\252", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("XJadminClass", "\345\270\270\344\272\256", nullptr));

        toolButton->setText(QCoreApplication::translate("XJadminClass", "\345\205\211\346\272\220\351\242\234\350\211\262\345\277\253\351\200\237\350\256\276\347\275\256\346\214\211\351\222\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("XJadminClass", "\345\211\224\351\231\244\350\256\276\347\275\256", nullptr));
        label_11->setText(QCoreApplication::translate("XJadminClass", "\350\242\213\351\225\277\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("XJadminClass", "\344\270\213\351\231\220\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("XJadminClass", "\344\270\212\351\231\220\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("XJadminClass", "\351\227\264\351\232\224\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("XJadminClass", "\350\277\236\345\214\205\357\274\232", nullptr));
        label_101->setText(QCoreApplication::translate("XJadminClass", "\347\274\226\347\240\201\345\231\250\347\233\264\345\276\204\357\274\232", nullptr));
        label_100->setText(QCoreApplication::translate("XJadminClass", "\347\274\226\347\240\201\345\231\250\350\204\211\345\206\262\346\225\260\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("XJadminClass", "\350\247\246\345\217\221\350\256\276\347\275\256", nullptr));
        label_23->setText(QCoreApplication::translate("XJadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\346\250\241\345\274\217\357\274\232", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("XJadminClass", "\345\205\263\351\227\255", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("XJadminClass", "\346\227\266\351\227\264\346\250\241\345\274\217", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("XJadminClass", "\350\267\235\347\246\273\346\250\241\345\274\217", nullptr));

        label_22->setText(QCoreApplication::translate("XJadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\346\227\266\351\227\264\357\274\232", nullptr));
        label_25->setText(QCoreApplication::translate("XJadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\350\267\235\347\246\273\357\274\232", nullptr));
        label_43->setText(QCoreApplication::translate("XJadminClass", "\346\213\215\347\205\247\345\273\266\345\220\216\350\247\246\345\217\221\346\250\241\345\274\217\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("XJadminClass", "\345\205\263\351\227\255", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("XJadminClass", "\346\227\266\351\227\264\346\250\241\345\274\217", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("XJadminClass", "\350\267\235\347\246\273\346\250\241\345\274\217", nullptr));

        label_48->setText(QCoreApplication::translate("XJadminClass", "\346\213\215\347\205\247\345\273\266\345\220\216\350\247\246\345\217\221\346\227\266\351\227\264\357\274\232", nullptr));
        label_49->setText(QCoreApplication::translate("XJadminClass", "\346\213\215\347\205\247\345\273\266\345\220\216\350\247\246\345\217\221\350\267\235\347\246\273\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("XJadminClass", "\346\243\200\346\265\213\345\217\202\346\225\260", nullptr));
        MIN->setText(QCoreApplication::translate("XJadminClass", "\346\234\200\345\260\217\345\214\226", nullptr));
        BACK->setText(QCoreApplication::translate("XJadminClass", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XJadminClass: public Ui_XJadminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XJADMIN_H
