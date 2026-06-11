/********************************************************************************
** Form generated from reading UI file 'Jgadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JGADMIN_H
#define UI_JGADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JgadminClass
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *contentArea;
    QGroupBox *groupBox_2;
    QFormLayout *lineLayout;
    QLabel *label_103;
    QSpinBox *spinBox_10;
    QLabel *label_99;
    QComboBox *comboBox_4;
    QLabel *label_102;
    QComboBox *comboBox_5;
    QLabel *label_72;
    QComboBox *comboBox_6;
    QLabel *label_100;
    QSpinBox *spinBox_15;
    QLabel *label_101;
    QSpinBox *spinBox_14;
    QGroupBox *groupBox;
    QFormLayout *sprayLayout;
    QLabel *label_27;
    QSpinBox *spinBox;
    QLabel *label_34;
    QSpinBox *spinBox_2;
    QLabel *label_41;
    QSpinBox *spinBox_3;
    QLabel *label_42;
    QSpinBox *spinBox_4;
    QLabel *label_44;
    QSpinBox *spinBox_5;
    QLabel *label_45;
    QSpinBox *spinBox_7;
    QLabel *label_20;
    QSpinBox *spinBox_8;
    QGroupBox *groupBox_3;
    QFormLayout *triggerLayout;
    QLabel *label_23;
    QComboBox *comboBox;
    QLabel *label_22;
    QSpinBox *spinBox_17;
    QLabel *label_25;
    QSpinBox *spinBox_18;
    QLabel *label_37;
    QComboBox *comboBox_2;
    QLabel *label_38;
    QSpinBox *spinBox_20;
    QLabel *label_39;
    QSpinBox *spinBox_21;
    QHBoxLayout *bottomBar;
    QSpacerItem *bottomSpacer;
    QPushButton *btnClose;

    void setupUi(QWidget *JgadminClass)
    {
        if (JgadminClass->objectName().isEmpty())
            JgadminClass->setObjectName(QString::fromUtf8("JgadminClass"));
        JgadminClass->resize(746, 364);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/DYTZ.png"), QSize(), QIcon::Normal, QIcon::Off);
        JgadminClass->setWindowIcon(icon);
        JgadminClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(JgadminClass);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        contentArea = new QHBoxLayout();
        contentArea->setObjectName(QString::fromUtf8("contentArea"));
        groupBox_2 = new QGroupBox(JgadminClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        lineLayout = new QFormLayout(groupBox_2);
        lineLayout->setObjectName(QString::fromUtf8("lineLayout"));
        lineLayout->setHorizontalSpacing(10);
        lineLayout->setVerticalSpacing(6);
        lineLayout->setContentsMargins(16, 20, 16, 16);
        label_103 = new QLabel(groupBox_2);
        label_103->setObjectName(QString::fromUtf8("label_103"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        font1.setBold(true);
        label_103->setFont(font1);
        label_103->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lineLayout->setWidget(0, QFormLayout::LabelRole, label_103);

        spinBox_10 = new QSpinBox(groupBox_2);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setFont(font);
        spinBox_10->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_10->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_10->setMinimum(1);
        spinBox_10->setMaximum(999);

        lineLayout->setWidget(0, QFormLayout::FieldRole, spinBox_10);

        label_99 = new QLabel(groupBox_2);
        label_99->setObjectName(QString::fromUtf8("label_99"));
        label_99->setFont(font1);
        label_99->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lineLayout->setWidget(1, QFormLayout::LabelRole, label_99);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setFont(font);
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}QComboBox:focus{border-color: #3498db;}QComboBox::drop-down{width: 28px;}"));

        lineLayout->setWidget(1, QFormLayout::FieldRole, comboBox_4);

        label_102 = new QLabel(groupBox_2);
        label_102->setObjectName(QString::fromUtf8("label_102"));
        label_102->setFont(font1);
        label_102->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lineLayout->setWidget(2, QFormLayout::LabelRole, label_102);

        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setFont(font);
        comboBox_5->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}QComboBox:focus{border-color: #3498db;}QComboBox::drop-down{width: 28px;}"));

        lineLayout->setWidget(2, QFormLayout::FieldRole, comboBox_5);

        label_72 = new QLabel(groupBox_2);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setFont(font1);
        label_72->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lineLayout->setWidget(3, QFormLayout::LabelRole, label_72);

        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setFont(font);
        comboBox_6->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}QComboBox:focus{border-color: #3498db;}QComboBox::drop-down{width: 28px;}"));

        lineLayout->setWidget(3, QFormLayout::FieldRole, comboBox_6);

        label_100 = new QLabel(groupBox_2);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setFont(font1);
        label_100->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lineLayout->setWidget(4, QFormLayout::LabelRole, label_100);

        spinBox_15 = new QSpinBox(groupBox_2);
        spinBox_15->setObjectName(QString::fromUtf8("spinBox_15"));
        spinBox_15->setFont(font);
        spinBox_15->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_15->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_15->setMinimum(1);
        spinBox_15->setMaximum(9999);

        lineLayout->setWidget(4, QFormLayout::FieldRole, spinBox_15);

        label_101 = new QLabel(groupBox_2);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setFont(font1);
        label_101->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lineLayout->setWidget(5, QFormLayout::LabelRole, label_101);

        spinBox_14 = new QSpinBox(groupBox_2);
        spinBox_14->setObjectName(QString::fromUtf8("spinBox_14"));
        spinBox_14->setFont(font);
        spinBox_14->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_14->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_14->setMinimum(1);
        spinBox_14->setMaximum(999);

        lineLayout->setWidget(5, QFormLayout::FieldRole, spinBox_14);


        contentArea->addWidget(groupBox_2);

        groupBox = new QGroupBox(JgadminClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        sprayLayout = new QFormLayout(groupBox);
        sprayLayout->setObjectName(QString::fromUtf8("sprayLayout"));
        sprayLayout->setHorizontalSpacing(10);
        sprayLayout->setVerticalSpacing(6);
        sprayLayout->setContentsMargins(16, 20, 16, 16);
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(0, QFormLayout::LabelRole, label_27);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFont(font);
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMinimum(5);
        spinBox->setMaximum(95);

        sprayLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font1);
        label_34->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(1, QFormLayout::LabelRole, label_34);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setFont(font);
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_2->setMinimum(5);
        spinBox_2->setMaximum(400);

        sprayLayout->setWidget(1, QFormLayout::FieldRole, spinBox_2);

        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font1);
        label_41->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(2, QFormLayout::LabelRole, label_41);

        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setFont(font);
        spinBox_3->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_3->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_3->setMinimum(0);
        spinBox_3->setMaximum(30);

        sprayLayout->setWidget(2, QFormLayout::FieldRole, spinBox_3);

        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font1);
        label_42->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(3, QFormLayout::LabelRole, label_42);

        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setFont(font);
        spinBox_4->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_4->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_4->setMinimum(0);
        spinBox_4->setMaximum(30);

        sprayLayout->setWidget(3, QFormLayout::FieldRole, spinBox_4);

        label_44 = new QLabel(groupBox);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);
        label_44->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(4, QFormLayout::LabelRole, label_44);

        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setFont(font);
        spinBox_5->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_5->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_5->setMinimum(0);
        spinBox_5->setMaximum(800);

        sprayLayout->setWidget(4, QFormLayout::FieldRole, spinBox_5);

        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font1);
        label_45->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(5, QFormLayout::LabelRole, label_45);

        spinBox_7 = new QSpinBox(groupBox);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setFont(font);
        spinBox_7->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_7->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_7->setMinimum(0);
        spinBox_7->setMaximum(30);

        sprayLayout->setWidget(5, QFormLayout::FieldRole, spinBox_7);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        sprayLayout->setWidget(6, QFormLayout::LabelRole, label_20);

        spinBox_8 = new QSpinBox(groupBox);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setFont(font);
        spinBox_8->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_8->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_8->setMinimum(1);
        spinBox_8->setMaximum(999);

        sprayLayout->setWidget(6, QFormLayout::FieldRole, spinBox_8);


        contentArea->addWidget(groupBox);

        groupBox_3 = new QGroupBox(JgadminClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        triggerLayout = new QFormLayout(groupBox_3);
        triggerLayout->setObjectName(QString::fromUtf8("triggerLayout"));
        triggerLayout->setHorizontalSpacing(10);
        triggerLayout->setVerticalSpacing(6);
        triggerLayout->setContentsMargins(16, 20, 16, 16);
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(0, QFormLayout::LabelRole, label_23);

        comboBox = new QComboBox(groupBox_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}QComboBox:focus{border-color: #3498db;}QComboBox::drop-down{width: 28px;}"));

        triggerLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);
        label_22->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(1, QFormLayout::LabelRole, label_22);

        spinBox_17 = new QSpinBox(groupBox_3);
        spinBox_17->setObjectName(QString::fromUtf8("spinBox_17"));
        spinBox_17->setFont(font);
        spinBox_17->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_17->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_17->setMinimum(1);
        spinBox_17->setMaximum(9999);

        triggerLayout->setWidget(1, QFormLayout::FieldRole, spinBox_17);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font1);
        label_25->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(2, QFormLayout::LabelRole, label_25);

        spinBox_18 = new QSpinBox(groupBox_3);
        spinBox_18->setObjectName(QString::fromUtf8("spinBox_18"));
        spinBox_18->setFont(font);
        spinBox_18->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_18->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_18->setMinimum(1);
        spinBox_18->setMaximum(9999);

        triggerLayout->setWidget(2, QFormLayout::FieldRole, spinBox_18);

        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font1);
        label_37->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(3, QFormLayout::LabelRole, label_37);

        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}QComboBox:focus{border-color: #3498db;}QComboBox::drop-down{width: 28px;}"));

        triggerLayout->setWidget(3, QFormLayout::FieldRole, comboBox_2);

        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font1);
        label_38->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(4, QFormLayout::LabelRole, label_38);

        spinBox_20 = new QSpinBox(groupBox_3);
        spinBox_20->setObjectName(QString::fromUtf8("spinBox_20"));
        spinBox_20->setFont(font);
        spinBox_20->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_20->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_20->setMinimum(1);
        spinBox_20->setMaximum(9999);

        triggerLayout->setWidget(4, QFormLayout::FieldRole, spinBox_20);

        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font1);
        label_39->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(5, QFormLayout::LabelRole, label_39);

        spinBox_21 = new QSpinBox(groupBox_3);
        spinBox_21->setObjectName(QString::fromUtf8("spinBox_21"));
        spinBox_21->setFont(font);
        spinBox_21->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}QSpinBox:focus{border-color: #3498db;}"));
        spinBox_21->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_21->setMinimum(1);
        spinBox_21->setMaximum(9999);

        triggerLayout->setWidget(5, QFormLayout::FieldRole, spinBox_21);


        contentArea->addWidget(groupBox_3);


        mainLayout->addLayout(contentArea);

        bottomBar = new QHBoxLayout();
        bottomBar->setObjectName(QString::fromUtf8("bottomBar"));
        bottomSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomBar->addItem(bottomSpacer);

        btnClose = new QPushButton(JgadminClass);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(80, 36));
        btnClose->setMaximumSize(QSize(80, 36));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #c0392b;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon1);
        btnClose->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnClose);


        mainLayout->addLayout(bottomBar);


        retranslateUi(JgadminClass);

        QMetaObject::connectSlotsByName(JgadminClass);
    } // setupUi

    void retranslateUi(QWidget *JgadminClass)
    {
        JgadminClass->setWindowTitle(QCoreApplication::translate("JgadminClass", "\346\211\223\345\215\260\345\217\202\346\225\260", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("JgadminClass", "\346\265\201\346\260\264\347\272\277\350\256\276\347\275\256", nullptr));
        label_103->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\346\214\257\351\225\234\345\271\205\351\235\242:", nullptr));
        label_99->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\347\274\226\347\240\201\345\231\250\346\226\271\345\220\221:", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("JgadminClass", "\351\241\272\346\227\266\351\222\210", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("JgadminClass", "\351\200\206\346\227\266\351\222\210", nullptr));

        label_102->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\350\275\264\346\226\271\345\220\221:", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("JgadminClass", "X\350\275\264\351\243\236\350\241\214", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("JgadminClass", "Y\350\275\264\351\243\236\350\241\214", nullptr));

        label_72->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\346\250\241\345\274\217\345\274\200\345\205\263:", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("JgadminClass", "\351\235\231\346\200\201", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214", nullptr));

        label_100->setText(QCoreApplication::translate("JgadminClass", "\347\274\226\347\240\201\345\231\250\350\204\211\345\206\262\346\225\260:", nullptr));
        label_101->setText(QCoreApplication::translate("JgadminClass", "\347\274\226\347\240\201\345\231\250\347\233\264\345\276\204:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("JgadminClass", "\345\226\267\347\240\201\345\217\202\346\225\260", nullptr));
        label_27->setText(QCoreApplication::translate("JgadminClass", "\346\277\200\345\205\211\345\212\237\347\216\207:", nullptr));
        label_34->setText(QCoreApplication::translate("JgadminClass", "\346\277\200\345\205\211\351\242\221\347\216\207:", nullptr));
        label_41->setText(QCoreApplication::translate("JgadminClass", "\345\274\200\345\205\211\345\273\266\346\227\266:", nullptr));
        label_42->setText(QCoreApplication::translate("JgadminClass", "\345\205\263\345\205\211\345\273\266\346\227\266:", nullptr));
        label_44->setText(QCoreApplication::translate("JgadminClass", "\350\267\263\350\275\254\345\273\266\346\227\266:", nullptr));
        label_45->setText(QCoreApplication::translate("JgadminClass", "\347\273\223\346\235\237\345\273\266\346\227\266:", nullptr));
        label_20->setText(QCoreApplication::translate("JgadminClass", "\345\205\211\347\224\265\346\273\244\346\263\242:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("JgadminClass", "\350\247\246\345\217\221\344\274\230\345\214\226", nullptr));
        label_23->setText(QCoreApplication::translate("JgadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\346\250\241\345\274\217:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("JgadminClass", "\345\205\263\351\227\255", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("JgadminClass", "\346\227\266\351\227\264\346\250\241\345\274\217", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("JgadminClass", "\350\267\235\347\246\273\346\250\241\345\274\217", nullptr));

        label_22->setText(QCoreApplication::translate("JgadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\346\227\266\351\227\264:", nullptr));
        label_25->setText(QCoreApplication::translate("JgadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\350\267\235\347\246\273:", nullptr));
        label_37->setText(QCoreApplication::translate("JgadminClass", "\346\240\207\345\210\273\345\273\266\345\220\216\350\247\246\345\217\221\346\250\241\345\274\217:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("JgadminClass", "\345\205\263\351\227\255", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("JgadminClass", "\346\227\266\351\227\264\346\250\241\345\274\217", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("JgadminClass", "\350\267\235\347\246\273\346\250\241\345\274\217", nullptr));

        label_38->setText(QCoreApplication::translate("JgadminClass", "\346\240\207\345\210\273\345\273\266\345\220\216\350\247\246\345\217\221\346\227\266\351\227\264:", nullptr));
        label_39->setText(QCoreApplication::translate("JgadminClass", "\346\240\207\345\210\273\345\273\266\345\220\216\350\247\246\345\217\221\350\267\235\347\246\273:", nullptr));
        btnClose->setText(QCoreApplication::translate("JgadminClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JgadminClass: public Ui_JgadminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JGADMIN_H
