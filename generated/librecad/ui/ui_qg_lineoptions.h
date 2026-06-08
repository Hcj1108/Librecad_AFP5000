/********************************************************************************
** Form generated from reading UI file 'qg_lineoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINEOPTIONS_H
#define UI_QG_LINEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LineOptions
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *bClose;
    QToolButton *bUndo;
    QToolButton *bRedo;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LineOptions)
    {
        if (Ui_LineOptions->objectName().isEmpty())
            Ui_LineOptions->setObjectName(QString::fromUtf8("Ui_LineOptions"));
        Ui_LineOptions->resize(152, 26);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LineOptions->sizePolicy().hasHeightForWidth());
        Ui_LineOptions->setSizePolicy(sizePolicy);
        Ui_LineOptions->setMinimumSize(QSize(94, 22));
        Ui_LineOptions->setMaximumSize(QSize(400, 32));
        horizontalLayout = new QHBoxLayout(Ui_LineOptions);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 0, 0, 0);
        bClose = new QToolButton(Ui_LineOptions);
        bClose->setObjectName(QString::fromUtf8("bClose"));
        bClose->setIconSize(QSize(24, 22));
        bClose->setCheckable(false);

        horizontalLayout->addWidget(bClose);

        bUndo = new QToolButton(Ui_LineOptions);
        bUndo->setObjectName(QString::fromUtf8("bUndo"));

        horizontalLayout->addWidget(bUndo);

        bRedo = new QToolButton(Ui_LineOptions);
        bRedo->setObjectName(QString::fromUtf8("bRedo"));

        horizontalLayout->addWidget(bRedo);

        sep1 = new QFrame(Ui_LineOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sep1);


        retranslateUi(Ui_LineOptions);
        QObject::connect(bClose, SIGNAL(clicked()), Ui_LineOptions, SLOT(close()));
        QObject::connect(bUndo, SIGNAL(clicked()), Ui_LineOptions, SLOT(undo()));
        QObject::connect(bRedo, SIGNAL(clicked()), Ui_LineOptions, SLOT(redo()));

        QMetaObject::connectSlotsByName(Ui_LineOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LineOptions)
    {
        Ui_LineOptions->setWindowTitle(QCoreApplication::translate("Ui_LineOptions", "Line Options", nullptr));
#if QT_CONFIG(tooltip)
        bClose->setToolTip(QCoreApplication::translate("Ui_LineOptions", "Form a closed contour from lines drawn", nullptr));
#endif // QT_CONFIG(tooltip)
        bClose->setText(QCoreApplication::translate("Ui_LineOptions", "Close", nullptr));
#if QT_CONFIG(tooltip)
        bUndo->setToolTip(QCoreApplication::translate("Ui_LineOptions", "Undo the last line drawing", nullptr));
#endif // QT_CONFIG(tooltip)
        bUndo->setText(QCoreApplication::translate("Ui_LineOptions", "Undo", nullptr));
#if QT_CONFIG(tooltip)
        bRedo->setToolTip(QCoreApplication::translate("Ui_LineOptions", "Redo the last line drawing", nullptr));
#endif // QT_CONFIG(tooltip)
        bRedo->setText(QCoreApplication::translate("Ui_LineOptions", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_LineOptions: public Ui_Ui_LineOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINEOPTIONS_H
