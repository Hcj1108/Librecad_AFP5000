/********************************************************************************
** Form generated from reading UI file 'qg_arcoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_ARCOPTIONS_H
#define UI_QG_ARCOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_ArcOptions
{
public:
    QGroupBox *buttonGroup1;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbPos;
    QFrame *sep1;
    QRadioButton *rbNeg;

    void setupUi(QWidget *Ui_ArcOptions)
    {
        if (Ui_ArcOptions->objectName().isEmpty())
            Ui_ArcOptions->setObjectName(QString::fromUtf8("Ui_ArcOptions"));
        Ui_ArcOptions->resize(113, 28);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_ArcOptions->sizePolicy().hasHeightForWidth());
        Ui_ArcOptions->setSizePolicy(sizePolicy);
        Ui_ArcOptions->setMinimumSize(QSize(113, 22));
        buttonGroup1 = new QGroupBox(Ui_ArcOptions);
        buttonGroup1->setObjectName(QString::fromUtf8("buttonGroup1"));
        buttonGroup1->setEnabled(true);
        buttonGroup1->setGeometry(QRect(0, 0, 113, 22));
        sizePolicy.setHeightForWidth(buttonGroup1->sizePolicy().hasHeightForWidth());
        buttonGroup1->setSizePolicy(sizePolicy);
        buttonGroup1->setFlat(true);
        buttonGroup1->setProperty("lineWidth", QVariant(0));
        layoutWidget = new QWidget(buttonGroup1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 1, 119, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rbPos = new QRadioButton(layoutWidget);
        rbPos->setObjectName(QString::fromUtf8("rbPos"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rbPos->sizePolicy().hasHeightForWidth());
        rbPos->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dirpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        rbPos->setIcon(icon);
        rbPos->setChecked(true);

        horizontalLayout->addWidget(rbPos);

        sep1 = new QFrame(layoutWidget);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setMinimumSize(QSize(3, 0));
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sep1);

        rbNeg = new QRadioButton(layoutWidget);
        rbNeg->setObjectName(QString::fromUtf8("rbNeg"));
        sizePolicy1.setHeightForWidth(rbNeg->sizePolicy().hasHeightForWidth());
        rbNeg->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/extui/dirneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        rbNeg->setIcon(icon1);
        rbNeg->setCheckable(true);

        horizontalLayout->addWidget(rbNeg);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(Ui_ArcOptions);

        QMetaObject::connectSlotsByName(Ui_ArcOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_ArcOptions)
    {
        Ui_ArcOptions->setWindowTitle(QCoreApplication::translate("Ui_ArcOptions", "Arc Options", nullptr));
        buttonGroup1->setTitle(QString());
#if QT_CONFIG(tooltip)
        rbPos->setToolTip(QCoreApplication::translate("Ui_ArcOptions", "Counterclockwise", nullptr));
#endif // QT_CONFIG(tooltip)
        rbPos->setText(QString());
#if QT_CONFIG(tooltip)
        rbNeg->setToolTip(QCoreApplication::translate("Ui_ArcOptions", "Clockwise", nullptr));
#endif // QT_CONFIG(tooltip)
        rbNeg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ui_ArcOptions: public Ui_Ui_ArcOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_ARCOPTIONS_H
