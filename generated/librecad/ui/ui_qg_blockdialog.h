/********************************************************************************
** Form generated from reading UI file 'qg_blockdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_BLOCKDIALOG_H
#define UI_QG_BLOCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_BlockDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *lName;
    QSpacerItem *spacer87;
    QLineEdit *leName;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_BlockDialog)
    {
        if (QG_BlockDialog->objectName().isEmpty())
            QG_BlockDialog->setObjectName(QString::fromUtf8("QG_BlockDialog"));
        QG_BlockDialog->resize(253, 79);
        QG_BlockDialog->setBaseSize(QSize(0, 0));
        QG_BlockDialog->setSizeGripEnabled(false);
        vboxLayout = new QVBoxLayout(QG_BlockDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lName = new QLabel(QG_BlockDialog);
        lName->setObjectName(QString::fromUtf8("lName"));
        lName->setFrameShape(QFrame::NoFrame);
        lName->setFrameShadow(QFrame::Plain);
        lName->setWordWrap(false);

        hboxLayout->addWidget(lName);

        spacer87 = new QSpacerItem(29, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer87);

        leName = new QLineEdit(QG_BlockDialog);
        leName->setObjectName(QString::fromUtf8("leName"));

        hboxLayout->addWidget(leName);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_BlockDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(QG_BlockDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_BlockDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_BlockDialog, SLOT(validate()));

        QMetaObject::connectSlotsByName(QG_BlockDialog);
    } // setupUi

    void retranslateUi(QDialog *QG_BlockDialog)
    {
        QG_BlockDialog->setWindowTitle(QCoreApplication::translate("QG_BlockDialog", "Block Settings", nullptr));
        lName->setText(QCoreApplication::translate("QG_BlockDialog", "Block Name:", nullptr));
        leName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_BlockDialog: public Ui_QG_BlockDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_BLOCKDIALOG_H
