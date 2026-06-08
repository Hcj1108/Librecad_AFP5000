/********************************************************************************
** Form generated from reading UI file 'qg_dlgimageoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGIMAGEOPTIONS_H
#define UI_QG_DLGIMAGEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_ImageOptionsDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *bgSize;
    QGridLayout *gridLayout1;
    QLabel *lResolution;
    QComboBox *cbResolution;
    QSpacerItem *verticalSpacer;
    QLabel *lWidth;
    QLabel *lHeight;
    QLineEdit *leHeight;
    QLineEdit *leWidth;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *bgBackground;
    QVBoxLayout *vboxLayout;
    QRadioButton *rbWhite;
    QRadioButton *rbBlack;
    QSpacerItem *hspacer1;
    QSpacerItem *vspacer3;
    QGroupBox *bgColouring;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbBlackWhite;
    QRadioButton *rbColoured;
    QSpacerItem *hspacer2;
    QSpacerItem *vspacer4;
    QGroupBox *bgBorders;
    QFormLayout *formLayout;
    QLineEdit *leLeftRight;
    QLineEdit *leTopBottom;
    QLabel *lTopBottom;
    QLabel *lLeftRight;
    QSpacerItem *vspacer5;
    QCheckBox *cbSameBorders;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_ImageOptionsDialog)
    {
        if (QG_ImageOptionsDialog->objectName().isEmpty())
            QG_ImageOptionsDialog->setObjectName(QString::fromUtf8("QG_ImageOptionsDialog"));
        QG_ImageOptionsDialog->resize(449, 545);
        QG_ImageOptionsDialog->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(QG_ImageOptionsDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bgSize = new QGroupBox(QG_ImageOptionsDialog);
        bgSize->setObjectName(QString::fromUtf8("bgSize"));
        gridLayout1 = new QGridLayout(bgSize);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        lResolution = new QLabel(bgSize);
        lResolution->setObjectName(QString::fromUtf8("lResolution"));
        lResolution->setWordWrap(false);

        gridLayout1->addWidget(lResolution, 2, 1, 1, 1);

        cbResolution = new QComboBox(bgSize);
        cbResolution->addItem(QString());
        cbResolution->addItem(QString::fromUtf8("1"));
        cbResolution->addItem(QString::fromUtf8("2"));
        cbResolution->addItem(QString::fromUtf8("3"));
        cbResolution->addItem(QString::fromUtf8("4"));
        cbResolution->addItem(QString::fromUtf8("5"));
        cbResolution->addItem(QString::fromUtf8("10"));
        cbResolution->addItem(QString::fromUtf8("15"));
        cbResolution->addItem(QString::fromUtf8("20"));
        cbResolution->addItem(QString::fromUtf8("25"));
        cbResolution->addItem(QString::fromUtf8("50"));
        cbResolution->addItem(QString::fromUtf8("75"));
        cbResolution->addItem(QString::fromUtf8("100"));
        cbResolution->addItem(QString::fromUtf8("150"));
        cbResolution->addItem(QString::fromUtf8("300"));
        cbResolution->addItem(QString::fromUtf8("600"));
        cbResolution->addItem(QString::fromUtf8("1200"));
        cbResolution->setObjectName(QString::fromUtf8("cbResolution"));
        cbResolution->setEditable(true);

        gridLayout1->addWidget(cbResolution, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(verticalSpacer, 7, 0, 1, 3);

        lWidth = new QLabel(bgSize);
        lWidth->setObjectName(QString::fromUtf8("lWidth"));
        lWidth->setWordWrap(false);

        gridLayout1->addWidget(lWidth, 5, 1, 1, 1);

        lHeight = new QLabel(bgSize);
        lHeight->setObjectName(QString::fromUtf8("lHeight"));
        lHeight->setWordWrap(false);

        gridLayout1->addWidget(lHeight, 6, 1, 1, 1);

        leHeight = new QLineEdit(bgSize);
        leHeight->setObjectName(QString::fromUtf8("leHeight"));
        leHeight->setText(QString::fromUtf8("480"));
        leHeight->setPlaceholderText(QString::fromUtf8(""));

        gridLayout1->addWidget(leHeight, 6, 2, 1, 1);

        leWidth = new QLineEdit(bgSize);
        leWidth->setObjectName(QString::fromUtf8("leWidth"));
        leWidth->setText(QString::fromUtf8("640"));
        leWidth->setPlaceholderText(QString::fromUtf8(""));

        gridLayout1->addWidget(leWidth, 5, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(verticalSpacer_2, 4, 0, 1, 3);


        gridLayout->addWidget(bgSize, 0, 0, 1, 2);

        bgBackground = new QGroupBox(QG_ImageOptionsDialog);
        bgBackground->setObjectName(QString::fromUtf8("bgBackground"));
        vboxLayout = new QVBoxLayout(bgBackground);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        rbWhite = new QRadioButton(bgBackground);
        rbWhite->setObjectName(QString::fromUtf8("rbWhite"));
        rbWhite->setChecked(true);

        vboxLayout->addWidget(rbWhite);

        rbBlack = new QRadioButton(bgBackground);
        rbBlack->setObjectName(QString::fromUtf8("rbBlack"));

        vboxLayout->addWidget(rbBlack);

        hspacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        vboxLayout->addItem(hspacer1);

        vspacer3 = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(vspacer3);


        gridLayout->addWidget(bgBackground, 2, 0, 1, 1);

        bgColouring = new QGroupBox(QG_ImageOptionsDialog);
        bgColouring->setObjectName(QString::fromUtf8("bgColouring"));
        verticalLayout = new QVBoxLayout(bgColouring);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbBlackWhite = new QRadioButton(bgColouring);
        rbBlackWhite->setObjectName(QString::fromUtf8("rbBlackWhite"));
        rbBlackWhite->setChecked(true);

        verticalLayout->addWidget(rbBlackWhite);

        rbColoured = new QRadioButton(bgColouring);
        rbColoured->setObjectName(QString::fromUtf8("rbColoured"));

        verticalLayout->addWidget(rbColoured);

        hspacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(hspacer2);

        vspacer4 = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(vspacer4);


        gridLayout->addWidget(bgColouring, 2, 1, 1, 1);

        bgBorders = new QGroupBox(QG_ImageOptionsDialog);
        bgBorders->setObjectName(QString::fromUtf8("bgBorders"));
        formLayout = new QFormLayout(bgBorders);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        leLeftRight = new QLineEdit(bgBorders);
        leLeftRight->setObjectName(QString::fromUtf8("leLeftRight"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leLeftRight);

        leTopBottom = new QLineEdit(bgBorders);
        leTopBottom->setObjectName(QString::fromUtf8("leTopBottom"));

        formLayout->setWidget(3, QFormLayout::FieldRole, leTopBottom);

        lTopBottom = new QLabel(bgBorders);
        lTopBottom->setObjectName(QString::fromUtf8("lTopBottom"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lTopBottom);

        lLeftRight = new QLabel(bgBorders);
        lLeftRight->setObjectName(QString::fromUtf8("lLeftRight"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lLeftRight);

        vspacer5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::SpanningRole, vspacer5);

        cbSameBorders = new QCheckBox(bgBorders);
        cbSameBorders->setObjectName(QString::fromUtf8("cbSameBorders"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbSameBorders);


        gridLayout->addWidget(bgBorders, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(QG_ImageOptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        QWidget::setTabOrder(leWidth, leHeight);
        QWidget::setTabOrder(leHeight, rbWhite);

        retranslateUi(QG_ImageOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_ImageOptionsDialog, SLOT(ok()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_ImageOptionsDialog, SLOT(reject()));
        QObject::connect(leWidth, SIGNAL(textChanged(QString)), QG_ImageOptionsDialog, SLOT(sizeChanged()));
        QObject::connect(leHeight, SIGNAL(textChanged(QString)), QG_ImageOptionsDialog, SLOT(sizeChanged()));
        QObject::connect(cbResolution, SIGNAL(editTextChanged(QString)), QG_ImageOptionsDialog, SLOT(resolutionChanged()));
        QObject::connect(cbSameBorders, SIGNAL(stateChanged(int)), QG_ImageOptionsDialog, SLOT(sameBordersChanged()));
        QObject::connect(leLeftRight, SIGNAL(textChanged(QString)), QG_ImageOptionsDialog, SLOT(borderChanged()));

        QMetaObject::connectSlotsByName(QG_ImageOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *QG_ImageOptionsDialog)
    {
        QG_ImageOptionsDialog->setWindowTitle(QCoreApplication::translate("QG_ImageOptionsDialog", "Image Export Options", nullptr));
        bgSize->setTitle(QCoreApplication::translate("QG_ImageOptionsDialog", "Bitmap Size", nullptr));
        lResolution->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Resolution:", nullptr));
        cbResolution->setItemText(0, QCoreApplication::translate("QG_ImageOptionsDialog", "auto", nullptr));

        lWidth->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Width:", nullptr));
        lHeight->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Height:", nullptr));
        bgBackground->setTitle(QCoreApplication::translate("QG_ImageOptionsDialog", "Background", nullptr));
        rbWhite->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "White", nullptr));
        rbBlack->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "B&lack", nullptr));
        bgColouring->setTitle(QCoreApplication::translate("QG_ImageOptionsDialog", "Colouring", nullptr));
        rbBlackWhite->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Black / White", nullptr));
        rbColoured->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Coloured", nullptr));
        bgBorders->setTitle(QCoreApplication::translate("QG_ImageOptionsDialog", "Borders", nullptr));
        leLeftRight->setText(QString());
        lTopBottom->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Top / Bottom - Border:", nullptr));
        lLeftRight->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "Left / Right - Border:", nullptr));
        cbSameBorders->setText(QCoreApplication::translate("QG_ImageOptionsDialog", "set same size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_ImageOptionsDialog: public Ui_QG_ImageOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGIMAGEOPTIONS_H
