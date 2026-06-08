/********************************************************************************
** Form generated from reading UI file 'qg_commandwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_COMMANDWIDGET_H
#define UI_QG_COMMANDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qg_commandedit.h"
#include "qg_commandhistory.h"

QT_BEGIN_NAMESPACE

class Ui_QG_CommandWidget
{
public:
    QVBoxLayout *vboxLayout;
    QG_CommandHistory *teHistory;
    QLabel *lCommand;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QG_CommandEdit *leCommand;
    QToolButton *options_button;

    void setupUi(QWidget *QG_CommandWidget)
    {
        if (QG_CommandWidget->objectName().isEmpty())
            QG_CommandWidget->setObjectName(QString::fromUtf8("QG_CommandWidget"));
        QG_CommandWidget->resize(332, 196);
        vboxLayout = new QVBoxLayout(QG_CommandWidget);
        vboxLayout->setSpacing(1);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(1, 1, 1, 1);
        teHistory = new QG_CommandHistory(QG_CommandWidget);
        teHistory->setObjectName(QString::fromUtf8("teHistory"));
        teHistory->setMinimumSize(QSize(0, 23));
        teHistory->setFocusPolicy(Qt::NoFocus);
        teHistory->setLineWidth(0);
        teHistory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        teHistory->setDocumentTitle(QString::fromUtf8(""));
        teHistory->setUndoRedoEnabled(false);
        teHistory->setReadOnly(true);
        teHistory->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans'; font-size:10pt;\"><br /></p></body></html>"));
        teHistory->setAcceptRichText(false);
        teHistory->setProperty("linkUnderline", QVariant(false));

        vboxLayout->addWidget(teHistory);

        lCommand = new QLabel(QG_CommandWidget);
        lCommand->setObjectName(QString::fromUtf8("lCommand"));
        lCommand->setWordWrap(false);

        vboxLayout->addWidget(lCommand);

        frame = new QFrame(QG_CommandWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        leCommand = new QG_CommandEdit(frame);
        leCommand->setObjectName(QString::fromUtf8("leCommand"));

        horizontalLayout->addWidget(leCommand);

        options_button = new QToolButton(frame);
        options_button->setObjectName(QString::fromUtf8("options_button"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/options.svg"), QSize(), QIcon::Normal, QIcon::Off);
        options_button->setIcon(icon);
        options_button->setIconSize(QSize(12, 12));
        options_button->setPopupMode(QToolButton::InstantPopup);
        options_button->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout->addWidget(options_button);


        vboxLayout->addWidget(frame);


        retranslateUi(QG_CommandWidget);

        QMetaObject::connectSlotsByName(QG_CommandWidget);
    } // setupUi

    void retranslateUi(QWidget *QG_CommandWidget)
    {
        QG_CommandWidget->setWindowTitle(QCoreApplication::translate("QG_CommandWidget", "Command Line", nullptr));
#if QT_CONFIG(tooltip)
        teHistory->setToolTip(QCoreApplication::translate("QG_CommandWidget", "Command history and output", nullptr));
#endif // QT_CONFIG(tooltip)
        lCommand->setText(QCoreApplication::translate("QG_CommandWidget", "Command:", nullptr));
        options_button->setText(QCoreApplication::translate("QG_CommandWidget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_CommandWidget: public Ui_QG_CommandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_COMMANDWIDGET_H
