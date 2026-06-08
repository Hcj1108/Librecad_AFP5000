/********************************************************************************
** Form generated from reading UI file 'qg_circleoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_CIRCLEOPTIONS_H
#define UI_QG_CIRCLEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_CircleOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lRadius;
    QLineEdit *leRadius;
    QFrame *sep1;

    void setupUi(QWidget *Ui_CircleOptions)
    {
        if (Ui_CircleOptions->objectName().isEmpty())
            Ui_CircleOptions->setObjectName(QString::fromUtf8("Ui_CircleOptions"));
        Ui_CircleOptions->resize(150, 22);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_CircleOptions->sizePolicy().hasHeightForWidth());
        Ui_CircleOptions->setSizePolicy(sizePolicy);
        Ui_CircleOptions->setMinimumSize(QSize(111, 22));
        Ui_CircleOptions->setMaximumSize(QSize(150, 22));
        hboxLayout = new QHBoxLayout(Ui_CircleOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lRadius = new QLabel(Ui_CircleOptions);
        lRadius->setObjectName(QString::fromUtf8("lRadius"));
        lRadius->setWordWrap(false);

        hboxLayout->addWidget(lRadius);

        leRadius = new QLineEdit(Ui_CircleOptions);
        leRadius->setObjectName(QString::fromUtf8("leRadius"));

        hboxLayout->addWidget(leRadius);

        sep1 = new QFrame(Ui_CircleOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_CircleOptions);
        QObject::connect(leRadius, SIGNAL(textChanged(QString)), Ui_CircleOptions, SLOT(updateRadius(QString)));

        QMetaObject::connectSlotsByName(Ui_CircleOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_CircleOptions)
    {
        Ui_CircleOptions->setWindowTitle(QCoreApplication::translate("Ui_CircleOptions", "Circle Options", nullptr));
        lRadius->setText(QCoreApplication::translate("Ui_CircleOptions", "Radius:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_CircleOptions: public Ui_Ui_CircleOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_CIRCLEOPTIONS_H
