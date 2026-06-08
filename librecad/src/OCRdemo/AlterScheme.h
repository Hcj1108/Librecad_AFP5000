#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_AlterScheme.h"

class AlterScheme : public QWidget
{
    Q_OBJECT

public:
    AlterScheme(QWidget *parent = nullptr);
    ~AlterScheme();

    bool BZJ = 0;
    bool IsAlter = false;

    QString SCHEME;
    int GapCount = 0;
    QString SerialNum;
    int DCLength = 0;
    double LocationScale = 0.5;
    int OutputLocationMax = 30;
    int OutputLocationMin = 30;
    int DelayTriggerMode = 0;
    int DelayTriggerTime = 1;
    int DelayTriggerDistance = 1;
    int DelayTriggerModetwo = 0;
    int DelayTriggerTimetwo = 1;
    int DelayTriggerDistancetwo = 1;
    int IntervalDistance = -1;
    int TriggerDis = 0;

    void SetQSS();
    void SetAlterScheme(QString _SCHEME, int _DCLength, int _GapCount,
                        double _LocationScale, int _OutputLocationMax, int _OutputLocationMin,
                        int _DelayTriggerMode, int _DelayTriggerModetwo,
                        int _DelayTriggerTime, int _DelayTriggerTimetwo,
                        int _DelayTriggerDistance, int _DelayTriggerDistancetwo);
    void AlterSchemeNameResult(bool result);
    QString GetSchemeName();

signals:
    void saveAlterScheme();
    void deleteScheme();
    void changeschemename();

private slots:
    void onCheckDCLength();
    void onCheckOutputLocationMax();
    void onCheckOutputLocationMin();
    void onCheckWarnDelayCount();
    void onCheckBZJ();
    void onCheckDelayTriggerDistance();
    void onCheckDelayTriggerDistancetwo();
    void onCheckDelayTriggerTime();
    void onCheckDelayTriggerTimetwo();
    void onSave();
    void onClose();
    void onDelete();

private:
    Ui::AlterSchemeClass ui;

    void showMsg(const QString& title, const QString& text, QMessageBox::Icon icon = QMessageBox::Critical);
    bool validateNotEmpty(QLineEdit* edit, const QString& fieldName);
    bool validateNumber(QLineEdit* edit, const QString& fieldName, int minVal = -1, int maxVal = -1);
    void setSavedIcon(QToolButton* btn);
    void setUnsavedIcon(QToolButton* btn);
};
