/********************************************************************************
** Form generated from reading UI file 'qg_dlgmtext.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGMTEXT_H
#define UI_QG_DLGMTEXT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "qg_fontbox.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgMText
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topRow;
    QGroupBox *bgFont;
    QGridLayout *gridLayout;
    QG_FontBox *cbFont;
    QLabel *label_3;
    QLineEdit *lex_scale;
    QLineEdit *lewordspace;
    QLineEdit *ley_scale;
    QLineEdit *leHeight;
    QCheckBox *cbDefault;
    QSpacerItem *verticalSpacer;
    QLabel *lHeight;
    QLabel *lLineSpacingFactor;
    QComboBox *AligncomboBox;
    QLabel *label_4;
    QLineEdit *leLineSpacingFactor;
    QLabel *label_5;
    QLineEdit *leAngle;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *rightColumn;
    QHBoxLayout *printTextHeader;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *teText;
    QHBoxLayout *bottomRow;
    QGroupBox *buttonGroup7;
    QGridLayout *gridLayout1;
    QToolButton *bLoad;
    QToolButton *bClear;
    QToolButton *bSave;
    QToolButton *toolButton_5;
    QToolButton *toolButton_2;
    QToolButton *toolButton_6;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QGroupBox *buttonGroup5;
    QGridLayout *gridLayout2;
    QComboBox *cbUniChar;
    QLabel *textLabel1_2;
    QLabel *label_6;
    QComboBox *cbSymbol;
    QLabel *textLabel1;
    QComboBox *cbUniPage;
    QToolButton *bUnicode;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgMText)
    {
        if (QG_DlgMText->objectName().isEmpty())
            QG_DlgMText->setObjectName(QString::fromUtf8("QG_DlgMText"));
        QG_DlgMText->resize(713, 562);
        QG_DlgMText->setStyleSheet(QString::fromUtf8("QG_DlgMText{background-color:rgb(220, 235, 240);}"));
        QG_DlgMText->setSizeGripEnabled(true);
        mainLayout = new QVBoxLayout(QG_DlgMText);
        mainLayout->setSpacing(5);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(12, 12, 12, 12);
        topRow = new QHBoxLayout();
        topRow->setSpacing(10);
        topRow->setObjectName(QString::fromUtf8("topRow"));
        bgFont = new QGroupBox(QG_DlgMText);
        bgFont->setObjectName(QString::fromUtf8("bgFont"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bgFont->sizePolicy().hasHeightForWidth());
        bgFont->setSizePolicy(sizePolicy);
        bgFont->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 2px solid #e0e0e0; border-radius: 10px; margin-top: 14px; padding-top: 18px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 14px; padding: 4px 14px; background: #3498db; color: white; border-radius: 4px;}\n"
"QLabel{color: #34495e; background: transparent; font: bold 11px \"Microsoft YaHei\"; padding: 2px 2px;}\n"
"QLineEdit{font: bold 11px \"Microsoft YaHei\"; padding: 6px 8px; border: 2px solid #dcdde1; border-radius: 6px; background: #fafafa; min-height: 28px;}\n"
"QLineEdit:focus{border-color: #3498db; background: #ffffff;}\n"
"QCheckBox{font: bold 11px \"Microsoft YaHei\"; color: #34495e; spacing: 6px;}\n"
"QCheckBox::indicator{width: 18px; height: 18px;}"));
        gridLayout = new QGridLayout(bgFont);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 16, 10, 10);
        cbFont = new QG_FontBox(bgFont);
        cbFont->setObjectName(QString::fromUtf8("cbFont"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbFont->sizePolicy().hasHeightForWidth());
        cbFont->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cbFont, 0, 0, 1, 5);

        label_3 = new QLabel(bgFont);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lex_scale = new QLineEdit(bgFont);
        lex_scale->setObjectName(QString::fromUtf8("lex_scale"));
        lex_scale->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lex_scale, 4, 2, 1, 1);

        lewordspace = new QLineEdit(bgFont);
        lewordspace->setObjectName(QString::fromUtf8("lewordspace"));
        lewordspace->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lewordspace, 3, 4, 1, 1);

        ley_scale = new QLineEdit(bgFont);
        ley_scale->setObjectName(QString::fromUtf8("ley_scale"));
        ley_scale->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(ley_scale, 3, 2, 1, 1);

        leHeight = new QLineEdit(bgFont);
        leHeight->setObjectName(QString::fromUtf8("leHeight"));
        sizePolicy1.setHeightForWidth(leHeight->sizePolicy().hasHeightForWidth());
        leHeight->setSizePolicy(sizePolicy1);
        leHeight->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leHeight, 2, 2, 1, 1);

        cbDefault = new QCheckBox(bgFont);
        cbDefault->setObjectName(QString::fromUtf8("cbDefault"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        cbDefault->setFont(font);

        gridLayout->addWidget(cbDefault, 1, 0, 1, 5);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 5);

        lHeight = new QLabel(bgFont);
        lHeight->setObjectName(QString::fromUtf8("lHeight"));

        gridLayout->addWidget(lHeight, 2, 0, 1, 1);

        lLineSpacingFactor = new QLabel(bgFont);
        lLineSpacingFactor->setObjectName(QString::fromUtf8("lLineSpacingFactor"));

        gridLayout->addWidget(lLineSpacingFactor, 2, 3, 1, 1);

        AligncomboBox = new QComboBox(bgFont);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/mtext_align_middleleft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AligncomboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/mtext_align_middlecenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AligncomboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/mtext_align_middleright.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AligncomboBox->addItem(icon2, QString());
        AligncomboBox->setObjectName(QString::fromUtf8("AligncomboBox"));
        AligncomboBox->setStyleSheet(QString::fromUtf8("QComboBox{font: bold 11px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #dcdde1; border-radius: 6px; background: #fafafa; min-height: 28px;}\n"
"QComboBox:focus{border-color: #3498db; background: #ffffff;}\n"
"QComboBox::drop-down{width: 24px;}"));

        gridLayout->addWidget(AligncomboBox, 5, 2, 1, 3);

        label_4 = new QLabel(bgFont);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 3, 1, 1);

        leLineSpacingFactor = new QLineEdit(bgFont);
        leLineSpacingFactor->setObjectName(QString::fromUtf8("leLineSpacingFactor"));
        sizePolicy1.setHeightForWidth(leLineSpacingFactor->sizePolicy().hasHeightForWidth());
        leLineSpacingFactor->setSizePolicy(sizePolicy1);
        leLineSpacingFactor->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leLineSpacingFactor, 2, 4, 1, 1);

        label_5 = new QLabel(bgFont);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        leAngle = new QLineEdit(bgFont);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        sizePolicy1.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy1);
        leAngle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leAngle, 4, 4, 1, 1);

        label = new QLabel(bgFont);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 3, 1, 1);

        label_2 = new QLabel(bgFont);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);


        topRow->addWidget(bgFont);

        rightColumn = new QVBoxLayout();
        rightColumn->setSpacing(6);
        rightColumn->setObjectName(QString::fromUtf8("rightColumn"));
        printTextHeader = new QHBoxLayout();
        printTextHeader->setSpacing(8);
        printTextHeader->setObjectName(QString::fromUtf8("printTextHeader"));
        label_7 = new QLabel(QG_DlgMText);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: #2c3e50; background: transparent; font: bold 14px \"Microsoft YaHei\";"));

        printTextHeader->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        printTextHeader->addItem(horizontalSpacer);

        label_8 = new QLabel(QG_DlgMText);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent; font: bold 12px \"Microsoft YaHei\";"));

        printTextHeader->addWidget(label_8);

        label_9 = new QLabel(QG_DlgMText);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color: #e74c3c; background: transparent; font: bold 12px \"Microsoft YaHei\";"));

        printTextHeader->addWidget(label_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        printTextHeader->addItem(horizontalSpacer_2);


        rightColumn->addLayout(printTextHeader);

        teText = new QTextEdit(QG_DlgMText);
        teText->setObjectName(QString::fromUtf8("teText"));
        teText->setStyleSheet(QString::fromUtf8("QTextEdit{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #dcdde1; border-radius: 8px; background: #ffffff; padding: 8px;}\n"
"QTextEdit:focus{border-color: #3498db;}"));

        rightColumn->addWidget(teText);


        topRow->addLayout(rightColumn);

        topRow->setStretch(0, 1);
        topRow->setStretch(1, 1);

        mainLayout->addLayout(topRow);

        bottomRow = new QHBoxLayout();
        bottomRow->setSpacing(10);
        bottomRow->setObjectName(QString::fromUtf8("bottomRow"));
        buttonGroup7 = new QGroupBox(QG_DlgMText);
        buttonGroup7->setObjectName(QString::fromUtf8("buttonGroup7"));
        sizePolicy.setHeightForWidth(buttonGroup7->sizePolicy().hasHeightForWidth());
        buttonGroup7->setSizePolicy(sizePolicy);
        buttonGroup7->setMinimumSize(QSize(148, 0));
        buttonGroup7->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 2px solid #e0e0e0; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 4px 12px; background: #3498db; color: white; border-radius: 4px;}\n"
"QToolButton{font: bold 9px \"Microsoft YaHei\"; border: 1px solid #e0e0e0; border-radius: 6px; padding: 4px 8px; background: #f8f9fa; min-height: 36px;}\n"
"QToolButton:hover{background: #e8f0fe; border-color: #3498db;}\n"
"QToolButton:pressed{background: #d4e6f9; padding-top: 6px; padding-bottom: 2px;}"));
        gridLayout1 = new QGridLayout(buttonGroup7);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setContentsMargins(8, 14, 8, 8);
        bLoad = new QToolButton(buttonGroup7);
        bLoad->setObjectName(QString::fromUtf8("bLoad"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PNG/Resources/PNG/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        bLoad->setIcon(icon3);
        bLoad->setIconSize(QSize(32, 32));
        bLoad->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bLoad, 0, 0, 1, 1);

        bClear = new QToolButton(buttonGroup7);
        bClear->setObjectName(QString::fromUtf8("bClear"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PNG/Resources/PNG/clear .png"), QSize(), QIcon::Normal, QIcon::Off);
        bClear->setIcon(icon4);
        bClear->setIconSize(QSize(32, 32));
        bClear->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bClear, 0, 1, 1, 1);

        bSave = new QToolButton(buttonGroup7);
        bSave->setObjectName(QString::fromUtf8("bSave"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PNG/Resources/PNG/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        bSave->setIcon(icon5);
        bSave->setIconSize(QSize(32, 32));
        bSave->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bSave, 0, 2, 1, 1);

        toolButton_5 = new QToolButton(buttonGroup7);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PIC/Resources/PICs/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon6);
        toolButton_5->setIconSize(QSize(32, 32));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_5, 1, 0, 1, 1);

        toolButton_2 = new QToolButton(buttonGroup7);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setIcon(icon6);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_2, 1, 1, 1, 1);

        toolButton_6 = new QToolButton(buttonGroup7);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/PIC/Resources/PICs/line break.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon7);
        toolButton_6->setIconSize(QSize(32, 32));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_6, 1, 2, 1, 1);

        toolButton = new QToolButton(buttonGroup7);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/PIC/Resources/PICs/rl.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon8);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton, 2, 0, 1, 1);

        toolButton_3 = new QToolButton(buttonGroup7);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setIcon(icon8);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_3, 2, 1, 1, 1);

        toolButton_4 = new QToolButton(buttonGroup7);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/PIC/Resources/PICs/time.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon9);
        toolButton_4->setIconSize(QSize(32, 32));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_4, 2, 2, 1, 1);


        bottomRow->addWidget(buttonGroup7);

        buttonGroup5 = new QGroupBox(QG_DlgMText);
        buttonGroup5->setObjectName(QString::fromUtf8("buttonGroup5"));
        buttonGroup5->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 13px \"Microsoft YaHei\"; color: #2c3e50; border: 2px solid #e0e0e0; border-radius: 8px; margin-top: 12px; padding-top: 16px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 12px; padding: 4px 12px; background: #27ae60; color: white; border-radius: 4px;}\n"
"QLabel{font: bold 11px \"Microsoft YaHei\"; color: #34495e; background: transparent;}\n"
"QComboBox{font: 11px \"Microsoft YaHei\"; padding: 4px 8px; border: 2px solid #dcdde1; border-radius: 6px; background: #fafafa; min-height: 28px;}\n"
"QComboBox:focus{border-color: #3498db; background: #ffffff;}\n"
"QComboBox::drop-down{width: 22px;}\n"
"QToolButton{border: 1px solid #bdc3c7; border-radius: 4px; background: #f8f9fa;}\n"
"QToolButton:hover{background: #e8f0fe; border-color: #3498db;}"));
        gridLayout2 = new QGridLayout(buttonGroup5);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        gridLayout2->setContentsMargins(8, 14, 8, 8);
        cbUniChar = new QComboBox(buttonGroup5);
        cbUniChar->setObjectName(QString::fromUtf8("cbUniChar"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbUniChar->sizePolicy().hasHeightForWidth());
        cbUniChar->setSizePolicy(sizePolicy2);
        cbUniChar->setMinimumSize(QSize(92, 40));

        gridLayout2->addWidget(cbUniChar, 4, 2, 1, 2);

        textLabel1_2 = new QLabel(buttonGroup5);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));

        gridLayout2->addWidget(textLabel1_2, 4, 0, 1, 1);

        label_6 = new QLabel(buttonGroup5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout2->addWidget(label_6, 0, 0, 1, 1);

        cbSymbol = new QComboBox(buttonGroup5);
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->setObjectName(QString::fromUtf8("cbSymbol"));
        sizePolicy2.setHeightForWidth(cbSymbol->sizePolicy().hasHeightForWidth());
        cbSymbol->setSizePolicy(sizePolicy2);

        gridLayout2->addWidget(cbSymbol, 0, 2, 1, 2);

        textLabel1 = new QLabel(buttonGroup5);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));

        gridLayout2->addWidget(textLabel1, 1, 0, 1, 1);

        cbUniPage = new QComboBox(buttonGroup5);
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->setObjectName(QString::fromUtf8("cbUniPage"));
        sizePolicy2.setHeightForWidth(cbUniPage->sizePolicy().hasHeightForWidth());
        cbUniPage->setSizePolicy(sizePolicy2);
        cbUniPage->setMinimumSize(QSize(280, 40));

        gridLayout2->addWidget(cbUniPage, 1, 2, 1, 1);

        bUnicode = new QToolButton(buttonGroup5);
        bUnicode->setObjectName(QString::fromUtf8("bUnicode"));
        bUnicode->setMinimumSize(QSize(28, 28));
        bUnicode->setMaximumSize(QSize(28, 28));
        bUnicode->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px; border-radius: 4px;} QToolButton:hover{background: #3498db; color: white;}"));

        gridLayout2->addWidget(bUnicode, 1, 3, 1, 1);


        bottomRow->addWidget(buttonGroup5);

        bottomRow->setStretch(0, 1);
        bottomRow->setStretch(1, 1);

        mainLayout->addLayout(bottomRow);

        buttonBox = new QDialogButtonBox(QG_DlgMText);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; padding: 8px 24px; border-radius: 6px; min-width: 50px;}\n"
"QPushButton[text=\"OK\"], QPushButton[text=\"\347\241\256\345\256\232\"]{background: #3498db; color: white;}\n"
"QPushButton[text=\"OK\"]:hover, QPushButton[text=\"\347\241\256\345\256\232\"]:hover{background: #2980b9;}\n"
"QPushButton[text=\"Cancel\"], QPushButton[text=\"\345\217\226\346\266\210\"]{background: #95a5a6; color: white;}\n"
"QPushButton[text=\"Cancel\"]:hover, QPushButton[text=\"\345\217\226\346\266\210\"]:hover{background: #7f8c8d;}"));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        mainLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        lHeight->setBuddy(leHeight);
        lLineSpacingFactor->setBuddy(leLineSpacingFactor);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QG_DlgMText);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgMText, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgMText, SLOT(reject()));
        QObject::connect(bClear, SIGNAL(clicked()), teText, SLOT(clear()));
        QObject::connect(bLoad, SIGNAL(clicked()), QG_DlgMText, SLOT(loadText()));
        QObject::connect(bSave, SIGNAL(clicked()), QG_DlgMText, SLOT(saveText()));
        QObject::connect(cbUniPage, SIGNAL(activated(int)), QG_DlgMText, SLOT(updateUniCharComboBox(int)));
        QObject::connect(bUnicode, SIGNAL(clicked()), QG_DlgMText, SLOT(insertChar()));
        QObject::connect(cbUniPage, SIGNAL(activated(int)), QG_DlgMText, SLOT(updateUniCharButton(int)));
        QObject::connect(cbUniChar, SIGNAL(activated(int)), QG_DlgMText, SLOT(updateUniCharButton(int)));
        QObject::connect(cbSymbol, SIGNAL(activated(int)), QG_DlgMText, SLOT(insertSymbol(int)));
        QObject::connect(cbDefault, SIGNAL(toggled(bool)), leLineSpacingFactor, SLOT(setDisabled(bool)));
        QObject::connect(cbDefault, SIGNAL(toggled(bool)), QG_DlgMText, SLOT(defaultChanged(bool)));
        QObject::connect(toolButton_4, SIGNAL(clicked()), QG_DlgMText, SLOT(setQuickTime()));
        QObject::connect(toolButton_3, SIGNAL(clicked()), QG_DlgMText, SLOT(setEXPDate()));
        QObject::connect(toolButton, SIGNAL(clicked()), QG_DlgMText, SLOT(setMFGDate()));
        QObject::connect(toolButton_5, SIGNAL(clicked()), QG_DlgMText, SLOT(setMFGDateText()));
        QObject::connect(toolButton_2, SIGNAL(clicked()), QG_DlgMText, SLOT(setEXPDateText()));
        QObject::connect(toolButton_6, SIGNAL(clicked()), QG_DlgMText, SLOT(setLineBreak()));

        QMetaObject::connectSlotsByName(QG_DlgMText);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgMText)
    {
        QG_DlgMText->setWindowTitle(QCoreApplication::translate("QG_DlgMText", "\346\226\207\346\234\254\347\274\226\350\276\221", nullptr));
        bgFont->setTitle(QCoreApplication::translate("QG_DlgMText", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("QG_DlgMText", "X\350\275\264\347\274\251\346\224\276\357\274\232", nullptr));
        cbDefault->setText(QCoreApplication::translate("QG_DlgMText", "\351\273\230\350\256\244\350\241\214\351\227\264\350\267\235", nullptr));
        lHeight->setText(QCoreApplication::translate("QG_DlgMText", "\351\253\230\345\272\246\357\274\232", nullptr));
        lLineSpacingFactor->setText(QCoreApplication::translate("QG_DlgMText", "\350\241\214\351\227\264\350\267\235\357\274\232", nullptr));
        AligncomboBox->setItemText(0, QCoreApplication::translate("QG_DlgMText", "\345\267\246\345\257\271\351\275\220", nullptr));
        AligncomboBox->setItemText(1, QCoreApplication::translate("QG_DlgMText", "\344\270\255\351\227\264\345\257\271\351\275\220", nullptr));
        AligncomboBox->setItemText(2, QCoreApplication::translate("QG_DlgMText", "\345\217\263\345\257\271\351\275\220", nullptr));

        label_4->setText(QCoreApplication::translate("QG_DlgMText", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("QG_DlgMText", "\345\257\271\351\275\220\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("QG_DlgMText", "\345\255\227\351\227\264\350\267\235\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("QG_DlgMText", "Y\350\275\264\347\274\251\346\224\276\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("QG_DlgMText", "\346\211\223\345\215\260\346\226\207\346\234\254", nullptr));
        label_8->setText(QCoreApplication::translate("QG_DlgMText", "\345\237\272\345\207\206\346\227\245\346\234\237\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("QG_DlgMText", "\346\234\252\350\256\276\347\275\256", nullptr));
        buttonGroup7->setTitle(QCoreApplication::translate("QG_DlgMText", "\345\277\253\346\215\267\350\276\223\345\205\245", nullptr));
        bLoad->setText(QCoreApplication::translate("QG_DlgMText", "\346\211\223\345\274\200\346\250\241\346\235\277", nullptr));
        bClear->setText(QCoreApplication::translate("QG_DlgMText", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        bSave->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\345\255\230\346\250\241\346\235\277", nullptr));
        toolButton_5->setText(QCoreApplication::translate("QG_DlgMText", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
        toolButton_2->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\350\264\250\346\234\237\350\207\263", nullptr));
        toolButton_6->setText(QCoreApplication::translate("QG_DlgMText", "\346\215\242\350\241\214\347\254\246", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgMText", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
        toolButton_3->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\350\264\250\346\234\237\350\207\263", nullptr));
        toolButton_4->setText(QCoreApplication::translate("QG_DlgMText", "\351\200\211\346\213\251\346\227\266\351\227\264", nullptr));
        buttonGroup5->setTitle(QCoreApplication::translate("QG_DlgMText", "\346\217\222\345\205\245\347\254\246\345\217\267", nullptr));
        textLabel1_2->setText(QCoreApplication::translate("QG_DlgMText", "\345\255\227\347\254\246\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("QG_DlgMText", "\347\254\246\345\217\267\357\274\232", nullptr));
        cbSymbol->setItemText(0, QCoreApplication::translate("QG_DlgMText", "Diameter (\342\214\200)", nullptr));
        cbSymbol->setItemText(1, QCoreApplication::translate("QG_DlgMText", "Degree (\302\260)", nullptr));
        cbSymbol->setItemText(2, QCoreApplication::translate("QG_DlgMText", "Plus / Minus (\302\261)", nullptr));
        cbSymbol->setItemText(3, QCoreApplication::translate("QG_DlgMText", "At (@)", nullptr));
        cbSymbol->setItemText(4, QCoreApplication::translate("QG_DlgMText", "Hash (#)", nullptr));
        cbSymbol->setItemText(5, QCoreApplication::translate("QG_DlgMText", "Dollar ($)", nullptr));
        cbSymbol->setItemText(6, QCoreApplication::translate("QG_DlgMText", "Copyright (\302\251)", nullptr));
        cbSymbol->setItemText(7, QCoreApplication::translate("QG_DlgMText", "Registered (\302\256)", nullptr));
        cbSymbol->setItemText(8, QCoreApplication::translate("QG_DlgMText", "Paragraph (\302\247)", nullptr));
        cbSymbol->setItemText(9, QCoreApplication::translate("QG_DlgMText", "Pi (\317\200)", nullptr));
        cbSymbol->setItemText(10, QCoreApplication::translate("QG_DlgMText", "Pound (\302\243)", nullptr));
        cbSymbol->setItemText(11, QCoreApplication::translate("QG_DlgMText", "Yen (\302\245)", nullptr));
        cbSymbol->setItemText(12, QCoreApplication::translate("QG_DlgMText", "Times (\303\227)", nullptr));
        cbSymbol->setItemText(13, QCoreApplication::translate("QG_DlgMText", "Division (\303\267)", nullptr));

        textLabel1->setText(QCoreApplication::translate("QG_DlgMText", "\351\241\265\351\235\242\357\274\232", nullptr));
        cbUniPage->setItemText(0, QCoreApplication::translate("QG_DlgMText", "[0000-007F] Basic Latin", nullptr));
        cbUniPage->setItemText(1, QCoreApplication::translate("QG_DlgMText", "[0080-00FF] Latin-1 Supplementary", nullptr));
        cbUniPage->setItemText(2, QCoreApplication::translate("QG_DlgMText", "[0100-017F] Latin Extended-A", nullptr));

        bUnicode->setText(QCoreApplication::translate("QG_DlgMText", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgMText: public Ui_QG_DlgMText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGMTEXT_H
