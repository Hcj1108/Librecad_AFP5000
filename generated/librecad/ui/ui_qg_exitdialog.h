/********************************************************************************
** Form generated from reading UI file 'qg_exitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_EXITDIALOG_H
#define UI_QG_EXITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_QG_ExitDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lQuestion;
    QLabel *l_icon;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_ExitDialog)
    {
        if (QG_ExitDialog->objectName().isEmpty())
            QG_ExitDialog->setObjectName(QString::fromUtf8("QG_ExitDialog"));
        QG_ExitDialog->resize(450, 106);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_ExitDialog->sizePolicy().hasHeightForWidth());
        QG_ExitDialog->setSizePolicy(sizePolicy);
        QG_ExitDialog->setMinimumSize(QSize(450, 0));
        QG_ExitDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(QG_ExitDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lQuestion = new QLabel(QG_ExitDialog);
        lQuestion->setObjectName(QString::fromUtf8("lQuestion"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lQuestion->sizePolicy().hasHeightForWidth());
        lQuestion->setSizePolicy(sizePolicy1);
        lQuestion->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lQuestion->setWordWrap(true);

        gridLayout->addWidget(lQuestion, 0, 1, 1, 1);

        l_icon = new QLabel(QG_ExitDialog);
        l_icon->setObjectName(QString::fromUtf8("l_icon"));
        l_icon->setWordWrap(false);

        gridLayout->addWidget(l_icon, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QG_ExitDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Close|QDialogButtonBox::StandardButton::Save|QDialogButtonBox::StandardButton::SaveAll);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(QG_ExitDialog);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), QG_ExitDialog, SLOT(clicked(QAbstractButton*)));

        QMetaObject::connectSlotsByName(QG_ExitDialog);
    } // setupUi

    void retranslateUi(QDialog *QG_ExitDialog)
    {
        QG_ExitDialog->setWindowTitle(QCoreApplication::translate("QG_ExitDialog", "QCad", nullptr));
        lQuestion->setText(QCoreApplication::translate("QG_ExitDialog", "again Still No Text supplied.", nullptr));
        l_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_ExitDialog: public Ui_QG_ExitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_EXITDIALOG_H
