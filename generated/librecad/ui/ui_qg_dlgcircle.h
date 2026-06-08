/********************************************************************************
** Form generated from reading UI file 'qg_dlgcircle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGCIRCLE_H
#define UI_QG_DLGCIRCLE_H

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

class Ui_QG_DlgCircle
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
    QLabel *lEndX;
    QLineEdit *leRadius;
    QLabel *lCenterY;
    QLineEdit *leCenterY;
    QLabel *lCenterX;
    QLineEdit *leCenterX;
    QSpacerItem *spacer58;
    QSpacerItem *spacer61;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgCircle)
    {
        if (QG_DlgCircle->objectName().isEmpty())
            QG_DlgCircle->setObjectName(QString::fromUtf8("QG_DlgCircle"));
        QG_DlgCircle->resize(380, 192);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgCircle->sizePolicy().hasHeightForWidth());
        QG_DlgCircle->setSizePolicy(sizePolicy);
        QG_DlgCircle->setMinimumSize(QSize(300, 190));
        vboxLayout = new QVBoxLayout(QG_DlgCircle);
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
        lLayer = new QLabel(QG_DlgCircle);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgCircle);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgCircle);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgCircle);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lEndX = new QLabel(buttonGroup8);
        lEndX->setObjectName(QString::fromUtf8("lEndX"));
        lEndX->setWordWrap(false);

        gridLayout->addWidget(lEndX, 2, 0, 1, 1);

        leRadius = new QLineEdit(buttonGroup8);
        leRadius->setObjectName(QString::fromUtf8("leRadius"));
        leRadius->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leRadius, 2, 1, 1, 1);

        lCenterY = new QLabel(buttonGroup8);
        lCenterY->setObjectName(QString::fromUtf8("lCenterY"));
        lCenterY->setWordWrap(false);

        gridLayout->addWidget(lCenterY, 1, 0, 1, 1);

        leCenterY = new QLineEdit(buttonGroup8);
        leCenterY->setObjectName(QString::fromUtf8("leCenterY"));
        leCenterY->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leCenterY, 1, 1, 1, 1);

        lCenterX = new QLabel(buttonGroup8);
        lCenterX->setObjectName(QString::fromUtf8("lCenterX"));
        lCenterX->setWordWrap(false);

        gridLayout->addWidget(lCenterX, 0, 0, 1, 1);

        leCenterX = new QLineEdit(buttonGroup8);
        leCenterX->setObjectName(QString::fromUtf8("leCenterX"));
        leCenterX->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leCenterX, 0, 1, 1, 1);

        spacer58 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 3, 0, 1, 1);

        spacer61 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 3, 1, 1, 1);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgCircle);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(leCenterX, leCenterY);
        QWidget::setTabOrder(leCenterY, leRadius);

        retranslateUi(QG_DlgCircle);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgCircle, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgCircle, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgCircle);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgCircle)
    {
        QG_DlgCircle->setWindowTitle(QCoreApplication::translate("QG_DlgCircle", "Circle", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgCircle", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgCircle", "Geometry", nullptr));
        lEndX->setText(QCoreApplication::translate("QG_DlgCircle", "Radius:", nullptr));
        lCenterY->setText(QCoreApplication::translate("QG_DlgCircle", "Center (y):", nullptr));
        lCenterX->setText(QCoreApplication::translate("QG_DlgCircle", "Center (x):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgCircle: public Ui_QG_DlgCircle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGCIRCLE_H
