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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialManagerClass
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *contentArea;
    QGroupBox *groupBox;
    QGridLayout *alarmLayout;
    QCheckBox *checkBox_4;
    QToolButton *toolButton_10;
    QCheckBox *checkBox_5;
    QToolButton *toolButton_11;
    QCheckBox *checkBox_6;
    QToolButton *toolButton_12;
    QCheckBox *checkBox_7;
    QToolButton *toolButton_13;
    QGroupBox *groupBox_2;
    QGridLayout *linkLayout;
    QCheckBox *checkBox;
    QToolButton *toolButton_14;
    QCheckBox *checkBox_2;
    QToolButton *toolButton_15;
    QCheckBox *checkBox_3;
    QToolButton *toolButton_16;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QToolButton *toolButton_2;
    QLabel *label_4;
    QToolButton *toolButton_3;
    QLabel *label_5;
    QHBoxLayout *bottomBar;
    QSpacerItem *bottomSpacer;
    QPushButton *btnClose;

    void setupUi(QWidget *SerialManagerClass)
    {
        if (SerialManagerClass->objectName().isEmpty())
            SerialManagerClass->setObjectName(QString::fromUtf8("SerialManagerClass"));
        SerialManagerClass->setEnabled(true);
        SerialManagerClass->resize(584, 410);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/XTZT.png"), QSize(), QIcon::Normal, QIcon::Off);
        SerialManagerClass->setWindowIcon(icon);
        SerialManagerClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(SerialManagerClass);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        contentArea = new QHBoxLayout();
        contentArea->setObjectName(QString::fromUtf8("contentArea"));
        groupBox = new QGroupBox(SerialManagerClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #e0e0e0; border-radius: 8px; margin-top: 14px; padding-top: 18px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 4px 12px; background: #3498db; color: white; border-radius: 4px;}\n"
"QToolButton{font: bold 11px \"Microsoft YaHei\"; border-radius: 4px; padding: 4px 8px; border: 1px solid #bdc3c7; background: #ffffff;}"));
        alarmLayout = new QGridLayout(groupBox);
        alarmLayout->setObjectName(QString::fromUtf8("alarmLayout"));
        alarmLayout->setHorizontalSpacing(8);
        alarmLayout->setVerticalSpacing(6);
        alarmLayout->setContentsMargins(16, 20, 16, 16);
        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        font1.setBold(true);
        checkBox_4->setFont(font1);
        checkBox_4->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        alarmLayout->addWidget(checkBox_4, 0, 0, 1, 1);

        toolButton_10 = new QToolButton(groupBox);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setMinimumSize(QSize(100, 30));
        toolButton_10->setMaximumSize(QSize(100, 16777215));
        toolButton_10->setFont(font);
        toolButton_10->setStyleSheet(QString::fromUtf8(""));

        alarmLayout->addWidget(toolButton_10, 0, 1, 1, 1);

        checkBox_5 = new QCheckBox(groupBox);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setFont(font1);
        checkBox_5->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        alarmLayout->addWidget(checkBox_5, 1, 0, 1, 1);

        toolButton_11 = new QToolButton(groupBox);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        toolButton_11->setMinimumSize(QSize(100, 30));
        toolButton_11->setMaximumSize(QSize(100, 16777215));
        toolButton_11->setFont(font);
        toolButton_11->setStyleSheet(QString::fromUtf8(""));

        alarmLayout->addWidget(toolButton_11, 1, 1, 1, 1);

        checkBox_6 = new QCheckBox(groupBox);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font1);
        checkBox_6->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        alarmLayout->addWidget(checkBox_6, 2, 0, 1, 1);

        toolButton_12 = new QToolButton(groupBox);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setMinimumSize(QSize(100, 30));
        toolButton_12->setMaximumSize(QSize(100, 16777215));
        toolButton_12->setFont(font);
        toolButton_12->setStyleSheet(QString::fromUtf8(""));

        alarmLayout->addWidget(toolButton_12, 2, 1, 1, 1);

        checkBox_7 = new QCheckBox(groupBox);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setFont(font1);
        checkBox_7->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        alarmLayout->addWidget(checkBox_7, 3, 0, 1, 1);

        toolButton_13 = new QToolButton(groupBox);
        toolButton_13->setObjectName(QString::fromUtf8("toolButton_13"));
        toolButton_13->setMinimumSize(QSize(100, 30));
        toolButton_13->setMaximumSize(QSize(100, 16777215));
        toolButton_13->setFont(font);
        toolButton_13->setStyleSheet(QString::fromUtf8(""));

        alarmLayout->addWidget(toolButton_13, 3, 1, 1, 1);


        contentArea->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SerialManagerClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #e0e0e0; border-radius: 8px; margin-top: 14px; padding-top: 18px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 4px 12px; background: #3498db; color: white; border-radius: 4px;}\n"
"QToolButton{font: bold 11px \"Microsoft YaHei\"; border-radius: 4px; padding: 4px 8px; border: 1px solid #bdc3c7; background: #ffffff;}"));
        linkLayout = new QGridLayout(groupBox_2);
        linkLayout->setObjectName(QString::fromUtf8("linkLayout"));
        linkLayout->setHorizontalSpacing(8);
        linkLayout->setVerticalSpacing(6);
        linkLayout->setContentsMargins(16, 20, 16, 16);
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font1);
        checkBox->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        linkLayout->addWidget(checkBox, 0, 0, 1, 1);

        toolButton_14 = new QToolButton(groupBox_2);
        toolButton_14->setObjectName(QString::fromUtf8("toolButton_14"));
        toolButton_14->setMinimumSize(QSize(100, 30));
        toolButton_14->setMaximumSize(QSize(100, 16777215));
        toolButton_14->setFont(font);
        toolButton_14->setStyleSheet(QString::fromUtf8(""));

        linkLayout->addWidget(toolButton_14, 0, 1, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font1);
        checkBox_2->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        linkLayout->addWidget(checkBox_2, 1, 0, 1, 1);

        toolButton_15 = new QToolButton(groupBox_2);
        toolButton_15->setObjectName(QString::fromUtf8("toolButton_15"));
        toolButton_15->setMinimumSize(QSize(100, 30));
        toolButton_15->setMaximumSize(QSize(100, 16777215));
        toolButton_15->setFont(font);
        toolButton_15->setStyleSheet(QString::fromUtf8(""));

        linkLayout->addWidget(toolButton_15, 1, 1, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font1);
        checkBox_3->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        linkLayout->addWidget(checkBox_3, 2, 0, 1, 1);

        toolButton_16 = new QToolButton(groupBox_2);
        toolButton_16->setObjectName(QString::fromUtf8("toolButton_16"));
        toolButton_16->setMinimumSize(QSize(100, 30));
        toolButton_16->setMaximumSize(QSize(100, 16777215));
        toolButton_16->setFont(font);
        toolButton_16->setStyleSheet(QString::fromUtf8(""));

        linkLayout->addWidget(toolButton_16, 2, 1, 1, 1);


        contentArea->addWidget(groupBox_2);


        mainLayout->addLayout(contentArea);

        groupBox_3 = new QGroupBox(SerialManagerClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #e0e0e0; border-radius: 8px; margin-top: 14px; padding-top: 18px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 4px 12px; background: #8e44ad; color: white; border-radius: 4px;}\n"
"QLabel{color: #34495e; background: transparent; font: bold 12px \"Microsoft YaHei\"; padding: 2px 4px;}\n"
"QToolButton{font: bold 11px \"Microsoft YaHei\"; border-radius: 4px; padding: 4px 8px; border: 1px solid #bdc3c7; background: #ffffff;}"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        toolButton_5 = new QToolButton(groupBox_3);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #1abc9c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        gridLayout->addWidget(toolButton_5, 0, 5, 1, 1);

        toolButton_4 = new QToolButton(groupBox_3);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #1abc9c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        gridLayout->addWidget(toolButton_4, 1, 3, 1, 1);

        toolButton = new QToolButton(groupBox_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #1abc9c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        gridLayout->addWidget(toolButton, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        toolButton_2 = new QToolButton(groupBox_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #1abc9c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        gridLayout->addWidget(toolButton_2, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        toolButton_3 = new QToolButton(groupBox_3);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\";background: #1abc9c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        gridLayout->addWidget(toolButton_3, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);


        mainLayout->addWidget(groupBox_3);

        bottomBar = new QHBoxLayout();
        bottomBar->setObjectName(QString::fromUtf8("bottomBar"));
        bottomSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomBar->addItem(bottomSpacer);

        btnClose = new QPushButton(SerialManagerClass);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(80, 36));
        btnClose->setMaximumSize(QSize(80, 36));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #c0392b;}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon1);
        btnClose->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnClose);


        mainLayout->addLayout(bottomBar);


        retranslateUi(SerialManagerClass);

        QMetaObject::connectSlotsByName(SerialManagerClass);
    } // setupUi

    void retranslateUi(QWidget *SerialManagerClass)
    {
        SerialManagerClass->setWindowTitle(QCoreApplication::translate("SerialManagerClass", "IO\347\233\221\350\247\206\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SerialManagerClass", "\346\212\245\350\255\246\347\212\266\346\200\201", nullptr));
        checkBox_4->setText(QCoreApplication::translate("SerialManagerClass", "\344\270\212\351\231\220\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        toolButton_10->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        checkBox_5->setText(QCoreApplication::translate("SerialManagerClass", "\344\270\213\351\231\220\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        toolButton_11->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        checkBox_6->setText(QCoreApplication::translate("SerialManagerClass", "\347\233\270\346\234\272\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        toolButton_12->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        checkBox_7->setText(QCoreApplication::translate("SerialManagerClass", "\350\266\205\345\214\272\345\237\237\346\212\245\350\255\246\345\261\217\350\224\275", nullptr));
        toolButton_13->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SerialManagerClass", "\350\201\224\346\234\272\347\212\266\346\200\201", nullptr));
        checkBox->setText(QCoreApplication::translate("SerialManagerClass", "\347\233\270\346\234\272\350\201\224\346\234\272\345\261\217\350\224\275", nullptr));
        toolButton_14->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SerialManagerClass", "\346\240\207\345\210\273\350\201\224\346\234\272\345\261\217\350\224\275", nullptr));
        toolButton_15->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        checkBox_3->setText(QCoreApplication::translate("SerialManagerClass", "\351\200\232\350\256\257\350\201\224\346\234\272\345\261\217\350\224\275", nullptr));
        toolButton_16->setText(QCoreApplication::translate("SerialManagerClass", "\346\255\243\345\270\270\350\277\220\350\241\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SerialManagerClass", "\344\277\241\345\217\267\350\276\223\345\207\272", nullptr));
        toolButton_5->setText(QCoreApplication::translate("SerialManagerClass", "\345\270\270\344\272\256\344\277\241\345\217\267", nullptr));
        toolButton_4->setText(QCoreApplication::translate("SerialManagerClass", "\346\270\205\351\231\244\346\212\245\350\255\246", nullptr));
        toolButton->setText(QCoreApplication::translate("SerialManagerClass", "\346\211\223\345\215\260\344\270\200\346\254\241", nullptr));
        label_3->setText(QCoreApplication::translate("SerialManagerClass", "\346\212\245\350\255\246\344\277\241\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SerialManagerClass", "\346\213\215\347\205\247\344\277\241\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SerialManagerClass", "\346\211\223\345\215\260\344\277\241\345\217\267\357\274\232", nullptr));
        toolButton_2->setText(QCoreApplication::translate("SerialManagerClass", "\346\213\215\347\205\247\344\270\200\346\254\241", nullptr));
        label_4->setText(QCoreApplication::translate("SerialManagerClass", "\346\270\205\351\231\244\346\212\245\350\255\246\357\274\232", nullptr));
        toolButton_3->setText(QCoreApplication::translate("SerialManagerClass", "\346\212\245\350\255\246\344\270\200\346\254\241", nullptr));
        label_5->setText(QCoreApplication::translate("SerialManagerClass", "\345\205\211\346\272\220\345\270\270\344\272\256\357\274\232", nullptr));
        btnClose->setText(QCoreApplication::translate("SerialManagerClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialManagerClass: public Ui_SerialManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALMANAGER_H
