/********************************************************************************
** Form generated from reading UI file 'AddScheme.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCHEME_H
#define UI_ADDSCHEME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
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

class Ui_AddSchemeClass
{
public:
    QVBoxLayout *mainLayout;
    QStackedWidget *stackedWidget_2;
    QWidget *stackedWidgetPage1;
    QVBoxLayout *page1Layout;
    QHBoxLayout *hl_scheme;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton;
    QHBoxLayout *hl_dc;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_mm;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_2;
    QHBoxLayout *hl_warn;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLabel *label_bag;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_4;
    QHBoxLayout *hl_machine;
    QLabel *label_8;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *pageIntermittent;
    QHBoxLayout *hl_delay1;
    QLabel *label_24;
    QLineEdit *lineEdit_8;
    QLabel *label_ms1;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButton_12;
    QHBoxLayout *hl_delay2;
    QLabel *label_23;
    QLineEdit *lineEdit_7;
    QLabel *label_ms2;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButton_11;
    QWidget *page_2;
    QVBoxLayout *pageContinuous;
    QHBoxLayout *hl_dist1;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QLabel *label_mm1;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_13;
    QHBoxLayout *hl_dist2;
    QLabel *label_13;
    QLineEdit *lineEdit_6;
    QLabel *label_mm2;
    QSpacerItem *horizontalSpacer_9;
    QToolButton *toolButton_10;
    QSpacerItem *vSpacer1;
    QWidget *page_3;
    QVBoxLayout *page3Layout;
    QFormLayout *formInfo;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_15;
    QHBoxLayout *hl_chain;
    QLabel *label_21;
    QLabel *label_16;
    QLabel *label_22;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_19;
    QLabel *label_20;
    QSpacerItem *vSpacer;
    QHBoxLayout *hl_reviewBtns;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_10;
    QHBoxLayout *hl_bottom;
    QToolButton *toolButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *AddSchemeClass)
    {
        if (AddSchemeClass->objectName().isEmpty())
            AddSchemeClass->setObjectName(QString::fromUtf8("AddSchemeClass"));
        AddSchemeClass->resize(693, 351);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/BCPF.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddSchemeClass->setWindowIcon(icon);
        AddSchemeClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(AddSchemeClass);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        stackedWidget_2 = new QStackedWidget(AddSchemeClass);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget_2->setStyleSheet(QString::fromUtf8(""));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QString::fromUtf8("stackedWidgetPage1"));
        page1Layout = new QVBoxLayout(stackedWidgetPage1);
        page1Layout->setSpacing(0);
        page1Layout->setObjectName(QString::fromUtf8("page1Layout"));
        page1Layout->setContentsMargins(0, 0, 0, 0);
        hl_scheme = new QHBoxLayout();
        hl_scheme->setObjectName(QString::fromUtf8("hl_scheme"));
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(108, 0));
        label_2->setMaximumSize(QSize(200, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c;"));

        hl_scheme->addWidget(label_2);

        lineEdit = new QLineEdit(stackedWidgetPage1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 0));
        lineEdit->setMaximumSize(QSize(300, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_scheme->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_scheme->addItem(horizontalSpacer_2);

        toolButton = new QToolButton(stackedWidgetPage1);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(100, 38));
        toolButton->setMaximumSize(QSize(100, 16777215));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_scheme->addWidget(toolButton);


        page1Layout->addLayout(hl_scheme);

        hl_dc = new QHBoxLayout();
        hl_dc->setObjectName(QString::fromUtf8("hl_dc"));
        label_4 = new QLabel(stackedWidgetPage1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(108, 0));
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c;"));

        hl_dc->addWidget(label_4);

        lineEdit_2 = new QLineEdit(stackedWidgetPage1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(104, 0));
        lineEdit_2->setMaximumSize(QSize(104, 16777215));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_dc->addWidget(lineEdit_2);

        label_mm = new QLabel(stackedWidgetPage1);
        label_mm->setObjectName(QString::fromUtf8("label_mm"));
        label_mm->setStyleSheet(QString::fromUtf8("font: 15px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_dc->addWidget(label_mm);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_dc->addItem(horizontalSpacer_3);

        toolButton_2 = new QToolButton(stackedWidgetPage1);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(100, 38));
        toolButton_2->setMaximumSize(QSize(100, 16777215));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_dc->addWidget(toolButton_2);


        page1Layout->addLayout(hl_dc);

        hl_warn = new QHBoxLayout();
        hl_warn->setObjectName(QString::fromUtf8("hl_warn"));
        label_7 = new QLabel(stackedWidgetPage1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(108, 0));
        label_7->setMaximumSize(QSize(200, 16777215));
        label_7->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c;"));

        hl_warn->addWidget(label_7);

        lineEdit_4 = new QLineEdit(stackedWidgetPage1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(104, 0));
        lineEdit_4->setMaximumSize(QSize(104, 16777215));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_warn->addWidget(lineEdit_4);

        label_bag = new QLabel(stackedWidgetPage1);
        label_bag->setObjectName(QString::fromUtf8("label_bag"));
        label_bag->setStyleSheet(QString::fromUtf8("font: 15px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_warn->addWidget(label_bag);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_warn->addItem(horizontalSpacer_4);

        toolButton_4 = new QToolButton(stackedWidgetPage1);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(100, 38));
        toolButton_4->setMaximumSize(QSize(100, 16777215));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_warn->addWidget(toolButton_4);


        page1Layout->addLayout(hl_warn);

        hl_machine = new QHBoxLayout();
        hl_machine->setObjectName(QString::fromUtf8("hl_machine"));
        label_8 = new QLabel(stackedWidgetPage1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(108, 0));
        label_8->setMaximumSize(QSize(200, 16777215));
        label_8->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c;"));

        hl_machine->addWidget(label_8);

        comboBox = new QComboBox(stackedWidgetPage1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(300, 38));
        comboBox->setMaximumSize(QSize(300, 16777215));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{font: 14px \"Microsoft YaHei\"; padding: 6px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QComboBox:focus{border-color: #3498db;}\n"
"QComboBox::drop-down{subcontrol-position: right; width: 30px;}\n"
"QComboBox::down-arrow {\n"
"    image: url(:/PNG/Resources/PNG/down_2.png);\n"
"} "));

        hl_machine->addWidget(comboBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_machine->addItem(horizontalSpacer_5);

        toolButton_5 = new QToolButton(stackedWidgetPage1);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(100, 38));
        toolButton_5->setMaximumSize(QSize(100, 16777215));
        toolButton_5->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_machine->addWidget(toolButton_5);


        page1Layout->addLayout(hl_machine);

        stackedWidget = new QStackedWidget(stackedWidgetPage1);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pageIntermittent = new QVBoxLayout(page);
        pageIntermittent->setSpacing(0);
        pageIntermittent->setObjectName(QString::fromUtf8("pageIntermittent"));
        pageIntermittent->setContentsMargins(0, 0, 0, 0);
        hl_delay1 = new QHBoxLayout();
        hl_delay1->setObjectName(QString::fromUtf8("hl_delay1"));
        label_24 = new QLabel(page);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(108, 0));
        label_24->setMaximumSize(QSize(200, 16777215));
        label_24->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_delay1->addWidget(label_24);

        lineEdit_8 = new QLineEdit(page);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 100px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_delay1->addWidget(lineEdit_8);

        label_ms1 = new QLabel(page);
        label_ms1->setObjectName(QString::fromUtf8("label_ms1"));
        label_ms1->setStyleSheet(QString::fromUtf8("font: 14px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_delay1->addWidget(label_ms1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_delay1->addItem(horizontalSpacer_6);

        toolButton_12 = new QToolButton(page);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setMinimumSize(QSize(100, 34));
        toolButton_12->setMaximumSize(QSize(100, 16777215));
        toolButton_12->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_delay1->addWidget(toolButton_12);


        pageIntermittent->addLayout(hl_delay1);

        hl_delay2 = new QHBoxLayout();
        hl_delay2->setObjectName(QString::fromUtf8("hl_delay2"));
        label_23 = new QLabel(page);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(108, 0));
        label_23->setMaximumSize(QSize(200, 16777215));
        label_23->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_delay2->addWidget(label_23);

        lineEdit_7 = new QLineEdit(page);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 100px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_delay2->addWidget(lineEdit_7);

        label_ms2 = new QLabel(page);
        label_ms2->setObjectName(QString::fromUtf8("label_ms2"));
        label_ms2->setStyleSheet(QString::fromUtf8("font: 14px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_delay2->addWidget(label_ms2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_delay2->addItem(horizontalSpacer_7);

        toolButton_11 = new QToolButton(page);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        toolButton_11->setMinimumSize(QSize(100, 34));
        toolButton_11->setMaximumSize(QSize(100, 16777215));
        toolButton_11->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_delay2->addWidget(toolButton_11);


        pageIntermittent->addLayout(hl_delay2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pageContinuous = new QVBoxLayout(page_2);
        pageContinuous->setSpacing(0);
        pageContinuous->setObjectName(QString::fromUtf8("pageContinuous"));
        pageContinuous->setContentsMargins(0, 0, 0, 0);
        hl_dist1 = new QHBoxLayout();
        hl_dist1->setObjectName(QString::fromUtf8("hl_dist1"));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_dist1->addWidget(label_10);

        lineEdit_9 = new QLineEdit(page_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(104, 0));
        lineEdit_9->setMaximumSize(QSize(128, 16777215));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 100px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_dist1->addWidget(lineEdit_9);

        label_mm1 = new QLabel(page_2);
        label_mm1->setObjectName(QString::fromUtf8("label_mm1"));
        label_mm1->setStyleSheet(QString::fromUtf8("font: 14px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_dist1->addWidget(label_mm1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_dist1->addItem(horizontalSpacer_8);

        toolButton_13 = new QToolButton(page_2);
        toolButton_13->setObjectName(QString::fromUtf8("toolButton_13"));
        toolButton_13->setMinimumSize(QSize(100, 34));
        toolButton_13->setMaximumSize(QSize(100, 16777215));
        toolButton_13->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_dist1->addWidget(toolButton_13);


        pageContinuous->addLayout(hl_dist1);

        hl_dist2 = new QHBoxLayout();
        hl_dist2->setObjectName(QString::fromUtf8("hl_dist2"));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: bold 13px \"Microsoft YaHei\"; color: #e74c3c; background: transparent;"));

        hl_dist2->addWidget(label_13);

        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(104, 0));
        lineEdit_6->setMaximumSize(QSize(128, 16777215));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit{font: 15px \"Microsoft YaHei\"; padding: 8px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white; max-width: 100px;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        hl_dist2->addWidget(lineEdit_6);

        label_mm2 = new QLabel(page_2);
        label_mm2->setObjectName(QString::fromUtf8("label_mm2"));
        label_mm2->setStyleSheet(QString::fromUtf8("font: 14px \"Microsoft YaHei\"; color: #7f8c8d; background: transparent;"));

        hl_dist2->addWidget(label_mm2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_dist2->addItem(horizontalSpacer_9);

        toolButton_10 = new QToolButton(page_2);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setMinimumSize(QSize(100, 34));
        toolButton_10->setMaximumSize(QSize(100, 16777215));
        toolButton_10->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #2980b9;}"));

        hl_dist2->addWidget(toolButton_10);


        pageContinuous->addLayout(hl_dist2);

        stackedWidget->addWidget(page_2);

        page1Layout->addWidget(stackedWidget);

        vSpacer1 = new QSpacerItem(20, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        page1Layout->addItem(vSpacer1);

        stackedWidget_2->addWidget(stackedWidgetPage1);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page3Layout = new QVBoxLayout(page_3);
        page3Layout->setSpacing(0);
        page3Layout->setObjectName(QString::fromUtf8("page3Layout"));
        page3Layout->setContentsMargins(0, 0, 0, 0);
        formInfo = new QFormLayout();
        formInfo->setObjectName(QString::fromUtf8("formInfo"));
        formInfo->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        formInfo->setHorizontalSpacing(16);
        formInfo->setVerticalSpacing(16);
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: bold 20px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        formInfo->setWidget(0, QFormLayout::LabelRole, label_5);

        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        label_9->setFont(font);

        formInfo->setWidget(0, QFormLayout::FieldRole, label_9);

        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: bold 20px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        formInfo->setWidget(1, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(page_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        formInfo->setWidget(1, QFormLayout::FieldRole, label_12);

        label_17 = new QLabel(page_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: bold 20px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        formInfo->setWidget(2, QFormLayout::LabelRole, label_17);

        label_18 = new QLabel(page_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font);

        formInfo->setWidget(2, QFormLayout::FieldRole, label_18);

        label_15 = new QLabel(page_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setBold(true);
        font1.setItalic(false);
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("font: bold 20px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        formInfo->setWidget(3, QFormLayout::LabelRole, label_15);

        hl_chain = new QHBoxLayout();
        hl_chain->setObjectName(QString::fromUtf8("hl_chain"));
        label_21 = new QLabel(page_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font2;
        font2.setPointSize(12);
        label_21->setFont(font2);

        hl_chain->addWidget(label_21);

        label_16 = new QLabel(page_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);

        hl_chain->addWidget(label_16);

        label_22 = new QLabel(page_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);

        hl_chain->addWidget(label_22);


        formInfo->setLayout(3, QFormLayout::FieldRole, hl_chain);

        label_25 = new QLabel(page_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("font: bold 18px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        formInfo->setWidget(4, QFormLayout::LabelRole, label_25);

        label_26 = new QLabel(page_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font);

        formInfo->setWidget(4, QFormLayout::FieldRole, label_26);

        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: bold 18px \"Microsoft YaHei\"; color: #34495e; background: transparent;"));

        formInfo->setWidget(5, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(page_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        formInfo->setWidget(5, QFormLayout::FieldRole, label_20);


        page3Layout->addLayout(formInfo);

        vSpacer = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        page3Layout->addItem(vSpacer);

        hl_reviewBtns = new QHBoxLayout();
        hl_reviewBtns->setObjectName(QString::fromUtf8("hl_reviewBtns"));
        pushButton_11 = new QPushButton(page_3);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(150, 48));
        QFont font3;
        font3.setBold(true);
        pushButton_11->setFont(font3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/YXBZC.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);
        pushButton_11->setIconSize(QSize(33, 33));

        hl_reviewBtns->addWidget(pushButton_11);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hl_reviewBtns->addItem(horizontalSpacer);

        pushButton_10 = new QPushButton(page_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(150, 48));
        pushButton_10->setFont(font3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/ZCYX.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon2);
        pushButton_10->setIconSize(QSize(33, 33));

        hl_reviewBtns->addWidget(pushButton_10);


        page3Layout->addLayout(hl_reviewBtns);

        stackedWidget_2->addWidget(page_3);

        mainLayout->addWidget(stackedWidget_2);

        hl_bottom = new QHBoxLayout();
        hl_bottom->setObjectName(QString::fromUtf8("hl_bottom"));
        hl_bottom->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        toolButton_7 = new QToolButton(AddSchemeClass);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy);
        toolButton_7->setMinimumSize(QSize(0, 0));
        toolButton_7->setFont(font3);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PIC/Resources/PICs/notsave.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon3);
        toolButton_7->setIconSize(QSize(33, 33));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        hl_bottom->addWidget(toolButton_7);

        pushButton_8 = new QPushButton(AddSchemeClass);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setMinimumSize(QSize(0, 0));
        pushButton_8->setFont(font3);
        pushButton_8->setStyleSheet(QString::fromUtf8(""));
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(33, 33));

        hl_bottom->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(AddSchemeClass);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setMinimumSize(QSize(0, 0));
        pushButton_9->setFont(font3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon4);
        pushButton_9->setIconSize(QSize(33, 33));

        hl_bottom->addWidget(pushButton_9);


        mainLayout->addLayout(hl_bottom);


        retranslateUi(AddSchemeClass);

        stackedWidget_2->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddSchemeClass);
    } // setupUi

    void retranslateUi(QWidget *AddSchemeClass)
    {
        AddSchemeClass->setWindowTitle(QCoreApplication::translate("AddSchemeClass", "\346\226\260\345\273\272\351\205\215\346\226\271", nullptr));
        label_2->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\240 \350\276\223\345\205\245\351\205\215\346\226\271\345\220\215", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\344\276\213: 455g\351\237\255\350\217\234\351\270\241\350\233\213\347\264\240\346\260\264\351\245\272", nullptr));
        toolButton->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_4->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\241 \350\276\223\345\205\245\345\215\267\346\235\220\350\242\213\351\225\277", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        label_mm->setText(QCoreApplication::translate("AddSchemeClass", "\346\257\253\347\261\263", nullptr));
        toolButton_2->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_7->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\242 \350\276\223\345\205\245\346\212\245\350\255\246\351\227\264\351\232\224", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        label_bag->setText(QCoreApplication::translate("AddSchemeClass", "\350\242\213", nullptr));
        toolButton_4->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_8->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\243 \351\200\211\346\213\251\345\214\205\350\243\205\346\234\272\347\261\273\345\236\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AddSchemeClass", "\351\227\264\346\255\207\345\274\217\345\214\205\350\243\205\346\234\272", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AddSchemeClass", "\350\277\236\347\273\255\345\274\217\345\214\205\350\243\205\346\234\272", nullptr));

        toolButton_5->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_24->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\244 \346\211\223\347\240\201\345\273\266\345\220\216\346\227\266\351\227\264", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        label_ms1->setText(QCoreApplication::translate("AddSchemeClass", "\346\257\253\347\247\222", nullptr));
        toolButton_12->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_23->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\245 \346\213\215\347\205\247\345\273\266\345\220\216\346\227\266\351\227\264", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        label_ms2->setText(QCoreApplication::translate("AddSchemeClass", "\346\257\253\347\247\222", nullptr));
        toolButton_11->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_10->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\244 \346\211\223\347\240\201\345\273\266\345\220\216\350\267\235\347\246\273", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        label_mm1->setText(QCoreApplication::translate("AddSchemeClass", "\346\257\253\347\261\263", nullptr));
        toolButton_13->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_13->setText(QCoreApplication::translate("AddSchemeClass", "\342\221\245 \346\213\215\347\205\247\345\273\266\345\220\216\350\267\235\347\246\273", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("AddSchemeClass", "\350\276\223\345\205\245\346\225\260\345\255\227", nullptr));
        label_mm2->setText(QCoreApplication::translate("AddSchemeClass", "\346\257\253\347\261\263", nullptr));
        toolButton_10->setText(QCoreApplication::translate("AddSchemeClass", "\347\241\256\350\256\244", nullptr));
        label_5->setText(QCoreApplication::translate("AddSchemeClass", "\351\205\215\346\226\271\345\220\215\347\247\260\357\274\232", nullptr));
        label_9->setText(QString());
        label_11->setText(QCoreApplication::translate("AddSchemeClass", "\345\215\267\346\235\220\350\242\213\351\225\277\357\274\232", nullptr));
        label_12->setText(QString());
        label_17->setText(QCoreApplication::translate("AddSchemeClass", "\345\214\205\350\243\205\346\234\272\347\261\273\345\236\213\357\274\232", nullptr));
        label_18->setText(QString());
        label_15->setText(QCoreApplication::translate("AddSchemeClass", "\350\277\236\345\214\205\344\275\215\347\275\256\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("AddSchemeClass", "\346\243\200\346\265\213\345\244\261\350\264\245\345\220\216\347\254\254", nullptr));
        label_16->setText(QString());
        label_22->setText(QCoreApplication::translate("AddSchemeClass", "\350\242\213\345\274\200\345\247\213\350\277\236\345\214\205", nullptr));
        label_25->setText(QCoreApplication::translate("AddSchemeClass", "\346\211\223\347\240\201\345\273\266\345\220\216\357\274\232", nullptr));
        label_26->setText(QString());
        label_19->setText(QCoreApplication::translate("AddSchemeClass", "\346\213\215\347\205\247\345\273\266\345\220\216\357\274\232", nullptr));
        label_20->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("AddSchemeClass", "\350\277\224\345\233\236\344\277\256\346\224\271", nullptr));
        pushButton_10->setText(QCoreApplication::translate("AddSchemeClass", "\346\240\270\345\256\236\346\227\240\350\257\257 ", nullptr));
        toolButton_7->setText(QCoreApplication::translate("AddSchemeClass", "\351\205\215\346\226\271\346\240\270\345\256\236", nullptr));
        pushButton_8->setText(QCoreApplication::translate("AddSchemeClass", "\346\267\273\345\212\240\351\205\215\346\226\271", nullptr));
        pushButton_9->setText(QCoreApplication::translate("AddSchemeClass", "\345\217\226\346\266\210\346\226\260\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSchemeClass: public Ui_AddSchemeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCHEME_H
