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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SenderBinUdpClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *tab1Layout;
    QHBoxLayout *paramRow;
    QLabel *label;
    QSpinBox *bytesPerPacketSpb;
    QLabel *label_2;
    QSpinBox *intervalSpb;
    QSpacerItem *paramSpacer;
    QTextEdit *dataEdit;
    QHBoxLayout *fileRow;
    QPushButton *selectFileBtn;
    QLineEdit *filePathEdit;
    QHBoxLayout *actionRow;
    QSpacerItem *actionSpacer;
    QPushButton *writeBtn;
    QPushButton *eraseBtn;
    QSpacerItem *actionSpacerRight;
    QWidget *tab_2;
    QHBoxLayout *tab2Layout;
    QGroupBox *switchModelBox;
    QVBoxLayout *switchModelLayout;
    QLineEdit *modelPathEdit;
    QTextEdit *modelInfoEdit;
    QHBoxLayout *modelBtnRow;
    QPushButton *selectModelBtn;
    QPushButton *confirmReplaceBtn;
    QGroupBox *currentModelBox;
    QVBoxLayout *currentModelLayout;
    QTextEdit *currentModelInfoEdit;
    QHBoxLayout *currentModelBtnRow;
    QSpacerItem *currentModelSpacer;
    QPushButton *viewModelBtn;
    QSpacerItem *currentModelSpacerRight;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;

    void setupUi(QMainWindow *SenderBinUdpClass)
    {
        if (SenderBinUdpClass->objectName().isEmpty())
            SenderBinUdpClass->setObjectName(QString::fromUtf8("SenderBinUdpClass"));
        SenderBinUdpClass->resize(735, 388);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/Gengxing.png"), QSize(), QIcon::Normal, QIcon::Off);
        SenderBinUdpClass->setWindowIcon(icon);
        SenderBinUdpClass->setStyleSheet(QString::fromUtf8("background-color:rgb(220, 235, 240);"));
        centralWidget = new QWidget(SenderBinUdpClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(8);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{border: 2px solid #dcdde1; border-radius: 8px; background: #ffffff; padding: 4px;}\n"
"QTabBar::tab{font: bold 12px \"Microsoft YaHei\"; padding: 8px 20px; margin-right: 2px; border: 1px solid #dcdde1; border-bottom: none; border-top-left-radius: 6px; border-top-right-radius: 6px; background: #ecf0f1; color: #7f8c8d;}\n"
"QTabBar::tab:selected{background: #ffffff; color: #2c3e50; border-bottom: 2px solid #3498db;}\n"
"QTabBar::tab:hover{background: #dfe6e9;}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab1Layout = new QVBoxLayout(tab);
        tab1Layout->setSpacing(10);
        tab1Layout->setObjectName(QString::fromUtf8("tab1Layout"));
        tab1Layout->setContentsMargins(15, 15, 15, 15);
        paramRow = new QHBoxLayout();
        paramRow->setSpacing(15);
        paramRow->setObjectName(QString::fromUtf8("paramRow"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        paramRow->addWidget(label);

        bytesPerPacketSpb = new QSpinBox(tab);
        bytesPerPacketSpb->setObjectName(QString::fromUtf8("bytesPerPacketSpb"));
        bytesPerPacketSpb->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setBold(true);
        font1.setItalic(false);
        bytesPerPacketSpb->setFont(font1);
        bytesPerPacketSpb->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: #fafafa; min-height: 32px;}\n"
"QSpinBox:focus{border-color: #3498db; background: #ffffff;}"));
        bytesPerPacketSpb->setWrapping(false);
        bytesPerPacketSpb->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        bytesPerPacketSpb->setMaximum(655536);

        paramRow->addWidget(bytesPerPacketSpb);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #34495e; background: transparent;"));

        paramRow->addWidget(label_2);

        intervalSpb = new QSpinBox(tab);
        intervalSpb->setObjectName(QString::fromUtf8("intervalSpb"));
        intervalSpb->setEnabled(false);
        intervalSpb->setFont(font1);
        intervalSpb->setStyleSheet(QString::fromUtf8("QSpinBox{font: bold 12px \"Microsoft YaHei\"; padding: 4px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: #fafafa; min-height: 32px;}\n"
"QSpinBox:focus{border-color: #3498db; background: #ffffff;}"));
        intervalSpb->setWrapping(false);
        intervalSpb->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        intervalSpb->setMaximum(99999);

        paramRow->addWidget(intervalSpb);

        paramSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        paramRow->addItem(paramSpacer);


        tab1Layout->addLayout(paramRow);

        dataEdit = new QTextEdit(tab);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));
        dataEdit->setEnabled(false);
        dataEdit->setFont(font1);
        dataEdit->setStyleSheet(QString::fromUtf8("QTextEdit{font: bold 11px \"Microsoft YaHei\"; border: 2px solid #bdc3c7; border-radius: 6px; background: #fafafa; padding: 6px;}\n"
"QTextEdit:focus{border-color: #3498db; background: #ffffff;}"));

        tab1Layout->addWidget(dataEdit);

        fileRow = new QHBoxLayout();
        fileRow->setSpacing(10);
        fileRow->setObjectName(QString::fromUtf8("fileRow"));
        selectFileBtn = new QPushButton(tab);
        selectFileBtn->setObjectName(QString::fromUtf8("selectFileBtn"));
        selectFileBtn->setMinimumSize(QSize(80, 36));
        selectFileBtn->setStyleSheet(QString::fromUtf8("QPushButton{background: #3498db; color: white; border-radius: 6px; padding: 8px 16px;}\n"
"QPushButton:hover{background: #2980b9;}"));

        fileRow->addWidget(selectFileBtn);

        filePathEdit = new QLineEdit(tab);
        filePathEdit->setObjectName(QString::fromUtf8("filePathEdit"));
        filePathEdit->setEnabled(false);
        filePathEdit->setFont(font1);
        filePathEdit->setStyleSheet(QString::fromUtf8("QLineEdit{font: bold 11px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #bdc3c7; border-radius: 6px; background: #f0f0f0; min-height: 32px;}"));

        fileRow->addWidget(filePathEdit);


        tab1Layout->addLayout(fileRow);

        actionRow = new QHBoxLayout();
        actionRow->setSpacing(10);
        actionRow->setObjectName(QString::fromUtf8("actionRow"));
        actionSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        actionRow->addItem(actionSpacer);

        writeBtn = new QPushButton(tab);
        writeBtn->setObjectName(QString::fromUtf8("writeBtn"));
        writeBtn->setMinimumSize(QSize(110, 40));
        writeBtn->setStyleSheet(QString::fromUtf8("QPushButton{background: #27ae60; color: white; border-radius: 6px; padding: 8px 20px;}\n"
"QPushButton:hover{background: #219a52;}\n"
"QPushButton:pressed{background: #1e8449;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Bianji.png"), QSize(), QIcon::Normal, QIcon::Off);
        writeBtn->setIcon(icon1);
        writeBtn->setIconSize(QSize(20, 20));

        actionRow->addWidget(writeBtn);

        eraseBtn = new QPushButton(tab);
        eraseBtn->setObjectName(QString::fromUtf8("eraseBtn"));
        eraseBtn->setMinimumSize(QSize(110, 40));
        eraseBtn->setStyleSheet(QString::fromUtf8("QPushButton{background: #e74c3c; color: white; border-radius: 6px; padding: 8px 20px;}\n"
"QPushButton:hover{background: #c0392b;}\n"
"QPushButton:pressed{background: #a93226;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PIC/Resources/PICs/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraseBtn->setIcon(icon2);
        eraseBtn->setIconSize(QSize(20, 20));

        actionRow->addWidget(eraseBtn);

        actionSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        actionRow->addItem(actionSpacerRight);


        tab1Layout->addLayout(actionRow);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab2Layout = new QHBoxLayout(tab_2);
        tab2Layout->setSpacing(12);
        tab2Layout->setObjectName(QString::fromUtf8("tab2Layout"));
        tab2Layout->setContentsMargins(12, 12, 12, 12);
        switchModelBox = new QGroupBox(tab_2);
        switchModelBox->setObjectName(QString::fromUtf8("switchModelBox"));
        switchModelBox->setFont(font1);
        switchModelBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 2px solid #e0e0e0; border-radius: 10px; margin-top: 14px; padding-top: 18px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 14px; padding: 4px 14px; background: #3498db; color: white; border-radius: 4px;}\n"
"QTextEdit{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #dcdde1; border-radius: 6px; background: #fafafa; padding: 6px;}\n"
"QTextEdit:focus{border-color: #3498db; background: #ffffff;}\n"
"QLineEdit{font: 12px \"Microsoft YaHei\"; padding: 6px 10px; border: 2px solid #dcdde1; border-radius: 6px; background: #f0f0f0; min-height: 30px;}\n"
"QPushButton{font: bold 12px \"Microsoft YaHei\"; border-radius: 6px; padding: 8px 16px; min-height: 32px;}\n"
"QPushButton:hover{opacity: 0.9;}"));
        switchModelLayout = new QVBoxLayout(switchModelBox);
        switchModelLayout->setSpacing(10);
        switchModelLayout->setObjectName(QString::fromUtf8("switchModelLayout"));
        switchModelLayout->setContentsMargins(14, 16, 14, 14);
        modelPathEdit = new QLineEdit(switchModelBox);
        modelPathEdit->setObjectName(QString::fromUtf8("modelPathEdit"));
        modelPathEdit->setEnabled(false);

        switchModelLayout->addWidget(modelPathEdit);

        modelInfoEdit = new QTextEdit(switchModelBox);
        modelInfoEdit->setObjectName(QString::fromUtf8("modelInfoEdit"));
        modelInfoEdit->setEnabled(false);

        switchModelLayout->addWidget(modelInfoEdit);

        modelBtnRow = new QHBoxLayout();
        modelBtnRow->setSpacing(10);
        modelBtnRow->setObjectName(QString::fromUtf8("modelBtnRow"));
        selectModelBtn = new QPushButton(switchModelBox);
        selectModelBtn->setObjectName(QString::fromUtf8("selectModelBtn"));
        selectModelBtn->setMinimumSize(QSize(90, 48));
        selectModelBtn->setStyleSheet(QString::fromUtf8("QPushButton{background: #3498db; color: white;} QPushButton:hover{background: #2980b9;}"));

        modelBtnRow->addWidget(selectModelBtn);

        confirmReplaceBtn = new QPushButton(switchModelBox);
        confirmReplaceBtn->setObjectName(QString::fromUtf8("confirmReplaceBtn"));
        confirmReplaceBtn->setMinimumSize(QSize(90, 48));
        confirmReplaceBtn->setStyleSheet(QString::fromUtf8("QPushButton{background: #27ae60; color: white;} QPushButton:hover{background: #219a52;}"));

        modelBtnRow->addWidget(confirmReplaceBtn);


        switchModelLayout->addLayout(modelBtnRow);


        tab2Layout->addWidget(switchModelBox);

        currentModelBox = new QGroupBox(tab_2);
        currentModelBox->setObjectName(QString::fromUtf8("currentModelBox"));
        currentModelBox->setFont(font1);
        currentModelBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: bold 14px \"Microsoft YaHei\"; color: #2c3e50; border: 2px solid #e0e0e0; border-radius: 10px; margin-top: 14px; padding-top: 18px; background: #ffffff;}\n"
"QGroupBox::title{subcontrol-origin: margin; left: 14px; padding: 4px 14px; background: #27ae60; color: white; border-radius: 4px;}\n"
"QTextEdit{font: bold 12px \"Microsoft YaHei\"; border: 2px solid #dcdde1; border-radius: 6px; background: #fafafa; padding: 6px;}\n"
"QTextEdit:focus{border-color: #3498db; background: #ffffff;}\n"
"QPushButton{font: bold 12px \"Microsoft YaHei\"; border-radius: 6px; padding: 8px 16px; min-height: 32px;}\n"
"QPushButton:hover{opacity: 0.9;}"));
        currentModelLayout = new QVBoxLayout(currentModelBox);
        currentModelLayout->setSpacing(10);
        currentModelLayout->setObjectName(QString::fromUtf8("currentModelLayout"));
        currentModelLayout->setContentsMargins(14, 16, 14, 14);
        currentModelInfoEdit = new QTextEdit(currentModelBox);
        currentModelInfoEdit->setObjectName(QString::fromUtf8("currentModelInfoEdit"));
        currentModelInfoEdit->setEnabled(false);

        currentModelLayout->addWidget(currentModelInfoEdit);

        currentModelBtnRow = new QHBoxLayout();
        currentModelBtnRow->setSpacing(10);
        currentModelBtnRow->setObjectName(QString::fromUtf8("currentModelBtnRow"));
        currentModelSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        currentModelBtnRow->addItem(currentModelSpacer);

        viewModelBtn = new QPushButton(currentModelBox);
        viewModelBtn->setObjectName(QString::fromUtf8("viewModelBtn"));
        viewModelBtn->setMinimumSize(QSize(120, 48));
        viewModelBtn->setStyleSheet(QString::fromUtf8("QPushButton{background: #3498db; color: white;} QPushButton:hover{background: #2980b9;}"));

        currentModelBtnRow->addWidget(viewModelBtn);

        currentModelSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        currentModelBtnRow->addItem(currentModelSpacerRight);


        currentModelLayout->addLayout(currentModelBtnRow);


        tab2Layout->addWidget(currentModelBox);

        tabWidget->addTab(tab_2, QString());

        mainLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeBtn = new QPushButton(centralWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(80, 36));
        closeBtn->setMaximumSize(QSize(80, 36));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{font: bold 12px \"Microsoft YaHei\"; background: #e74c3c; color: white; border-radius: 6px; padding: 6px 14px;}\n"
"QPushButton:hover{background: #c0392b;}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PIC/Resources/PICs/Fanhui.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon3);
        closeBtn->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(closeBtn);


        mainLayout->addLayout(horizontalLayout);

        SenderBinUdpClass->setCentralWidget(centralWidget);

        retranslateUi(SenderBinUdpClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SenderBinUdpClass);
    } // setupUi

    void retranslateUi(QMainWindow *SenderBinUdpClass)
    {
        SenderBinUdpClass->setWindowTitle(QCoreApplication::translate("SenderBinUdpClass", "\345\233\272\344\273\266\346\233\264\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\257\217\345\214\205\345\255\227\350\212\202\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\257\217\345\214\205\351\227\264\351\232\224\357\274\232", nullptr));
        dataEdit->setPlaceholderText(QCoreApplication::translate("SenderBinUdpClass", "\346\225\260\346\215\256\345\206\205\345\256\271...", nullptr));
        selectFileBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        filePathEdit->setPlaceholderText(QCoreApplication::translate("SenderBinUdpClass", "\346\234\252\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        writeBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\344\270\200\351\224\256\345\206\231\345\205\245", nullptr));
        eraseBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\347\250\213\345\272\217\346\223\246\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SenderBinUdpClass", "\347\241\254\344\273\266\345\215\207\347\272\247", nullptr));
        switchModelBox->setTitle(QCoreApplication::translate("SenderBinUdpClass", "\345\210\207\346\215\242\346\250\241\345\236\213", nullptr));
        modelPathEdit->setPlaceholderText(QCoreApplication::translate("SenderBinUdpClass", "\346\250\241\345\236\213\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        modelInfoEdit->setPlaceholderText(QCoreApplication::translate("SenderBinUdpClass", "\346\250\241\345\236\213\344\277\241\346\201\257...", nullptr));
        selectModelBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\250\241\345\236\213\351\200\211\346\213\251", nullptr));
        confirmReplaceBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\347\241\256\350\256\244\346\233\277\346\215\242", nullptr));
        currentModelBox->setTitle(QCoreApplication::translate("SenderBinUdpClass", "\345\275\223\345\211\215\346\250\241\345\236\213", nullptr));
        currentModelInfoEdit->setPlaceholderText(QCoreApplication::translate("SenderBinUdpClass", "\345\275\223\345\211\215\350\277\220\350\241\214\346\250\241\345\236\213\344\277\241\346\201\257...", nullptr));
        viewModelBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\346\237\245\347\234\213\345\275\223\345\211\215\346\250\241\345\236\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SenderBinUdpClass", "\346\250\241\345\236\213\345\210\207\346\215\242", nullptr));
        closeBtn->setText(QCoreApplication::translate("SenderBinUdpClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SenderBinUdpClass: public Ui_SenderBinUdpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDERBINUDP_H
