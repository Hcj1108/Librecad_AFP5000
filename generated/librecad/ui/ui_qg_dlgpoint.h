/********************************************************************************
** Form generated from reading UI file 'qg_dlgpoint.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGPOINT_H
#define UI_QG_DLGPOINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgPoint
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
    QLabel *lPosY;
    QLineEdit *lePosY;
    QLabel *lPosX;
    QLineEdit *lePosX;
    QSpacerItem *spacer61;
    QSpacerItem *spacer58;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgPoint)
    {
        if (QG_DlgPoint->objectName().isEmpty())
            QG_DlgPoint->setObjectName(QString::fromUtf8("QG_DlgPoint"));
        QG_DlgPoint->resize(457, 192);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgPoint->sizePolicy().hasHeightForWidth());
        QG_DlgPoint->setSizePolicy(sizePolicy);
        QG_DlgPoint->setMinimumSize(QSize(300, 190));
        vboxLayout = new QVBoxLayout(QG_DlgPoint);
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
        lLayer = new QLabel(QG_DlgPoint);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgPoint);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgPoint);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgPoint);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lPosY = new QLabel(buttonGroup8);
        lPosY->setObjectName(QString::fromUtf8("lPosY"));
        lPosY->setWordWrap(false);

        gridLayout->addWidget(lPosY, 3, 0, 1, 1);

        lePosY = new QLineEdit(buttonGroup8);
        lePosY->setObjectName(QString::fromUtf8("lePosY"));
        lePosY->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(lePosY, 3, 1, 1, 1);

        lPosX = new QLabel(buttonGroup8);
        lPosX->setObjectName(QString::fromUtf8("lPosX"));
        lPosX->setWordWrap(false);

        gridLayout->addWidget(lPosX, 1, 0, 1, 1);

        lePosX = new QLineEdit(buttonGroup8);
        lePosX->setObjectName(QString::fromUtf8("lePosX"));
        lePosX->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(lePosX, 1, 1, 1, 1);

        spacer61 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 8, 1, 1, 1);

        spacer58 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 8, 0, 1, 1);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgPoint);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(lePosX, lePosY);

        retranslateUi(QG_DlgPoint);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgPoint, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgPoint, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgPoint);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgPoint)
    {
        QG_DlgPoint->setWindowTitle(QCoreApplication::translate("QG_DlgPoint", "Point", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgPoint", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgPoint", "Geometry", nullptr));
        lPosY->setText(QCoreApplication::translate("QG_DlgPoint", "Position (y):", nullptr));
        lPosX->setText(QCoreApplication::translate("QG_DlgPoint", "Position (x):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgPoint: public Ui_QG_DlgPoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGPOINT_H
