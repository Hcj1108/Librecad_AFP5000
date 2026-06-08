/********************************************************************************
** Form generated from reading UI file 'ImageViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewerClass
{
public:
    QLabel *label;
    QFrame *line;
    QTreeView *treeView;
    QLabel *label_2;
    QToolButton *toolButton_2;
    QToolButton *toolButton_5;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;

    void setupUi(QWidget *ImageViewerClass)
    {
        if (ImageViewerClass->objectName().isEmpty())
            ImageViewerClass->setObjectName(QString::fromUtf8("ImageViewerClass"));
        ImageViewerClass->resize(930, 620);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/NGTP.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImageViewerClass->setWindowIcon(icon);
        ImageViewerClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        label = new QLabel(ImageViewerClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 0, 711, 541));
        line = new QFrame(ImageViewerClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 550, 911, 16));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        treeView = new QTreeView(ImageViewerClass);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 70, 191, 471));
        label_2 = new QLabel(ImageViewerClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 560, 191, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolButton_2 = new QToolButton(ImageViewerClass);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(210, 560, 161, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(true);
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/calendar_prevmonth.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(30, 30));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolButton_5 = new QToolButton(ImageViewerClass);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(760, 560, 161, 61));
        toolButton_5->setFont(font1);
        toolButton_5->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon2);
        toolButton_5->setIconSize(QSize(30, 30));
        toolButton_5->setCheckable(false);
        toolButton_5->setAutoRepeat(false);
        toolButton_5->setAutoRepeatInterval(100);
        toolButton_5->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolButton_5->setAutoRaise(false);
        toolButton = new QToolButton(ImageViewerClass);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 0, 191, 61));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        toolButton->setIconSize(QSize(30, 30));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        toolButton_3 = new QToolButton(ImageViewerClass);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(400, 560, 161, 61));
        toolButton_3->setFont(font1);
        toolButton_3->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Huanyuan.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(30, 30));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolButton_4 = new QToolButton(ImageViewerClass);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(580, 560, 161, 61));
        toolButton_4->setFont(font1);
        toolButton_4->setStyleSheet(QString::fromUtf8("/* \346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QToolButton:pressed {\n"
"   background-color: #546E7A; /* \346\267\261\347\237\263\346\235\277\347\201\260 */\n"
"    background-image: none;\n"
"    padding-top: 12px;\n"
"    padding-bottom: 8px;\n"
"    border: 1px solid #37474F; /* \346\267\261\350\211\262\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261 */\n"
"}\n"
" QToolButton {\n"
"		background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    	stop:0 #ffffff,       /* \351\241\266\351\203\250\357\274\232\347\272\257\347\231\275\357\274\210\351\253\230\345\205\211\357\274\211 */\n"
"   		stop:0.15 #dcdcdc,    /* \350\277\207\346\270\241\357\274\232\346\265\205\347\201\260 */\n"
"    	stop:0.85 #a9a9a9,    /* \345\272\225\351\203\250\350\277\207\346\270\241\357\274\232\344\270\255\347\201\260 */\n"
"    	stop:1 #e8e8e8        /* \345\272\225\351\203\250\357\274\232\344\272\256\347\201\260\357\274\210\345\217\215\345\205\211\357\274\211 */);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/calendar_nextmonth.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(30, 30));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        retranslateUi(ImageViewerClass);

        QMetaObject::connectSlotsByName(ImageViewerClass);
    } // setupUi

    void retranslateUi(QWidget *ImageViewerClass)
    {
        ImageViewerClass->setWindowTitle(QCoreApplication::translate("ImageViewerClass", "ImageViewer", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("ImageViewerClass", "\344\270\212\344\270\200\345\274\240", nullptr));
        toolButton_5->setText(QCoreApplication::translate("ImageViewerClass", "\345\205\263\351\227\255\347\252\227\345\217\243", nullptr));
        toolButton->setText(QCoreApplication::translate("ImageViewerClass", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        toolButton_3->setText(QCoreApplication::translate("ImageViewerClass", "\346\227\213\350\275\254", nullptr));
        toolButton_4->setText(QCoreApplication::translate("ImageViewerClass", "\344\270\213\344\270\200\345\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerClass: public Ui_ImageViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
