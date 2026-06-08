/********************************************************************************
** Form generated from reading UI file 'qg_arctangentialoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_ARCTANGENTIALOPTIONS_H
#define UI_QG_ARCTANGENTIALOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_ArcTangentialOptions
{
public:
    QFrame *sep1;
    QLineEdit *leRadius;
    QLineEdit *leAngle;
    QRadioButton *rbRadius;
    QRadioButton *rbAngle;

    void setupUi(QWidget *Ui_ArcTangentialOptions)
    {
        if (Ui_ArcTangentialOptions->objectName().isEmpty())
            Ui_ArcTangentialOptions->setObjectName(QString::fromUtf8("Ui_ArcTangentialOptions"));
        Ui_ArcTangentialOptions->resize(258, 24);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_ArcTangentialOptions->sizePolicy().hasHeightForWidth());
        Ui_ArcTangentialOptions->setSizePolicy(sizePolicy);
        Ui_ArcTangentialOptions->setMinimumSize(QSize(248, 22));
        sep1 = new QFrame(Ui_ArcTangentialOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        sep1->setGeometry(QRect(124, 0, 16, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy1);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);
        leRadius = new QLineEdit(Ui_ArcTangentialOptions);
        leRadius->setObjectName(QString::fromUtf8("leRadius"));
        leRadius->setGeometry(QRect(70, 0, 60, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leRadius->sizePolicy().hasHeightForWidth());
        leRadius->setSizePolicy(sizePolicy2);
        leAngle = new QLineEdit(Ui_ArcTangentialOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        leAngle->setGeometry(QRect(192, 0, 60, 22));
        sizePolicy2.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy2);
        rbRadius = new QRadioButton(Ui_ArcTangentialOptions);
        rbRadius->setObjectName(QString::fromUtf8("rbRadius"));
        rbRadius->setGeometry(QRect(0, 0, 70, 22));
        rbRadius->setIconSize(QSize(12, 12));
        rbRadius->setChecked(true);
        rbAngle = new QRadioButton(Ui_ArcTangentialOptions);
        rbAngle->setObjectName(QString::fromUtf8("rbAngle"));
        rbAngle->setGeometry(QRect(130, 0, 65, 22));
        rbAngle->setIconSize(QSize(12, 12));
        QWidget::setTabOrder(leRadius, leAngle);

        retranslateUi(Ui_ArcTangentialOptions);

        QMetaObject::connectSlotsByName(Ui_ArcTangentialOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_ArcTangentialOptions)
    {
        Ui_ArcTangentialOptions->setWindowTitle(QCoreApplication::translate("Ui_ArcTangentialOptions", "Tangential Arc Options", nullptr));
#if QT_CONFIG(tooltip)
        leRadius->setToolTip(QCoreApplication::translate("Ui_ArcTangentialOptions", "Radius of the tangential arc", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leAngle->setToolTip(QCoreApplication::translate("Ui_ArcTangentialOptions", "Total subtending angle of the tangential arc", nullptr));
#endif // QT_CONFIG(tooltip)
        rbRadius->setText(QCoreApplication::translate("Ui_ArcTangentialOptions", "Radius", nullptr));
        rbAngle->setText(QCoreApplication::translate("Ui_ArcTangentialOptions", "Angle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_ArcTangentialOptions: public Ui_Ui_ArcTangentialOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_ARCTANGENTIALOPTIONS_H
