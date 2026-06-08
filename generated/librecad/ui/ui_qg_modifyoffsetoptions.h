/********************************************************************************
** Form generated from reading UI file 'qg_modifyoffsetoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_MODIFYOFFSETOPTIONS_H
#define UI_QG_MODIFYOFFSETOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_ModifyOffsetOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lDist;
    QLineEdit *leDist;
    QFrame *sep1;

    void setupUi(QWidget *Ui_ModifyOffsetOptions)
    {
        if (Ui_ModifyOffsetOptions->objectName().isEmpty())
            Ui_ModifyOffsetOptions->setObjectName(QString::fromUtf8("Ui_ModifyOffsetOptions"));
        Ui_ModifyOffsetOptions->resize(112, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_ModifyOffsetOptions->sizePolicy().hasHeightForWidth());
        Ui_ModifyOffsetOptions->setSizePolicy(sizePolicy);
        Ui_ModifyOffsetOptions->setMinimumSize(QSize(100, 22));
        Ui_ModifyOffsetOptions->setMaximumSize(QSize(140, 26));
        hboxLayout = new QHBoxLayout(Ui_ModifyOffsetOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lDist = new QLabel(Ui_ModifyOffsetOptions);
        lDist->setObjectName(QString::fromUtf8("lDist"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lDist->sizePolicy().hasHeightForWidth());
        lDist->setSizePolicy(sizePolicy1);
        lDist->setWordWrap(false);

        hboxLayout->addWidget(lDist);

        leDist = new QLineEdit(Ui_ModifyOffsetOptions);
        leDist->setObjectName(QString::fromUtf8("leDist"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leDist->sizePolicy().hasHeightForWidth());
        leDist->setSizePolicy(sizePolicy2);

        hboxLayout->addWidget(leDist);

        sep1 = new QFrame(Ui_ModifyOffsetOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy3);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_ModifyOffsetOptions);
        QObject::connect(leDist, SIGNAL(textChanged(QString)), Ui_ModifyOffsetOptions, SLOT(updateDist(QString)));

        QMetaObject::connectSlotsByName(Ui_ModifyOffsetOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_ModifyOffsetOptions)
    {
        Ui_ModifyOffsetOptions->setWindowTitle(QCoreApplication::translate("Ui_ModifyOffsetOptions", "Modify Offset Options", nullptr));
        lDist->setText(QCoreApplication::translate("Ui_ModifyOffsetOptions", "Distance:", nullptr));
#if QT_CONFIG(tooltip)
        leDist->setToolTip(QCoreApplication::translate("Ui_ModifyOffsetOptions", "Offset from original entity", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_ModifyOffsetOptions: public Ui_Ui_ModifyOffsetOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_MODIFYOFFSETOPTIONS_H
