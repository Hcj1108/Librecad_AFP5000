/********************************************************************************
** Form generated from reading UI file 'qg_dlgoptionsmakercam.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGOPTIONSMAKERCAM_H
#define UI_QG_DLGOPTIONSMAKERCAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgOptionsMakerCam
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbLayers;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hLayoutDefaultElementWidth;
    QLabel *lbDefaultElementWidth;
    QDoubleSpinBox *dSpinBoxDefaultElementWidth;
    QCheckBox *checkInvisibleLayers;
    QCheckBox *checkConstructionLayers;
    QGroupBox *gbBlocks;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout2;
    QCheckBox *checkBlocksInline;
    QGroupBox *gbEllipses;
    QHBoxLayout *hboxLayout2;
    QVBoxLayout *vboxLayout3;
    QCheckBox *checkEllipsesToBeziers;
    QGroupBox *gbImages;
    QHBoxLayout *hboxLayout3;
    QVBoxLayout *vboxLayout4;
    QCheckBox *checkImages;
    QGroupBox *gbDashLines;
    QHBoxLayout *hboxLayout4;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *hLayoutDashLinePatternLength;
    QLabel *lbDashLinePatternLength;
    QDoubleSpinBox *dSpinBoxDashLinePatternLength;
    QCheckBox *checkDashDotLines;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QG_DlgOptionsMakerCam)
    {
        if (QG_DlgOptionsMakerCam->objectName().isEmpty())
            QG_DlgOptionsMakerCam->setObjectName(QString::fromUtf8("QG_DlgOptionsMakerCam"));
        QG_DlgOptionsMakerCam->resize(500, 522);
        QG_DlgOptionsMakerCam->setMinimumSize(QSize(500, 522));
        vboxLayout = new QVBoxLayout(QG_DlgOptionsMakerCam);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        gbLayers = new QGroupBox(QG_DlgOptionsMakerCam);
        gbLayers->setObjectName(QString::fromUtf8("gbLayers"));
        hboxLayout = new QHBoxLayout(gbLayers);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hLayoutDefaultElementWidth = new QHBoxLayout();
        hLayoutDefaultElementWidth->setSpacing(6);
        hLayoutDefaultElementWidth->setObjectName(QString::fromUtf8("hLayoutDefaultElementWidth"));
        lbDefaultElementWidth = new QLabel(gbLayers);
        lbDefaultElementWidth->setObjectName(QString::fromUtf8("lbDefaultElementWidth"));

        hLayoutDefaultElementWidth->addWidget(lbDefaultElementWidth);

        dSpinBoxDefaultElementWidth = new QDoubleSpinBox(gbLayers);
        dSpinBoxDefaultElementWidth->setObjectName(QString::fromUtf8("dSpinBoxDefaultElementWidth"));
        dSpinBoxDefaultElementWidth->setMinimumSize(QSize(0, 0));
        dSpinBoxDefaultElementWidth->setSingleStep(0.010000000000000);
        dSpinBoxDefaultElementWidth->setValue(1.000000000000000);

        hLayoutDefaultElementWidth->addWidget(dSpinBoxDefaultElementWidth);


        vboxLayout1->addLayout(hLayoutDefaultElementWidth);

        checkInvisibleLayers = new QCheckBox(gbLayers);
        checkInvisibleLayers->setObjectName(QString::fromUtf8("checkInvisibleLayers"));

        vboxLayout1->addWidget(checkInvisibleLayers);

        checkConstructionLayers = new QCheckBox(gbLayers);
        checkConstructionLayers->setObjectName(QString::fromUtf8("checkConstructionLayers"));

        vboxLayout1->addWidget(checkConstructionLayers);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addWidget(gbLayers, 0, Qt::AlignTop);

        gbBlocks = new QGroupBox(QG_DlgOptionsMakerCam);
        gbBlocks->setObjectName(QString::fromUtf8("gbBlocks"));
        hboxLayout1 = new QHBoxLayout(gbBlocks);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(11, 11, 11, 11);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        checkBlocksInline = new QCheckBox(gbBlocks);
        checkBlocksInline->setObjectName(QString::fromUtf8("checkBlocksInline"));
        checkBlocksInline->setChecked(true);

        vboxLayout2->addWidget(checkBlocksInline);


        hboxLayout1->addLayout(vboxLayout2);


        vboxLayout->addWidget(gbBlocks, 0, Qt::AlignTop);

        gbEllipses = new QGroupBox(QG_DlgOptionsMakerCam);
        gbEllipses->setObjectName(QString::fromUtf8("gbEllipses"));
        hboxLayout2 = new QHBoxLayout(gbEllipses);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        checkEllipsesToBeziers = new QCheckBox(gbEllipses);
        checkEllipsesToBeziers->setObjectName(QString::fromUtf8("checkEllipsesToBeziers"));

        vboxLayout3->addWidget(checkEllipsesToBeziers);


        hboxLayout2->addLayout(vboxLayout3);


        vboxLayout->addWidget(gbEllipses, 0, Qt::AlignTop);

        gbImages = new QGroupBox(QG_DlgOptionsMakerCam);
        gbImages->setObjectName(QString::fromUtf8("gbImages"));
        hboxLayout3 = new QHBoxLayout(gbImages);
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(6);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        checkImages = new QCheckBox(gbImages);
        checkImages->setObjectName(QString::fromUtf8("checkImages"));

        vboxLayout4->addWidget(checkImages);


        hboxLayout3->addLayout(vboxLayout4);


        vboxLayout->addWidget(gbImages, 0, Qt::AlignTop);

        gbDashLines = new QGroupBox(QG_DlgOptionsMakerCam);
        gbDashLines->setObjectName(QString::fromUtf8("gbDashLines"));
        hboxLayout4 = new QHBoxLayout(gbDashLines);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(11, 11, 11, 11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        vboxLayout5 = new QVBoxLayout();
        vboxLayout5->setSpacing(6);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        hLayoutDashLinePatternLength = new QHBoxLayout();
        hLayoutDashLinePatternLength->setSpacing(6);
        hLayoutDashLinePatternLength->setObjectName(QString::fromUtf8("hLayoutDashLinePatternLength"));
        lbDashLinePatternLength = new QLabel(gbDashLines);
        lbDashLinePatternLength->setObjectName(QString::fromUtf8("lbDashLinePatternLength"));

        hLayoutDashLinePatternLength->addWidget(lbDashLinePatternLength);

        dSpinBoxDashLinePatternLength = new QDoubleSpinBox(gbDashLines);
        dSpinBoxDashLinePatternLength->setObjectName(QString::fromUtf8("dSpinBoxDashLinePatternLength"));
        dSpinBoxDashLinePatternLength->setMaximum(999.990000000000009);
        dSpinBoxDashLinePatternLength->setSingleStep(0.100000000000000);
        dSpinBoxDashLinePatternLength->setValue(10.000000000000000);

        hLayoutDashLinePatternLength->addWidget(dSpinBoxDashLinePatternLength);


        vboxLayout5->addLayout(hLayoutDashLinePatternLength);

        checkDashDotLines = new QCheckBox(gbDashLines);
        checkDashDotLines->setObjectName(QString::fromUtf8("checkDashDotLines"));

        vboxLayout5->addWidget(checkDashDotLines);


        hboxLayout4->addLayout(vboxLayout5);


        vboxLayout->addWidget(gbDashLines, 0, Qt::AlignTop);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        buttonBox = new QDialogButtonBox(QG_DlgOptionsMakerCam);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(QG_DlgOptionsMakerCam);
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgOptionsMakerCam, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgOptionsMakerCam, SLOT(validate()));

        QMetaObject::connectSlotsByName(QG_DlgOptionsMakerCam);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgOptionsMakerCam)
    {
        QG_DlgOptionsMakerCam->setWindowTitle(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Export as CAM/plain SVG", nullptr));
        gbLayers->setTitle(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Layers", nullptr));
        lbDefaultElementWidth->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Default width of elements, mm", nullptr));
        checkInvisibleLayers->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Export invisible layers", nullptr));
        checkConstructionLayers->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Export visible construction layers", nullptr));
        gbBlocks->setTitle(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Blocks", nullptr));
        checkBlocksInline->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Convert blocks to safe inline SVG content", nullptr));
        gbEllipses->setTitle(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Ellipses / Ellipse arcs", nullptr));
        checkEllipsesToBeziers->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Approximate ellipses and ellipse arcs with cubic b\303\251ziers", nullptr));
        gbImages->setTitle(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Images", nullptr));
        checkImages->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Raster Image export", nullptr));
        gbDashLines->setTitle(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Dash/Dot Lines", nullptr));
        lbDashLinePatternLength->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Length of the pattern, mm", nullptr));
        checkDashDotLines->setText(QCoreApplication::translate("QG_DlgOptionsMakerCam", "Bake dash/dot lines to SVG path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgOptionsMakerCam: public Ui_QG_DlgOptionsMakerCam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGOPTIONSMAKERCAM_H
