#pragma once

#include <QWidget>
#include "ui_Jgadmin.h"
#include<QPainter>


/**
 * @brief 激光管理员配置界面类
 *
 * 负责激光打标系统的参数配置，包括编码器设置、触发参数、激光参数等
 */
class Jgadmin : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口指针
     */
    Jgadmin(QWidget* parent = nullptr);

    /**
     * @brief 析构函数
     */
    ~Jgadmin();

    //int currentIndex = 0;  ///< 当前索引值，用于界面导航或状态管理


   
    /**
     * @brief 设置界面样式表(QSS)
     */
    void SetQSS();

    /**
     * @brief 事件过滤器
     * @param obj 事件目标对象
     * @param evt 事件对象
     * @return 是否处理事件
     */
    bool eventFilter(QObject* obj, QEvent* evt);

    /**
     * @brief 设置激光参数
     *
     * @param BMQzhijing 编码器直径(单位: mm)
     * @param BMQmaichong 编码器周脉冲数(脉冲/周)
     * @param GdFilterTime 光电滤波时间(单位: ms)
     * @param MinThresholdMode 最小触发模式(0:禁用,1:时间,2:距离)
     * @param MinTriggerTime 最小触发时间(单位: ms)
     * @param MinTriggerDistance 最小触发距离(单位: mm)
     * @param DelayTriggerMode 延迟触发模式(0:禁用,1:时间,2:距离)
     * @param DelayTriggerTime 延迟触发时间(单位: ms)
     * @param DelayTriggerDistance 延迟触发距离(单位: mm)
     * @param DelayTriggerMode_2 二次延迟触发模式(0:禁用,1:时间,2:距离)
     * @param DelayTriggerTime_2 二次延迟触发时间(单位: ms)
     * @param DelayTriggerDistance_2 二次延迟触发距离(单位: mm)
     * @param Dbchoice 打标方式选择(0:连续,1:点打)
     * @param interpolationStep 插补步长(单位: mm)
     * @param scanW_mm 扫描宽度(单位: mm)
     * @param BMQdirection 编码器方向(0:正向,1:反向)
     * @param FXDBirection 方向选择(0:正向,1:反向)
     * @param Dbmode 打标模式(0:正常,1:镜像)
     * @param JgFreq 激光频率(单位: kHz)
     * @param JgPower 激光功率(单位: %)
     * @param KgDelay 开关延迟(单位: ms)
     * @param GgDelay 关光延迟(单位: ms)
     * @param firstJumpDelay 首次跳转延迟(单位: ms)
     * @param jumpDelay 跳转延迟(单位: ms)
     * @param endDelay 结束延迟(单位: ms)
     */
    void setJgadmin(int BMQzhijing, int BMQmaichong, int GdFilterTime,
        int MinThresholdMode, int MinTriggerTime, int MinTriggerDistance,
        int DelayTriggerMode, int DelayTriggerTime, int DelayTriggerDistance,
        int DelayTriggerMode_2, int DelayTriggerTime_2, int DelayTriggerDistance_2,
        int Dbchoice, int interpolationStep, int scanW_mm,
        int BMQdirection, int FXDBirection, int Dbmode,
        int JgFreq, int JgPower, int KgDelay, int GgDelay,
        int firstJumpDelay, int jumpDelay, int endDelay);

    /**
     * @brief 设置激光权限
     * @param PenMa 喷码权限(0:禁用,1:启用)
     * @param LiuShuixian 流水线权限(0:禁用,1:启用)
     * @param Chufa 触发权限(0:禁用,1:启用)
     */
    void setupLaserPermissions(int PenMa, int LiuShuixian, int Chufa);

    // 编码器参数获取函数
    int getBMQzhijing();        ///< 获取编码器直径(单位: mm)
    int getBMQmaichong();       ///< 获取编码器周脉冲数(脉冲/周)
    int getGdFilterTime();      ///< 获取光电滤波时间(单位: ms)

    // 触发参数获取函数
    int getMinThresholdMode();  ///< 获取最小触发模式(0:禁用,1:时间,2:距离)
    int getMinTriggerTime();    ///< 获取最小触发时间(单位: ms)
    int getMinTriggerDistance();///< 获取最小触发距离(单位: mm)

    // 延迟触发参数获取函数
    int getDelayTriggerMode();  ///< 获取延迟触发模式(0:禁用,1:时间,2:距离)
    int getDelayTriggerTime();  ///< 获取延迟触发时间(单位: ms)
    int getDelayTriggerDistance();///< 获取延迟触发距离(单位: mm)

    int getscanW_mm();          ///< 获取扫描宽度(单位: mm)
    int getBMQdirection();      ///< 获取编码器方向(0:正向,1:反向)
    int getFXDBirection();      ///< 获取方向选择(0:正向,1:反向)
    int getDbmode();            ///< 获取打标模式(0:正常,1:镜像)

    // 激光参数获取函数
    int getJgFreq();           ///< 获取激光频率(单位: kHz)
    int getJgPower();          ///< 获取激光功率(单位: %)
    int getKgDelay();          ///< 获取开关延迟(单位: ms)
    int getGgDelay();          ///< 获取关光延迟(单位: ms)
    int getFirstJumpDelay();   ///< 获取首次跳转延迟(单位: ms)
    int getEndDelay();         ///< 获取结束延迟(单位: ms)

private:
    Ui::JgadminClass ui;       ///< UI界面对象

signals:
    /**
     * @brief 显示主界面信号
     * 当需要返回主界面时发射此信号
     */
    void showmain();
};