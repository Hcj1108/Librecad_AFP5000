/********************************************************************************
** Form generated from reading UI file 'textfileviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFILEVIEWER_H
#define UI_TEXTFILEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TextFileViewer
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *list;
    QPlainTextEdit *text_edit;

    void setupUi(QFrame *TextFileViewer)
    {
        if (TextFileViewer->objectName().isEmpty())
            TextFileViewer->setObjectName(QString::fromUtf8("TextFileViewer"));
        TextFileViewer->resize(973, 632);
        TextFileViewer->setFrameShape(QFrame::StyledPanel);
        TextFileViewer->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(TextFileViewer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        list = new QListWidget(TextFileViewer);
        list->setObjectName(QString::fromUtf8("list"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(list->sizePolicy().hasHeightForWidth());
        list->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(list);

        text_edit = new QPlainTextEdit(TextFileViewer);
        text_edit->setObjectName(QString::fromUtf8("text_edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(text_edit->sizePolicy().hasHeightForWidth());
        text_edit->setSizePolicy(sizePolicy1);
        text_edit->setMinimumSize(QSize(600, 600));
        text_edit->setOverwriteMode(false);

        horizontalLayout->addWidget(text_edit);


        retranslateUi(TextFileViewer);

        QMetaObject::connectSlotsByName(TextFileViewer);
    } // setupUi

    void retranslateUi(QFrame *TextFileViewer)
    {
        TextFileViewer->setWindowTitle(QCoreApplication::translate("TextFileViewer", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextFileViewer: public Ui_TextFileViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFILEVIEWER_H
