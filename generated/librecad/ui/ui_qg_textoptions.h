/********************************************************************************
** Form generated from reading UI file 'qg_textoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_TEXTOPTIONS_H
#define UI_QG_TEXTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_TextOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lText;
    QTextEdit *teText;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QFrame *sep1;

    void setupUi(QWidget *Ui_TextOptions)
    {
        if (Ui_TextOptions->objectName().isEmpty())
            Ui_TextOptions->setObjectName(QString::fromUtf8("Ui_TextOptions"));
        Ui_TextOptions->resize(300, 24);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_TextOptions->sizePolicy().hasHeightForWidth());
        Ui_TextOptions->setSizePolicy(sizePolicy);
        Ui_TextOptions->setMinimumSize(QSize(200, 22));
        Ui_TextOptions->setMaximumSize(QSize(300, 32767));
        hboxLayout = new QHBoxLayout(Ui_TextOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lText = new QLabel(Ui_TextOptions);
        lText->setObjectName(QString::fromUtf8("lText"));
        lText->setWordWrap(false);

        hboxLayout->addWidget(lText);

        teText = new QTextEdit(Ui_TextOptions);
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

        lAngle = new QLabel(Ui_TextOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_TextOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        hboxLayout->addWidget(leAngle);

        sep1 = new QFrame(Ui_TextOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_TextOptions);
        QObject::connect(teText, SIGNAL(textChanged()), Ui_TextOptions, SLOT(updateText()));
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_TextOptions, SLOT(updateAngle()));

        QMetaObject::connectSlotsByName(Ui_TextOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_TextOptions)
    {
        Ui_TextOptions->setWindowTitle(QCoreApplication::translate("Ui_TextOptions", "Text Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_TextOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lText->setText(QCoreApplication::translate("Ui_TextOptions", "Text:", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_TextOptions", "Angle:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_TextOptions: public Ui_Ui_TextOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_TEXTOPTIONS_H
