/********************************************************************************
** Form generated from reading UI file 'qg_dlgrotate2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGROTATE2_H
#define UI_QG_DLGROTATE2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgRotate2
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
    QVBoxLayout *vboxLayout1;
    QToolButton *toolButton;
    QHBoxLayout *hboxLayout;
    QLabel *lAngle1;
    QSpacerItem *spacer13_2;
    QLineEdit *leAngle1;
    QHBoxLayout *hboxLayout1;
    QLabel *lAngle2;
    QSpacerItem *spacer13;
    QLineEdit *leAngle2;
    QCheckBox *cbCurrentAttributes;
    QCheckBox *cbCurrentLayer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgRotate2)
    {
        if (QG_DlgRotate2->objectName().isEmpty())
            QG_DlgRotate2->setObjectName(QString::fromUtf8("QG_DlgRotate2"));
        QG_DlgRotate2->resize(456, 283);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgRotate2->sizePolicy().hasHeightForWidth());
        QG_DlgRotate2->setSizePolicy(sizePolicy);
        QG_DlgRotate2->setMinimumSize(QSize(300, 190));
        gridLayout = new QGridLayout(QG_DlgRotate2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bgNumber = new QGroupBox(QG_DlgRotate2);
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

        spacer7 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer7);


        gridLayout->addWidget(bgNumber, 0, 0, 1, 1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        toolButton = new QToolButton(QG_DlgRotate2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dlgmodifyrotate2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(80, 80));

        vboxLayout1->addWidget(toolButton);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lAngle1 = new QLabel(QG_DlgRotate2);
        lAngle1->setObjectName(QString::fromUtf8("lAngle1"));
        lAngle1->setWordWrap(false);

        hboxLayout->addWidget(lAngle1);

        spacer13_2 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer13_2);

        leAngle1 = new QLineEdit(QG_DlgRotate2);
        leAngle1->setObjectName(QString::fromUtf8("leAngle1"));

        hboxLayout->addWidget(leAngle1);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        lAngle2 = new QLabel(QG_DlgRotate2);
        lAngle2->setObjectName(QString::fromUtf8("lAngle2"));
        lAngle2->setWordWrap(false);

        hboxLayout1->addWidget(lAngle2);

        spacer13 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer13);

        leAngle2 = new QLineEdit(QG_DlgRotate2);
        leAngle2->setObjectName(QString::fromUtf8("leAngle2"));

        hboxLayout1->addWidget(leAngle2);


        vboxLayout1->addLayout(hboxLayout1);

        cbCurrentAttributes = new QCheckBox(QG_DlgRotate2);
        cbCurrentAttributes->setObjectName(QString::fromUtf8("cbCurrentAttributes"));

        vboxLayout1->addWidget(cbCurrentAttributes);

        cbCurrentLayer = new QCheckBox(QG_DlgRotate2);
        cbCurrentLayer->setObjectName(QString::fromUtf8("cbCurrentLayer"));

        vboxLayout1->addWidget(cbCurrentLayer);


        gridLayout->addLayout(vboxLayout1, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(QG_DlgRotate2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);

#if QT_CONFIG(shortcut)
        lAngle1->setBuddy(leAngle1);
        lAngle2->setBuddy(leAngle2);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QG_DlgRotate2);
        QObject::connect(rbMove, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbMultiCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgRotate2, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgRotate2, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgRotate2);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgRotate2)
    {
        QG_DlgRotate2->setWindowTitle(QCoreApplication::translate("QG_DlgRotate2", "Rotate Two Options", nullptr));
        bgNumber->setTitle(QCoreApplication::translate("QG_DlgRotate2", "Number of copies", nullptr));
        rbMove->setText(QCoreApplication::translate("QG_DlgRotate2", "&Delete Original", nullptr));
        rbCopy->setText(QCoreApplication::translate("QG_DlgRotate2", "&Keep Original", nullptr));
        rbMultiCopy->setText(QCoreApplication::translate("QG_DlgRotate2", "&Multiple Copies", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgRotate2", "...", nullptr));
        lAngle1->setText(QCoreApplication::translate("QG_DlgRotate2", "Angle (&a):", nullptr));
        lAngle2->setText(QCoreApplication::translate("QG_DlgRotate2", "Angle (&b):", nullptr));
        cbCurrentAttributes->setText(QCoreApplication::translate("QG_DlgRotate2", "Use current &attributes", nullptr));
        cbCurrentLayer->setText(QCoreApplication::translate("QG_DlgRotate2", "Use current &layer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgRotate2: public Ui_QG_DlgRotate2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGROTATE2_H
