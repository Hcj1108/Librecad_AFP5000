#pragma once

#include <QWidget>
#include "ui_Jgadmin.h"

/**
 * @brief 激光参数配置结构体
 */
struct JgParam {
    // 喷码参数
    int power = 50;          // 激光功率(%)
    int freq = 30;           // 激光频率(kHz)
    int kgDelay = 2;         // 开光延时(ms)
    int ggDelay = 2;         // 关光延时(ms)
    int jumpDelay = 4;       // 跳转延时(ms)
    int endDelay = 2;        // 结束延时(ms)
    int gdFilterTime = 50;   // 光电滤波(ms)

    // 流水线设置
    int scanW_mm = 100;        // 飞行振镜幅面(mm)
    int bmqDirection = 0;      // 编码器方向(0:顺时针,1:逆时针)
    int fxdDirection = 0;      // 飞行轴方向(0:X轴,1:Y轴)
    int dbMode = 0;            // 飞行模式(0:静态,1:飞行)
    int bmqZhijing = 50;       // 编码器直径(mm)
    int bmqMaichong = 1000;    // 编码器脉冲数

    // 触发优化
    int minThresholdMode = 0;     // 最小触发模式
    int minTriggerTime = 50;      // 最小触发时间(ms)
    int minTriggerDistance = 50;  // 最小触发距离(mm)
    int delayTriggerMode = 0;     // 标刻延后触发模式
    int delayTriggerTime = 50;    // 标刻延后触发时间(ms)
    int delayTriggerDistance = 50;// 标刻延后触发距离(mm)
};

/**
 * @brief 激光管理员界面
 *
 * 负责激光系统参数配置：喷码参数、流水线设置、触发优化
 */
class Jgadmin : public QWidget
{
    Q_OBJECT

public:
    explicit Jgadmin(QWidget* parent = nullptr);
    ~Jgadmin() override;

    /// 设置所有参数（推荐方式）
    void setParams(const JgParam& params);

    /// 获取所有参数
    JgParam getParams() const;

    /// 设置激光权限
    void setupLaserPermissions(int penMa, int liuShuixian, int chuFa);

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::JgadminClass ui;

signals:
    void showmain();
};
