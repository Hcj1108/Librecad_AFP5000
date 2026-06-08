#pragma once
//时间滚动条-日期

#ifndef ROLLINGBOXD_H
#define ROLLINGBOXD_H

#include <QTimer>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QDateTime>
#include "rollingboxy.h"
#include "rollingboxm.h"

class RollingBoxD : public QWidget
{
    Q_OBJECT
        Q_PROPERTY(int deviation READ readDeviation WRITE setDeviation)

public:
    explicit RollingBoxD(QWidget* parent = 0);

    //    void setRange(int min,int max); //设置范围
    int readValue();                //获取当前值
    void setRange(int min, int max);                             //设置范围

public slots:
    //    void receiveValue();

private:
    int m_currYear;
    int m_currMonth;
    QTimer* time;
    RollingBoxY* rby;
    RollingBoxM* rbm;

protected:
    int m_minRange;
    int m_maxRange;
    int m_currentValue = QDateTime::currentDateTime().toString("dd").toInt();
    bool isDragging;
    int m_deviation;
    int m_mouseSrcPos;
    int m_numSize;//计算所得的数字字符尺寸，以最长的情况为准
    QPropertyAnimation* homingAni;

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    //    void wheelEvent(QWheelEvent *);

    void paintEvent(QPaintEvent*);
    void paintNum(QPainter& painter, int num, int deviation);     //绘制数字
    void homing();                                              //使选中的数字回到屏幕中间
    int readDeviation();                                        //获取鼠标移动偏移量，默认为0
    void setDeviation(int n);                                   //设置偏移量
    int maxValue();

signals:
    void currentValueChanged(int value);                        //当前数值改变信号
    void deviationChange(float deviation);                      //偏移量改变信号
};


#endif // ROLLINGBOXD_H

