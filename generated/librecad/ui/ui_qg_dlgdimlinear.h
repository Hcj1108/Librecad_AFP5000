/********************************************************************************
** Form generated from reading UI file 'qg_dlgdimlinear.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGDIMLINEAR_H
#define UI_QG_DLGDIMLINEAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include "qg_dimensionlabeleditor.h"
#include "qg_layerbox.h"
#include "qg_widgetpen.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgDimLinear
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *lLayer;
    QG_LayerBox *cbLayer;
    QG_WidgetPen *wPen;
    QVBoxLayout *vboxLayout2;
    QG_DimensionLabelEditor *wLabel;
    QGroupBox *bgGeometry;
    QHBoxLayout *hboxLayout2;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgDimLinear)
    {
        if (QG_DlgDimLinear->objectName().isEmpty())
            QG_DlgDimLinear->setObjectName(QString::fromUtf8("QG_DlgDimLinear"));
        QG_DlgDimLinear->resize(424, 218);
        QG_DlgDimLinear->setBaseSize(QSize(0, 0));
        QG_DlgDimLinear->setSizeGripEnabled(false);
        vboxLayout = new QVBoxLayout(QG_DlgDimLinear);
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
        lLayer = new QLabel(QG_DlgDimLinear);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgDimLinear);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgDimLinear);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        wLabel = new QG_DimensionLabelEditor(QG_DlgDimLinear);
        wLabel->setObjectName(QString::fromUtf8("wLabel"));

        vboxLayout2->addWidget(wLabel);

        bgGeometry = new QGroupBox(QG_DlgDimLinear);
        bgGeometry->setObjectName(QString::fromUtf8("bgGeometry"));
        hboxLayout2 = new QHBoxLayout(bgGeometry);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        lAngle = new QLabel(bgGeometry);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lAngle->sizePolicy().hasHeightForWidth());
        lAngle->setSizePolicy(sizePolicy2);
        lAngle->setMinimumSize(QSize(0, 19));
        lAngle->setFrameShape(QFrame::NoFrame);
        lAngle->setFrameShadow(QFrame::Plain);
        lAngle->setWordWrap(false);

        hboxLayout2->addWidget(lAngle);

        leAngle = new QLineEdit(bgGeometry);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy3);
        leAngle->setMinimumSize(QSize(0, 19));

        hboxLayout2->addWidget(leAngle);


        vboxLayout2->addWidget(bgGeometry);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgDimLinear);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(QG_DlgDimLinear);
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgDimLinear, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgDimLinear, SLOT(accept()));

        QMetaObject::connectSlotsByName(QG_DlgDimLinear);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgDimLinear)
    {
        QG_DlgDimLinear->setWindowTitle(QCoreApplication::translate("QG_DlgDimLinear", "Linear Dimension", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgDimLinear", "Layer:", nullptr));
        bgGeometry->setTitle(QCoreApplication::translate("QG_DlgDimLinear", "Geometry", nullptr));
        lAngle->setText(QCoreApplication::translate("QG_DlgDimLinear", "Angle:", nullptr));
        leAngle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_DlgDimLinear: public Ui_QG_DlgDimLinear {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGDIMLINEAR_H
