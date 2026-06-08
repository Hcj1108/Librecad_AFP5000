#pragma once
//时间滚动条-月份

#ifndef ROLLINGBOXM_H
#define ROLLINGBOXM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTimer>
#include <QDateTime>

class RollingBoxM : public QWidget
{
    Q_OBJECT
        Q_PROPERTY(int deviation READ readDeviation WRITE setDeviation)

public:
    explicit RollingBoxM(QWidget* parent = 0);

    void setRange(int min, int max); //设置范围

public slots:
    int readValue();                //获取当前值

private:
    QTimer* time;

protected:
    int m_minRange;
    int m_maxRange;
    int m_currentValueM = QDateTime::currentDateTime().toString("MM").toInt();
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
signals:
    void currentValueChanged(int value);                        //当前数值改变信号
    void deviationChange(float deviation);                      //偏移量改变信号
    int sendMonth(int);
};

#endif // ROLLINGBOXM_H

