/********************************************************************************
** Form generated from reading UI file 'qg_coordinatewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_COORDINATEWIDGET_H
#define UI_QG_COORDINATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QG_CoordinateWidget
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *lCoord1;
    QLabel *lCoord1b;
    QFrame *line1;
    QVBoxLayout *vboxLayout1;
    QLabel *lCoord2;
    QLabel *lCoord2b;

    void setupUi(QWidget *QG_CoordinateWidget)
    {
        if (QG_CoordinateWidget->objectName().isEmpty())
            QG_CoordinateWidget->setObjectName(QString::fromUtf8("QG_CoordinateWidget"));
        QG_CoordinateWidget->resize(380, 27);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_CoordinateWidget->sizePolicy().hasHeightForWidth());
        QG_CoordinateWidget->setSizePolicy(sizePolicy);
        QG_CoordinateWidget->setMinimumSize(QSize(380, 27));
        QG_CoordinateWidget->setMaximumSize(QSize(1500, 160));
        hboxLayout = new QHBoxLayout(QG_CoordinateWidget);
        hboxLayout->setSpacing(0);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(4, 0, 0, 0);
        lCoord1 = new QLabel(QG_CoordinateWidget);
        lCoord1->setObjectName(QString::fromUtf8("lCoord1"));
        lCoord1->setFrameShape(QFrame::NoFrame);
        lCoord1->setFrameShadow(QFrame::Plain);
        lCoord1->setWordWrap(false);

        vboxLayout->addWidget(lCoord1);

        lCoord1b = new QLabel(QG_CoordinateWidget);
        lCoord1b->setObjectName(QString::fromUtf8("lCoord1b"));
        lCoord1b->setFrameShape(QFrame::NoFrame);
        lCoord1b->setFrameShadow(QFrame::Plain);
        lCoord1b->setWordWrap(false);

        vboxLayout->addWidget(lCoord1b);


        hboxLayout->addLayout(vboxLayout);

        line1 = new QFrame(QG_CoordinateWidget);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::VLine);
        line1->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(4, 0, 0, 0);
        lCoord2 = new QLabel(QG_CoordinateWidget);
        lCoord2->setObjectName(QString::fromUtf8("lCoord2"));
        lCoord2->setWordWrap(false);

        vboxLayout1->addWidget(lCoord2);

        lCoord2b = new QLabel(QG_CoordinateWidget);
        lCoord2b->setObjectName(QString::fromUtf8("lCoord2b"));
        lCoord2b->setWordWrap(false);

        vboxLayout1->addWidget(lCoord2b);


        hboxLayout->addLayout(vboxLayout1);


        retranslateUi(QG_CoordinateWidget);

        QMetaObject::connectSlotsByName(QG_CoordinateWidget);
    } // setupUi

    void retranslateUi(QWidget *QG_CoordinateWidget)
    {
        QG_CoordinateWidget->setWindowTitle(QCoreApplication::translate("QG_CoordinateWidget", "Coordinates", nullptr));
        lCoord1->setText(QCoreApplication::translate("QG_CoordinateWidget", "Coordinates", nullptr));
        lCoord1b->setText(QCoreApplication::translate("QG_CoordinateWidget", "Coordinates", nullptr));
        lCoord2->setText(QCoreApplication::translate("QG_CoordinateWidget", "Coordinates", nullptr));
        lCoord2b->setText(QCoreApplication::translate("QG_CoordinateWidget", "Coordinates", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_CoordinateWidget: public Ui_QG_CoordinateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_COORDINATEWIDGET_H
