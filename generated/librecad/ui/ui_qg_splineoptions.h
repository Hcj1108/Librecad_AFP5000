/********************************************************************************
** Form generated from reading UI file 'qg_splineoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_SPLINEOPTIONS_H
#define UI_QG_SPLINEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_SplineOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lDegree;
    QComboBox *cbDegree;
    QCheckBox *cbClosed;
    QToolButton *bUndo;
    QFrame *sep1;

    void setupUi(QWidget *Ui_SplineOptions)
    {
        if (Ui_SplineOptions->objectName().isEmpty())
            Ui_SplineOptions->setObjectName(QString::fromUtf8("Ui_SplineOptions"));
        Ui_SplineOptions->resize(258, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_SplineOptions->sizePolicy().hasHeightForWidth());
        Ui_SplineOptions->setSizePolicy(sizePolicy);
        Ui_SplineOptions->setMinimumSize(QSize(200, 22));
        Ui_SplineOptions->setMaximumSize(QSize(400, 22));
        hboxLayout = new QHBoxLayout(Ui_SplineOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lDegree = new QLabel(Ui_SplineOptions);
        lDegree->setObjectName(QString::fromUtf8("lDegree"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lDegree->sizePolicy().hasHeightForWidth());
        lDegree->setSizePolicy(sizePolicy1);
        lDegree->setWordWrap(false);

        hboxLayout->addWidget(lDegree);

        cbDegree = new QComboBox(Ui_SplineOptions);
        cbDegree->addItem(QString::fromUtf8("1"));
        cbDegree->addItem(QString::fromUtf8("2"));
        cbDegree->addItem(QString::fromUtf8("3"));
        cbDegree->setObjectName(QString::fromUtf8("cbDegree"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbDegree->sizePolicy().hasHeightForWidth());
        cbDegree->setSizePolicy(sizePolicy2);

        hboxLayout->addWidget(cbDegree);

        cbClosed = new QCheckBox(Ui_SplineOptions);
        cbClosed->setObjectName(QString::fromUtf8("cbClosed"));

        hboxLayout->addWidget(cbClosed);

        bUndo = new QToolButton(Ui_SplineOptions);
        bUndo->setObjectName(QString::fromUtf8("bUndo"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bUndo->sizePolicy().hasHeightForWidth());
        bUndo->setSizePolicy(sizePolicy3);

        hboxLayout->addWidget(bUndo);

        sep1 = new QFrame(Ui_SplineOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy4);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_SplineOptions);
        QObject::connect(bUndo, SIGNAL(clicked()), Ui_SplineOptions, SLOT(undo()));
        QObject::connect(cbDegree, SIGNAL(activated(QString)), Ui_SplineOptions, SLOT(setDegree(QString)));
        QObject::connect(cbClosed, SIGNAL(toggled(bool)), Ui_SplineOptions, SLOT(setClosed(bool)));

        QMetaObject::connectSlotsByName(Ui_SplineOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_SplineOptions)
    {
        Ui_SplineOptions->setWindowTitle(QCoreApplication::translate("Ui_SplineOptions", "Spline Options", nullptr));
        lDegree->setText(QCoreApplication::translate("Ui_SplineOptions", "Degree:", nullptr));

        cbClosed->setText(QCoreApplication::translate("Ui_SplineOptions", "Closed", nullptr));
        bUndo->setText(QCoreApplication::translate("Ui_SplineOptions", "Undo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_SplineOptions: public Ui_Ui_SplineOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_SPLINEOPTIONS_H
