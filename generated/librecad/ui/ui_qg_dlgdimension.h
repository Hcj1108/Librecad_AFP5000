/********************************************************************************
** Form generated from reading UI file 'qg_dlgdimension.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGDIMENSION_H
#define UI_QG_DLGDIMENSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "qg_dimensionlabeleditor.h"
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgDimension
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *lLayer;
    QG_LayerBox *cbLayer;
    QG_WidgetPen *wPen;
    QG_DimensionLabelEditor *wLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgDimension)
    {
        if (QG_DlgDimension->objectName().isEmpty())
            QG_DlgDimension->setObjectName(QString::fromUtf8("QG_DlgDimension"));
        QG_DlgDimension->resize(424, 218);
        QG_DlgDimension->setBaseSize(QSize(0, 0));
        QG_DlgDimension->setSizeGripEnabled(false);
        vboxLayout = new QVBoxLayout(QG_DlgDimension);
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
        lLayer = new QLabel(QG_DlgDimension);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgDimension);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgDimension);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        wLabel = new QG_DimensionLabelEditor(QG_DlgDimension);
        wLabel->setObjectName(QString::fromUtf8("wLabel"));

        hboxLayout->addWidget(wLabel);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgDimension);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(QG_DlgDimension);
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgDimension, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgDimension, SLOT(accept()));

        QMetaObject::connectSlotsByName(QG_DlgDimension);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgDimension)
    {
        QG_DlgDimension->setWindowTitle(QCoreApplication::translate("QG_DlgDimension", "Dimension", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgDimension", "Layer:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgDimension: public Ui_QG_DlgDimension {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGDIMENSION_H
