/********************************************************************************
** Form generated from reading UI file 'qg_insertoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_INSERTOPTIONS_H
#define UI_QG_INSERTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_InsertOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QLabel *lFactor;
    QLineEdit *leFactor;
    QFrame *sep1_2;
    QLabel *lArray;
    QSpinBox *sbColumns;
    QSpinBox *sbRows;
    QLabel *lSpacing;
    QLineEdit *leColumnSpacing;
    QLineEdit *leRowSpacing;
    QFrame *sep1;

    void setupUi(QWidget *Ui_InsertOptions)
    {
        if (Ui_InsertOptions->objectName().isEmpty())
            Ui_InsertOptions->setObjectName(QString::fromUtf8("Ui_InsertOptions"));
        Ui_InsertOptions->resize(450, 26);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_InsertOptions->sizePolicy().hasHeightForWidth());
        Ui_InsertOptions->setSizePolicy(sizePolicy);
        Ui_InsertOptions->setMinimumSize(QSize(50, 22));
        Ui_InsertOptions->setMaximumSize(QSize(600, 32));
        hboxLayout = new QHBoxLayout(Ui_InsertOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lAngle = new QLabel(Ui_InsertOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lAngle->sizePolicy().hasHeightForWidth());
        lAngle->setSizePolicy(sizePolicy1);
        lAngle->setMinimumSize(QSize(36, 0));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_InsertOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy2);
        leAngle->setMinimumSize(QSize(32, 0));

        hboxLayout->addWidget(leAngle);

        lFactor = new QLabel(Ui_InsertOptions);
        lFactor->setObjectName(QString::fromUtf8("lFactor"));
        sizePolicy1.setHeightForWidth(lFactor->sizePolicy().hasHeightForWidth());
        lFactor->setSizePolicy(sizePolicy1);
        lFactor->setMinimumSize(QSize(40, 0));
        lFactor->setWordWrap(false);

        hboxLayout->addWidget(lFactor);

        leFactor = new QLineEdit(Ui_InsertOptions);
        leFactor->setObjectName(QString::fromUtf8("leFactor"));
        sizePolicy2.setHeightForWidth(leFactor->sizePolicy().hasHeightForWidth());
        leFactor->setSizePolicy(sizePolicy2);
        leFactor->setMinimumSize(QSize(32, 0));

        hboxLayout->addWidget(leFactor);

        sep1_2 = new QFrame(Ui_InsertOptions);
        sep1_2->setObjectName(QString::fromUtf8("sep1_2"));
        sizePolicy.setHeightForWidth(sep1_2->sizePolicy().hasHeightForWidth());
        sep1_2->setSizePolicy(sizePolicy);
        sep1_2->setFrameShape(QFrame::VLine);
        sep1_2->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1_2);

        lArray = new QLabel(Ui_InsertOptions);
        lArray->setObjectName(QString::fromUtf8("lArray"));
        sizePolicy1.setHeightForWidth(lArray->sizePolicy().hasHeightForWidth());
        lArray->setSizePolicy(sizePolicy1);
        lArray->setMinimumSize(QSize(34, 0));
        lArray->setWordWrap(false);

        hboxLayout->addWidget(lArray);

        sbColumns = new QSpinBox(Ui_InsertOptions);
        sbColumns->setObjectName(QString::fromUtf8("sbColumns"));
        sizePolicy2.setHeightForWidth(sbColumns->sizePolicy().hasHeightForWidth());
        sbColumns->setSizePolicy(sizePolicy2);
        sbColumns->setMinimumSize(QSize(34, 0));
        sbColumns->setMinimum(1);
        sbColumns->setMaximum(10000);

        hboxLayout->addWidget(sbColumns);

        sbRows = new QSpinBox(Ui_InsertOptions);
        sbRows->setObjectName(QString::fromUtf8("sbRows"));
        sizePolicy2.setHeightForWidth(sbRows->sizePolicy().hasHeightForWidth());
        sbRows->setSizePolicy(sizePolicy2);
        sbRows->setMinimumSize(QSize(34, 0));
        sbRows->setMinimum(1);
        sbRows->setMaximum(10000);

        hboxLayout->addWidget(sbRows);

        lSpacing = new QLabel(Ui_InsertOptions);
        lSpacing->setObjectName(QString::fromUtf8("lSpacing"));
        sizePolicy1.setHeightForWidth(lSpacing->sizePolicy().hasHeightForWidth());
        lSpacing->setSizePolicy(sizePolicy1);
        lSpacing->setMinimumSize(QSize(50, 0));
        lSpacing->setWordWrap(false);

        hboxLayout->addWidget(lSpacing);

        leColumnSpacing = new QLineEdit(Ui_InsertOptions);
        leColumnSpacing->setObjectName(QString::fromUtf8("leColumnSpacing"));
        sizePolicy2.setHeightForWidth(leColumnSpacing->sizePolicy().hasHeightForWidth());
        leColumnSpacing->setSizePolicy(sizePolicy2);
        leColumnSpacing->setMinimumSize(QSize(32, 0));

        hboxLayout->addWidget(leColumnSpacing);

        leRowSpacing = new QLineEdit(Ui_InsertOptions);
        leRowSpacing->setObjectName(QString::fromUtf8("leRowSpacing"));
        sizePolicy2.setHeightForWidth(leRowSpacing->sizePolicy().hasHeightForWidth());
        leRowSpacing->setSizePolicy(sizePolicy2);
        leRowSpacing->setMinimumSize(QSize(32, 0));

        hboxLayout->addWidget(leRowSpacing);

        sep1 = new QFrame(Ui_InsertOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        sizePolicy.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_InsertOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_InsertOptions, SLOT(updateData()));
        QObject::connect(leFactor, SIGNAL(textChanged(QString)), Ui_InsertOptions, SLOT(updateData()));
        QObject::connect(sbColumns, SIGNAL(valueChanged(int)), Ui_InsertOptions, SLOT(updateData()));
        QObject::connect(sbRows, SIGNAL(valueChanged(int)), Ui_InsertOptions, SLOT(updateData()));
        QObject::connect(leColumnSpacing, SIGNAL(textChanged(QString)), Ui_InsertOptions, SLOT(updateData()));
        QObject::connect(leRowSpacing, SIGNAL(textChanged(QString)), Ui_InsertOptions, SLOT(updateData()));

        QMetaObject::connectSlotsByName(Ui_InsertOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_InsertOptions)
    {
        Ui_InsertOptions->setWindowTitle(QCoreApplication::translate("Ui_InsertOptions", "Insert Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_InsertOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lAngle->setText(QCoreApplication::translate("Ui_InsertOptions", "Angle:", nullptr));
#if QT_CONFIG(tooltip)
        leAngle->setToolTip(QCoreApplication::translate("Ui_InsertOptions", "Rotation Angle", nullptr));
#endif // QT_CONFIG(tooltip)
        lFactor->setText(QCoreApplication::translate("Ui_InsertOptions", "Factor:", nullptr));
#if QT_CONFIG(tooltip)
        leFactor->setToolTip(QCoreApplication::translate("Ui_InsertOptions", "Scale Factor", nullptr));
#endif // QT_CONFIG(tooltip)
        lArray->setText(QCoreApplication::translate("Ui_InsertOptions", "Array:", nullptr));
#if QT_CONFIG(tooltip)
        sbColumns->setToolTip(QCoreApplication::translate("Ui_InsertOptions", "Number of Columns", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbRows->setToolTip(QCoreApplication::translate("Ui_InsertOptions", "Number of Rows", nullptr));
#endif // QT_CONFIG(tooltip)
        lSpacing->setText(QCoreApplication::translate("Ui_InsertOptions", "Spacing:", nullptr));
#if QT_CONFIG(tooltip)
        leColumnSpacing->setToolTip(QCoreApplication::translate("Ui_InsertOptions", "Column Spacing", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leRowSpacing->setToolTip(QCoreApplication::translate("Ui_InsertOptions", "Row Spacing", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_InsertOptions: public Ui_Ui_InsertOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_INSERTOPTIONS_H
