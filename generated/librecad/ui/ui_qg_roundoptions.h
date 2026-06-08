/********************************************************************************
** Form generated from reading UI file 'qg_roundoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_ROUNDOPTIONS_H
#define UI_QG_ROUNDOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_RoundOptions
{
public:
    QHBoxLayout *hboxLayout;
    QCheckBox *cbTrim;
    QFrame *sep1_2;
    QLabel *lRadius;
    QLineEdit *leRadius;
    QFrame *sep1;

    void setupUi(QWidget *Ui_RoundOptions)
    {
        if (Ui_RoundOptions->objectName().isEmpty())
            Ui_RoundOptions->setObjectName(QString::fromUtf8("Ui_RoundOptions"));
        Ui_RoundOptions->resize(200, 24);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_RoundOptions->sizePolicy().hasHeightForWidth());
        Ui_RoundOptions->setSizePolicy(sizePolicy);
        Ui_RoundOptions->setMinimumSize(QSize(170, 22));
        Ui_RoundOptions->setMaximumSize(QSize(200, 32767));
        hboxLayout = new QHBoxLayout(Ui_RoundOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        cbTrim = new QCheckBox(Ui_RoundOptions);
        cbTrim->setObjectName(QString::fromUtf8("cbTrim"));

        hboxLayout->addWidget(cbTrim);

        sep1_2 = new QFrame(Ui_RoundOptions);
        sep1_2->setObjectName(QString::fromUtf8("sep1_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1_2->sizePolicy().hasHeightForWidth());
        sep1_2->setSizePolicy(sizePolicy1);
        sep1_2->setFrameShape(QFrame::VLine);
        sep1_2->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1_2);

        lRadius = new QLabel(Ui_RoundOptions);
        lRadius->setObjectName(QString::fromUtf8("lRadius"));
        lRadius->setWordWrap(false);

        hboxLayout->addWidget(lRadius);

        leRadius = new QLineEdit(Ui_RoundOptions);
        leRadius->setObjectName(QString::fromUtf8("leRadius"));

        hboxLayout->addWidget(leRadius);

        sep1 = new QFrame(Ui_RoundOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_RoundOptions);
        QObject::connect(leRadius, SIGNAL(textChanged(QString)), Ui_RoundOptions, SLOT(updateData()));
        QObject::connect(cbTrim, SIGNAL(toggled(bool)), Ui_RoundOptions, SLOT(updateData()));

        QMetaObject::connectSlotsByName(Ui_RoundOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_RoundOptions)
    {
        Ui_RoundOptions->setWindowTitle(QCoreApplication::translate("Ui_RoundOptions", "Round Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_RoundOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbTrim->setToolTip(QCoreApplication::translate("Ui_RoundOptions", "Check to trim both edges to the rounding", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTrim->setText(QCoreApplication::translate("Ui_RoundOptions", "Trim", nullptr));
        lRadius->setText(QCoreApplication::translate("Ui_RoundOptions", "Radius:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_RoundOptions: public Ui_Ui_RoundOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_ROUNDOPTIONS_H
