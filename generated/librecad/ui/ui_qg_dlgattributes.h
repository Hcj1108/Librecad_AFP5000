/********************************************************************************
** Form generated from reading UI file 'qg_dlgattributes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGATTRIBUTES_H
#define UI_QG_DLGATTRIBUTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgAttributes
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *lLayer;
    QG_LayerBox *cbLayer;
    QG_WidgetPen *wPen;
    QCheckBox *cbBlockDeep;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgAttributes)
    {
        if (QG_DlgAttributes->objectName().isEmpty())
            QG_DlgAttributes->setObjectName(QString::fromUtf8("QG_DlgAttributes"));
        QG_DlgAttributes->resize(300, 192);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgAttributes->sizePolicy().hasHeightForWidth());
        QG_DlgAttributes->setSizePolicy(sizePolicy);
        QG_DlgAttributes->setMinimumSize(QSize(0, 0));
        vboxLayout = new QVBoxLayout(QG_DlgAttributes);
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
        lLayer = new QLabel(QG_DlgAttributes);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgAttributes);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgAttributes);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        sizePolicy.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy);

        vboxLayout1->addWidget(wPen);

        cbBlockDeep = new QCheckBox(QG_DlgAttributes);
        cbBlockDeep->setObjectName(QString::fromUtf8("cbBlockDeep"));

        vboxLayout1->addWidget(cbBlockDeep);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgAttributes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(QG_DlgAttributes);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgAttributes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgAttributes, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgAttributes);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgAttributes)
    {
        QG_DlgAttributes->setWindowTitle(QCoreApplication::translate("QG_DlgAttributes", "Attributes", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgAttributes", "Layer:", nullptr));
#if QT_CONFIG(tooltip)
        cbBlockDeep->setToolTip(QCoreApplication::translate("QG_DlgAttributes", "Apply attributes also to all sub-entities of selected INSERT.\n"
"This recursively modifies all entities of the Block itself.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbBlockDeep->setText(QCoreApplication::translate("QG_DlgAttributes", "Apply attributes Block-deep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgAttributes: public Ui_QG_DlgAttributes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGATTRIBUTES_H
