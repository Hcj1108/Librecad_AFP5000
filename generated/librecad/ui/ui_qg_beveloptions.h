/********************************************************************************
** Form generated from reading UI file 'qg_beveloptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_BEVELOPTIONS_H
#define UI_QG_BEVELOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_BevelOptions
{
public:
    QHBoxLayout *hboxLayout;
    QCheckBox *cbTrim;
    QFrame *sep1_2;
    QLabel *lLength1;
    QLineEdit *leLength1;
    QLabel *lLength2;
    QLineEdit *leLength2;
    QFrame *sep1;

    void setupUi(QWidget *Ui_BevelOptions)
    {
        if (Ui_BevelOptions->objectName().isEmpty())
            Ui_BevelOptions->setObjectName(QString::fromUtf8("Ui_BevelOptions"));
        Ui_BevelOptions->resize(341, 24);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_BevelOptions->sizePolicy().hasHeightForWidth());
        Ui_BevelOptions->setSizePolicy(sizePolicy);
        Ui_BevelOptions->setMinimumSize(QSize(341, 22));
        Ui_BevelOptions->setMaximumSize(QSize(400, 32767));
        hboxLayout = new QHBoxLayout(Ui_BevelOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        cbTrim = new QCheckBox(Ui_BevelOptions);
        cbTrim->setObjectName(QString::fromUtf8("cbTrim"));

        hboxLayout->addWidget(cbTrim);

        sep1_2 = new QFrame(Ui_BevelOptions);
        sep1_2->setObjectName(QString::fromUtf8("sep1_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1_2->sizePolicy().hasHeightForWidth());
        sep1_2->setSizePolicy(sizePolicy1);
        sep1_2->setFrameShape(QFrame::VLine);
        sep1_2->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1_2);

        lLength1 = new QLabel(Ui_BevelOptions);
        lLength1->setObjectName(QString::fromUtf8("lLength1"));
        lLength1->setWordWrap(false);

        hboxLayout->addWidget(lLength1);

        leLength1 = new QLineEdit(Ui_BevelOptions);
        leLength1->setObjectName(QString::fromUtf8("leLength1"));

        hboxLayout->addWidget(leLength1);

        lLength2 = new QLabel(Ui_BevelOptions);
        lLength2->setObjectName(QString::fromUtf8("lLength2"));
        lLength2->setWordWrap(false);

        hboxLayout->addWidget(lLength2);

        leLength2 = new QLineEdit(Ui_BevelOptions);
        leLength2->setObjectName(QString::fromUtf8("leLength2"));

        hboxLayout->addWidget(leLength2);

        sep1 = new QFrame(Ui_BevelOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_BevelOptions);
        QObject::connect(leLength1, SIGNAL(textChanged(QString)), Ui_BevelOptions, SLOT(updateData()));
        QObject::connect(cbTrim, SIGNAL(toggled(bool)), Ui_BevelOptions, SLOT(updateData()));
        QObject::connect(leLength2, SIGNAL(textChanged(QString)), Ui_BevelOptions, SLOT(updateData()));

        QMetaObject::connectSlotsByName(Ui_BevelOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_BevelOptions)
    {
        Ui_BevelOptions->setWindowTitle(QCoreApplication::translate("Ui_BevelOptions", "Bevel Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_BevelOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbTrim->setToolTip(QCoreApplication::translate("Ui_BevelOptions", "Check to trim both entities to the bevel", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTrim->setText(QCoreApplication::translate("Ui_BevelOptions", "Trim", nullptr));
        lLength1->setText(QCoreApplication::translate("Ui_BevelOptions", "Length 1:", nullptr));
        lLength2->setText(QCoreApplication::translate("Ui_BevelOptions", "Length 2:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_BevelOptions: public Ui_Ui_BevelOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_BEVELOPTIONS_H
