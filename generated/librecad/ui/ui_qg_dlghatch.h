/********************************************************************************
** Form generated from reading UI file 'qg_dlghatch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGHATCH_H
#define UI_QG_DLGHATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include "qg_graphicview.h"
#include "qg_patternbox.h"

QT_BEGIN_NAMESPACE

class Ui_QG_DlgHatch
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *bgParameter;
    QGridLayout *gridLayout;
    QLineEdit *leScale;
    QLineEdit *leAngle;
    QLabel *lAngle;
    QLabel *lScale;
    QG_PatternBox *cbPattern;
    QCheckBox *cbSolid;
    QGroupBox *bgPreview;
    QVBoxLayout *vboxLayout1;
    QCheckBox *cbEnablePreview;
    QG_GraphicView *gvPreview;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgHatch)
    {
        if (QG_DlgHatch->objectName().isEmpty())
            QG_DlgHatch->setObjectName(QString::fromUtf8("QG_DlgHatch"));
        QG_DlgHatch->resize(438, 294);
        vboxLayout = new QVBoxLayout(QG_DlgHatch);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        bgParameter = new QGroupBox(QG_DlgHatch);
        bgParameter->setObjectName(QString::fromUtf8("bgParameter"));
        gridLayout = new QGridLayout(bgParameter);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leScale = new QLineEdit(bgParameter);
        leScale->setObjectName(QString::fromUtf8("leScale"));

        gridLayout->addWidget(leScale, 2, 1, 1, 1);

        leAngle = new QLineEdit(bgParameter);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        gridLayout->addWidget(leAngle, 3, 1, 1, 1);

        lAngle = new QLabel(bgParameter);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        gridLayout->addWidget(lAngle, 3, 0, 1, 1);

        lScale = new QLabel(bgParameter);
        lScale->setObjectName(QString::fromUtf8("lScale"));
        lScale->setWordWrap(false);

        gridLayout->addWidget(lScale, 2, 0, 1, 1);

        cbPattern = new QG_PatternBox(bgParameter);
        cbPattern->setObjectName(QString::fromUtf8("cbPattern"));

        gridLayout->addWidget(cbPattern, 1, 0, 1, 2);

        cbSolid = new QCheckBox(bgParameter);
        cbSolid->setObjectName(QString::fromUtf8("cbSolid"));

        gridLayout->addWidget(cbSolid, 0, 0, 1, 2);


        hboxLayout->addWidget(bgParameter);

        bgPreview = new QGroupBox(QG_DlgHatch);
        bgPreview->setObjectName(QString::fromUtf8("bgPreview"));
        vboxLayout1 = new QVBoxLayout(bgPreview);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        cbEnablePreview = new QCheckBox(bgPreview);
        cbEnablePreview->setObjectName(QString::fromUtf8("cbEnablePreview"));

        vboxLayout1->addWidget(cbEnablePreview);

        gvPreview = new QG_GraphicView(bgPreview);
        gvPreview->setObjectName(QString::fromUtf8("gvPreview"));

        vboxLayout1->addWidget(gvPreview);


        hboxLayout->addWidget(bgPreview);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgHatch);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(cbSolid, leScale);
        QWidget::setTabOrder(leScale, leAngle);
        QWidget::setTabOrder(leAngle, cbEnablePreview);

        retranslateUi(QG_DlgHatch);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgHatch, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgHatch, SLOT(reject()));
        QObject::connect(cbSolid, SIGNAL(toggled(bool)), cbPattern, SLOT(setDisabled(bool)));
        QObject::connect(cbSolid, SIGNAL(toggled(bool)), leScale, SLOT(setDisabled(bool)));
        QObject::connect(cbSolid, SIGNAL(toggled(bool)), lScale, SLOT(setDisabled(bool)));
        QObject::connect(cbSolid, SIGNAL(toggled(bool)), leAngle, SLOT(setDisabled(bool)));
        QObject::connect(cbSolid, SIGNAL(toggled(bool)), lAngle, SLOT(setDisabled(bool)));
        QObject::connect(cbPattern, SIGNAL(patternChanged()), QG_DlgHatch, SLOT(updatePreview()));
        QObject::connect(cbSolid, SIGNAL(toggled(bool)), QG_DlgHatch, SLOT(updatePreview()));
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), QG_DlgHatch, SLOT(updatePreview()));
        QObject::connect(leScale, SIGNAL(textChanged(QString)), QG_DlgHatch, SLOT(updatePreview()));
        QObject::connect(cbEnablePreview, SIGNAL(toggled(bool)), QG_DlgHatch, SLOT(updatePreview()));

        QMetaObject::connectSlotsByName(QG_DlgHatch);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgHatch)
    {
        QG_DlgHatch->setWindowTitle(QCoreApplication::translate("QG_DlgHatch", "Choose Hatch Attributes", nullptr));
        bgParameter->setTitle(QCoreApplication::translate("QG_DlgHatch", "Pattern", nullptr));
        lAngle->setText(QCoreApplication::translate("QG_DlgHatch", "Angle:", nullptr));
        lScale->setText(QCoreApplication::translate("QG_DlgHatch", "Scale:", nullptr));
        cbSolid->setText(QCoreApplication::translate("QG_DlgHatch", "Solid Fill", nullptr));
        bgPreview->setTitle(QCoreApplication::translate("QG_DlgHatch", "Preview", nullptr));
        cbEnablePreview->setText(QCoreApplication::translate("QG_DlgHatch", "Enable Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgHatch: public Ui_QG_DlgHatch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGHATCH_H
