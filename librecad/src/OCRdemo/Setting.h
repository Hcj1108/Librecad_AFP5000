#pragma once
#include <QMainWindow>
#include "ui_Setting.h"

class Setting : public QMainWindow
{
    Q_OBJECT

public:
    Setting(QWidget* parent = nullptr);
    ~Setting();

    // 配置参数
    QString schemeName;
    double ImageSize = 1.0;
    bool isfistopen = true;
    bool isOpenSetting = true;

    void SetQSS();
    void closeEvent(QCloseEvent* event) override; // 重写关闭事件
    //bool eventFilter(QObject* obj, QEvent* evt) override;
    void setbackground(const QImage& img);

    // 获取参数
    double getExposureTime();
    double getTriggerDelay();
    double getGainValue();
    int getRot();
    QString getSharpness();
    QRect mygetrect();

    void showResult(bool result, const QString& successMsg, const QString& failMsg);
    void alarmrect(bool result);
    void alarmexposuretime(bool result);
    void alarmGainValue(bool result);
    void alarmupdata(bool result);
    void updateDBresult(bool result);
    void insertDBresult(bool result);
    void alarmSharpness(bool result);

    void SetSetting(int ExposureTime, double rot, double GainValue, double Sharpness);

    // 参数微调
    void RaiseExposureTime();
    void ReduceExposureTime();
    void RaiseGainValue();
    void ReduceGainValue();

private:
    Ui::SettingClass ui;
    bool isautocap = false;

signals:
    void closeautocap();
    void showmain();
    void firstopen();
    void autocap();
    void getrect();
    void setExposureTime();
    void setGainValue();
    void setRot();
    void setCapAlarm();
    void setSharpness();
    void viewlog();
    void updatapsw();
    void caponepic();
};
