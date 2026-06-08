/********************************************************************************
** Form generated from reading UI file 'qg_snapmiddleoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_SNAPMIDDLEOPTIONS_H
#define UI_QG_SNAPMIDDLEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "rs_circle.h"
#include "rs_settings.h"

QT_BEGIN_NAMESPACE

class Ui_Ui_SnapMiddleOptions
{
public:
    QLabel *lDist;
    QSpinBox *sbMiddlePoints;

    void setupUi(QWidget *Ui_SnapMiddleOptions)
    {
        if (Ui_SnapMiddleOptions->objectName().isEmpty())
            Ui_SnapMiddleOptions->setObjectName(QString::fromUtf8("Ui_SnapMiddleOptions"));
        Ui_SnapMiddleOptions->resize(135, 24);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_SnapMiddleOptions->sizePolicy().hasHeightForWidth());
        Ui_SnapMiddleOptions->setSizePolicy(sizePolicy);
        Ui_SnapMiddleOptions->setMinimumSize(QSize(135, 22));
        Ui_SnapMiddleOptions->setMaximumSize(QSize(155, 24));
        Ui_SnapMiddleOptions->setMouseTracking(true);
        lDist = new QLabel(Ui_SnapMiddleOptions);
        lDist->setObjectName(QString::fromUtf8("lDist"));
        lDist->setGeometry(QRect(1, 1, 101, 22));
        lDist->setWordWrap(false);
        sbMiddlePoints = new QSpinBox(Ui_SnapMiddleOptions);
        sbMiddlePoints->setObjectName(QString::fromUtf8("sbMiddlePoints"));
        sbMiddlePoints->setGeometry(QRect(93, 1, 40, 22));
        sbMiddlePoints->setMinimum(1);
        sbMiddlePoints->setValue(1);

        retranslateUi(Ui_SnapMiddleOptions);

        QMetaObject::connectSlotsByName(Ui_SnapMiddleOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_SnapMiddleOptions)
    {
        Ui_SnapMiddleOptions->setWindowTitle(QCoreApplication::translate("Ui_SnapMiddleOptions", "Snap Distance Options", nullptr));
        lDist->setText(QCoreApplication::translate("Ui_SnapMiddleOptions", "Middle Points:", nullptr));
#if QT_CONFIG(tooltip)
        sbMiddlePoints->setToolTip(QCoreApplication::translate("Ui_SnapMiddleOptions", "Number of equidistant division points", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_SnapMiddleOptions: public Ui_Ui_SnapMiddleOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_SNAPMIDDLEOPTIONS_H
