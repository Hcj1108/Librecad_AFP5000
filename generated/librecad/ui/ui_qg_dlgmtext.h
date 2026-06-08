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
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vlAttributes;
    QGroupBox *bgFont;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *leAngle;
    QLineEdit *leLineSpacingFactor;
    QG_FontBox *cbFont;
    QLabel *label;
    QLabel *lHeight;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lewordspace;
    QComboBox *AligncomboBox;
    QLabel *lLineSpacingFactor;
    QSpacerItem *verticalSpacer;
    QLineEdit *leHeight;
    QLineEdit *lex_scale;
    QLineEdit *ley_scale;
    QCheckBox *cbDefault;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *teText;
    QHBoxLayout *hboxLayout3;
    QGroupBox *buttonGroup7;
    QGridLayout *gridLayout1;
    QToolButton *toolButton_5;
    QToolButton *toolButton;
    QToolButton *bSave;
    QToolButton *bLoad;
    QToolButton *toolButton_3;
    QToolButton *toolButton_6;
    QToolButton *bClear;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QGroupBox *buttonGroup5;
    QGridLayout *gridLayout2;
    QComboBox *cbSymbol;
    QComboBox *cbUniPage;
    QLabel *textLabel1;
    QLabel *textLabel1_2;
    QComboBox *cbUniChar;
    QLabel *label_6;
    QToolButton *bUnicode;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgMText)
    {
        if (QG_DlgMText->objectName().isEmpty())
            QG_DlgMText->setObjectName(QString::fromUtf8("QG_DlgMText"));
        QG_DlgMText->resize(770, 465);
        QG_DlgMText->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(QG_DlgMText);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        vlAttributes = new QVBoxLayout();
        vlAttributes->setSpacing(6);
        vlAttributes->setObjectName(QString::fromUtf8("vlAttributes"));

        hboxLayout1->addLayout(vlAttributes);

        bgFont = new QGroupBox(QG_DlgMText);
        bgFont->setObjectName(QString::fromUtf8("bgFont"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bgFont->sizePolicy().hasHeightForWidth());
        bgFont->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(bgFont);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(bgFont);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        label_3 = new QLabel(bgFont);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        label_2 = new QLabel(bgFont);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 6, 0, 1, 2);

        label_5 = new QLabel(bgFont);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        leAngle = new QLineEdit(bgFont);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy1);
        leAngle->setFont(font);
        leAngle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leAngle, 8, 2, 1, 1);

        leLineSpacingFactor = new QLineEdit(bgFont);
        leLineSpacingFactor->setObjectName(QString::fromUtf8("leLineSpacingFactor"));
        sizePolicy1.setHeightForWidth(leLineSpacingFactor->sizePolicy().hasHeightForWidth());
        leLineSpacingFactor->setSizePolicy(sizePolicy1);
        leLineSpacingFactor->setFont(font);
        leLineSpacingFactor->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leLineSpacingFactor, 4, 2, 1, 1);

        cbFont = new QG_FontBox(bgFont);
        cbFont->setObjectName(QString::fromUtf8("cbFont"));
        sizePolicy1.setHeightForWidth(cbFont->sizePolicy().hasHeightForWidth());
        cbFont->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cbFont, 0, 0, 1, 3);

        label = new QLabel(bgFont);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        lHeight = new QLabel(bgFont);
        lHeight->setObjectName(QString::fromUtf8("lHeight"));
        lHeight->setFont(font);
        lHeight->setWordWrap(false);

        gridLayout->addWidget(lHeight, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 12, 2, 1, 1);

        lewordspace = new QLineEdit(bgFont);
        lewordspace->setObjectName(QString::fromUtf8("lewordspace"));
        lewordspace->setFont(font);
        lewordspace->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lewordspace, 5, 2, 1, 1);

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
        AligncomboBox->setFont(font);

        gridLayout->addWidget(AligncomboBox, 9, 2, 1, 1);

        lLineSpacingFactor = new QLabel(bgFont);
        lLineSpacingFactor->setObjectName(QString::fromUtf8("lLineSpacingFactor"));
        lLineSpacingFactor->setFont(font);
        lLineSpacingFactor->setWordWrap(false);

        gridLayout->addWidget(lLineSpacingFactor, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 1);

        leHeight = new QLineEdit(bgFont);
        leHeight->setObjectName(QString::fromUtf8("leHeight"));
        sizePolicy1.setHeightForWidth(leHeight->sizePolicy().hasHeightForWidth());
        leHeight->setSizePolicy(sizePolicy1);
        leHeight->setFont(font);
        leHeight->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(leHeight, 2, 2, 1, 1);

        lex_scale = new QLineEdit(bgFont);
        lex_scale->setObjectName(QString::fromUtf8("lex_scale"));
        lex_scale->setFont(font);
        lex_scale->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lex_scale, 7, 2, 1, 1);

        ley_scale = new QLineEdit(bgFont);
        ley_scale->setObjectName(QString::fromUtf8("ley_scale"));
        ley_scale->setFont(font);
        ley_scale->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(ley_scale, 6, 2, 1, 1);

        cbDefault = new QCheckBox(bgFont);
        cbDefault->setObjectName(QString::fromUtf8("cbDefault"));
        sizePolicy1.setHeightForWidth(cbDefault->sizePolicy().hasHeightForWidth());
        cbDefault->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(9);
        font1.setBold(false);
        cbDefault->setFont(font1);

        gridLayout->addWidget(cbDefault, 1, 0, 1, 1);


        hboxLayout1->addWidget(bgFont);


        vboxLayout1->addLayout(hboxLayout1);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label_7 = new QLabel(QG_DlgMText);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font2;
        font2.setBold(true);
        label_7->setFont(font2);

        hboxLayout2->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer);

        label_8 = new QLabel(QG_DlgMText);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        hboxLayout2->addWidget(label_8);

        label_9 = new QLabel(QG_DlgMText);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        hboxLayout2->addWidget(label_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer_2);


        vboxLayout2->addLayout(hboxLayout2);

        teText = new QTextEdit(QG_DlgMText);
        teText->setObjectName(QString::fromUtf8("teText"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(true);
        teText->setFont(font3);
        teText->setProperty("linkUnderline", QVariant(false));

        vboxLayout2->addWidget(teText);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        buttonGroup7 = new QGroupBox(QG_DlgMText);
        buttonGroup7->setObjectName(QString::fromUtf8("buttonGroup7"));
        sizePolicy.setHeightForWidth(buttonGroup7->sizePolicy().hasHeightForWidth());
        buttonGroup7->setSizePolicy(sizePolicy);
        buttonGroup7->setMinimumSize(QSize(148, 0));
        gridLayout1 = new QGridLayout(buttonGroup7);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        toolButton_5 = new QToolButton(buttonGroup7);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(8);
        font4.setBold(true);
        toolButton_5->setFont(font4);
        toolButton_5->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PIC/Resources/PICs/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon3);
        toolButton_5->setIconSize(QSize(40, 40));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_5, 1, 0, 1, 1);

        toolButton = new QToolButton(buttonGroup7);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setFont(font4);
        toolButton->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/rl.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton, 2, 0, 1, 1);

        bSave = new QToolButton(buttonGroup7);
        bSave->setObjectName(QString::fromUtf8("bSave"));
        bSave->setFont(font4);
        bSave->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PNG/Resources/PNG/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        bSave->setIcon(icon5);
        bSave->setIconSize(QSize(40, 40));
        bSave->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bSave, 0, 3, 1, 1);

        bLoad = new QToolButton(buttonGroup7);
        bLoad->setObjectName(QString::fromUtf8("bLoad"));
        bLoad->setFont(font4);
        bLoad->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PNG/Resources/PNG/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        bLoad->setIcon(icon6);
        bLoad->setIconSize(QSize(40, 40));
        bLoad->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bLoad, 0, 0, 1, 1);

        toolButton_3 = new QToolButton(buttonGroup7);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setFont(font4);
        toolButton_3->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        toolButton_3->setIcon(icon4);
        toolButton_3->setIconSize(QSize(40, 40));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_3, 2, 1, 1, 1);

        toolButton_6 = new QToolButton(buttonGroup7);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setFont(font4);
        toolButton_6->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/PIC/Resources/PICs/line break.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon7);
        toolButton_6->setIconSize(QSize(40, 40));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_6, 1, 3, 1, 1);

        bClear = new QToolButton(buttonGroup7);
        bClear->setObjectName(QString::fromUtf8("bClear"));
        bClear->setFont(font4);
        bClear->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/PNG/Resources/PNG/clear .png"), QSize(), QIcon::Normal, QIcon::Off);
        bClear->setIcon(icon8);
        bClear->setIconSize(QSize(40, 40));
        bClear->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(bClear, 0, 1, 1, 1);

        toolButton_2 = new QToolButton(buttonGroup7);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setFont(font4);
        toolButton_2->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        toolButton_2->setIcon(icon3);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_2, 1, 1, 1, 1);

        toolButton_4 = new QToolButton(buttonGroup7);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setFont(font4);
        toolButton_4->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/PIC/Resources/PICs/time.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon9);
        toolButton_4->setIconSize(QSize(40, 40));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout1->addWidget(toolButton_4, 2, 3, 1, 1);


        hboxLayout3->addWidget(buttonGroup7);

        buttonGroup5 = new QGroupBox(QG_DlgMText);
        buttonGroup5->setObjectName(QString::fromUtf8("buttonGroup5"));
        gridLayout2 = new QGridLayout(buttonGroup5);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
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
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbSymbol->sizePolicy().hasHeightForWidth());
        cbSymbol->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setPointSize(10);
        cbSymbol->setFont(font5);

        gridLayout2->addWidget(cbSymbol, 0, 2, 1, 1);

        cbUniPage = new QComboBox(buttonGroup5);
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->addItem(QString());
        cbUniPage->setObjectName(QString::fromUtf8("cbUniPage"));
        sizePolicy2.setHeightForWidth(cbUniPage->sizePolicy().hasHeightForWidth());
        cbUniPage->setSizePolicy(sizePolicy2);
        cbUniPage->setMinimumSize(QSize(280, 0));
        cbUniPage->setFont(font5);

        gridLayout2->addWidget(cbUniPage, 1, 2, 1, 1);

        textLabel1 = new QLabel(buttonGroup5);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setFont(font5);
        textLabel1->setWordWrap(false);

        gridLayout2->addWidget(textLabel1, 1, 0, 1, 1);

        textLabel1_2 = new QLabel(buttonGroup5);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setFont(font5);
        textLabel1_2->setWordWrap(false);

        gridLayout2->addWidget(textLabel1_2, 2, 0, 1, 1);

        cbUniChar = new QComboBox(buttonGroup5);
        cbUniChar->setObjectName(QString::fromUtf8("cbUniChar"));
        sizePolicy2.setHeightForWidth(cbUniChar->sizePolicy().hasHeightForWidth());
        cbUniChar->setSizePolicy(sizePolicy2);
        cbUniChar->setMinimumSize(QSize(92, 0));
        cbUniChar->setFont(font5);

        gridLayout2->addWidget(cbUniChar, 2, 2, 1, 1);

        label_6 = new QLabel(buttonGroup5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font5);

        gridLayout2->addWidget(label_6, 0, 0, 1, 1);

        bUnicode = new QToolButton(buttonGroup5);
        bUnicode->setObjectName(QString::fromUtf8("bUnicode"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bUnicode->sizePolicy().hasHeightForWidth());
        bUnicode->setSizePolicy(sizePolicy3);
        bUnicode->setMinimumSize(QSize(25, 25));
        bUnicode->setMaximumSize(QSize(25, 25));

        gridLayout2->addWidget(bUnicode, 1, 3, 1, 1);


        hboxLayout3->addWidget(buttonGroup5);

        hboxLayout3->setStretch(0, 1);
        hboxLayout3->setStretch(1, 1);

        vboxLayout->addLayout(hboxLayout3);

        buttonBox = new QDialogButtonBox(QG_DlgMText);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        vboxLayout->addWidget(buttonBox);

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

        AligncomboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QG_DlgMText);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgMText)
    {
        QG_DlgMText->setWindowTitle(QCoreApplication::translate("QG_DlgMText", "MText", nullptr));
        bgFont->setTitle(QCoreApplication::translate("QG_DlgMText", "Font", nullptr));
        label_4->setText(QCoreApplication::translate("QG_DlgMText", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("QG_DlgMText", "x\350\275\264\347\274\251\346\224\276\346\257\224\344\276\213\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("QG_DlgMText", "y\350\275\264\347\274\251\346\224\276\346\257\224\344\276\213\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("QG_DlgMText", "\345\257\271\351\275\220\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("QG_DlgMText", "\345\255\227\351\227\264\350\267\235\357\274\232", nullptr));
        lHeight->setText(QCoreApplication::translate("QG_DlgMText", "&Height:", nullptr));
        lewordspace->setText(QString());
        AligncomboBox->setItemText(0, QCoreApplication::translate("QG_DlgMText", "\345\267\246\345\257\271\351\275\220", nullptr));
        AligncomboBox->setItemText(1, QCoreApplication::translate("QG_DlgMText", "\344\270\255\351\227\264\345\257\271\351\275\220", nullptr));
        AligncomboBox->setItemText(2, QCoreApplication::translate("QG_DlgMText", "\345\217\263\345\257\271\351\275\220", nullptr));

        lLineSpacingFactor->setText(QCoreApplication::translate("QG_DlgMText", "&Line spacing:", nullptr));
        ley_scale->setText(QString());
        cbDefault->setText(QCoreApplication::translate("QG_DlgMText", "&Default line spacing", nullptr));
#if QT_CONFIG(shortcut)
        cbDefault->setShortcut(QCoreApplication::translate("QG_DlgMText", "Alt+D", nullptr));
#endif // QT_CONFIG(shortcut)
        label_7->setText(QCoreApplication::translate("QG_DlgMText", "\346\211\223\345\215\260\346\226\207\346\234\254", nullptr));
        label_8->setText(QCoreApplication::translate("QG_DlgMText", "\345\237\272\345\207\206\346\227\245\346\234\237\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("QG_DlgMText", "\346\234\252\350\256\276\347\275\256", nullptr));
        teText->setHtml(QCoreApplication::translate("QG_DlgMText", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:12pt; font-weight:700; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p></body></html>", nullptr));
        buttonGroup7->setTitle(QCoreApplication::translate("QG_DlgMText", "\345\277\253\346\215\267\350\276\223\345\205\245", nullptr));
        toolButton_5->setText(QCoreApplication::translate("QG_DlgMText", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgMText", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
#if QT_CONFIG(tooltip)
        bSave->setToolTip(QCoreApplication::translate("QG_DlgMText", "Save Text To File", nullptr));
#endif // QT_CONFIG(tooltip)
        bSave->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\345\255\230\346\250\241\346\235\277", nullptr));
#if QT_CONFIG(tooltip)
        bLoad->setToolTip(QCoreApplication::translate("QG_DlgMText", "Load Text From File", nullptr));
#endif // QT_CONFIG(tooltip)
        bLoad->setText(QCoreApplication::translate("QG_DlgMText", "\346\211\223\345\274\200\346\250\241\346\235\277", nullptr));
        toolButton_3->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\350\264\250\346\234\237\350\207\263", nullptr));
        toolButton_6->setText(QCoreApplication::translate("QG_DlgMText", "\346\215\242\350\241\214\347\254\246", nullptr));
#if QT_CONFIG(tooltip)
        bClear->setToolTip(QCoreApplication::translate("QG_DlgMText", "Clear Text", nullptr));
#endif // QT_CONFIG(tooltip)
        bClear->setText(QCoreApplication::translate("QG_DlgMText", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        toolButton_2->setText(QCoreApplication::translate("QG_DlgMText", "\344\277\235\350\264\250\346\234\237\350\207\263", nullptr));
        toolButton_4->setText(QCoreApplication::translate("QG_DlgMText", "\351\200\211\346\213\251\346\227\266\351\227\264", nullptr));
        buttonGroup5->setTitle(QCoreApplication::translate("QG_DlgMText", "\346\217\222\345\205\245", nullptr));
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

        cbUniPage->setItemText(0, QCoreApplication::translate("QG_DlgMText", "[0000-007F] Basic Latin", nullptr));
        cbUniPage->setItemText(1, QCoreApplication::translate("QG_DlgMText", "[0080-00FF] Latin-1 Supplementary", nullptr));
        cbUniPage->setItemText(2, QCoreApplication::translate("QG_DlgMText", "[0100-017F] Latin Extended-A", nullptr));
        cbUniPage->setItemText(3, QCoreApplication::translate("QG_DlgMText", "[0180-024F] Latin Extended-B", nullptr));
        cbUniPage->setItemText(4, QCoreApplication::translate("QG_DlgMText", "[0250-02AF] IPA Extensions", nullptr));
        cbUniPage->setItemText(5, QCoreApplication::translate("QG_DlgMText", "[02B0-02FF] Spacing Modifier Letters", nullptr));
        cbUniPage->setItemText(6, QCoreApplication::translate("QG_DlgMText", "[0300-036F] Combining Diacritical Marks", nullptr));
        cbUniPage->setItemText(7, QCoreApplication::translate("QG_DlgMText", "[0370-03FF] Greek and Coptic", nullptr));
        cbUniPage->setItemText(8, QCoreApplication::translate("QG_DlgMText", "[0400-04FF] Cyrillic", nullptr));
        cbUniPage->setItemText(9, QCoreApplication::translate("QG_DlgMText", "[0500-052F] Cyrillic Supplementary", nullptr));
        cbUniPage->setItemText(10, QCoreApplication::translate("QG_DlgMText", "[0530-058F] Armenian", nullptr));
        cbUniPage->setItemText(11, QCoreApplication::translate("QG_DlgMText", "[0590-05FF] Hebrew", nullptr));
        cbUniPage->setItemText(12, QCoreApplication::translate("QG_DlgMText", "[0600-06FF] Arabic", nullptr));
        cbUniPage->setItemText(13, QCoreApplication::translate("QG_DlgMText", "[0700-074F] Syriac", nullptr));
        cbUniPage->setItemText(14, QCoreApplication::translate("QG_DlgMText", "[0780-07BF] Thaana", nullptr));
        cbUniPage->setItemText(15, QCoreApplication::translate("QG_DlgMText", "[0900-097F] Devanagari", nullptr));
        cbUniPage->setItemText(16, QCoreApplication::translate("QG_DlgMText", "[0980-09FF] Bengali", nullptr));
        cbUniPage->setItemText(17, QCoreApplication::translate("QG_DlgMText", "[0A00-0A7F] Gurmukhi", nullptr));
        cbUniPage->setItemText(18, QCoreApplication::translate("QG_DlgMText", "[0A80-0AFF] Gujarati", nullptr));
        cbUniPage->setItemText(19, QCoreApplication::translate("QG_DlgMText", "[0B00-0B7F] Oriya", nullptr));
        cbUniPage->setItemText(20, QCoreApplication::translate("QG_DlgMText", "[0B80-0BFF] Tamil", nullptr));
        cbUniPage->setItemText(21, QCoreApplication::translate("QG_DlgMText", "[0C00-0C7F] Telugu", nullptr));
        cbUniPage->setItemText(22, QCoreApplication::translate("QG_DlgMText", "[0C80-0CFF] Kannada", nullptr));
        cbUniPage->setItemText(23, QCoreApplication::translate("QG_DlgMText", "[0D00-0D7F] Malayalam", nullptr));
        cbUniPage->setItemText(24, QCoreApplication::translate("QG_DlgMText", "[0D80-0DFF] Sinhala", nullptr));
        cbUniPage->setItemText(25, QCoreApplication::translate("QG_DlgMText", "[0E00-0E7F] Thai", nullptr));
        cbUniPage->setItemText(26, QCoreApplication::translate("QG_DlgMText", "[0E80-0EFF] Lao", nullptr));
        cbUniPage->setItemText(27, QCoreApplication::translate("QG_DlgMText", "[0F00-0FFF] Tibetan", nullptr));
        cbUniPage->setItemText(28, QCoreApplication::translate("QG_DlgMText", "[1000-109F] Myanmar", nullptr));
        cbUniPage->setItemText(29, QCoreApplication::translate("QG_DlgMText", "[10A0-10FF] Georgian", nullptr));
        cbUniPage->setItemText(30, QCoreApplication::translate("QG_DlgMText", "[1100-11FF] Hangul Jamo", nullptr));
        cbUniPage->setItemText(31, QCoreApplication::translate("QG_DlgMText", "[1200-137F] Ethiopic", nullptr));
        cbUniPage->setItemText(32, QCoreApplication::translate("QG_DlgMText", "[13A0-13FF] Cherokee", nullptr));
        cbUniPage->setItemText(33, QCoreApplication::translate("QG_DlgMText", "[1400-167F] Unified Canadian Aboriginal Syllabic", nullptr));
        cbUniPage->setItemText(34, QCoreApplication::translate("QG_DlgMText", "[1680-169F] Ogham", nullptr));
        cbUniPage->setItemText(35, QCoreApplication::translate("QG_DlgMText", "[16A0-16FF] Runic", nullptr));
        cbUniPage->setItemText(36, QCoreApplication::translate("QG_DlgMText", "[1700-171F] Tagalog", nullptr));
        cbUniPage->setItemText(37, QCoreApplication::translate("QG_DlgMText", "[1720-173F] Hanunoo", nullptr));
        cbUniPage->setItemText(38, QCoreApplication::translate("QG_DlgMText", "[1740-175F] Buhid", nullptr));
        cbUniPage->setItemText(39, QCoreApplication::translate("QG_DlgMText", "[1760-177F] Tagbanwa", nullptr));
        cbUniPage->setItemText(40, QCoreApplication::translate("QG_DlgMText", "[1780-17FF] Khmer", nullptr));
        cbUniPage->setItemText(41, QCoreApplication::translate("QG_DlgMText", "[1800-18AF] Mongolian", nullptr));
        cbUniPage->setItemText(42, QCoreApplication::translate("QG_DlgMText", "[1E00-1EFF] Latin Extended Additional", nullptr));
        cbUniPage->setItemText(43, QCoreApplication::translate("QG_DlgMText", "[1F00-1FFF] Greek Extended", nullptr));
        cbUniPage->setItemText(44, QCoreApplication::translate("QG_DlgMText", "[2000-206F] General Punctuation", nullptr));
        cbUniPage->setItemText(45, QCoreApplication::translate("QG_DlgMText", "[2070-209F] Superscripts and Subscripts", nullptr));
        cbUniPage->setItemText(46, QCoreApplication::translate("QG_DlgMText", "[20A0-20CF] Currency Symbols", nullptr));
        cbUniPage->setItemText(47, QCoreApplication::translate("QG_DlgMText", "[20D0-20FF] Combining Marks for Symbols", nullptr));
        cbUniPage->setItemText(48, QCoreApplication::translate("QG_DlgMText", "[2100-214F] Letterlike Symbols", nullptr));
        cbUniPage->setItemText(49, QCoreApplication::translate("QG_DlgMText", "[2150-218F] Number Forms", nullptr));
        cbUniPage->setItemText(50, QCoreApplication::translate("QG_DlgMText", "[2190-21FF] Arrows", nullptr));
        cbUniPage->setItemText(51, QCoreApplication::translate("QG_DlgMText", "[2200-22FF] Mathematical Operators", nullptr));
        cbUniPage->setItemText(52, QCoreApplication::translate("QG_DlgMText", "[2300-23FF] Miscellaneous Technical", nullptr));
        cbUniPage->setItemText(53, QCoreApplication::translate("QG_DlgMText", "[2400-243F] Control Pictures", nullptr));
        cbUniPage->setItemText(54, QCoreApplication::translate("QG_DlgMText", "[2440-245F] Optical Character Recognition", nullptr));
        cbUniPage->setItemText(55, QCoreApplication::translate("QG_DlgMText", "[2460-24FF] Enclosed Alphanumerics", nullptr));
        cbUniPage->setItemText(56, QCoreApplication::translate("QG_DlgMText", "[2500-257F] Box Drawing", nullptr));
        cbUniPage->setItemText(57, QCoreApplication::translate("QG_DlgMText", "[2580-259F] Block Elements", nullptr));
        cbUniPage->setItemText(58, QCoreApplication::translate("QG_DlgMText", "[25A0-25FF] Geometric Shapes", nullptr));
        cbUniPage->setItemText(59, QCoreApplication::translate("QG_DlgMText", "[2600-26FF] Miscellaneous Symbols", nullptr));
        cbUniPage->setItemText(60, QCoreApplication::translate("QG_DlgMText", "[2700-27BF] Dingbats", nullptr));
        cbUniPage->setItemText(61, QCoreApplication::translate("QG_DlgMText", "[27C0-27EF] Miscellaneous Mathematical Symbols-A", nullptr));
        cbUniPage->setItemText(62, QCoreApplication::translate("QG_DlgMText", "[27F0-27FF] Supplemental Arrows-A", nullptr));
        cbUniPage->setItemText(63, QCoreApplication::translate("QG_DlgMText", "[2800-28FF] Braille Patterns", nullptr));
        cbUniPage->setItemText(64, QCoreApplication::translate("QG_DlgMText", "[2900-297F] Supplemental Arrows-B", nullptr));
        cbUniPage->setItemText(65, QCoreApplication::translate("QG_DlgMText", "[2980-29FF] Miscellaneous Mathematical Symbols-B", nullptr));
        cbUniPage->setItemText(66, QCoreApplication::translate("QG_DlgMText", "[2A00-2AFF] Supplemental Mathematical Operators", nullptr));
        cbUniPage->setItemText(67, QCoreApplication::translate("QG_DlgMText", "[2E80-2EFF] CJK Radicals Supplement", nullptr));
        cbUniPage->setItemText(68, QCoreApplication::translate("QG_DlgMText", "[2F00-2FDF] Kangxi Radicals", nullptr));
        cbUniPage->setItemText(69, QCoreApplication::translate("QG_DlgMText", "[2FF0-2FFF] Ideographic Description Characters", nullptr));
        cbUniPage->setItemText(70, QCoreApplication::translate("QG_DlgMText", "[3000-303F] CJK Symbols and Punctuation", nullptr));
        cbUniPage->setItemText(71, QCoreApplication::translate("QG_DlgMText", "[3040-309F] Hiragana", nullptr));
        cbUniPage->setItemText(72, QCoreApplication::translate("QG_DlgMText", "[30A0-30FF] Katakana", nullptr));
        cbUniPage->setItemText(73, QCoreApplication::translate("QG_DlgMText", "[3100-312F] Bopomofo", nullptr));
        cbUniPage->setItemText(74, QCoreApplication::translate("QG_DlgMText", "[3130-318F] Hangul Compatibility Jamo", nullptr));
        cbUniPage->setItemText(75, QCoreApplication::translate("QG_DlgMText", "[3190-319F] Kanbun", nullptr));
        cbUniPage->setItemText(76, QCoreApplication::translate("QG_DlgMText", "[31A0-31BF] Bopomofo Extended", nullptr));
        cbUniPage->setItemText(77, QCoreApplication::translate("QG_DlgMText", "[3200-32FF] Enclosed CJK Letters and Months", nullptr));
        cbUniPage->setItemText(78, QCoreApplication::translate("QG_DlgMText", "[3300-33FF] CJK Compatibility", nullptr));
        cbUniPage->setItemText(79, QCoreApplication::translate("QG_DlgMText", "[3400-4DBF] CJK Unified Ideographs Extension A", nullptr));
        cbUniPage->setItemText(80, QCoreApplication::translate("QG_DlgMText", "[4E00-9FAF] CJK Unified Ideographs", nullptr));
        cbUniPage->setItemText(81, QCoreApplication::translate("QG_DlgMText", "[A000-A48F] Yi Syllables", nullptr));
        cbUniPage->setItemText(82, QCoreApplication::translate("QG_DlgMText", "[A490-A4CF] Yi Radicals", nullptr));
        cbUniPage->setItemText(83, QCoreApplication::translate("QG_DlgMText", "[AC00-D7AF] Hangul Syllables", nullptr));
        cbUniPage->setItemText(84, QCoreApplication::translate("QG_DlgMText", "[D800-DBFF] High Surrogates", nullptr));
        cbUniPage->setItemText(85, QCoreApplication::translate("QG_DlgMText", "[DC00-DFFF] Low Surrogate Area", nullptr));
        cbUniPage->setItemText(86, QCoreApplication::translate("QG_DlgMText", "[E000-F8FF] Private Use Area", nullptr));
        cbUniPage->setItemText(87, QCoreApplication::translate("QG_DlgMText", "[F900-FAFF] CJK Compatibility Ideographs", nullptr));
        cbUniPage->setItemText(88, QCoreApplication::translate("QG_DlgMText", "[FB00-FB4F] Alphabetic Presentation Forms", nullptr));
        cbUniPage->setItemText(89, QCoreApplication::translate("QG_DlgMText", "[FB50-FDFF] Arabic Presentation Forms-A", nullptr));
        cbUniPage->setItemText(90, QCoreApplication::translate("QG_DlgMText", "[FE00-FE0F] Variation Selectors", nullptr));
        cbUniPage->setItemText(91, QCoreApplication::translate("QG_DlgMText", "[FE20-FE2F] Combining Half Marks", nullptr));
        cbUniPage->setItemText(92, QCoreApplication::translate("QG_DlgMText", "[FE30-FE4F] CJK Compatibility Forms", nullptr));
        cbUniPage->setItemText(93, QCoreApplication::translate("QG_DlgMText", "[FE50-FE6F] Small Form Variants", nullptr));
        cbUniPage->setItemText(94, QCoreApplication::translate("QG_DlgMText", "[FE70-FEFF] Arabic Presentation Forms-B", nullptr));
        cbUniPage->setItemText(95, QCoreApplication::translate("QG_DlgMText", "[FF00-FFEF] Halfwidth and Fullwidth Forms", nullptr));
        cbUniPage->setItemText(96, QCoreApplication::translate("QG_DlgMText", "[FFF0-FFFF] Specials", nullptr));
        cbUniPage->setItemText(97, QCoreApplication::translate("QG_DlgMText", "[10300-1032F] Old Italic", nullptr));
        cbUniPage->setItemText(98, QCoreApplication::translate("QG_DlgMText", "[10330-1034F] Gothic", nullptr));
        cbUniPage->setItemText(99, QCoreApplication::translate("QG_DlgMText", "[10400-1044F] Deseret", nullptr));
        cbUniPage->setItemText(100, QCoreApplication::translate("QG_DlgMText", "[1D000-1D0FF] Byzantine Musical Symbols", nullptr));
        cbUniPage->setItemText(101, QCoreApplication::translate("QG_DlgMText", "[1D100-1D1FF] Musical Symbols", nullptr));
        cbUniPage->setItemText(102, QCoreApplication::translate("QG_DlgMText", "[1D400-1D7FF] Mathematical Alphanumeric Symbols", nullptr));
        cbUniPage->setItemText(103, QCoreApplication::translate("QG_DlgMText", "[20000-2A6DF] CJK Unified Ideographs Extension B", nullptr));
        cbUniPage->setItemText(104, QCoreApplication::translate("QG_DlgMText", "[2F800-2FA1F] CJK Compatibility Ideographs Supplement", nullptr));
        cbUniPage->setItemText(105, QCoreApplication::translate("QG_DlgMText", "[E0000-E007F] Tags", nullptr));
        cbUniPage->setItemText(106, QCoreApplication::translate("QG_DlgMText", "[F0000-FFFFD] Supplementary Private Use Area-A", nullptr));
        cbUniPage->setItemText(107, QCoreApplication::translate("QG_DlgMText", "[100000-10FFFD] Supplementary Private Use Area-B", nullptr));

        textLabel1->setText(QCoreApplication::translate("QG_DlgMText", "Page:", nullptr));
        textLabel1_2->setText(QCoreApplication::translate("QG_DlgMText", "Char:", nullptr));
        label_6->setText(QCoreApplication::translate("QG_DlgMText", "\347\254\246\345\217\267", nullptr));
        bUnicode->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_DlgMText: public Ui_QG_DlgMText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGMTEXT_H
