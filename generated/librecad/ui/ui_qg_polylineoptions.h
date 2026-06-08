/********************************************************************************
** Form generated from reading UI file 'qg_polylineoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_POLYLINEOPTIONS_H
#define UI_QG_POLYLINEOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_PolylineOptions
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *bClose;
    QToolButton *bUndo;
    QComboBox *cbMode;
    QLabel *lRadius;
    QLineEdit *leRadius;
    QLabel *lAngle;
    QLineEdit *leAngle;
    QGroupBox *buttonGroup1;
    QFrame *sep1;
    QRadioButton *rbPos;
    QRadioButton *rbNeg;

    void setupUi(QWidget *Ui_PolylineOptions)
    {
        if (Ui_PolylineOptions->objectName().isEmpty())
            Ui_PolylineOptions->setObjectName(QString::fromUtf8("Ui_PolylineOptions"));
        Ui_PolylineOptions->resize(425, 28);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_PolylineOptions->sizePolicy().hasHeightForWidth());
        Ui_PolylineOptions->setSizePolicy(sizePolicy);
        Ui_PolylineOptions->setMinimumSize(QSize(320, 22));
        Ui_PolylineOptions->setMaximumSize(QSize(750, 32));
        horizontalLayout = new QHBoxLayout(Ui_PolylineOptions);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 0, 0, 0);
        bClose = new QToolButton(Ui_PolylineOptions);
        bClose->setObjectName(QString::fromUtf8("bClose"));

        horizontalLayout->addWidget(bClose);

        bUndo = new QToolButton(Ui_PolylineOptions);
        bUndo->setObjectName(QString::fromUtf8("bUndo"));

        horizontalLayout->addWidget(bUndo);

        cbMode = new QComboBox(Ui_PolylineOptions);
        cbMode->addItem(QString());
        cbMode->addItem(QString());
        cbMode->addItem(QString());
        cbMode->addItem(QString());
        cbMode->setObjectName(QString::fromUtf8("cbMode"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbMode->sizePolicy().hasHeightForWidth());
        cbMode->setSizePolicy(sizePolicy1);
        cbMode->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(cbMode);

        lRadius = new QLabel(Ui_PolylineOptions);
        lRadius->setObjectName(QString::fromUtf8("lRadius"));
        lRadius->setAlignment(Qt::AlignVCenter);
        lRadius->setWordWrap(false);

        horizontalLayout->addWidget(lRadius);

        leRadius = new QLineEdit(Ui_PolylineOptions);
        leRadius->setObjectName(QString::fromUtf8("leRadius"));
        leRadius->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(leRadius);

        lAngle = new QLabel(Ui_PolylineOptions);
        lAngle->setObjectName(QString::fromUtf8("lAngle"));
        lAngle->setAlignment(Qt::AlignVCenter);
        lAngle->setWordWrap(false);

        horizontalLayout->addWidget(lAngle);

        leAngle = new QLineEdit(Ui_PolylineOptions);
        leAngle->setObjectName(QString::fromUtf8("leAngle"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leAngle->sizePolicy().hasHeightForWidth());
        leAngle->setSizePolicy(sizePolicy2);
        leAngle->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(leAngle);

        buttonGroup1 = new QGroupBox(Ui_PolylineOptions);
        buttonGroup1->setObjectName(QString::fromUtf8("buttonGroup1"));
        buttonGroup1->setFlat(true);

        horizontalLayout->addWidget(buttonGroup1);

        sep1 = new QFrame(Ui_PolylineOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy3);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sep1);

        rbPos = new QRadioButton(Ui_PolylineOptions);
        rbPos->setObjectName(QString::fromUtf8("rbPos"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/extui/dirpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        rbPos->setIcon(icon);
        rbPos->setChecked(true);

        horizontalLayout->addWidget(rbPos);

        rbNeg = new QRadioButton(Ui_PolylineOptions);
        rbNeg->setObjectName(QString::fromUtf8("rbNeg"));
        rbNeg->setMinimumSize(QSize(0, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/extui/dirneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        rbNeg->setIcon(icon1);

        horizontalLayout->addWidget(rbNeg);


        retranslateUi(Ui_PolylineOptions);
        QObject::connect(bClose, SIGNAL(clicked()), Ui_PolylineOptions, SLOT(close()));
        QObject::connect(bUndo, SIGNAL(clicked()), Ui_PolylineOptions, SLOT(undo()));
        QObject::connect(leRadius, SIGNAL(textChanged(QString)), Ui_PolylineOptions, SLOT(updateRadius(QString)));
        QObject::connect(leAngle, SIGNAL(textChanged(QString)), Ui_PolylineOptions, SLOT(updateAngle(QString)));
        QObject::connect(cbMode, SIGNAL(activated(int)), Ui_PolylineOptions, SLOT(updateMode(int)));
        QObject::connect(rbNeg, SIGNAL(toggled(bool)), Ui_PolylineOptions, SLOT(updateDirection(bool)));
        QObject::connect(rbPos, SIGNAL(toggled(bool)), Ui_PolylineOptions, SLOT(updateDirection(bool)));

        QMetaObject::connectSlotsByName(Ui_PolylineOptions);
    } // setupUi

    void retranslateUi(QWidget *Ui_PolylineOptions)
    {
        Ui_PolylineOptions->setWindowTitle(QCoreApplication::translate("Ui_PolylineOptions", "Polyline Options", nullptr));
        bClose->setText(QCoreApplication::translate("Ui_PolylineOptions", "Close", nullptr));
        bUndo->setText(QCoreApplication::translate("Ui_PolylineOptions", "Undo", nullptr));
        cbMode->setItemText(0, QCoreApplication::translate("Ui_PolylineOptions", "Line", nullptr));
        cbMode->setItemText(1, QCoreApplication::translate("Ui_PolylineOptions", "Tangential", nullptr));
        cbMode->setItemText(2, QCoreApplication::translate("Ui_PolylineOptions", "Tan Radius", nullptr));
        cbMode->setItemText(3, QCoreApplication::translate("Ui_PolylineOptions", "Angle", nullptr));

        lRadius->setText(QCoreApplication::translate("Ui_PolylineOptions", "Radius:", nullptr));
        lAngle->setText(QCoreApplication::translate("Ui_PolylineOptions", "Angle:", nullptr));
        buttonGroup1->setTitle(QString());
#if QT_CONFIG(tooltip)
        rbPos->setToolTip(QCoreApplication::translate("Ui_PolylineOptions", "Counter Clockwise", nullptr));
#endif // QT_CONFIG(tooltip)
        rbPos->setText(QString());
#if QT_CONFIG(tooltip)
        rbNeg->setToolTip(QCoreApplication::translate("Ui_PolylineOptions", "Clockwise", nullptr));
#endif // QT_CONFIG(tooltip)
        rbNeg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ui_PolylineOptions: public Ui_Ui_PolylineOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_POLYLINEOPTIONS_H
