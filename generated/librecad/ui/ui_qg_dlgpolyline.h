/********************************************************************************
** Form generated from reading UI file 'qg_dlgpolyline.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGPOLYLINE_H
#define UI_QG_DLGPOLYLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgPolyline
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
    QSpacerItem *spacer58;
    QSpacerItem *spacer61;
    QCheckBox *cbClosed;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgPolyline)
    {
        if (QG_DlgPolyline->objectName().isEmpty())
            QG_DlgPolyline->setObjectName(QString::fromUtf8("QG_DlgPolyline"));
        QG_DlgPolyline->resize(406, 234);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgPolyline->sizePolicy().hasHeightForWidth());
        QG_DlgPolyline->setSizePolicy(sizePolicy);
        QG_DlgPolyline->setMinimumSize(QSize(300, 190));
        vboxLayout = new QVBoxLayout(QG_DlgPolyline);
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
        lLayer = new QLabel(QG_DlgPolyline);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgPolyline);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgPolyline);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgPolyline);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonGroup8->sizePolicy().hasHeightForWidth());
        buttonGroup8->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacer58 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 1, 0, 1, 1);

        spacer61 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 1, 1, 1, 1);

        cbClosed = new QCheckBox(buttonGroup8);
        cbClosed->setObjectName(QString::fromUtf8("cbClosed"));

        gridLayout->addWidget(cbClosed, 0, 0, 1, 2);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgPolyline);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(QG_DlgPolyline);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgPolyline, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgPolyline, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgPolyline);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgPolyline)
    {
        QG_DlgPolyline->setWindowTitle(QCoreApplication::translate("QG_DlgPolyline", "Polyline", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgPolyline", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgPolyline", "Geometry", nullptr));
        cbClosed->setText(QCoreApplication::translate("QG_DlgPolyline", "Closed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgPolyline: public Ui_QG_DlgPolyline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGPOLYLINE_H
