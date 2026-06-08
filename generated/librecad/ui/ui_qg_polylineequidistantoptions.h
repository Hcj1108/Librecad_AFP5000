/********************************************************************************
** Form generated from reading UI file 'qg_polylineequidistantoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_POLYLINEEQUIDISTANTOPTIONS_H
#define UI_QG_POLYLINEEQUIDISTANTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PolylineEquidistantOptions
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lLength;
    QLineEdit *leDist;
    QLabel *lNumber;
    QLineEdit *leNumber;
    QFrame *sep1;

    void setupUi(QWidget *PolylineEquidistantOptions)
    {
        if (PolylineEquidistantOptions->objectName().isEmpty())
            PolylineEquidistantOptions->setObjectName(QString::fromUtf8("PolylineEquidistantOptions"));
        PolylineEquidistantOptions->resize(180, 24);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PolylineEquidistantOptions->sizePolicy().hasHeightForWidth());
        PolylineEquidistantOptions->setSizePolicy(sizePolicy);
        PolylineEquidistantOptions->setMinimumSize(QSize(120, 22));
        PolylineEquidistantOptions->setMaximumSize(QSize(180, 32767));
        horizontalLayout = new QHBoxLayout(PolylineEquidistantOptions);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 0, 0, 0);
        lLength = new QLabel(PolylineEquidistantOptions);
        lLength->setObjectName(QString::fromUtf8("lLength"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lLength->sizePolicy().hasHeightForWidth());
        lLength->setSizePolicy(sizePolicy1);
        lLength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lLength->setWordWrap(false);

        horizontalLayout->addWidget(lLength);

        leDist = new QLineEdit(PolylineEquidistantOptions);
        leDist->setObjectName(QString::fromUtf8("leDist"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leDist->sizePolicy().hasHeightForWidth());
        leDist->setSizePolicy(sizePolicy2);
        leDist->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(leDist);

        lNumber = new QLabel(PolylineEquidistantOptions);
        lNumber->setObjectName(QString::fromUtf8("lNumber"));
        sizePolicy1.setHeightForWidth(lNumber->sizePolicy().hasHeightForWidth());
        lNumber->setSizePolicy(sizePolicy1);
        lNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lNumber->setWordWrap(false);

        horizontalLayout->addWidget(lNumber);

        leNumber = new QLineEdit(PolylineEquidistantOptions);
        leNumber->setObjectName(QString::fromUtf8("leNumber"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leNumber->sizePolicy().hasHeightForWidth());
        leNumber->setSizePolicy(sizePolicy3);
        leNumber->setMaximumSize(QSize(24, 16777215));

        horizontalLayout->addWidget(leNumber);

        sep1 = new QFrame(PolylineEquidistantOptions);
        sep1->setObjectName(QString::fromUtf8("sep1"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sep1->sizePolicy().hasHeightForWidth());
        sep1->setSizePolicy(sizePolicy4);
        sep1->setFrameShape(QFrame::VLine);
        sep1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sep1);


        retranslateUi(PolylineEquidistantOptions);
        QObject::connect(leDist, SIGNAL(editingFinished()), PolylineEquidistantOptions, SLOT(updateDist()));
        QObject::connect(leNumber, SIGNAL(editingFinished()), PolylineEquidistantOptions, SLOT(updateNumber()));

        QMetaObject::connectSlotsByName(PolylineEquidistantOptions);
    } // setupUi

    void retranslateUi(QWidget *PolylineEquidistantOptions)
    {
        PolylineEquidistantOptions->setWindowTitle(QCoreApplication::translate("PolylineEquidistantOptions", "Line Relative Angle Options", nullptr));
        lLength->setText(QCoreApplication::translate("PolylineEquidistantOptions", "Spacing:", nullptr));
#if QT_CONFIG(tooltip)
        leDist->setToolTip(QCoreApplication::translate("PolylineEquidistantOptions", "Distance from original polyline", nullptr));
#endif // QT_CONFIG(tooltip)
        lNumber->setText(QCoreApplication::translate("PolylineEquidistantOptions", "Copies:", nullptr));
#if QT_CONFIG(tooltip)
        leNumber->setToolTip(QCoreApplication::translate("PolylineEquidistantOptions", "Distance from original polyline", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class PolylineEquidistantOptions: public Ui_PolylineEquidistantOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_POLYLINEEQUIDISTANTOPTIONS_H
