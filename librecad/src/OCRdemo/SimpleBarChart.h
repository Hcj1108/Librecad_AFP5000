// SimpleBarChart.h
#ifndef SIMPLEBARCHART_H
#define SIMPLEBARCHART_H


#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QMap>
class SimpleBarChart : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleBarChart(QWidget* parent = nullptr);

    // 添加或更新数据
    void setData(const QMap<QString, double>& data);
    void addData(const QString& label, double value);
    void clear();

    // 设置颜色
    void setBarColors(const QVector<QColor>& colors);

    // 获取数据
    QMap<QString, double> getData() const { return m_data; }

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QMap<QString, double> m_data;           // 标签 -> 数值
    QVector<QColor> m_colors;               // 颜色列表
    double m_maxValue;                      // 最大值

    void updateMaxValue();
    void drawBar(QPainter& painter, const QString& label,
        double value, const QColor& color,
        int startX, int y, int maxWidth, int height);
    void drawAdvancedBar(QPainter& painter, const QString& label,
        double value, const QColor& color,
        int startX, int y, int maxWidth, int height);
};

#endif // SIMPLEBARCHART_H