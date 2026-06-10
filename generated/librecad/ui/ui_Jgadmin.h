/********************************************************************************
** Form generated from reading UI file 'Jgadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JGADMIN_H
#define UI_JGADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JgadminClass
{
public:
    QGroupBox *groupBox;
    QLabel *label_27;
    QLabel *label_34;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_20;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QGroupBox *groupBox_2;
    QLabel *label_103;
    QLabel *label_99;
    QLabel *label_102;
    QLabel *label_72;
    QLabel *label_101;
    QLabel *label_100;
    QSpinBox *spinBox_10;
    QSpinBox *spinBox_14;
    QSpinBox *spinBox_15;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QGroupBox *groupBox_3;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_25;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QSpinBox *spinBox_17;
    QSpinBox *spinBox_18;
    QSpinBox *spinBox_20;
    QSpinBox *spinBox_21;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QWidget *JgadminClass)
    {
        if (JgadminClass->objectName().isEmpty())
            JgadminClass->setObjectName(QString::fromUtf8("JgadminClass"));
        JgadminClass->resize(821, 349);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PNG/Resources/PNG/DYTZ.png"), QSize(), QIcon::Normal, QIcon::Off);
        JgadminClass->setWindowIcon(icon);
        JgadminClass->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(220, 235, 240);\n"
"}"));
        groupBox = new QGroupBox(JgadminClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(290, 20, 211, 311));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(14);
        font.setBold(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox->setCheckable(false);
        groupBox->setChecked(false);
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 30, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        font1.setBold(true);
        label_27->setFont(font1);
        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 70, 81, 31));
        label_34->setFont(font1);
        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 110, 81, 31));
        label_41->setFont(font1);
        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(10, 150, 81, 31));
        label_42->setFont(font1);
        label_44 = new QLabel(groupBox);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(10, 190, 81, 31));
        label_44->setFont(font1);
        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(10, 230, 81, 31));
        label_45->setFont(font1);
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 270, 81, 31));
        label_20->setFont(font1);
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(90, 30, 71, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(10);
        font2.setBold(true);
        spinBox->setFont(font2);
        spinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMinimum(5);
        spinBox->setMaximum(95);
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(90, 70, 71, 31));
        spinBox_2->setFont(font2);
        spinBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_2->setMinimum(5);
        spinBox_2->setMaximum(400);
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(90, 110, 71, 31));
        spinBox_3->setFont(font2);
        spinBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_3->setMinimum(0);
        spinBox_3->setMaximum(30);
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(90, 150, 71, 31));
        spinBox_4->setFont(font2);
        spinBox_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_4->setMinimum(0);
        spinBox_4->setMaximum(30);
        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(90, 190, 71, 31));
        spinBox_5->setFont(font2);
        spinBox_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_5->setMinimum(0);
        spinBox_5->setMaximum(800);
        spinBox_7 = new QSpinBox(groupBox);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(90, 230, 71, 31));
        spinBox_7->setFont(font2);
        spinBox_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_7->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_7->setMinimum(0);
        spinBox_7->setMaximum(30);
        spinBox_8 = new QSpinBox(groupBox);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(90, 270, 71, 31));
        spinBox_8->setFont(font2);
        spinBox_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_8->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_8->setMinimum(1);
        spinBox_8->setMaximum(999);
        groupBox_2 = new QGroupBox(JgadminClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 251, 311));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        label_103 = new QLabel(groupBox_2);
        label_103->setObjectName(QString::fromUtf8("label_103"));
        label_103->setGeometry(QRect(10, 30, 101, 31));
        label_103->setFont(font1);
        label_99 = new QLabel(groupBox_2);
        label_99->setObjectName(QString::fromUtf8("label_99"));
        label_99->setGeometry(QRect(10, 70, 131, 31));
        label_99->setFont(font1);
        label_102 = new QLabel(groupBox_2);
        label_102->setObjectName(QString::fromUtf8("label_102"));
        label_102->setGeometry(QRect(10, 110, 91, 31));
        label_102->setFont(font1);
        label_72 = new QLabel(groupBox_2);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setGeometry(QRect(10, 150, 111, 31));
        label_72->setFont(font1);
        label_101 = new QLabel(groupBox_2);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setGeometry(QRect(10, 230, 111, 31));
        label_101->setFont(font1);
        label_100 = new QLabel(groupBox_2);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setGeometry(QRect(10, 190, 111, 31));
        label_100->setFont(font1);
        spinBox_10 = new QSpinBox(groupBox_2);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setGeometry(QRect(140, 30, 81, 31));
        spinBox_10->setFont(font2);
        spinBox_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_10->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_10->setMinimum(1);
        spinBox_10->setMaximum(999);
        spinBox_14 = new QSpinBox(groupBox_2);
        spinBox_14->setObjectName(QString::fromUtf8("spinBox_14"));
        spinBox_14->setGeometry(QRect(140, 230, 81, 31));
        spinBox_14->setFont(font2);
        spinBox_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_14->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_14->setMinimum(1);
        spinBox_14->setMaximum(999);
        spinBox_15 = new QSpinBox(groupBox_2);
        spinBox_15->setObjectName(QString::fromUtf8("spinBox_15"));
        spinBox_15->setGeometry(QRect(140, 190, 81, 31));
        spinBox_15->setFont(font2);
        spinBox_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_15->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_15->setMinimum(1);
        spinBox_15->setMaximum(9999);
        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(140, 70, 81, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setPointSize(11);
        font3.setBold(true);
        comboBox_4->setFont(font3);
        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(140, 110, 81, 31));
        comboBox_5->setFont(font3);
        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(140, 150, 81, 31));
        comboBox_6->setFont(font3);
        groupBox_3 = new QGroupBox(JgadminClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(530, 20, 281, 311));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 30, 141, 31));
        label_23->setFont(font1);
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 70, 141, 31));
        label_22->setFont(font1);
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 110, 141, 31));
        label_25->setFont(font1);
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 150, 141, 31));
        label_37->setFont(font1);
        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(10, 190, 141, 31));
        label_38->setFont(font1);
        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 230, 141, 31));
        label_39->setFont(font1);
        spinBox_17 = new QSpinBox(groupBox_3);
        spinBox_17->setObjectName(QString::fromUtf8("spinBox_17"));
        spinBox_17->setGeometry(QRect(150, 70, 71, 31));
        spinBox_17->setFont(font2);
        spinBox_17->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_17->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_17->setMinimum(1);
        spinBox_17->setMaximum(9999);
        spinBox_18 = new QSpinBox(groupBox_3);
        spinBox_18->setObjectName(QString::fromUtf8("spinBox_18"));
        spinBox_18->setGeometry(QRect(150, 110, 71, 31));
        spinBox_18->setFont(font2);
        spinBox_18->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_18->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_18->setMinimum(1);
        spinBox_18->setMaximum(9999);
        spinBox_20 = new QSpinBox(groupBox_3);
        spinBox_20->setObjectName(QString::fromUtf8("spinBox_20"));
        spinBox_20->setGeometry(QRect(150, 190, 71, 31));
        spinBox_20->setFont(font2);
        spinBox_20->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_20->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_20->setMinimum(1);
        spinBox_20->setMaximum(9999);
        spinBox_21 = new QSpinBox(groupBox_3);
        spinBox_21->setObjectName(QString::fromUtf8("spinBox_21"));
        spinBox_21->setGeometry(QRect(150, 230, 71, 31));
        spinBox_21->setFont(font2);
        spinBox_21->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_21->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox_21->setMinimum(1);
        spinBox_21->setMaximum(9999);
        comboBox = new QComboBox(groupBox_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 30, 71, 31));
        comboBox->setFont(font3);
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 150, 71, 31));
        comboBox_2->setFont(font3);

        retranslateUi(JgadminClass);

        QMetaObject::connectSlotsByName(JgadminClass);
    } // setupUi

    void retranslateUi(QWidget *JgadminClass)
    {
        JgadminClass->setWindowTitle(QCoreApplication::translate("JgadminClass", "\346\211\223\345\215\260\345\217\202\346\225\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("JgadminClass", "\345\226\267\347\240\201\345\217\202\346\225\260", nullptr));
        label_27->setText(QCoreApplication::translate("JgadminClass", "\346\277\200\345\205\211\345\212\237\347\216\207:", nullptr));
        label_34->setText(QCoreApplication::translate("JgadminClass", "\346\277\200\345\205\211\351\242\221\347\216\207:", nullptr));
        label_41->setText(QCoreApplication::translate("JgadminClass", "\345\274\200\345\205\211\345\273\266\346\227\266:", nullptr));
        label_42->setText(QCoreApplication::translate("JgadminClass", "\345\205\263\345\205\211\345\273\266\346\227\266:", nullptr));
        label_44->setText(QCoreApplication::translate("JgadminClass", "\350\267\263\350\275\254\345\273\266\346\227\266:", nullptr));
        label_45->setText(QCoreApplication::translate("JgadminClass", "\347\273\223\346\235\237\345\273\266\346\227\266:", nullptr));
        label_20->setText(QCoreApplication::translate("JgadminClass", "\345\205\211\347\224\265\346\273\244\346\263\242:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("JgadminClass", "\346\265\201\346\260\264\347\272\277\350\256\276\347\275\256", nullptr));
        label_103->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\346\214\257\351\225\234\345\271\205\351\235\242:", nullptr));
        label_99->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\347\274\226\347\240\201\345\231\250\346\226\271\345\220\221:", nullptr));
        label_102->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\350\275\264\346\226\271\345\220\221:", nullptr));
        label_72->setText(QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214\346\250\241\345\274\217\345\274\200\345\205\263:", nullptr));
        label_101->setText(QCoreApplication::translate("JgadminClass", "\347\274\226\347\240\201\345\231\250\347\233\264\345\276\204:", nullptr));
        label_100->setText(QCoreApplication::translate("JgadminClass", "\347\274\226\347\240\201\345\231\250\350\204\211\345\206\262\346\225\260:", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("JgadminClass", "\351\241\272\346\227\266\351\222\210", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("JgadminClass", "\351\200\206\346\227\266\351\222\210", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("JgadminClass", "X\350\275\264\351\243\236\350\241\214", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("JgadminClass", "Y\350\275\264\351\243\236\350\241\214", nullptr));

        comboBox_6->setItemText(0, QCoreApplication::translate("JgadminClass", "\351\235\231\346\200\201", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("JgadminClass", "\351\243\236\350\241\214", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("JgadminClass", "\350\247\246\345\217\221\344\274\230\345\214\226", nullptr));
        label_23->setText(QCoreApplication::translate("JgadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\346\250\241\345\274\217:", nullptr));
        label_22->setText(QCoreApplication::translate("JgadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\346\227\266\351\227\264:", nullptr));
        label_25->setText(QCoreApplication::translate("JgadminClass", "\346\234\200\345\260\217\350\247\246\345\217\221\350\267\235\347\246\273:", nullptr));
        label_37->setText(QCoreApplication::translate("JgadminClass", "\346\240\207\345\210\273\345\273\266\345\220\216\350\247\246\345\217\221\346\250\241\345\274\217:", nullptr));
        label_38->setText(QCoreApplication::translate("JgadminClass", "\346\240\207\345\210\273\345\273\266\345\220\216\350\247\246\345\217\221\346\227\266\351\227\264:", nullptr));
        label_39->setText(QCoreApplication::translate("JgadminClass", "\346\240\207\345\210\273\345\273\266\345\220\216\350\247\246\345\217\221\350\267\235\347\246\273:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("JgadminClass", "\345\205\263\351\227\255", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("JgadminClass", "\346\227\266\351\227\264\346\250\241\345\274\217", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("JgadminClass", "\350\267\235\347\246\273\346\250\241\345\274\217", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("JgadminClass", "\345\205\263\351\227\255", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("JgadminClass", "\346\227\266\351\227\264\346\250\241\345\274\217", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("JgadminClass", "\350\267\235\347\246\273\346\250\241\345\274\217", nullptr));

    } // retranslateUi

};

namespace Ui {
    class JgadminClass: public Ui_JgadminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JGADMIN_H
