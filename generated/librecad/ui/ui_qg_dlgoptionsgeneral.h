/********************************************************************************
** Form generated from reading UI file 'qg_dlgoptionsgeneral.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QG_DLGOPTIONSGENERAL_H
#define UI_QG_DLGOPTIONSGENERAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QG_DlgOptionsGeneral
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_3;
    QGroupBox *bgLanguage;
    QGridLayout *language_layout;
    QLabel *lLanguage;
    QComboBox *cbLanguageCmd;
    QLabel *lLanguageCmd;
    QComboBox *cbLanguage;
    QGroupBox *bgGraphicView;
    QGridLayout *graphic_view_layout;
    QCheckBox *indicator_lines_checkbox;
    QComboBox *indicator_lines_combobox;
    QCheckBox *indicator_shape_checkbox;
    QComboBox *indicator_shape_combobox;
    QCheckBox *cursor_hiding_checkbox;
    QCheckBox *cb_antialiasing;
    QCheckBox *scrollbars_check_box;
    QCheckBox *cbScaleGrid;
    QLabel *lMinGridSpacing;
    QComboBox *cbMinGridSpacing;
    QLabel *lMaxPreview;
    QComboBox *cbMaxPreview;
    QGroupBox *bgGraphicColors;
    QGridLayout *graphicColGridLayout;
    QComboBox *cbHandleColor;
    QLabel *label_3;
    QLabel *lGridColor;
    QComboBox *cbEndHandleColor;
    QPushButton *pb_background;
    QPushButton *pb_grid;
    QPushButton *pb_meta;
    QPushButton *pb_selected;
    QPushButton *pb_highlighted;
    QPushButton *pb_start;
    QPushButton *pb_handle;
    QPushButton *pb_end;
    QLabel *lHighlightedColor;
    QComboBox *cbHighlightedColor;
    QLabel *lMetaGridColor;
    QComboBox *cbSelectedColor;
    QLabel *lSelectedColor;
    QComboBox *cbGridColor;
    QLabel *lStartHandleColor;
    QLabel *lBackground;
    QComboBox *cbBackgroundColor;
    QComboBox *cbMetaGridColor;
    QComboBox *cbStartHandleColor;
    QLabel *label_2;
    QLabel *label_6;
    QComboBox *cb_snap_color;
    QPushButton *pb_snap_color;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *textLabel4;
    QLineEdit *lePathTranslations;
    QLabel *textLabel6;
    QLineEdit *lePathHatch;
    QLabel *textLabel7;
    QLineEdit *leTemplate;
    QLineEdit *lePathLibrary;
    QLineEdit *lePathFonts;
    QToolButton *btTemplate;
    QSpacerItem *spacer5_2;
    QLabel *textLabel2;
    QLabel *textLabel3;
    QSpacerItem *spacer5;
    QLineEdit *variablefile_field;
    QToolButton *variablefile_button;
    QToolButton *fonts_button;
    QWidget *tab_3;
    QGridLayout *gridLayout1;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *cbAutoBackup;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *cbAutoSaveTime;
    QCheckBox *cbUseQtFileOpenDialog;
    QCheckBox *cbWheelScrollInvertH;
    QCheckBox *cbWheelScrollInvertV;
    QCheckBox *cbInvertZoomDirection;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_clear_geometry;
    QPushButton *pb_clear_all;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbSplash;
    QCheckBox *tab_mode_check_box;
    QCheckBox *maximize_checkbox;
    QCheckBox *left_sidebar_checkbox;
    QCheckBox *cad_toolbars_checkbox;
    QGroupBox *buttonGroup5;
    QHBoxLayout *hboxLayout;
    QLabel *lUnit;
    QComboBox *cbUnit;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cbEvaluateOnSpace;
    QCheckBox *cbToggleFreeSnapOnSpace;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *cbToActiveLayer;
    QCheckBox *cbAutoZoomDrawing;

    void setupUi(QDialog *QG_DlgOptionsGeneral)
    {
        if (QG_DlgOptionsGeneral->objectName().isEmpty())
            QG_DlgOptionsGeneral->setObjectName(QString::fromUtf8("QG_DlgOptionsGeneral"));
        QG_DlgOptionsGeneral->resize(783, 603);
        QG_DlgOptionsGeneral->setSizeGripEnabled(true);
        gridLayout_2 = new QGridLayout(QG_DlgOptionsGeneral);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        buttonBox = new QDialogButtonBox(QG_DlgOptionsGeneral);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        tabWidget = new QTabWidget(QG_DlgOptionsGeneral);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_3 = new QGridLayout(tab_1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        bgLanguage = new QGroupBox(tab_1);
        bgLanguage->setObjectName(QString::fromUtf8("bgLanguage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bgLanguage->sizePolicy().hasHeightForWidth());
        bgLanguage->setSizePolicy(sizePolicy);
        language_layout = new QGridLayout(bgLanguage);
        language_layout->setSpacing(6);
        language_layout->setContentsMargins(11, 11, 11, 11);
        language_layout->setObjectName(QString::fromUtf8("language_layout"));
        lLanguage = new QLabel(bgLanguage);
        lLanguage->setObjectName(QString::fromUtf8("lLanguage"));
        lLanguage->setWordWrap(false);

        language_layout->addWidget(lLanguage, 0, 0, 1, 1);

        cbLanguageCmd = new QComboBox(bgLanguage);
        cbLanguageCmd->setObjectName(QString::fromUtf8("cbLanguageCmd"));

        language_layout->addWidget(cbLanguageCmd, 1, 1, 1, 1);

        lLanguageCmd = new QLabel(bgLanguage);
        lLanguageCmd->setObjectName(QString::fromUtf8("lLanguageCmd"));
        lLanguageCmd->setWordWrap(false);

        language_layout->addWidget(lLanguageCmd, 1, 0, 1, 1);

        cbLanguage = new QComboBox(bgLanguage);
        cbLanguage->setObjectName(QString::fromUtf8("cbLanguage"));

        language_layout->addWidget(cbLanguage, 0, 1, 1, 1);


        gridLayout_3->addWidget(bgLanguage, 3, 0, 1, 2);

        bgGraphicView = new QGroupBox(tab_1);
        bgGraphicView->setObjectName(QString::fromUtf8("bgGraphicView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bgGraphicView->sizePolicy().hasHeightForWidth());
        bgGraphicView->setSizePolicy(sizePolicy1);
        graphic_view_layout = new QGridLayout(bgGraphicView);
        graphic_view_layout->setSpacing(6);
        graphic_view_layout->setContentsMargins(11, 11, 11, 11);
        graphic_view_layout->setObjectName(QString::fromUtf8("graphic_view_layout"));
        indicator_lines_checkbox = new QCheckBox(bgGraphicView);
        indicator_lines_checkbox->setObjectName(QString::fromUtf8("indicator_lines_checkbox"));

        graphic_view_layout->addWidget(indicator_lines_checkbox, 0, 0, 1, 1);

        indicator_lines_combobox = new QComboBox(bgGraphicView);
        indicator_lines_combobox->addItem(QString::fromUtf8("Crosshair"));
        indicator_lines_combobox->addItem(QString::fromUtf8("Crosshair2"));
        indicator_lines_combobox->addItem(QString::fromUtf8("Isometric"));
        indicator_lines_combobox->addItem(QString::fromUtf8("Spiderweb"));
        indicator_lines_combobox->setObjectName(QString::fromUtf8("indicator_lines_combobox"));
#if QT_CONFIG(accessibility)
        indicator_lines_combobox->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)

        graphic_view_layout->addWidget(indicator_lines_combobox, 0, 1, 1, 1);

        indicator_shape_checkbox = new QCheckBox(bgGraphicView);
        indicator_shape_checkbox->setObjectName(QString::fromUtf8("indicator_shape_checkbox"));

        graphic_view_layout->addWidget(indicator_shape_checkbox, 1, 0, 1, 1);

        indicator_shape_combobox = new QComboBox(bgGraphicView);
        indicator_shape_combobox->addItem(QString::fromUtf8("Circle"));
        indicator_shape_combobox->addItem(QString::fromUtf8("Point"));
        indicator_shape_combobox->addItem(QString::fromUtf8("Square"));
        indicator_shape_combobox->setObjectName(QString::fromUtf8("indicator_shape_combobox"));
#if QT_CONFIG(accessibility)
        indicator_shape_combobox->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)

        graphic_view_layout->addWidget(indicator_shape_combobox, 1, 1, 1, 1);

        cursor_hiding_checkbox = new QCheckBox(bgGraphicView);
        cursor_hiding_checkbox->setObjectName(QString::fromUtf8("cursor_hiding_checkbox"));

        graphic_view_layout->addWidget(cursor_hiding_checkbox, 2, 0, 1, 1);

        cb_antialiasing = new QCheckBox(bgGraphicView);
        cb_antialiasing->setObjectName(QString::fromUtf8("cb_antialiasing"));

        graphic_view_layout->addWidget(cb_antialiasing, 3, 0, 1, 1);

        scrollbars_check_box = new QCheckBox(bgGraphicView);
        scrollbars_check_box->setObjectName(QString::fromUtf8("scrollbars_check_box"));

        graphic_view_layout->addWidget(scrollbars_check_box, 4, 0, 1, 1);

        cbScaleGrid = new QCheckBox(bgGraphicView);
        cbScaleGrid->setObjectName(QString::fromUtf8("cbScaleGrid"));

        graphic_view_layout->addWidget(cbScaleGrid, 5, 0, 1, 1);

        lMinGridSpacing = new QLabel(bgGraphicView);
        lMinGridSpacing->setObjectName(QString::fromUtf8("lMinGridSpacing"));
        lMinGridSpacing->setWordWrap(false);

        graphic_view_layout->addWidget(lMinGridSpacing, 6, 0, 1, 1);

        cbMinGridSpacing = new QComboBox(bgGraphicView);
        cbMinGridSpacing->addItem(QString::fromUtf8("0"));
        cbMinGridSpacing->addItem(QString::fromUtf8("4"));
        cbMinGridSpacing->addItem(QString::fromUtf8("5"));
        cbMinGridSpacing->addItem(QString::fromUtf8("6"));
        cbMinGridSpacing->addItem(QString::fromUtf8("8"));
        cbMinGridSpacing->addItem(QString::fromUtf8("10"));
        cbMinGridSpacing->addItem(QString::fromUtf8("15"));
        cbMinGridSpacing->addItem(QString::fromUtf8("20"));
        cbMinGridSpacing->setObjectName(QString::fromUtf8("cbMinGridSpacing"));
        cbMinGridSpacing->setEditable(true);

        graphic_view_layout->addWidget(cbMinGridSpacing, 6, 1, 1, 1);

        lMaxPreview = new QLabel(bgGraphicView);
        lMaxPreview->setObjectName(QString::fromUtf8("lMaxPreview"));
        lMaxPreview->setWordWrap(false);

        graphic_view_layout->addWidget(lMaxPreview, 7, 0, 1, 1);

        cbMaxPreview = new QComboBox(bgGraphicView);
        cbMaxPreview->addItem(QString::fromUtf8("0"));
        cbMaxPreview->addItem(QString::fromUtf8("50"));
        cbMaxPreview->addItem(QString::fromUtf8("100"));
        cbMaxPreview->addItem(QString::fromUtf8("200"));
        cbMaxPreview->addItem(QString::fromUtf8("400"));
        cbMaxPreview->addItem(QString::fromUtf8("800"));
        cbMaxPreview->setObjectName(QString::fromUtf8("cbMaxPreview"));
        cbMaxPreview->setEditable(true);

        graphic_view_layout->addWidget(cbMaxPreview, 7, 1, 1, 1);


        gridLayout_3->addWidget(bgGraphicView, 0, 0, 3, 1);

        bgGraphicColors = new QGroupBox(tab_1);
        bgGraphicColors->setObjectName(QString::fromUtf8("bgGraphicColors"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bgGraphicColors->sizePolicy().hasHeightForWidth());
        bgGraphicColors->setSizePolicy(sizePolicy2);
        bgGraphicColors->setFlat(false);
        graphicColGridLayout = new QGridLayout(bgGraphicColors);
        graphicColGridLayout->setSpacing(6);
        graphicColGridLayout->setContentsMargins(11, 11, 11, 11);
        graphicColGridLayout->setObjectName(QString::fromUtf8("graphicColGridLayout"));
        cbHandleColor = new QComboBox(bgGraphicColors);
        cbHandleColor->addItem(QString::fromUtf8("#0000FF"));
        cbHandleColor->setObjectName(QString::fromUtf8("cbHandleColor"));
#if QT_CONFIG(accessibility)
        cbHandleColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbHandleColor->setEditable(true);

        graphicColGridLayout->addWidget(cbHandleColor, 7, 2, 1, 1);

        label_3 = new QLabel(bgGraphicColors);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        graphicColGridLayout->addWidget(label_3, 8, 0, 1, 1);

        lGridColor = new QLabel(bgGraphicColors);
        lGridColor->setObjectName(QString::fromUtf8("lGridColor"));
        lGridColor->setWordWrap(false);

        graphicColGridLayout->addWidget(lGridColor, 2, 0, 1, 1);

        cbEndHandleColor = new QComboBox(bgGraphicColors);
        cbEndHandleColor->addItem(QString::fromUtf8("#0000FF"));
        cbEndHandleColor->setObjectName(QString::fromUtf8("cbEndHandleColor"));
#if QT_CONFIG(accessibility)
        cbEndHandleColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbEndHandleColor->setEditable(true);

        graphicColGridLayout->addWidget(cbEndHandleColor, 8, 2, 1, 1);

        pb_background = new QPushButton(bgGraphicColors);
        pb_background->setObjectName(QString::fromUtf8("pb_background"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pb_background->sizePolicy().hasHeightForWidth());
        pb_background->setSizePolicy(sizePolicy3);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/colorxx.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_background->setIcon(icon);

        graphicColGridLayout->addWidget(pb_background, 1, 3, 1, 1);

        pb_grid = new QPushButton(bgGraphicColors);
        pb_grid->setObjectName(QString::fromUtf8("pb_grid"));
        sizePolicy3.setHeightForWidth(pb_grid->sizePolicy().hasHeightForWidth());
        pb_grid->setSizePolicy(sizePolicy3);
        pb_grid->setIcon(icon);

        graphicColGridLayout->addWidget(pb_grid, 2, 3, 1, 1);

        pb_meta = new QPushButton(bgGraphicColors);
        pb_meta->setObjectName(QString::fromUtf8("pb_meta"));
        sizePolicy3.setHeightForWidth(pb_meta->sizePolicy().hasHeightForWidth());
        pb_meta->setSizePolicy(sizePolicy3);
        pb_meta->setIcon(icon);

        graphicColGridLayout->addWidget(pb_meta, 3, 3, 1, 1);

        pb_selected = new QPushButton(bgGraphicColors);
        pb_selected->setObjectName(QString::fromUtf8("pb_selected"));
        sizePolicy3.setHeightForWidth(pb_selected->sizePolicy().hasHeightForWidth());
        pb_selected->setSizePolicy(sizePolicy3);
        pb_selected->setIcon(icon);

        graphicColGridLayout->addWidget(pb_selected, 4, 3, 1, 1);

        pb_highlighted = new QPushButton(bgGraphicColors);
        pb_highlighted->setObjectName(QString::fromUtf8("pb_highlighted"));
        sizePolicy3.setHeightForWidth(pb_highlighted->sizePolicy().hasHeightForWidth());
        pb_highlighted->setSizePolicy(sizePolicy3);
        pb_highlighted->setIcon(icon);

        graphicColGridLayout->addWidget(pb_highlighted, 5, 3, 1, 1);

        pb_start = new QPushButton(bgGraphicColors);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));
        sizePolicy3.setHeightForWidth(pb_start->sizePolicy().hasHeightForWidth());
        pb_start->setSizePolicy(sizePolicy3);
        pb_start->setIcon(icon);

        graphicColGridLayout->addWidget(pb_start, 6, 3, 1, 1);

        pb_handle = new QPushButton(bgGraphicColors);
        pb_handle->setObjectName(QString::fromUtf8("pb_handle"));
        sizePolicy3.setHeightForWidth(pb_handle->sizePolicy().hasHeightForWidth());
        pb_handle->setSizePolicy(sizePolicy3);
        pb_handle->setIcon(icon);

        graphicColGridLayout->addWidget(pb_handle, 7, 3, 1, 1);

        pb_end = new QPushButton(bgGraphicColors);
        pb_end->setObjectName(QString::fromUtf8("pb_end"));
        sizePolicy3.setHeightForWidth(pb_end->sizePolicy().hasHeightForWidth());
        pb_end->setSizePolicy(sizePolicy3);
        pb_end->setIcon(icon);

        graphicColGridLayout->addWidget(pb_end, 8, 3, 1, 1);

        lHighlightedColor = new QLabel(bgGraphicColors);
        lHighlightedColor->setObjectName(QString::fromUtf8("lHighlightedColor"));
        lHighlightedColor->setWordWrap(false);

        graphicColGridLayout->addWidget(lHighlightedColor, 5, 0, 1, 1);

        cbHighlightedColor = new QComboBox(bgGraphicColors);
        cbHighlightedColor->addItem(QString::fromUtf8("#739373"));
        cbHighlightedColor->setObjectName(QString::fromUtf8("cbHighlightedColor"));
#if QT_CONFIG(accessibility)
        cbHighlightedColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbHighlightedColor->setEditable(true);

        graphicColGridLayout->addWidget(cbHighlightedColor, 5, 2, 1, 1);

        lMetaGridColor = new QLabel(bgGraphicColors);
        lMetaGridColor->setObjectName(QString::fromUtf8("lMetaGridColor"));
        lMetaGridColor->setWordWrap(false);

        graphicColGridLayout->addWidget(lMetaGridColor, 3, 0, 1, 1);

        cbSelectedColor = new QComboBox(bgGraphicColors);
        cbSelectedColor->addItem(QString::fromUtf8("#A54747"));
        cbSelectedColor->setObjectName(QString::fromUtf8("cbSelectedColor"));
#if QT_CONFIG(accessibility)
        cbSelectedColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbSelectedColor->setEditable(true);

        graphicColGridLayout->addWidget(cbSelectedColor, 4, 2, 1, 1);

        lSelectedColor = new QLabel(bgGraphicColors);
        lSelectedColor->setObjectName(QString::fromUtf8("lSelectedColor"));
        lSelectedColor->setWordWrap(false);

        graphicColGridLayout->addWidget(lSelectedColor, 4, 0, 1, 1);

        cbGridColor = new QComboBox(bgGraphicColors);
        cbGridColor->addItem(QString::fromUtf8("#736F6E"));
        cbGridColor->setObjectName(QString::fromUtf8("cbGridColor"));
#if QT_CONFIG(accessibility)
        cbGridColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbGridColor->setEditable(true);

        graphicColGridLayout->addWidget(cbGridColor, 2, 2, 1, 1);

        lStartHandleColor = new QLabel(bgGraphicColors);
        lStartHandleColor->setObjectName(QString::fromUtf8("lStartHandleColor"));

        graphicColGridLayout->addWidget(lStartHandleColor, 6, 0, 1, 1);

        lBackground = new QLabel(bgGraphicColors);
        lBackground->setObjectName(QString::fromUtf8("lBackground"));
        lBackground->setWordWrap(false);

        graphicColGridLayout->addWidget(lBackground, 1, 0, 1, 1);

        cbBackgroundColor = new QComboBox(bgGraphicColors);
        cbBackgroundColor->addItem(QString::fromUtf8("#000000"));
        cbBackgroundColor->addItem(QString::fromUtf8("#FFFFFF"));
        cbBackgroundColor->addItem(QString::fromUtf8("#F0F8FF"));
        cbBackgroundColor->setObjectName(QString::fromUtf8("cbBackgroundColor"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbBackgroundColor->sizePolicy().hasHeightForWidth());
        cbBackgroundColor->setSizePolicy(sizePolicy4);
#if QT_CONFIG(accessibility)
        cbBackgroundColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbBackgroundColor->setEditable(true);

        graphicColGridLayout->addWidget(cbBackgroundColor, 1, 2, 1, 1);

        cbMetaGridColor = new QComboBox(bgGraphicColors);
        cbMetaGridColor->addItem(QString::fromUtf8("#404040"));
        cbMetaGridColor->setObjectName(QString::fromUtf8("cbMetaGridColor"));
#if QT_CONFIG(accessibility)
        cbMetaGridColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbMetaGridColor->setEditable(true);

        graphicColGridLayout->addWidget(cbMetaGridColor, 3, 2, 1, 1);

        cbStartHandleColor = new QComboBox(bgGraphicColors);
        cbStartHandleColor->addItem(QString::fromUtf8("#00FFFF"));
        cbStartHandleColor->setObjectName(QString::fromUtf8("cbStartHandleColor"));
#if QT_CONFIG(accessibility)
        cbStartHandleColor->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cbStartHandleColor->setEditable(true);

        graphicColGridLayout->addWidget(cbStartHandleColor, 6, 2, 1, 1);

        label_2 = new QLabel(bgGraphicColors);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        graphicColGridLayout->addWidget(label_2, 7, 0, 1, 1);

        label_6 = new QLabel(bgGraphicColors);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        graphicColGridLayout->addWidget(label_6, 0, 0, 1, 1);

        cb_snap_color = new QComboBox(bgGraphicColors);
        cb_snap_color->addItem(QString::fromUtf8("#FFC200"));
        cb_snap_color->addItem(QString());
        cb_snap_color->setObjectName(QString::fromUtf8("cb_snap_color"));
#if QT_CONFIG(accessibility)
        cb_snap_color->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        cb_snap_color->setEditable(true);

        graphicColGridLayout->addWidget(cb_snap_color, 0, 2, 1, 1);

        pb_snap_color = new QPushButton(bgGraphicColors);
        pb_snap_color->setObjectName(QString::fromUtf8("pb_snap_color"));
        sizePolicy3.setHeightForWidth(pb_snap_color->sizePolicy().hasHeightForWidth());
        pb_snap_color->setSizePolicy(sizePolicy3);
        pb_snap_color->setIcon(icon);

        graphicColGridLayout->addWidget(pb_snap_color, 0, 3, 1, 1);


        gridLayout_3->addWidget(bgGraphicColors, 0, 1, 3, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        textLabel4 = new QLabel(tab_2);
        textLabel4->setObjectName(QString::fromUtf8("textLabel4"));
        textLabel4->setWordWrap(false);

        gridLayout->addWidget(textLabel4, 2, 0, 1, 1);

        lePathTranslations = new QLineEdit(tab_2);
        lePathTranslations->setObjectName(QString::fromUtf8("lePathTranslations"));

        gridLayout->addWidget(lePathTranslations, 0, 2, 1, 1);

        textLabel6 = new QLabel(tab_2);
        textLabel6->setObjectName(QString::fromUtf8("textLabel6"));
        textLabel6->setWordWrap(false);

        gridLayout->addWidget(textLabel6, 3, 0, 1, 1);

        lePathHatch = new QLineEdit(tab_2);
        lePathHatch->setObjectName(QString::fromUtf8("lePathHatch"));

        gridLayout->addWidget(lePathHatch, 1, 2, 1, 1);

        textLabel7 = new QLabel(tab_2);
        textLabel7->setObjectName(QString::fromUtf8("textLabel7"));
        textLabel7->setWordWrap(false);

        gridLayout->addWidget(textLabel7, 4, 0, 1, 1);

        leTemplate = new QLineEdit(tab_2);
        leTemplate->setObjectName(QString::fromUtf8("leTemplate"));

        gridLayout->addWidget(leTemplate, 4, 2, 1, 1);

        lePathLibrary = new QLineEdit(tab_2);
        lePathLibrary->setObjectName(QString::fromUtf8("lePathLibrary"));

        gridLayout->addWidget(lePathLibrary, 3, 2, 1, 1);

        lePathFonts = new QLineEdit(tab_2);
        lePathFonts->setObjectName(QString::fromUtf8("lePathFonts"));

        gridLayout->addWidget(lePathFonts, 2, 2, 1, 1);

        btTemplate = new QToolButton(tab_2);
        btTemplate->setObjectName(QString::fromUtf8("btTemplate"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btTemplate->setIcon(icon1);

        gridLayout->addWidget(btTemplate, 4, 3, 1, 1);

        spacer5_2 = new QSpacerItem(31, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer5_2, 6, 2, 1, 1);

        textLabel2 = new QLabel(tab_2);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        textLabel2->setWordWrap(false);

        gridLayout->addWidget(textLabel2, 0, 0, 1, 1);

        textLabel3 = new QLabel(tab_2);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        textLabel3->setWordWrap(false);

        gridLayout->addWidget(textLabel3, 1, 0, 1, 1);

        spacer5 = new QSpacerItem(31, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer5, 6, 0, 1, 1);

        variablefile_field = new QLineEdit(tab_2);
        variablefile_field->setObjectName(QString::fromUtf8("variablefile_field"));

        gridLayout->addWidget(variablefile_field, 5, 2, 1, 1);

        variablefile_button = new QToolButton(tab_2);
        variablefile_button->setObjectName(QString::fromUtf8("variablefile_button"));
        variablefile_button->setIcon(icon1);

        gridLayout->addWidget(variablefile_button, 5, 3, 1, 1);

        fonts_button = new QToolButton(tab_2);
        fonts_button->setObjectName(QString::fromUtf8("fonts_button"));
        fonts_button->setIcon(icon1);

        gridLayout->addWidget(fonts_button, 2, 3, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout1 = new QGridLayout(tab_3);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy5);
        groupBox->setMinimumSize(QSize(0, 70));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbAutoBackup = new QCheckBox(groupBox);
        cbAutoBackup->setObjectName(QString::fromUtf8("cbAutoBackup"));

        verticalLayout->addWidget(cbAutoBackup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbAutoSaveTime = new QSpinBox(groupBox);
        cbAutoSaveTime->setObjectName(QString::fromUtf8("cbAutoSaveTime"));
        cbAutoSaveTime->setMinimum(1);
        cbAutoSaveTime->setMaximum(60);

        horizontalLayout->addWidget(cbAutoSaveTime);


        verticalLayout->addLayout(horizontalLayout);

        cbUseQtFileOpenDialog = new QCheckBox(groupBox);
        cbUseQtFileOpenDialog->setObjectName(QString::fromUtf8("cbUseQtFileOpenDialog"));

        verticalLayout->addWidget(cbUseQtFileOpenDialog);

        cbWheelScrollInvertH = new QCheckBox(groupBox);
        cbWheelScrollInvertH->setObjectName(QString::fromUtf8("cbWheelScrollInvertH"));

        verticalLayout->addWidget(cbWheelScrollInvertH);

        cbWheelScrollInvertV = new QCheckBox(groupBox);
        cbWheelScrollInvertV->setObjectName(QString::fromUtf8("cbWheelScrollInvertV"));

        verticalLayout->addWidget(cbWheelScrollInvertV);

        cbInvertZoomDirection = new QCheckBox(groupBox);
        cbInvertZoomDirection->setObjectName(QString::fromUtf8("cbInvertZoomDirection"));

        verticalLayout->addWidget(cbInvertZoomDirection);


        gridLayout1->addWidget(groupBox, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(verticalSpacer, 3, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_clear_geometry = new QPushButton(groupBox_3);
        pb_clear_geometry->setObjectName(QString::fromUtf8("pb_clear_geometry"));
        sizePolicy3.setHeightForWidth(pb_clear_geometry->sizePolicy().hasHeightForWidth());
        pb_clear_geometry->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pb_clear_geometry);

        pb_clear_all = new QPushButton(groupBox_3);
        pb_clear_all->setObjectName(QString::fromUtf8("pb_clear_all"));
        sizePolicy3.setHeightForWidth(pb_clear_all->sizePolicy().hasHeightForWidth());
        pb_clear_all->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pb_clear_all);


        gridLayout1->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cbSplash = new QCheckBox(groupBox_2);
        cbSplash->setObjectName(QString::fromUtf8("cbSplash"));

        verticalLayout_2->addWidget(cbSplash);

        tab_mode_check_box = new QCheckBox(groupBox_2);
        tab_mode_check_box->setObjectName(QString::fromUtf8("tab_mode_check_box"));

        verticalLayout_2->addWidget(tab_mode_check_box);

        maximize_checkbox = new QCheckBox(groupBox_2);
        maximize_checkbox->setObjectName(QString::fromUtf8("maximize_checkbox"));

        verticalLayout_2->addWidget(maximize_checkbox);

        left_sidebar_checkbox = new QCheckBox(groupBox_2);
        left_sidebar_checkbox->setObjectName(QString::fromUtf8("left_sidebar_checkbox"));

        verticalLayout_2->addWidget(left_sidebar_checkbox);

        cad_toolbars_checkbox = new QCheckBox(groupBox_2);
        cad_toolbars_checkbox->setObjectName(QString::fromUtf8("cad_toolbars_checkbox"));

        verticalLayout_2->addWidget(cad_toolbars_checkbox);


        gridLayout1->addWidget(groupBox_2, 1, 1, 1, 1);

        buttonGroup5 = new QGroupBox(tab_3);
        buttonGroup5->setObjectName(QString::fromUtf8("buttonGroup5"));
        sizePolicy1.setHeightForWidth(buttonGroup5->sizePolicy().hasHeightForWidth());
        buttonGroup5->setSizePolicy(sizePolicy1);
        buttonGroup5->setMinimumSize(QSize(0, 70));
        hboxLayout = new QHBoxLayout(buttonGroup5);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lUnit = new QLabel(buttonGroup5);
        lUnit->setObjectName(QString::fromUtf8("lUnit"));
        sizePolicy5.setHeightForWidth(lUnit->sizePolicy().hasHeightForWidth());
        lUnit->setSizePolicy(sizePolicy5);
        lUnit->setWordWrap(false);

        hboxLayout->addWidget(lUnit);

        cbUnit = new QComboBox(buttonGroup5);
        cbUnit->setObjectName(QString::fromUtf8("cbUnit"));

        hboxLayout->addWidget(cbUnit);


        gridLayout1->addWidget(buttonGroup5, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cbEvaluateOnSpace = new QCheckBox(groupBox_4);
        cbEvaluateOnSpace->setObjectName(QString::fromUtf8("cbEvaluateOnSpace"));

        verticalLayout_3->addWidget(cbEvaluateOnSpace);

        cbToggleFreeSnapOnSpace = new QCheckBox(groupBox_4);
        cbToggleFreeSnapOnSpace->setObjectName(QString::fromUtf8("cbToggleFreeSnapOnSpace"));

        verticalLayout_3->addWidget(cbToggleFreeSnapOnSpace);


        gridLayout1->addWidget(groupBox_4, 2, 0, 1, 1);

        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        cbToActiveLayer = new QCheckBox(groupBox_5);
        cbToActiveLayer->setObjectName(QString::fromUtf8("cbToActiveLayer"));

        verticalLayout_4->addWidget(cbToActiveLayer);

        cbAutoZoomDrawing = new QCheckBox(groupBox_5);
        cbAutoZoomDrawing->setObjectName(QString::fromUtf8("cbAutoZoomDrawing"));

        verticalLayout_4->addWidget(cbAutoZoomDrawing);


        gridLayout1->addWidget(groupBox_5, 2, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        lLanguage->setBuddy(cbLanguage);
        lLanguageCmd->setBuddy(cbLanguageCmd);
        lMinGridSpacing->setBuddy(cbMaxPreview);
        lMaxPreview->setBuddy(cbMaxPreview);
        label_3->setBuddy(cbEndHandleColor);
        lGridColor->setBuddy(cbGridColor);
        lHighlightedColor->setBuddy(cbMetaGridColor);
        lMetaGridColor->setBuddy(cbMetaGridColor);
        lSelectedColor->setBuddy(cbMetaGridColor);
        lStartHandleColor->setBuddy(cbStartHandleColor);
        lBackground->setBuddy(cbBackgroundColor);
        label_2->setBuddy(cbHandleColor);
        label_6->setBuddy(cbEndHandleColor);
        lUnit->setBuddy(cbUnit);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(cbLanguage, cbLanguageCmd);
        QWidget::setTabOrder(cbLanguageCmd, indicator_lines_checkbox);
        QWidget::setTabOrder(indicator_lines_checkbox, cbMinGridSpacing);
        QWidget::setTabOrder(cbMinGridSpacing, cbMaxPreview);
        QWidget::setTabOrder(cbMaxPreview, cbBackgroundColor);
        QWidget::setTabOrder(cbBackgroundColor, cbGridColor);
        QWidget::setTabOrder(cbGridColor, cbMetaGridColor);
        QWidget::setTabOrder(cbMetaGridColor, cbSelectedColor);
        QWidget::setTabOrder(cbSelectedColor, cbHighlightedColor);
        QWidget::setTabOrder(cbHighlightedColor, cbStartHandleColor);
        QWidget::setTabOrder(cbStartHandleColor, cbHandleColor);
        QWidget::setTabOrder(cbHandleColor, cbEndHandleColor);
        QWidget::setTabOrder(cbEndHandleColor, buttonBox);
        QWidget::setTabOrder(buttonBox, lePathLibrary);
        QWidget::setTabOrder(lePathLibrary, cbUnit);
        QWidget::setTabOrder(cbUnit, lePathFonts);
        QWidget::setTabOrder(lePathFonts, leTemplate);
        QWidget::setTabOrder(leTemplate, btTemplate);
        QWidget::setTabOrder(btTemplate, cbAutoSaveTime);
        QWidget::setTabOrder(cbAutoSaveTime, lePathTranslations);
        QWidget::setTabOrder(lePathTranslations, lePathHatch);

        retranslateUi(QG_DlgOptionsGeneral);
        QObject::connect(buttonBox, SIGNAL(accepted()), QG_DlgOptionsGeneral, SLOT(ok()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QG_DlgOptionsGeneral, SLOT(reject()));
        QObject::connect(cbLanguageCmd, SIGNAL(activated(int)), QG_DlgOptionsGeneral, SLOT(setRestartNeeded()));
        QObject::connect(cbLanguage, SIGNAL(activated(int)), QG_DlgOptionsGeneral, SLOT(setRestartNeeded()));
        QObject::connect(btTemplate, SIGNAL(clicked()), QG_DlgOptionsGeneral, SLOT(setTemplateFile()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(QG_DlgOptionsGeneral);
    } // setupUi

    void retranslateUi(QDialog *QG_DlgOptionsGeneral)
    {
        QG_DlgOptionsGeneral->setWindowTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Application Preferences", nullptr));
        bgLanguage->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Language", nullptr));
        lLanguage->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&GUI Language:", nullptr));
        lLanguageCmd->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&Command Language:", nullptr));
        bgGraphicView->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Graphic View", nullptr));
        indicator_lines_checkbox->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Snap indicator lines", nullptr));
#if QT_CONFIG(shortcut)
        indicator_lines_checkbox->setShortcut(QCoreApplication::translate("QG_DlgOptionsGeneral", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)

        indicator_shape_checkbox->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Snap indicator shape", nullptr));

        cursor_hiding_checkbox->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Hide cursor when snapping", nullptr));
        cb_antialiasing->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Anti-aliasing", nullptr));
        scrollbars_check_box->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Scrollbars", nullptr));
        cbScaleGrid->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "A&utomatically scale grid", nullptr));
#if QT_CONFIG(shortcut)
        cbScaleGrid->setShortcut(QCoreApplication::translate("QG_DlgOptionsGeneral", "Alt+U", nullptr));
#endif // QT_CONFIG(shortcut)
        lMinGridSpacing->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Minimal Grid Spacing (p&x):", nullptr));

        lMaxPreview->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "N&umber of preview entities:", nullptr));

        bgGraphicColors->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Graphic Colors", nullptr));

        label_3->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&End Handle Color:", nullptr));
        lGridColor->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "G&rid Color:", nullptr));

        pb_background->setText(QString());
        pb_grid->setText(QString());
        pb_meta->setText(QString());
        pb_selected->setText(QString());
        pb_highlighted->setText(QString());
        pb_start->setText(QString());
        pb_handle->setText(QString());
        pb_end->setText(QString());
        lHighlightedColor->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&Highlighted Color:", nullptr));

        lMetaGridColor->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&Meta Grid Color:", nullptr));

        lSelectedColor->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "S&elected Color:", nullptr));

        lStartHandleColor->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "St&art Handle Color:", nullptr));
        lBackground->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Backgr&ound:", nullptr));



        label_2->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&Handle Color:", nullptr));
        label_6->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Snap indicator:", nullptr));
        cb_snap_color->setItemText(1, QCoreApplication::translate("QG_DlgOptionsGeneral", "#1E90FF", nullptr));

        pb_snap_color->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("QG_DlgOptionsGeneral", "&Appearance", nullptr));
        label_4->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Variable File:", nullptr));
        textLabel4->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Fonts:", nullptr));
        textLabel6->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Part Libraries:", nullptr));
        textLabel7->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Template:", nullptr));
        textLabel2->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Translations:", nullptr));
        textLabel3->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Hatch Patterns:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("QG_DlgOptionsGeneral", "&Paths", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Program Defaults", nullptr));
#if QT_CONFIG(tooltip)
        cbAutoBackup->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "When set, LibreCAD will automatically generate a backup of your current drawing.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAutoBackup->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Auto backup", nullptr));
        label->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Auto save time (minutes):", nullptr));
#if QT_CONFIG(tooltip)
        cbAutoSaveTime->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "Time between automatic saving of the document in minutes.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbUseQtFileOpenDialog->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Don't use native OS file open dialog", nullptr));
#if QT_CONFIG(tooltip)
        cbWheelScrollInvertH->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "Inverts scrolling direction when using mouse wheel with Shift key.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbWheelScrollInvertH->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Invert horizontal scrolling direction", nullptr));
#if QT_CONFIG(tooltip)
        cbWheelScrollInvertV->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "Inverts scrolling direction when using mouse wheel with Ctrl key.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbWheelScrollInvertV->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Invert vertical scrolling direction", nullptr));
#if QT_CONFIG(tooltip)
        cbInvertZoomDirection->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "Inverts zoom direction when using mouse wheel.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbInvertZoomDirection->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Invert zoom direction", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Clear Settings", nullptr));
#if QT_CONFIG(tooltip)
        pb_clear_geometry->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "restores program geometry/layout to original state", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_clear_geometry->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Layout", nullptr));
#if QT_CONFIG(tooltip)
        pb_clear_all->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "restores the program to its original state", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_clear_all->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "All", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Startup", nullptr));
        cbSplash->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Display loading screen", nullptr));
        tab_mode_check_box->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Start in tab mode", nullptr));
        maximize_checkbox->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Start with main window maximized", nullptr));
        left_sidebar_checkbox->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Enable CAD dockwidgets", nullptr));
        cad_toolbars_checkbox->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Enable CAD toolbars", nullptr));
        buttonGroup5->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Defaults for new drawings", nullptr));
        lUnit->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "&Unit:", nullptr));
#if QT_CONFIG(tooltip)
        cbUnit->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "Drawing unit.", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_4->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "Keyboard Settings", nullptr));
        cbEvaluateOnSpace->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Evaluate commands when SPACE BAR is pressed", nullptr));
#if QT_CONFIG(tooltip)
        cbToggleFreeSnapOnSpace->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "Toggle free snap mode when the SPACE BAR is pressed and the command window is empty", nullptr));
#endif // QT_CONFIG(tooltip)
        cbToggleFreeSnapOnSpace->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Toggle free snap mode when SPACE BAR is pressed", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("QG_DlgOptionsGeneral", "CAD Preferences", nullptr));
#if QT_CONFIG(tooltip)
        cbToActiveLayer->setToolTip(QCoreApplication::translate("QG_DlgOptionsGeneral", "<html><head/><body><p>When enabled, activating a layer would modify all selected entities to that new layer. To change layer of multiple entities: first select needed entities; activate a layer in the layer widget. This makes all selected entities modified to belong to the new layer.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbToActiveLayer->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Modify layer of selected entities, at  layer activation", nullptr));
        cbAutoZoomDrawing->setText(QCoreApplication::translate("QG_DlgOptionsGeneral", "Automatically zoom drawing when opening", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("QG_DlgOptionsGeneral", "&Defaults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QG_DlgOptionsGeneral: public Ui_QG_DlgOptionsGeneral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QG_DLGOPTIONSGENERAL_H
