#include "SerialNumberDialog.h"
#include "ui_SerialNumberDialog.h"

#include <QRegularExpressionValidator>

SerialNumberDialog::SerialNumberDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SerialNumberDialogClass)
{
    ui->setupUi(this);

    connect(ui->previewBtn, &QPushButton::clicked, this, &SerialNumberDialog::onPreview);
    connect(ui->resetBtn, &QPushButton::clicked, this, &SerialNumberDialog::onReset);
    connect(ui->okBtn, &QPushButton::clicked, this, &SerialNumberDialog::onAccept);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    // 实时预览：当任何参数改变时更新
    connect(ui->startNumSpb, QOverload<int>::of(&QSpinBox::valueChanged), this, &SerialNumberDialog::onPreview);
    connect(ui->currentNumSpb, QOverload<int>::of(&QSpinBox::valueChanged), this, &SerialNumberDialog::onPreview);
    connect(ui->endNumSpb, QOverload<int>::of(&QSpinBox::valueChanged), this, &SerialNumberDialog::onPreview);
    connect(ui->stepSpb, QOverload<int>::of(&QSpinBox::valueChanged), this, &SerialNumberDialog::onPreview);
    connect(ui->digitSpb, QOverload<int>::of(&QSpinBox::valueChanged), this, &SerialNumberDialog::onPreview);
    connect(ui->loopModeCbx, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SerialNumberDialog::onPreview);

    updatePreview();
}

SerialNumberDialog::~SerialNumberDialog()
{
    delete ui;
}

void SerialNumberDialog::updatePreview()
{
    m_currentNumber = ui->currentNumSpb->value();
    QString formatted = getFormattedNumber();
    ui->previewEdit->setText(formatted);
}

QString SerialNumberDialog::getFormattedNumber() const
{
    int digits = ui->digitSpb->value();
    return QString("%1").arg(m_currentNumber, digits, 10, QChar('0'));
}

void SerialNumberDialog::onPreview()
{
    updatePreview();
}

void SerialNumberDialog::onReset()
{
    int start = ui->startNumSpb->value();
    ui->currentNumSpb->setValue(start);
    m_currentNumber = start;
    updatePreview();
}

void SerialNumberDialog::onAccept()
{
    m_currentNumber = ui->currentNumSpb->value();
    accept();
}

int SerialNumberDialog::getCurrentNumber() const
{
    return m_currentNumber;
}

void SerialNumberDialog::setStartNumber(int n)
{
    ui->startNumSpb->setValue(n);
}

int SerialNumberDialog::getStartNumber() const
{
    return ui->startNumSpb->value();
}

void SerialNumberDialog::setCurrentNumber(int n)
{
    m_currentNumber = n;
    ui->currentNumSpb->setValue(n);
}

int SerialNumberDialog::getEndNumber() const
{
    return ui->endNumSpb->value();
}

void SerialNumberDialog::setEndNumber(int n)
{
    ui->endNumSpb->setValue(n);
}

void SerialNumberDialog::setStep(int s)
{
    ui->stepSpb->setValue(s);
}

int SerialNumberDialog::getStep() const
{
    return ui->stepSpb->value();
}

void SerialNumberDialog::setDigitCount(int d)
{
    ui->digitSpb->setValue(d);
}

int SerialNumberDialog::getDigitCount() const
{
    return ui->digitSpb->value();
}

int SerialNumberDialog::getLoopMode() const
{
    return ui->loopModeCbx->currentIndex();
}

int SerialNumberDialog::nextNumber()
{
    int step = ui->stepSpb->value();
    int end = ui->endNumSpb->value();
    int mode = ui->loopModeCbx->currentIndex();

    m_currentNumber += step;

    // 超过结束编号时的处理
    if (m_currentNumber > end) {
        if (mode == 0) {
            // 到结束停止
            m_currentNumber = end;
        } else if (mode == 1) {
            // 到结束归零重新开始
            m_currentNumber = ui->startNumSpb->value();
        } else {
            // 无限循环：不限制
        }
    }

    ui->currentNumSpb->setValue(m_currentNumber);
    updatePreview();

    QString formatted = getFormattedNumber();
    emit serialNumberChanged(formatted);
    return m_currentNumber;
}
