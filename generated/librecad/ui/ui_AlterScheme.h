/********************************************************************************
** Form generated from reading UI file 'AlterScheme.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERSCHEME_H
#define UI_ALTERSCHEME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlterSchemeClass
{
public:
    QVBoxLayout *mainLayout;
    QWidget *widget;
    QVBoxLayout *widgetLayout;
    QHBoxLayout *hl_name;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_4;
    QHBoxLayout *hl_dc;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton;
    QHBoxLayout *hl_max;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_2;
    QHBoxLayout *hl_min;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_9;
    QHBoxLayout *hl_warn;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButton_3;
    QHBoxLayout *hl_machine;
    QLabel *label_7;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *pageLayout;
    QHBoxLayout *hl_time1;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QLabel *label_ms1;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButton_7;
    QHBoxLayout *hl_time2;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QLabel *label_ms2;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_8;
    QWidget *page_2;
    QVBoxLayout *page2Layout;
    QHBoxLayout *hl_dist1;
    QLabel *label_11;
    QLineEdit *lineEdit_7;
    QLabel *label_mm1;
    QToolButton *toolButton_6;
    QHBoxLayout *hl_dist2;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QLabel *label_mm2;
    QToolButton *toolButton_5;
    QHBoxLayout *hl_btns;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AlterSchemeClass)
    {
        if (AlterSchemeClass->objectName().isEmpty())
            AlterSchemeClass->setObjectName(QString::fromUtf8("AlterSchemeClass"));
        AlterSchemeClass->resize(630, 385);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/GXPF.png"), QSize(), QIcon::Normal, QIcon::Off);
        AlterSchemeClass->setWindowIcon(icon);
        AlterSchemeClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(AlterSchemeClass);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        widget = new QWidget(AlterSchemeClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        widgetLayout = new QVBoxLayout(widget);
        widgetLayout->setSpacing(0);
        widgetLayout->setObjectName(QString::fromUtf8("widgetLayout"));
        widgetLayout->setContentsMargins(0, 0, 0, 0);
        hl_name = new QHBoxLayout();
        hl_name->setObjectName(QString::fromUtf8("hl_name"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(165, 0));
        label_2->setMaximumSize(QSize(165, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("font: bold 16px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_name->addWidget(label_2);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(300, 0));
        lineEdit_4->setMaximumSize(QSize(300, 16777215));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_name->addWidget(lineEdit_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_name->addItem(horizontalSpacer_2);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(100, 34));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_name->addWidget(toolButton_4);


        widgetLayout->addLayout(hl_name);

        hl_dc = new QHBoxLayout();
        hl_dc->setObjectName(QString::fromUtf8("hl_dc"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(165, 0));
        label_4->setMaximumSize(QSize(165, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("font: bold 16px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_dc->addWidget(label_4);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_dc->addWidget(lineEdit);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_dc->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_dc->addItem(horizontalSpacer_3);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(100, 34));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_dc->addWidget(toolButton);


        widgetLayout->addLayout(hl_dc);

        hl_max = new QHBoxLayout();
        hl_max->setObjectName(QString::fromUtf8("hl_max"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(165, 0));
        label_5->setMaximumSize(QSize(165, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("font: bold 16px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_max->addWidget(label_5);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_max->addWidget(lineEdit_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_max->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_max->addItem(horizontalSpacer_4);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(100, 34));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_max->addWidget(toolButton_2);


        widgetLayout->addLayout(hl_max);

        hl_min = new QHBoxLayout();
        hl_min->setObjectName(QString::fromUtf8("hl_min"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(165, 0));
        label_8->setMaximumSize(QSize(165, 16777215));
        label_8->setStyleSheet(QString::fromUtf8("font: bold 16px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_min->addWidget(label_8);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_min->addWidget(lineEdit_5);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_min->addWidget(label_9);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_min->addItem(horizontalSpacer_5);

        toolButton_9 = new QToolButton(widget);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setMinimumSize(QSize(100, 34));
        toolButton_9->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_min->addWidget(toolButton_9);


        widgetLayout->addLayout(hl_min);

        hl_warn = new QHBoxLayout();
        hl_warn->setObjectName(QString::fromUtf8("hl_warn"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(165, 0));
        label_6->setMaximumSize(QSize(165, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("font: bold 16px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_warn->addWidget(label_6);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_warn->addWidget(lineEdit_3);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_warn->addWidget(label_14);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_warn->addItem(horizontalSpacer_6);

        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(100, 34));
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_warn->addWidget(toolButton_3);


        widgetLayout->addLayout(hl_warn);

        hl_machine = new QHBoxLayout();
        hl_machine->setObjectName(QString::fromUtf8("hl_machine"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(165, 0));
        label_7->setMaximumSize(QSize(165, 16777215));
        label_7->setStyleSheet(QString::fromUtf8("font: bold 16px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        hl_machine->addWidget(label_7);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(300, 34));
        comboBox->setMaximumSize(QSize(300, 16777215));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{font: 14px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QComboBox:focus{border-color: #3498db;}\n"
"QComboBox::drop-down{subcontrol-position: right; width: 28px;}\n"
""));

        hl_machine->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_machine->addItem(horizontalSpacer);


        widgetLayout->addLayout(hl_machine);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("#stackedWidget{background: #fafafa; border: 1px solid #e0e0e0; border-radius: 6px;}"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pageLayout = new QVBoxLayout(page);
        pageLayout->setSpacing(0);
        pageLayout->setObjectName(QString::fromUtf8("pageLayout"));
        pageLayout->setContentsMargins(0, 0, 0, 0);
        hl_time1 = new QHBoxLayout();
        hl_time1->setObjectName(QString::fromUtf8("hl_time1"));
        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(165, 0));
        label_12->setMaximumSize(QSize(165, 16777215));
        label_12->setStyleSheet(QString::fromUtf8("font: bold 14px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_time1->addWidget(label_12);

        lineEdit_8 = new QLineEdit(page);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_time1->addWidget(lineEdit_8);

        label_ms1 = new QLabel(page);
        label_ms1->setObjectName(QString::fromUtf8("label_ms1"));
        label_ms1->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_time1->addWidget(label_ms1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_time1->addItem(horizontalSpacer_7);

        toolButton_7 = new QToolButton(page);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(100, 32));
        toolButton_7->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_time1->addWidget(toolButton_7);


        pageLayout->addLayout(hl_time1);

        hl_time2 = new QHBoxLayout();
        hl_time2->setObjectName(QString::fromUtf8("hl_time2"));
        label_13 = new QLabel(page);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(165, 0));
        label_13->setMaximumSize(QSize(165, 16777215));
        label_13->setStyleSheet(QString::fromUtf8("font: bold 14px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_time2->addWidget(label_13);

        lineEdit_9 = new QLineEdit(page);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_time2->addWidget(lineEdit_9);

        label_ms2 = new QLabel(page);
        label_ms2->setObjectName(QString::fromUtf8("label_ms2"));
        label_ms2->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_time2->addWidget(label_ms2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_time2->addItem(horizontalSpacer_8);

        toolButton_8 = new QToolButton(page);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(100, 32));
        toolButton_8->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_time2->addWidget(toolButton_8);


        pageLayout->addLayout(hl_time2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page2Layout = new QVBoxLayout(page_2);
        page2Layout->setSpacing(0);
        page2Layout->setObjectName(QString::fromUtf8("page2Layout"));
        page2Layout->setContentsMargins(0, 0, 0, 0);
        hl_dist1 = new QHBoxLayout();
        hl_dist1->setObjectName(QString::fromUtf8("hl_dist1"));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: bold 14px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_dist1->addWidget(label_11);

        lineEdit_7 = new QLineEdit(page_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_dist1->addWidget(lineEdit_7);

        label_mm1 = new QLabel(page_2);
        label_mm1->setObjectName(QString::fromUtf8("label_mm1"));
        label_mm1->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_dist1->addWidget(label_mm1);

        toolButton_6 = new QToolButton(page_2);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(70, 32));
        toolButton_6->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_dist1->addWidget(toolButton_6);


        page2Layout->addLayout(hl_dist1);

        hl_dist2 = new QHBoxLayout();
        hl_dist2->setObjectName(QString::fromUtf8("hl_dist2"));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: bold 14px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_dist2->addWidget(label_10);

        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit{font: 14px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 80px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_dist2->addWidget(lineEdit_6);

        label_mm2 = new QLabel(page_2);
        label_mm2->setObjectName(QString::fromUtf8("label_mm2"));
        label_mm2->setStyleSheet(QString::fromUtf8("font: 13px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_dist2->addWidget(label_mm2);

        toolButton_5 = new QToolButton(page_2);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(70, 32));
        toolButton_5->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_dist2->addWidget(toolButton_5);


        page2Layout->addLayout(hl_dist2);

        stackedWidget->addWidget(page_2);

        widgetLayout->addWidget(stackedWidget);


        mainLayout->addWidget(widget);

        hl_btns = new QHBoxLayout();
        hl_btns->setObjectName(QString::fromUtf8("hl_btns"));
        pushButton_3 = new QPushButton(AlterSchemeClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(130, 48));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PNG/Resources/PNG/SCPF.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(28, 28));

        hl_btns->addWidget(pushButton_3);

        pushButton = new QPushButton(AlterSchemeClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(130, 48));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/ZCYX.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(28, 28));

        hl_btns->addWidget(pushButton);

        pushButton_2 = new QPushButton(AlterSchemeClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(130, 48));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(28, 28));

        hl_btns->addWidget(pushButton_2);


        mainLayout->addLayout(hl_btns);


        retranslateUi(AlterSchemeClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AlterSchemeClass);
    } // setupUi

    void retranslateUi(QWidget *AlterSchemeClass)
    {
        AlterSchemeClass->setWindowTitle(QCoreApplication::translate("AlterSchemeClass", "\351\205\215\346\226\271\345\217\202\346\225\260\347\256\241\347\220\206", nullptr));
        label_2->setText(QCoreApplication::translate("AlterSchemeClass", "\345\275\223\345\211\215\351\205\215\346\226\271\345\220\215\357\274\232", nullptr));
        toolButton_4->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_4->setText(QCoreApplication::translate("AlterSchemeClass", "\350\242\213\351\225\277(mm)\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("AlterSchemeClass", "\346\257\253\347\261\263", nullptr));
        toolButton->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_5->setText(QCoreApplication::translate("AlterSchemeClass", "\350\242\213\351\225\277\344\270\212\351\231\220\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AlterSchemeClass", "\346\257\253\347\261\263", nullptr));
        toolButton_2->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_8->setText(QCoreApplication::translate("AlterSchemeClass", "\350\242\213\351\225\277\344\270\213\351\231\220\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("AlterSchemeClass", "\346\257\253\347\261\263", nullptr));
        toolButton_9->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_6->setText(QCoreApplication::translate("AlterSchemeClass", "\346\212\245\350\255\246\350\277\236\345\214\205\357\274\210\347\254\254\345\207\240\350\242\213\357\274\211\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("AlterSchemeClass", "\350\242\213", nullptr));
        toolButton_3->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_7->setText(QCoreApplication::translate("AlterSchemeClass", "\345\214\205\350\243\205\346\234\272\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AlterSchemeClass", "\351\227\264\346\255\207\345\274\217\345\214\205\350\243\205\346\234\272", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AlterSchemeClass", "\350\277\236\347\273\255\345\274\217\345\214\205\350\243\205\346\234\272", nullptr));

        label_12->setText(QCoreApplication::translate("AlterSchemeClass", "\346\211\223\347\240\201\345\273\266\345\220\216\346\227\266\351\227\264\357\274\232", nullptr));
        label_ms1->setText(QCoreApplication::translate("AlterSchemeClass", "\346\257\253\347\247\222", nullptr));
        toolButton_7->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_13->setText(QCoreApplication::translate("AlterSchemeClass", "\346\213\215\347\205\247\345\273\266\345\220\216\346\227\266\351\227\264\357\274\232", nullptr));
        label_ms2->setText(QCoreApplication::translate("AlterSchemeClass", "\346\257\253\347\247\222", nullptr));
        toolButton_8->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_11->setText(QCoreApplication::translate("AlterSchemeClass", "\346\211\223\347\240\201\345\273\266\345\220\216\350\267\235\347\246\273\357\274\232", nullptr));
        label_mm1->setText(QCoreApplication::translate("AlterSchemeClass", "mm", nullptr));
        toolButton_6->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_10->setText(QCoreApplication::translate("AlterSchemeClass", "\346\213\215\347\205\247\345\273\266\345\220\216\350\267\235\347\246\273\357\274\232", nullptr));
        label_mm2->setText(QCoreApplication::translate("AlterSchemeClass", "mm", nullptr));
        toolButton_5->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AlterSchemeClass", "\345\210\240\351\231\244\351\205\215\346\226\271", nullptr));
        pushButton->setText(QCoreApplication::translate("AlterSchemeClass", "\347\241\256\350\256\244\351\205\215\346\226\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AlterSchemeClass", "\345\217\226\346\266\210\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlterSchemeClass: public Ui_AlterSchemeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERSCHEME_H
