/********************************************************************************
** Form generated from reading UI file 'widgetcreator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCREATOR_H
#define UI_WIDGETCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "actionlist.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetCreator
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *categories_combobox;
    ActionList *offered_actions;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *add_button;
    QPushButton *remove_button;
    QFrame *widget_list;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *combo;
    ActionList *chosen_actions;
    QFrame *button_frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *create_button;
    QPushButton *destroy_button;
    QPushButton *assign_button;
    QPushButton *update_button;

    void setupUi(QFrame *WidgetCreator)
    {
        if (WidgetCreator->objectName().isEmpty())
            WidgetCreator->setObjectName(QString::fromUtf8("WidgetCreator"));
        WidgetCreator->resize(684, 522);
        WidgetCreator->setFrameShape(QFrame::StyledPanel);
        WidgetCreator->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(WidgetCreator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(WidgetCreator);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        categories_combobox = new QComboBox(frame_6);
        categories_combobox->setObjectName(QString::fromUtf8("categories_combobox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(categories_combobox->sizePolicy().hasHeightForWidth());
        categories_combobox->setSizePolicy(sizePolicy);
        categories_combobox->setEditable(true);

        horizontalLayout_4->addWidget(categories_combobox);


        verticalLayout_2->addWidget(frame_6);

        offered_actions = new ActionList(frame_2);
        offered_actions->setObjectName(QString::fromUtf8("offered_actions"));

        verticalLayout_2->addWidget(offered_actions);


        horizontalLayout->addWidget(frame_2);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        add_button = new QPushButton(frame_5);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(add_button->sizePolicy().hasHeightForWidth());
        add_button->setSizePolicy(sizePolicy2);
        add_button->setIconSize(QSize(32, 32));

        verticalLayout_4->addWidget(add_button);

        remove_button = new QPushButton(frame_5);
        remove_button->setObjectName(QString::fromUtf8("remove_button"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(remove_button->sizePolicy().hasHeightForWidth());
        remove_button->setSizePolicy(sizePolicy3);
        remove_button->setIconSize(QSize(32, 32));

        verticalLayout_4->addWidget(remove_button);


        horizontalLayout->addWidget(frame_5, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        widget_list = new QFrame(frame);
        widget_list->setObjectName(QString::fromUtf8("widget_list"));
        widget_list->setFrameShape(QFrame::StyledPanel);
        widget_list->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(widget_list);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_3 = new QFrame(widget_list);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(label);

        combo = new QComboBox(frame_3);
        combo->setObjectName(QString::fromUtf8("combo"));
        combo->setEditable(true);

        horizontalLayout_3->addWidget(combo);


        verticalLayout_3->addWidget(frame_3);

        chosen_actions = new ActionList(widget_list);
        chosen_actions->setObjectName(QString::fromUtf8("chosen_actions"));

        verticalLayout_3->addWidget(chosen_actions);


        horizontalLayout->addWidget(widget_list);


        verticalLayout->addWidget(frame);

        button_frame = new QFrame(WidgetCreator);
        button_frame->setObjectName(QString::fromUtf8("button_frame"));
        button_frame->setFrameShape(QFrame::StyledPanel);
        button_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(button_frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        create_button = new QPushButton(button_frame);
        create_button->setObjectName(QString::fromUtf8("create_button"));
        sizePolicy2.setHeightForWidth(create_button->sizePolicy().hasHeightForWidth());
        create_button->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(create_button);

        destroy_button = new QPushButton(button_frame);
        destroy_button->setObjectName(QString::fromUtf8("destroy_button"));
        sizePolicy2.setHeightForWidth(destroy_button->sizePolicy().hasHeightForWidth());
        destroy_button->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(destroy_button);

        assign_button = new QPushButton(button_frame);
        assign_button->setObjectName(QString::fromUtf8("assign_button"));

        horizontalLayout_2->addWidget(assign_button);

        update_button = new QPushButton(button_frame);
        update_button->setObjectName(QString::fromUtf8("update_button"));

        horizontalLayout_2->addWidget(update_button);


        verticalLayout->addWidget(button_frame, 0, Qt::AlignHCenter);


        retranslateUi(WidgetCreator);

        QMetaObject::connectSlotsByName(WidgetCreator);
    } // setupUi

    void retranslateUi(QFrame *WidgetCreator)
    {
        WidgetCreator->setWindowTitle(QCoreApplication::translate("WidgetCreator", "Frame", nullptr));
        add_button->setText(QCoreApplication::translate("WidgetCreator", ">", nullptr));
        remove_button->setText(QCoreApplication::translate("WidgetCreator", "<", nullptr));
        label->setText(QCoreApplication::translate("WidgetCreator", "Name", nullptr));
        create_button->setText(QCoreApplication::translate("WidgetCreator", "Create", nullptr));
        destroy_button->setText(QCoreApplication::translate("WidgetCreator", "Destroy", nullptr));
        assign_button->setText(QCoreApplication::translate("WidgetCreator", "Assign", nullptr));
        update_button->setText(QCoreApplication::translate("WidgetCreator", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetCreator: public Ui_WidgetCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCREATOR_H
