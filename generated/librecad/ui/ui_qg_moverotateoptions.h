/********************************************************************************
** Form generated from reading UI file 'qg_moverotateoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_MOVEROTATEOPTIONS_H
#define UI_QG_MOVEROTATEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_MoveRotateOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QFrame *sep1;

    void setupUi(QWidget *Ui_MoveRotateOptions)
    {
        if (Ui_MoveRotateOptions->objectName().isEmpty())
            Ui_MoveRotateOptions->setObjectName(QString::fromUtf8("Ui_MoveRotateOptions"));
        Ui_MoveRotateOptions->resize(140, 22);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_MoveRotateOptions->sizePolicy().hasHeightForWidth());
        Ui_MoveRotateOptions->setSizePolicy(sizePolicy);
        Ui_MoveRotateOptions->setMinimumSize(QSize(128, 22));
        Ui_MoveRotateOptions->setMaximumSize(QSize(140, 22));
        hboxLayout = new QHBoxLayout(Ui_MoveRotateOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lAngle = new QLabel(Ui_MoveRotateOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_MoveRotateOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        hboxLayout->addWidget(leAngle);

        sep1 = new QFrame(Ui_MoveRotateOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_MoveRotateOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_MoveRotateOptions, SLOT(updateAngle(QString)));

        QMetaObject::connectSlotsByName(Ui_MoveRotateOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_MoveRotateOptions)
    {
        Ui_MoveRotateOptions->setWindowTitle(QCoreApplication::translate("Ui_MoveRotateOptions", "Move Rotate Options", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_MoveRotateOptions", "Angle:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_MoveRotateOptions: public Ui_Ui_MoveRotateOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_MOVEROTATEOPTIONS_H
