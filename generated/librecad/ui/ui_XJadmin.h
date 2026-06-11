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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XJadminClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *contentArea;
    QGroupBox *groupBox;
    QFormLayout *lightLayout;
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
    QFormLayout *rejectLayout;
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
    QFormLayout *triggerLayout;
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
    QHBoxLayout *bottomBar;
    QSpacerItem *bottomSpacer;
    QPushButton *btnClose;

    void setupUi(QMainWindow *XJadminClass)
    {
        if (XJadminClass->objectName().isEmpty())
            XJadminClass->setObjectName(QString::fromUtf8("XJadminClass"));
        XJadminClass->resize(766, 364);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/\344\273\273\345\212\241.png"), QSize(), QIcon::Normal, QIcon::Off);
        XJadminClass->setWindowIcon(icon);
        XJadminClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        centralWidget = new QWidget(XJadminClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        contentArea = new QHBoxLayout();
        contentArea->setObjectName(QString::fromUtf8("contentArea"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        lightLayout = new QFormLayout(groupBox);
        lightLayout->setObjectName(QString::fromUtf8("lightLayout"));
        lightLayout->setHorizontalSpacing(10);
        lightLayout->setVerticalSpacing(6);
        lightLayout->setContentsMargins(16, 20, 16, 16);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lightLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(true);
        spinBox->setFont(font);
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMaximum(255);

        lightLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lightLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setEnabled(true);
        spinBox_2->setFont(font);
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_2->setMaximum(255);

        lightLayout->setWidget(1, QFormLayout::FieldRole, spinBox_2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lightLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setEnabled(true);
        spinBox_3->setFont(font);
        spinBox_3->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_3->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_3->setMaximum(255);

        lightLayout->setWidget(2, QFormLayout::FieldRole, spinBox_3);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lightLayout->setWidget(3, QFormLayout::LabelRole, label_9);

        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setFont(font);
        spinBox_4->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_4->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_4->setMaximum(2000);

        lightLayout->setWidget(3, QFormLayout::FieldRole, spinBox_4);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        lightLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QComboBox:focus{border-color: #3498db;}\n"
"QComboBox::drop-down{width: 28px;}"));

        lightLayout->setWidget(4, QFormLayout::FieldRole, comboBox_2);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(0, 40));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 11px \"Microsoft YaHei\"; border-radius: 4px; padding: 4px 8px; border: 1px solid #bdc3c7; background: #ffffff;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PNG/Resources/PNG/YSXZ.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(24, 24));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        lightLayout->setWidget(5, QFormLayout::SpanningRole, toolButton);


        contentArea->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 1px solid #dcdde1; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 0 6px;}"));
        rejectLayout = new QFormLayout(groupBox_2);
        rejectLayout->setObjectName(QString::fromUtf8("rejectLayout"));
        rejectLayout->setHorizontalSpacing(10);
        rejectLayout->setVerticalSpacing(6);
        rejectLayout->setContentsMargins(16, 20, 16, 16);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(0, QFormLayout::LabelRole, label_11);

        spinBox_6 = new QSpinBox(groupBox_2);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setFont(font);
        spinBox_6->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_6->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_6->setMinimum(1);
        spinBox_6->setMaximum(9999);

        rejectLayout->setWidget(0, QFormLayout::FieldRole, spinBox_6);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(1, QFormLayout::LabelRole, label_12);

        spinBox_7 = new QSpinBox(groupBox_2);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setFont(font);
        spinBox_7->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_7->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_7->setMinimum(1);
        spinBox_7->setMaximum(9999);

        rejectLayout->setWidget(1, QFormLayout::FieldRole, spinBox_7);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        spinBox_8 = new QSpinBox(groupBox_2);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setFont(font);
        spinBox_8->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_8->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_8->setMinimum(1);
        spinBox_8->setMaximum(9999);

        rejectLayout->setWidget(2, QFormLayout::FieldRole, spinBox_8);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(3, QFormLayout::LabelRole, label_15);

        spinBox_9 = new QSpinBox(groupBox_2);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setFont(font);
        spinBox_9->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_9->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_9->setMinimum(0);
        spinBox_9->setMaximum(30);

        rejectLayout->setWidget(3, QFormLayout::FieldRole, spinBox_9);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(4, QFormLayout::LabelRole, label_14);

        spinBox_10 = new QSpinBox(groupBox_2);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setFont(font);
        spinBox_10->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_10->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_10->setMinimum(1);
        spinBox_10->setMaximum(30);

        rejectLayout->setWidget(4, QFormLayout::FieldRole, spinBox_10);

        label_101 = new QLabel(groupBox_2);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setFont(font1);
        label_101->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(5, QFormLayout::LabelRole, label_101);

        spinBox_14 = new QSpinBox(groupBox_2);
        spinBox_14->setObjectName(QString::fromUtf8("spinBox_14"));
        spinBox_14->setFont(font);
        spinBox_14->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_14->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_14->setMinimum(1);
        spinBox_14->setMaximum(999);

        rejectLayout->setWidget(5, QFormLayout::FieldRole, spinBox_14);

        label_100 = new QLabel(groupBox_2);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setFont(font1);
        label_100->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        rejectLayout->setWidget(6, QFormLayout::LabelRole, label_100);

        spinBox_15 = new QSpinBox(groupBox_2);
        spinBox_15->setObjectName(QString::fromUtf8("spinBox_15"));
        spinBox_15->setFont(font);
        spinBox_15->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_15->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_15->setMinimum(1);
        spinBox_15->setMaximum(9999);

        rejectLayout->setWidget(6, QFormLayout::FieldRole, spinBox_15);


        contentArea->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
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

        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setFont(font);
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QComboBox:focus{border-color: #3498db;}\n"
"QComboBox::drop-down{width: 28px;}"));

        triggerLayout->setWidget(0, QFormLayout::FieldRole, comboBox_4);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);
        label_22->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(1, QFormLayout::LabelRole, label_22);

        spinBox_17 = new QSpinBox(groupBox_3);
        spinBox_17->setObjectName(QString::fromUtf8("spinBox_17"));
        spinBox_17->setFont(font);
        spinBox_17->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
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
        spinBox_18->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_18->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_18->setMinimum(1);
        spinBox_18->setMaximum(9999);

        triggerLayout->setWidget(2, QFormLayout::FieldRole, spinBox_18);

        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font1);
        label_43->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(3, QFormLayout::LabelRole, label_43);

        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setFont(font);
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}\n"
"QComboBox:focus{border-color: #3498db;}\n"
"QComboBox::drop-down{width: 28px;}"));

        triggerLayout->setWidget(3, QFormLayout::FieldRole, comboBox_3);

        label_48 = new QLabel(groupBox_3);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setFont(font1);
        label_48->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(4, QFormLayout::LabelRole, label_48);

        spinBox_23 = new QSpinBox(groupBox_3);
        spinBox_23->setObjectName(QString::fromUtf8("spinBox_23"));
        spinBox_23->setFont(font);
        spinBox_23->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_23->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_23->setMinimum(1);
        spinBox_23->setMaximum(9999);

        triggerLayout->setWidget(4, QFormLayout::FieldRole, spinBox_23);

        label_49 = new QLabel(groupBox_3);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setFont(font1);
        label_49->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        triggerLayout->setWidget(5, QFormLayout::LabelRole, label_49);

        spinBox_24 = new QSpinBox(groupBox_3);
        spinBox_24->setObjectName(QString::fromUtf8("spinBox_24"));
        spinBox_24->setFont(font);
        spinBox_24->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 4px; background: white; padding: 2px 6px;}\n"
"QSpinBox:focus{border-color: #3498db;}"));
        spinBox_24->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_24->setMinimum(1);
        spinBox_24->setMaximum(9999);

        triggerLayout->setWidget(5, QFormLayout::FieldRole, spinBox_24);


        contentArea->addWidget(groupBox_3);


        mainLayout->addLayout(contentArea);

        bottomBar = new QHBoxLayout();
        bottomBar->setObjectName(QString::fromUtf8("bottomBar"));
        bottomSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomBar->addItem(bottomSpacer);

        btnClose = new QPushButton(centralWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(80, 36));
        btnClose->setMaximumSize(QSize(80, 36));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #c0392b;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon2);
        btnClose->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnClose);


        mainLayout->addLayout(bottomBar);

        XJadminClass->setCentralWidget(centralWidget);

        retranslateUi(XJadminClass);

        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(XJadminClass);
    } // setupUi

    void retranslateUi(QMainWindow *XJadminClass)
    {
        XJadminClass->setWindowTitle(QCoreApplication::translate("XJadminClass", "\346\243\200\346\265\213\345\217\202\346\225\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("XJadminClass", "\345\205\211\346\272\220\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("XJadminClass", "R\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("XJadminClass", "G\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("XJadminClass", "B\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("XJadminClass", "RGBTime\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("XJadminClass", "RGBMode\357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("XJadminClass", "\351\242\221\351\227\252", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("XJadminClass", "\345\270\270\344\272\256", nullptr));

        toolButton->setText(QCoreApplication::translate("XJadminClass", "\360\237\216\250 \345\205\211\346\272\220\351\242\234\350\211\262\345\277\253\351\200\237\350\256\276\347\275\256", nullptr));
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
        btnClose->setText(QCoreApplication::translate("XJadminClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XJadminClass: public Ui_XJadminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XJADMIN_H
