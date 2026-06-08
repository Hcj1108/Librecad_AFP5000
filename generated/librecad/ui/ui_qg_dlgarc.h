/********************************************************************************
** Form generated from reading UI file 'qg_dlgarc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGARC_H
#define UI_QG_DLGARC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_QG_DlgArc
{
public:
    QVBoxLayout *gfdgf;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
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
    QLabel *lAngle1;
    QLineEdit *leAngle1;
    QLineEdit *leAngle2;
    QLabel *lAngle2;
    QSpacerItem *spacer58;
    QSpacerItem *spacer61;
    QCheckBox *cbReversed;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgArc)
    {
        if (QG_DlgArc->objectName().isEmpty())
            QG_DlgArc->setObjectName(QString::fromUtf8("QG_DlgArc"));
        QG_DlgArc->resize(389, 251);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgArc->sizePolicy().hasHeightForWidth());
        QG_DlgArc->setSizePolicy(sizePolicy);
        QG_DlgArc->setMinimumSize(QSize(300, 190));
        gfdgf = new QVBoxLayout(QG_DlgArc);
        gfdgf->setSpacing(6);
        gfdgf->setContentsMargins(11, 11, 11, 11);
        gfdgf->setObjectName(QString::fromUtf8("gfdgf"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        lLayer = new QLabel(QG_DlgArc);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgArc);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgArc);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout);

        buttonGroup8 = new QGroupBox(QG_DlgArc);
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

        lAngle1 = new QLabel(buttonGroup8);
        lAngle1->setObjectName(QString::fromUtf8("lAngle1"));
        lAngle1->setWordWrap(false);

        gridLayout->addWidget(lAngle1, 3, 0, 1, 1);

        leAngle1 = new QLineEdit(buttonGroup8);
        leAngle1->setObjectName(QString::fromUtf8("leAngle1"));
        leAngle1->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leAngle1, 3, 1, 1, 1);

        leAngle2 = new QLineEdit(buttonGroup8);
        leAngle2->setObjectName(QString::fromUtf8("leAngle2"));
        leAngle2->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leAngle2, 4, 1, 1, 1);

        lAngle2 = new QLabel(buttonGroup8);
        lAngle2->setObjectName(QString::fromUtf8("lAngle2"));
        lAngle2->setWordWrap(false);

        gridLayout->addWidget(lAngle2, 4, 0, 1, 1);

        spacer58 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 6, 0, 1, 1);

        spacer61 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 6, 1, 1, 1);

        cbReversed = new QCheckBox(buttonGroup8);
        cbReversed->setObjectName(QString::fromUtf8("cbReversed"));

        gridLayout->addWidget(cbReversed, 5, 0, 1, 2);


        hboxLayout->addWidget(buttonGroup8);


        gfdgf->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgArc);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gfdgf->addWidget(buttonBox);

        QWidget::setTabOrder(leCenterX, leCenterY);
        QWidget::setTabOrder(leCenterY, leRadius);
        QWidget::setTabOrder(leRadius, leAngle1);
        QWidget::setTabOrder(leAngle1, leAngle2);
        QWidget::setTabOrder(leAngle2, cbReversed);

        retranslateUi(QG_DlgArc);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgArc, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgArc, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgArc);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgArc)
    {
        QG_DlgArc->setWindowTitle(QCoreApplication::translate("QG_DlgArc", "Arc", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgArc", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgArc", "Geometry", nullptr));
        lEndX->setText(QCoreApplication::translate("QG_DlgArc", "Radius:", nullptr));
        lCenterY->setText(QCoreApplication::translate("QG_DlgArc", "Center (y):", nullptr));
        lCenterX->setText(QCoreApplication::translate("QG_DlgArc", "Center (x):", nullptr));
        lAngle1->setText(QCoreApplication::translate("QG_DlgArc", "Start Angle:", nullptr));
        lAngle2->setText(QCoreApplication::translate("QG_DlgArc", "End Angle:", nullptr));
        cbReversed->setText(QCoreApplication::translate("QG_DlgArc", "Reversed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgArc: public Ui_QG_DlgArc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGARC_H
