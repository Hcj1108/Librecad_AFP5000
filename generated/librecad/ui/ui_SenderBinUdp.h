/********************************************************************************
** Form generated from reading UI file 'SenderBinUdp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDERBINUDP_H
#define UI_SENDERBINUDP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SenderBinUdpClass
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QToolButton *toolButton_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QTextEdit *textEdit;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QToolButton *toolButton_2;
    QLabel *label_4;
    QToolButton *toolButton_7;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QGroupBox *groupBox_4;
    QTextEdit *textEdit_3;
    QToolButton *toolButton_5;

    void setupUi(QMainWindow *SenderBinUdpClass)
    {
        if (SenderBinUdpClass->objectName().isEmpty())
            SenderBinUdpClass->setObjectName(QString::fromUtf8("SenderBinUdpClass"));
        SenderBinUdpClass->resize(690, 370);
        SenderBinUdpClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(SenderBinUdpClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 10, 211, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(640, 10, 41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(true);
        toolButton_6->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PIC/Resources/PICs/GB.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(5, 50, 681, 311));
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("border:2px solid rgb(150, 150, 150)"));
        tabWidget->setIconSize(QSize(0, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 20, 81, 31));
        label_2->setFont(font2);
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setGeometry(QRect(110, 20, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        font3.setBold(true);
        spinBox->setFont(font3);
        spinBox->setWrapping(false);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMaximum(655536);
        spinBox_2 = new QSpinBox(tab);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setEnabled(false);
        spinBox_2->setGeometry(QRect(410, 20, 111, 31));
        spinBox_2->setFont(font3);
        spinBox_2->setWrapping(false);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_2->setMaximum(99999);
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(110, 70, 411, 101));
        textEdit->setFont(font3);
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(20, 190, 81, 41));
        toolButton->setFont(font2);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(110, 190, 301, 41));
        lineEdit->setFont(font3);
        lineEdit->setFrame(true);
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(420, 190, 101, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        font4.setBold(true);
        toolButton_2->setFont(font4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Bianji.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 81, 41));
        label_4->setFont(font2);
        toolButton_7 = new QToolButton(tab);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(540, 190, 101, 41));
        toolButton_7->setFont(font4);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon2);
        toolButton_7->setIconSize(QSize(40, 40));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 261, 241));
        groupBox_3->setFont(font2);
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(10, 30, 241, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(9);
        font5.setBold(false);
        lineEdit_2->setFont(font5);
        textEdit_2 = new QTextEdit(groupBox_3);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setEnabled(false);
        textEdit_2->setGeometry(QRect(10, 70, 241, 111));
        textEdit_2->setFont(font2);
        toolButton_3 = new QToolButton(groupBox_3);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 190, 121, 41));
        toolButton_4 = new QToolButton(groupBox_3);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(130, 190, 121, 41));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(300, 10, 361, 241));
        groupBox_4->setFont(font2);
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        textEdit_3 = new QTextEdit(groupBox_4);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setEnabled(false);
        textEdit_3->setGeometry(QRect(10, 30, 341, 151));
        textEdit_3->setFont(font2);
        toolButton_5 = new QToolButton(groupBox_4);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(10, 190, 121, 41));
        tabWidget->addTab(tab_2, QString());
        SenderBinUdpClass->setCentralWidget(centralWidget);

        retranslateUi(SenderBinUdpClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SenderBinUdpClass);
    } // setupUi

    void retranslateUi(QMainWindow *SenderBinUdpClass)
    {
        SenderBinUdpClass->setWindowTitle(QCoreApplication::translate("SenderBinUdpClass", "SenderBinUdp", nullptr));
        label_3->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\233\264\346\226\260", nullptr));
        toolButton_6->setText(QCoreApplication::translate("SenderBinUdpClass", "X", nullptr));
        label->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\257\217\345\214\205\345\255\227\350\212\202\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\257\217\345\214\205\351\227\264\351\232\224\357\274\232", nullptr));
        toolButton->setText(QCoreApplication::translate("SenderBinUdpClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        lineEdit->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("SenderBinUdpClass", "\344\270\200\351\224\256\345\206\231\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("SenderBinUdpClass", "\345\217\221\351\200\201\347\273\223\346\236\234\357\274\232", nullptr));
        toolButton_7->setText(QCoreApplication::translate("SenderBinUdpClass", "\347\250\213\345\272\217\346\223\246\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SenderBinUdpClass", "\347\241\254\344\273\266\345\215\207\347\272\247", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SenderBinUdpClass", "\345\210\207\346\215\242\346\250\241\345\236\213", nullptr));
        toolButton_3->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\250\241\345\236\213\351\200\211\346\213\251", nullptr));
        toolButton_4->setText(QCoreApplication::translate("SenderBinUdpClass", "\347\241\256\350\256\244\346\233\277\346\215\242", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("SenderBinUdpClass", "\345\275\223\345\211\215\346\250\241\345\236\213", nullptr));
        toolButton_5->setText(QCoreApplication::translate("SenderBinUdpClass", "\347\202\271\345\207\273\346\237\245\347\234\213\345\275\223\345\211\215\346\250\241\345\236\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SenderBinUdpClass", "\346\250\241\345\236\213\345\210\207\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SenderBinUdpClass: public Ui_SenderBinUdpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDERBINUDP_H
