#pragma once
//时间滚动条控件(封装)

#ifndef ROLLINGBOX_H
#define ROLLINGBOX_H

#include <QTimer>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include "rollingboxy.h"
#include "rollingboxm.h"
#include "rollingboxd.h"

class RollingBox : public QWidget
{
    Q_OBJECT

public:
    explicit RollingBox(QWidget* parent = 0);

    //    int readValue();                //获取当前值
    int readYear();
    int readMonth();
    int readDay();
    int m_currYear;
    int m_currMonth;
    int m_currDay;

public slots:
    void receiveValue();

private:
    QTimer* time;
    RollingBoxY* rby;
    RollingBoxM* rbm;
    RollingBoxD* rbd;

protected:
    int m_maxRange;                 //设置偏移量
    int maxValue();
};

#endif // ROLLINGBOX_H

