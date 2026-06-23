#pragma once
#include <QWidget>  
#include "ui_SerialManager.h" 

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QRegularExpression>
#include <QPainter>
#include <QPushButton>;
#include <QMessageBox>;

#include "fileuilts.h"              // 文件工具类，处理文件操作

class SerialManager : public QWidget
{
	Q_OBJECT

public:
	bool Serial_IsOpenBKBK = false;
	bool Serial_isOpenCam = false;

	SerialManager(QWidget* parent = nullptr);
	~SerialManager();
	//void paintEvent(QPaintEvent* event) override;
	void SetQSS();
	void closeEvent(QCloseEvent* event);
	
	int getSerialNum();
	int getSerialNum2();
	void setSerialNum(int MaxThresholdAlermOpen, int MinThresholdAlermOpen, int cameraAlarmOpen, int markingOutOfAreaOpen, int linkTXOpen, int linkBKBKOpen, int linkCameraOpen, bool IsOpenBKBK, bool isOpenCam);
	void updateDeviceStatus(quint32 data);
	void updateAlarmStatusUI(quint32 data, int markingOutOfAreaOpen, int cameraAlarmOpen, int MinThresholdAlermOpen, int MaxThresholdAlermOpen);
	void updateAlarmStatusUI2();

private:
	Ui::SerialManagerClass ui;

signals:
	void showmain();
	void setzhuangtai();
	void SendNG();


};
