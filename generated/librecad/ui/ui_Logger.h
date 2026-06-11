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
    QVBoxLayout *mainLayout;
    QHBoxLayout *topBar;
    QPushButton *btnOperate;
    QPushButton *btnError;
    QPushButton *btnComm;
    QSpacerItem *topSpacer;
    QLabel *labelKeepDays;
    QSpinBox *spinKeepDays;
    QHBoxLayout *contentArea;
    QListWidget *fileList;
    QTextEdit *contentView;
    QHBoxLayout *bottomBar;
    QLineEdit *searchBox;
    QPushButton *btnSearchPrev;
    QPushButton *btnSearchNext;
    QPushButton *btnExport;
    QSpacerItem *bottomSpacer;
    QPushButton *btnClose;

    void setupUi(QWidget *LoggerClass)
    {
        if (LoggerClass->objectName().isEmpty())
            LoggerClass->setObjectName(QString::fromUtf8("LoggerClass"));
        LoggerClass->setWindowModality(Qt::WindowModality::NonModal);
        LoggerClass->resize(941, 589);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Rizhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoggerClass->setWindowIcon(icon);
        LoggerClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(LoggerClass);
        mainLayout->setSpacing(8);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        topBar = new QHBoxLayout();
        topBar->setObjectName(QString::fromUtf8("topBar"));
        btnOperate = new QPushButton(LoggerClass);
        btnOperate->setObjectName(QString::fromUtf8("btnOperate"));
        btnOperate->setMinimumSize(QSize(120, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        btnOperate->setFont(font);
        btnOperate->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #2980b9;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/\346\223\215\344\275\234\346\227\245\345\277\227.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOperate->setIcon(icon1);
        btnOperate->setIconSize(QSize(24, 24));

        topBar->addWidget(btnOperate);

        btnError = new QPushButton(LoggerClass);
        btnError->setObjectName(QString::fromUtf8("btnError"));
        btnError->setMinimumSize(QSize(120, 38));
        btnError->setFont(font);
        btnError->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 13px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #c0392b;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/NG.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnError->setIcon(icon2);
        btnError->setIconSize(QSize(24, 24));

        topBar->addWidget(btnError);

        btnComm = new QPushButton(LoggerClass);
        btnComm->setObjectName(QString::fromUtf8("btnComm"));
        btnComm->setMinimumSize(QSize(120, 38));
        btnComm->setFont(font);
        btnComm->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 13px \"Microsoft YaHei\"; background: #f39c12; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #e67e22;}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PNG/Resources/PNG/stopBJ.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnComm->setIcon(icon3);
        btnComm->setIconSize(QSize(24, 24));

        topBar->addWidget(btnComm);

        topSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBar->addItem(topSpacer);

        labelKeepDays = new QLabel(LoggerClass);
        labelKeepDays->setObjectName(QString::fromUtf8("labelKeepDays"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(13);
        labelKeepDays->setFont(font1);
        labelKeepDays->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        topBar->addWidget(labelKeepDays);

        spinKeepDays = new QSpinBox(LoggerClass);
        spinKeepDays->setObjectName(QString::fromUtf8("spinKeepDays"));
        spinKeepDays->setFont(font);
        spinKeepDays->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 13px \"Microsoft YaHei\"; padding: 4px 8px; border: 2px solid #bdc3c7; border-radius: 4px; background: white;}"));
        spinKeepDays->setMinimum(1);
        spinKeepDays->setMaximum(365);
        spinKeepDays->setValue(30);

        topBar->addWidget(spinKeepDays);


        mainLayout->addLayout(topBar);

        contentArea = new QHBoxLayout();
        contentArea->setObjectName(QString::fromUtf8("contentArea"));
        fileList = new QListWidget(LoggerClass);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setMinimumSize(QSize(220, 0));
        fileList->setStyleSheet(QString::fromUtf8("QListWidget{font: 13px \"Microsoft YaHei\"; background: #ffffff; border: 2px solid #bdc3c7; border-radius: 6px; padding: 4px;}\n"
"QListWidget::item{padding: 6px 8px; border-bottom: 1px solid #ecf0f1;}\n"
"QListWidget::item:selected{background: #3498db; color: white; border-radius: 4px;}"));

        contentArea->addWidget(fileList);

        contentView = new QTextEdit(LoggerClass);
        contentView->setObjectName(QString::fromUtf8("contentView"));
        contentView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        contentView->setStyleSheet(QString::fromUtf8("QTextEdit{font: 13px \"Consolas\", \"Microsoft YaHei\"; background: #ffffff; border: 2px solid #bdc3c7; border-radius: 6px; padding: 8px;}\n"
"QTextEdit:focus{border-color: #3498db;}"));
        contentView->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        contentView->setReadOnly(true);

        contentArea->addWidget(contentView);

        contentArea->setStretch(0, 3);
        contentArea->setStretch(1, 7);

        mainLayout->addLayout(contentArea);

        bottomBar = new QHBoxLayout();
        bottomBar->setObjectName(QString::fromUtf8("bottomBar"));
        searchBox = new QLineEdit(LoggerClass);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setMinimumSize(QSize(200, 36));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setBold(false);
        font2.setItalic(false);
        searchBox->setFont(font2);
        searchBox->setStyleSheet(QString::fromUtf8("QLineEdit{font: 13px \"Microsoft YaHei\"; padding: 6px 12px; border: 2px solid #bdc3c7; border-radius: 6px; background: white;}\n"
"QLineEdit:focus{border-color: #3498db;}"));

        bottomBar->addWidget(searchBox);

        btnSearchPrev = new QPushButton(LoggerClass);
        btnSearchPrev->setObjectName(QString::fromUtf8("btnSearchPrev"));
        btnSearchPrev->setMinimumSize(QSize(90, 36));
        btnSearchPrev->setFont(font);
        btnSearchPrev->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #7f8c8d;}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/add_top.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearchPrev->setIcon(icon4);
        btnSearchPrev->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnSearchPrev);

        btnSearchNext = new QPushButton(LoggerClass);
        btnSearchNext->setObjectName(QString::fromUtf8("btnSearchNext"));
        btnSearchNext->setMinimumSize(QSize(90, 36));
        btnSearchNext->setFont(font);
        btnSearchNext->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #7f8c8d;}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PIC/Resources/PICs/add_bottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearchNext->setIcon(icon5);
        btnSearchNext->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnSearchNext);

        btnExport = new QPushButton(LoggerClass);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        btnExport->setMinimumSize(QSize(100, 36));
        btnExport->setFont(font);
        btnExport->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #27ae60; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #229954;}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PNG/Resources/PNG/BCCS.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExport->setIcon(icon6);
        btnExport->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnExport);

        bottomSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomBar->addItem(bottomSpacer);

        btnClose = new QPushButton(LoggerClass);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(80, 36));
        btnClose->setMaximumSize(QSize(80, 36));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #c0392b;}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon7);
        btnClose->setIconSize(QSize(20, 20));

        bottomBar->addWidget(btnClose);


        mainLayout->addLayout(bottomBar);


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
        btnClose->setText(QCoreApplication::translate("LoggerClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggerClass: public Ui_LoggerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGER_H
