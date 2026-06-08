/********************************************************************************
** Form generated from reading UI file 'qg_dlgscale.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGSCALE_H
#define UI_QG_DLGSCALE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgScale
{
public:
    QGroupBox *bgNumber;
    QVBoxLayout *vboxLayout;
    QRadioButton *rbMove;
    QRadioButton *rbCopy;
    QRadioButton *rbMultiCopy;
    QLineEdit *leNumber;
    QSpacerItem *spacer7;
    QToolButton *toolButton;
    QWidget *layoutWidget_1;
    QHBoxLayout *hboxLayout;
    QCheckBox *cbIsotropic;
    QCheckBox *cbCurrentLayer;
    QCheckBox *cbCurrentAttributes;
    QWidget *layoutWidget_2;
    QHBoxLayout *_2;
    QLabel *lFactor;
    QLineEdit *leFactorX;
    QSpacerItem *horizontalSpacer;
    QLabel *lFactor_2;
    QLineEdit *leFactorY;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgScale)
    {
        if (QG_DlgScale->objectName().isEmpty())
            QG_DlgScale->setObjectName(QString::fromUtf8("QG_DlgScale"));
        QG_DlgScale->resize(422, 277);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgScale->sizePolicy().hasHeightForWidth());
        QG_DlgScale->setSizePolicy(sizePolicy);
        QG_DlgScale->setMinimumSize(QSize(300, 190));
        bgNumber = new QGroupBox(QG_DlgScale);
        bgNumber->setObjectName(QString::fromUtf8("bgNumber"));
        bgNumber->setGeometry(QRect(9, 9, 159, 165));
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

        spacer7 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacer7);

        toolButton = new QToolButton(QG_DlgScale);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(175, 10, 86, 88));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dlgmodifyscale.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(80, 80));
        layoutWidget_1 = new QWidget(QG_DlgScale);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(180, 100, 237, 41));
        hboxLayout = new QHBoxLayout(layoutWidget_1);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        cbIsotropic = new QCheckBox(layoutWidget_1);
        cbIsotropic->setObjectName(QString::fromUtf8("cbIsotropic"));
        cbIsotropic->setChecked(true);

        hboxLayout->addWidget(cbIsotropic);

        cbCurrentLayer = new QCheckBox(QG_DlgScale);
        cbCurrentLayer->setObjectName(QString::fromUtf8("cbCurrentLayer"));
        cbCurrentLayer->setGeometry(QRect(175, 210, 146, 21));
        cbCurrentAttributes = new QCheckBox(QG_DlgScale);
        cbCurrentAttributes->setObjectName(QString::fromUtf8("cbCurrentAttributes"));
        cbCurrentAttributes->setGeometry(QRect(175, 190, 179, 21));
        layoutWidget_2 = new QWidget(QG_DlgScale);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(180, 140, 237, 41));
        _2 = new QHBoxLayout(layoutWidget_2);
        _2->setSpacing(6);
        _2->setContentsMargins(11, 11, 11, 11);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(0, 0, 0, 0);
        lFactor = new QLabel(layoutWidget_2);
        lFactor->setObjectName(QString::fromUtf8("lFactor"));
        lFactor->setWordWrap(false);

        _2->addWidget(lFactor);

        leFactorX = new QLineEdit(layoutWidget_2);
        leFactorX->setObjectName(QString::fromUtf8("leFactorX"));
        leFactorX->setText(QString::fromUtf8("1.0"));

        _2->addWidget(leFactorX);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(horizontalSpacer);

        lFactor_2 = new QLabel(layoutWidget_2);
        lFactor_2->setObjectName(QString::fromUtf8("lFactor_2"));
        lFactor_2->setWordWrap(false);

        _2->addWidget(lFactor_2);

        leFactorY = new QLineEdit(layoutWidget_2);
        leFactorY->setObjectName(QString::fromUtf8("leFactorY"));
        leFactorY->setText(QString::fromUtf8("1.0"));
        leFactorY->setReadOnly(true);

        _2->addWidget(leFactorY);

        buttonBox = new QDialogButtonBox(QG_DlgScale);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 250, 401, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(QG_DlgScale);
        QObject::connect(rbMove, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbMultiCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgScale, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgScale, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgScale);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgScale)
    {
        QG_DlgScale->setWindowTitle(QCoreApplication::translate("QG_DlgScale", "Scaling Options", nullptr));
        bgNumber->setTitle(QCoreApplication::translate("QG_DlgScale", "Number of copies", nullptr));
        rbMove->setText(QCoreApplication::translate("QG_DlgScale", "&Delete Original", nullptr));
        rbCopy->setText(QCoreApplication::translate("QG_DlgScale", "&Keep Original", nullptr));
        rbMultiCopy->setText(QCoreApplication::translate("QG_DlgScale", "&Multiple Copies", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgScale", "...", nullptr));
#if QT_CONFIG(tooltip)
        cbIsotropic->setToolTip(QCoreApplication::translate("QG_DlgScale", "Scale by the same factor at both x- and y- directions", nullptr));
#endif // QT_CONFIG(tooltip)
        cbIsotropic->setText(QCoreApplication::translate("QG_DlgScale", "Isotropic Scaling", nullptr));
        cbCurrentLayer->setText(QCoreApplication::translate("QG_DlgScale", "Use current &layer", nullptr));
        cbCurrentAttributes->setText(QCoreApplication::translate("QG_DlgScale", "Use current &attributes", nullptr));
        lFactor->setText(QCoreApplication::translate("QG_DlgScale", "X", nullptr));
        lFactor_2->setText(QCoreApplication::translate("QG_DlgScale", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgScale: public Ui_QG_DlgScale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGSCALE_H
