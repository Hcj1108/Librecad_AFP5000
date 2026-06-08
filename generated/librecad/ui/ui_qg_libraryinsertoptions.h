/********************************************************************************
** Form generated from reading UI file 'qg_libraryinsertoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LIBRARYINSERTOPTIONS_H
#define UI_QG_LIBRARYINSERTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LibraryInsertOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QLabel *lFactor;
    QLineEdit *leFactor;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LibraryInsertOptions)
    {
        if (Ui_LibraryInsertOptions->objectName().isEmpty())
            Ui_LibraryInsertOptions->setObjectName(QString::fromUtf8("Ui_LibraryInsertOptions"));
        Ui_LibraryInsertOptions->resize(240, 24);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LibraryInsertOptions->sizePolicy().hasHeightForWidth());
        Ui_LibraryInsertOptions->setSizePolicy(sizePolicy);
        Ui_LibraryInsertOptions->setMinimumSize(QSize(240, 22));
        Ui_LibraryInsertOptions->setMaximumSize(QSize(300, 32767));
        hboxLayout = new QHBoxLayout(Ui_LibraryInsertOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lAngle = new QLabel(Ui_LibraryInsertOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_LibraryInsertOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));

        hboxLayout->addWidget(leAngle);

        lFactor = new QLabel(Ui_LibraryInsertOptions);
        lFactor->setObjectName(QString::fromUtf8("lFactor"));
        lFactor->setWordWrap(false);

        hboxLayout->addWidget(lFactor);

        leFactor = new QLineEdit(Ui_LibraryInsertOptions);
        leFactor->setObjectName(QString::fromUtf8("leFactor"));

        hboxLayout->addWidget(leFactor);

        sep1 = new QFrame(Ui_LibraryInsertOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LibraryInsertOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_LibraryInsertOptions, SLOT(updateData()));
        QObject::connect(leFactor, SIGNAL(textChanged(QString)), Ui_LibraryInsertOptions, SLOT(updateData()));

        QMetaObject::connectSlotsByName(Ui_LibraryInsertOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_LibraryInsertOptions)
    {
        Ui_LibraryInsertOptions->setWindowTitle(QCoreApplication::translate("Ui_LibraryInsertOptions", "Library Insert Options", nullptr));
#if QT_CONFIG(tooltip)
        Ui_LibraryInsertOptions->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lAngle->setText(QCoreApplication::translate("Ui_LibraryInsertOptions", "Angle:", nullptr));
#if QT_CONFIG(tooltip)
        leAngle->setToolTip(QCoreApplication::translate("Ui_LibraryInsertOptions", "Rotation Angle", nullptr));
#endif // QT_CONFIG(tooltip)
        lFactor->setText(QCoreApplication::translate("Ui_LibraryInsertOptions", "Factor:", nullptr));
#if QT_CONFIG(tooltip)
        leFactor->setToolTip(QCoreApplication::translate("Ui_LibraryInsertOptions", "Scale Factor", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_LibraryInsertOptions: public Ui_Ui_LibraryInsertOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LIBRARYINSERTOPTIONS_H
