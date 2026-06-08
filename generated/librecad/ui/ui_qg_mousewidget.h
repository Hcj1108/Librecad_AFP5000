/********************************************************************************
** Form generated from reading UI file 'qg_mousewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_MOUSEWIDGET_H
#define UI_QG_MOUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QG_MouseWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lRightButton;
    QLabel *lLeftButton;
    QLabel *lMousePixmap;

    void setupUi(QWidget *QG_MouseWidget)
    {
        if (QG_MouseWidget->objectName().isEmpty())
            QG_MouseWidget->setObjectName(QString::fromUtf8("QG_MouseWidget"));
        QG_MouseWidget->resize(318, 28);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_MouseWidget->sizePolicy().hasHeightForWidth());
        QG_MouseWidget->setSizePolicy(sizePolicy);
        QG_MouseWidget->setMinimumSize(QSize(300, 28));
        QG_MouseWidget->setMaximumSize(QSize(500, 80));
        gridLayout = new QGridLayout(QG_MouseWidget);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lRightButton = new QLabel(QG_MouseWidget);
        lRightButton->setObjectName(QString::fromUtf8("lRightButton"));
        sizePolicy.setHeightForWidth(lRightButton->sizePolicy().hasHeightForWidth());
        lRightButton->setSizePolicy(sizePolicy);
        lRightButton->setMinimumSize(QSize(0, 28));
        lRightButton->setMaximumSize(QSize(32767, 80));
        lRightButton->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lRightButton->setWordWrap(false);

        gridLayout->addWidget(lRightButton, 0, 2, 1, 1);

        lLeftButton = new QLabel(QG_MouseWidget);
        lLeftButton->setObjectName(QString::fromUtf8("lLeftButton"));
        sizePolicy.setHeightForWidth(lLeftButton->sizePolicy().hasHeightForWidth());
        lLeftButton->setSizePolicy(sizePolicy);
        lLeftButton->setMinimumSize(QSize(0, 27));
        lLeftButton->setMaximumSize(QSize(32767, 80));
        lLeftButton->setFrameShape(QFrame::NoFrame);
        lLeftButton->setFrameShadow(QFrame::Plain);
        lLeftButton->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        lLeftButton->setWordWrap(false);

        gridLayout->addWidget(lLeftButton, 0, 0, 1, 1);

        lMousePixmap = new QLabel(QG_MouseWidget);
        lMousePixmap->setObjectName(QString::fromUtf8("lMousePixmap"));
        lMousePixmap->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lMousePixmap->sizePolicy().hasHeightForWidth());
        lMousePixmap->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lMousePixmap, 0, 1, 1, 1);


        retranslateUi(QG_MouseWidget);

        QMetaObject::connectSlotsByName(QG_MouseWidget);
    } // setupUi

    void retranslateUi(QWidget *QG_MouseWidget)
    {
        QG_MouseWidget->setWindowTitle(QCoreApplication::translate("QG_MouseWidget", "Mouse", nullptr));
        lRightButton->setText(QCoreApplication::translate("QG_MouseWidget", "Right", nullptr));
        lLeftButton->setText(QCoreApplication::translate("QG_MouseWidget", "Left", nullptr));
#if QT_CONFIG(tooltip)
        lMousePixmap->setToolTip(QCoreApplication::translate("QG_MouseWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Helvetica'; font-size:9pt;\">Hint about left/right mouse button actions</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lMousePixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QG_MouseWidget: public Ui_QG_MouseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_MOUSEWIDGET_H
