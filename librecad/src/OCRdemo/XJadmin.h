#pragma once

#include <QMainWindow>
#include "ui_XJadmin.h"
#include<QPainter>

class XJadmin : public QMainWindow
{
	Q_OBJECT

public:
	XJadmin(QWidget *parent = nullptr);
	~XJadmin();

	

	void SetQSS();
	
	/**
 * @brief 事件过滤器
 * @param obj 事件目标对象
 * @param evt 事件对象
 * @return 是否处理事件
 */
	bool eventFilter(QObject* obj, QEvent* evt);
	// 获取RGB颜色参数
	int getR();						///< 获取红色分量值(0-255)
	int getG();						///< 获取绿色分量值(0-255)
	int getB();						///< 获取蓝色分量值(0-255)
	int getRGBTime();				///< 获取RGB颜色变化时间(单位: ms)
	int getRGBMode();				///< 获取RGB颜色模式(0: 静态, 1: 动态)

	// 获取触发和输出参数
	int getDCLength();				///< 获取触发长度(单位: mm)
	int getOutputLocationMin();		///< 获取触发下限冗余长度(单位: mm)
	int getOutputLocationMax();		///< 获取触发上限冗余长度(单位: mm)
	int getGapCount();				///< 获取报警间隔数(连续异常次数)
	int getKeepCount();				///< 获取报警保持数

	// 编码器参数获取函数
	int getBMQzhijing();        ///< 获取编码器直径(单位: mm)
	int getBMQmaichong();       ///< 获取编码器周脉冲数(脉冲/周)

	// 触发参数获取函数
	int getMinThresholdMode();  ///< 获取最小触发模式(0:禁用,1:时间,2:距离)
	int getMinTriggerTime();    ///< 获取最小触发时间(单位: ms)
	int getMinTriggerDistance();///< 获取最小触发距离(单位: mm)

	// 二次延迟触发参数获取函数
	int getDelayTriggerMode_2();///< 获取二次延迟触发模式(0:禁用,1:时间,2:距离)
	int getDelayTriggerTime_2();  ///< 获取二次延迟触发时间(单位: ms)
	int getDelayTriggerDistance_2();///< 获取二次延迟触发距离(单位: mm)

	void SetSetting(int BMQzhijing, int BMQmaichong, int GapCount, int DelayModel, int DelayTime, int DelayDistance, int DCLength, int OutputLocationMin, int OutputLocationMax, int KeepCount, int R, int G, int B, int RGBTime, int RGBMode, int MinThresholdMode, int MinTriggerTime, int MinTriggerDistance, int DelayTriggerMode_2, int DelayTriggerTime_2, int DelayTriggerDistance_2);
	
	void onColorButtonClicked();

private:
	Ui::XJadminClass ui;

signals:
	/**
	 * @brief 显示主界面信号
	 * 当需要返回主界面时发射此信号
	 */
	void showmain();
};


