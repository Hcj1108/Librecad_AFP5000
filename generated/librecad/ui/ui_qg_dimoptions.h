/********************************************************************************
** Form generated from reading UI file 'qg_dimoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DIMOPTIONS_H
#define UI_QG_DIMOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_DimOptions
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lLabel;
    QToolButton *bDiameter;
    QLineEdit *leLabel;
    QComboBox *cbSymbol;
    QToolButton *toolButton;
    QLineEdit *leTol1;
    QToolButton *toolButton_2;
    QLineEdit *leTol2;
    QFrame *sep1;

    void setupUi(QWidget *Ui_DimOptions)
    {
        if (Ui_DimOptions->objectName().isEmpty())
            Ui_DimOptions->setObjectName(QString::fromUtf8("Ui_DimOptions"));
        Ui_DimOptions->resize(420, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_DimOptions->sizePolicy().hasHeightForWidth());
        Ui_DimOptions->setSizePolicy(sizePolicy);
        Ui_DimOptions->setMinimumSize(QSize(420, 22));
        Ui_DimOptions->setMaximumSize(QSize(420, 22));
        hboxLayout = new QHBoxLayout(Ui_DimOptions);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lLabel = new QLabel(Ui_DimOptions);
        lLabel->setObjectName(QString::fromUtf8("lLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLabel->sizePolicy().hasHeightForWidth());
        lLabel->setSizePolicy(sizePolicy1);
        lLabel->setFrameShape(QFrame::NoFrame);
        lLabel->setFrameShadow(QFrame::Plain);
        lLabel->setWordWrap(false);

        hboxLayout->addWidget(lLabel);

        bDiameter = new QToolButton(Ui_DimOptions);
        bDiameter->setObjectName(QString::fromUtf8("bDiameter"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bDiameter->sizePolicy().hasHeightForWidth());
        bDiameter->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/char_diameter.png"), QSize(), QIcon::Normal, QIcon::Off);
        bDiameter->setIcon(icon);
        bDiameter->setCheckable(true);

        hboxLayout->addWidget(bDiameter);

        leLabel = new QLineEdit(Ui_DimOptions);
        leLabel->setObjectName(QString::fromUtf8("leLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leLabel->sizePolicy().hasHeightForWidth());
        leLabel->setSizePolicy(sizePolicy3);

        hboxLayout->addWidget(leLabel);

        cbSymbol = new QComboBox(Ui_DimOptions);
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->setObjectName(QString::fromUtf8("cbSymbol"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbSymbol->sizePolicy().hasHeightForWidth());
        cbSymbol->setSizePolicy(sizePolicy4);

        hboxLayout->addWidget(cbSymbol);

        toolButton = new QToolButton(Ui_DimOptions);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/extui/tolerance1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);

        hboxLayout->addWidget(toolButton);

        leTol1 = new QLineEdit(Ui_DimOptions);
        leTol1->setObjectName(QString::fromUtf8("leTol1"));
        sizePolicy3.setHeightForWidth(leTol1->sizePolicy().hasHeightForWidth());
        leTol1->setSizePolicy(sizePolicy3);

        hboxLayout->addWidget(leTol1);

        toolButton_2 = new QToolButton(Ui_DimOptions);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/extui/tolerance2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);

        hboxLayout->addWidget(toolButton_2);

        leTol2 = new QLineEdit(Ui_DimOptions);
        leTol2->setObjectName(QString::fromUtf8("leTol2"));
        sizePolicy3.setHeightForWidth(leTol2->sizePolicy().hasHeightForWidth());
        leTol2->setSizePolicy(sizePolicy3);

        hboxLayout->addWidget(leTol2);

        sep1 = new QFrame(Ui_DimOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy5);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_DimOptions);
        QObject::connect(leLabel, SIGNAL(textChanged(QString)), Ui_DimOptions, SLOT(updateLabel()));
        QObject::connect(bDiameter, SIGNAL(toggled(bool)), Ui_DimOptions, SLOT(updateLabel()));
        QObject::connect(leTol1, SIGNAL(textChanged(QString)), Ui_DimOptions, SLOT(updateLabel()));
        QObject::connect(leTol2, SIGNAL(textChanged(QString)), Ui_DimOptions, SLOT(updateLabel()));
        QObject::connect(cbSymbol, SIGNAL(activated(QString)), Ui_DimOptions, SLOT(insertSign(QString)));

        QMetaObject::connectSlotsByName(Ui_DimOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_DimOptions)
    {
        Ui_DimOptions->setWindowTitle(QCoreApplication::translate("Ui_DimOptions", "Dimension Options", nullptr));
        lLabel->setText(QCoreApplication::translate("Ui_DimOptions", "Label:", nullptr));
        bDiameter->setText(QString());
        cbSymbol->setItemText(0, QCoreApplication::translate("Ui_DimOptions", "\342\214\200", nullptr));
        cbSymbol->setItemText(1, QCoreApplication::translate("Ui_DimOptions", "\302\260", nullptr));
        cbSymbol->setItemText(2, QCoreApplication::translate("Ui_DimOptions", "\302\261", nullptr));
        cbSymbol->setItemText(3, QCoreApplication::translate("Ui_DimOptions", "\317\200", nullptr));
        cbSymbol->setItemText(4, QCoreApplication::translate("Ui_DimOptions", "\303\227", nullptr));
        cbSymbol->setItemText(5, QCoreApplication::translate("Ui_DimOptions", "\303\267", nullptr));

        toolButton->setText(QCoreApplication::translate("Ui_DimOptions", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Ui_DimOptions", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_DimOptions: public Ui_Ui_DimOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DIMOPTIONS_H
