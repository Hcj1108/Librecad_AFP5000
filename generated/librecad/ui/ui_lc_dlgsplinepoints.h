/********************************************************************************
** Form generated from reading UI file 'lc_dlgsplinepoints.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LC_DLGSPLINEPOINTS_H
#define UI_LC_DLGSPLINEPOINTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_DlgSplinePoints
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *lLayer;
    QG_LayerBox *cbLayer;
    QG_WidgetPen *wPen;
    QGroupBox *buttonGroup8;
    QGridLayout *gridLayout;
    QCheckBox *cbClosed;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbSplinePoints;
    QRadioButton *rbControlPoints;
    QTableView *tvPoints;
    QSpacerItem *spacer58;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgSplinePoints)
    {
        if (DlgSplinePoints->objectName().isEmpty())
            DlgSplinePoints->setObjectName(QString::fromUtf8("DlgSplinePoints"));
        DlgSplinePoints->resize(406, 320);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgSplinePoints->sizePolicy().hasHeightForWidth());
        DlgSplinePoints->setSizePolicy(sizePolicy);
        DlgSplinePoints->setMinimumSize(QSize(400, 320));
        DlgSplinePoints->setModal(true);
        vboxLayout = new QVBoxLayout(DlgSplinePoints);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        lLayer = new QLabel(DlgSplinePoints);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(DlgSplinePoints);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(DlgSplinePoints);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(DlgSplinePoints);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonGroup8->sizePolicy().hasHeightForWidth());
        buttonGroup8->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbClosed = new QCheckBox(buttonGroup8);
        cbClosed->setObjectName(QString::fromUtf8("cbClosed"));

        gridLayout->addWidget(cbClosed, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbSplinePoints = new QRadioButton(buttonGroup8);
        rbSplinePoints->setObjectName(QString::fromUtf8("rbSplinePoints"));
        rbSplinePoints->setChecked(true);

        horizontalLayout_2->addWidget(rbSplinePoints);

        rbControlPoints = new QRadioButton(buttonGroup8);
        rbControlPoints->setObjectName(QString::fromUtf8("rbControlPoints"));

        horizontalLayout_2->addWidget(rbControlPoints);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        tvPoints = new QTableView(buttonGroup8);
        tvPoints->setObjectName(QString::fromUtf8("tvPoints"));
        tvPoints->setMinimumSize(QSize(320, 240));
        tvPoints->setTextElideMode(Qt::ElideRight);
        tvPoints->horizontalHeader()->setCascadingSectionResizes(false);

        gridLayout->addWidget(tvPoints, 2, 0, 1, 2);

        spacer58 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 3, 0, 1, 1);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(DlgSplinePoints);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(DlgSplinePoints);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgSplinePoints, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgSplinePoints, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgSplinePoints);
    } // setupUi

    void retranslateUi(QDialog *DlgSplinePoints)
    {
        DlgSplinePoints->setWindowTitle(QCoreApplication::translate("DlgSplinePoints", "SplinePoints", nullptr));
        lLayer->setText(QCoreApplication::translate("DlgSplinePoints", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("DlgSplinePoints", "Geometry", nullptr));
        cbClosed->setText(QCoreApplication::translate("DlgSplinePoints", "Closed", nullptr));
        rbSplinePoints->setText(QCoreApplication::translate("DlgSplinePoints", "Spline Points", nullptr));
        rbControlPoints->setText(QCoreApplication::translate("DlgSplinePoints", "Control Points", nullptr));
#if QT_CONFIG(tooltip)
        tvPoints->setToolTip(QCoreApplication::translate("DlgSplinePoints", "Points on Spline", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tvPoints->setWhatsThis(QCoreApplication::translate("DlgSplinePoints", "Points on Spline", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class DlgSplinePoints: public Ui_DlgSplinePoints {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LC_DLGSPLINEPOINTS_H
