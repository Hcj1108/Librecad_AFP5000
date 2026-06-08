/********************************************************************************
** Form generated from reading UI file 'qg_dlgmove.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGMOVE_H
#define UI_QG_DLGMOVE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgMove
{
public:
    QGridLayout *gridLayout;
    QGroupBox *bgNumber;
    QVBoxLayout *vboxLayout;
    QRadioButton *rbMove;
    QRadioButton *rbCopy;
    QRadioButton *rbMultiCopy;
    QLineEdit *leNumber;
    QSpacerItem *spacer7;
    QCheckBox *cbCurrentAttributes;
    QCheckBox *cbCurrentLayer;
    QToolButton *toolButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgMove)
    {
        if (QG_DlgMove->objectName().isEmpty())
            QG_DlgMove->setObjectName(QString::fromUtf8("QG_DlgMove"));
        QG_DlgMove->resize(398, 218);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgMove->sizePolicy().hasHeightForWidth());
        QG_DlgMove->setSizePolicy(sizePolicy);
        QG_DlgMove->setMinimumSize(QSize(300, 190));
        gridLayout = new QGridLayout(QG_DlgMove);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bgNumber = new QGroupBox(QG_DlgMove);
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

        rbMultiCopy = new QRadioButton(bgNumber);
        rbMultiCopy->setObjectName(QString::fromUtf8("rbMultiCopy"));
        sizePolicy1.setHeightForWidth(rbMultiCopy->sizePolicy().hasHeightForWidth());
        rbMultiCopy->setSizePolicy(sizePolicy1);
        rbMultiCopy->setMinimumSize(QSize(0, 18));

        vboxLayout->addWidget(rbMultiCopy);

        leNumber = new QLineEdit(bgNumber);
        leNumber->setObjectName(QString::fromUtf8("leNumber"));

        vboxLayout->addWidget(leNumber);

        spacer7 = new QSpacerItem(20, 130, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer7);


        gridLayout->addWidget(bgNumber, 0, 0, 3, 1);

        cbCurrentAttributes = new QCheckBox(QG_DlgMove);
        cbCurrentAttributes->setObjectName(QString::fromUtf8("cbCurrentAttributes"));

        gridLayout->addWidget(cbCurrentAttributes, 1, 1, 1, 1);

        cbCurrentLayer = new QCheckBox(QG_DlgMove);
        cbCurrentLayer->setObjectName(QString::fromUtf8("cbCurrentLayer"));

        gridLayout->addWidget(cbCurrentLayer, 2, 1, 1, 1);

        toolButton = new QToolButton(QG_DlgMove);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dlgmove1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(80, 80));

        gridLayout->addWidget(toolButton, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(QG_DlgMove);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(QG_DlgMove);
        QObject::connect(rbMove, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbMultiCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgMove, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgMove, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgMove);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgMove)
    {
        QG_DlgMove->setWindowTitle(QCoreApplication::translate("QG_DlgMove", "Move/Copy Options", nullptr));
        bgNumber->setTitle(QCoreApplication::translate("QG_DlgMove", "Number of copies", nullptr));
        rbMove->setText(QCoreApplication::translate("QG_DlgMove", "&Delete Original", nullptr));
        rbCopy->setText(QCoreApplication::translate("QG_DlgMove", "&Keep Original", nullptr));
        rbMultiCopy->setText(QCoreApplication::translate("QG_DlgMove", "&Multiple Copies", nullptr));
#if QT_CONFIG(tooltip)
        leNumber->setToolTip(QCoreApplication::translate("QG_DlgMove", "Number of copies. Maximum 100", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCurrentAttributes->setText(QCoreApplication::translate("QG_DlgMove", "Use current &attributes", nullptr));
        cbCurrentLayer->setText(QCoreApplication::translate("QG_DlgMove", "Use current &layer", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgMove", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgMove: public Ui_QG_DlgMove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGMOVE_H
