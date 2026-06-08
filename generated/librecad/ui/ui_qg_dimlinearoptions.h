/********************************************************************************
** Form generated from reading UI file 'qg_dimlinearoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DIMLINEAROPTIONS_H
#define UI_QG_DIMLINEAROPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_DimLinearOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QToolButton *bHor;
    QToolButton *bVer;
    QFrame *sep1;

    void setupUi(QWidget *Ui_DimLinearOptions)
    {
        if (Ui_DimLinearOptions->objectName().isEmpty())
            Ui_DimLinearOptions->setObjectName(QString::fromUtf8("Ui_DimLinearOptions"));
        Ui_DimLinearOptions->resize(200, 22);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_DimLinearOptions->sizePolicy().hasHeightForWidth());
        Ui_DimLinearOptions->setSizePolicy(sizePolicy);
        Ui_DimLinearOptions->setMinimumSize(QSize(180, 22));
        Ui_DimLinearOptions->setMaximumSize(QSize(200, 22));
        hboxLayout = new QHBoxLayout(Ui_DimLinearOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lAngle = new QLabel(Ui_DimLinearOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lAngle->sizePolicy().hasHeightForWidth());
        lAngle->setSizePolicy(sizePolicy1);
        lAngle->setMinimumSize(QSize(0, 19));
        lAngle->setFrameShape(QFrame::NoFrame);
        lAngle->setFrameShadow(QFrame::Plain);
        lAngle->setWordWrap(false);

        hboxLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_DimLinearOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        sizePolicy.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy);
        leAngle->setMinimumSize(QSize(0, 19));

        hboxLayout->addWidget(leAngle);

        bHor = new QToolButton(Ui_DimLinearOptions);
        bHor->setObjectName(QString::fromUtf8("bHor"));
        sizePolicy1.setHeightForWidth(bHor->sizePolicy().hasHeightForWidth());
        bHor->setSizePolicy(sizePolicy1);
        bHor->setMinimumSize(QSize(0, 19));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dimhor.png"), QSize(), QIcon::Normal, QIcon::Off);
        bHor->setIcon(icon);

        hboxLayout->addWidget(bHor);

        bVer = new QToolButton(Ui_DimLinearOptions);
        bVer->setObjectName(QString::fromUtf8("bVer"));
        sizePolicy1.setHeightForWidth(bVer->sizePolicy().hasHeightForWidth());
        bVer->setSizePolicy(sizePolicy1);
        bVer->setMinimumSize(QSize(0, 19));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/extui/dimver.png"), QSize(), QIcon::Normal, QIcon::Off);
        bVer->setIcon(icon1);

        hboxLayout->addWidget(bVer);

        sep1 = new QFrame(Ui_DimLinearOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setMinimumSize(QSize(0, 19));
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_DimLinearOptions);
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_DimLinearOptions, SLOT(updateAngle(QString)));
        QObject::connect(bHor, SIGNAL(clicked()), Ui_DimLinearOptions, SLOT(setHor()));
        QObject::connect(bVer, SIGNAL(clicked()), Ui_DimLinearOptions, SLOT(setVer()));

        QMetaObject::connectSlotsByName(Ui_DimLinearOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_DimLinearOptions)
    {
        Ui_DimLinearOptions->setWindowTitle(QCoreApplication::translate("Ui_DimLinearOptions", "Linear Dimension Options", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_DimLinearOptions", "Angle:", nullptr));
        leAngle->setText(QString());
        bHor->setText(QString());
        bVer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ui_DimLinearOptions: public Ui_Ui_DimLinearOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DIMLINEAROPTIONS_H
