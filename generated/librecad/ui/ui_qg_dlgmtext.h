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
    QToolButton *toolButton_3;
    QToolButton *toolButton;
    QToolButton *bSave;
    QToolButton *bClear;
    QToolButton *toolButton_4;
    QToolButton *toolButton_7;
    QToolButton *toolButton_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgMText)
    {
        if (QG_DlgMText->objectName().isEmpty())
            QG_DlgMText->setObjectName(QString::fromUtf8("QG_DlgMText"));
        QG_DlgMText->resize(610, 562);
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

        gridLayout1->addWidget(bLoad, 1, 0, 1, 1);

        toolButton_3 = new QToolButton(buttonGroup7);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(99, 46));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/rl.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon4);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_3, 2, 4, 1, 1);

        toolButton = new QToolButton(buttonGroup7);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(99, 46));
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton, 1, 4, 1, 1);

        bSave = new QToolButton(buttonGroup7);
        bSave->setObjectName(QString::fromUtf8("bSave"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PNG/Resources/PNG/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        bSave->setIcon(icon5);
        bSave->setIconSize(QSize(32, 32));
        bSave->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bSave, 3, 0, 1, 1);

        bClear = new QToolButton(buttonGroup7);
        bClear->setObjectName(QString::fromUtf8("bClear"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PNG/Resources/PNG/clear .png"), QSize(), QIcon::Normal, QIcon::Off);
        bClear->setIcon(icon6);
        bClear->setIconSize(QSize(32, 32));
        bClear->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bClear, 2, 0, 1, 1);

        toolButton_4 = new QToolButton(buttonGroup7);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(99, 46));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/PIC/Resources/PICs/time.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon7);
        toolButton_4->setIconSize(QSize(32, 32));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_4, 3, 4, 1, 1);

        toolButton_7 = new QToolButton(buttonGroup7);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setMaximumSize(QSize(99, 16777215));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/PIC/Resources/PICs/PFGL.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon8);
        toolButton_7->setIconSize(QSize(32, 32));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_7, 1, 5, 1, 1);

        toolButton_6 = new QToolButton(buttonGroup7);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(99, 46));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/PIC/Resources/PICs/line break.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon9);
        toolButton_6->setIconSize(QSize(32, 32));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_6, 2, 5, 1, 1);


        bottomRow->addWidget(buttonGroup7);

        bottomRow->setStretch(0, 7);

        mainLayout->addLayout(bottomRow);

        buttonBox = new QDialogButtonBox(QG_DlgMText);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 0));
        buttonBox->setMaximumSize(QSize(16777215, 16777215));
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; padding: 1px 20px; border-radius: 6px; min-width: 50px;}\n"
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
        QObject::connect(cbDefault, SIGNAL(toggled(bool)), leLineSpacingFactor, SLOT(setDisabled(bool)));
        QObject::connect(cbDefault, SIGNAL(toggled(bool)), QG_DlgMText, SLOT(defaultChanged(bool)));
        QObject::connect(toolButton_4, SIGNAL(clicked()), QG_DlgMText, SLOT(setQuickTime()));
        QObject::connect(toolButton_3, SIGNAL(clicked()), QG_DlgMText, SLOT(setEXPDate()));
        QObject::connect(toolButton, SIGNAL(clicked()), QG_DlgMText, SLOT(setMFGDate()));
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
        toolButton_3->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\350\264\250\346\234\237\350\207\263", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgMText", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
        bSave->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\345\255\230\346\250\241\346\235\277", nullptr));
        bClear->setText(QCoreApplication::translate("QG_DlgMText", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        toolButton_4->setText(QCoreApplication::translate("QG_DlgMText", "\351\200\211\346\213\251\346\227\266\351\227\264", nullptr));
        toolButton_7->setText(QCoreApplication::translate("QG_DlgMText", "\345\272\217\345\210\227\345\217\267", nullptr));
        toolButton_6->setText(QCoreApplication::translate("QG_DlgMText", "\346\215\242\350\241\214\347\254\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgMText: public Ui_QG_DlgMText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGMTEXT_H
