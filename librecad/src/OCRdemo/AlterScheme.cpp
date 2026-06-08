#include "AlterScheme.h"
#include <QRegularExpression>

AlterScheme::AlterScheme(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    SetQSS();

    connect(ui.toolButton, &QPushButton::clicked, this, &AlterScheme::onCheckDCLength);
    connect(ui.toolButton_2, &QPushButton::clicked, this, &AlterScheme::onCheckOutputLocationMax);
    connect(ui.toolButton_9, &QPushButton::clicked, this, &AlterScheme::onCheckOutputLocationMin);
    connect(ui.toolButton_3, &QPushButton::clicked, this, &AlterScheme::onCheckWarnDelayCount);
    connect(ui.toolButton_6, &QPushButton::clicked, this, &AlterScheme::onCheckDelayTriggerDistance);
    connect(ui.toolButton_5, &QPushButton::clicked, this, &AlterScheme::onCheckDelayTriggerDistancetwo);
    connect(ui.toolButton_7, &QPushButton::clicked, this, &AlterScheme::onCheckDelayTriggerTime);
    connect(ui.toolButton_8, &QPushButton::clicked, this, &AlterScheme::onCheckDelayTriggerTimetwo);
    connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AlterScheme::onCheckBZJ);
    connect(ui.pushButton, &QPushButton::clicked, this, &AlterScheme::onSave);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &AlterScheme::onDelete);
    connect(ui.toolButton_4, &QPushButton::clicked, this, &AlterScheme::changeschemename);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &AlterScheme::onClose);

    // 输入变化时重置保存状态
    connect(ui.lineEdit, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton); });
    connect(ui.lineEdit_2, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_2); });
    connect(ui.lineEdit_5, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_9); });
    connect(ui.lineEdit_3, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_3); });
    connect(ui.lineEdit_7, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_6); });
    connect(ui.lineEdit_6, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_5); });
    connect(ui.lineEdit_8, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_7); });
    connect(ui.lineEdit_9, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_8); });
    connect(ui.lineEdit_4, &QLineEdit::textChanged, this, [=] { setUnsavedIcon(ui.toolButton_4); });
}

AlterScheme::~AlterScheme()
{}

// ─── 工具方法 ─────────────────────────────────────────────────

void AlterScheme::showMsg(const QString& title, const QString& text, QMessageBox::Icon icon)
{
    QMessageBox msgBox(icon, title, text, QMessageBox::Ok, this);
    msgBox.button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定"));
    msgBox.exec();
}

bool AlterScheme::validateNotEmpty(QLineEdit* edit, const QString& fieldName)
{
    if (edit->text().trimmed().isEmpty()) {
        showMsg(fieldName + QString::fromLocal8Bit("不能为空"), fieldName + QString::fromLocal8Bit("不能为空，请输入!"));
        return false;
    }
    return true;
}

bool AlterScheme::validateNumber(QLineEdit* edit, const QString& fieldName, int minVal, int maxVal)
{
    if (!validateNotEmpty(edit, fieldName)) return false;

    QRegularExpression regex("^\\d+$");
    QRegularExpressionMatch match = regex.match(edit->text());
    if (!match.hasMatch()) {
        edit->clear();
        showMsg(fieldName + QString::fromLocal8Bit("格式错误"), fieldName + QString::fromLocal8Bit("必须为数字!"));
        return false;
    }

    if (minVal >= 0 && maxVal >= 0) {
        int val = edit->text().toInt();
        if (val < minVal || val > maxVal) {
            edit->clear();
            showMsg(fieldName + QString::fromLocal8Bit("超出范围"), fieldName + QString::fromLocal8Bit("范围") + QString::number(minVal) + "-" + QString::number(maxVal));
            return false;
        }
    }
    return true;
}

void AlterScheme::setSavedIcon(QToolButton* btn)
{
    btn->setIcon(QIcon(":/PIC/Resources/PICs/endsave.png"));
}

void AlterScheme::setUnsavedIcon(QToolButton* btn)
{
    btn->setIcon(QIcon(":/PIC/Resources/PICs/notsave.png"));
}

// ─── 界面初始化 ───────────────────────────────────────────────

void AlterScheme::SetQSS()
{
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    setWindowTitle(QString::fromLocal8Bit("配方参数管理"));
  

    for (QToolButton* btn : {ui.toolButton, ui.toolButton_2, ui.toolButton_3, ui.toolButton_4,
                             ui.toolButton_5, ui.toolButton_6, ui.toolButton_7, ui.toolButton_8,
                             ui.toolButton_9}) {
        btn->setIcon(QIcon(":/PIC/Resources/PICs/notsave.png"));
        btn->setIconSize(QSize(33, 33));
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    }
}

// ─── 设置配方参数 ─────────────────────────────────────────────

void AlterScheme::SetAlterScheme(QString _SCHEME, int _DCLength, int _GapCount,
                                  double _LocationScale, int _OutputLocationMax, int _OutputLocationMin,
                                  int _DelayTriggerMode, int _DelayTriggerModetwo,
                                  int _DelayTriggerTime, int _DelayTriggerTimetwo,
                                  int _DelayTriggerDistance, int _DelayTriggerDistancetwo)
{
    SCHEME = _SCHEME;
    DCLength = _DCLength;
    GapCount = _GapCount;
    LocationScale = _LocationScale;
    OutputLocationMax = _OutputLocationMax;
    OutputLocationMin = _OutputLocationMin;
    DelayTriggerMode = _DelayTriggerMode;
    DelayTriggerTime = _DelayTriggerTime;
    DelayTriggerDistance = _DelayTriggerDistance;
    DelayTriggerModetwo = _DelayTriggerModetwo;
    DelayTriggerTimetwo = _DelayTriggerTimetwo;
    DelayTriggerDistancetwo = _DelayTriggerDistancetwo;

    ui.lineEdit_4->setText(SCHEME);
    ui.lineEdit->setText(QString::number(DCLength));
    ui.lineEdit_2->setText(QString::number(OutputLocationMax));
    ui.lineEdit_5->setText(QString::number(OutputLocationMin));
    ui.lineEdit_3->setText(QString::number(GapCount));

    if (DelayTriggerMode == 1) {
        // 间歇式
        ui.lineEdit_8->setText(QString::number(DelayTriggerTime));
        ui.lineEdit_9->setText(QString::number(DelayTriggerTimetwo));
        ui.lineEdit_6->clear();
        ui.lineEdit_7->clear();
        ui.stackedWidget->setCurrentIndex(0);
        ui.comboBox->setCurrentIndex(0);
        BZJ = 0;
        setSavedIcon(ui.toolButton_7);
        setSavedIcon(ui.toolButton_8);
        setUnsavedIcon(ui.toolButton_5);
        setUnsavedIcon(ui.toolButton_6);
    } else if (DelayTriggerMode == 2) {
        // 连续式
        ui.lineEdit_6->setText(QString::number(DelayTriggerDistancetwo));
        ui.lineEdit_7->setText(QString::number(DelayTriggerDistance));
        ui.lineEdit_8->clear();
        ui.lineEdit_9->clear();
        ui.stackedWidget->setCurrentIndex(1);
        ui.comboBox->setCurrentIndex(1);
        BZJ = 1;
        setSavedIcon(ui.toolButton_5);
        setSavedIcon(ui.toolButton_6);
        setUnsavedIcon(ui.toolButton_7);
        setUnsavedIcon(ui.toolButton_8);
    }

    for (QToolButton* btn : {ui.toolButton, ui.toolButton_2, ui.toolButton_3, ui.toolButton_4, ui.toolButton_9}) {
        setSavedIcon(btn);
    }
    IsAlter = false;
}

// ─── 校验函数 ─────────────────────────────────────────────────

void AlterScheme::onCheckDCLength()
{
    if (!validateNumber(ui.lineEdit, QString::fromLocal8Bit("袋长"))) return;
    DCLength = ui.lineEdit->text().toInt();
    setSavedIcon(ui.toolButton);
    IsAlter = true;
}

void AlterScheme::onCheckOutputLocationMax()
{
    if (!validateNumber(ui.lineEdit_2, QString::fromLocal8Bit("袋长上限"), 1, 9999)) return;
    OutputLocationMax = ui.lineEdit_2->text().toInt();
    setSavedIcon(ui.toolButton_2);
    IsAlter = true;
}

void AlterScheme::onCheckOutputLocationMin()
{
    if (!validateNumber(ui.lineEdit_5, QString::fromLocal8Bit("袋长下限"), 1, 9999)) return;
    OutputLocationMin = ui.lineEdit_5->text().toInt();
    setSavedIcon(ui.toolButton_9);
    IsAlter = true;
}

void AlterScheme::onCheckWarnDelayCount()
{
    if (!validateNumber(ui.lineEdit_3, QString::fromLocal8Bit("报警间隔数"), 1, 30)) return;
    GapCount = ui.lineEdit_3->text().toInt();
    setSavedIcon(ui.toolButton_3);
    IsAlter = true;
}

void AlterScheme::onCheckBZJ()
{
    if (ui.comboBox->currentIndex()) {
        BZJ = 1;
        DelayTriggerMode = 2;
        DelayTriggerModetwo = 2;
        ui.stackedWidget->setCurrentIndex(1);
    } else {
        BZJ = 0;
        DelayTriggerMode = 1;
        DelayTriggerModetwo = 1;
        ui.stackedWidget->setCurrentIndex(0);
    }
    IsAlter = true;
}

void AlterScheme::onCheckDelayTriggerDistance()
{
    if (!validateNumber(ui.lineEdit_7, QString::fromLocal8Bit("打码延后距离"), 1, 9999)) return;
    DelayTriggerDistance = ui.lineEdit_7->text().toInt();
    setSavedIcon(ui.toolButton_6);
    IsAlter = true;
}

void AlterScheme::onCheckDelayTriggerDistancetwo()
{
    if (!validateNumber(ui.lineEdit_6, QString::fromLocal8Bit("拍照延后距离"), 1, 9999)) return;
    DelayTriggerDistancetwo = ui.lineEdit_6->text().toInt();
    setSavedIcon(ui.toolButton_5);
    IsAlter = true;
}

void AlterScheme::onCheckDelayTriggerTime()
{
    if (!validateNumber(ui.lineEdit_8, QString::fromLocal8Bit("打码延后时间"), 1, 9999)) return;
    DelayTriggerTime = ui.lineEdit_8->text().toInt();
    setSavedIcon(ui.toolButton_7);
    IsAlter = true;
}

void AlterScheme::onCheckDelayTriggerTimetwo()
{
    if (!validateNumber(ui.lineEdit_9, QString::fromLocal8Bit("拍照延后时间"), 1, 9999)) return;
    DelayTriggerTimetwo = ui.lineEdit_9->text().toInt();
    setSavedIcon(ui.toolButton_8);
    IsAlter = true;
}

// ─── 操作按钮 ─────────────────────────────────────────────────

void AlterScheme::onSave()
{
    if (IsAlter) {
        saveAlterScheme();
        hide();
    } else {
        showMsg(QString::fromLocal8Bit("未修改参数"), QString::fromLocal8Bit("参数未修改，无需保存配方!"));
    }
}

void AlterScheme::onClose()
{
    if (IsAlter) {
        QMessageBox msgBox(QMessageBox::Question,
            QString::fromLocal8Bit("是否保存配方"),
            QString::fromLocal8Bit("是否保存修改数据？"),
            QMessageBox::NoButton, this);
        QAbstractButton* saveBtn = msgBox.addButton(QString::fromLocal8Bit("保存并返回"), QMessageBox::AcceptRole);
        QAbstractButton* returnBtn = msgBox.addButton(QString::fromLocal8Bit("直接返回"), QMessageBox::RejectRole);
        msgBox.exec();

        if (msgBox.clickedButton() == saveBtn) {
            saveAlterScheme();
            IsAlter = false;
        } else if (msgBox.clickedButton() == returnBtn) {
            IsAlter = false;
        }
    }
    hide();
}

void AlterScheme::onDelete()
{
    deleteScheme();
}

QString AlterScheme::GetSchemeName()
{
    return ui.lineEdit_4->text();
}

void AlterScheme::AlterSchemeNameResult(bool result)
{
    if (result) {
        setSavedIcon(ui.toolButton_4);
        showMsg(QString::fromLocal8Bit("修改成功"), QString::fromLocal8Bit("成功修改配方名!"), QMessageBox::Information);
    } else {
        showMsg(QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("存在重复的配方名!请重新修改!"));
    }
}
