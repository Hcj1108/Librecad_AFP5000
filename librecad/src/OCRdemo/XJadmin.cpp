#include "XJadmin.h"
#include<QMouseEvent>
#include<QMessageBox>
#include<QTimer>
#include<QPushButton>
#include <QLineEdit>  // 必须包含的头文件
#include <QToolTip>  // 必须包含的头文件
#include <QUdpSocket>
#include <qendian.h>
#include <QColorDialog>

XJadmin::XJadmin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);        //设置阻塞类型

	connect(ui.MIN, &QPushButton::clicked, this, [=] {
		this->setWindowState(Qt::WindowMinimized);
		});

	connect(ui.BACK, &QPushButton::clicked, this, [=] {
		showmain();
		});
	connect(ui.toolButton, &QPushButton::clicked, this, &XJadmin::onColorButtonClicked);

	

	SetQSS();

}

XJadmin::~XJadmin()
{}



void XJadmin::SetQSS()
{
	// 在 XJadmin 的构造函数中调用
	
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	qApp->installEventFilter(this);                   //给自己加事件过滤器,用来实现拖动窗口
	this->setFixedSize(821, 421);
	
}
bool XJadmin::eventFilter(QObject* obj, QEvent* evt)
{
	QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(evt);
	if (obj == this && mouse)                 //判断拖动
	{
		if (this->isMaximized())
		{
			return true;
		}
		static bool dragFlag = false;
		static QPoint dragPoint(0, 0);
		if (mouse->button() == Qt::LeftButton && mouse->type() == QEvent::MouseButtonPress)    //按下
		{
			dragFlag = true;
			dragPoint = mouse->pos();                                  //记录鼠标所在的界面位置
			return true;
		}
		else if (dragFlag && mouse->type() == QEvent::MouseMove)     //拖动
		{
			this->move(mouse->globalPos() - dragPoint);
			return true;
		}
		else if (mouse->type() == QEvent::MouseButtonRelease)
		{
			dragFlag = false;
			return true;
		}
	}

	return QWidget::eventFilter(obj, evt);
}


int XJadmin::getR()
{
	return ui.spinBox->text().toInt();
}
int XJadmin::getG()
{
	return ui.spinBox_2->text().toInt();
}
int XJadmin::getB()
{
	return ui.spinBox_3->text().toInt();
}
int XJadmin::getRGBTime()
{
	return ui.spinBox_4->text().toInt();
}
int XJadmin::getRGBMode()
{
	//return ui.spinBox_5->text().toInt();
	return ui.comboBox_2->currentIndex();
}
int XJadmin::getDCLength()
{
	return ui.spinBox_6->text().toInt();
}
int XJadmin::getOutputLocationMin()
{
	return ui.spinBox_7->text().toInt();
}
int XJadmin::getOutputLocationMax()
{
	return ui.spinBox_8->text().toInt();
}
int XJadmin::getGapCount()
{
	return ui.spinBox_9->text().toInt();
}
int XJadmin::getKeepCount()
{
	return ui.spinBox_10->text().toInt();
}
int XJadmin::getBMQzhijing()
{
	return ui.spinBox_14->value();
}
int XJadmin::getBMQmaichong()
{
	return ui.spinBox_15->value();
}
int XJadmin::getMinThresholdMode()
{
	return ui.comboBox_4->currentIndex();
}
int XJadmin::getMinTriggerTime()
{
	return ui.spinBox_17->value();
}
int XJadmin::getMinTriggerDistance()
{
	return ui.spinBox_18->value();
}
int XJadmin::getDelayTriggerMode_2()
{
	return ui.comboBox_3->currentIndex();
}
int XJadmin::getDelayTriggerTime_2()
{
	return ui.spinBox_23->value();
}
int XJadmin::getDelayTriggerDistance_2()
{
	return ui.spinBox_24->value();
}


void XJadmin::SetSetting(int BMQzhijing, int BMQmaichong, int GapCount, int DelayModel, int DelayTime, int DelayDistance, int DCLength, int OutputLocationMin, int OutputLocationMax, int KeepCount, int R, int G, int B, int RGBTime, int RGBMode, int MinThresholdMode, int MinTriggerTime, int MinTriggerDistance, int DelayTriggerMode_2, int DelayTriggerTime_2, int DelayTriggerDistance_2)
{

	ui.spinBox->setValue(R);
	ui.spinBox_2->setValue(G);
	ui.spinBox_3->setValue(B);
	ui.spinBox_4->setValue(RGBTime);
	ui.comboBox_2->setCurrentIndex(RGBMode);

	ui.comboBox_4->setCurrentIndex(MinThresholdMode);//最小阈值模式
	ui.spinBox_17->setValue(MinTriggerTime);//最小触发时间
	ui.spinBox_18->setValue(MinTriggerDistance);//最小触发距离
	ui.comboBox_3->setCurrentIndex(DelayTriggerMode_2);//二次延迟触发模式
	ui.spinBox_23->setValue(DelayTriggerTime_2);//二次延迟触发时间
	ui.spinBox_24->setValue(DelayTriggerDistance_2);//二次延迟触发距离
	QColor color(R, G, B);
	if (color.isValid()) {
		// 示例：修改按钮背景色
		ui.toolButton->setStyleSheet(
			"background-color: " + color.name() + ";"
			"color: " + (color.lightness() > 128 ? "black" : "white") + ";" // 自动调整文字颜色
		);
	}
	ui.spinBox_6->setValue(DCLength);
	ui.spinBox_7->setValue(OutputLocationMin);
	ui.spinBox_8->setValue(OutputLocationMax);
	ui.spinBox_9->setValue(GapCount);
	ui.spinBox_10->setValue(KeepCount);
	ui.spinBox_14->setValue(BMQzhijing); //编码器直径
	ui.spinBox_15->setValue(BMQmaichong);//编码器脉冲
	
}

void XJadmin::onColorButtonClicked() {
	QColor color = QColorDialog::getColor(Qt::white, this, QString::fromLocal8Bit("选择颜色"));

	if (color.isValid()) {
		// 示例：修改按钮背景色
		ui.toolButton->setStyleSheet(
			"background-color: " + color.name() + ";"
			"color: " + (color.lightness() > 128 ? "black" : "white") + ";" // 自动调整文字颜色
		);

		ui.spinBox->setValue(color.red());
		ui.spinBox_2->setValue(color.green());
		ui.spinBox_3->setValue(color.blue());
		// 输出颜色信息
		qDebug() << "Hex:" << color.name()
			<< "RGB:" << color.red() << color.green() << color.blue()
			<< "Alpha:" << color.alpha();
	}
}