#include "SerialManager.h"
#include<QMouseEvent>
#include <QUuid>
#include <QTimer>
#include <windows.h>
#include <QWidget>
#include "ui_SerialManager.h"


#include <QDebug>
SerialManager::SerialManager(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	/*connect(ui.toolButton_21, &QToolButton::clicked, this, [=] {
		showmain();
		});*/
	connect(ui.checkBox, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.checkBox_2, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.checkBox_3, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.checkBox_4, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.checkBox_5, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.checkBox_6, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.checkBox_7, &QCheckBox::clicked, this, &SerialManager::setzhuangtai);
	connect(ui.btnClose, &QPushButton::clicked, this, [=] {
		this->hide();
		emit showmain();
	});
	SetQSS();
}

SerialManager::~SerialManager()
{
	
}

//设置页面样式
void SerialManager::SetQSS()
{
	
	setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
	// 设置窗体的初始大小
	
	qApp->installEventFilter(this);                   //给自己加事件过滤器,用来实现拖动窗口

	/*ui.toolButton_21->setIcon(QIcon("OCRdemo/Resources/PICs/GB.png"));
	ui.toolButton_21->setIconSize(QSize(71, 71));*/

	
}
void SerialManager::closeEvent(QCloseEvent* event)
{
	this->hide();
	emit showmain();
	event->ignore();
}

void SerialManager::setSerialNum(int MaxThresholdAlermOpen, int MinThresholdAlermOpen, int cameraAlarmOpen, int markingOutOfAreaOpen, int linkTXOpen, int linkBKBKOpen, int linkCameraOpen)
{
	ui.checkBox_4->setChecked(MaxThresholdAlermOpen);
	ui.checkBox_5->setChecked(MinThresholdAlermOpen);
	ui.checkBox_6->setChecked(cameraAlarmOpen);
	ui.checkBox_7->setChecked(markingOutOfAreaOpen);
	ui.checkBox->setChecked(linkCameraOpen);
	ui.checkBox_2->setChecked(linkBKBKOpen);
	ui.checkBox_3->setChecked(linkTXOpen);
		
}
int SerialManager::getSerialNum()
{
	int serialNum = 0;

	// 使用位移运算
	serialNum |= (ui.checkBox->isChecked() ? 1 : 0) << 2;   // 第2位
	serialNum |= (ui.checkBox_2->isChecked() ? 1 : 0) << 1; // 第1位
	serialNum |= (ui.checkBox_3->isChecked() ? 1 : 0) << 0; // 第0位
	qDebug() << "serialNum:" << serialNum;
	return serialNum;
}
int SerialManager::getSerialNum2()
{
	int serialNum = 0;

	// 使用位移运算
	serialNum |= (ui.checkBox_4->isChecked() ? 1 : 0) << 3;   // 第3位
	serialNum |= (ui.checkBox_5->isChecked() ? 1 : 0) << 2;   // 第2位
	serialNum |= (ui.checkBox_6->isChecked() ? 1 : 0) << 1; // 第1位
	serialNum |= (ui.checkBox_7->isChecked() ? 1 : 0) << 0; // 第0位
	qDebug() << "serialNum2:" << serialNum;
	return serialNum;
}
// 函数实现
void SerialManager::updateDeviceStatus(quint32 data)
{
	// 联机状态
	if (!ui.checkBox->isChecked()) {//相机联机
		ui.toolButton_14->setStyleSheet((data & 0x04) ?
			"background-color: rgb(0, 255, 0);" : "background-color: rgb(240, 0, 0);");
		ui.toolButton_14->setText((data & 0x04) ?
		QString::fromLocal8Bit("相机联机"): QString::fromLocal8Bit("相机未联机"));
	}
	else {
		ui.toolButton_14->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	if (!ui.checkBox_2->isChecked()) {//标刻联机
		ui.toolButton_15->setStyleSheet((data & 0x02) ?
			"background-color: rgb(0, 255, 0);" : "background-color: rgb(240, 0, 0);");
		ui.toolButton_15->setText((data & 0x04) ?
			QString::fromLocal8Bit("标刻联机") : QString::fromLocal8Bit("标刻未联机"));
	}
	else {
		ui.toolButton_15->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	if (!ui.checkBox_3->isChecked()) {//通讯联机
		ui.toolButton_16->setStyleSheet((data & 0x01) ?
			"background-color: rgb(0, 255, 0);" : "background-color: rgb(240, 0, 0);");
		ui.toolButton_16->setText((data & 0x04) ?
			QString::fromLocal8Bit("通讯联机") : QString::fromLocal8Bit("通讯未联机"));
	}
	else {
		ui.toolButton_16->setStyleSheet("background-color: rgb(240, 210, 75);");
	}
}

// 实现函数
void SerialManager::updateAlarmStatusUI(quint32 data, int markingOutOfAreaOpen,int cameraAlarmOpen,int MinThresholdAlermOpen,int MaxThresholdAlermOpen)
{
	// 标刻超范围报警
	if (!ui.checkBox_7->isChecked()) {
		ui.toolButton_13->setStyleSheet((data & 0x01) ?
			"background-color: rgb(255, 0, 0);" : "background-color: rgb(0, 255, 0);");
		ui.toolButton_13->setText((data & 0x01)?
			QString::fromLocal8Bit("标刻报警") : QString::fromLocal8Bit("标刻正常"));
	}
	else {
		ui.toolButton_13->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	// 相机报警
	if (!ui.checkBox_6->isChecked()) {
		ui.toolButton_12->setStyleSheet((data & 0x02) ?
			"background-color: rgb(255, 0, 0);" : "background-color: rgb(0, 255, 0);");
		ui.toolButton_12->setText((data & 0x02)?
			QString::fromLocal8Bit("相机报警") : QString::fromLocal8Bit("相机正常"));
	}
	else {
		ui.toolButton_12->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	// 最小阈值报警
	if (!ui.checkBox_5->isChecked()) {
		ui.toolButton_11->setStyleSheet((data & 0x04) ?
			"background-color: rgb(255, 0, 0);" : "background-color: rgb(0, 255, 0);");
		ui.toolButton_11->setText((data & 0x04) ?
			QString::fromLocal8Bit("下限报警") : QString::fromLocal8Bit("下限正常"));
	}
	else {
		ui.toolButton_11->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	// 最大阈值报警
	if (!ui.checkBox_4->isChecked()) {
		ui.toolButton_10->setStyleSheet((data & 0x08) ?
			"background-color: rgb(255, 0, 0);" : "background-color: rgb(0, 255, 0);");
		ui.toolButton_10->setText((data & 0x08)?
			QString::fromLocal8Bit("上限报警") : QString::fromLocal8Bit("上限正常"));
	}
	else {
		ui.toolButton_10->setStyleSheet("background-color: rgb(240, 210, 75);");
	}
}
// 实现函数
void SerialManager::updateAlarmStatusUI2()
{
	// 标刻超范围报警
	if (!ui.checkBox_7->isChecked()) {
		ui.toolButton_13->setStyleSheet("background-color: rgb(0, 255, 0);");
		ui.toolButton_13->setText(QString::fromLocal8Bit("标刻正常"));
	}
	else {
		ui.toolButton_13->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	// 相机报警
	if (!ui.checkBox_6->isChecked()) {
		ui.toolButton_12->setStyleSheet("background-color: rgb(0, 255, 0);");
		ui.toolButton_12->setText(QString::fromLocal8Bit("相机正常"));
	}
	else {
		ui.toolButton_12->setStyleSheet("background-color: rgb(240, 210, 75);");
	}

	// 最小阈值报警
	if (!ui.checkBox_5->isChecked()) {
		ui.toolButton_11->setStyleSheet("background-color: rgb(0, 255, 0);");
		ui.toolButton_11->setText(QString::fromLocal8Bit("下限正常"));
	}
	else {
		ui.toolButton_11->setStyleSheet("background-color: rgb(240, 210, 75);");
	}
	// 最大阈值报警
	if (!ui.checkBox_4->isChecked()) {
		ui.toolButton_10->setStyleSheet("background-color: rgb(0, 255, 0);");
		ui.toolButton_10->setText(QString::fromLocal8Bit("上限正常"));
	}
	else {
		ui.toolButton_10->setStyleSheet("background-color: rgb(240, 210, 75);");
	}
}