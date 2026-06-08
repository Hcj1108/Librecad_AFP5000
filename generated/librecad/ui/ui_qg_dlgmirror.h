/********************************************************************************
** Form generated from reading UI file 'qg_dlgmirror.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGMIRROR_H
#define UI_QG_DLGMIRROR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgMirror
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QCheckBox *cbCurrentAttributes;
    QCheckBox *cbCurrentLayer;
    QToolButton *toolButton;
    QGroupBox *bgNumber;
    QVBoxLayout *vboxLayout;
    QRadioButton *rbMove;
    QRadioButton *rbCopy;
    QSpacerItem *spacer7;

    void setupUi(QDialog *QG_DlgMirror)
    {
        if (QG_DlgMirror->objectName().isEmpty())
            QG_DlgMirror->setObjectName(QString::fromUtf8("QG_DlgMirror"));
        QG_DlgMirror->resize(357, 195);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgMirror->sizePolicy().hasHeightForWidth());
        QG_DlgMirror->setSizePolicy(sizePolicy);
        QG_DlgMirror->setMinimumSize(QSize(300, 190));
        gridLayout = new QGridLayout(QG_DlgMirror);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(QG_DlgMirror);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);

        cbCurrentAttributes = new QCheckBox(QG_DlgMirror);
        cbCurrentAttributes->setObjectName(QString::fromUtf8("cbCurrentAttributes"));

        gridLayout->addWidget(cbCurrentAttributes, 2, 1, 1, 1);

        cbCurrentLayer = new QCheckBox(QG_DlgMirror);
        cbCurrentLayer->setObjectName(QString::fromUtf8("cbCurrentLayer"));

        gridLayout->addWidget(cbCurrentLayer, 3, 1, 1, 1);

        toolButton = new QToolButton(QG_DlgMirror);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dlgmodifymirror.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(80, 80));

        gridLayout->addWidget(toolButton, 0, 1, 1, 1);

        bgNumber = new QGroupBox(QG_DlgMirror);
        bgNumber->setObjectName(QString::fromUtf8("bgNumber"));
        vboxLayout = new QVBoxLayout(bgNumber);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        rbMove = new QRadioButton(bgNumber);
        rbMove->setObjectName(QString::fromUtf8("rbMove"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rbMove->sizePolicy().hasHeightForWidth());
        rbMove->setSizePolicy(sizePolicy1);
        rbMove->setMinimumSize(QSize(0, 18));

        vboxLayout->addWidget(rbMove);

        rbCopy = new QRadioButton(bgNumber);
        rbCopy->setObjectName(QString::fromUtf8("rbCopy"));
        sizePolicy1.setHeightForWidth(rbCopy->sizePolicy().hasHeightForWidth());
        rbCopy->setSizePolicy(sizePolicy1);
        rbCopy->setMinimumSize(QSize(0, 18));

        vboxLayout->addWidget(rbCopy);

        spacer7 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer7);


        gridLayout->addWidget(bgNumber, 0, 0, 4, 1);


        retranslateUi(QG_DlgMirror);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgMirror, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgMirror, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgMirror);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgMirror)
    {
        QG_DlgMirror->setWindowTitle(QCoreApplication::translate("QG_DlgMirror", "Mirroring Options", nullptr));
        cbCurrentAttributes->setText(QCoreApplication::translate("QG_DlgMirror", "Use current &attributes", nullptr));
        cbCurrentLayer->setText(QCoreApplication::translate("QG_DlgMirror", "Use current &layer", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgMirror", "...", nullptr));
        bgNumber->setTitle(QCoreApplication::translate("QG_DlgMirror", "Number of copies", nullptr));
        rbMove->setText(QCoreApplication::translate("QG_DlgMirror", "&Delete Original", nullptr));
        rbCopy->setText(QCoreApplication::translate("QG_DlgMirror", "&Keep Original", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgMirror: public Ui_QG_DlgMirror {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGMIRROR_H
