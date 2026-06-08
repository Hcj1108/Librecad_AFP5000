/********************************************************************************
** Form generated from reading UI file 'qg_lineparallelthroughoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINEPARALLELTHROUGHOPTIONS_H
#define UI_QG_LINEPARALLELTHROUGHOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LineParallelThroughOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lNumber;
    QSpinBox *sbNumber;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LineParallelThroughOptions)
    {
        if (Ui_LineParallelThroughOptions->objectName().isEmpty())
            Ui_LineParallelThroughOptions->setObjectName(QString::fromUtf8("Ui_LineParallelThroughOptions"));
        Ui_LineParallelThroughOptions->resize(140, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LineParallelThroughOptions->sizePolicy().hasHeightForWidth());
        Ui_LineParallelThroughOptions->setSizePolicy(sizePolicy);
        Ui_LineParallelThroughOptions->setMinimumSize(QSize(100, 22));
        Ui_LineParallelThroughOptions->setMaximumSize(QSize(140, 22));
        hboxLayout = new QHBoxLayout(Ui_LineParallelThroughOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lNumber = new QLabel(Ui_LineParallelThroughOptions);
        lNumber->setObjectName(QString::fromUtf8("lNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lNumber->sizePolicy().hasHeightForWidth());
        lNumber->setSizePolicy(sizePolicy1);
        lNumber->setWordWrap(false);

        hboxLayout->addWidget(lNumber);

        sbNumber = new QSpinBox(Ui_LineParallelThroughOptions);
        sbNumber->setObjectName(QString::fromUtf8("sbNumber"));
        sbNumber->setMinimum(1);

        hboxLayout->addWidget(sbNumber);

        sep1 = new QFrame(Ui_LineParallelThroughOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LineParallelThroughOptions);
        QObject::connect(sbNumber, SIGNAL(valueChanged(int)), Ui_LineParallelThroughOptions, SLOT(updateNumber(int)));

        QMetaObject::connectSlotsByName(Ui_LineParallelThroughOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LineParallelThroughOptions)
    {
        Ui_LineParallelThroughOptions->setWindowTitle(QCoreApplication::translate("Ui_LineParallelThroughOptions", "Line Parallel Through Options", nullptr));
        lNumber->setText(QCoreApplication::translate("Ui_LineParallelThroughOptions", "Number:", nullptr));
#if QT_CONFIG(tooltip)
        sbNumber->setToolTip(QCoreApplication::translate("Ui_LineParallelThroughOptions", "Number of parallels to create", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_LineParallelThroughOptions: public Ui_Ui_LineParallelThroughOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINEPARALLELTHROUGHOPTIONS_H
