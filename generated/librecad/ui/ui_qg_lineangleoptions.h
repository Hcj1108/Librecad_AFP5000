/********************************************************************************
** Form generated from reading UI file 'qg_lineangleoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINEANGLEOPTIONS_H
#define UI_QG_LINEANGLEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LineAngleOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QLabel *lLength;
    QLineEdit *leLength;
    QLabel *lSnapPoint;
    QComboBox *cbSnapPoint;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LineAngleOptions)
    {
        if (Ui_LineAngleOptions->objectName().isEmpty())
            Ui_LineAngleOptions->setObjectName(QString::fromUtf8("Ui_LineAngleOptions"));
        Ui_LineAngleOptions->resize(400, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LineAngleOptions->sizePolicy().hasHeightForWidth());
        Ui_LineAngleOptions->setSizePolicy(sizePolicy);
        Ui_LineAngleOptions->setMinimumSize(QSize(300, 22));
        Ui_LineAngleOptions->setMaximumSize(QSize(400, 22));
        hboxLayout = new QHBoxLayout(Ui_LineAngleOptions);
        hboxLayout->setSpacing(1);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        lAngle = new QLabel(Ui_LineAngleOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lAngle->sizePolicy().hasHeightForWidth());
        lAngle->setSizePolicy(sizePolicy1);
        lAngle->setMaximumSize(QSize(45, 16777215));
        lAngle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_LineAngleOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy2);
        leAngle->setMaximumSize(QSize(50, 32));

        hboxLayout->addWidget(leAngle);

        lLength = new QLabel(Ui_LineAngleOptions);
        lLength->setObjectName(QString::fromUtf8("lLength"));
        sizePolicy1.setHeightForWidth(lLength->sizePolicy().hasHeightForWidth());
        lLength->setSizePolicy(sizePolicy1);
        lLength->setMaximumSize(QSize(50, 16777215));
        lLength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lLength->setWordWrap(false);

        hboxLayout->addWidget(lLength);

        leLength = new QLineEdit(Ui_LineAngleOptions);
        leLength->setObjectName(QString::fromUtf8("leLength"));
        sizePolicy2.setHeightForWidth(leLength->sizePolicy().hasHeightForWidth());
        leLength->setSizePolicy(sizePolicy2);
        leLength->setMaximumSize(QSize(50, 32));

        hboxLayout->addWidget(leLength);

        lSnapPoint = new QLabel(Ui_LineAngleOptions);
        lSnapPoint->setObjectName(QString::fromUtf8("lSnapPoint"));
        lSnapPoint->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lSnapPoint->setWordWrap(false);

        hboxLayout->addWidget(lSnapPoint);

        cbSnapPoint = new QComboBox(Ui_LineAngleOptions);
        cbSnapPoint->addItem(QString());
        cbSnapPoint->addItem(QString());
        cbSnapPoint->addItem(QString());
        cbSnapPoint->setObjectName(QString::fromUtf8("cbSnapPoint"));
        QFont font;
        cbSnapPoint->setFont(font);

        hboxLayout->addWidget(cbSnapPoint);

        sep1 = new QFrame(Ui_LineAngleOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy3);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LineAngleOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_LineAngleOptions, SLOT(updateAngle(QString)));
        QObject::connect(leLength, SIGNAL(textChanged(QString)), Ui_LineAngleOptions, SLOT(updateLength(QString)));
        QObject::connect(cbSnapPoint, SIGNAL(activated(int)), Ui_LineAngleOptions, SLOT(updateSnapPoint(int)));

        QMetaObject::connectSlotsByName(Ui_LineAngleOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LineAngleOptions)
    {
        Ui_LineAngleOptions->setWindowTitle(QCoreApplication::translate("Ui_LineAngleOptions", "Line Angle Options", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_LineAngleOptions", "Angle:", nullptr));
#if QT_CONFIG(tooltip)
        leAngle->setToolTip(QCoreApplication::translate("Ui_LineAngleOptions", "Line angle", nullptr));
#endif // QT_CONFIG(tooltip)
        lLength->setText(QCoreApplication::translate("Ui_LineAngleOptions", "Length:", nullptr));
#if QT_CONFIG(tooltip)
        leLength->setToolTip(QCoreApplication::translate("Ui_LineAngleOptions", "Length of line", nullptr));
#endif // QT_CONFIG(tooltip)
        lSnapPoint->setText(QCoreApplication::translate("Ui_LineAngleOptions", "Snap Point:", nullptr));
        cbSnapPoint->setItemText(0, QCoreApplication::translate("Ui_LineAngleOptions", "Start", nullptr));
        cbSnapPoint->setItemText(1, QCoreApplication::translate("Ui_LineAngleOptions", "Middle", nullptr));
        cbSnapPoint->setItemText(2, QCoreApplication::translate("Ui_LineAngleOptions", "End", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Ui_LineAngleOptions: public Ui_Ui_LineAngleOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINEANGLEOPTIONS_H
