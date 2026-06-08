/********************************************************************************
** Form generated from reading UI file 'comboboxoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBOBOXOPTION_H
#define UI_COMBOBOXOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ComboBoxOption
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QFrame *ComboBoxOption)
    {
        if (ComboBoxOption->objectName().isEmpty())
            ComboBoxOption->setObjectName(QString::fromUtf8("ComboBoxOption"));
        ComboBoxOption->resize(265, 82);
        ComboBoxOption->setFrameShape(QFrame::StyledPanel);
        ComboBoxOption->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(ComboBoxOption);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ComboBoxOption);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        retranslateUi(ComboBoxOption);

        QMetaObject::connectSlotsByName(ComboBoxOption);
    } // setupUi

    void retranslateUi(QFrame *ComboBoxOption)
    {
        ComboBoxOption->setWindowTitle(QCoreApplication::translate("ComboBoxOption", "Frame", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ComboBoxOption", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("ComboBoxOption", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComboBoxOption: public Ui_ComboBoxOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBOBOXOPTION_H
