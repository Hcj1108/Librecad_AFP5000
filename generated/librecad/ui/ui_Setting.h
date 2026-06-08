/********************************************************************************
** Form generated from reading UI file 'Setting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_SettingClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *mainArea;
    QSpacerItem *horizontalSpacer_2;
    MyLabel *label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *rightPanel;
    QGroupBox *groupBox_2;
    QVBoxLayout *gbLayout1;
    QHBoxLayout *hl_exp;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton_5;
    QToolButton *toolButton_7;
    QHBoxLayout *hl_gain;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_8;
    QToolButton *toolButton_6;
    QHBoxLayout *hl_rot;
    QLabel *label_5;
    QComboBox *comboBox;
    QPushButton *pushButton_12;
    QHBoxLayout *hl_sharp;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_3;
    QHBoxLayout *gbLayout2;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *SettingClass)
    {
        if (SettingClass->objectName().isEmpty())
            SettingClass->setObjectName(QString::fromUtf8("SettingClass"));
        SettingClass->resize(900, 550);
        SettingClass->setMinimumSize(QSize(900, 550));
        SettingClass->setMaximumSize(QSize(900, 550));
        SettingClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        centralWidget = new QWidget(SettingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainArea = new QHBoxLayout();
        mainArea->setSpacing(0);
        mainArea->setObjectName(QString::fromUtf8("mainArea"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mainArea->addItem(horizontalSpacer_2);

        label = new MyLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(6);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(561, 491));
        label->setMaximumSize(QSize(561, 491));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label->setFrameShape(QFrame::Shape::Box);

        mainArea->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mainArea->addItem(horizontalSpacer);

        rightPanel = new QVBoxLayout();
        rightPanel->setSpacing(0);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(280, 200));
        groupBox_2->setMaximumSize(QSize(280, 200));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 14px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        gbLayout1 = new QVBoxLayout(groupBox_2);
        gbLayout1->setSpacing(0);
        gbLayout1->setContentsMargins(11, 11, 11, 11);
        gbLayout1->setObjectName(QString::fromUtf8("gbLayout1"));
        hl_exp = new QHBoxLayout();
        hl_exp->setSpacing(6);
        hl_exp->setObjectName(QString::fromUtf8("hl_exp"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(71, 37));
        label_2->setMaximumSize(QSize(71, 37));
        label_2->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_exp->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(105, 23));
        lineEdit->setMaximumSize(QSize(105, 23));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{font: 13px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_exp->addWidget(lineEdit);

        toolButton_5 = new QToolButton(groupBox_2);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(32, 32));
        toolButton_5->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Moon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon);

        hl_exp->addWidget(toolButton_5);

        toolButton_7 = new QToolButton(groupBox_2);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(32, 32));
        toolButton_7->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Sun.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon1);

        hl_exp->addWidget(toolButton_7);


        gbLayout1->addLayout(hl_exp);

        hl_gain = new QHBoxLayout();
        hl_gain->setSpacing(6);
        hl_gain->setObjectName(QString::fromUtf8("hl_gain"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(71, 36));
        label_3->setMaximumSize(QSize(71, 36));
        label_3->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_gain->addWidget(label_3);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(105, 23));
        lineEdit_2->setMaximumSize(QSize(105, 23));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{font: 13px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_gain->addWidget(lineEdit_2);

        toolButton_8 = new QToolButton(groupBox_2);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(32, 32));
        toolButton_8->setMaximumSize(QSize(32, 32));
        toolButton_8->setIcon(icon);

        hl_gain->addWidget(toolButton_8);

        toolButton_6 = new QToolButton(groupBox_2);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(32, 32));
        toolButton_6->setMaximumSize(QSize(32, 32));
        toolButton_6->setIcon(icon1);

        hl_gain->addWidget(toolButton_6);


        gbLayout1->addLayout(hl_gain);

        hl_rot = new QHBoxLayout();
        hl_rot->setSpacing(6);
        hl_rot->setObjectName(QString::fromUtf8("hl_rot"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(71, 37));
        label_5->setMaximumSize(QSize(71, 37));
        label_5->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_rot->addWidget(label_5);

        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(105, 31));
        comboBox->setMaximumSize(QSize(105, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{font: 13px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 4px;}\n"
"QComboBox:focus{border-color: #3498db;}"));

        hl_rot->addWidget(comboBox);

        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(70, 30));
        pushButton_12->setMaximumSize(QSize(70, 30));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 4px;}\n"
"QPushButton:hover{background: #2980b9;}"));

        hl_rot->addWidget(pushButton_12);


        gbLayout1->addLayout(hl_rot);

        hl_sharp = new QHBoxLayout();
        hl_sharp->setSpacing(6);
        hl_sharp->setObjectName(QString::fromUtf8("hl_sharp"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(71, 36));
        label_4->setMaximumSize(QSize(71, 36));
        label_4->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_sharp->addWidget(label_4);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(105, 23));
        lineEdit_3->setMaximumSize(QSize(105, 23));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{font: 13px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_sharp->addWidget(lineEdit_3);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(70, 30));
        pushButton_8->setMaximumSize(QSize(70, 30));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 4px;}\n"
"QPushButton:hover{background: #2980b9;}"));

        hl_sharp->addWidget(pushButton_8);


        gbLayout1->addLayout(hl_sharp);


        rightPanel->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(280, 150));
        groupBox_3->setMaximumSize(QSize(280, 150));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 14px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        gbLayout2 = new QHBoxLayout(groupBox_3);
        gbLayout2->setSpacing(6);
        gbLayout2->setContentsMargins(11, 11, 11, 11);
        gbLayout2->setObjectName(QString::fromUtf8("gbLayout2"));
        toolButton_2 = new QToolButton(groupBox_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(109, 45));
        toolButton_2->setMaximumSize(QSize(109, 45));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px;}\n"
"QToolButton:hover{background: #2980b9;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PNG/Resources/PNG/DZCJ1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(30, 30));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gbLayout2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(groupBox_3);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(109, 45));
        toolButton_3->setMaximumSize(QSize(109, 45));
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #27ae60; color: white; border-radius: 6px; padding: 6px;}\n"
"QToolButton:hover{background: #229954;}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PNG/Resources/PNG/KXFW.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(30, 30));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gbLayout2->addWidget(toolButton_3);


        rightPanel->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        rightPanel->addItem(verticalSpacer);


        mainArea->addLayout(rightPanel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mainArea->addItem(horizontalSpacer_3);


        mainLayout->addLayout(mainArea);

        SettingClass->setCentralWidget(centralWidget);

        retranslateUi(SettingClass);

        QMetaObject::connectSlotsByName(SettingClass);
    } // setupUi

    void retranslateUi(QMainWindow *SettingClass)
    {
        SettingClass->setWindowTitle(QCoreApplication::translate("SettingClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingClass", "\345\233\276\345\203\217\350\260\203\346\225\264", nullptr));
        label_2->setText(QCoreApplication::translate("SettingClass", "\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        toolButton_5->setText(QString());
        toolButton_7->setText(QString());
        label_3->setText(QCoreApplication::translate("SettingClass", "\345\242\236\347\233\212", nullptr));
        toolButton_8->setText(QString());
        toolButton_6->setText(QString());
        label_5->setText(QCoreApplication::translate("SettingClass", "\346\227\213\350\275\254", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SettingClass", "0\302\260(\351\273\230\350\256\244)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SettingClass", "90\302\260(\351\241\272\346\227\266\351\222\210)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SettingClass", "180\302\260(\351\241\272\346\227\266\351\222\210)", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SettingClass", "270\302\260(\351\241\272\346\227\266\351\222\210)", nullptr));

        pushButton_12->setText(QCoreApplication::translate("SettingClass", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("SettingClass", "\351\224\220\345\214\226", nullptr));
        pushButton_8->setText(QCoreApplication::translate("SettingClass", "\347\241\256\345\256\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SettingClass", "\345\233\276\345\203\217ROI", nullptr));
        toolButton_2->setText(QCoreApplication::translate("SettingClass", "\345\215\225\345\274\240\351\207\207\351\233\206", nullptr));
        toolButton_3->setText(QCoreApplication::translate("SettingClass", "\344\277\235\345\255\230\346\241\206\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingClass: public Ui_SettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
