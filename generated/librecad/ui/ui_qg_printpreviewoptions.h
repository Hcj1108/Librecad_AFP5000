/********************************************************************************
** Form generated from reading UI file 'qg_printpreviewoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_PRINTPREVIEWOPTIONS_H
#define UI_QG_PRINTPREVIEWOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_PrintPreviewOptions
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *cbScale;
    QCheckBox *cFixed;
    QSpacerItem *horizontalSpacer;
    QToolButton *bScaleLineWidth;
    QToolButton *bBlackWhite;
    QToolButton *bCenter;
    QToolButton *bFit;
    QToolButton *bCalcPagesNum;
    QFrame *sep1_2;

    void setupUi(QWidget *Ui_PrintPreviewOptions)
    {
        if (Ui_PrintPreviewOptions->objectName().isEmpty())
            Ui_PrintPreviewOptions->setObjectName(QString::fromUtf8("Ui_PrintPreviewOptions"));
        Ui_PrintPreviewOptions->resize(350, 37);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_PrintPreviewOptions->sizePolicy().hasHeightForWidth());
        Ui_PrintPreviewOptions->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(Ui_PrintPreviewOptions);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 0, 1, 0);
        cbScale = new QComboBox(Ui_PrintPreviewOptions);
        cbScale->setObjectName(QString::fromUtf8("cbScale"));
        sizePolicy.setHeightForWidth(cbScale->sizePolicy().hasHeightForWidth());
        cbScale->setSizePolicy(sizePolicy);
        cbScale->setMinimumSize(QSize(110, 0));
        cbScale->setEditable(true);
        cbScale->setInsertPolicy(QComboBox::InsertAtTop);

        horizontalLayout->addWidget(cbScale);

        cFixed = new QCheckBox(Ui_PrintPreviewOptions);
        cFixed->setObjectName(QString::fromUtf8("cFixed"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cFixed->sizePolicy().hasHeightForWidth());
        cFixed->setSizePolicy(sizePolicy1);
        cFixed->setMinimumSize(QSize(25, 16));
        cFixed->setMaximumSize(QSize(54, 32));

        horizontalLayout->addWidget(cFixed);

        horizontalSpacer = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bScaleLineWidth = new QToolButton(Ui_PrintPreviewOptions);
        bScaleLineWidth->setObjectName(QString::fromUtf8("bScaleLineWidth"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bScaleLineWidth->sizePolicy().hasHeightForWidth());
        bScaleLineWidth->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/scaleLineWidth.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bScaleLineWidth->setIcon(icon);
        bScaleLineWidth->setIconSize(QSize(20, 20));
        bScaleLineWidth->setCheckable(true);

        horizontalLayout->addWidget(bScaleLineWidth);

        bBlackWhite = new QToolButton(Ui_PrintPreviewOptions);
        bBlackWhite->setObjectName(QString::fromUtf8("bBlackWhite"));
        sizePolicy2.setHeightForWidth(bBlackWhite->sizePolicy().hasHeightForWidth());
        bBlackWhite->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/black_n_white_mode.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bBlackWhite->setIcon(icon1);
        bBlackWhite->setIconSize(QSize(20, 20));
        bBlackWhite->setCheckable(true);

        horizontalLayout->addWidget(bBlackWhite);

        bCenter = new QToolButton(Ui_PrintPreviewOptions);
        bCenter->setObjectName(QString::fromUtf8("bCenter"));
        sizePolicy2.setHeightForWidth(bCenter->sizePolicy().hasHeightForWidth());
        bCenter->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/center_to_page.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bCenter->setIcon(icon2);
        bCenter->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(bCenter);

        bFit = new QToolButton(Ui_PrintPreviewOptions);
        bFit->setObjectName(QString::fromUtf8("bFit"));
        sizePolicy2.setHeightForWidth(bFit->sizePolicy().hasHeightForWidth());
        bFit->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/fit_to_page.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bFit->setIcon(icon3);
        bFit->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(bFit);

        bCalcPagesNum = new QToolButton(Ui_PrintPreviewOptions);
        bCalcPagesNum->setObjectName(QString::fromUtf8("bCalcPagesNum"));
        sizePolicy2.setHeightForWidth(bCalcPagesNum->sizePolicy().hasHeightForWidth());
        bCalcPagesNum->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/multi_pages.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bCalcPagesNum->setIcon(icon4);
        bCalcPagesNum->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(bCalcPagesNum);

        sep1_2 = new QFrame(Ui_PrintPreviewOptions);
        sep1_2->setObjectName(QString::fromUtf8("sep1_2"));
        sizePolicy2.setHeightForWidth(sep1_2->sizePolicy().hasHeightForWidth());
        sep1_2->setSizePolicy(sizePolicy2);
        sep1_2->setFrameShape(QFrame::VLine);
        sep1_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sep1_2);


        retranslateUi(Ui_PrintPreviewOptions);
        QObject::connect(bCenter, SIGNAL(clicked()), Ui_PrintPreviewOptions, SLOT(center()));
        QObject::connect(bScaleLineWidth, SIGNAL(toggled(bool)), Ui_PrintPreviewOptions, SLOT(setLineWidthScaling(bool)));
        QObject::connect(bBlackWhite, SIGNAL(toggled(bool)), Ui_PrintPreviewOptions, SLOT(setBlackWhite(bool)));
        QObject::connect(cbScale, SIGNAL(currentIndexChanged(QString)), Ui_PrintPreviewOptions, SLOT(scale(QString)));
        QObject::connect(bFit, SIGNAL(clicked()), Ui_PrintPreviewOptions, SLOT(fit()));
        QObject::connect(cFixed, SIGNAL(clicked(bool)), Ui_PrintPreviewOptions, SLOT(setScaleFixed(bool)));
        QObject::connect(bCalcPagesNum, SIGNAL(clicked()), Ui_PrintPreviewOptions, SLOT(calcPagesNum()));

        QMetaObject::connectSlotsByName(Ui_PrintPreviewOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_PrintPreviewOptions)
    {
        Ui_PrintPreviewOptions->setWindowTitle(QCoreApplication::translate("Ui_PrintPreviewOptions", "Print Preview Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_PrintPreviewOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cFixed->setToolTip(QCoreApplication::translate("Ui_PrintPreviewOptions", "<html><head/><body><p>Print Scale is locked to the current value</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cFixed->setText(QCoreApplication::translate("Ui_PrintPreviewOptions", "fixed", nullptr));
#if QT_CONFIG(tooltip)
        bScaleLineWidth->setToolTip(QCoreApplication::translate("Ui_PrintPreviewOptions", "Apply Print Scale to line width", nullptr));
#endif // QT_CONFIG(tooltip)
        bScaleLineWidth->setText(QString());
#if QT_CONFIG(tooltip)
        bBlackWhite->setToolTip(QCoreApplication::translate("Ui_PrintPreviewOptions", "Toggle Black / White mode", nullptr));
#endif // QT_CONFIG(tooltip)
        bBlackWhite->setText(QString());
#if QT_CONFIG(tooltip)
        bCenter->setToolTip(QCoreApplication::translate("Ui_PrintPreviewOptions", "Center to page", nullptr));
#endif // QT_CONFIG(tooltip)
        bCenter->setText(QString());
#if QT_CONFIG(tooltip)
        bFit->setToolTip(QCoreApplication::translate("Ui_PrintPreviewOptions", "Fit to page", nullptr));
#endif // QT_CONFIG(tooltip)
        bFit->setText(QString());
#if QT_CONFIG(tooltip)
        bCalcPagesNum->setToolTip(QCoreApplication::translate("Ui_PrintPreviewOptions", "Calculate number of pages needed to contain the drawing", nullptr));
#endif // QT_CONFIG(tooltip)
        bCalcPagesNum->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ui_PrintPreviewOptions: public Ui_Ui_PrintPreviewOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_PRINTPREVIEWOPTIONS_H
