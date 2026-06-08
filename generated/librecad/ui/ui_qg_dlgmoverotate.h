/********************************************************************************
** Form generated from reading UI file 'qg_dlgmoverotate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGMOVEROTATE_H
#define UI_QG_DLGMOVEROTATE_H

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

class Ui_QG_DlgMoveRotate
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *vboxLayout;
    QToolButton *toolButton;
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QSpacerItem *spacer13;
    QLineEdit *leAngle;
    QCheckBox *cbCurrentAttributes;
    QCheckBox *cbCurrentLayer;
    QGroupBox *bgNumber;
    QVBoxLayout *vboxLayout1;
    QRadioButton *rbMove;
    QRadioButton *rbCopy;
    QRadioButton *rbMultiCopy;
    QLineEdit *leNumber;
    QSpacerItem *spacer7;

    void setupUi(QDialog *QG_DlgMoveRotate)
    {
        if (QG_DlgMoveRotate->objectName().isEmpty())
            QG_DlgMoveRotate->setObjectName(QString::fromUtf8("QG_DlgMoveRotate"));
        QG_DlgMoveRotate->resize(406, 237);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_DlgMoveRotate->sizePolicy().hasHeightForWidth());
        QG_DlgMoveRotate->setSizePolicy(sizePolicy);
        QG_DlgMoveRotate->setMinimumSize(QSize(300, 190));
        gridLayout = new QGridLayout(QG_DlgMoveRotate);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(QG_DlgMoveRotate);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        toolButton = new QToolButton(QG_DlgMoveRotate);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dlgmodifymoverotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(80, 80));

        vboxLayout->addWidget(toolButton);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lAngle = new QLabel(QG_DlgMoveRotate);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        spacer13 = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer13);

        leAngle = new QLineEdit(QG_DlgMoveRotate);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        hboxLayout->addWidget(leAngle);


        vboxLayout->addLayout(hboxLayout);

        cbCurrentAttributes = new QCheckBox(QG_DlgMoveRotate);
        cbCurrentAttributes->setObjectName(QString::fromUtf8("cbCurrentAttributes"));

        vboxLayout->addWidget(cbCurrentAttributes);

        cbCurrentLayer = new QCheckBox(QG_DlgMoveRotate);
        cbCurrentLayer->setObjectName(QString::fromUtf8("cbCurrentLayer"));

        vboxLayout->addWidget(cbCurrentLayer);


        gridLayout->addLayout(vboxLayout, 0, 1, 1, 1);

        bgNumber = new QGroupBox(QG_DlgMoveRotate);
        bgNumber->setObjectName(QString::fromUtf8("bgNumber"));
        vboxLayout1 = new QVBoxLayout(bgNumber);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        rbMove = new QRadioButton(bgNumber);
        rbMove->setObjectName(QString::fromUtf8("rbMove"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rbMove->sizePolicy().hasHeightForWidth());
        rbMove->setSizePolicy(sizePolicy1);
        rbMove->setMinimumSize(QSize(0, 18));

        vboxLayout1->addWidget(rbMove);

        rbCopy = new QRadioButton(bgNumber);
        rbCopy->setObjectName(QString::fromUtf8("rbCopy"));
        sizePolicy1.setHeightForWidth(rbCopy->sizePolicy().hasHeightForWidth());
        rbCopy->setSizePolicy(sizePolicy1);
        rbCopy->setMinimumSize(QSize(0, 18));

        vboxLayout1->addWidget(rbCopy);

        rbMultiCopy = new QRadioButton(bgNumber);
        rbMultiCopy->setObjectName(QString::fromUtf8("rbMultiCopy"));
        sizePolicy1.setHeightForWidth(rbMultiCopy->sizePolicy().hasHeightForWidth());
        rbMultiCopy->setSizePolicy(sizePolicy1);
        rbMultiCopy->setMinimumSize(QSize(0, 18));

        vboxLayout1->addWidget(rbMultiCopy);

        leNumber = new QLineEdit(bgNumber);
        leNumber->setObjectName(QString::fromUtf8("leNumber"));

        vboxLayout1->addWidget(leNumber);

        spacer7 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacer7);


        gridLayout->addWidget(bgNumber, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        lAngle->setBuddy(leAngle);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(rbMove, rbCopy);
        QWidget::setTabOrder(rbCopy, rbMultiCopy);
        QWidget::setTabOrder(rbMultiCopy, leNumber);
        QWidget::setTabOrder(leNumber, leAngle);
        QWidget::setTabOrder(leAngle, cbCurrentAttributes);
        QWidget::setTabOrder(cbCurrentAttributes, cbCurrentLayer);

        retranslateUi(QG_DlgMoveRotate);
        QObject::connect(rbMove, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setDisabled(bool)));
        QObject::connect(rbMultiCopy, SIGNAL(toggled(bool)), leNumber, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgMoveRotate, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgMoveRotate, SLOT(reject()));

        QMetaObject::connectSlotsByName(QG_DlgMoveRotate);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgMoveRotate)
    {
        QG_DlgMoveRotate->setWindowTitle(QCoreApplication::translate("QG_DlgMoveRotate", "Move/Rotate Options", nullptr));
        toolButton->setText(QCoreApplication::translate("QG_DlgMoveRotate", "...", nullptr));
#if QT_CONFIG(shortcut)
        toolButton->setShortcut(QCoreApplication::translate("QG_DlgMoveRotate", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        lAngle->setText(QCoreApplication::translate("QG_DlgMoveRotate", "&Angle (a):", nullptr));
        cbCurrentAttributes->setText(QCoreApplication::translate("QG_DlgMoveRotate", "Use current &attributes", nullptr));
        cbCurrentLayer->setText(QCoreApplication::translate("QG_DlgMoveRotate", "Use current &layer", nullptr));
        bgNumber->setTitle(QCoreApplication::translate("QG_DlgMoveRotate", "Number of copies", nullptr));
        rbMove->setText(QCoreApplication::translate("QG_DlgMoveRotate", "&Delete Original", nullptr));
        rbCopy->setText(QCoreApplication::translate("QG_DlgMoveRotate", "&Keep Original", nullptr));
        rbMultiCopy->setText(QCoreApplication::translate("QG_DlgMoveRotate", "&Multiple Copies", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgMoveRotate: public Ui_QG_DlgMoveRotate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGMOVEROTATE_H
