/********************************************************************************
** Form generated from reading UI file 'qg_dlgline.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGLINE_H
#define UI_QG_DLGLINE_H

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

class Ui_QG_DlgLine
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
    QLineEdit *leEndX;
    QLineEdit *leEndY;
    QLabel *lEndY;
    QLabel *lStartY;
    QLineEdit *leStartY;
    QLabel *lStartX;
    QLineEdit *leStartX;
    QSpacerItem *spacer61;
    QSpacerItem *spacer58;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgLine)
    {
        if (QG_DlgLine->objectName().isEmpty())
            QG_DlgLine->setObjectName(QString::fromUtf8("QG_DlgLine"));
        QG_DlgLine->setEnabled(true);
        QG_DlgLine->resize(548, 270);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgLine->sizePolicy().hasHeightForWidth());
        QG_DlgLine->setSizePolicy(sizePolicy);
        QG_DlgLine->setMinimumSize(QSize(0, 0));
        vboxLayout = new QVBoxLayout(QG_DlgLine);
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
        lLayer = new QLabel(QG_DlgLine);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgLine);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgLine);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        sizePolicy.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy);
        wPen->setMinimumSize(QSize(230, 140));

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgLine);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lEndX = new QLabel(buttonGroup8);
        lEndX->setObjectName(QString::fromUtf8("lEndX"));
        lEndX->setWordWrap(false);

        gridLayout->addWidget(lEndX, 5, 0, 1, 1);

        leEndX = new QLineEdit(buttonGroup8);
        leEndX->setObjectName(QString::fromUtf8("leEndX"));
        leEndX->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leEndX, 5, 1, 1, 1);

        leEndY = new QLineEdit(buttonGroup8);
        leEndY->setObjectName(QString::fromUtf8("leEndY"));
        leEndY->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leEndY, 7, 1, 1, 1);

        lEndY = new QLabel(buttonGroup8);
        lEndY->setObjectName(QString::fromUtf8("lEndY"));
        lEndY->setWordWrap(false);

        gridLayout->addWidget(lEndY, 7, 0, 1, 1);

        lStartY = new QLabel(buttonGroup8);
        lStartY->setObjectName(QString::fromUtf8("lStartY"));
        lStartY->setWordWrap(false);

        gridLayout->addWidget(lStartY, 3, 0, 1, 1);

        leStartY = new QLineEdit(buttonGroup8);
        leStartY->setObjectName(QString::fromUtf8("leStartY"));
        leStartY->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leStartY, 3, 1, 1, 1);

        lStartX = new QLabel(buttonGroup8);
        lStartX->setObjectName(QString::fromUtf8("lStartX"));
        lStartX->setWordWrap(false);

        gridLayout->addWidget(lStartX, 1, 0, 1, 1);

        leStartX = new QLineEdit(buttonGroup8);
        leStartX->setObjectName(QString::fromUtf8("leStartX"));
        leStartX->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leStartX, 1, 1, 1, 1);

        spacer61 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 8, 1, 1, 1);

        spacer58 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 8, 0, 1, 1);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgLine);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(leStartX, leStartY);
        QWidget::setTabOrder(leStartY, leEndX);
        QWidget::setTabOrder(leEndX, leEndY);

        retranslateUi(QG_DlgLine);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgLine, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgLine, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgLine);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgLine)
    {
        QG_DlgLine->setWindowTitle(QCoreApplication::translate("QG_DlgLine", "Line", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgLine", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgLine", "Geometry", nullptr));
        lEndX->setText(QCoreApplication::translate("QG_DlgLine", "End point (x):", nullptr));
        lEndY->setText(QCoreApplication::translate("QG_DlgLine", "End point (y):", nullptr));
        lStartY->setText(QCoreApplication::translate("QG_DlgLine", "Start point (y):", nullptr));
        lStartX->setText(QCoreApplication::translate("QG_DlgLine", "Start point (x):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgLine: public Ui_QG_DlgLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGLINE_H
