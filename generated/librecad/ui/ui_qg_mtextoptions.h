/********************************************************************************
** Form generated from reading UI file 'qg_mtextoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_MTEXTOPTIONS_H
#define UI_QG_MTEXTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_MTextOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lText;
    QTextEdit *teText;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QFrame *sep1;

    void setupUi(QWidget *Ui_MTextOptions)
    {
        if (Ui_MTextOptions->objectName().isEmpty())
            Ui_MTextOptions->setObjectName(QString::fromUtf8("Ui_MTextOptions"));
        Ui_MTextOptions->resize(300, 24);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_MTextOptions->sizePolicy().hasHeightForWidth());
        Ui_MTextOptions->setSizePolicy(sizePolicy);
        Ui_MTextOptions->setMinimumSize(QSize(200, 22));
        Ui_MTextOptions->setMaximumSize(QSize(300, 32767));
        hboxLayout = new QHBoxLayout(Ui_MTextOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lText = new QLabel(Ui_MTextOptions);
        lText->setObjectName(QString::fromUtf8("lText"));
        lText->setWordWrap(false);

        hboxLayout->addWidget(lText);

        teText = new QTextEdit(Ui_MTextOptions);
        teText->setObjectName(QString::fromUtf8("teText"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(teText->sizePolicy().hasHeightForWidth());
        teText->setSizePolicy(sizePolicy1);
        teText->setMinimumSize(QSize(0, 22));
        teText->setMaximumSize(QSize(32767, 22));
        teText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        teText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        hboxLayout->addWidget(teText);

        lAngle = new QLabel(Ui_MTextOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_MTextOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        hboxLayout->addWidget(leAngle);

        sep1 = new QFrame(Ui_MTextOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_MTextOptions);
        QObject::connect(teText, SIGNAL(textChanged()), Ui_MTextOptions, SLOT(updateText()));
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_MTextOptions, SLOT(updateAngle()));

        QMetaObject::connectSlotsByName(Ui_MTextOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_MTextOptions)
    {
        Ui_MTextOptions->setWindowTitle(QCoreApplication::translate("Ui_MTextOptions", "Text Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_MTextOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lText->setText(QCoreApplication::translate("Ui_MTextOptions", "Text:", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_MTextOptions", "Angle:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_MTextOptions: public Ui_Ui_MTextOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_MTEXTOPTIONS_H
