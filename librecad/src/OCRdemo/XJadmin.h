#pragma once

#include <QMainWindow>
#include "ui_XJadmin.h"

/**
 * @brief 相机检测参数配置结构体
 */
struct XjParam {
    // 光源设置
    int r = 255;
    int g = 255;
    int b = 255;
    int rgbTime = 100;
    int rgbMode = 0;       // 0:频闪, 1:常亮

    // 剔除设置
    int dcLength = 100;           // 袋长(mm)
    int outputLocationMin = 30;   // 下限(mm)
    int outputLocationMax = 30;   // 上限(mm)
    int gapCount = 7;             // 间隔(袋)
    int keepCount = 3;            // 连包(袋)
    int bmqZhijing = 50;         // 编码器直径(mm)
    int bmqMaichong = 1000;      // 编码器脉冲数

    // 触发设置
    int minThresholdMode = 0;     // 最小触发模式
    int minTriggerTime = 50;      // 最小触发时间(ms)
    int minTriggerDistance = 50;  // 最小触发距离(mm)
    int delayTriggerMode = 0;     // 拍照延后触发模式
    int delayTriggerTime = 50;    // 拍照延后触发时间(ms)
    int delayTriggerDistance = 50;// 拍照延后触发距离(mm)
};

/**
 * @brief 相机检测参数界面
 *
 * 负责相机参数配置：光源设置、剔除设置、触发设置
 */
class XJadmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit XJadmin(QWidget* parent = nullptr);
    ~XJadmin() override;

    /// 设置所有参数
    void setParams(const XjParam& params);

    /// 获取所有参数
    XjParam getParams() const;

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    void onColorButtonClicked();

    Ui::XJadminClass ui;

signals:
    void showmain();
};
