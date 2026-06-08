/********************************************************************************
** Form generated from reading UI file 'qg_linerelangleoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINERELANGLEOPTIONS_H
#define UI_QG_LINERELANGLEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LineRelAngleOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QLabel *lLength;
    QLineEdit *leLength;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LineRelAngleOptions)
    {
        if (Ui_LineRelAngleOptions->objectName().isEmpty())
            Ui_LineRelAngleOptions->setObjectName(QString::fromUtf8("Ui_LineRelAngleOptions"));
        Ui_LineRelAngleOptions->resize(280, 24);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LineRelAngleOptions->sizePolicy().hasHeightForWidth());
        Ui_LineRelAngleOptions->setSizePolicy(sizePolicy);
        Ui_LineRelAngleOptions->setMinimumSize(QSize(200, 22));
        Ui_LineRelAngleOptions->setMaximumSize(QSize(280, 32767));
        hboxLayout = new QHBoxLayout(Ui_LineRelAngleOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lAngle = new QLabel(Ui_LineRelAngleOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lAngle->sizePolicy().hasHeightForWidth());
        lAngle->setSizePolicy(sizePolicy1);
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_LineRelAngleOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy2);

        hboxLayout->addWidget(leAngle);

        lLength = new QLabel(Ui_LineRelAngleOptions);
        lLength->setObjectName(QString::fromUtf8("lLength"));
        sizePolicy1.setHeightForWidth(lLength->sizePolicy().hasHeightForWidth());
        lLength->setSizePolicy(sizePolicy1);
        lLength->setWordWrap(false);

        hboxLayout->addWidget(lLength);

        leLength = new QLineEdit(Ui_LineRelAngleOptions);
        leLength->setObjectName(QString::fromUtf8("leLength"));
        sizePolicy2.setHeightForWidth(leLength->sizePolicy().hasHeightForWidth());
        leLength->setSizePolicy(sizePolicy2);

        hboxLayout->addWidget(leLength);

        sep1 = new QFrame(Ui_LineRelAngleOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy3);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LineRelAngleOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_LineRelAngleOptions, SLOT(updateAngle(QString)));
        QObject::connect(leLength, SIGNAL(textChanged(QString)), Ui_LineRelAngleOptions, SLOT(updateLength(QString)));

        QMetaObject::connectSlotsByName(Ui_LineRelAngleOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LineRelAngleOptions)
    {
        Ui_LineRelAngleOptions->setWindowTitle(QCoreApplication::translate("Ui_LineRelAngleOptions", "Line Relative Angle Options", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_LineRelAngleOptions", "Angle:", nullptr));
#if QT_CONFIG(tooltip)
        leAngle->setToolTip(QCoreApplication::translate("Ui_LineRelAngleOptions", "Line angle", nullptr));
#endif // QT_CONFIG(tooltip)
        lLength->setText(QCoreApplication::translate("Ui_LineRelAngleOptions", "Length:", nullptr));
#if QT_CONFIG(tooltip)
        leLength->setToolTip(QCoreApplication::translate("Ui_LineRelAngleOptions", "Length of line", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_LineRelAngleOptions: public Ui_Ui_LineRelAngleOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINERELANGLEOPTIONS_H
