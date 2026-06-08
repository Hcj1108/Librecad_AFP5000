#include "AddScheme.h"
#include <QMessageBox>
#include <QRegularExpression>

AddScheme::AddScheme(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    SetQSS();

    connect(ui.toolButton, &QPushButton::clicked, this, &AddScheme::onCheckSchemeName);
    connect(ui.toolButton_2, &QPushButton::clicked, this, &AddScheme::onCheckDCLength);
    connect(ui.toolButton_4, &QPushButton::clicked, this, &AddScheme::onCheckWarnDelayCount);
    connect(ui.toolButton_5, &QPushButton::clicked, this, &AddScheme::onCheckBZJ);
    connect(ui.toolButton_13, &QPushButton::clicked, this, &AddScheme::onCheckIntervalDistanceDM);
    connect(ui.toolButton_10, &QPushButton::clicked, this, &AddScheme::onCheckIntervalDistance);
    connect(ui.toolButton_12, &QPushButton::clicked, this, &AddScheme::onCheckIntervalTimeDM);
    connect(ui.toolButton_11, &QPushButton::clicked, this, &AddScheme::onCheckIntervalTime);
    connect(ui.toolButton_7, &QPushButton::clicked, this, &AddScheme::onCheckAll);
    connect(ui.pushButton_10, &QPushButton::clicked, this, &AddScheme::onCheckEnd);
    connect(ui.pushButton_9, &QPushButton::clicked, this, &AddScheme::hide);
    connect(ui.pushButton_8, &QPushButton::clicked, this, &AddScheme::onConfirmAdd);
    connect(ui.pushButton_11, &QPushButton::clicked, this, &AddScheme::onResetForm);

    // 输入变化时重置保存状态
    connect(ui.lineEdit, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton); });
    connect(ui.lineEdit_2, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_2); });
    connect(ui.lineEdit_4, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_4); });
    connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=] { setUnsavedIcon(ui.toolButton_5); });
    connect(ui.lineEdit_6, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_10); });
}

AddScheme::~AddScheme()
{}

// ─── 工具方法 ─────────────────────────────────────────────────

void AddScheme::showMsg(const QString& title, const QString& text, QMessageBox::Icon icon)
{
    QMessageBox msgBox(icon, title, text, QMessageBox::Ok, this);
    msgBox.button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定"));
    msgBox.exec();
}

bool AddScheme::validateNotEmpty(QLineEdit* edit, const QString& fieldName)
{
    if (edit->text().trimmed().isEmpty()) {
        showMsg(fieldName + QString::fromLocal8Bit("不能为空"), fieldName + QString::fromLocal8Bit("不能为空，请输入!"));
        return false;
    }
    return true;
}

bool AddScheme::validateNumber(QLineEdit* edit, const QString& fieldName, int minVal, int maxVal)
{
    if (!validateNotEmpty(edit, fieldName)) return false;

    QRegularExpression regex("^\\d+$");
    QRegularExpressionMatch match = regex.match(edit->text());
    if (!match.hasMatch()) {
        edit->clear();
        showMsg(fieldName + QString::fromLocal8Bit("格式错误"), fieldName + QString::fromLocal8Bit("必须为数字"));
        return false;
    }

    if (minVal >= 0 && maxVal >= 0) {
        int val = edit->text().toInt();
        if (val < minVal || val > maxVal) {
            edit->clear();
            showMsg(fieldName + QString::fromLocal8Bit("超出范围"), fieldName + QString::fromLocal8Bit("范围") + QString::number(minVal) + "-" + QString::number(maxVal) );
            return false;
        }
    }
    return true;
}

void AddScheme::setSavedIcon(QToolButton* btn)
{
    btn->setIcon(QIcon(":/PIC/Resources/PICs/endsave.png"));
}

void AddScheme::setUnsavedIcon(QToolButton* btn)
{
    btn->setIcon(QIcon(":/PIC/Resources/PICs/notsave.png"));
}

void AddScheme::enableNext(QWidget* widget, QToolButton* btn, bool enable)
{
    widget->setEnabled(enable);
    btn->setEnabled(enable);
}

// ─── 界面初始化 ───────────────────────────────────────────────

void AddScheme::SetQSS()
{
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    setWindowTitle(QString::fromLocal8Bit("新建配方"));
   
    // 红色星号标签
    for (QLabel* label : {ui.label_2, ui.label_4, ui.label_7, ui.label_8, ui.label_10,
                          ui.label_9, ui.label_12, ui.label_13, ui.label_16, ui.label_18,
                          ui.label_20, ui.label_23, ui.label_24, ui.label_26}) {
        label->setStyleSheet("color:red;");
    }

    // 初始化所有按钮为未保存状态
    for (QToolButton* btn : {ui.toolButton, ui.toolButton_2, ui.toolButton_4, ui.toolButton_5,
                             ui.toolButton_10, ui.toolButton_11, ui.toolButton_12, ui.toolButton_13,
                             ui.toolButton_7}) {
        btn->setIcon(QIcon(":/PIC/Resources/PICs/notsave.png"));
        btn->setIconSize(QSize(33, 33));
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    }
    ui.toolButton_7->setIconSize(QSize(33, 33));

    // 初始禁用
    enableNext(ui.lineEdit_2, ui.toolButton_2, false);
    enableNext(ui.lineEdit_4, ui.toolButton_4, false);
    ui.comboBox->setEnabled(false); ui.toolButton_5->setEnabled(false);
    enableNext(ui.lineEdit_6, ui.toolButton_10, false);
    ui.toolButton_11->setEnabled(false);
    ui.toolButton_12->setEnabled(false);
    ui.pushButton_8->setEnabled(false);
    ui.toolButton_7->setEnabled(false);
}


// ─── 分步校验 ─────────────────────────────────────────────────

void AddScheme::onCheckSchemeName()
{
    if (!validateNotEmpty(ui.lineEdit, QString::fromLocal8Bit("配方名"))) return;

    SCHEME = ui.lineEdit->text();
    CheckSchemeOverlap();
    if (!IsSchemeOK) {
        ui.lineEdit->clear();
        showMsg(QString::fromLocal8Bit("配方名重复"), QString::fromLocal8Bit("配方名已存在!"));
        return;
    }

    setSavedIcon(ui.toolButton);
    enableNext(ui.lineEdit_2, ui.toolButton_2, true);
}


void AddScheme::onCheckDCLength()
{
    if (!validateNumber(ui.lineEdit_2, QString::fromLocal8Bit("袋长"))) return;

    DCLength = ui.lineEdit_2->text().toInt();
    if (BZJ && DelayTriggerDistancetwo >= DCLength) {
        DelayTriggerDistancetwo = DCLength * 0.5;
        ui.lineEdit_6->setText(QString::number(DelayTriggerDistancetwo));
    }

    setSavedIcon(ui.toolButton_2);
    enableNext(ui.lineEdit_4, ui.toolButton_4, true);
}

void AddScheme::onCheckWarnDelayCount()
{
    if (!validateNumber(ui.lineEdit_4, QString::fromLocal8Bit("报警间隔数"), 1, 30)) return;

    GapCount = ui.lineEdit_4->text().toInt();
    setSavedIcon(ui.toolButton_4);
    ui.comboBox->setEnabled(true);
    ui.toolButton_5->setEnabled(true);
}

void AddScheme::onCheckBZJ()
{
    setSavedIcon(ui.toolButton_5);

    if (ui.comboBox->currentIndex()) {
        // 连续式
        BZJ = 1;
        DelayTriggerMode = 2;
        DelayTriggerModetwo = 2;
        ui.stackedWidget->setCurrentIndex(1);
        setUnsavedIcon(ui.toolButton_13);
        enableNext(ui.lineEdit_9, ui.toolButton_13, true);
        enableNext(ui.lineEdit_6, ui.toolButton_10, false);
        ui.toolButton_7->setEnabled(false);
    } else {
        // 间歇式
        BZJ = 0;
        DelayTriggerMode = 1;
        DelayTriggerModetwo = 1;
        ui.stackedWidget->setCurrentIndex(0);
        setUnsavedIcon(ui.toolButton_12);
        enableNext(ui.lineEdit_8, ui.toolButton_12, true);
        enableNext(ui.lineEdit_7, ui.toolButton_11, false);
        ui.toolButton_7->setEnabled(false);
    }
}

void AddScheme::onCheckIntervalDistanceDM()
{
    if (!validateNumber(ui.lineEdit_9, QString::fromLocal8Bit("打码延后距离"), 0, 9999)) return;

    DelayTriggerDistance = ui.lineEdit_9->text().toInt();
    setSavedIcon(ui.toolButton_13);
    enableNext(ui.lineEdit_6, ui.toolButton_10, true);
    setUnsavedIcon(ui.toolButton_10);
}

void AddScheme::onCheckIntervalDistance()
{
    if (!validateNumber(ui.lineEdit_6, QString::fromLocal8Bit("拍照延后距离"), 0, 9999)) return;

    DelayTriggerDistancetwo = ui.lineEdit_6->text().toInt();
    setSavedIcon(ui.toolButton_10);
    ui.toolButton_7->setEnabled(true);
    setUnsavedIcon(ui.toolButton_7);
}

void AddScheme::onCheckIntervalTimeDM()
{
    if (!validateNumber(ui.lineEdit_8, QString::fromLocal8Bit("打码延后时间"), 0, 9999)) return;

    DelayTriggerTime = ui.lineEdit_8->text().toInt();
    setSavedIcon(ui.toolButton_12);
    enableNext(ui.lineEdit_7, ui.toolButton_11, true);
    setUnsavedIcon(ui.toolButton_11);
}

void AddScheme::onCheckIntervalTime()
{
    if (!validateNumber(ui.lineEdit_7, QString::fromLocal8Bit("拍照延后时间"), 0, 9999)) return;

    DelayTriggerTimetwo = ui.lineEdit_7->text().toInt();
    setSavedIcon(ui.toolButton_11);
    ui.toolButton_7->setEnabled(true);
    setUnsavedIcon(ui.toolButton_7);
}

// ─── 核对与确认 ───────────────────────────────────────────────

void AddScheme::onCheckAll()
{
    ui.stackedWidget_2->setCurrentIndex(1);
    ui.label_9->setText(SCHEME);
    ui.label_12->setText(QString::number(DCLength));
    ui.label_16->setText(QString::number(GapCount));

    bool isContinuous = ui.comboBox->currentIndex() != 0;
    QString packType = isContinuous ? QString::fromLocal8Bit("连续式包装机") : QString::fromLocal8Bit("间歇式包装机");
    ui.label_18->setText(packType);

    if (isContinuous) {
        ui.label_25->setText(QString::fromLocal8Bit("连续式包装机\n打码延后距离："));
        ui.label_26->setText(QString::number(DelayTriggerDistance));
        ui.label_19->setText(QString::fromLocal8Bit("连续式包装机\n拍照延后距离："));
        ui.label_20->setText(QString::number(DelayTriggerDistancetwo));
    } else {
        ui.label_25->setText(QString::fromLocal8Bit("间歇式包装机\n打码延后时间："));
        ui.label_26->setText(QString::number(DelayTriggerTime));
        ui.label_19->setText(QString::fromLocal8Bit("间歇式包装机\n拍照延后时间："));
        ui.label_20->setText(QString::number(DelayTriggerTimetwo));
    }
}

void AddScheme::onCheckEnd()
{
    setSavedIcon(ui.toolButton_7);
    ui.pushButton_8->setEnabled(true);
}

void AddScheme::onConfirmAdd()
{
    CalSchemeParam();
}

// ─── 重置 ─────────────────────────────────────────────────────

void AddScheme::onResetForm()
{
    ui.stackedWidget_2->setCurrentIndex(0);
    setUnsavedIcon(ui.toolButton_7);
    ui.pushButton_8->setEnabled(false);
}

// ─── 参数设置 ─────────────────────────────────────────────────

void AddScheme::SetAddScheme(double locationScale)
{
    for (QToolButton* btn : {ui.toolButton, ui.toolButton_2, ui.toolButton_4, ui.toolButton_5,
                             ui.toolButton_10, ui.toolButton_11, ui.toolButton_12, ui.toolButton_13,
                             ui.toolButton_7}) {
        setUnsavedIcon(btn);
    }

    enableNext(ui.lineEdit_2, ui.toolButton_2, false);
    enableNext(ui.lineEdit_4, ui.toolButton_4, false);
    ui.comboBox->setEnabled(false); ui.toolButton_5->setEnabled(false);
    enableNext(ui.lineEdit_6, ui.toolButton_10, false);
    enableNext(ui.lineEdit_7, ui.toolButton_11, false);
    enableNext(ui.lineEdit_8, ui.toolButton_12, false);
    enableNext(ui.lineEdit_9, ui.toolButton_13, false);
    ui.pushButton_8->setEnabled(false);
    ui.toolButton_7->setEnabled(false);

    // 清空所有输入
    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_4->clear();
    ui.comboBox->setCurrentIndex(0);
    ui.lineEdit_6->clear();
    ui.lineEdit_7->clear();
    ui.lineEdit_8->clear();
    ui.lineEdit_9->clear();
    ui.label_9->clear();
    ui.label_12->clear();
    ui.label_16->clear();
    ui.label_18->clear();
    ui.label_20->clear();

    ui.stackedWidget_2->setCurrentIndex(0);
    ui.stackedWidget->setCurrentIndex(0);

    // 重置参数
    IsSchemeOK = true;
    BZJ = false;
    SCHEME = "";
    rectX = 100; rectY = 50; rectW = 250; rectH = 250;
    GapCount = 10;
    DCLength = 270;
    LocationScale = locationScale;
}

void AddScheme::CalSchemeParam()
{
    rectX = 100; rectY = 50; rectW = 250; rectH = 250;

    if (!BZJ) {
        DelayTriggerMode = 1;
        DelayTriggerModetwo = 1;
    }
    OutputLocationMin = LocationScale * DCLength;
    OutputLocationMax = LocationScale * DCLength;

    FinalAddScheme();
}
