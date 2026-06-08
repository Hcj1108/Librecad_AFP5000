// SimpleBarChart.cpp
#include "SimpleBarChart.h"
#include <QDebug>
#include <QPainterPath>
 

SimpleBarChart::SimpleBarChart(QWidget *parent)
    : QWidget(parent)
    , m_maxValue(0)
{
    // 设置默认颜色（绿色和蓝色，与图片一致）
    m_colors << QColor(255, 0, 0)       // 红色 - NG
        << QColor(0, 255, 0)  // 浅绿色 - OK
        << QColor(48, 153, 248);  // 天蓝色 - unm
    // 设置背景为白色
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::white);
    setPalette(palette);
    
    // 设置图片中的初始数据
    addData("NG", 0);
    addData("OK", 0);
    addData(QString::fromLocal8Bit("总数"), 0);
}

void SimpleBarChart::setData(const QMap<QString, double> &data)
{
    m_data = data;
    updateMaxValue();
    update();
}

void SimpleBarChart::addData(const QString &label, double value)
{
    m_data[label] = value;
    if (value > m_maxValue) {
        m_maxValue = value;
    }
    update();
}

void SimpleBarChart::clear()
{
    m_data.clear();
    m_maxValue = 0;
    update();
}

void SimpleBarChart::setBarColors(const QVector<QColor> &colors)
{
    m_colors = colors;
    update();
}
void SimpleBarChart::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // 开启抗锯齿，这是绘制高质量图形的关键
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    int leftMargin = 50;   // 左侧留空给文字
    int topMargin = 10;
    int rightMargin = 10;
    int bottomMargin = 20;

    int barHeight = 25;    // 柱子高度
    int spacing = 10;      // 柱子间距（比柱子略高，显得透气）
   
    // 绘图区域尺寸
    int drawWidth = this->width() - leftMargin - rightMargin;
    int drawHeight = this->height() - topMargin - bottomMargin;

    if (drawWidth <= 0 || drawHeight <= 0 || m_data.isEmpty()) return;

  
    // --- 2. 绘制每个条形 ---
    int barIndex = 0;
    int totalBars = m_data.size();

    for (auto it = m_data.begin(); it != m_data.end(); ++it, ++barIndex) {
        // 计算当前条形的 Y 轴位置（居中分布）
        int totalHeightNeeded = totalBars * (barHeight + spacing) - spacing;
        int startY = (this->height() - totalHeightNeeded) / 2;
        int currentY = startY + barIndex * (barHeight + spacing);

        drawBar(painter, it.key(), it.value(),
            m_colors[barIndex % m_colors.size()],
            leftMargin, currentY, drawWidth, barHeight);
    }
}

void SimpleBarChart::drawBar(QPainter& painter, const QString& label,
    double value, const QColor& color,
    int startX, int y, int maxWidth, int height)
{
    // 1. 计算宽度
    double ratio = (m_maxValue > 0) ? (value / m_maxValue) : 0;
    int barWidth = static_cast<int>(ratio * maxWidth);

    // 如果值为0，至少画一个小点表示存在
    if (barWidth < 2) barWidth = 2;

    QRectF barRect(startX, y, barWidth, height);

    // 2. 创建渐变色 (模拟光照立体感)
    // 从上到下的渐变：亮色 -> 主色 -> 暗色
    QLinearGradient gradient(barRect.topLeft(), barRect.bottomLeft());

    // 让颜色亮一点，看起来像圆柱体受光面
    gradient.setColorAt(0.0, color.lighter(120));
    gradient.setColorAt(0.5, color);
    gradient.setColorAt(1.0, color.darker(110));

    // 3. 绘制阴影 (增加层次感)
    painter.save();
    painter.setBrush(QColor(0, 0, 0, 40)); // 半透明黑色阴影
    painter.setPen(Qt::NoPen);
    // 阴影向右下偏移 3px
    painter.drawRoundedRect(barRect.translated(3, 3), 4, 4);
    painter.restore();

    // 4. 绘制主体 (圆角矩形)
    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen); // 去掉边框，让渐变更自然
    painter.drawRoundedRect(barRect, 4, 4);

    // 5. 绘制高光条 (顶部边缘，增强立体感)
    painter.save();
    QLinearGradient highlight(barRect.topLeft(), barRect.bottomLeft());
    highlight.setColorAt(0.0, QColor(255, 255, 255, 150)); // 顶部半透明白
    highlight.setColorAt(0.4, QColor(255, 255, 255, 0));   // 往下渐变透明
    painter.setBrush(highlight);
    painter.drawRoundedRect(barRect, 4, 4);
    painter.restore();

    // 6. 绘制数值文本 (带描边，防止看不清)
    if (barWidth > 40) {
        painter.setPen(Qt::white);
        painter.setFont(QFont("Microsoft YaHei", 10, QFont::Bold));

        // 简单的文字描边效果 (先画黑色粗字，再画白色细字)
        QString valText = QString::number(value, 'f', 1);
        QRectF textRect = barRect.adjusted(0, 0, -10, 0); // 右边留空

        // 这里的逻辑是：文字显示在柱子内部靠右
        painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignRight, valText);
    }
    else {
        // 柱子太短，文字显示在柱子右侧外部
        painter.setPen(color.darker()); // 用深色文字
        painter.setFont(QFont("Microsoft YaHei", 9));
        QString valText = QString::number(value, 'f', 1);
        painter.drawText(barRect.right() + 10, y + height / 2 + 3, valText);
    }

    // 7. 绘制左侧标签
    if (!label.isEmpty()) {
        // 设置标签颜色为与条形相同颜色
        painter.setPen(color);
        painter.setFont(QFont("Microsoft YaHei", 11));
        QRectF labelRect(0, y, startX - 10, height);
        painter.drawText(labelRect, Qt::AlignVCenter | Qt::AlignRight, label);
    }
}
void SimpleBarChart::drawAdvancedBar(QPainter& painter, const QString& label,
    double value, const QColor& color,
    int startX, int y, int maxWidth, int height)
{
    // 1. 计算比例和宽度
    double ratio = (m_maxValue > 0) ? (value / m_maxValue) : 0;
    int barWidth = static_cast<int>(ratio * maxWidth);
    if (barWidth < 2) barWidth = 2; // 最小可见宽度

    QRectF barRect(startX, y, barWidth, height);

    // ==========================================
    // 2. 绘制左侧标签 (带颜色指示器)
    // ==========================================
    painter.save();
    painter.setPen(QColor(80, 80, 80));
    QFont labelFont("Microsoft YaHei", 10, QFont::Bold); // 加粗
    painter.setFont(labelFont);

    // 绘制一个小圆点作为图例
    painter.setBrush(color);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QPointF(startX - 15, y + height / 2), 4, 4);

    // 绘制文字
    QRectF labelRect(0, y, startX - 30, height);
    painter.setPen(QColor(60, 60, 60));
    painter.drawText(labelRect, Qt::AlignVCenter | Qt::AlignRight, label);
    painter.restore();

    // ==========================================
    // 3. 绘制主体 (拟物化胶囊效果)
    // ==========================================
    painter.save();

    // A. 绘制阴影 (柔和扩散)
    QPainterPath path;
    path.addRoundedRect(barRect, height / 2.0, height / 2.0); // 完全圆角

    // 投射阴影
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(0, 0, 0, 30)); // 淡淡的黑影
    painter.drawPath(path.translated(2, 3));

    // B. 绘制柱体 (径向渐变模拟光泽)
    // 这种渐变会让柱子看起来像圆柱体或者充气管
    QLinearGradient grad(barRect.topLeft(), barRect.bottomLeft());
    grad.setColorAt(0.0, color.lighter(115));   // 顶部高光
    grad.setColorAt(0.4, color);                // 中间本色
    grad.setColorAt(1.0, color.darker(105));    // 底部微暗
    painter.setBrush(grad);
    painter.drawPath(path);

    // C. 绘制高光条 (顶部反光)
    if (barWidth > 10) {
        QRectF highlightRect = barRect.adjusted(0, 2, 0, -height / 2); // 上半部分
        QPainterPath highlightPath;
        highlightPath.addRoundedRect(highlightRect, height / 2.0, height / 2.0);

        QLinearGradient hlGrad(highlightRect.topLeft(), highlightRect.bottomLeft());
        hlGrad.setColorAt(0.0, QColor(255, 255, 255, 180)); // 强白光
        hlGrad.setColorAt(1.0, QColor(255, 255, 255, 20));  // 渐隐

        painter.setBrush(hlGrad);
        painter.setCompositionMode(QPainter::CompositionMode_Overlay); // 叠加模式
        painter.drawPath(highlightPath);
    }
    painter.restore();

    // ==========================================
    // 4. 绘制右侧数值 (带百分比)
    // ==========================================
    painter.save();
    painter.setPen(QColor(100, 100, 100));
    QFont valFont("Arial", 9);
    painter.setFont(valFont);

    // 格式化文本：显示具体数值和百分比
    QString percentText = QString(" (%1%)").arg(ratio * 100, 0, 'f', 1);
    QString valText = QString::number(value, 'f', 0) + percentText;

    // 只有当柱子够长时才在内部显示，否则显示在外部
    if (barWidth > 80) {
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 9, QFont::Bold));
        // 内部显示
        QRectF textRect = barRect.adjusted(10, 0, -10, 0);
        painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignRight, valText);
    }
    else {
        // 外部显示
        painter.setPen(QColor(50, 50, 50));
        QPointF pos(startX + maxWidth + 10, y + height / 2 + 3);
        painter.drawText(pos, valText);
    }
    painter.restore();
}

void SimpleBarChart::updateMaxValue()
{
    m_maxValue = 0;
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        if (it.value() > m_maxValue) {
            m_maxValue = it.value();
        }
    }
    
    if (m_maxValue < 1.0) {
        m_maxValue = 1.0;
    }
}