
#include "Jgadmin.h"
#include<QMouseEvent>
#include<QMessageBox>
#include<QTimer>
#include <QLineEdit>  // 必须包含的头文件
#include<QDebug>

#include <QToolTip>  // 必须包含的头文件
#include <QUdpSocket>
#include <qendian.h>
#include<QPushButton>
//#include"OCRdemo/Config.h"

Jgadmin::Jgadmin(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.MIN, &QPushButton::clicked, this, [=] {
        this->setWindowState(Qt::WindowMinimized);
        });

    connect(ui.BACK, &QPushButton::clicked, this, [=] {

        showmain();
        });
   
    SetQSS();

}

Jgadmin::~Jgadmin()
{}


void Jgadmin::SetQSS()
{
    //setWindowFlags(Qt::WindowSystemMenuHint);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    qApp->installEventFilter(this);                   //给自己加事件过滤器,用来实现拖动窗口
    this->setFixedSize(821, 421);
}

bool Jgadmin::eventFilter(QObject* obj, QEvent* evt)
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


void Jgadmin::setJgadmin(int BMQzhijing, int BMQmaichong, int GdFilterTime, int MinThresholdMode, int MinTriggerTime, int MinTriggerDistance, int DelayTriggerMode, int DelayTriggerTime, int DelayTriggerDistance, int DelayTriggerMode_2, int DelayTriggerTime_2, int DelayTriggerDistance_2, int Dbchoice, int interpolationStep, int scanW_mm, int BMQdirection, int FXDBirection, int Dbmode, int JgFreq, int JgPower, int KgDelay, int GgDelay, int firstJumpDelay, int jumpDelay, int endDelay)
{
    
    ui.spinBox->setValue(JgPower);//激光功率
    ui.spinBox_2->setValue(JgFreq);//激光频率
    ui.spinBox_3->setValue(KgDelay); //开光延时
    ui.spinBox_4->setValue(GgDelay); //关光延时
    ui.spinBox_5->setValue(jumpDelay); //跳转延时
   
    ui.spinBox_7->setValue(endDelay); //结束延时
    ui.spinBox_8->setValue(GdFilterTime); //滤波时间
  
    ui.spinBox_10->setValue(scanW_mm);//扫描宽度
    ui.comboBox_4->setCurrentIndex(BMQdirection);//飞行编码器方向
    ui.comboBox_5->setCurrentIndex(FXDBirection);//飞行轴方向
    ui.comboBox_6->setCurrentIndex(Dbmode); //飞行模式开关
    ui.spinBox_14->setValue(BMQzhijing); //编码器直径
    ui.spinBox_15->setValue(BMQmaichong);//编码器脉冲
    // ui.lineEdit_15->setText(QString::number(cfg_read.interpolationStep));  //02插补步长

    ui.comboBox->setCurrentIndex(MinThresholdMode);//最小阈值模式
    ui.spinBox_17->setValue(MinTriggerTime);//最小触发时间
    ui.spinBox_18->setValue(MinTriggerDistance);//最小触发距离
    ui.comboBox_2->setCurrentIndex(DelayTriggerMode);//延迟触发模式
    ui.spinBox_20->setValue(DelayTriggerTime);//延迟触发时间
    ui.spinBox_21->setValue(DelayTriggerDistance);//延迟触发距离
  
  
  
   // ui.lineEdit_24->setText(QString::number(ButtonTriggerDirection));
        
}

void Jgadmin::setupLaserPermissions(int PenMa, int LiuShuixian, int Chufa)
{
    if (PenMa == 1) {
        ui.groupBox->setEnabled(true);
       
    }
    else {
        ui.groupBox->setEnabled(false);
      
    }
    if (LiuShuixian == 1) {
        ui.groupBox_2->setEnabled(true);
       
    }
    else {
        ui.groupBox_2->setEnabled(false);
       
    }
    if (Chufa == 1) {
        ui.groupBox_3->setEnabled(true);
       
    }
    else {
        ui.groupBox_3->setEnabled(false);
       
    }
}

int Jgadmin::getBMQzhijing()
{
    return ui.spinBox_14->value();
}
int Jgadmin::getBMQmaichong()
{
    return ui.spinBox_15->value();
}
int Jgadmin::getGdFilterTime()
{
    return ui.spinBox_8->value();
}
int Jgadmin::getMinThresholdMode()
{
    return ui.comboBox->currentIndex();
}
int Jgadmin::getMinTriggerTime()
{
    return ui.spinBox_17->value();
}
int Jgadmin::getMinTriggerDistance()
{
    return ui.spinBox_18->value();
}
int Jgadmin::getDelayTriggerMode()
{
    return ui.comboBox_2->currentIndex();
}
int Jgadmin::getDelayTriggerTime()
{
    return ui.spinBox_20->value();
}
int Jgadmin::getDelayTriggerDistance()
{
    return ui.spinBox_21->value();
}



int Jgadmin::getscanW_mm()
{
    return ui.spinBox_10->value();
}
int Jgadmin::getBMQdirection()
{
    return ui.comboBox_4->currentIndex();
}
int Jgadmin::getFXDBirection()
{
    return ui.comboBox_5->currentIndex();
}
int Jgadmin::getDbmode()
{
    return ui.comboBox_6->currentIndex();
}
int Jgadmin::getJgFreq()
{
    return ui.spinBox_2->value();
}
int Jgadmin::getJgPower()
{
    return ui.spinBox->value();
}
int Jgadmin::getKgDelay()
{
    return ui.spinBox_3->value();
}
int Jgadmin::getGgDelay()
{
    return ui.spinBox_4->value();
}
int Jgadmin::getFirstJumpDelay()
{
    return ui.spinBox_5->value();
}

int Jgadmin::getEndDelay()
{
    return ui.spinBox_7->value();
}
