/********************************************************************************
** Form generated from reading UI file 'colorwizard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORWIZARD_H
#define UI_COLORWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "colorcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_ColorWizard
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_0;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *add_button;
    ColorComboBox *combo;
    QToolButton *colorwin_button;
    QListWidget *fav_list;

    void setupUi(QFrame *ColorWizard)
    {
        if (ColorWizard->objectName().isEmpty())
            ColorWizard->setObjectName(QString::fromUtf8("ColorWizard"));
        ColorWizard->resize(305, 200);
        ColorWizard->setFrameShape(QFrame::StyledPanel);
        ColorWizard->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(ColorWizard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_0 = new QFrame(ColorWizard);
        frame_0->setObjectName(QString::fromUtf8("frame_0"));
        frame_0->setFrameShape(QFrame::StyledPanel);
        frame_0->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        add_button = new QToolButton(frame_0);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/char_pm.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_button->setIcon(icon);
        add_button->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(add_button);

        combo = new ColorComboBox(frame_0);
        combo->setObjectName(QString::fromUtf8("combo"));
#if QT_CONFIG(tooltip)
        combo->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)

        horizontalLayout_2->addWidget(combo);

        colorwin_button = new QToolButton(frame_0);
        colorwin_button->setObjectName(QString::fromUtf8("colorwin_button"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ui/colorxx.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorwin_button->setIcon(icon1);
        colorwin_button->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(colorwin_button);


        verticalLayout->addWidget(frame_0);

        fav_list = new QListWidget(ColorWizard);
        fav_list->setObjectName(QString::fromUtf8("fav_list"));

        verticalLayout->addWidget(fav_list);


        retranslateUi(ColorWizard);

        QMetaObject::connectSlotsByName(ColorWizard);
    } // setupUi

    void retranslateUi(QFrame *ColorWizard)
    {
        ColorWizard->setWindowTitle(QCoreApplication::translate("ColorWizard", "Frame", nullptr));
#if QT_CONFIG(tooltip)
        add_button->setToolTip(QCoreApplication::translate("ColorWizard", "Add to favorites", nullptr));
#endif // QT_CONFIG(tooltip)
        add_button->setText(QCoreApplication::translate("ColorWizard", "...", nullptr));
        colorwin_button->setText(QCoreApplication::translate("ColorWizard", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorWizard: public Ui_ColorWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORWIZARD_H
