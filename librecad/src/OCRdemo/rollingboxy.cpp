//时间滚动条-年份

#include "rollingboxy.h"
#include <QTimer>

RollingBoxY::RollingBoxY(QWidget* parent) :
    QWidget(parent),
    m_minRange(1950),         //最小值
    m_maxRange(2050),         //最大值
    //    m_currentValueY(2020),      //当前选中的值
    isDragging(0),          //鼠标是否按下
    m_deviation(0),         //偏移量，记录鼠标按下后移动的垂直距离
    m_numSize(6)            //计算所得的数字字符尺寸，以最长的情况为准
{
    this->setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
    this->setStyleSheet("background:white;");
    homingAni = new QPropertyAnimation(this, "deviation");      //一个控制动画效果的类
    homingAni->setDuration(300);                                //设置动画持续时间
    homingAni->setEasingCurve(QEasingCurve::OutQuad);           //设置动画的缓动曲线，这里OutQuad是二次函数缓和曲线，减速到零
}

//设置范围
void RollingBoxY::setRange(int min, int max)
{
    m_minRange = min;
    m_maxRange = max;

    if (m_currentValueY < min)        //如果选中的当前值小于最小值，就等于最小值
        m_currentValueY = min;
    if (m_currentValueY > max)        //最大值同理
        m_currentValueY = max;

    //计算字符尺寸
    m_numSize = 3;
    int temp = m_maxRange;
    while (temp > 0)
    {
        temp /= 10;
        m_numSize++;
    }

    repaint();      //重绘此组件，需要进行重绘时，要使用repaint
}

//获取当前值
int RollingBoxY::readValue()
{
    return m_currentValueY;
}

//鼠标按下事件
void RollingBoxY::mousePressEvent(QMouseEvent* e)
{
    homingAni->stop();      //动画停止
    isDragging = 1;         //鼠标是否按下的标志位，布尔类型
    m_mouseSrcPos = e->pos().y();   //鼠标按下时候的y轴坐标记录下来
}

//鼠标移动事件
void RollingBoxY::mouseMoveEvent(QMouseEvent* e)
{
    if (isDragging)
    {
        //数值到边界时，阻止继续往对应方向移动
        if ((m_currentValueY == m_minRange && e->pos().y() >= m_mouseSrcPos) ||
            (m_currentValueY == m_maxRange && e->pos().y() <= m_mouseSrcPos))
            return;

        m_deviation = e->pos().y() - m_mouseSrcPos;     //垂直偏移量 = 现在的坐标 - 开始的坐标

        //若移动速度过快时进行限制
        if (m_deviation > (height() - 1) / 4)
            m_deviation = (height() - 1) / 4;
        else if (m_deviation < -(height() - 1) / 4)
            m_deviation = -(height() - 1) / 4;

        emit deviationChange((float)m_deviation / ((height() - 1) / 5));      //发出偏移量改变的信号，随着偏移量改变，重绘数字，就变成了数字滚动的效果

        repaint();
    }
}

//鼠标松开事件
void RollingBoxY::mouseReleaseEvent(QMouseEvent*)
{
    if (isDragging)      //如果鼠标松开了，那么还原鼠标按下标志位
    {
        isDragging = 0;
        homing();       //使选中的数字回到屏幕中间
    }
}

//void RollingBoxM::wheelEvent(QWheelEvent *e)
//{
//    if(e->delta()>0)
//    {
//        m_deviation = (this->height() -1)/4;
//    }
//    else{
//        m_deviation = -(this->height() -1)/4;
//    }
//    homing();
//    repaint();
//}

//绘图事件
void RollingBoxY::paintEvent(QPaintEvent*)
{
    QPainter painter(this);     //创建画家类，指定绘图设备
    painter.setRenderHint(QPainter::Antialiasing, true);    //抗锯齿

    int Width = width() - 1;
    int Height = height() - 1;

    if (m_deviation >= Height / 4 && m_currentValueY > m_minRange)  //偏移量大于1/4的时候，数字减一
    {
        m_mouseSrcPos += Height / 4;  //鼠标起始位置重新设置，即加上1/4的高度
        m_deviation -= Height / 4;    //偏移量重新设置，即减去1/4的高度
        m_currentValueY -= 1;
    }
    if (m_deviation <= -Height / 4 && m_currentValueY < m_maxRange) //同理，数字加一
    {
        m_mouseSrcPos -= Height / 4;
        m_deviation += Height / 4;
        m_currentValueY += 1;
    }

    //中间数字
    paintNum(painter, m_currentValueY, m_deviation);   //将选中数字画到中间

    //两侧数字1
    if (m_currentValueY != m_minRange)    //选中的数字不是最小，不是最大，那么就有两侧数字，然后画出两侧数字
        paintNum(painter, m_currentValueY - 1, m_deviation - Height / 4);
    if (m_currentValueY != m_maxRange)
        paintNum(painter, m_currentValueY + 1, m_deviation + Height / 4);

    //两侧数字2,超出则不显示
    if (m_deviation >= 0 && m_currentValueY - 2 >= m_minRange)
        paintNum(painter, m_currentValueY - 2, m_deviation - Height / 2);
    if (m_deviation <= 0 && m_currentValueY + 2 <= m_maxRange)
        paintNum(painter, m_currentValueY + 2, m_deviation + Height / 2);

    //中间数字两侧的边框
    painter.setPen(QPen(QColor(70, 144, 249), 2));
    painter.drawLine(0, Height / 8 * 3, Width, Height / 8 * 3);
    painter.drawLine(0, Height / 8 * 5, Width, Height / 8 * 5);
}

//画数字
void RollingBoxY::paintNum(QPainter& painter, int num, int deviation)
{
    int Width = this->width() - 1;
    int Height = this->height() - 1;

    int size = (Height - qAbs(deviation)) / m_numSize;        //qAbs 返回输入参数对应类型的绝对值
    int transparency = 255 - 510 * qAbs(deviation) / Height;      //设置透明度
    int height = Height / 2 - 3 * qAbs(deviation) / 5;
    int y = Height / 2 + deviation - height / 2;

    QFont font;
    font.setPixelSize(size);    //设置像素大小
    painter.setFont(font);      //设置字体
    painter.setPen(QColor(0, 0, 0, transparency));     //设置画笔
    painter.drawText(QRectF(0, y, Width, height),      //画文本，参数：QRectF参数：位置xy，长宽大小；对齐方式，居中对齐；内容
        Qt::AlignCenter,
        (QString::number(num) + QString::fromLocal8Bit("年 ")));
}

void RollingBoxY::homing()
{
    //将数字矫正到中心
    if (m_deviation > height() / 8)
    {
        homingAni->setStartValue((height() - 1) / 8 - m_deviation);
        homingAni->setEndValue(0);
        m_currentValueY--;
    }
    else if (m_deviation > -height() / 8)
    {
        homingAni->setStartValue(m_deviation);
        homingAni->setEndValue(0);
    }
    else if (m_deviation < -height() / 8)
    {
        homingAni->setStartValue(-(height() - 1) / 8 - m_deviation);
        homingAni->setEndValue(0);
        m_currentValueY++;
    }
    emit currentValueChanged(m_currentValueY);   //发送当前数值改变信号
    homingAni->start();     //开始动画
}

//获取鼠标移动偏移量
int RollingBoxY::readDeviation()
{
    return m_deviation;
}

//设置偏移量
void RollingBoxY::setDeviation(int n)
{
    m_deviation = n;
    repaint();
}

