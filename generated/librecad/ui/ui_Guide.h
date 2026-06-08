/********************************************************************************
** Form generated from reading UI file 'Guide.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDE_H
#define UI_GUIDE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuideClass
{
public:
    QVBoxLayout *mainLayout;
    QWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *btnLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *spacerBtn;
    QPushButton *pushButton_2;

    void setupUi(QWidget *GuideClass)
    {
        if (GuideClass->objectName().isEmpty())
            GuideClass->setObjectName(QString::fromUtf8("GuideClass"));
        GuideClass->resize(839, 605);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GuideClass->sizePolicy().hasHeightForWidth());
        GuideClass->setSizePolicy(sizePolicy);
        GuideClass->setMinimumSize(QSize(700, 550));
        GuideClass->setMaximumSize(QSize(900, 750));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/jiaocheng.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuideClass->setWindowIcon(icon);
        GuideClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(GuideClass);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GuideClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        mainLayout->addWidget(widget);

        widget_2 = new QWidget(GuideClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        btnLayout = new QHBoxLayout(widget_2);
        btnLayout->setSpacing(0);
        btnLayout->setObjectName(QString::fromUtf8("btnLayout"));
        btnLayout->setContentsMargins(0, -1, 0, -1);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 44));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 15px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #2980b9;}"));

        btnLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 44));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 15px \"Microsoft YaHei\"; background: #f39c12; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #e67e22;}"));

        btnLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 44));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 15px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #7f8c8d;}"));

        btnLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 44));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 15px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #7f8c8d;}"));

        btnLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 44));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 15px \"Microsoft YaHei\"; background: #27ae60; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #229954;}"));

        btnLayout->addWidget(pushButton_6);

        spacerBtn = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        btnLayout->addItem(spacerBtn);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(120, 44));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 15px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #c0392b;}"));

        btnLayout->addWidget(pushButton_2);


        mainLayout->addWidget(widget_2);

        mainLayout->setStretch(0, 7);

        retranslateUi(GuideClass);

        QMetaObject::connectSlotsByName(GuideClass);
    } // setupUi

    void retranslateUi(QWidget *GuideClass)
    {
        GuideClass->setWindowTitle(QCoreApplication::translate("GuideClass", "\344\275\277\347\224\250\346\225\231\347\250\213", nullptr));
        pushButton->setText(QCoreApplication::translate("GuideClass", "\351\207\215\346\226\260\351\200\211\346\213\251\350\247\206\351\242\221", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GuideClass", "\346\232\202\345\201\234", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GuideClass", "\342\227\200 \345\233\236\351\200\2005s", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GuideClass", "\345\277\253\350\277\2335s \342\226\266", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GuideClass", "\360\237\223\204 \346\225\231\347\250\213\346\226\207\346\241\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GuideClass", "\345\205\263\351\227\255\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuideClass: public Ui_GuideClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDE_H
