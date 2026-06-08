/********************************************************************************
** Form generated from reading UI file 'qg_imageoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_IMAGEOPTIONS_H
#define UI_QG_IMAGEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_ImageOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QLabel *lFactor;
    QLineEdit *leFactor;
    QLabel *lDPI;
    QLineEdit *leDPI;
    QFrame *sep1_2;

    void setupUi(QWidget *Ui_ImageOptions)
    {
        if (Ui_ImageOptions->objectName().isEmpty())
            Ui_ImageOptions->setObjectName(QString::fromUtf8("Ui_ImageOptions"));
        Ui_ImageOptions->resize(250, 24);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_ImageOptions->sizePolicy().hasHeightForWidth());
        Ui_ImageOptions->setSizePolicy(sizePolicy);
        Ui_ImageOptions->setMinimumSize(QSize(200, 22));
        Ui_ImageOptions->setMaximumSize(QSize(250, 32767));
        hboxLayout = new QHBoxLayout(Ui_ImageOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lAngle = new QLabel(Ui_ImageOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_ImageOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        hboxLayout->addWidget(leAngle);

        lFactor = new QLabel(Ui_ImageOptions);
        lFactor->setObjectName(QString::fromUtf8("lFactor"));
        lFactor->setWordWrap(false);

        hboxLayout->addWidget(lFactor);

        leFactor = new QLineEdit(Ui_ImageOptions);
        leFactor->setObjectName(QString::fromUtf8("leFactor"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leFactor->sizePolicy().hasHeightForWidth());
        leFactor->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(leFactor);

        lDPI = new QLabel(Ui_ImageOptions);
        lDPI->setObjectName(QString::fromUtf8("lDPI"));

        hboxLayout->addWidget(lDPI);

        leDPI = new QLineEdit(Ui_ImageOptions);
        leDPI->setObjectName(QString::fromUtf8("leDPI"));

        hboxLayout->addWidget(leDPI);

        sep1_2 = new QFrame(Ui_ImageOptions);
        sep1_2->setObjectName(QString::fromUtf8("sep1_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1_2->sizePolicy().hasHeightForWidth());
        sep1_2->setSizePolicy(sizePolicy2);
        sep1_2->setFrameShape(QFrame::VLine);
        sep1_2->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1_2);


        retranslateUi(Ui_ImageOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_ImageOptions, SLOT(updateData()));
        QObject::connect(leDPI, SIGNAL(textChanged(QString)), Ui_ImageOptions, SLOT(updateDPI()));
        QObject::connect(leFactor, SIGNAL(textChanged(QString)), Ui_ImageOptions, SLOT(updateFactor()));

        QMetaObject::connectSlotsByName(Ui_ImageOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_ImageOptions)
    {
        Ui_ImageOptions->setWindowTitle(QCoreApplication::translate("Ui_ImageOptions", "Insert Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_ImageOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lAngle->setText(QCoreApplication::translate("Ui_ImageOptions", "Angle:", nullptr));
#if QT_CONFIG(tooltip)
        leAngle->setToolTip(QCoreApplication::translate("Ui_ImageOptions", "Rotation Angle", nullptr));
#endif // QT_CONFIG(tooltip)
        lFactor->setText(QCoreApplication::translate("Ui_ImageOptions", "Factor:", nullptr));
#if QT_CONFIG(tooltip)
        leFactor->setToolTip(QCoreApplication::translate("Ui_ImageOptions", "Scale Factor", nullptr));
#endif // QT_CONFIG(tooltip)
        lDPI->setText(QCoreApplication::translate("Ui_ImageOptions", "DPI", nullptr));
#if QT_CONFIG(tooltip)
        leDPI->setToolTip(QCoreApplication::translate("Ui_ImageOptions", "DPI of Image", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_ImageOptions: public Ui_Ui_ImageOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_IMAGEOPTIONS_H
