/********************************************************************************
** Form generated from reading UI file 'qg_layerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LAYERDIALOG_H
#define UI_QG_LAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_LayerDialog
{
public:
    QGridLayout *gridLayout;
    QCheckBox *cbConstructionLayer;
    QLabel *lName;
    QDialogButtonBox *buttonBox;
    QG_WidgetPen *wPen;
    QSpacerItem *spacer87;
    QLineEdit *leName;

    void setupUi(QDialog *QG_LayerDialog)
    {
        if (QG_LayerDialog->objectName().isEmpty())
            QG_LayerDialog->setObjectName(QString::fromUtf8("QG_LayerDialog"));
        QG_LayerDialog->resize(253, 203);
        QG_LayerDialog->setBaseSize(QSize(0, 0));
        QG_LayerDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(QG_LayerDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbConstructionLayer = new QCheckBox(QG_LayerDialog);
        cbConstructionLayer->setObjectName(QString::fromUtf8("cbConstructionLayer"));

        gridLayout->addWidget(cbConstructionLayer, 1, 2, 1, 1);

        lName = new QLabel(QG_LayerDialog);
        lName->setObjectName(QString::fromUtf8("lName"));
        lName->setFrameShape(QFrame::NoFrame);
        lName->setFrameShadow(QFrame::Plain);
        lName->setWordWrap(false);

        gridLayout->addWidget(lName, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QG_LayerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);

        wPen = new QG_WidgetPen(QG_LayerDialog);
        wPen->setObjectName(QString::fromUtf8("wPen"));

        gridLayout->addWidget(wPen, 2, 0, 1, 3);

        spacer87 = new QSpacerItem(5, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacer87, 0, 1, 1, 1);

        leName = new QLineEdit(QG_LayerDialog);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 2, 1, 1);


        retranslateUi(QG_LayerDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_LayerDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_LayerDialog, SLOT(validate()));

        QMetaObject::connectSlotsByName(QG_LayerDialog);
    } // setupUi

    void retranslateUi(QDialog *QG_LayerDialog)
    {
        QG_LayerDialog->setWindowTitle(QCoreApplication::translate("QG_LayerDialog", "Layer Settings", nullptr));
#if QT_CONFIG(tooltip)
        cbConstructionLayer->setToolTip(QCoreApplication::translate("QG_LayerDialog", "A Construction Layer has entities of infinite straight lines intended to be used for geometric construction.\n"
"The contents of a Construction Layer should not appear in printout.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbConstructionLayer->setText(QCoreApplication::translate("QG_LayerDialog", "Construction Layer", nullptr));
        lName->setText(QCoreApplication::translate("QG_LayerDialog", "Layer Name:", nullptr));
        leName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_LayerDialog: public Ui_QG_LayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LAYERDIALOG_H
