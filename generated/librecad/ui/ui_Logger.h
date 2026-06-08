/********************************************************************************
** Form generated from reading UI file 'Logger.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGER_H
#define UI_LOGGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggerClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *btnLayout;
    QPushButton *btnOperate;
    QPushButton *btnError;
    QPushButton *btnComm;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelKeepDays;
    QSpinBox *spinKeepDays;
    QHBoxLayout *horizontalLayout;
    QListWidget *fileList;
    QTextEdit *contentView;
    QHBoxLayout *searchLayout;
    QLineEdit *searchBox;
    QPushButton *btnSearchPrev;
    QPushButton *btnSearchNext;
    QPushButton *btnExport;

    void setupUi(QWidget *LoggerClass)
    {
        if (LoggerClass->objectName().isEmpty())
            LoggerClass->setObjectName(QString::fromUtf8("LoggerClass"));
        LoggerClass->setWindowModality(Qt::WindowModality::NonModal);
        LoggerClass->resize(936, 620);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Rizhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoggerClass->setWindowIcon(icon);
        LoggerClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        verticalLayout = new QVBoxLayout(LoggerClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnLayout = new QHBoxLayout();
        btnLayout->setSpacing(6);
        btnLayout->setObjectName(QString::fromUtf8("btnLayout"));
        btnOperate = new QPushButton(LoggerClass);
        btnOperate->setObjectName(QString::fromUtf8("btnOperate"));
        btnOperate->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/\346\223\215\344\275\234\346\227\245\345\277\227.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOperate->setIcon(icon1);
        btnOperate->setIconSize(QSize(30, 30));

        btnLayout->addWidget(btnOperate);

        btnError = new QPushButton(LoggerClass);
        btnError->setObjectName(QString::fromUtf8("btnError"));
        btnError->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/NG.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnError->setIcon(icon2);
        btnError->setIconSize(QSize(30, 30));

        btnLayout->addWidget(btnError);

        btnComm = new QPushButton(LoggerClass);
        btnComm->setObjectName(QString::fromUtf8("btnComm"));
        btnComm->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PNG/Resources/PNG/stopBJ.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnComm->setIcon(icon3);
        btnComm->setIconSize(QSize(30, 30));

        btnLayout->addWidget(btnComm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        btnLayout->addItem(horizontalSpacer_2);

        labelKeepDays = new QLabel(LoggerClass);
        labelKeepDays->setObjectName(QString::fromUtf8("labelKeepDays"));
        labelKeepDays->setStyleSheet(QString::fromUtf8("font-size: 14px;"));

        btnLayout->addWidget(labelKeepDays);

        spinKeepDays = new QSpinBox(LoggerClass);
        spinKeepDays->setObjectName(QString::fromUtf8("spinKeepDays"));
        spinKeepDays->setStyleSheet(QString::fromUtf8("font-size: 14px; padding: 4px;"));
        spinKeepDays->setMinimum(1);
        spinKeepDays->setMaximum(365);
        spinKeepDays->setValue(30);

        btnLayout->addWidget(spinKeepDays);


        verticalLayout->addLayout(btnLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fileList = new QListWidget(LoggerClass);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setMinimumSize(QSize(200, 0));
        fileList->setStyleSheet(QString::fromUtf8("font-size: 14px;"));

        horizontalLayout->addWidget(fileList);

        contentView = new QTextEdit(LoggerClass);
        contentView->setObjectName(QString::fromUtf8("contentView"));
        contentView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        contentView->setStyleSheet(QString::fromUtf8("font-size: 14px; font-family: Consolas, monospace;"));
        contentView->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        contentView->setMidLineWidth(-1);
        contentView->setReadOnly(true);

        horizontalLayout->addWidget(contentView);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout);

        searchLayout = new QHBoxLayout();
        searchLayout->setSpacing(6);
        searchLayout->setObjectName(QString::fromUtf8("searchLayout"));
        searchBox = new QLineEdit(LoggerClass);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setStyleSheet(QString::fromUtf8("font-size: 14px; padding: 6px 10px;"));

        searchLayout->addWidget(searchBox);

        btnSearchPrev = new QPushButton(LoggerClass);
        btnSearchPrev->setObjectName(QString::fromUtf8("btnSearchPrev"));
        btnSearchPrev->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/add_top.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearchPrev->setIcon(icon4);

        searchLayout->addWidget(btnSearchPrev);

        btnSearchNext = new QPushButton(LoggerClass);
        btnSearchNext->setObjectName(QString::fromUtf8("btnSearchNext"));
        btnSearchNext->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PIC/Resources/PICs/add_bottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearchNext->setIcon(icon5);

        searchLayout->addWidget(btnSearchNext);

        btnExport = new QPushButton(LoggerClass);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        btnExport->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        opacity: 1;\n"
" 		border: none;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PNG/Resources/PNG/BCCS.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExport->setIcon(icon6);
        btnExport->setIconSize(QSize(16, 16));

        searchLayout->addWidget(btnExport);


        verticalLayout->addLayout(searchLayout);


        retranslateUi(LoggerClass);

        QMetaObject::connectSlotsByName(LoggerClass);
    } // setupUi

    void retranslateUi(QWidget *LoggerClass)
    {
        LoggerClass->setWindowTitle(QCoreApplication::translate("LoggerClass", "\346\227\245\345\277\227\346\237\245\347\234\213\345\231\250", nullptr));
        btnOperate->setText(QCoreApplication::translate("LoggerClass", "\346\223\215\344\275\234\346\227\245\345\277\227", nullptr));
        btnError->setText(QCoreApplication::translate("LoggerClass", "\351\224\231\350\257\257\346\227\245\345\277\227", nullptr));
        btnComm->setText(QCoreApplication::translate("LoggerClass", "\351\200\232\344\277\241\346\227\245\345\277\227", nullptr));
        labelKeepDays->setText(QCoreApplication::translate("LoggerClass", "\344\277\235\347\225\231", nullptr));
        spinKeepDays->setSuffix(QCoreApplication::translate("LoggerClass", " \345\244\251", nullptr));
        searchBox->setPlaceholderText(QCoreApplication::translate("LoggerClass", "\346\220\234\347\264\242\345\205\263\351\224\256\345\255\227...", nullptr));
        btnSearchPrev->setText(QCoreApplication::translate("LoggerClass", "\344\270\212\344\270\200\344\270\252", nullptr));
        btnSearchNext->setText(QCoreApplication::translate("LoggerClass", "\344\270\213\344\270\200\344\270\252", nullptr));
        btnExport->setText(QCoreApplication::translate("LoggerClass", "\345\257\274\345\207\272\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggerClass: public Ui_LoggerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGER_H
