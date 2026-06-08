/********************************************************************************
** Form generated from reading UI file 'qg_linebisectoroptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINEBISECTOROPTIONS_H
#define UI_QG_LINEBISECTOROPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LineBisectorOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lLength;
    QLineEdit *leLength;
    QLabel *lNumber;
    QSpinBox *sbNumber;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LineBisectorOptions)
    {
        if (Ui_LineBisectorOptions->objectName().isEmpty())
            Ui_LineBisectorOptions->setObjectName(QString::fromUtf8("Ui_LineBisectorOptions"));
        Ui_LineBisectorOptions->resize(280, 22);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LineBisectorOptions->sizePolicy().hasHeightForWidth());
        Ui_LineBisectorOptions->setSizePolicy(sizePolicy);
        Ui_LineBisectorOptions->setMinimumSize(QSize(220, 22));
        Ui_LineBisectorOptions->setMaximumSize(QSize(280, 22));
        hboxLayout = new QHBoxLayout(Ui_LineBisectorOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lLength = new QLabel(Ui_LineBisectorOptions);
        lLength->setObjectName(QString::fromUtf8("lLength"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLength->sizePolicy().hasHeightForWidth());
        lLength->setSizePolicy(sizePolicy1);
        lLength->setWordWrap(false);

        hboxLayout->addWidget(lLength);

        leLength = new QLineEdit(Ui_LineBisectorOptions);
        leLength->setObjectName(QString::fromUtf8("leLength"));

        hboxLayout->addWidget(leLength);

        lNumber = new QLabel(Ui_LineBisectorOptions);
        lNumber->setObjectName(QString::fromUtf8("lNumber"));
        lNumber->setWordWrap(false);

        hboxLayout->addWidget(lNumber);

        sbNumber = new QSpinBox(Ui_LineBisectorOptions);
        sbNumber->setObjectName(QString::fromUtf8("sbNumber"));
        sbNumber->setMinimum(1);

        hboxLayout->addWidget(sbNumber);

        sep1 = new QFrame(Ui_LineBisectorOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LineBisectorOptions);
        QObject::connect(leLength, SIGNAL(textChanged(QString)), Ui_LineBisectorOptions, SLOT(updateLength(QString)));
        QObject::connect(sbNumber, SIGNAL(valueChanged(int)), Ui_LineBisectorOptions, SLOT(updateNumber(int)));

        QMetaObject::connectSlotsByName(Ui_LineBisectorOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LineBisectorOptions)
    {
        Ui_LineBisectorOptions->setWindowTitle(QCoreApplication::translate("Ui_LineBisectorOptions", "Line Bisector Options", nullptr));
        lLength->setText(QCoreApplication::translate("Ui_LineBisectorOptions", "Length:", nullptr));
#if QT_CONFIG(tooltip)
        leLength->setToolTip(QCoreApplication::translate("Ui_LineBisectorOptions", "Length of bisector", nullptr));
#endif // QT_CONFIG(tooltip)
        lNumber->setText(QCoreApplication::translate("Ui_LineBisectorOptions", "Number:", nullptr));
#if QT_CONFIG(tooltip)
        sbNumber->setToolTip(QCoreApplication::translate("Ui_LineBisectorOptions", "Number of bisectors to create", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_LineBisectorOptions: public Ui_Ui_LineBisectorOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINEBISECTOROPTIONS_H
