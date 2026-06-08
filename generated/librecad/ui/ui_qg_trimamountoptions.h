/********************************************************************************
** Form generated from reading UI file 'qg_trimamountoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_TRIMAMOUNTOPTIONS_H
#define UI_QG_TRIMAMOUNTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_TrimAmountOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lDist;
    QLineEdit *leDist;
    QCheckBox *cbTotalLength;
    QSpacerItem *horizontalSpacer;
    QFrame *line;

    void setupUi(QWidget *Ui_TrimAmountOptions)
    {
        if (Ui_TrimAmountOptions->objectName().isEmpty())
            Ui_TrimAmountOptions->setObjectName(QString::fromUtf8("Ui_TrimAmountOptions"));
        Ui_TrimAmountOptions->resize(168, 33);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_TrimAmountOptions->sizePolicy().hasHeightForWidth());
        Ui_TrimAmountOptions->setSizePolicy(sizePolicy);
        hboxLayout = new QHBoxLayout(Ui_TrimAmountOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lDist = new QLabel(Ui_TrimAmountOptions);
        lDist->setObjectName(QString::fromUtf8("lDist"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lDist->sizePolicy().hasHeightForWidth());
        lDist->setSizePolicy(sizePolicy1);
        lDist->setMinimumSize(QSize(51, 0));
        lDist->setWordWrap(false);

        hboxLayout->addWidget(lDist);

        leDist = new QLineEdit(Ui_TrimAmountOptions);
        leDist->setObjectName(QString::fromUtf8("leDist"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(40);
        sizePolicy2.setVerticalStretch(22);
        sizePolicy2.setHeightForWidth(leDist->sizePolicy().hasHeightForWidth());
        leDist->setSizePolicy(sizePolicy2);
        leDist->setMaximumSize(QSize(64, 16777215));
        leDist->setToolTipDuration(2);
        leDist->setMaxLength(32769);

        hboxLayout->addWidget(leDist);

        cbTotalLength = new QCheckBox(Ui_TrimAmountOptions);
        cbTotalLength->setObjectName(QString::fromUtf8("cbTotalLength"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbTotalLength->sizePolicy().hasHeightForWidth());
        cbTotalLength->setSizePolicy(sizePolicy3);

        hboxLayout->addWidget(cbTotalLength);

        horizontalSpacer = new QSpacerItem(4, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        line = new QFrame(Ui_TrimAmountOptions);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line);


        retranslateUi(Ui_TrimAmountOptions);

        QMetaObject::connectSlotsByName(Ui_TrimAmountOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_TrimAmountOptions)
    {
        Ui_TrimAmountOptions->setWindowTitle(QCoreApplication::translate("Ui_TrimAmountOptions", "Trim Amount Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_TrimAmountOptions->setToolTip(QCoreApplication::translate("Ui_TrimAmountOptions", "Distance. Negative values for trimming, positive values for extending.", nullptr));
#endif // QT_CONFIG(tooltip)
        lDist->setText(QCoreApplication::translate("Ui_TrimAmountOptions", "Length:", nullptr));
#if QT_CONFIG(tooltip)
        leDist->setToolTip(QCoreApplication::translate("Ui_TrimAmountOptions", "Distance. Negative values for trimming, positive values for extending. Negative sign is ignored when trimming to final total length.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbTotalLength->setToolTip(QCoreApplication::translate("Ui_TrimAmountOptions", "The input length is used as total length after trimming, instead of length increase", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTotalLength->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ui_TrimAmountOptions: public Ui_Ui_TrimAmountOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_TRIMAMOUNTOPTIONS_H
