/********************************************************************************
** Form generated from reading UI file 'qg_dimensionlabeleditor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DIMENSIONLABELEDITOR_H
#define UI_QG_DIMENSIONLABELEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QG_DimensionLabelEditor
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *bgLabel;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *hboxLayout1;
    QLabel *lLabel;
    QToolButton *bDiameter;
    QLineEdit *leLabel;
    QVBoxLayout *vboxLayout2;
    QLineEdit *leTol1;
    QLineEdit *leTol2;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel1;
    QComboBox *cbSymbol;

    void setupUi(QWidget *QG_DimensionLabelEditor)
    {
        if (QG_DimensionLabelEditor->objectName().isEmpty())
            QG_DimensionLabelEditor->setObjectName(QString::fromUtf8("QG_DimensionLabelEditor"));
        QG_DimensionLabelEditor->resize(220, 124);
        QG_DimensionLabelEditor->setMinimumSize(QSize(220, 0));
        vboxLayout = new QVBoxLayout(QG_DimensionLabelEditor);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        bgLabel = new QGroupBox(QG_DimensionLabelEditor);
        bgLabel->setObjectName(QString::fromUtf8("bgLabel"));
        vboxLayout1 = new QVBoxLayout(bgLabel);
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        lLabel = new QLabel(bgLabel);
        lLabel->setObjectName(QString::fromUtf8("lLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lLabel->sizePolicy().hasHeightForWidth());
        lLabel->setSizePolicy(sizePolicy);
        lLabel->setFrameShape(QFrame::NoFrame);
        lLabel->setFrameShadow(QFrame::Plain);
        lLabel->setWordWrap(false);

        hboxLayout1->addWidget(lLabel);

        bDiameter = new QToolButton(bgLabel);
        bDiameter->setObjectName(QString::fromUtf8("bDiameter"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bDiameter->sizePolicy().hasHeightForWidth());
        bDiameter->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/char_diameter.png"), QSize(), QIcon::Normal, QIcon::Off);
        bDiameter->setIcon(icon);
        bDiameter->setCheckable(true);

        hboxLayout1->addWidget(bDiameter);

        leLabel = new QLineEdit(bgLabel);
        leLabel->setObjectName(QString::fromUtf8("leLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leLabel->sizePolicy().hasHeightForWidth());
        leLabel->setSizePolicy(sizePolicy2);

        hboxLayout1->addWidget(leLabel);


        hboxLayout->addLayout(hboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        leTol1 = new QLineEdit(bgLabel);
        leTol1->setObjectName(QString::fromUtf8("leTol1"));
        sizePolicy2.setHeightForWidth(leTol1->sizePolicy().hasHeightForWidth());
        leTol1->setSizePolicy(sizePolicy2);

        vboxLayout2->addWidget(leTol1);

        leTol2 = new QLineEdit(bgLabel);
        leTol2->setObjectName(QString::fromUtf8("leTol2"));
        sizePolicy2.setHeightForWidth(leTol2->sizePolicy().hasHeightForWidth());
        leTol2->setSizePolicy(sizePolicy2);

        vboxLayout2->addWidget(leTol2);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel1 = new QLabel(bgLabel);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1);

        cbSymbol = new QComboBox(bgLabel);
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->addItem(QString());
        cbSymbol->setObjectName(QString::fromUtf8("cbSymbol"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbSymbol->sizePolicy().hasHeightForWidth());
        cbSymbol->setSizePolicy(sizePolicy3);

        hboxLayout2->addWidget(cbSymbol);


        vboxLayout1->addLayout(hboxLayout2);


        vboxLayout->addWidget(bgLabel);


        retranslateUi(QG_DimensionLabelEditor);
        QObject::connect(cbSymbol, SIGNAL(activated(QString)), QG_DimensionLabelEditor, SLOT(insertSign(QString)));

        QMetaObject::connectSlotsByName(QG_DimensionLabelEditor);
    } // setupUi

    void retranslateUi(QWidget *QG_DimensionLabelEditor)
    {
        QG_DimensionLabelEditor->setWindowTitle(QCoreApplication::translate("QG_DimensionLabelEditor", "Dimension Label Editor", nullptr));
        bgLabel->setTitle(QCoreApplication::translate("QG_DimensionLabelEditor", "Dimension Label:", nullptr));
        lLabel->setText(QCoreApplication::translate("QG_DimensionLabelEditor", "Label:", nullptr));
        bDiameter->setText(QString());
        textLabel1->setText(QCoreApplication::translate("QG_DimensionLabelEditor", "Insert:", nullptr));
        cbSymbol->setItemText(0, QCoreApplication::translate("QG_DimensionLabelEditor", "\342\214\200 (Diameter)", nullptr));
        cbSymbol->setItemText(1, QCoreApplication::translate("QG_DimensionLabelEditor", "\302\260 (Degree)", nullptr));
        cbSymbol->setItemText(2, QCoreApplication::translate("QG_DimensionLabelEditor", "\302\261 (Plus / Minus)", nullptr));
        cbSymbol->setItemText(3, QCoreApplication::translate("QG_DimensionLabelEditor", "\317\200 (Pi)", nullptr));
        cbSymbol->setItemText(4, QCoreApplication::translate("QG_DimensionLabelEditor", "\303\227 (Times)", nullptr));
        cbSymbol->setItemText(5, QCoreApplication::translate("QG_DimensionLabelEditor", "\303\267 (Division)", nullptr));

    } // retranslateUi

};

namespace Ui {
    class QG_DimensionLabelEditor: public Ui_QG_DimensionLabelEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DIMENSIONLABELEDITOR_H
