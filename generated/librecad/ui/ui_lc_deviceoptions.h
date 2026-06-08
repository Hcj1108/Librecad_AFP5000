/********************************************************************************
** Form generated from reading UI file 'lc_deviceoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LC_DEVICEOPTIONS_H
#define UI_LC_DEVICEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LC_DeviceOptions
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *device_combobox;
    QPushButton *save_button;

    void setupUi(QFrame *LC_DeviceOptions)
    {
        if (LC_DeviceOptions->objectName().isEmpty())
            LC_DeviceOptions->setObjectName(QString::fromUtf8("LC_DeviceOptions"));
        LC_DeviceOptions->resize(234, 114);
        verticalLayout = new QVBoxLayout(LC_DeviceOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(LC_DeviceOptions);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        device_combobox = new QComboBox(groupBox);
        device_combobox->addItem(QString::fromUtf8("Mouse"));
        device_combobox->addItem(QString::fromUtf8("Tablet"));
        device_combobox->addItem(QString::fromUtf8("Trackpad"));
        device_combobox->addItem(QString::fromUtf8("Touchscreen"));
        device_combobox->setObjectName(QString::fromUtf8("device_combobox"));

        gridLayout->addWidget(device_combobox, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        save_button = new QPushButton(LC_DeviceOptions);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        verticalLayout->addWidget(save_button, 0, Qt::AlignHCenter|Qt::AlignBottom);


        retranslateUi(LC_DeviceOptions);

        QMetaObject::connectSlotsByName(LC_DeviceOptions);
    } // setupUi

    void retranslateUi(QFrame *LC_DeviceOptions)
    {
        LC_DeviceOptions->setWindowTitle(QCoreApplication::translate("LC_DeviceOptions", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LC_DeviceOptions", "Device", nullptr));

        save_button->setText(QCoreApplication::translate("LC_DeviceOptions", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LC_DeviceOptions: public Ui_LC_DeviceOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LC_DEVICEOPTIONS_H
