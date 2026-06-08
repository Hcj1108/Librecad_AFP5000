#pragma once
#include <QWidget>  
#include "ui_SerialManager.h" 

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QRegularExpression>
#include<QPainter>
#include <QPushButton>;

class SerialManager : public QWidget
{
	Q_OBJECT

public:
	SerialManager(QWidget* parent = nullptr);
	~SerialManager();
	//void paintEvent(QPaintEvent* event) override;
	void SetQSS();
	bool eventFilter(QObject* obj, QEvent* evt);//用于拖动设置页面
	int getSerialNum();
	int getSerialNum2();
	void setSerialNum(int MaxThresholdAlermOpen, int MinThresholdAlermOpen, int cameraAlarmOpen, int markingOutOfAreaOpen, int linkTXOpen, int linkBKBKOpen, int linkCameraOpen);
	void updateDeviceStatus(quint32 data);
	void updateAlarmStatusUI(quint32 data, int markingOutOfAreaOpen, int cameraAlarmOpen, int MinThresholdAlermOpen, int MaxThresholdAlermOpen);
	void updateAlarmStatusUI2();

private:
	Ui::SerialManagerClass ui;

signals:
	void showmain();
	void setzhuangtai();

};
