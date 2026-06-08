/********************************************************************************
** Form generated from reading UI file 'qg_snapdistoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_SNAPDISTOPTIONS_H
#define UI_QG_SNAPDISTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include "rs_circle.h"
#include "rs_settings.h"

QT_BEGIN_NAMESPACE

class Ui_Ui_SnapDistOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lDist;
    QLineEdit *leDist;
    QFrame *sep1;

    void setupUi(QWidget *Ui_SnapDistOptions)
    {
        if (Ui_SnapDistOptions->objectName().isEmpty())
            Ui_SnapDistOptions->setObjectName(QString::fromUtf8("Ui_SnapDistOptions"));
        Ui_SnapDistOptions->resize(150, 24);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_SnapDistOptions->sizePolicy().hasHeightForWidth());
        Ui_SnapDistOptions->setSizePolicy(sizePolicy);
        Ui_SnapDistOptions->setMinimumSize(QSize(130, 22));
        Ui_SnapDistOptions->setMaximumSize(QSize(150, 32767));
        hboxLayout = new QHBoxLayout(Ui_SnapDistOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lDist = new QLabel(Ui_SnapDistOptions);
        lDist->setObjectName(QString::fromUtf8("lDist"));
        lDist->setWordWrap(false);

        hboxLayout->addWidget(lDist);

        leDist = new QLineEdit(Ui_SnapDistOptions);
        leDist->setObjectName(QString::fromUtf8("leDist"));

        hboxLayout->addWidget(leDist);

        sep1 = new QFrame(Ui_SnapDistOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_SnapDistOptions);
        QObject::connect(leDist, SIGNAL(textChanged(QString)), Ui_SnapDistOptions, SLOT(updateDist(QString)));

        QMetaObject::connectSlotsByName(Ui_SnapDistOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_SnapDistOptions)
    {
        Ui_SnapDistOptions->setWindowTitle(QCoreApplication::translate("Ui_SnapDistOptions", "Snap Distance Options", nullptr));
        lDist->setText(QCoreApplication::translate("Ui_SnapDistOptions", "Distance:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_SnapDistOptions: public Ui_Ui_SnapDistOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_SNAPDISTOPTIONS_H
