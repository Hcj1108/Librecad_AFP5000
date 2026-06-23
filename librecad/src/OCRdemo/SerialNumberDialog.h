#pragma once

#include <QDialog>
#include <QString>

namespace Ui {
class SerialNumberDialogClass;
}

class SerialNumberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialNumberDialog(QWidget* parent = nullptr);
    ~SerialNumberDialog();

    /// 获取当前编号（用于插入到文本中）
    int getCurrentNumber() const;
    QString getFormattedNumber() const;

    /// 设置/获取参数
    void setStartNumber(int n);
    int getStartNumber() const;
    void setCurrentNumber(int n);
    int getEndNumber() const;
    void setEndNumber(int n);
    void setStep(int s);
    int getStep() const;
    void setDigitCount(int d);
    int getDigitCount() const;
    int getLoopMode() const;

    /// 编号递增（每打一次调用）
    int nextNumber();

    /// 重置为起始编号
    void resetToStart();

signals:
    void serialNumberChanged(const QString& formatted);

private slots:
    void onPreview();
    void onReset();
    void onAccept();

private:
    void updatePreview();
    Ui::SerialNumberDialogClass* ui;
    int m_currentNumber{ 1 };
};
