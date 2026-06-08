/********************************************************************************
** Form generated from reading UI file 'qg_circletan2options.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_CIRCLETAN2OPTIONS_H
#define UI_QG_CIRCLETAN2OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_CircleTan2Options
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lRadius;
    QLineEdit *leRadius;
    QFrame *sep1;

    void setupUi(QWidget *Ui_CircleTan2Options)
    {
        if (Ui_CircleTan2Options->objectName().isEmpty())
            Ui_CircleTan2Options->setObjectName(QString::fromUtf8("Ui_CircleTan2Options"));
        Ui_CircleTan2Options->resize(110, 22);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_CircleTan2Options->sizePolicy().hasHeightForWidth());
        Ui_CircleTan2Options->setSizePolicy(sizePolicy);
        Ui_CircleTan2Options->setMinimumSize(QSize(65, 22));
        Ui_CircleTan2Options->setMaximumSize(QSize(160, 32));
        hboxLayout = new QHBoxLayout(Ui_CircleTan2Options);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 0, 1, 0);
        lRadius = new QLabel(Ui_CircleTan2Options);
        lRadius->setObjectName(QString::fromUtf8("lRadius"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lRadius->sizePolicy().hasHeightForWidth());
        lRadius->setSizePolicy(sizePolicy1);
        lRadius->setWordWrap(false);

        hboxLayout->addWidget(lRadius);

        leRadius = new QLineEdit(Ui_CircleTan2Options);
        leRadius->setObjectName(QString::fromUtf8("leRadius"));

        hboxLayout->addWidget(leRadius);

        sep1 = new QFrame(Ui_CircleTan2Options);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_CircleTan2Options);
        QObject::connect(leRadius, SIGNAL(textChanged(QString)), Ui_CircleTan2Options, SLOT(updateRadius(QString)));

        QMetaObject::connectSlotsByName(Ui_CircleTan2Options);
    } // setupUi

    void retranslateUi(QWidget *Ui_CircleTan2Options)
    {
        Ui_CircleTan2Options->setWindowTitle(QCoreApplication::translate("Ui_CircleTan2Options", "Circle Tangential2 Options", nullptr));
#if QT_CONFIG(tooltip)
        lRadius->setToolTip(QCoreApplication::translate("Ui_CircleTan2Options", "<html><head/><body><p>Radius of the tangential circle to draw</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lRadius->setText(QCoreApplication::translate("Ui_CircleTan2Options", "Radius:", nullptr));
#if QT_CONFIG(tooltip)
        leRadius->setToolTip(QCoreApplication::translate("Ui_CircleTan2Options", "Radius of tangential circle", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_CircleTan2Options: public Ui_Ui_CircleTan2Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_CIRCLETAN2OPTIONS_H
