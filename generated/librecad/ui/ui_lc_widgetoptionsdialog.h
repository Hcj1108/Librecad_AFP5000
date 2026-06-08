/********************************************************************************
** Form generated from reading UI file 'lc_widgetoptionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LC_WIDGETOPTIONSDIALOG_H
#define UI_LC_WIDGETOPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_LC_WidgetOptionsDialog
{
public:
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *toolbar_icon_size_checkbox;
    QSpinBox *toolbar_icon_size_spinbox;
    QCheckBox *theme_checkbox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QCheckBox *style_checkbox;
    QComboBox *style_combobox;
    QPushButton *stylesheet_button;
    QLineEdit *stylesheet_field;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QCheckBox *statusbar_height_checkbox;
    QSpinBox *statusbar_height_spinbox;
    QCheckBox *statusbar_fontsize_checkbox;
    QSpinBox *statusbar_fontsize_spinbox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LC_WidgetOptionsDialog)
    {
        if (LC_WidgetOptionsDialog->objectName().isEmpty())
            LC_WidgetOptionsDialog->setObjectName(QString::fromUtf8("LC_WidgetOptionsDialog"));
        LC_WidgetOptionsDialog->resize(326, 417);
        gridLayout_4 = new QGridLayout(LC_WidgetOptionsDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        frame = new QFrame(LC_WidgetOptionsDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        toolbar_icon_size_checkbox = new QCheckBox(groupBox);
        toolbar_icon_size_checkbox->setObjectName(QString::fromUtf8("toolbar_icon_size_checkbox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolbar_icon_size_checkbox->sizePolicy().hasHeightForWidth());
        toolbar_icon_size_checkbox->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(toolbar_icon_size_checkbox, 1, 0, 1, 1);

        toolbar_icon_size_spinbox = new QSpinBox(groupBox);
        toolbar_icon_size_spinbox->setObjectName(QString::fromUtf8("toolbar_icon_size_spinbox"));
        sizePolicy1.setHeightForWidth(toolbar_icon_size_spinbox->sizePolicy().hasHeightForWidth());
        toolbar_icon_size_spinbox->setSizePolicy(sizePolicy1);
        toolbar_icon_size_spinbox->setMinimum(8);
        toolbar_icon_size_spinbox->setMaximum(150);
        toolbar_icon_size_spinbox->setValue(24);

        gridLayout_2->addWidget(toolbar_icon_size_spinbox, 1, 1, 1, 1);

        theme_checkbox = new QCheckBox(groupBox);
        theme_checkbox->setObjectName(QString::fromUtf8("theme_checkbox"));

        gridLayout_2->addWidget(theme_checkbox, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        style_checkbox = new QCheckBox(groupBox_3);
        style_checkbox->setObjectName(QString::fromUtf8("style_checkbox"));
        sizePolicy1.setHeightForWidth(style_checkbox->sizePolicy().hasHeightForWidth());
        style_checkbox->setSizePolicy(sizePolicy1);
        style_checkbox->setTristate(false);

        gridLayout_6->addWidget(style_checkbox, 0, 0, 1, 1);

        style_combobox = new QComboBox(groupBox_3);
        style_combobox->setObjectName(QString::fromUtf8("style_combobox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(style_combobox->sizePolicy().hasHeightForWidth());
        style_combobox->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(style_combobox, 0, 1, 1, 1);

        stylesheet_button = new QPushButton(groupBox_3);
        stylesheet_button->setObjectName(QString::fromUtf8("stylesheet_button"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stylesheet_button->sizePolicy().hasHeightForWidth());
        stylesheet_button->setSizePolicy(sizePolicy3);

        gridLayout_6->addWidget(stylesheet_button, 1, 0, 1, 1);

        stylesheet_field = new QLineEdit(groupBox_3);
        stylesheet_field->setObjectName(QString::fromUtf8("stylesheet_field"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stylesheet_field->sizePolicy().hasHeightForWidth());
        stylesheet_field->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(stylesheet_field, 2, 0, 1, 2);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        statusbar_height_checkbox = new QCheckBox(groupBox_2);
        statusbar_height_checkbox->setObjectName(QString::fromUtf8("statusbar_height_checkbox"));

        gridLayout_5->addWidget(statusbar_height_checkbox, 0, 0, 1, 1);

        statusbar_height_spinbox = new QSpinBox(groupBox_2);
        statusbar_height_spinbox->setObjectName(QString::fromUtf8("statusbar_height_spinbox"));

        gridLayout_5->addWidget(statusbar_height_spinbox, 0, 1, 1, 1);

        statusbar_fontsize_checkbox = new QCheckBox(groupBox_2);
        statusbar_fontsize_checkbox->setObjectName(QString::fromUtf8("statusbar_fontsize_checkbox"));

        gridLayout_5->addWidget(statusbar_fontsize_checkbox, 1, 0, 1, 1);

        statusbar_fontsize_spinbox = new QSpinBox(groupBox_2);
        statusbar_fontsize_spinbox->setObjectName(QString::fromUtf8("statusbar_fontsize_spinbox"));

        gridLayout_5->addWidget(statusbar_fontsize_spinbox, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);


        gridLayout_4->addWidget(frame, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(LC_WidgetOptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);

        gridLayout_4->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(LC_WidgetOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LC_WidgetOptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LC_WidgetOptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LC_WidgetOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *LC_WidgetOptionsDialog)
    {
        LC_WidgetOptionsDialog->setWindowTitle(QCoreApplication::translate("LC_WidgetOptionsDialog", "Widget Options", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LC_WidgetOptionsDialog", "Toolbar", nullptr));
        toolbar_icon_size_checkbox->setText(QCoreApplication::translate("LC_WidgetOptionsDialog", "Icon Size", nullptr));
#if QT_CONFIG(tooltip)
        toolbar_icon_size_spinbox->setToolTip(QCoreApplication::translate("LC_WidgetOptionsDialog", "side length in pixels", nullptr));
#endif // QT_CONFIG(tooltip)
        theme_checkbox->setText(QCoreApplication::translate("LC_WidgetOptionsDialog", "Use themed icons", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("LC_WidgetOptionsDialog", "General", nullptr));
        style_checkbox->setText(QCoreApplication::translate("LC_WidgetOptionsDialog", "Style", nullptr));
        stylesheet_button->setText(QCoreApplication::translate("LC_WidgetOptionsDialog", "Style Sheet", nullptr));
#if QT_CONFIG(tooltip)
        stylesheet_field->setToolTip(QCoreApplication::translate("LC_WidgetOptionsDialog", "Input the path of a Qt style sheet.", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_2->setTitle(QCoreApplication::translate("LC_WidgetOptionsDialog", "Statusbar", nullptr));
        statusbar_height_checkbox->setText(QCoreApplication::translate("LC_WidgetOptionsDialog", "Height", nullptr));
        statusbar_fontsize_checkbox->setText(QCoreApplication::translate("LC_WidgetOptionsDialog", "Font Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LC_WidgetOptionsDialog: public Ui_LC_WidgetOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LC_WIDGETOPTIONSDIALOG_H
