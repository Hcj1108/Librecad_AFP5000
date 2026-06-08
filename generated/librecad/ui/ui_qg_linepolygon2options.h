/********************************************************************************
** Form generated from reading UI file 'qg_linepolygon2options.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_LINEPOLYGON2OPTIONS_H
#define UI_QG_LINEPOLYGON2OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_LinePolygon2Options
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *lNumber;
    QSpinBox *sbNumber;
    QFrame *sep1;

    void setupUi(QWidget *Ui_LinePolygon2Options)
    {
        if (Ui_LinePolygon2Options->objectName().isEmpty())
            Ui_LinePolygon2Options->setObjectName(QString::fromUtf8("Ui_LinePolygon2Options"));
        Ui_LinePolygon2Options->resize(140, 22);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_LinePolygon2Options->sizePolicy().hasHeightForWidth());
        Ui_LinePolygon2Options->setSizePolicy(sizePolicy);
        Ui_LinePolygon2Options->setMinimumSize(QSize(100, 22));
        Ui_LinePolygon2Options->setMaximumSize(QSize(140, 22));
        hboxLayout = new QHBoxLayout(Ui_LinePolygon2Options);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        lNumber = new QLabel(Ui_LinePolygon2Options);
        lNumber->setObjectName(QString::fromUtf8("lNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lNumber->sizePolicy().hasHeightForWidth());
        lNumber->setSizePolicy(sizePolicy1);
        lNumber->setWordWrap(false);

        hboxLayout->addWidget(lNumber);

        sbNumber = new QSpinBox(Ui_LinePolygon2Options);
        sbNumber->setObjectName(QString::fromUtf8("sbNumber"));
        sbNumber->setMinimum(3);
        sbNumber->setMaximum(9999);

        hboxLayout->addWidget(sbNumber);

        sep1 = new QFrame(Ui_LinePolygon2Options);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy2);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(sep1);


        retranslateUi(Ui_LinePolygon2Options);
        QObject::connect(sbNumber, SIGNAL(valueChanged(int)), Ui_LinePolygon2Options, SLOT(updateNumber(int)));

        QMetaObject::connectSlotsByName(Ui_LinePolygon2Options);
    } // setupUi

    void retranslateUi(QWidget *Ui_LinePolygon2Options)
    {
        Ui_LinePolygon2Options->setWindowTitle(QCoreApplication::translate("Ui_LinePolygon2Options", "Polygon Options", nullptr));
        lNumber->setText(QCoreApplication::translate("Ui_LinePolygon2Options", "Number:", nullptr));
#if QT_CONFIG(tooltip)
        sbNumber->setToolTip(QCoreApplication::translate("Ui_LinePolygon2Options", "Number of edges", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Ui_LinePolygon2Options: public Ui_Ui_LinePolygon2Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_LINEPOLYGON2OPTIONS_H
