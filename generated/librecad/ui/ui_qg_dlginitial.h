/********************************************************************************
** Form generated from reading UI file 'qg_dlginitial.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGINITIAL_H
#define UI_QG_DLGINITIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgInitial
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *lImage;
    QVBoxLayout *vboxLayout1;
    QLabel *lWelcome;
    QGridLayout *gridLayout;
    QComboBox *cbLanguageCmd;
    QComboBox *cbLanguage;
    QComboBox *cbUnit;
    QLabel *lUnit;
    QLabel *lLanguage;
    QLabel *lCmdLanguage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgInitial)
    {
        if (QG_DlgInitial->objectName().isEmpty())
            QG_DlgInitial->setObjectName(QString::fromUtf8("QG_DlgInitial"));
        QG_DlgInitial->resize(413, 340);
        QG_DlgInitial->setSizeGripEnabled(false);
        vboxLayout = new QVBoxLayout(QG_DlgInitial);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(19);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lImage = new QLabel(QG_DlgInitial);
        lImage->setObjectName(QString::fromUtf8("lImage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lImage->sizePolicy().hasHeightForWidth());
        lImage->setSizePolicy(sizePolicy);
        lImage->setFrameShape(QFrame::Shape::WinPanel);
        lImage->setFrameShadow(QFrame::Shadow::Sunken);
        lImage->setLineWidth(1);
        lImage->setPixmap(QPixmap(QString::fromUtf8("image0")));
        lImage->setScaledContents(true);
        lImage->setWordWrap(false);

        hboxLayout->addWidget(lImage);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lWelcome = new QLabel(QG_DlgInitial);
        lWelcome->setObjectName(QString::fromUtf8("lWelcome"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lWelcome->sizePolicy().hasHeightForWidth());
        lWelcome->setSizePolicy(sizePolicy1);
        lWelcome->setAlignment(Qt::AlignmentFlag::AlignVCenter);
        lWelcome->setWordWrap(true);

        vboxLayout1->addWidget(lWelcome);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(14, 14, 14, 14);
        cbLanguageCmd = new QComboBox(QG_DlgInitial);
        cbLanguageCmd->setObjectName(QString::fromUtf8("cbLanguageCmd"));

        gridLayout->addWidget(cbLanguageCmd, 2, 1, 1, 1);

        cbLanguage = new QComboBox(QG_DlgInitial);
        cbLanguage->setObjectName(QString::fromUtf8("cbLanguage"));

        gridLayout->addWidget(cbLanguage, 1, 1, 1, 1);

        cbUnit = new QComboBox(QG_DlgInitial);
        cbUnit->setObjectName(QString::fromUtf8("cbUnit"));

        gridLayout->addWidget(cbUnit, 0, 1, 1, 1);

        lUnit = new QLabel(QG_DlgInitial);
        lUnit->setObjectName(QString::fromUtf8("lUnit"));
        lUnit->setWordWrap(false);

        gridLayout->addWidget(lUnit, 0, 0, 1, 1);

        lLanguage = new QLabel(QG_DlgInitial);
        lLanguage->setObjectName(QString::fromUtf8("lLanguage"));
        lLanguage->setWordWrap(false);

        gridLayout->addWidget(lLanguage, 1, 0, 1, 1);

        lCmdLanguage = new QLabel(QG_DlgInitial);
        lCmdLanguage->setObjectName(QString::fromUtf8("lCmdLanguage"));
        lCmdLanguage->setWordWrap(false);

        gridLayout->addWidget(lCmdLanguage, 2, 0, 1, 1);


        vboxLayout1->addLayout(gridLayout);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(QG_DlgInitial);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(cbUnit, cbLanguage);
        QWidget::setTabOrder(cbLanguage, cbLanguageCmd);

        retranslateUi(QG_DlgInitial);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgInitial, SLOT(ok()));

        QMetaObject::connectSlotsByName(QG_DlgInitial);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgInitial)
    {
        QG_DlgInitial->setWindowTitle(QCoreApplication::translate("QG_DlgInitial", "Welcome", nullptr));
        lWelcome->setText(QCoreApplication::translate("QG_DlgInitial", "<html><head/><body><p><span style=\" font-family:'ui-monospace','SFMono-Regular','SF Mono','Menlo','Consolas','Liberation Mono','monospace'; font-size:14pt; font-weight:700; color:#000000; background-color:#ffffff;\">\346\254\242\350\277\216\344\275\277\347\224\250 LibreCAD</span><span style=\" font-size:14pt;\"><br/></span><span style=\" font-family:'ui-monospace','SFMono-Regular','SF Mono','Menlo','Consolas','Liberation Mono','monospace'; font-size:14pt; color:#000000; background-color:#ffffff;\">\350\257\267\351\200\211\346\213\251\346\226\260\345\233\276\347\272\270\344\275\277\347\224\250\347\232\204\345\215\225\344\275\215\344\273\245\345\217\212\346\202\250\345\201\217\345\245\275\347\232\204\350\257\255\350\250\200\343\200\202</span></p></body></html>", nullptr));
        lUnit->setText(QCoreApplication::translate("QG_DlgInitial", "Default Unit:", nullptr));
        lLanguage->setText(QCoreApplication::translate("QG_DlgInitial", "GUI Language:", nullptr));
        lCmdLanguage->setText(QCoreApplication::translate("QG_DlgInitial", "Command Language:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgInitial: public Ui_QG_DlgInitial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGINITIAL_H
