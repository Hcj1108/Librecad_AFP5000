/********************************************************************************
** Form generated from reading UI file 'qg_dlginsert.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGINSERT_H
#define UI_QG_DLGINSERT_H

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

class Ui_QG_DlgInsert
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
    QSpacerItem *spacer61;
    QSpacerItem *spacer58;
    QLineEdit *leInsertionPointY;
    QLineEdit *leInsertionPointX;
    QLabel *lInsertionPointX;
    QLabel *lInsertionPointY;
    QLineEdit *leScaleX;
    QLabel *lFactorX;
    QLineEdit *leScaleY;
    QLabel *lFactorY;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QLabel *lRows;
    QLineEdit *leRows;
    QLineEdit *leCols;
    QLabel *lCols;
    QLabel *lRowSpacing;
    QLineEdit *leRowSpacing;
    QLineEdit *leColSpacing;
    QLabel *lColSpacing;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgInsert)
    {
        if (QG_DlgInsert->objectName().isEmpty())
            QG_DlgInsert->setObjectName(QString::fromUtf8("QG_DlgInsert"));
        QG_DlgInsert->resize(457, 310);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgInsert->sizePolicy().hasHeightForWidth());
        QG_DlgInsert->setSizePolicy(sizePolicy);
        QG_DlgInsert->setMinimumSize(QSize(300, 190));
        vboxLayout = new QVBoxLayout(QG_DlgInsert);
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
        lLayer = new QLabel(QG_DlgInsert);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgInsert);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgInsert);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgInsert);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacer61 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 8, 1, 1, 1);

        spacer58 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 8, 0, 1, 1);

        leInsertionPointY = new QLineEdit(buttonGroup8);
        leInsertionPointY->setObjectName(QString::fromUtf8("leInsertionPointY"));
        leInsertionPointY->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leInsertionPointY, 1, 1, 1, 1);

        leInsertionPointX = new QLineEdit(buttonGroup8);
        leInsertionPointX->setObjectName(QString::fromUtf8("leInsertionPointX"));
        leInsertionPointX->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leInsertionPointX, 0, 1, 1, 1);

        lInsertionPointX = new QLabel(buttonGroup8);
        lInsertionPointX->setObjectName(QString::fromUtf8("lInsertionPointX"));
        lInsertionPointX->setWordWrap(false);

        gridLayout->addWidget(lInsertionPointX, 0, 0, 1, 1);

        lInsertionPointY = new QLabel(buttonGroup8);
        lInsertionPointY->setObjectName(QString::fromUtf8("lInsertionPointY"));
        lInsertionPointY->setWordWrap(false);

        gridLayout->addWidget(lInsertionPointY, 1, 0, 1, 1);

        leScaleX = new QLineEdit(buttonGroup8);
        leScaleX->setObjectName(QString::fromUtf8("leScaleX"));
        leScaleX->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leScaleX, 2, 1, 1, 1);

        lFactorX = new QLabel(buttonGroup8);
        lFactorX->setObjectName(QString::fromUtf8("lFactorX"));
        lFactorX->setWordWrap(false);

        gridLayout->addWidget(lFactorX, 2, 0, 1, 1);

        leScaleY = new QLineEdit(buttonGroup8);
        leScaleY->setObjectName(QString::fromUtf8("leScaleY"));
        leScaleY->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leScaleY, 3, 1, 1, 1);

        lFactorY = new QLabel(buttonGroup8);
        lFactorY->setObjectName(QString::fromUtf8("lFactorY"));
        lFactorY->setWordWrap(false);

        gridLayout->addWidget(lFactorY, 3, 0, 1, 1);

        lAngle = new QLabel(buttonGroup8);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        gridLayout->addWidget(lAngle, 4, 0, 1, 1);

        leAngle = new QLineEdit(buttonGroup8);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        leAngle->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leAngle, 4, 1, 1, 1);

        lRows = new QLabel(buttonGroup8);
        lRows->setObjectName(QString::fromUtf8("lRows"));
        lRows->setWordWrap(false);

        gridLayout->addWidget(lRows, 5, 0, 1, 1);

        leRows = new QLineEdit(buttonGroup8);
        leRows->setObjectName(QString::fromUtf8("leRows"));
        leRows->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leRows, 5, 1, 1, 1);

        leCols = new QLineEdit(buttonGroup8);
        leCols->setObjectName(QString::fromUtf8("leCols"));
        leCols->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leCols, 6, 1, 1, 1);

        lCols = new QLabel(buttonGroup8);
        lCols->setObjectName(QString::fromUtf8("lCols"));
        lCols->setWordWrap(false);

        gridLayout->addWidget(lCols, 6, 0, 1, 1);

        lRowSpacing = new QLabel(buttonGroup8);
        lRowSpacing->setObjectName(QString::fromUtf8("lRowSpacing"));
        lRowSpacing->setWordWrap(false);

        gridLayout->addWidget(lRowSpacing, 7, 0, 1, 1);

        leRowSpacing = new QLineEdit(buttonGroup8);
        leRowSpacing->setObjectName(QString::fromUtf8("leRowSpacing"));
        leRowSpacing->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leRowSpacing, 7, 1, 1, 1);

        leColSpacing = new QLineEdit(buttonGroup8);
        leColSpacing->setObjectName(QString::fromUtf8("leColSpacing"));
        leColSpacing->setMinimumSize(QSize(64, 0));

        gridLayout->addWidget(leColSpacing, 8, 1, 1, 1);

        lColSpacing = new QLabel(buttonGroup8);
        lColSpacing->setObjectName(QString::fromUtf8("lColSpacing"));
        lColSpacing->setWordWrap(false);

        gridLayout->addWidget(lColSpacing, 8, 0, 1, 1);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgInsert);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(leInsertionPointX, leInsertionPointY);
        QWidget::setTabOrder(leInsertionPointY, leScaleX);
        QWidget::setTabOrder(leScaleX, leScaleY);
        QWidget::setTabOrder(leScaleY, leAngle);
        QWidget::setTabOrder(leAngle, leRows);
        QWidget::setTabOrder(leRows, leCols);
        QWidget::setTabOrder(leCols, leRowSpacing);
        QWidget::setTabOrder(leRowSpacing, leColSpacing);

        retranslateUi(QG_DlgInsert);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgInsert, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgInsert, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgInsert);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgInsert)
    {
        QG_DlgInsert->setWindowTitle(QCoreApplication::translate("QG_DlgInsert", "Insert", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgInsert", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgInsert", "Geometry", nullptr));
        lInsertionPointX->setText(QCoreApplication::translate("QG_DlgInsert", "Insertion point (x):", nullptr));
        lInsertionPointY->setText(QCoreApplication::translate("QG_DlgInsert", "Insertion point (y):", nullptr));
        lFactorX->setText(QCoreApplication::translate("QG_DlgInsert", "Scale X:", nullptr));
        lFactorY->setText(QCoreApplication::translate("QG_DlgInsert", "Scale Y:", nullptr));
        lAngle->setText(QCoreApplication::translate("QG_DlgInsert", "Angle:", nullptr));
        lRows->setText(QCoreApplication::translate("QG_DlgInsert", "Rows:", nullptr));
        lCols->setText(QCoreApplication::translate("QG_DlgInsert", "Columns:", nullptr));
        lRowSpacing->setText(QCoreApplication::translate("QG_DlgInsert", "Row Spacing:", nullptr));
        lColSpacing->setText(QCoreApplication::translate("QG_DlgInsert", "Column Spacing:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgInsert: public Ui_QG_DlgInsert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGINSERT_H
