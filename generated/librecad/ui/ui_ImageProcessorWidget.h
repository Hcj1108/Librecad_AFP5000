/********************************************************************************
** Form generated from reading UI file 'ImageProcessorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESSORWIDGET_H
#define UI_IMAGEPROCESSORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProcessorWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnSelectFolder;
    QHBoxLayout *horizontalLayout;
    QLabel *lblOriginal;
    QLabel *lblProcessed;
    QLabel *lblStatus;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnProcess;
    QPushButton *btnSave;
    QCheckBox *chkLivePreview;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *sliderBrightness;
    QLabel *label_2;
    QSlider *sliderContrast;

    void setupUi(QWidget *ImageProcessorWidget)
    {
        if (ImageProcessorWidget->objectName().isEmpty())
            ImageProcessorWidget->setObjectName(QString::fromUtf8("ImageProcessorWidget"));
        ImageProcessorWidget->resize(427, 421);
        verticalLayout = new QVBoxLayout(ImageProcessorWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ImageProcessorWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnSelectFolder = new QPushButton(groupBox);
        btnSelectFolder->setObjectName(QString::fromUtf8("btnSelectFolder"));

        verticalLayout_2->addWidget(btnSelectFolder);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblOriginal = new QLabel(groupBox);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setFrameShape(QFrame::Shape::Box);
        lblOriginal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblOriginal);

        lblProcessed = new QLabel(groupBox);
        lblProcessed->setObjectName(QString::fromUtf8("lblProcessed"));
        lblProcessed->setFrameShape(QFrame::Shape::Box);
        lblProcessed->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblProcessed);


        verticalLayout_2->addLayout(horizontalLayout);

        lblStatus = new QLabel(groupBox);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));

        verticalLayout_2->addWidget(lblStatus);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ImageProcessorWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnProcess = new QPushButton(groupBox_2);
        btnProcess->setObjectName(QString::fromUtf8("btnProcess"));
        btnProcess->setEnabled(false);

        horizontalLayout_2->addWidget(btnProcess);

        btnSave = new QPushButton(groupBox_2);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setEnabled(false);

        horizontalLayout_2->addWidget(btnSave);


        verticalLayout_3->addLayout(horizontalLayout_2);

        chkLivePreview = new QCheckBox(groupBox_2);
        chkLivePreview->setObjectName(QString::fromUtf8("chkLivePreview"));

        verticalLayout_3->addWidget(chkLivePreview);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sliderBrightness = new QSlider(groupBox_2);
        sliderBrightness->setObjectName(QString::fromUtf8("sliderBrightness"));
        sliderBrightness->setMinimum(-100);
        sliderBrightness->setMaximum(100);
        sliderBrightness->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, sliderBrightness);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sliderContrast = new QSlider(groupBox_2);
        sliderContrast->setObjectName(QString::fromUtf8("sliderContrast"));
        sliderContrast->setMinimum(-100);
        sliderContrast->setMaximum(100);
        sliderContrast->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, sliderContrast);


        verticalLayout_3->addLayout(formLayout);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(ImageProcessorWidget);

        QMetaObject::connectSlotsByName(ImageProcessorWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageProcessorWidget)
    {
        btnSelectFolder->setText(QCoreApplication::translate("ImageProcessorWidget", "Select Image Folder", nullptr));
        lblStatus->setText(QCoreApplication::translate("ImageProcessorWidget", "Ready", nullptr));
        btnProcess->setText(QCoreApplication::translate("ImageProcessorWidget", "Process Image", nullptr));
        btnSave->setText(QCoreApplication::translate("ImageProcessorWidget", "Save Result", nullptr));
        chkLivePreview->setText(QCoreApplication::translate("ImageProcessorWidget", "Live Preview", nullptr));
        label->setText(QCoreApplication::translate("ImageProcessorWidget", "Brightness:", nullptr));
        label_2->setText(QCoreApplication::translate("ImageProcessorWidget", "Contrast:", nullptr));
        (void)ImageProcessorWidget;
    } // retranslateUi

};

namespace Ui {
    class ImageProcessorWidget: public Ui_ImageProcessorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESSORWIDGET_H
