/********************************************************************************
** Form generated from reading UI file 'qg_dlgimage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGIMAGE_H
#define UI_QG_DLGIMAGE_H

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

class Ui_QG_DlgImage
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
    QLabel *lWidth;
    QLineEdit *lePath;
    QLineEdit *leInsertY;
    QLabel *lHeight;
    QLabel *lInsertX;
    QLabel *lScale;
    QSpacerItem *spacer58;
    QLineEdit *leSize;
    QLabel *lSize;
    QLineEdit *leInsertX;
    QLabel *lPath;
    QSpacerItem *spacer61;
    QLabel *lInsertY;
    QLineEdit *leScale;
    QLabel *lAngle;
    QLineEdit *leWidth;
    QLineEdit *leHeight;
    QLineEdit *leAngle;
    QLabel *lDPI;
    QLineEdit *leDPI;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgImage)
    {
        if (QG_DlgImage->objectName().isEmpty())
            QG_DlgImage->setObjectName(QString::fromUtf8("QG_DlgImage"));
        QG_DlgImage->resize(426, 331);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgImage->sizePolicy().hasHeightForWidth());
        QG_DlgImage->setSizePolicy(sizePolicy);
        QG_DlgImage->setMinimumSize(QSize(300, 190));
        vboxLayout = new QVBoxLayout(QG_DlgImage);
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
        lLayer = new QLabel(QG_DlgImage);
        lLayer->setObjectName(QString::fromUtf8("lLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLayer->sizePolicy().hasHeightForWidth());
        lLayer->setSizePolicy(sizePolicy1);
        lLayer->setWordWrap(false);

        hboxLayout1->addWidget(lLayer);

        cbLayer = new QG_LayerBox(QG_DlgImage);
        cbLayer->setObjectName(QString::fromUtf8("cbLayer"));

        hboxLayout1->addWidget(cbLayer);


        vboxLayout1->addLayout(hboxLayout1);

        wPen = new QG_WidgetPen(QG_DlgImage);
        wPen->setObjectName(QString::fromUtf8("wPen"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wPen->sizePolicy().hasHeightForWidth());
        wPen->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(wPen);


        hboxLayout->addLayout(vboxLayout1);

        buttonGroup8 = new QGroupBox(QG_DlgImage);
        buttonGroup8->setObjectName(QString::fromUtf8("buttonGroup8"));
        buttonGroup8->setEnabled(true);
        sizePolicy1.setHeightForWidth(buttonGroup8->sizePolicy().hasHeightForWidth());
        buttonGroup8->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(buttonGroup8);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lWidth = new QLabel(buttonGroup8);
        lWidth->setObjectName(QString::fromUtf8("lWidth"));

        gridLayout->addWidget(lWidth, 2, 0, 1, 1);

        lePath = new QLineEdit(buttonGroup8);
        lePath->setObjectName(QString::fromUtf8("lePath"));
        lePath->setMinimumSize(QSize(70, 0));
        lePath->setReadOnly(true);

        gridLayout->addWidget(lePath, 6, 1, 1, 1);

        leInsertY = new QLineEdit(buttonGroup8);
        leInsertY->setObjectName(QString::fromUtf8("leInsertY"));
        leInsertY->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(leInsertY, 1, 1, 1, 1);

        lHeight = new QLabel(buttonGroup8);
        lHeight->setObjectName(QString::fromUtf8("lHeight"));

        gridLayout->addWidget(lHeight, 3, 0, 1, 1);

        lInsertX = new QLabel(buttonGroup8);
        lInsertX->setObjectName(QString::fromUtf8("lInsertX"));

        gridLayout->addWidget(lInsertX, 0, 0, 1, 1);

        lScale = new QLabel(buttonGroup8);
        lScale->setObjectName(QString::fromUtf8("lScale"));

        gridLayout->addWidget(lScale, 4, 0, 1, 1);

        spacer58 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer58, 9, 0, 1, 1);

        leSize = new QLineEdit(buttonGroup8);
        leSize->setObjectName(QString::fromUtf8("leSize"));
        leSize->setMinimumSize(QSize(70, 0));
        leSize->setReadOnly(true);

        gridLayout->addWidget(leSize, 7, 1, 1, 1);

        lSize = new QLabel(buttonGroup8);
        lSize->setObjectName(QString::fromUtf8("lSize"));

        gridLayout->addWidget(lSize, 7, 0, 1, 1);

        leInsertX = new QLineEdit(buttonGroup8);
        leInsertX->setObjectName(QString::fromUtf8("leInsertX"));
        leInsertX->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(leInsertX, 0, 1, 1, 1);

        lPath = new QLabel(buttonGroup8);
        lPath->setObjectName(QString::fromUtf8("lPath"));

        gridLayout->addWidget(lPath, 6, 0, 1, 1);

        spacer61 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer61, 9, 1, 1, 1);

        lInsertY = new QLabel(buttonGroup8);
        lInsertY->setObjectName(QString::fromUtf8("lInsertY"));

        gridLayout->addWidget(lInsertY, 1, 0, 1, 1);

        leScale = new QLineEdit(buttonGroup8);
        leScale->setObjectName(QString::fromUtf8("leScale"));
        leScale->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(leScale, 4, 1, 1, 1);

        lAngle = new QLabel(buttonGroup8);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));

        gridLayout->addWidget(lAngle, 5, 0, 1, 1);

        leWidth = new QLineEdit(buttonGroup8);
        leWidth->setObjectName(QString::fromUtf8("leWidth"));
        leWidth->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(leWidth, 2, 1, 1, 1);

        leHeight = new QLineEdit(buttonGroup8);
        leHeight->setObjectName(QString::fromUtf8("leHeight"));
        leHeight->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(leHeight, 3, 1, 1, 1);

        leAngle = new QLineEdit(buttonGroup8);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        leAngle->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(leAngle, 5, 1, 1, 1);

        lDPI = new QLabel(buttonGroup8);
        lDPI->setObjectName(QString::fromUtf8("lDPI"));

        gridLayout->addWidget(lDPI, 8, 0, 1, 1);

        leDPI = new QLineEdit(buttonGroup8);
        leDPI->setObjectName(QString::fromUtf8("leDPI"));

        gridLayout->addWidget(leDPI, 8, 1, 1, 1);


        hboxLayout->addWidget(buttonGroup8);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgImage);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(leInsertX, leInsertY);
        QWidget::setTabOrder(leInsertY, leWidth);
        QWidget::setTabOrder(leWidth, leHeight);
        QWidget::setTabOrder(leHeight, leScale);
        QWidget::setTabOrder(leScale, leAngle);
        QWidget::setTabOrder(leAngle, lePath);
        QWidget::setTabOrder(lePath, leSize);
        QWidget::setTabOrder(leSize, leDPI);

        retranslateUi(QG_DlgImage);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgImage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgImage, SLOT(reject()));
        QObject::connect(leWidth, SIGNAL(editingFinished()), QG_DlgImage, SLOT(changeWidth()));
        QObject::connect(leHeight, SIGNAL(editingFinished()), QG_DlgImage, SLOT(changeHeight()));
        QObject::connect(leScale, SIGNAL(editingFinished()), QG_DlgImage, SLOT(changeScale()));
        QObject::connect(leDPI, SIGNAL(editingFinished()), QG_DlgImage, SLOT(changeDPI()));

        QMetaObject::connectSlotsByName(QG_DlgImage);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgImage)
    {
        QG_DlgImage->setWindowTitle(QCoreApplication::translate("QG_DlgImage", "Image", nullptr));
        lLayer->setText(QCoreApplication::translate("QG_DlgImage", "Layer:", nullptr));
        buttonGroup8->setTitle(QCoreApplication::translate("QG_DlgImage", "Geometry", nullptr));
        lWidth->setText(QCoreApplication::translate("QG_DlgImage", "Width:", nullptr));
        lHeight->setText(QCoreApplication::translate("QG_DlgImage", "Height:", nullptr));
        lInsertX->setText(QCoreApplication::translate("QG_DlgImage", "insert (x):", nullptr));
        lScale->setText(QCoreApplication::translate("QG_DlgImage", "Scale:", nullptr));
        lSize->setText(QCoreApplication::translate("QG_DlgImage", "Size (px):", nullptr));
        lPath->setText(QCoreApplication::translate("QG_DlgImage", "path:", nullptr));
        lInsertY->setText(QCoreApplication::translate("QG_DlgImage", "insert (y):", nullptr));
        lAngle->setText(QCoreApplication::translate("QG_DlgImage", "Angle:", nullptr));
        lDPI->setText(QCoreApplication::translate("QG_DlgImage", "DPI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgImage: public Ui_QG_DlgImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGIMAGE_H
