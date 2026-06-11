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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewerClass
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *contentArea;
    QVBoxLayout *leftPanel;
    QToolButton *btnUp;
    QTreeView *treeView;
    QLabel *labelInfo;
    QVBoxLayout *rightPanel;
    QLabel *labelImage;
    QHBoxLayout *bottomBar;
    QToolButton *btnPrev;
    QToolButton *btnRotate;
    QToolButton *btnNext;
    QSpacerItem *spacerBtn;
    QToolButton *btnClose;

    void setupUi(QWidget *ImageViewerClass)
    {
        if (ImageViewerClass->objectName().isEmpty())
            ImageViewerClass->setObjectName(QString::fromUtf8("ImageViewerClass"));
        ImageViewerClass->resize(864, 559);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/NGTP.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImageViewerClass->setWindowIcon(icon);
        ImageViewerClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        mainLayout = new QVBoxLayout(ImageViewerClass);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        contentArea = new QHBoxLayout();
        contentArea->setObjectName(QString::fromUtf8("contentArea"));
        leftPanel = new QVBoxLayout();
        leftPanel->setSpacing(4);
        leftPanel->setObjectName(QString::fromUtf8("leftPanel"));
        btnUp = new QToolButton(ImageViewerClass);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setMinimumSize(QSize(0, 36));
        btnUp->setMaximumSize(QSize(16777215, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setBold(true);
        font.setItalic(false);
        btnUp->setFont(font);
        btnUp->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 13px \"Microsoft YaHei\"; background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QToolButton:hover{background: #2980b9;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/add_top.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUp->setIcon(icon1);
        btnUp->setIconSize(QSize(20, 20));
        btnUp->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        leftPanel->addWidget(btnUp);

        treeView = new QTreeView(ImageViewerClass);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setStyleSheet(QString::fromUtf8("QTreeView{font: 12px \"Microsoft YaHei\"; background: #ffffff; border: 2px solid #bdc3c7; border-radius: 6px; padding: 4px;}\n"
"QTreeView::item{padding: 4px 8px;}\n"
"QTreeView::item:selected{background: #3498db; color: white;}"));

        leftPanel->addWidget(treeView);

        labelInfo = new QLabel(ImageViewerClass);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(11);
        font1.setBold(true);
        labelInfo->setFont(font1);
        labelInfo->setStyleSheet(QString::fromUtf8("QLabel{background: #ffffff; border: 2px solid #bdc3c7; border-radius: 6px; padding: 8px; color: #34495e;}"));
        labelInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        leftPanel->addWidget(labelInfo);


        contentArea->addLayout(leftPanel);

        rightPanel = new QVBoxLayout();
        rightPanel->setSpacing(4);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        labelImage = new QLabel(ImageViewerClass);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setStyleSheet(QString::fromUtf8("QLabel{  border: 2px solid #27ae60;\n"
"border-radius: 6px; min-height: 400px;}"));
        labelImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        rightPanel->addWidget(labelImage);

        bottomBar = new QHBoxLayout();
        bottomBar->setSpacing(10);
        bottomBar->setObjectName(QString::fromUtf8("bottomBar"));
        btnPrev = new QToolButton(ImageViewerClass);
        btnPrev->setObjectName(QString::fromUtf8("btnPrev"));
        btnPrev->setMinimumSize(QSize(0, 36));
        btnPrev->setMaximumSize(QSize(16777215, 36));
        btnPrev->setFont(font);
        btnPrev->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 8px 20px;}\n"
"QToolButton:hover{background: #7f8c8d;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/calendar_prevmonth.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrev->setIcon(icon2);
        btnPrev->setIconSize(QSize(20, 20));
        btnPrev->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        bottomBar->addWidget(btnPrev);

        btnRotate = new QToolButton(ImageViewerClass);
        btnRotate->setObjectName(QString::fromUtf8("btnRotate"));
        btnRotate->setMinimumSize(QSize(0, 36));
        btnRotate->setMaximumSize(QSize(16777215, 36));
        btnRotate->setFont(font);
        btnRotate->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #f39c12; color: white; border-radius: 6px; padding: 8px 20px;}\n"
"QToolButton:hover{background: #e67e22;}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Huanyuan.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRotate->setIcon(icon3);
        btnRotate->setIconSize(QSize(20, 20));
        btnRotate->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        bottomBar->addWidget(btnRotate);

        btnNext = new QToolButton(ImageViewerClass);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(0, 36));
        btnNext->setMaximumSize(QSize(16777215, 36));
        btnNext->setFont(font);
        btnNext->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 14px \"Microsoft YaHei\"; background: #95a5a6; color: white; border-radius: 6px; padding: 8px 20px;}\n"
"QToolButton:hover{background: #7f8c8d;}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PIC/Resources/PICs/calendar_nextmonth.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon4);
        btnNext->setIconSize(QSize(20, 20));
        btnNext->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        bottomBar->addWidget(btnNext);

        spacerBtn = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomBar->addItem(spacerBtn);

        btnClose = new QToolButton(ImageViewerClass);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(80, 36));
        btnClose->setMaximumSize(QSize(80, 36));
        btnClose->setFont(font);
        btnClose->setStyleSheet(QString::fromUtf8("QToolButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QToolButton:hover{background: #c0392b;}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon5);
        btnClose->setIconSize(QSize(20, 20));
        btnClose->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        bottomBar->addWidget(btnClose);


        rightPanel->addLayout(bottomBar);


        contentArea->addLayout(rightPanel);

        contentArea->setStretch(0, 2);
        contentArea->setStretch(1, 8);

        mainLayout->addLayout(contentArea);


        retranslateUi(ImageViewerClass);

        QMetaObject::connectSlotsByName(ImageViewerClass);
    } // setupUi

    void retranslateUi(QWidget *ImageViewerClass)
    {
        ImageViewerClass->setWindowTitle(QCoreApplication::translate("ImageViewerClass", "\346\237\245\347\234\213\345\233\276\345\203\217\350\256\260\345\275\225", nullptr));
        btnUp->setText(QCoreApplication::translate("ImageViewerClass", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        labelInfo->setText(QString());
        labelImage->setText(QString());
        btnPrev->setText(QCoreApplication::translate("ImageViewerClass", "\344\270\212\344\270\200\345\274\240", nullptr));
        btnRotate->setText(QCoreApplication::translate("ImageViewerClass", "\346\227\213\350\275\254", nullptr));
        btnNext->setText(QCoreApplication::translate("ImageViewerClass", "\344\270\213\344\270\200\345\274\240", nullptr));
        btnClose->setText(QCoreApplication::translate("ImageViewerClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerClass: public Ui_ImageViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
