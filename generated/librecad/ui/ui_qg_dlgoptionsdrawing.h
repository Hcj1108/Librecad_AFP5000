/********************************************************************************
** Form generated from reading UI file 'qg_dlgoptionsdrawing.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGOPTIONSDRAWING_H
#define UI_QG_DLGOPTIONSDRAWING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../lg_dimzerosbox.h"
#include "../qg_colorbox.h"
#include "../qg_widthbox.h"
#include "qg_fontbox.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgOptionsDrawing
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *tab1Layout;
    QVBoxLayout *paperOptionsLayout;
    QGroupBox *formatGroupBox;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QComboBox *cbPaperFormat;
    QGridLayout *gridLayout_3;
    QLineEdit *lePaperWidth;
    QLabel *lPageHeight;
    QLineEdit *lePaperHeight;
    QLabel *lPageWidth;
    QGroupBox *orientGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbLandscape;
    QRadioButton *rbPortrait;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *marginsGroupBox;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QLineEdit *leMarginLeft;
    QLineEdit *leMarginBottom;
    QLineEdit *leMarginRight;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *leMarginTop;
    QGroupBox *pagesNumGroupBox;
    QHBoxLayout *pagesNumLayout;
    QLabel *lPagesNumH;
    QSpinBox *sbPagesNumH;
    QLabel *lPagesNumV;
    QSpinBox *sbPagesNumV;
    QGroupBox *paperPreviewGroupBox;
    QVBoxLayout *verticalLayout;
    QGraphicsView *gvPaperPreview;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab2;
    QVBoxLayout *vboxLayout2;
    QGroupBox *bgUnit;
    QHBoxLayout *hboxLayout1;
    QLabel *lUnit;
    QComboBox *cbUnit;
    QSpacerItem *spacer19;
    QHBoxLayout *hboxLayout2;
    QVBoxLayout *vboxLayout3;
    QGroupBox *bgLength;
    QGridLayout *gridLayout_4;
    QLabel *lLengthFormat;
    QComboBox *cbLengthFormat;
    QComboBox *cbLengthPrecision;
    QLabel *lLengthPrecision;
    QSpacerItem *spacer15;
    QSpacerItem *spacer15_2;
    QGroupBox *bgLengthPreview;
    QHBoxLayout *hboxLayout3;
    QLabel *lLinear;
    QVBoxLayout *vboxLayout4;
    QGroupBox *bgAngle;
    QGridLayout *gridLayout_5;
    QLabel *lAngleFormat;
    QSpacerItem *spacer15_3;
    QSpacerItem *spacer15_2_2;
    QComboBox *cbAngleFormat;
    QLabel *lAnglePrecision;
    QComboBox *cbAnglePrecision;
    QGroupBox *bgAnglePreview;
    QHBoxLayout *hboxLayout4;
    QLabel *lAngular;
    QWidget *tab3;
    QGridLayout *gridLayout_9;
    QGroupBox *bgGrid;
    QGridLayout *gridLayout_7;
    QCheckBox *cbGridOn;
    QRadioButton *rbOrthogonalGrid;
    QRadioButton *rbIsometricGrid;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QRadioButton *rbCrosshairLeft;
    QRadioButton *rbCrosshairTop;
    QRadioButton *rbCrosshairRight;
    QLabel *lCrosshair;
    QGridLayout *gridLayout_8;
    QLabel *lXSpacing;
    QComboBox *cbXSpacing;
    QLabel *lYSpacing;
    QComboBox *cbYSpacing;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *tab4;
    QGridLayout *gridLayout;
    QSpacerItem *spacer11_2_2;
    QG_FontBox *cbDimTxSty;
    QLabel *label_5;
    QComboBox *cbDimDSep;
    QLabel *label_6;
    QLabel *lDimUnit6;
    QLabel *lDimUnit5;
    QLabel *lDimLUnit;
    QLabel *lDimClrT;
    LG_DimzerosBox *cbDimAZin;
    QLabel *lDimFactor;
    QComboBox *cbDimFactor;
    QLabel *lDimTsz;
    QLabel *lDimUnit1;
    QSpacerItem *spacer11;
    QG_WidthBox *cbDimLwD;
    QLabel *lDimAUnit;
    QLabel *lDimTextHeight;
    QLabel *lDimZin;
    QComboBox *cbDimTsz;
    QLabel *label_4;
    QComboBox *cbDimGap;
    QComboBox *cbDimScale;
    QLabel *label_2;
    QLabel *lDimScale;
    QComboBox *cbDimTextHeight;
    QComboBox *cbDimDec;
    QG_ColorBox *cbDimClrD;
    QComboBox *cbDimExe;
    QComboBox *cbDimAsz;
    QSpacerItem *spacer11_2;
    QLabel *lDimAsz;
    QComboBox *cbDimADec;
    QLabel *lDimLwD;
    QComboBox *cbDimAUnit;
    QLabel *lDimUnit4;
    QLabel *label;
    QLabel *lDimAZin;
    QLabel *lDimClrD;
    QLabel *lDimADec;
    QLabel *lDimExe;
    QLabel *lDimExo;
    QComboBox *cbDimLUnit;
    QLabel *lDimDec;
    QG_ColorBox *cbDimClrT;
    QComboBox *cbDimTih;
    QLabel *lDimUnit2;
    QLabel *lDimUnit3;
    LG_DimzerosBox *cbDimZin;
    QFrame *line;
    QComboBox *cbDimExo;
    QLabel *lDimUnit7;
    QLabel *lDimTih;
    QLabel *lDimGap;
    QLabel *label_3;
    QCheckBox *cbDimFxLon;
    QLabel *lDimClrE;
    QLabel *lDimLwE;
    QG_WidthBox *cbDimLwE;
    QG_ColorBox *cbDimClrE;
    QDoubleSpinBox *cbDimFxL;
    QWidget *tab5;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *hboxLayout5;
    QLabel *lSplineSegs;
    QComboBox *cbSplineSegs;
    QSpacerItem *spacer19_2;

    void setupUi(QDialog *QG_DlgOptionsDrawing)
    {
        if (QG_DlgOptionsDrawing->objectName().isEmpty())
            QG_DlgOptionsDrawing->setObjectName(QString::fromUtf8("QG_DlgOptionsDrawing"));
        QG_DlgOptionsDrawing->resize(653, 519);
        QG_DlgOptionsDrawing->setSizeGripEnabled(true);
        gridLayout_2 = new QGridLayout(QG_DlgOptionsDrawing);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(QG_DlgOptionsDrawing);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        tabWidget = new QTabWidget(QG_DlgOptionsDrawing);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        vboxLayout = new QVBoxLayout(tab1);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        tab1Layout = new QHBoxLayout();
        tab1Layout->setSpacing(6);
        tab1Layout->setObjectName(QString::fromUtf8("tab1Layout"));
        paperOptionsLayout = new QVBoxLayout();
        paperOptionsLayout->setSpacing(6);
        paperOptionsLayout->setObjectName(QString::fromUtf8("paperOptionsLayout"));
        formatGroupBox = new QGroupBox(tab1);
        formatGroupBox->setObjectName(QString::fromUtf8("formatGroupBox"));
        vboxLayout1 = new QVBoxLayout(formatGroupBox);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(12);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        cbPaperFormat = new QComboBox(formatGroupBox);
        cbPaperFormat->setObjectName(QString::fromUtf8("cbPaperFormat"));

        hboxLayout->addWidget(cbPaperFormat);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, -1, -1, -1);
        lePaperWidth = new QLineEdit(formatGroupBox);
        lePaperWidth->setObjectName(QString::fromUtf8("lePaperWidth"));

        gridLayout_3->addWidget(lePaperWidth, 0, 2, 1, 1);

        lPageHeight = new QLabel(formatGroupBox);
        lPageHeight->setObjectName(QString::fromUtf8("lPageHeight"));
        lPageHeight->setWordWrap(false);

        gridLayout_3->addWidget(lPageHeight, 1, 0, 1, 1);

        lePaperHeight = new QLineEdit(formatGroupBox);
        lePaperHeight->setObjectName(QString::fromUtf8("lePaperHeight"));

        gridLayout_3->addWidget(lePaperHeight, 1, 2, 1, 1);

        lPageWidth = new QLabel(formatGroupBox);
        lPageWidth->setObjectName(QString::fromUtf8("lPageWidth"));
        lPageWidth->setWordWrap(false);

        gridLayout_3->addWidget(lPageWidth, 0, 0, 1, 1);


        hboxLayout->addLayout(gridLayout_3);


        vboxLayout1->addLayout(hboxLayout);


        paperOptionsLayout->addWidget(formatGroupBox);

        orientGroupBox = new QGroupBox(tab1);
        orientGroupBox->setObjectName(QString::fromUtf8("orientGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(orientGroupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbLandscape = new QRadioButton(orientGroupBox);
        rbLandscape->setObjectName(QString::fromUtf8("rbLandscape"));

        horizontalLayout_2->addWidget(rbLandscape);

        rbPortrait = new QRadioButton(orientGroupBox);
        rbPortrait->setObjectName(QString::fromUtf8("rbPortrait"));

        horizontalLayout_2->addWidget(rbPortrait);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        paperOptionsLayout->addWidget(orientGroupBox);

        marginsGroupBox = new QGroupBox(tab1);
        marginsGroupBox->setObjectName(QString::fromUtf8("marginsGroupBox"));
        gridLayout_11 = new QGridLayout(marginsGroupBox);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        leMarginLeft = new QLineEdit(marginsGroupBox);
        leMarginLeft->setObjectName(QString::fromUtf8("leMarginLeft"));
        leMarginLeft->setMaximumSize(QSize(70, 16777215));

        gridLayout_10->addWidget(leMarginLeft, 2, 1, 1, 1);

        leMarginBottom = new QLineEdit(marginsGroupBox);
        leMarginBottom->setObjectName(QString::fromUtf8("leMarginBottom"));
        leMarginBottom->setMaximumSize(QSize(70, 16777215));

        gridLayout_10->addWidget(leMarginBottom, 3, 2, 1, 1);

        leMarginRight = new QLineEdit(marginsGroupBox);
        leMarginRight->setObjectName(QString::fromUtf8("leMarginRight"));
        leMarginRight->setMaximumSize(QSize(70, 16777215));

        gridLayout_10->addWidget(leMarginRight, 2, 3, 1, 1);

        label_10 = new QLabel(marginsGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_10, 4, 2, 1, 1);

        label_7 = new QLabel(marginsGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_7, 0, 2, 1, 1);

        label_9 = new QLabel(marginsGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_10->addWidget(label_9, 2, 4, 1, 1);

        label_8 = new QLabel(marginsGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_8, 2, 0, 1, 1);

        leMarginTop = new QLineEdit(marginsGroupBox);
        leMarginTop->setObjectName(QString::fromUtf8("leMarginTop"));
        leMarginTop->setMaximumSize(QSize(70, 16777215));

        gridLayout_10->addWidget(leMarginTop, 1, 2, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);


        paperOptionsLayout->addWidget(marginsGroupBox);

        pagesNumGroupBox = new QGroupBox(tab1);
        pagesNumGroupBox->setObjectName(QString::fromUtf8("pagesNumGroupBox"));
        pagesNumLayout = new QHBoxLayout(pagesNumGroupBox);
        pagesNumLayout->setSpacing(6);
        pagesNumLayout->setContentsMargins(11, 11, 11, 11);
        pagesNumLayout->setObjectName(QString::fromUtf8("pagesNumLayout"));
        lPagesNumH = new QLabel(pagesNumGroupBox);
        lPagesNumH->setObjectName(QString::fromUtf8("lPagesNumH"));
        lPagesNumH->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        pagesNumLayout->addWidget(lPagesNumH);

        sbPagesNumH = new QSpinBox(pagesNumGroupBox);
        sbPagesNumH->setObjectName(QString::fromUtf8("sbPagesNumH"));
        sbPagesNumH->setMinimum(1);

        pagesNumLayout->addWidget(sbPagesNumH);

        lPagesNumV = new QLabel(pagesNumGroupBox);
        lPagesNumV->setObjectName(QString::fromUtf8("lPagesNumV"));
        lPagesNumV->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        pagesNumLayout->addWidget(lPagesNumV);

        sbPagesNumV = new QSpinBox(pagesNumGroupBox);
        sbPagesNumV->setObjectName(QString::fromUtf8("sbPagesNumV"));
        sbPagesNumV->setMinimum(1);

        pagesNumLayout->addWidget(sbPagesNumV);


        paperOptionsLayout->addWidget(pagesNumGroupBox);


        tab1Layout->addLayout(paperOptionsLayout);

        paperPreviewGroupBox = new QGroupBox(tab1);
        paperPreviewGroupBox->setObjectName(QString::fromUtf8("paperPreviewGroupBox"));
        verticalLayout = new QVBoxLayout(paperPreviewGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gvPaperPreview = new QGraphicsView(paperPreviewGroupBox);
        gvPaperPreview->setObjectName(QString::fromUtf8("gvPaperPreview"));
        gvPaperPreview->setFocusPolicy(Qt::NoFocus);
        gvPaperPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gvPaperPreview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gvPaperPreview->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(gvPaperPreview);


        tab1Layout->addWidget(paperPreviewGroupBox);


        vboxLayout->addLayout(tab1Layout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(verticalSpacer_2);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        vboxLayout2 = new QVBoxLayout(tab2);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(11, 11, 11, 11);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        bgUnit = new QGroupBox(tab2);
        bgUnit->setObjectName(QString::fromUtf8("bgUnit"));
        hboxLayout1 = new QHBoxLayout(bgUnit);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(11, 11, 11, 11);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        lUnit = new QLabel(bgUnit);
        lUnit->setObjectName(QString::fromUtf8("lUnit"));
        lUnit->setWordWrap(false);

        hboxLayout1->addWidget(lUnit);

        cbUnit = new QComboBox(bgUnit);
        cbUnit->setObjectName(QString::fromUtf8("cbUnit"));

        hboxLayout1->addWidget(cbUnit);

        spacer19 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer19);


        vboxLayout2->addWidget(bgUnit);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        bgLength = new QGroupBox(tab2);
        bgLength->setObjectName(QString::fromUtf8("bgLength"));
        gridLayout_4 = new QGridLayout(bgLength);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lLengthFormat = new QLabel(bgLength);
        lLengthFormat->setObjectName(QString::fromUtf8("lLengthFormat"));
        lLengthFormat->setWordWrap(false);

        gridLayout_4->addWidget(lLengthFormat, 0, 0, 1, 1);

        cbLengthFormat = new QComboBox(bgLength);
        cbLengthFormat->setObjectName(QString::fromUtf8("cbLengthFormat"));

        gridLayout_4->addWidget(cbLengthFormat, 0, 1, 1, 1);

        cbLengthPrecision = new QComboBox(bgLength);
        cbLengthPrecision->setObjectName(QString::fromUtf8("cbLengthPrecision"));

        gridLayout_4->addWidget(cbLengthPrecision, 1, 1, 1, 1);

        lLengthPrecision = new QLabel(bgLength);
        lLengthPrecision->setObjectName(QString::fromUtf8("lLengthPrecision"));
        lLengthPrecision->setWordWrap(false);

        gridLayout_4->addWidget(lLengthPrecision, 1, 0, 1, 1);

        spacer15 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(spacer15, 2, 1, 1, 1);

        spacer15_2 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(spacer15_2, 2, 0, 1, 1);


        vboxLayout3->addWidget(bgLength);

        bgLengthPreview = new QGroupBox(tab2);
        bgLengthPreview->setObjectName(QString::fromUtf8("bgLengthPreview"));
        hboxLayout3 = new QHBoxLayout(bgLengthPreview);
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        lLinear = new QLabel(bgLengthPreview);
        lLinear->setObjectName(QString::fromUtf8("lLinear"));
        lLinear->setWordWrap(false);

        hboxLayout3->addWidget(lLinear);


        vboxLayout3->addWidget(bgLengthPreview);


        hboxLayout2->addLayout(vboxLayout3);

        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(6);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        bgAngle = new QGroupBox(tab2);
        bgAngle->setObjectName(QString::fromUtf8("bgAngle"));
        gridLayout_5 = new QGridLayout(bgAngle);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lAngleFormat = new QLabel(bgAngle);
        lAngleFormat->setObjectName(QString::fromUtf8("lAngleFormat"));
        lAngleFormat->setWordWrap(false);

        gridLayout_5->addWidget(lAngleFormat, 0, 0, 1, 1);

        spacer15_3 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(spacer15_3, 2, 1, 1, 1);

        spacer15_2_2 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(spacer15_2_2, 2, 0, 1, 1);

        cbAngleFormat = new QComboBox(bgAngle);
        cbAngleFormat->setObjectName(QString::fromUtf8("cbAngleFormat"));

        gridLayout_5->addWidget(cbAngleFormat, 0, 1, 1, 1);

        lAnglePrecision = new QLabel(bgAngle);
        lAnglePrecision->setObjectName(QString::fromUtf8("lAnglePrecision"));
        lAnglePrecision->setWordWrap(false);

        gridLayout_5->addWidget(lAnglePrecision, 1, 0, 1, 1);

        cbAnglePrecision = new QComboBox(bgAngle);
        cbAnglePrecision->setObjectName(QString::fromUtf8("cbAnglePrecision"));

        gridLayout_5->addWidget(cbAnglePrecision, 1, 1, 1, 1);


        vboxLayout4->addWidget(bgAngle);

        bgAnglePreview = new QGroupBox(tab2);
        bgAnglePreview->setObjectName(QString::fromUtf8("bgAnglePreview"));
        hboxLayout4 = new QHBoxLayout(bgAnglePreview);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(11, 11, 11, 11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        lAngular = new QLabel(bgAnglePreview);
        lAngular->setObjectName(QString::fromUtf8("lAngular"));
        lAngular->setWordWrap(false);

        hboxLayout4->addWidget(lAngular);


        vboxLayout4->addWidget(bgAnglePreview);


        hboxLayout2->addLayout(vboxLayout4);


        vboxLayout2->addLayout(hboxLayout2);

        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        gridLayout_9 = new QGridLayout(tab3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        bgGrid = new QGroupBox(tab3);
        bgGrid->setObjectName(QString::fromUtf8("bgGrid"));
        bgGrid->setMinimumSize(QSize(120, 60));
        gridLayout_7 = new QGridLayout(bgGrid);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        cbGridOn = new QCheckBox(bgGrid);
        cbGridOn->setObjectName(QString::fromUtf8("cbGridOn"));

        gridLayout_7->addWidget(cbGridOn, 0, 0, 1, 1);

        rbOrthogonalGrid = new QRadioButton(bgGrid);
        rbOrthogonalGrid->setObjectName(QString::fromUtf8("rbOrthogonalGrid"));
        rbOrthogonalGrid->setAutoExclusive(true);

        gridLayout_7->addWidget(rbOrthogonalGrid, 0, 1, 1, 1);

        rbIsometricGrid = new QRadioButton(bgGrid);
        rbIsometricGrid->setObjectName(QString::fromUtf8("rbIsometricGrid"));
        rbIsometricGrid->setAutoExclusive(false);

        gridLayout_7->addWidget(rbIsometricGrid, 1, 1, 1, 1);

        widget = new QWidget(bgGrid);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(350, 16777215));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        rbCrosshairLeft = new QRadioButton(widget);
        rbCrosshairLeft->setObjectName(QString::fromUtf8("rbCrosshairLeft"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rbCrosshairLeft->sizePolicy().hasHeightForWidth());
        rbCrosshairLeft->setSizePolicy(sizePolicy1);
        rbCrosshairLeft->setMinimumSize(QSize(100, 0));

        gridLayout_6->addWidget(rbCrosshairLeft, 1, 0, 1, 1);

        rbCrosshairTop = new QRadioButton(widget);
        rbCrosshairTop->setObjectName(QString::fromUtf8("rbCrosshairTop"));
        sizePolicy1.setHeightForWidth(rbCrosshairTop->sizePolicy().hasHeightForWidth());
        rbCrosshairTop->setSizePolicy(sizePolicy1);
        rbCrosshairTop->setMinimumSize(QSize(100, 0));

        gridLayout_6->addWidget(rbCrosshairTop, 1, 1, 1, 1);

        rbCrosshairRight = new QRadioButton(widget);
        rbCrosshairRight->setObjectName(QString::fromUtf8("rbCrosshairRight"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rbCrosshairRight->sizePolicy().hasHeightForWidth());
        rbCrosshairRight->setSizePolicy(sizePolicy2);
        rbCrosshairRight->setMinimumSize(QSize(100, 0));

        gridLayout_6->addWidget(rbCrosshairRight, 1, 2, 1, 1);

        lCrosshair = new QLabel(widget);
        lCrosshair->setObjectName(QString::fromUtf8("lCrosshair"));
        sizePolicy1.setHeightForWidth(lCrosshair->sizePolicy().hasHeightForWidth());
        lCrosshair->setSizePolicy(sizePolicy1);
        lCrosshair->setMinimumSize(QSize(70, 0));

        gridLayout_6->addWidget(lCrosshair, 0, 0, 1, 3);


        gridLayout_7->addWidget(widget, 2, 1, 1, 1);


        gridLayout_9->addWidget(bgGrid, 0, 0, 1, 2);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        lXSpacing = new QLabel(tab3);
        lXSpacing->setObjectName(QString::fromUtf8("lXSpacing"));
        lXSpacing->setMinimumSize(QSize(120, 0));
        lXSpacing->setWordWrap(false);

        gridLayout_8->addWidget(lXSpacing, 0, 0, 1, 1);

        cbXSpacing = new QComboBox(tab3);
        cbXSpacing->addItem(QString());
        cbXSpacing->addItem(QString::fromUtf8("0.01"));
        cbXSpacing->addItem(QString::fromUtf8("0.1"));
        cbXSpacing->addItem(QString::fromUtf8("1"));
        cbXSpacing->addItem(QString::fromUtf8("10"));
        cbXSpacing->setObjectName(QString::fromUtf8("cbXSpacing"));
        cbXSpacing->setMinimumSize(QSize(100, 0));
        cbXSpacing->setEditable(true);

        gridLayout_8->addWidget(cbXSpacing, 0, 1, 1, 1);

        lYSpacing = new QLabel(tab3);
        lYSpacing->setObjectName(QString::fromUtf8("lYSpacing"));
        lYSpacing->setWordWrap(false);

        gridLayout_8->addWidget(lYSpacing, 1, 0, 1, 1);

        cbYSpacing = new QComboBox(tab3);
        cbYSpacing->addItem(QString());
        cbYSpacing->addItem(QString::fromUtf8("0.01"));
        cbYSpacing->addItem(QString::fromUtf8("0.1"));
        cbYSpacing->addItem(QString::fromUtf8("1"));
        cbYSpacing->addItem(QString::fromUtf8("10"));
        cbYSpacing->setObjectName(QString::fromUtf8("cbYSpacing"));
        cbYSpacing->setEditable(true);

        gridLayout_8->addWidget(cbYSpacing, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 2, 0, 1, 1);

        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        gridLayout = new QGridLayout(tab4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacer11_2_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer11_2_2, 14, 5, 1, 1);

        cbDimTxSty = new QG_FontBox(tab4);
        cbDimTxSty->setObjectName(QString::fromUtf8("cbDimTxSty"));

        gridLayout->addWidget(cbDimTxSty, 3, 2, 1, 1);

        label_5 = new QLabel(tab4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        cbDimDSep = new QComboBox(tab4);
        cbDimDSep->addItem(QString());
        cbDimDSep->addItem(QString());
        cbDimDSep->setObjectName(QString::fromUtf8("cbDimDSep"));

        gridLayout->addWidget(cbDimDSep, 10, 7, 1, 1);

        label_6 = new QLabel(tab4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 10, 6, 1, 1);

        lDimUnit6 = new QLabel(tab4);
        lDimUnit6->setObjectName(QString::fromUtf8("lDimUnit6"));
        lDimUnit6->setWordWrap(false);

        gridLayout->addWidget(lDimUnit6, 3, 8, 1, 1);

        lDimUnit5 = new QLabel(tab4);
        lDimUnit5->setObjectName(QString::fromUtf8("lDimUnit5"));
        lDimUnit5->setWordWrap(false);

        gridLayout->addWidget(lDimUnit5, 2, 8, 1, 1);

        lDimLUnit = new QLabel(tab4);
        lDimLUnit->setObjectName(QString::fromUtf8("lDimLUnit"));
        lDimLUnit->setTextFormat(Qt::PlainText);
        lDimLUnit->setWordWrap(false);

        gridLayout->addWidget(lDimLUnit, 7, 6, 1, 1);

        lDimClrT = new QLabel(tab4);
        lDimClrT->setObjectName(QString::fromUtf8("lDimClrT"));

        gridLayout->addWidget(lDimClrT, 7, 1, 1, 1);

        cbDimAZin = new LG_DimzerosBox(tab4);
        cbDimAZin->setObjectName(QString::fromUtf8("cbDimAZin"));

        gridLayout->addWidget(cbDimAZin, 13, 7, 1, 1);

        lDimFactor = new QLabel(tab4);
        lDimFactor->setObjectName(QString::fromUtf8("lDimFactor"));
        lDimFactor->setWordWrap(false);

        gridLayout->addWidget(lDimFactor, 2, 1, 1, 1);

        cbDimFactor = new QComboBox(tab4);
        cbDimFactor->addItem(QString::fromUtf8("0.1"));
        cbDimFactor->addItem(QString::fromUtf8("0.2"));
        cbDimFactor->addItem(QString::fromUtf8("0.5"));
        cbDimFactor->addItem(QString::fromUtf8("1"));
        cbDimFactor->addItem(QString::fromUtf8("2"));
        cbDimFactor->addItem(QString::fromUtf8("5"));
        cbDimFactor->addItem(QString::fromUtf8("10"));
        cbDimFactor->addItem(QString::fromUtf8("20"));
        cbDimFactor->addItem(QString::fromUtf8("50"));
        cbDimFactor->addItem(QString::fromUtf8("100"));
        cbDimFactor->addItem(QString::fromUtf8("200"));
        cbDimFactor->addItem(QString::fromUtf8("500"));
        cbDimFactor->addItem(QString::fromUtf8("1000"));
        cbDimFactor->setObjectName(QString::fromUtf8("cbDimFactor"));
        cbDimFactor->setEditable(true);

        gridLayout->addWidget(cbDimFactor, 2, 2, 1, 1);

        lDimTsz = new QLabel(tab4);
        lDimTsz->setObjectName(QString::fromUtf8("lDimTsz"));
        lDimTsz->setWordWrap(false);

        gridLayout->addWidget(lDimTsz, 3, 6, 1, 1);

        lDimUnit1 = new QLabel(tab4);
        lDimUnit1->setObjectName(QString::fromUtf8("lDimUnit1"));
        lDimUnit1->setWordWrap(false);

        gridLayout->addWidget(lDimUnit1, 4, 3, 1, 1);

        spacer11 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer11, 15, 0, 1, 1);

        cbDimLwD = new QG_WidthBox(tab4);
        cbDimLwD->setObjectName(QString::fromUtf8("cbDimLwD"));

        gridLayout->addWidget(cbDimLwD, 5, 7, 1, 1);

        lDimAUnit = new QLabel(tab4);
        lDimAUnit->setObjectName(QString::fromUtf8("lDimAUnit"));
        lDimAUnit->setWordWrap(false);

        gridLayout->addWidget(lDimAUnit, 11, 6, 1, 1);

        lDimTextHeight = new QLabel(tab4);
        lDimTextHeight->setObjectName(QString::fromUtf8("lDimTextHeight"));
        lDimTextHeight->setWordWrap(false);

        gridLayout->addWidget(lDimTextHeight, 4, 1, 1, 1);

        lDimZin = new QLabel(tab4);
        lDimZin->setObjectName(QString::fromUtf8("lDimZin"));

        gridLayout->addWidget(lDimZin, 9, 6, 1, 1);

        cbDimTsz = new QComboBox(tab4);
        cbDimTsz->addItem(QString::fromUtf8("0"));
        cbDimTsz->addItem(QString::fromUtf8("1"));
        cbDimTsz->addItem(QString::fromUtf8("2"));
        cbDimTsz->addItem(QString::fromUtf8("5"));
        cbDimTsz->setObjectName(QString::fromUtf8("cbDimTsz"));
        cbDimTsz->setEditable(true);

        gridLayout->addWidget(cbDimTsz, 3, 7, 1, 1);

        label_4 = new QLabel(tab4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 5, 1, 3);

        cbDimGap = new QComboBox(tab4);
        cbDimGap->addItem(QString::fromUtf8("1"));
        cbDimGap->addItem(QString::fromUtf8("2"));
        cbDimGap->addItem(QString::fromUtf8("5"));
        cbDimGap->setObjectName(QString::fromUtf8("cbDimGap"));
        cbDimGap->setEditable(true);

        gridLayout->addWidget(cbDimGap, 6, 2, 1, 1);

        cbDimScale = new QComboBox(tab4);
        cbDimScale->addItem(QString::fromUtf8("0.1"));
        cbDimScale->addItem(QString::fromUtf8("0.2"));
        cbDimScale->addItem(QString::fromUtf8("0.5"));
        cbDimScale->addItem(QString::fromUtf8("1"));
        cbDimScale->addItem(QString::fromUtf8("2"));
        cbDimScale->addItem(QString::fromUtf8("5"));
        cbDimScale->addItem(QString::fromUtf8("10"));
        cbDimScale->setObjectName(QString::fromUtf8("cbDimScale"));
        cbDimScale->setEditable(true);

        gridLayout->addWidget(cbDimScale, 0, 2, 1, 1);

        label_2 = new QLabel(tab4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 3);

        lDimScale = new QLabel(tab4);
        lDimScale->setObjectName(QString::fromUtf8("lDimScale"));
        lDimScale->setWordWrap(false);

        gridLayout->addWidget(lDimScale, 0, 1, 1, 1);

        cbDimTextHeight = new QComboBox(tab4);
        cbDimTextHeight->addItem(QString::fromUtf8("1"));
        cbDimTextHeight->addItem(QString::fromUtf8("2"));
        cbDimTextHeight->addItem(QString::fromUtf8("5"));
        cbDimTextHeight->setObjectName(QString::fromUtf8("cbDimTextHeight"));
        cbDimTextHeight->setEditable(true);

        gridLayout->addWidget(cbDimTextHeight, 4, 2, 1, 1);

        cbDimDec = new QComboBox(tab4);
        cbDimDec->setObjectName(QString::fromUtf8("cbDimDec"));

        gridLayout->addWidget(cbDimDec, 8, 7, 1, 1);

        cbDimClrD = new QG_ColorBox(tab4);
        cbDimClrD->setObjectName(QString::fromUtf8("cbDimClrD"));

        gridLayout->addWidget(cbDimClrD, 4, 7, 1, 1);

        cbDimExe = new QComboBox(tab4);
        cbDimExe->addItem(QString::fromUtf8("1"));
        cbDimExe->addItem(QString::fromUtf8("2"));
        cbDimExe->addItem(QString::fromUtf8("5"));
        cbDimExe->setObjectName(QString::fromUtf8("cbDimExe"));
        cbDimExe->setEditable(true);

        gridLayout->addWidget(cbDimExe, 10, 2, 1, 1);

        cbDimAsz = new QComboBox(tab4);
        cbDimAsz->addItem(QString::fromUtf8("1"));
        cbDimAsz->addItem(QString::fromUtf8("2"));
        cbDimAsz->addItem(QString::fromUtf8("5"));
        cbDimAsz->setObjectName(QString::fromUtf8("cbDimAsz"));
        cbDimAsz->setEditable(true);

        gridLayout->addWidget(cbDimAsz, 2, 7, 1, 1);

        spacer11_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer11_2, 15, 1, 1, 1);

        lDimAsz = new QLabel(tab4);
        lDimAsz->setObjectName(QString::fromUtf8("lDimAsz"));
        lDimAsz->setWordWrap(false);

        gridLayout->addWidget(lDimAsz, 2, 6, 1, 1);

        cbDimADec = new QComboBox(tab4);
        cbDimADec->setObjectName(QString::fromUtf8("cbDimADec"));

        gridLayout->addWidget(cbDimADec, 12, 7, 1, 1);

        lDimLwD = new QLabel(tab4);
        lDimLwD->setObjectName(QString::fromUtf8("lDimLwD"));

        gridLayout->addWidget(lDimLwD, 5, 6, 1, 1);

        cbDimAUnit = new QComboBox(tab4);
        cbDimAUnit->setObjectName(QString::fromUtf8("cbDimAUnit"));

        gridLayout->addWidget(cbDimAUnit, 11, 7, 1, 1);

        lDimUnit4 = new QLabel(tab4);
        lDimUnit4->setObjectName(QString::fromUtf8("lDimUnit4"));
        lDimUnit4->setWordWrap(false);

        gridLayout->addWidget(lDimUnit4, 6, 3, 1, 1);

        label = new QLabel(tab4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 5, 1, 3);

        lDimAZin = new QLabel(tab4);
        lDimAZin->setObjectName(QString::fromUtf8("lDimAZin"));

        gridLayout->addWidget(lDimAZin, 13, 6, 1, 1);

        lDimClrD = new QLabel(tab4);
        lDimClrD->setObjectName(QString::fromUtf8("lDimClrD"));

        gridLayout->addWidget(lDimClrD, 4, 6, 1, 1);

        lDimADec = new QLabel(tab4);
        lDimADec->setObjectName(QString::fromUtf8("lDimADec"));
        lDimADec->setWordWrap(false);

        gridLayout->addWidget(lDimADec, 12, 6, 1, 1);

        lDimExe = new QLabel(tab4);
        lDimExe->setObjectName(QString::fromUtf8("lDimExe"));
        lDimExe->setWordWrap(false);

        gridLayout->addWidget(lDimExe, 10, 1, 1, 1);

        lDimExo = new QLabel(tab4);
        lDimExo->setObjectName(QString::fromUtf8("lDimExo"));
        lDimExo->setWordWrap(false);

        gridLayout->addWidget(lDimExo, 9, 1, 1, 1);

        cbDimLUnit = new QComboBox(tab4);
        cbDimLUnit->setObjectName(QString::fromUtf8("cbDimLUnit"));

        gridLayout->addWidget(cbDimLUnit, 7, 7, 1, 1);

        lDimDec = new QLabel(tab4);
        lDimDec->setObjectName(QString::fromUtf8("lDimDec"));
        lDimDec->setTextFormat(Qt::PlainText);
        lDimDec->setWordWrap(false);

        gridLayout->addWidget(lDimDec, 8, 6, 1, 1);

        cbDimClrT = new QG_ColorBox(tab4);
        cbDimClrT->setObjectName(QString::fromUtf8("cbDimClrT"));

        gridLayout->addWidget(cbDimClrT, 7, 2, 1, 1);

        cbDimTih = new QComboBox(tab4);
        cbDimTih->addItem(QString());
        cbDimTih->addItem(QString());
        cbDimTih->setObjectName(QString::fromUtf8("cbDimTih"));
        cbDimTih->setEditable(false);

        gridLayout->addWidget(cbDimTih, 5, 2, 1, 1);

        lDimUnit2 = new QLabel(tab4);
        lDimUnit2->setObjectName(QString::fromUtf8("lDimUnit2"));
        lDimUnit2->setWordWrap(false);

        gridLayout->addWidget(lDimUnit2, 10, 3, 1, 1);

        lDimUnit3 = new QLabel(tab4);
        lDimUnit3->setObjectName(QString::fromUtf8("lDimUnit3"));
        lDimUnit3->setWordWrap(false);

        gridLayout->addWidget(lDimUnit3, 9, 3, 1, 1);

        cbDimZin = new LG_DimzerosBox(tab4);
        cbDimZin->setObjectName(QString::fromUtf8("cbDimZin"));

        gridLayout->addWidget(cbDimZin, 9, 7, 1, 1);

        line = new QFrame(tab4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(1);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 4, 13, 1);

        cbDimExo = new QComboBox(tab4);
        cbDimExo->addItem(QString::fromUtf8("1"));
        cbDimExo->addItem(QString::fromUtf8("2"));
        cbDimExo->addItem(QString::fromUtf8("5"));
        cbDimExo->setObjectName(QString::fromUtf8("cbDimExo"));
        cbDimExo->setEditable(true);

        gridLayout->addWidget(cbDimExo, 9, 2, 1, 1);

        lDimUnit7 = new QLabel(tab4);
        lDimUnit7->setObjectName(QString::fromUtf8("lDimUnit7"));

        gridLayout->addWidget(lDimUnit7, 11, 3, 1, 1);

        lDimTih = new QLabel(tab4);
        lDimTih->setObjectName(QString::fromUtf8("lDimTih"));
        lDimTih->setWordWrap(false);

        gridLayout->addWidget(lDimTih, 5, 1, 1, 1);

        lDimGap = new QLabel(tab4);
        lDimGap->setObjectName(QString::fromUtf8("lDimGap"));
        lDimGap->setWordWrap(false);

        gridLayout->addWidget(lDimGap, 6, 1, 1, 1);

        label_3 = new QLabel(tab4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 8, 0, 1, 3);

        cbDimFxLon = new QCheckBox(tab4);
        cbDimFxLon->setObjectName(QString::fromUtf8("cbDimFxLon"));
        cbDimFxLon->setTristate(false);

        gridLayout->addWidget(cbDimFxLon, 11, 0, 1, 2);

        lDimClrE = new QLabel(tab4);
        lDimClrE->setObjectName(QString::fromUtf8("lDimClrE"));

        gridLayout->addWidget(lDimClrE, 12, 1, 1, 1);

        lDimLwE = new QLabel(tab4);
        lDimLwE->setObjectName(QString::fromUtf8("lDimLwE"));

        gridLayout->addWidget(lDimLwE, 13, 1, 1, 1);

        cbDimLwE = new QG_WidthBox(tab4);
        cbDimLwE->setObjectName(QString::fromUtf8("cbDimLwE"));

        gridLayout->addWidget(cbDimLwE, 13, 2, 1, 1);

        cbDimClrE = new QG_ColorBox(tab4);
        cbDimClrE->setObjectName(QString::fromUtf8("cbDimClrE"));
        cbDimClrE->setEditable(false);

        gridLayout->addWidget(cbDimClrE, 12, 2, 1, 1);

        cbDimFxL = new QDoubleSpinBox(tab4);
        cbDimFxL->setObjectName(QString::fromUtf8("cbDimFxL"));
        cbDimFxL->setDecimals(4);

        gridLayout->addWidget(cbDimFxL, 11, 2, 1, 1);

        tabWidget->addTab(tab4, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        vboxLayout5 = new QVBoxLayout(tab5);
        vboxLayout5->setSpacing(6);
        vboxLayout5->setContentsMargins(11, 11, 11, 11);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        lSplineSegs = new QLabel(tab5);
        lSplineSegs->setObjectName(QString::fromUtf8("lSplineSegs"));
        lSplineSegs->setWordWrap(false);

        hboxLayout5->addWidget(lSplineSegs);

        cbSplineSegs = new QComboBox(tab5);
        cbSplineSegs->addItem(QString::fromUtf8("2"));
        cbSplineSegs->addItem(QString::fromUtf8("4"));
        cbSplineSegs->addItem(QString::fromUtf8("8"));
        cbSplineSegs->addItem(QString::fromUtf8("16"));
        cbSplineSegs->addItem(QString::fromUtf8("32"));
        cbSplineSegs->addItem(QString::fromUtf8("64"));
        cbSplineSegs->setObjectName(QString::fromUtf8("cbSplineSegs"));
        cbSplineSegs->setEditable(true);

        hboxLayout5->addWidget(cbSplineSegs);


        vboxLayout5->addLayout(hboxLayout5);

        spacer19_2 = new QSpacerItem(20, 111, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacer19_2);

        tabWidget->addTab(tab5, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        lPageHeight->setBuddy(lePaperHeight);
        lPageWidth->setBuddy(lePaperWidth);
        lUnit->setBuddy(cbUnit);
        lLengthFormat->setBuddy(cbLengthFormat);
        lLengthPrecision->setBuddy(cbLengthPrecision);
        lAngleFormat->setBuddy(cbAngleFormat);
        lAnglePrecision->setBuddy(cbAnglePrecision);
        lDimLUnit->setBuddy(cbLengthFormat);
        lDimAUnit->setBuddy(cbAngleFormat);
        lDimADec->setBuddy(cbAnglePrecision);
        lDimDec->setBuddy(cbLengthPrecision);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(tabWidget, cbPaperFormat);
        QWidget::setTabOrder(cbPaperFormat, lePaperWidth);
        QWidget::setTabOrder(lePaperWidth, lePaperHeight);
        QWidget::setTabOrder(lePaperHeight, rbLandscape);
        QWidget::setTabOrder(rbLandscape, rbPortrait);
        QWidget::setTabOrder(rbPortrait, leMarginTop);
        QWidget::setTabOrder(leMarginTop, leMarginLeft);
        QWidget::setTabOrder(leMarginLeft, leMarginRight);
        QWidget::setTabOrder(leMarginRight, leMarginBottom);
        QWidget::setTabOrder(leMarginBottom, sbPagesNumH);
        QWidget::setTabOrder(sbPagesNumH, sbPagesNumV);
        QWidget::setTabOrder(sbPagesNumV, gvPaperPreview);
        QWidget::setTabOrder(gvPaperPreview, cbUnit);
        QWidget::setTabOrder(cbUnit, cbLengthFormat);
        QWidget::setTabOrder(cbLengthFormat, cbLengthPrecision);
        QWidget::setTabOrder(cbLengthPrecision, cbAngleFormat);
        QWidget::setTabOrder(cbAngleFormat, cbAnglePrecision);
        QWidget::setTabOrder(cbAnglePrecision, cbGridOn);
        QWidget::setTabOrder(cbGridOn, rbOrthogonalGrid);
        QWidget::setTabOrder(rbOrthogonalGrid, rbIsometricGrid);
        QWidget::setTabOrder(rbIsometricGrid, rbCrosshairLeft);
        QWidget::setTabOrder(rbCrosshairLeft, rbCrosshairTop);
        QWidget::setTabOrder(rbCrosshairTop, rbCrosshairRight);
        QWidget::setTabOrder(rbCrosshairRight, cbXSpacing);
        QWidget::setTabOrder(cbXSpacing, cbYSpacing);
        QWidget::setTabOrder(cbYSpacing, cbDimScale);
        QWidget::setTabOrder(cbDimScale, cbDimFactor);
        QWidget::setTabOrder(cbDimFactor, cbDimTextHeight);
        QWidget::setTabOrder(cbDimTextHeight, cbDimTih);
        QWidget::setTabOrder(cbDimTih, cbDimGap);
        QWidget::setTabOrder(cbDimGap, cbDimClrT);
        QWidget::setTabOrder(cbDimClrT, cbDimExo);
        QWidget::setTabOrder(cbDimExo, cbDimExe);
        QWidget::setTabOrder(cbDimExe, cbDimFxLon);
        QWidget::setTabOrder(cbDimFxLon, cbDimFxL);
        QWidget::setTabOrder(cbDimFxL, cbDimClrE);
        QWidget::setTabOrder(cbDimClrE, cbDimLwE);
        QWidget::setTabOrder(cbDimLwE, cbDimAsz);
        QWidget::setTabOrder(cbDimAsz, cbDimTsz);
        QWidget::setTabOrder(cbDimTsz, cbDimClrD);
        QWidget::setTabOrder(cbDimClrD, cbDimLwD);
        QWidget::setTabOrder(cbDimLwD, cbDimLUnit);
        QWidget::setTabOrder(cbDimLUnit, cbDimDec);
        QWidget::setTabOrder(cbDimDec, cbDimZin);
        QWidget::setTabOrder(cbDimZin, cbDimDSep);
        QWidget::setTabOrder(cbDimDSep, cbDimAUnit);
        QWidget::setTabOrder(cbDimAUnit, cbDimADec);
        QWidget::setTabOrder(cbDimADec, cbDimAZin);
        QWidget::setTabOrder(cbDimAZin, cbSplineSegs);

        retranslateUi(QG_DlgOptionsDrawing);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgOptionsDrawing, SLOT(validate()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgOptionsDrawing, SLOT(reject()));
        QObject::connect(cbLengthFormat, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updateLengthPrecision()));
        QObject::connect(cbDimLUnit, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updateDimLengthPrecision()));
        QObject::connect(cbAngleFormat, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updateAnglePrecision()));
        QObject::connect(cbDimAUnit, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updateDimAnglePrecision()));
        QObject::connect(cbUnit, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updatePreview()));
        QObject::connect(cbAngleFormat, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updatePreview()));
        QObject::connect(cbLengthFormat, SIGNAL(activated(QString)), QG_DlgOptionsDrawing, SLOT(updatePreview()));
        QObject::connect(cbAnglePrecision, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updatePreview()));
        QObject::connect(cbLengthPrecision, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updatePreview()));
        QObject::connect(cbPaperFormat, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updatePaperSize()));
        QObject::connect(cbUnit, SIGNAL(activated(int)), QG_DlgOptionsDrawing, SLOT(updateUnitLabels()));
        QObject::connect(leMarginRight, SIGNAL(textChanged(QString)), QG_DlgOptionsDrawing, SLOT(updatePaperPreview()));
        QObject::connect(leMarginLeft, SIGNAL(textChanged(QString)), QG_DlgOptionsDrawing, SLOT(updatePaperPreview()));
        QObject::connect(leMarginBottom, SIGNAL(textChanged(QString)), QG_DlgOptionsDrawing, SLOT(updatePaperPreview()));
        QObject::connect(leMarginTop, SIGNAL(textChanged(QString)), QG_DlgOptionsDrawing, SLOT(updatePaperPreview()));
        QObject::connect(lePaperWidth, SIGNAL(textChanged(QString)), QG_DlgOptionsDrawing, SLOT(updatePaperPreview()));
        QObject::connect(lePaperHeight, SIGNAL(textChanged(QString)), QG_DlgOptionsDrawing, SLOT(updatePaperPreview()));

        tabWidget->setCurrentIndex(0);
        cbDimFactor->setCurrentIndex(3);
        cbDimScale->setCurrentIndex(3);
        cbDimTih->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QG_DlgOptionsDrawing);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgOptionsDrawing)
    {
        QG_DlgOptionsDrawing->setWindowTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Drawing Preferences", nullptr));
        formatGroupBox->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Format", nullptr));
        lPageHeight->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "&Height:", nullptr));
        lPageWidth->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "&Width:", nullptr));
        orientGroupBox->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Orientation", nullptr));
        rbLandscape->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "&Landscape", nullptr));
        rbPortrait->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "P&ortrait", nullptr));
        marginsGroupBox->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Margins", nullptr));
#if QT_CONFIG(tooltip)
        leMarginLeft->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Left", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leMarginBottom->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Bottom", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leMarginRight->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Right", nullptr));
#endif // QT_CONFIG(tooltip)
        label_10->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Bottom", nullptr));
        label_7->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Top", nullptr));
        label_9->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Right", nullptr));
        label_8->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Left", nullptr));
#if QT_CONFIG(tooltip)
        leMarginTop->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Top", nullptr));
#endif // QT_CONFIG(tooltip)
        pagesNumGroupBox->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Number of pages", nullptr));
        lPagesNumH->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Horizontally:", nullptr));
        lPagesNumV->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Vertically:", nullptr));
        paperPreviewGroupBox->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Preview", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("QG_DlgOptionsDrawing", "&Paper", nullptr));
        bgUnit->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Main Unit", nullptr));
        lUnit->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "&Main drawing unit:", nullptr));
        bgLength->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Length", nullptr));
        lLengthFormat->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "&Format:", nullptr));
        lLengthPrecision->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "P&recision:", nullptr));
        bgLengthPreview->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Preview", nullptr));
        lLinear->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "linear", nullptr));
        bgAngle->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Angle", nullptr));
        lAngleFormat->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "F&ormat:", nullptr));
        lAnglePrecision->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Pre&cision:", nullptr));
        bgAnglePreview->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Preview", nullptr));
        lAngular->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "angular", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("QG_DlgOptionsDrawing", "&Units", nullptr));
        bgGrid->setTitle(QCoreApplication::translate("QG_DlgOptionsDrawing", "Grid Settings", nullptr));
        cbGridOn->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Show Grid", nullptr));
#if QT_CONFIG(tooltip)
        rbOrthogonalGrid->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Use orthogonal grid", nullptr));
#endif // QT_CONFIG(tooltip)
        rbOrthogonalGrid->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Orthogonal Grid", nullptr));
#if QT_CONFIG(tooltip)
        rbIsometricGrid->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Use isometric grid", nullptr));
#endif // QT_CONFIG(tooltip)
        rbIsometricGrid->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Isometric Grid", nullptr));
#if QT_CONFIG(tooltip)
        rbCrosshairLeft->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Left crosshair with isometric grid", nullptr));
#endif // QT_CONFIG(tooltip)
        rbCrosshairLeft->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Left", nullptr));
#if QT_CONFIG(tooltip)
        rbCrosshairTop->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Top crosshair with isometric grid", nullptr));
#endif // QT_CONFIG(tooltip)
        rbCrosshairTop->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Top", nullptr));
#if QT_CONFIG(tooltip)
        rbCrosshairRight->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Right crosshair with isometric grid", nullptr));
#endif // QT_CONFIG(tooltip)
        rbCrosshairRight->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Right", nullptr));
        lCrosshair->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Crosshair", nullptr));
        lXSpacing->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "X Spacing:", nullptr));
        cbXSpacing->setItemText(0, QCoreApplication::translate("QG_DlgOptionsDrawing", "auto", nullptr));

        lYSpacing->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Y Spacing:", nullptr));
        cbYSpacing->setItemText(0, QCoreApplication::translate("QG_DlgOptionsDrawing", "auto", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("QG_DlgOptionsDrawing", "&Grid", nullptr));
        label_5->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Text style:", nullptr));
        cbDimDSep->setItemText(0, QCoreApplication::translate("QG_DlgOptionsDrawing", "'.' (Period)", nullptr));
        cbDimDSep->setItemText(1, QCoreApplication::translate("QG_DlgOptionsDrawing", "',' (Comma)", nullptr));

        label_6->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Decimal separator:", nullptr));
        lDimUnit6->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));
        lDimUnit5->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));
        lDimLUnit->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Linear units:", nullptr));
        lDimClrT->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Color:", nullptr));
        lDimFactor->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Length Factor:", nullptr));

#if QT_CONFIG(tooltip)
        cbDimFactor->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Scale to multiply all dimension values.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lDimTsz->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Tick size:", nullptr));
        lDimUnit1->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));
        lDimAUnit->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Angular units:", nullptr));
        lDimTextHeight->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Text Height:", nullptr));
        lDimZin->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Linear zeros:", nullptr));

#if QT_CONFIG(tooltip)
        cbDimTsz->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Dimension Tick size. Set it to 0 will disable the dimension tick. Dimension arrow won't be drawn when dimension tick is enabled.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Format units", nullptr));

#if QT_CONFIG(tooltip)
        cbDimGap->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Distance gap around text</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)

#if QT_CONFIG(tooltip)
        cbDimScale->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Scale to multiply all dimension geometries.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Text size & position", nullptr));
        lDimScale->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "General Scale:", nullptr));


#if QT_CONFIG(tooltip)
        cbDimExe->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "Length to enlarge over dimension line", nullptr));
#endif // QT_CONFIG(tooltip)

#if QT_CONFIG(tooltip)
        cbDimAsz->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Dimension arrow size. <a name=\"result_box\"/>without effect when tick size <a name=\"result_box\"/>is other than 0</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lDimAsz->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Arrow size:", nullptr));
        lDimLwD->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Width:", nullptr));
        lDimUnit4->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));
        label->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Dimension lines, arrows & ticks", nullptr));
        lDimAZin->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Angular zeros:", nullptr));
        lDimClrD->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Color:", nullptr));
        lDimADec->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Angular precision:", nullptr));
        lDimExe->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Enlarge:", nullptr));
        lDimExo->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Offset:", nullptr));
        lDimDec->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Linear precision:", nullptr));
        cbDimTih->setItemText(0, QCoreApplication::translate("QG_DlgOptionsDrawing", "Aligned", nullptr));
        cbDimTih->setItemText(1, QCoreApplication::translate("QG_DlgOptionsDrawing", "Horizontal", nullptr));

#if QT_CONFIG(tooltip)
        cbDimTih->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Text alignment <a name=\"result_box\"/>relative to the dimension line.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lDimUnit2->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));
        lDimUnit3->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));

#if QT_CONFIG(tooltip)
        cbDimExo->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "<html><head/><body><p>Offset from origin point.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lDimUnit7->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "units", nullptr));
        lDimTih->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Text alignment:", nullptr));
        lDimGap->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Dimension line gap:", nullptr));
        label_3->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Extension lines", nullptr));
        cbDimFxLon->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Fixed length:", nullptr));
        lDimClrE->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Color:", nullptr));
        lDimLwE->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Width:", nullptr));
#if QT_CONFIG(tooltip)
        cbDimClrE->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbDimFxL->setToolTip(QCoreApplication::translate("QG_DlgOptionsDrawing", "fixed extension line length", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab4), QCoreApplication::translate("QG_DlgOptionsDrawing", "&Dimensions", nullptr));
        lSplineSegs->setText(QCoreApplication::translate("QG_DlgOptionsDrawing", "Number of line segments per spline patch:", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab5), QCoreApplication::translate("QG_DlgOptionsDrawing", "Splines", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgOptionsDrawing: public Ui_QG_DlgOptionsDrawing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGOPTIONSDRAWING_H
