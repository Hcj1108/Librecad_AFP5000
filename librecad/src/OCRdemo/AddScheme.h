#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_AddScheme.h"

class AddScheme : public QWidget
{
    Q_OBJECT

public:
    AddScheme(QWidget *parent = nullptr);
    ~AddScheme();

    // 配方参数
    bool IsSchemeOK = true;
    bool BZJ = 0;
    QString SCHEME;
    int rectX = 100;
    int rectY = 50;
    int rectW = 250;
    int rectH = 250;
    int GapCount = 10;
    int DCLength = 270;
    double LocationScale = 0.5;
    int OutputLocationMin = 0;
    int OutputLocationMax = 0;

    // 延迟触发参数
    int DelayTriggerMode = 0;
    int DelayTriggerTime = 1;
    int DelayTriggerDistance = 1;
    int DelayTriggerModetwo = 0;
    int DelayTriggerTimetwo = 1;
    int DelayTriggerDistancetwo = 1;

    void SetQSS();
    void SetAddScheme(double locationScale);
    void CalSchemeParam();

signals:
    void CheckSchemeOverlap();
    void FinalAddScheme();

private slots:
    void onCheckSchemeName();
    void onCheckDCLength();
    void onCheckWarnDelayCount();
    void onCheckBZJ();
    void onCheckIntervalDistanceDM();
    void onCheckIntervalDistance();
    void onCheckIntervalTimeDM();
    void onCheckIntervalTime();
    void onCheckAll();
    void onCheckEnd();
    void onResetForm();
    void onConfirmAdd();

private:
    Ui::AddSchemeClass ui;

    bool validateNotEmpty(QLineEdit* edit, const QString& fieldName);
    bool validateNumber(QLineEdit* edit, const QString& fieldName, int minVal = -1, int maxVal = -1);
    void showMsg(const QString& title, const QString& text, QMessageBox::Icon icon = QMessageBox::Critical);
    void setSavedIcon(QToolButton* btn);
    void setUnsavedIcon(QToolButton* btn);
    void enableNext(QWidget* widget, QToolButton* btn, bool enable);
};
