#ifndef FONT_SETTINGS_SINGLETON_H
#define FONT_SETTINGS_SINGLETON_H

#include <QVector>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include "rs_vector.h"  // 假设 RS_Vector 是自定义的向量类

/**
 * @brief 字体设置单例类
 *
 * 管理激光打标系统中的字体相关参数，提供全局唯一的字体设置访问点。
 * 包括字体尺寸、缩放、间距、占位符位置等。
 * 线程安全设计，支持多线程访问。
 */
class FontSettingsSingleton {
private:
    // 字体尺寸参数
    double m_fontWidth;         ///< 当前字体宽度（单位：像素或设备单位）
    int m_fontHeight;           ///< 字体高度（单位：像素）

    // 占位符位置参数
    RS_Vector m_placeholderPos; ///< 占位符坐标，用于动态文本打标位置
    bool m_hasPlaceholderPos;   ///< 标记是否有有效的占位符坐标

    // 线程安全控制
    mutable QMutex m_mutex;     ///< 互斥锁，确保线程安全访问

    // 字体间距和缩放参数
    double m_wordSpacing;       ///< 字间距/行间距因子
    double y_scale = 1.0;       ///< Y轴方向缩放因子，默认为1.0（不缩放）
    double x_scale = 1.0;       ///< X轴方向缩放因子，默认为1.0（不缩放）

    /**
     * @brief 私有构造函数
     * 单例模式，禁止外部创建实例
     */
    FontSettingsSingleton() : m_fontWidth(0.0) {}

    /**
     * @brief 析构函数
     */
    ~FontSettingsSingleton() = default;

    // 禁止拷贝构造和赋值操作
    FontSettingsSingleton(const FontSettingsSingleton&) = delete;
    FontSettingsSingleton& operator=(const FontSettingsSingleton&) = delete;

public:
    /**
     * @brief 获取单例实例
     * @return FontSettingsSingleton& 单例实例的引用
     */
    static FontSettingsSingleton& getInstance() {
        static FontSettingsSingleton instance;  // 线程安全的局部静态变量
        return instance;
    }

    // ================================
    // 字间距/行间距相关方法
    // ================================

    /**
     * @brief 获取字间距/行间距
     * @return double 字间距值
     */
    double getm_wordSpacing() const {
        QMutexLocker locker(&m_mutex);
        return m_wordSpacing;
    }

    /**
     * @brief 设置字间距/行间距
     * @param Linespace 新的字间距值
     */
    void setm_wordSpacing(double Linespace) {
        QMutexLocker locker(&m_mutex);
        m_wordSpacing = Linespace;
        qDebug() << "Font m_wordSpacing set to:" << Linespace;
    }

    // ================================
    // 缩放因子相关方法
    // ================================

    /**
     * @brief 获取Y轴缩放因子
     * @return double Y轴缩放因子
     */
    double gety_scale() const {
        QMutexLocker locker(&m_mutex);
        return y_scale;
    }

    /**
     * @brief 设置Y轴缩放因子
     * @param Linespace 新的Y轴缩放因子
     */
    void sety_scale(double Linespace) {
        QMutexLocker locker(&m_mutex);
        y_scale = Linespace;
        qDebug() << "Font y_scale set to:" << Linespace;
    }

    /**
     * @brief 获取X轴缩放因子
     * @return double X轴缩放因子
     */
    double getx_scale() const {
        QMutexLocker locker(&m_mutex);
        return x_scale;
    }

    /**
     * @brief 设置X轴缩放因子
     * @param Linespace 新的X轴缩放因子
     */
    void setx_scale(double Linespace) {
        QMutexLocker locker(&m_mutex);
        x_scale = Linespace;
        qDebug() << "Font x_scale set to:" << Linespace;
    }

    // ================================
    // 字体尺寸相关方法
    // ================================

    /**
     * @brief 获取字体宽度
     * @return double 字体宽度值
     */
    double getFontWidth() const {
        QMutexLocker locker(&m_mutex);
        return m_fontWidth;
    }

    /**
     * @brief 设置字体宽度
     * @param width 新的字体宽度
     */
    void setFontWidth(double width) {
        QMutexLocker locker(&m_mutex);
        m_fontWidth = width;
        qDebug() << "Font width set to:" << width;
    }

    /**
     * @brief 获取字体高度
     * @return int 字体高度值
     */
    int getFontHeight() const {
        QMutexLocker locker(&m_mutex);
        return m_fontHeight;
    }

    /**
     * @brief 设置字体高度
     * @param height 新的字体高度
     */
    void setFontHeight(int height) {
        QMutexLocker locker(&m_mutex);
        m_fontHeight = height;
        qDebug() << "Font height set to:" << height;
    }

    // ================================
    // 占位符位置相关方法
    // ================================

    /**
     * @brief 设置占位符坐标
     *
     * 用于存储动态文本（如时间、日期）的打标位置坐标
     *
     * @param pos 占位符坐标
     */
    void setPlaceholderPos(const RS_Vector& pos) {
        QMutexLocker locker(&m_mutex);
        m_placeholderPos = pos;
        m_hasPlaceholderPos = true;
        // qDebug() << "Placeholder position set to:" << pos;  // 调试输出可选
    }

    /**
     * @brief 获取占位符坐标
     *
     * 安全获取占位符坐标，如果坐标存在则返回true
     *
     * @param outPos 输出参数，用于接收坐标值
     * @return bool 如果坐标存在返回true，否则返回false
     */
    bool getPlaceholderPos(RS_Vector& outPos) const {
        QMutexLocker locker(&m_mutex);
        if (m_hasPlaceholderPos) {
            outPos = m_placeholderPos;
            return true;
        }
        return false;
    }

    /**
     * @brief 清除占位符坐标
     *
     * 将占位符坐标标记为无效
     */
    void clearPlaceholderPos() {
        QMutexLocker locker(&m_mutex);
        m_hasPlaceholderPos = false;
        qDebug() << "Placeholder position cleared";
    }

    /**
     * @brief 重置所有设置
     *
     * 将所有字体设置重置为默认值
     */
    void reset() {
        QMutexLocker locker(&m_mutex);
        m_fontWidth = 0.0;
        m_fontHeight = 0;
        m_hasPlaceholderPos = false;
        qDebug() << "All settings reset to default";
    }
};

#endif // FONT_SETTINGS_SINGLETON_H