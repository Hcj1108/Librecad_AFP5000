/********************************************************************************
** Form generated from reading UI file 'qg_dlgtext.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGTEXT_H
#define UI_QG_DLGTEXT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "qg_fontbox.h"
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgText
{
public:
    QVBoxLayout *vboxLayout;
    QVBoxLayout *_4;
    QHBoxLayout *hboxLayout;
    QLabel *lText;
    QSpacerItem *spacer4;
    QToolButton *bClear;
    QToolButton *bLoad;
    QToolButton *bSave;
    QToolButton *bCut;
    QToolButton *bCopy;
    QToolButton *bPaste;
    QLineEdit *teText;
    QHBoxLayout *_5;
    QVBoxLayout *vlAttributes;
    QHBoxLayout *hboxLayout1;
    QLabel *lLayer;
    QG_LayerBox *cbLayer;
    QG_WidgetPen *wPen;
    QGroupBox *bgFont;
    QGridLayout *gridLayout;
    QLineEdit *leWidthRel;
    QLineEdit *leAngle;
    QLabel *lHeight;
    QLabel *lAngle;
    QSpacerItem *spacer2;
    QLineEdit *leHeight;
    QSpacerItem *spacer2_2;
    QLabel *lOblique;
    QLineEdit *leOblique;
    QLabel *lWidthFactor;
    QLabel *lFont;
    QG_FontBox *cbFont;
    QHBoxLayout *horizontalLayout;
    QGroupBox *bgAlignment;
    QGridLayout *gridLayout1;
    QToolButton *bBC;
    QToolButton *bBR;
    QToolButton *bMR;
    QToolButton *bBL;
    QToolButton *bML;
    QToolButton *bLL;
    QToolButton *bTC;
    QToolButton *bLR;
    QToolButton *bLC;
    QToolButton *bTL;
    QToolButton *bTR;
    QToolButton *bMC;
    QRadioButton *rbFit;
    QRadioButton *rbAligned;
    QRadioButton *rbMiddle;
    QHBoxLayout *_2;
    QGroupBox *buttonGroup7;
    QVBoxLayout *vboxLayout1;
    QComboBox *cbSymbol;
    QGroupBox *buttonGroup5;
    QGridLayout *gridLayout2;
    QLabel *textLabel1;
    QLabel *textLabel1_2;
    QComboBox *cbUniPage;
    QComboBox *cbUniChar;
    QToolButton *bUnicode;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgText)
    {
        if (QG_DlgText->objectName().isEmpty())
            QG_DlgText->setObjectName(QString::fromUtf8("QG_DlgText"));
        QG_DlgText->resize(548, 441);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgText->sizePolicy().hasHeightForWidth());
        QG_DlgText->setSizePolicy(sizePolicy);
        QG_DlgText->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(QG_DlgText);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        _4 = new QVBoxLayout();
        _4->setSpacing(6);
        _4->setObjectName(QString::fromUtf8("_4"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lText = new QLabel(QG_DlgText);
        lText->setObjectName(QString::fromUtf8("lText"));
        lText->setWordWrap(false);

        hboxLayout->addWidget(lText);

        spacer4 = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer4);

        bClear = new QToolButton(QG_DlgText);
        bClear->setObjectName(QString::fromUtf8("bClear"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/new.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bClear->setIcon(icon);

        hboxLayout->addWidget(bClear);

        bLoad = new QToolButton(QG_DlgText);
        bLoad->setObjectName(QString::fromUtf8("bLoad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bLoad->setIcon(icon1);

        hboxLayout->addWidget(bLoad);

        bSave = new QToolButton(QG_DlgText);
        bSave->setObjectName(QString::fromUtf8("bSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bSave->setIcon(icon2);

        hboxLayout->addWidget(bSave);

        bCut = new QToolButton(QG_DlgText);
        bCut->setObjectName(QString::fromUtf8("bCut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/cut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bCut->setIcon(icon3);

        hboxLayout->addWidget(bCut);

        bCopy = new QToolButton(QG_DlgText);
        bCopy->setObjectName(QString::fromUtf8("bCopy"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bCopy->setIcon(icon4);

        hboxLayout->addWidget(bCopy);

        bPaste = new QToolButton(QG_DlgText);
        bPaste->setObjectName(QString::fromUtf8("bPaste"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/paste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bPaste->setIcon(icon5);

        hboxLayout->addWidget(bPaste);


        _4->addLayout(hboxLayout);

        teText = new QLineEdit(QG_DlgText);
        teText->setObjectName(QString::fromUtf8("teText"));
        teText->setProperty("linkUnderline", QVariant(false));

        _4->addWidget(teText);


        vboxLayout->addLayout(_4);

        _5 = new QHBoxLayout();
        _5->setSpacing(6);
        _5->setObjectName(QString::fromUtf8("_5"));
        _5->setSizeConstraint(QLayout::SetMinimumSize);
        vlAttributes = new QVBoxLayout();
        vlAttributes->setSpacing(6);
        vlAttributes->setObjectName(QString::fromUtf8("vlAttributes"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        lLayer = new QLabel(QG_DlgText);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        sizePolicy.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgText);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vlAttributes->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgText);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy1);

        vlAttributes->addWidget(wPen);


        _5->addLayout(vlAttributes);

        bgFont = new QGroupBox(QG_DlgText);
        bgFont->setObjectName(QString::fromUtf8("bgFont"));
        sizePolicy.setHeightForWidth(bgFont->sizePolicy().hasHeightForWidth());
        bgFont->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(bgFont);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leWidthRel = new QLineEdit(bgFont);
        leWidthRel->setObjectName(QString::fromUtf8("leWidthRel"));

        gridLayout->addWidget(leWidthRel, 5, 2, 1, 1);

        leAngle = new QLineEdit(bgFont);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(leAngle, 3, 2, 1, 1);

        lHeight = new QLabel(bgFont);
        lHeight->setObjectName(QString::fromUtf8("lHeight"));
        lHeight->setWordWrap(false);

        gridLayout->addWidget(lHeight, 2, 1, 1, 1);

        lAngle = new QLabel(bgFont);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));

        gridLayout->addWidget(lAngle, 3, 1, 1, 1);

        spacer2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer2, 6, 1, 1, 1);

        leHeight = new QLineEdit(bgFont);
        leHeight->setObjectName(QString::fromUtf8("leHeight"));
        sizePolicy2.setHeightForWidth(leHeight->sizePolicy().hasHeightForWidth());
        leHeight->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(leHeight, 2, 2, 1, 1);

        spacer2_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer2_2, 6, 2, 1, 1);

        lOblique = new QLabel(bgFont);
        lOblique->setObjectName(QString::fromUtf8("lOblique"));

        gridLayout->addWidget(lOblique, 4, 1, 1, 1);

        leOblique = new QLineEdit(bgFont);
        leOblique->setObjectName(QString::fromUtf8("leOblique"));

        gridLayout->addWidget(leOblique, 4, 2, 1, 1);

        lWidthFactor = new QLabel(bgFont);
        lWidthFactor->setObjectName(QString::fromUtf8("lWidthFactor"));

        gridLayout->addWidget(lWidthFactor, 5, 1, 1, 1);

        lFont = new QLabel(bgFont);
        lFont->setObjectName(QString::fromUtf8("lFont"));

        gridLayout->addWidget(lFont, 1, 1, 1, 1);

        cbFont = new QG_FontBox(bgFont);
        cbFont->setObjectName(QString::fromUtf8("cbFont"));
        sizePolicy2.setHeightForWidth(cbFont->sizePolicy().hasHeightForWidth());
        cbFont->setSizePolicy(sizePolicy2);
        cbFont->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(cbFont, 1, 2, 1, 1);


        _5->addWidget(bgFont);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        bgAlignment = new QGroupBox(QG_DlgText);
        bgAlignment->setObjectName(QString::fromUtf8("bgAlignment"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bgAlignment->sizePolicy().hasHeightForWidth());
        bgAlignment->setSizePolicy(sizePolicy3);
        gridLayout1 = new QGridLayout(bgAlignment);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        bBC = new QToolButton(bgAlignment);
        bBC->setObjectName(QString::fromUtf8("bBC"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(bBC->sizePolicy().hasHeightForWidth());
        bBC->setSizePolicy(sizePolicy4);
        bBC->setMinimumSize(QSize(25, 25));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/text_align_bottomcenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bBC->setIcon(icon6);
        bBC->setIconSize(QSize(20, 20));
        bBC->setCheckable(true);

        gridLayout1->addWidget(bBC, 3, 1, 1, 1);

        bBR = new QToolButton(bgAlignment);
        bBR->setObjectName(QString::fromUtf8("bBR"));
        sizePolicy4.setHeightForWidth(bBR->sizePolicy().hasHeightForWidth());
        bBR->setSizePolicy(sizePolicy4);
        bBR->setMinimumSize(QSize(25, 25));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/text_align_bottomright.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bBR->setIcon(icon7);
        bBR->setIconSize(QSize(20, 20));
        bBR->setCheckable(true);

        gridLayout1->addWidget(bBR, 3, 2, 1, 1);

        bMR = new QToolButton(bgAlignment);
        bMR->setObjectName(QString::fromUtf8("bMR"));
        sizePolicy4.setHeightForWidth(bMR->sizePolicy().hasHeightForWidth());
        bMR->setSizePolicy(sizePolicy4);
        bMR->setMinimumSize(QSize(25, 25));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/text_align_middleright.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bMR->setIcon(icon8);
        bMR->setIconSize(QSize(20, 20));
        bMR->setCheckable(true);

        gridLayout1->addWidget(bMR, 1, 2, 1, 1);

        bBL = new QToolButton(bgAlignment);
        bBL->setObjectName(QString::fromUtf8("bBL"));
        sizePolicy4.setHeightForWidth(bBL->sizePolicy().hasHeightForWidth());
        bBL->setSizePolicy(sizePolicy4);
        bBL->setMinimumSize(QSize(25, 25));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/text_align_bottomleft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bBL->setIcon(icon9);
        bBL->setIconSize(QSize(20, 20));
        bBL->setCheckable(true);

        gridLayout1->addWidget(bBL, 3, 0, 1, 1);

        bML = new QToolButton(bgAlignment);
        bML->setObjectName(QString::fromUtf8("bML"));
        sizePolicy4.setHeightForWidth(bML->sizePolicy().hasHeightForWidth());
        bML->setSizePolicy(sizePolicy4);
        bML->setMinimumSize(QSize(25, 25));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/text_align_middleleft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bML->setIcon(icon10);
        bML->setIconSize(QSize(20, 20));
        bML->setCheckable(true);

        gridLayout1->addWidget(bML, 1, 0, 1, 1);

        bLL = new QToolButton(bgAlignment);
        bLL->setObjectName(QString::fromUtf8("bLL"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/text_align_baselineleft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bLL->setIcon(icon11);
        bLL->setIconSize(QSize(20, 20));
        bLL->setCheckable(true);

        gridLayout1->addWidget(bLL, 2, 0, 1, 1);

        bTC = new QToolButton(bgAlignment);
        bTC->setObjectName(QString::fromUtf8("bTC"));
        sizePolicy4.setHeightForWidth(bTC->sizePolicy().hasHeightForWidth());
        bTC->setSizePolicy(sizePolicy4);
        bTC->setMinimumSize(QSize(25, 25));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/text_align_topcenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bTC->setIcon(icon12);
        bTC->setIconSize(QSize(20, 20));
        bTC->setCheckable(true);

        gridLayout1->addWidget(bTC, 0, 1, 1, 1);

        bLR = new QToolButton(bgAlignment);
        bLR->setObjectName(QString::fromUtf8("bLR"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/text_align_baselineright.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bLR->setIcon(icon13);
        bLR->setIconSize(QSize(20, 20));
        bLR->setCheckable(true);

        gridLayout1->addWidget(bLR, 2, 2, 1, 1);

        bLC = new QToolButton(bgAlignment);
        bLC->setObjectName(QString::fromUtf8("bLC"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/text_align_baselinecenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bLC->setIcon(icon14);
        bLC->setIconSize(QSize(20, 20));
        bLC->setCheckable(true);

        gridLayout1->addWidget(bLC, 2, 1, 1, 1);

        bTL = new QToolButton(bgAlignment);
        bTL->setObjectName(QString::fromUtf8("bTL"));
        sizePolicy4.setHeightForWidth(bTL->sizePolicy().hasHeightForWidth());
        bTL->setSizePolicy(sizePolicy4);
        bTL->setMinimumSize(QSize(25, 25));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/text_align_topleft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bTL->setIcon(icon15);
        bTL->setIconSize(QSize(20, 20));
        bTL->setCheckable(true);

        gridLayout1->addWidget(bTL, 0, 0, 1, 1);

        bTR = new QToolButton(bgAlignment);
        bTR->setObjectName(QString::fromUtf8("bTR"));
        sizePolicy4.setHeightForWidth(bTR->sizePolicy().hasHeightForWidth());
        bTR->setSizePolicy(sizePolicy4);
        bTR->setMinimumSize(QSize(25, 25));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/text_align_topright.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bTR->setIcon(icon16);
        bTR->setIconSize(QSize(20, 20));
        bTR->setCheckable(true);

        gridLayout1->addWidget(bTR, 0, 2, 1, 1);

        bMC = new QToolButton(bgAlignment);
        bMC->setObjectName(QString::fromUtf8("bMC"));
        sizePolicy4.setHeightForWidth(bMC->sizePolicy().hasHeightForWidth());
        bMC->setSizePolicy(sizePolicy4);
        bMC->setMinimumSize(QSize(25, 25));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/text_align_middlecenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bMC->setIcon(icon17);
        bMC->setIconSize(QSize(20, 20));
        bMC->setCheckable(true);

        gridLayout1->addWidget(bMC, 1, 1, 1, 1);

        rbFit = new QRadioButton(bgAlignment);
        rbFit->setObjectName(QString::fromUtf8("rbFit"));
        rbFit->setAutoExclusive(false);

        gridLayout1->addWidget(rbFit, 0, 3, 1, 1);

        rbAligned = new QRadioButton(bgAlignment);
        rbAligned->setObjectName(QString::fromUtf8("rbAligned"));
        rbAligned->setAutoExclusive(false);

        gridLayout1->addWidget(rbAligned, 1, 3, 1, 1);

        rbMiddle = new QRadioButton(bgAlignment);
        rbMiddle->setObjectName(QString::fromUtf8("rbMiddle"));
        rbMiddle->setAutoExclusive(false);

        gridLayout1->addWidget(rbMiddle, 2, 3, 1, 1);


        horizontalLayout->addWidget(bgAlignment);


        _5->addLayout(horizontalLayout);


        vboxLayout->addLayout(_5);

        _2 = new QHBoxLayout();
        _2->setSpacing(6);
        _2->setObjectName(QString::fromUtf8("_2"));
        buttonGroup7 = new QGroupBox(QG_DlgText);
        buttonGroup7->setObjectName(QString::fromUtf8("buttonGroup7"));
        sizePolicy.setHeightForWidth(buttonGroup7->sizePolicy().hasHeightForWidth());
        buttonGroup7->setSizePolicy(sizePolicy);
        buttonGroup7->setMinimumSize(QSize(148, 0));
        vboxLayout1 = new QVBoxLayout(buttonGroup7);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        cbSymbol = new QComboBox(buttonGroup7);
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
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(cbSymbol->sizePolicy().hasHeightForWidth());
        cbSymbol->setSizePolicy(sizePolicy5);

        vboxLayout1->addWidget(cbSymbol);


        _2->addWidget(buttonGroup7);

        buttonGroup5 = new QGroupBox(QG_DlgText);
        buttonGroup5->setObjectName(QString::fromUtf8("buttonGroup5"));
        gridLayout2 = new QGridLayout(buttonGroup5);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        textLabel1 = new QLabel(buttonGroup5);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        gridLayout2->addWidget(textLabel1, 0, 0, 1, 1);

        textLabel1_2 = new QLabel(buttonGroup5);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setWordWrap(false);

        gridLayout2->addWidget(textLabel1_2, 1, 0, 1, 1);

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
        sizePolicy5.setHeightForWidth(cbUniPage->sizePolicy().hasHeightForWidth());
        cbUniPage->setSizePolicy(sizePolicy5);
        cbUniPage->setMinimumSize(QSize(280, 0));

        gridLayout2->addWidget(cbUniPage, 0, 1, 1, 1);

        cbUniChar = new QComboBox(buttonGroup5);
        cbUniChar->setObjectName(QString::fromUtf8("cbUniChar"));
        sizePolicy5.setHeightForWidth(cbUniChar->sizePolicy().hasHeightForWidth());
        cbUniChar->setSizePolicy(sizePolicy5);
        cbUniChar->setMinimumSize(QSize(92, 0));

        gridLayout2->addWidget(cbUniChar, 1, 1, 1, 1);

        bUnicode = new QToolButton(buttonGroup5);
        bUnicode->setObjectName(QString::fromUtf8("bUnicode"));
        sizePolicy4.setHeightForWidth(bUnicode->sizePolicy().hasHeightForWidth());
        bUnicode->setSizePolicy(sizePolicy4);
        bUnicode->setMinimumSize(QSize(25, 25));
        bUnicode->setMaximumSize(QSize(25, 25));

        gridLayout2->addWidget(bUnicode, 0, 2, 1, 1);


        _2->addWidget(buttonGroup5);


        vboxLayout->addLayout(_2);

        buttonBox = new QDialogButtonBox(QG_DlgText);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        lHeight->setBuddy(leHeight);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(buttonBox, bClear);
        QWidget::setTabOrder(bClear, bLoad);
        QWidget::setTabOrder(bLoad, bSave);
        QWidget::setTabOrder(bSave, bCut);
        QWidget::setTabOrder(bCut, bCopy);
        QWidget::setTabOrder(bCopy, bPaste);
        QWidget::setTabOrder(bPaste, teText);
        QWidget::setTabOrder(teText, leHeight);
        QWidget::setTabOrder(leHeight, leAngle);
        QWidget::setTabOrder(leAngle, leOblique);
        QWidget::setTabOrder(leOblique, leWidthRel);
        QWidget::setTabOrder(leWidthRel, bTL);
        QWidget::setTabOrder(bTL, bTC);
        QWidget::setTabOrder(bTC, bTR);
        QWidget::setTabOrder(bTR, bML);
        QWidget::setTabOrder(bML, bMC);
        QWidget::setTabOrder(bMC, bMR);
        QWidget::setTabOrder(bMR, bLL);
        QWidget::setTabOrder(bLL, bLC);
        QWidget::setTabOrder(bLC, bLR);
        QWidget::setTabOrder(bLR, bBL);
        QWidget::setTabOrder(bBL, bBC);
        QWidget::setTabOrder(bBC, bBR);
        QWidget::setTabOrder(bBR, rbFit);
        QWidget::setTabOrder(rbFit, rbAligned);
        QWidget::setTabOrder(rbAligned, rbMiddle);
        QWidget::setTabOrder(rbMiddle, cbSymbol);
        QWidget::setTabOrder(cbSymbol, cbUniPage);
        QWidget::setTabOrder(cbUniPage, cbUniChar);
        QWidget::setTabOrder(cbUniChar, bUnicode);

        retranslateUi(QG_DlgText);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgText, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgText, SLOT(reject()));
        QObject::connect(cbUniPage, SIGNAL(activated(int)), QG_DlgText, SLOT(updateUniCharComboBox(int)));
        QObject::connect(bUnicode, SIGNAL(clicked()), QG_DlgText, SLOT(insertChar()));
        QObject::connect(cbUniPage, SIGNAL(activated(int)), QG_DlgText, SLOT(updateUniCharButton(int)));
        QObject::connect(cbUniChar, SIGNAL(activated(int)), QG_DlgText, SLOT(updateUniCharButton(int)));
        QObject::connect(cbSymbol, SIGNAL(activated(int)), QG_DlgText, SLOT(insertSymbol(int)));
        QObject::connect(bCopy, SIGNAL(clicked()), teText, SLOT(copy()));
        QObject::connect(bClear, SIGNAL(clicked()), teText, SLOT(clear()));
        QObject::connect(bCut, SIGNAL(clicked()), teText, SLOT(cut()));
        QObject::connect(bPaste, SIGNAL(clicked()), teText, SLOT(paste()));
        QObject::connect(bSave, SIGNAL(clicked()), QG_DlgText, SLOT(saveText()));
        QObject::connect(bLoad, SIGNAL(clicked()), QG_DlgText, SLOT(loadText()));
        QObject::connect(bMC, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentMC()));
        QObject::connect(bMR, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentMR()));
        QObject::connect(bBR, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentBR()));
        QObject::connect(bBL, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentBL()));
        QObject::connect(bTL, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentTL()));
        QObject::connect(bBC, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentBC()));
        QObject::connect(bTC, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentTC()));
        QObject::connect(bLC, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentLC()));
        QObject::connect(bLL, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentLL()));
        QObject::connect(bLR, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentLR()));
        QObject::connect(bML, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentML()));
        QObject::connect(bTR, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentTR()));
        QObject::connect(rbFit, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentFit()));
        QObject::connect(rbAligned, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentAlign()));
        QObject::connect(rbMiddle, SIGNAL(clicked()), QG_DlgText, SLOT(setAlignmentMiddle()));

        QMetaObject::connectSlotsByName(QG_DlgText);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgText)
    {
        QG_DlgText->setWindowTitle(QCoreApplication::translate("QG_DlgText", "Text", nullptr));
        lText->setText(QCoreApplication::translate("QG_DlgText", "Text:", nullptr));
#if QT_CONFIG(tooltip)
        bClear->setToolTip(QCoreApplication::translate("QG_DlgText", "Clear Text", nullptr));
#endif // QT_CONFIG(tooltip)
        bClear->setText(QString());
#if QT_CONFIG(tooltip)
        bLoad->setToolTip(QCoreApplication::translate("QG_DlgText", "Load Text From File", nullptr));
#endif // QT_CONFIG(tooltip)
        bLoad->setText(QString());
#if QT_CONFIG(tooltip)
        bSave->setToolTip(QCoreApplication::translate("QG_DlgText", "Save Text To File", nullptr));
#endif // QT_CONFIG(tooltip)
        bSave->setText(QString());
#if QT_CONFIG(tooltip)
        bCut->setToolTip(QCoreApplication::translate("QG_DlgText", "Cut", nullptr));
#endif // QT_CONFIG(tooltip)
        bCut->setText(QString());
#if QT_CONFIG(tooltip)
        bCopy->setToolTip(QCoreApplication::translate("QG_DlgText", "Copy", nullptr));
#endif // QT_CONFIG(tooltip)
        bCopy->setText(QString());
#if QT_CONFIG(tooltip)
        bPaste->setToolTip(QCoreApplication::translate("QG_DlgText", "Paste", nullptr));
#endif // QT_CONFIG(tooltip)
        bPaste->setText(QString());
        lLayer->setText(QCoreApplication::translate("QG_DlgText", "Layer:", nullptr));
        bgFont->setTitle(QCoreApplication::translate("QG_DlgText", "Font settings", nullptr));
        lHeight->setText(QCoreApplication::translate("QG_DlgText", "&Height:", nullptr));
        lAngle->setText(QCoreApplication::translate("QG_DlgText", "Angle:", nullptr));
        lOblique->setText(QCoreApplication::translate("QG_DlgText", "Oblique:", nullptr));
        lWidthFactor->setText(QCoreApplication::translate("QG_DlgText", "Width factor:", nullptr));
        lFont->setText(QCoreApplication::translate("QG_DlgText", "Font:", nullptr));
        bgAlignment->setTitle(QCoreApplication::translate("QG_DlgText", "Alignment", nullptr));
#if QT_CONFIG(tooltip)
        bBC->setToolTip(QCoreApplication::translate("QG_DlgText", "Bottom Center", nullptr));
#endif // QT_CONFIG(tooltip)
        bBC->setText(QString());
#if QT_CONFIG(tooltip)
        bBR->setToolTip(QCoreApplication::translate("QG_DlgText", "Bottom Right", nullptr));
#endif // QT_CONFIG(tooltip)
        bBR->setText(QString());
#if QT_CONFIG(tooltip)
        bMR->setToolTip(QCoreApplication::translate("QG_DlgText", "Middle Right", nullptr));
#endif // QT_CONFIG(tooltip)
        bMR->setText(QString());
#if QT_CONFIG(tooltip)
        bBL->setToolTip(QCoreApplication::translate("QG_DlgText", "Bottom Left", nullptr));
#endif // QT_CONFIG(tooltip)
        bBL->setText(QString());
#if QT_CONFIG(tooltip)
        bML->setToolTip(QCoreApplication::translate("QG_DlgText", "Middle Left", nullptr));
#endif // QT_CONFIG(tooltip)
        bML->setText(QString());
#if QT_CONFIG(tooltip)
        bLL->setToolTip(QCoreApplication::translate("QG_DlgText", "Baseline Left", nullptr));
#endif // QT_CONFIG(tooltip)
        bLL->setText(QCoreApplication::translate("QG_DlgText", "...", nullptr));
#if QT_CONFIG(tooltip)
        bTC->setToolTip(QCoreApplication::translate("QG_DlgText", "Top Center", nullptr));
#endif // QT_CONFIG(tooltip)
        bTC->setText(QString());
#if QT_CONFIG(tooltip)
        bLR->setToolTip(QCoreApplication::translate("QG_DlgText", "Baseline Right", nullptr));
#endif // QT_CONFIG(tooltip)
        bLR->setText(QCoreApplication::translate("QG_DlgText", "...", nullptr));
#if QT_CONFIG(tooltip)
        bLC->setToolTip(QCoreApplication::translate("QG_DlgText", "Baseline Center", nullptr));
#endif // QT_CONFIG(tooltip)
        bLC->setText(QCoreApplication::translate("QG_DlgText", "...", nullptr));
#if QT_CONFIG(tooltip)
        bTL->setToolTip(QCoreApplication::translate("QG_DlgText", "Top Left", nullptr));
#endif // QT_CONFIG(tooltip)
        bTL->setText(QString());
#if QT_CONFIG(tooltip)
        bTR->setToolTip(QCoreApplication::translate("QG_DlgText", "Top Right", nullptr));
#endif // QT_CONFIG(tooltip)
        bTR->setText(QString());
#if QT_CONFIG(tooltip)
        bMC->setToolTip(QCoreApplication::translate("QG_DlgText", "Middle Center", nullptr));
#endif // QT_CONFIG(tooltip)
        bMC->setText(QString());
        rbFit->setText(QCoreApplication::translate("QG_DlgText", "Fit", nullptr));
        rbAligned->setText(QCoreApplication::translate("QG_DlgText", "A&ligned", nullptr));
        rbMiddle->setText(QCoreApplication::translate("QG_DlgText", "&Middle", nullptr));
        buttonGroup7->setTitle(QCoreApplication::translate("QG_DlgText", "Insert Symbol", nullptr));
        cbSymbol->setItemText(0, QCoreApplication::translate("QG_DlgText", "Diameter (\342\214\200)", nullptr));
        cbSymbol->setItemText(1, QCoreApplication::translate("QG_DlgText", "Degree (\302\260)", nullptr));
        cbSymbol->setItemText(2, QCoreApplication::translate("QG_DlgText", "Plus / Minus (\302\261)", nullptr));
        cbSymbol->setItemText(3, QCoreApplication::translate("QG_DlgText", "At (@)", nullptr));
        cbSymbol->setItemText(4, QCoreApplication::translate("QG_DlgText", "Hash (#)", nullptr));
        cbSymbol->setItemText(5, QCoreApplication::translate("QG_DlgText", "Dollar ($)", nullptr));
        cbSymbol->setItemText(6, QCoreApplication::translate("QG_DlgText", "Copyright (\302\251)", nullptr));
        cbSymbol->setItemText(7, QCoreApplication::translate("QG_DlgText", "Registered (\302\256)", nullptr));
        cbSymbol->setItemText(8, QCoreApplication::translate("QG_DlgText", "Paragraph (\302\247)", nullptr));
        cbSymbol->setItemText(9, QCoreApplication::translate("QG_DlgText", "Pi (\317\200)", nullptr));
        cbSymbol->setItemText(10, QCoreApplication::translate("QG_DlgText", "Pound (\302\243)", nullptr));
        cbSymbol->setItemText(11, QCoreApplication::translate("QG_DlgText", "Yen (\302\245)", nullptr));
        cbSymbol->setItemText(12, QCoreApplication::translate("QG_DlgText", "Times (\303\227)", nullptr));
        cbSymbol->setItemText(13, QCoreApplication::translate("QG_DlgText", "Division (\303\267)", nullptr));

        buttonGroup5->setTitle(QCoreApplication::translate("QG_DlgText", "Insert Unicode", nullptr));
        textLabel1->setText(QCoreApplication::translate("QG_DlgText", "Page:", nullptr));
        textLabel1_2->setText(QCoreApplication::translate("QG_DlgText", "Char:", nullptr));
        cbUniPage->setItemText(0, QCoreApplication::translate("QG_DlgText", "[0000-007F] Basic Latin", nullptr));
        cbUniPage->setItemText(1, QCoreApplication::translate("QG_DlgText", "[0080-00FF] Latin-1 Supplementary", nullptr));
        cbUniPage->setItemText(2, QCoreApplication::translate("QG_DlgText", "[0100-017F] Latin Extended-A", nullptr));
        cbUniPage->setItemText(3, QCoreApplication::translate("QG_DlgText", "[0180-024F] Latin Extended-B", nullptr));
        cbUniPage->setItemText(4, QCoreApplication::translate("QG_DlgText", "[0250-02AF] IPA Extensions", nullptr));
        cbUniPage->setItemText(5, QCoreApplication::translate("QG_DlgText", "[02B0-02FF] Spacing Modifier Letters", nullptr));
        cbUniPage->setItemText(6, QCoreApplication::translate("QG_DlgText", "[0300-036F] Combining Diacritical Marks", nullptr));
        cbUniPage->setItemText(7, QCoreApplication::translate("QG_DlgText", "[0370-03FF] Greek and Coptic", nullptr));
        cbUniPage->setItemText(8, QCoreApplication::translate("QG_DlgText", "[0400-04FF] Cyrillic", nullptr));
        cbUniPage->setItemText(9, QCoreApplication::translate("QG_DlgText", "[0500-052F] Cyrillic Supplementary", nullptr));
        cbUniPage->setItemText(10, QCoreApplication::translate("QG_DlgText", "[0530-058F] Armenian", nullptr));
        cbUniPage->setItemText(11, QCoreApplication::translate("QG_DlgText", "[0590-05FF] Hebrew", nullptr));
        cbUniPage->setItemText(12, QCoreApplication::translate("QG_DlgText", "[0600-06FF] Arabic", nullptr));
        cbUniPage->setItemText(13, QCoreApplication::translate("QG_DlgText", "[0700-074F] Syriac", nullptr));
        cbUniPage->setItemText(14, QCoreApplication::translate("QG_DlgText", "[0780-07BF] Thaana", nullptr));
        cbUniPage->setItemText(15, QCoreApplication::translate("QG_DlgText", "[0900-097F] Devanagari", nullptr));
        cbUniPage->setItemText(16, QCoreApplication::translate("QG_DlgText", "[0980-09FF] Bengali", nullptr));
        cbUniPage->setItemText(17, QCoreApplication::translate("QG_DlgText", "[0A00-0A7F] Gurmukhi", nullptr));
        cbUniPage->setItemText(18, QCoreApplication::translate("QG_DlgText", "[0A80-0AFF] Gujarati", nullptr));
        cbUniPage->setItemText(19, QCoreApplication::translate("QG_DlgText", "[0B00-0B7F] Oriya", nullptr));
        cbUniPage->setItemText(20, QCoreApplication::translate("QG_DlgText", "[0B80-0BFF] Tamil", nullptr));
        cbUniPage->setItemText(21, QCoreApplication::translate("QG_DlgText", "[0C00-0C7F] Telugu", nullptr));
        cbUniPage->setItemText(22, QCoreApplication::translate("QG_DlgText", "[0C80-0CFF] Kannada", nullptr));
        cbUniPage->setItemText(23, QCoreApplication::translate("QG_DlgText", "[0D00-0D7F] Malayalam", nullptr));
        cbUniPage->setItemText(24, QCoreApplication::translate("QG_DlgText", "[0D80-0DFF] Sinhala", nullptr));
        cbUniPage->setItemText(25, QCoreApplication::translate("QG_DlgText", "[0E00-0E7F] Thai", nullptr));
        cbUniPage->setItemText(26, QCoreApplication::translate("QG_DlgText", "[0E80-0EFF] Lao", nullptr));
        cbUniPage->setItemText(27, QCoreApplication::translate("QG_DlgText", "[0F00-0FFF] Tibetan", nullptr));
        cbUniPage->setItemText(28, QCoreApplication::translate("QG_DlgText", "[1000-109F] Myanmar", nullptr));
        cbUniPage->setItemText(29, QCoreApplication::translate("QG_DlgText", "[10A0-10FF] Georgian", nullptr));
        cbUniPage->setItemText(30, QCoreApplication::translate("QG_DlgText", "[1100-11FF] Hangul Jamo", nullptr));
        cbUniPage->setItemText(31, QCoreApplication::translate("QG_DlgText", "[1200-137F] Ethiopic", nullptr));
        cbUniPage->setItemText(32, QCoreApplication::translate("QG_DlgText", "[13A0-13FF] Cherokee", nullptr));
        cbUniPage->setItemText(33, QCoreApplication::translate("QG_DlgText", "[1400-167F] Unified Canadian Aboriginal Syllabic", nullptr));
        cbUniPage->setItemText(34, QCoreApplication::translate("QG_DlgText", "[1680-169F] Ogham", nullptr));
        cbUniPage->setItemText(35, QCoreApplication::translate("QG_DlgText", "[16A0-16FF] Runic", nullptr));
        cbUniPage->setItemText(36, QCoreApplication::translate("QG_DlgText", "[1700-171F] Tagalog", nullptr));
        cbUniPage->setItemText(37, QCoreApplication::translate("QG_DlgText", "[1720-173F] Hanunoo", nullptr));
        cbUniPage->setItemText(38, QCoreApplication::translate("QG_DlgText", "[1740-175F] Buhid", nullptr));
        cbUniPage->setItemText(39, QCoreApplication::translate("QG_DlgText", "[1760-177F] Tagbanwa", nullptr));
        cbUniPage->setItemText(40, QCoreApplication::translate("QG_DlgText", "[1780-17FF] Khmer", nullptr));
        cbUniPage->setItemText(41, QCoreApplication::translate("QG_DlgText", "[1800-18AF] Mongolian", nullptr));
        cbUniPage->setItemText(42, QCoreApplication::translate("QG_DlgText", "[1E00-1EFF] Latin Extended Additional", nullptr));
        cbUniPage->setItemText(43, QCoreApplication::translate("QG_DlgText", "[1F00-1FFF] Greek Extended", nullptr));
        cbUniPage->setItemText(44, QCoreApplication::translate("QG_DlgText", "[2000-206F] General Punctuation", nullptr));
        cbUniPage->setItemText(45, QCoreApplication::translate("QG_DlgText", "[2070-209F] Superscripts and Subscripts", nullptr));
        cbUniPage->setItemText(46, QCoreApplication::translate("QG_DlgText", "[20A0-20CF] Currency Symbols", nullptr));
        cbUniPage->setItemText(47, QCoreApplication::translate("QG_DlgText", "[20D0-20FF] Combining Marks for Symbols", nullptr));
        cbUniPage->setItemText(48, QCoreApplication::translate("QG_DlgText", "[2100-214F] Letterlike Symbols", nullptr));
        cbUniPage->setItemText(49, QCoreApplication::translate("QG_DlgText", "[2150-218F] Number Forms", nullptr));
        cbUniPage->setItemText(50, QCoreApplication::translate("QG_DlgText", "[2190-21FF] Arrows", nullptr));
        cbUniPage->setItemText(51, QCoreApplication::translate("QG_DlgText", "[2200-22FF] Mathematical Operators", nullptr));
        cbUniPage->setItemText(52, QCoreApplication::translate("QG_DlgText", "[2300-23FF] Miscellaneous Technical", nullptr));
        cbUniPage->setItemText(53, QCoreApplication::translate("QG_DlgText", "[2400-243F] Control Pictures", nullptr));
        cbUniPage->setItemText(54, QCoreApplication::translate("QG_DlgText", "[2440-245F] Optical Character Recognition", nullptr));
        cbUniPage->setItemText(55, QCoreApplication::translate("QG_DlgText", "[2460-24FF] Enclosed Alphanumerics", nullptr));
        cbUniPage->setItemText(56, QCoreApplication::translate("QG_DlgText", "[2500-257F] Box Drawing", nullptr));
        cbUniPage->setItemText(57, QCoreApplication::translate("QG_DlgText", "[2580-259F] Block Elements", nullptr));
        cbUniPage->setItemText(58, QCoreApplication::translate("QG_DlgText", "[25A0-25FF] Geometric Shapes", nullptr));
        cbUniPage->setItemText(59, QCoreApplication::translate("QG_DlgText", "[2600-26FF] Miscellaneous Symbols", nullptr));
        cbUniPage->setItemText(60, QCoreApplication::translate("QG_DlgText", "[2700-27BF] Dingbats", nullptr));
        cbUniPage->setItemText(61, QCoreApplication::translate("QG_DlgText", "[27C0-27EF] Miscellaneous Mathematical Symbols-A", nullptr));
        cbUniPage->setItemText(62, QCoreApplication::translate("QG_DlgText", "[27F0-27FF] Supplemental Arrows-A", nullptr));
        cbUniPage->setItemText(63, QCoreApplication::translate("QG_DlgText", "[2800-28FF] Braille Patterns", nullptr));
        cbUniPage->setItemText(64, QCoreApplication::translate("QG_DlgText", "[2900-297F] Supplemental Arrows-B", nullptr));
        cbUniPage->setItemText(65, QCoreApplication::translate("QG_DlgText", "[2980-29FF] Miscellaneous Mathematical Symbols-B", nullptr));
        cbUniPage->setItemText(66, QCoreApplication::translate("QG_DlgText", "[2A00-2AFF] Supplemental Mathematical Operators", nullptr));
        cbUniPage->setItemText(67, QCoreApplication::translate("QG_DlgText", "[2E80-2EFF] CJK Radicals Supplement", nullptr));
        cbUniPage->setItemText(68, QCoreApplication::translate("QG_DlgText", "[2F00-2FDF] Kangxi Radicals", nullptr));
        cbUniPage->setItemText(69, QCoreApplication::translate("QG_DlgText", "[2FF0-2FFF] Ideographic Description Characters", nullptr));
        cbUniPage->setItemText(70, QCoreApplication::translate("QG_DlgText", "[3000-303F] CJK Symbols and Punctuation", nullptr));
        cbUniPage->setItemText(71, QCoreApplication::translate("QG_DlgText", "[3040-309F] Hiragana", nullptr));
        cbUniPage->setItemText(72, QCoreApplication::translate("QG_DlgText", "[30A0-30FF] Katakana", nullptr));
        cbUniPage->setItemText(73, QCoreApplication::translate("QG_DlgText", "[3100-312F] Bopomofo", nullptr));
        cbUniPage->setItemText(74, QCoreApplication::translate("QG_DlgText", "[3130-318F] Hangul Compatibility Jamo", nullptr));
        cbUniPage->setItemText(75, QCoreApplication::translate("QG_DlgText", "[3190-319F] Kanbun", nullptr));
        cbUniPage->setItemText(76, QCoreApplication::translate("QG_DlgText", "[31A0-31BF] Bopomofo Extended", nullptr));
        cbUniPage->setItemText(77, QCoreApplication::translate("QG_DlgText", "[3200-32FF] Enclosed CJK Letters and Months", nullptr));
        cbUniPage->setItemText(78, QCoreApplication::translate("QG_DlgText", "[3300-33FF] CJK Compatibility", nullptr));
        cbUniPage->setItemText(79, QCoreApplication::translate("QG_DlgText", "[3400-4DBF] CJK Unified Ideographs Extension A", nullptr));
        cbUniPage->setItemText(80, QCoreApplication::translate("QG_DlgText", "[4E00-9FAF] CJK Unified Ideographs", nullptr));
        cbUniPage->setItemText(81, QCoreApplication::translate("QG_DlgText", "[A000-A48F] Yi Syllables", nullptr));
        cbUniPage->setItemText(82, QCoreApplication::translate("QG_DlgText", "[A490-A4CF] Yi Radicals", nullptr));
        cbUniPage->setItemText(83, QCoreApplication::translate("QG_DlgText", "[AC00-D7AF] Hangul Syllables", nullptr));
        cbUniPage->setItemText(84, QCoreApplication::translate("QG_DlgText", "[D800-DBFF] High Surrogates", nullptr));
        cbUniPage->setItemText(85, QCoreApplication::translate("QG_DlgText", "[DC00-DFFF] Low Surrogate Area", nullptr));
        cbUniPage->setItemText(86, QCoreApplication::translate("QG_DlgText", "[E000-F8FF] Private Use Area", nullptr));
        cbUniPage->setItemText(87, QCoreApplication::translate("QG_DlgText", "[F900-FAFF] CJK Compatibility Ideographs", nullptr));
        cbUniPage->setItemText(88, QCoreApplication::translate("QG_DlgText", "[FB00-FB4F] Alphabetic Presentation Forms", nullptr));
        cbUniPage->setItemText(89, QCoreApplication::translate("QG_DlgText", "[FB50-FDFF] Arabic Presentation Forms-A", nullptr));
        cbUniPage->setItemText(90, QCoreApplication::translate("QG_DlgText", "[FE00-FE0F] Variation Selectors", nullptr));
        cbUniPage->setItemText(91, QCoreApplication::translate("QG_DlgText", "[FE20-FE2F] Combining Half Marks", nullptr));
        cbUniPage->setItemText(92, QCoreApplication::translate("QG_DlgText", "[FE30-FE4F] CJK Compatibility Forms", nullptr));
        cbUniPage->setItemText(93, QCoreApplication::translate("QG_DlgText", "[FE50-FE6F] Small Form Variants", nullptr));
        cbUniPage->setItemText(94, QCoreApplication::translate("QG_DlgText", "[FE70-FEFF] Arabic Presentation Forms-B", nullptr));
        cbUniPage->setItemText(95, QCoreApplication::translate("QG_DlgText", "[FF00-FFEF] Halfwidth and Fullwidth Forms", nullptr));
        cbUniPage->setItemText(96, QCoreApplication::translate("QG_DlgText", "[FFF0-FFFF] Specials", nullptr));
        cbUniPage->setItemText(97, QCoreApplication::translate("QG_DlgText", "[10300-1032F] Old Italic", nullptr));
        cbUniPage->setItemText(98, QCoreApplication::translate("QG_DlgText", "[10330-1034F] Gothic", nullptr));
        cbUniPage->setItemText(99, QCoreApplication::translate("QG_DlgText", "[10400-1044F] Deseret", nullptr));
        cbUniPage->setItemText(100, QCoreApplication::translate("QG_DlgText", "[1D000-1D0FF] Byzantine Musical Symbols", nullptr));
        cbUniPage->setItemText(101, QCoreApplication::translate("QG_DlgText", "[1D100-1D1FF] Musical Symbols", nullptr));
        cbUniPage->setItemText(102, QCoreApplication::translate("QG_DlgText", "[1D400-1D7FF] Mathematical Alphanumeric Symbols", nullptr));
        cbUniPage->setItemText(103, QCoreApplication::translate("QG_DlgText", "[20000-2A6DF] CJK Unified Ideographs Extension B", nullptr));
        cbUniPage->setItemText(104, QCoreApplication::translate("QG_DlgText", "[2F800-2FA1F] CJK Compatibility Ideographs Supplement", nullptr));
        cbUniPage->setItemText(105, QCoreApplication::translate("QG_DlgText", "[E0000-E007F] Tags", nullptr));
        cbUniPage->setItemText(106, QCoreApplication::translate("QG_DlgText", "[F0000-FFFFD] Supplementary Private Use Area-A", nullptr));
        cbUniPage->setItemText(107, QCoreApplication::translate("QG_DlgText", "[100000-10FFFD] Supplementary Private Use Area-B", nullptr));

        bUnicode->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_DlgText: public Ui_QG_DlgText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGTEXT_H
