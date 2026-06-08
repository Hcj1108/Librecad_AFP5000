/********************************************************************************
** Form generated from reading UI file 'qg_dlgellipse.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGELLIPSE_H
#define UI_QG_DLGELLIPSE_H

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

class Ui_QG_DlgEllipse
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
    QLabel *lCenterY;
    QLineEdit *leCenterY;
    QLabel *lCenterX;
    QLineEdit *leCenterX;
    QSpacerItem *spacer58;
    QSpacerItem *spacer61;
    QLabel *lAngle2;
    QLineEdit *leAngle2;
    QLineEdit *leAngle1;
    QLabel *lAngle1;
    QLabel *lRotation;
    QLineEdit *leRotation;
    QLineEdit *leMinor;
    QLabel *lMinor;
    QLabel *lMajor;
    QLineEdit *leMajor;
    QCheckBox *cbReversed;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgEllipse)
    {
        if (QG_DlgEllipse->objectName().isEmpty())
            QG_DlgEllipse->setObjectName(QString::fromUtf8("QG_DlgEllipse"));
        QG_DlgEllipse->resize(394, 307);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgEllipse->sizePolicy().hasHeightForWidth());
        QG_DlgEllipse->setSizePolicy(sizePolicy);
        QG_DlgEllipse->setMinimumSize(QSize(300, 190));
        vboxLayout = new QVBoxLayout(QG_DlgEllipse);
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
        lLayer = new QLabel(QG_DlgEllipse);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgEllipse);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgEllipse);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgEllipse);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        gridLayout->addItem(spacer58, 8, 0, 1, 1);

        spacer61 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 8, 1, 1, 1);

        lAngle2 = new QLabel(buttonGroup8);
        lAngle2->setObjectName(QString::fromUtf8("lAngle2"));
        lAngle2->setWordWrap(false);

        gridLayout->addWidget(lAngle2, 6, 0, 1, 1);

        leAngle2 = new QLineEdit(buttonGroup8);
        leAngle2->setObjectName(QString::fromUtf8("leAngle2"));
        leAngle2->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leAngle2, 6, 1, 1, 1);

        leAngle1 = new QLineEdit(buttonGroup8);
        leAngle1->setObjectName(QString::fromUtf8("leAngle1"));
        leAngle1->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leAngle1, 5, 1, 1, 1);

        lAngle1 = new QLabel(buttonGroup8);
        lAngle1->setObjectName(QString::fromUtf8("lAngle1"));
        lAngle1->setWordWrap(false);

        gridLayout->addWidget(lAngle1, 5, 0, 1, 1);

        lRotation = new QLabel(buttonGroup8);
        lRotation->setObjectName(QString::fromUtf8("lRotation"));
        lRotation->setWordWrap(false);

        gridLayout->addWidget(lRotation, 4, 0, 1, 1);

        leRotation = new QLineEdit(buttonGroup8);
        leRotation->setObjectName(QString::fromUtf8("leRotation"));
        leRotation->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leRotation, 4, 1, 1, 1);

        leMinor = new QLineEdit(buttonGroup8);
        leMinor->setObjectName(QString::fromUtf8("leMinor"));
        leMinor->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leMinor, 3, 1, 1, 1);

        lMinor = new QLabel(buttonGroup8);
        lMinor->setObjectName(QString::fromUtf8("lMinor"));
        lMinor->setWordWrap(false);

        gridLayout->addWidget(lMinor, 3, 0, 1, 1);

        lMajor = new QLabel(buttonGroup8);
        lMajor->setObjectName(QString::fromUtf8("lMajor"));
        lMajor->setWordWrap(false);

        gridLayout->addWidget(lMajor, 2, 0, 1, 1);

        leMajor = new QLineEdit(buttonGroup8);
        leMajor->setObjectName(QString::fromUtf8("leMajor"));
        leMajor->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leMajor, 2, 1, 1, 1);

        cbReversed = new QCheckBox(buttonGroup8);
        cbReversed->setObjectName(QString::fromUtf8("cbReversed"));

        gridLayout->addWidget(cbReversed, 7, 0, 1, 2);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgEllipse);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(leCenterX, leCenterY);
        QWidget::setTabOrder(leCenterY, leMajor);
        QWidget::setTabOrder(leMajor, leMinor);
        QWidget::setTabOrder(leMinor, leRotation);
        QWidget::setTabOrder(leRotation, leAngle1);
        QWidget::setTabOrder(leAngle1, leAngle2);
        QWidget::setTabOrder(leAngle2, cbReversed);

        retranslateUi(QG_DlgEllipse);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgEllipse, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgEllipse, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgEllipse);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgEllipse)
    {
        QG_DlgEllipse->setWindowTitle(QCoreApplication::translate("QG_DlgEllipse", "Ellipse", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgEllipse", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgEllipse", "Geometry", nullptr));
        lCenterY->setText(QCoreApplication::translate("QG_DlgEllipse", "Center (y):", nullptr));
        lCenterX->setText(QCoreApplication::translate("QG_DlgEllipse", "Center (x):", nullptr));
        lAngle2->setText(QCoreApplication::translate("QG_DlgEllipse", "End Angle:", nullptr));
        lAngle1->setText(QCoreApplication::translate("QG_DlgEllipse", "Start Angle:", nullptr));
        lRotation->setText(QCoreApplication::translate("QG_DlgEllipse", "Rotation:", nullptr));
        lMinor->setText(QCoreApplication::translate("QG_DlgEllipse", "Minor:", nullptr));
        lMajor->setText(QCoreApplication::translate("QG_DlgEllipse", "Major:", nullptr));
        cbReversed->setText(QCoreApplication::translate("QG_DlgEllipse", "Reversed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgEllipse: public Ui_QG_DlgEllipse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGELLIPSE_H
