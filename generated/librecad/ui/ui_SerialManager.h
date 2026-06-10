/********************************************************************************
** Form generated from reading UI file 'SerialManager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALMANAGER_H
#define UI_SERIALMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialManagerClass
{
public:
    QLabel *label;
    QToolButton *toolButton_21;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QToolButton *toolButton_14;
    QToolButton *toolButton_15;
    QToolButton *toolButton_16;
    QGroupBox *groupBox;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_4;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QToolButton *toolButton_13;
    QFrame *line_2;
    QFrame *line_3;

    void setupUi(QWidget *SerialManagerClass)
    {
        if (SerialManagerClass->objectName().isEmpty())
            SerialManagerClass->setObjectName(QString::fromUtf8("SerialManagerClass"));
        SerialManagerClass->setEnabled(true);
        SerialManagerClass->resize(692, 300);
        SerialManagerClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        label = new QLabel(SerialManagerClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 10, 281, 54));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("opacity: 1;\n"
"border-radius: 15px;  \n"
"border: 2px solid #4CAF50;\n"
"padding: 5px 15px;\n"
"min-width: 100px;\n"
"min-height: 40px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolButton_21 = new QToolButton(SerialManagerClass);
        toolButton_21->setObjectName(QString::fromUtf8("toolButton_21"));
        toolButton_21->setGeometry(QRect(640, 10, 41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(14);
        font1.setBold(true);
        toolButton_21->setFont(font1);
        toolButton_21->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/GB.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_21->setIcon(icon);
        groupBox_2 = new QGroupBox(SerialManagerClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 90, 301, 191));
        groupBox_2->setFont(font1);
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 30, 131, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(12);
        font2.setBold(true);
        checkBox->setFont(font2);
        checkBox->setIconSize(QSize(20, 16));
        checkBox->setChecked(false);
        checkBox->setAutoExclusive(false);
        checkBox->setAutoRepeatDelay(300);
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 70, 131, 31));
        checkBox_2->setFont(font2);
        checkBox_2->setChecked(false);
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 110, 131, 31));
        checkBox_3->setFont(font2);
        checkBox_3->setChecked(false);
        toolButton_14 = new QToolButton(groupBox_2);
        toolButton_14->setObjectName(QString::fromUtf8("toolButton_14"));
        toolButton_14->setGeometry(QRect(190, 30, 101, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setPointSize(10);
        font3.setBold(true);
        toolButton_14->setFont(font3);
        toolButton_14->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        toolButton_15 = new QToolButton(groupBox_2);
        toolButton_15->setObjectName(QString::fromUtf8("toolButton_15"));
        toolButton_15->setGeometry(QRect(190, 70, 101, 31));
        toolButton_15->setFont(font3);
        toolButton_15->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        toolButton_16 = new QToolButton(groupBox_2);
        toolButton_16->setObjectName(QString::fromUtf8("toolButton_16"));
        toolButton_16->setGeometry(QRect(190, 110, 101, 31));
        toolButton_16->setFont(font3);
        toolButton_16->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        groupBox = new QGroupBox(SerialManagerClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 301, 191));
        groupBox->setFont(font1);
        checkBox_5 = new QCheckBox(groupBox);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 70, 121, 31));
        checkBox_5->setFont(font2);
        checkBox_5->setChecked(false);
        checkBox_5->setTristate(false);
        checkBox_6 = new QCheckBox(groupBox);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(20, 110, 121, 31));
        checkBox_6->setFont(font2);
        checkBox_6->setChecked(false);
        checkBox_7 = new QCheckBox(groupBox);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(20, 150, 171, 31));
        checkBox_7->setFont(font2);
        checkBox_7->setChecked(false);
        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 30, 121, 31));
        checkBox_4->setFont(font2);
        checkBox_4->setIconSize(QSize(25, 25));
        checkBox_4->setCheckable(true);
        checkBox_4->setChecked(false);
        toolButton_10 = new QToolButton(groupBox);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setGeometry(QRect(190, 30, 101, 31));
        toolButton_10->setFont(font3);
        toolButton_10->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        toolButton_11 = new QToolButton(groupBox);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        toolButton_11->setGeometry(QRect(190, 70, 101, 31));
        toolButton_11->setFont(font3);
        toolButton_11->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        toolButton_12 = new QToolButton(groupBox);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setGeometry(QRect(190, 110, 101, 31));
        toolButton_12->setFont(font3);
        toolButton_12->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        toolButton_13 = new QToolButton(groupBox);
        toolButton_13->setObjectName(QString::fromUtf8("toolButton_13"));
        toolButton_13->setGeometry(QRect(190, 150, 101, 31));
        toolButton_13->setFont(font3);
        toolButton_13->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
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
        line_2 = new QFrame(SerialManagerClass);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 70, 661, 20));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(SerialManagerClass);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 280, 661, 20));
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        retranslateUi(SerialManagerClass);

        QMetaObject::connectSlotsByName(SerialManagerClass);
    } // setupUi

    void retranslateUi(QWidget *SerialManagerClass)
    {
        SerialManagerClass->setWindowTitle(QCoreApplication::translate("SerialManagerClass", "SerialManager", nullptr));
        label->setText(QCoreApplication::translate("SerialManagerClass", "\350\277\220\350\241\214\347\212\266\346\200\201\350\256\276\347\275\256\347\225\214\351\235\242", nullptr));
        toolButton_21->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("SerialManagerClass", "\350\201\224\346\234\272\347\212\266\346\200\201", nullptr));
        checkBox->setText(QCoreApplication::translate("SerialManagerClass", "\347\233\270\346\234\272\350\201\224\346\234\272\345\261\217\350\224\275", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SerialManagerClass", "\346\240\207\345\210\273\350\201\224\346\234\272\345\261\217\350\224\275", nullptr));
        checkBox_3->setText(QCoreApplication::translate("SerialManagerClass", "\351\200\232\350\256\257\350\201\224\346\234\272\345\261\217\350\224\275", nullptr));
        toolButton_14->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        toolButton_15->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        toolButton_16->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SerialManagerClass", "\346\212\245\350\255\246\347\212\266\346\200\201", nullptr));
        checkBox_5->setText(QCoreApplication::translate("SerialManagerClass", "\344\270\213\351\231\220\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        checkBox_6->setText(QCoreApplication::translate("SerialManagerClass", "\347\233\270\346\234\272\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        checkBox_7->setText(QCoreApplication::translate("SerialManagerClass", "\350\266\205\345\214\272\345\237\237\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        checkBox_4->setText(QCoreApplication::translate("SerialManagerClass", "\344\270\212\351\231\220\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        toolButton_10->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        toolButton_11->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        toolButton_12->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        toolButton_13->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialManagerClass: public Ui_SerialManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALMANAGER_H
