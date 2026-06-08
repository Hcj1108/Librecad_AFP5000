/********************************************************************************
** Form generated from reading UI file 'qg_activelayername.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_ACTIVELAYERNAME_H
#define UI_QG_ACTIVELAYERNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QG_ActiveLayerName
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lActiveLayer;
    QLabel *lActiveLayerName;

    void setupUi(QWidget *QG_ActiveLayerName)
    {
        if (QG_ActiveLayerName->objectName().isEmpty())
            QG_ActiveLayerName->setObjectName(QString::fromUtf8("QG_ActiveLayerName"));
        QG_ActiveLayerName->resize(112, 32);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QG_ActiveLayerName->sizePolicy().hasHeightForWidth());
        QG_ActiveLayerName->setSizePolicy(sizePolicy);
        QG_ActiveLayerName->setMinimumSize(QSize(112, 29));
        QG_ActiveLayerName->setMaximumSize(QSize(600, 160));
        verticalLayout = new QVBoxLayout(QG_ActiveLayerName);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lActiveLayer = new QLabel(QG_ActiveLayerName);
        lActiveLayer->setObjectName(QString::fromUtf8("lActiveLayer"));
        lActiveLayer->setMinimumSize(QSize(46, 0));
        lActiveLayer->setMaximumSize(QSize(500, 16777215));
        lActiveLayer->setFrameShape(QFrame::NoFrame);
        lActiveLayer->setFrameShadow(QFrame::Plain);
        lActiveLayer->setWordWrap(false);

        verticalLayout->addWidget(lActiveLayer);

        lActiveLayerName = new QLabel(QG_ActiveLayerName);
        lActiveLayerName->setObjectName(QString::fromUtf8("lActiveLayerName"));
        lActiveLayerName->setMaximumSize(QSize(500, 16777215));
        lActiveLayerName->setFocusPolicy(Qt::ClickFocus);
        lActiveLayerName->setText(QString::fromUtf8(""));
        lActiveLayerName->setWordWrap(false);
        lActiveLayerName->setIndent(0);
        lActiveLayerName->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(lActiveLayerName);


        retranslateUi(QG_ActiveLayerName);

        QMetaObject::connectSlotsByName(QG_ActiveLayerName);
    } // setupUi

    void retranslateUi(QWidget *QG_ActiveLayerName)
    {
        QG_ActiveLayerName->setWindowTitle(QCoreApplication::translate("QG_ActiveLayerName", "Selection", nullptr));
#if QT_CONFIG(tooltip)
        lActiveLayer->setToolTip(QCoreApplication::translate("QG_ActiveLayerName", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lActiveLayer->setText(QCoreApplication::translate("QG_ActiveLayerName", "Current Layer", nullptr));
#if QT_CONFIG(tooltip)
        lActiveLayerName->setToolTip(QCoreApplication::translate("QG_ActiveLayerName", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Helvetica'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Name of Current Active Layer</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class QG_ActiveLayerName: public Ui_QG_ActiveLayerName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_ACTIVELAYERNAME_H
