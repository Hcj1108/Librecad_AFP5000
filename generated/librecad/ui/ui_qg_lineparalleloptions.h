/********************************************************************************
** Form generated from reading UI file 'qg_lineparalleloptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINEPARALLELOPTIONS_H
#define UI_QG_LINEPARALLELOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LineParallelOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lDist;
    QLineEdit *leDist;
    QLabel *lNumber;
    QSpinBox *sbNumber;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LineParallelOptions)
    {
        if (Ui_LineParallelOptions->objectName().isEmpty())
            Ui_LineParallelOptions->setObjectName(QString::fromUtf8("Ui_LineParallelOptions"));
        Ui_LineParallelOptions->resize(252, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LineParallelOptions->sizePolicy().hasHeightForWidth());
        Ui_LineParallelOptions->setSizePolicy(sizePolicy);
        Ui_LineParallelOptions->setMinimumSize(QSize(200, 22));
        Ui_LineParallelOptions->setMaximumSize(QSize(280, 22));
        hboxLayout = new QHBoxLayout(Ui_LineParallelOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lDist = new QLabel(Ui_LineParallelOptions);
        lDist->setObjectName(QString::fromUtf8("lDist"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lDist->sizePolicy().hasHeightForWidth());
        lDist->setSizePolicy(sizePolicy1);
        lDist->setWordWrap(false);

        hboxLayout->addWidget(lDist);

        leDist = new QLineEdit(Ui_LineParallelOptions);
        leDist->setObjectName(QString::fromUtf8("leDist"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leDist->sizePolicy().hasHeightForWidth());
        leDist->setSizePolicy(sizePolicy2);

        hboxLayout->addWidget(leDist);

        lNumber = new QLabel(Ui_LineParallelOptions);
        lNumber->setObjectName(QString::fromUtf8("lNumber"));
        sizePolicy1.setHeightForWidth(lNumber->sizePolicy().hasHeightForWidth());
        lNumber->setSizePolicy(sizePolicy1);
        lNumber->setWordWrap(false);

        hboxLayout->addWidget(lNumber);

        sbNumber = new QSpinBox(Ui_LineParallelOptions);
        sbNumber->setObjectName(QString::fromUtf8("sbNumber"));
        sbNumber->setMinimum(1);

        hboxLayout->addWidget(sbNumber);

        sep1 = new QFrame(Ui_LineParallelOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy3);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LineParallelOptions);
        QObject::connect(leDist, SIGNAL(textChanged(QString)), Ui_LineParallelOptions, SLOT(updateDist(QString)));
        QObject::connect(sbNumber, SIGNAL(valueChanged(int)), Ui_LineParallelOptions, SLOT(updateNumber(int)));

        QMetaObject::connectSlotsByName(Ui_LineParallelOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LineParallelOptions)
    {
        Ui_LineParallelOptions->setWindowTitle(QCoreApplication::translate("Ui_LineParallelOptions", "Line Parallel Options", nullptr));
        lDist->setText(QCoreApplication::translate("Ui_LineParallelOptions", "Distance:", nullptr));
#if QT_CONFIG(tooltip)
        leDist->setToolTip(QCoreApplication::translate("Ui_LineParallelOptions", "Distance to original entity", nullptr));
#endif // QT_CONFIG(tooltip)
        lNumber->setText(QCoreApplication::translate("Ui_LineParallelOptions", "Number:", nullptr));
#if QT_CONFIG(tooltip)
        sbNumber->setToolTip(QCoreApplication::translate("Ui_LineParallelOptions", "Number of parallels to create", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_LineParallelOptions: public Ui_Ui_LineParallelOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINEPARALLELOPTIONS_H
