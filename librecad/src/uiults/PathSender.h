#pragma once

#include <QString>
#include <QVector>
#include <QPoint>
#include "rs_vector.h"

class RS_Document;
class RS_GraphicView;
class QWidget;

/**
 * @brief 路径点发送类
 *
 * 将当前文档中所有实体的路径点提取、优化并通过 UDP 发送到激光打标设备。
 * 同时处理 nomArray 寻址信息和时间占位符坐标。
 *
 * 使用方式：
 *   PathSender sender(document, graphicView, parentWidget);
 *   int result = sender.sendPathPoints();
 *
 * 返回值：
 *   1 = 成功
 *   0 = 无数据可发送
 *  -1 = 文档无效
 */
class PathSender
{
public:
    /// 构造函数
    /// @param doc   CAD 文档指针
    /// @param view  CAD 图形视图指针
    /// @param parent 父窗口（用于弹消息框）
    PathSender(RS_Document* doc, RS_GraphicView* view, QWidget* parent = nullptr);

    /// 执行路径点发送主流程
    int sendPathPoints();

private:
    /// 获取所有实体的路径点
    void collectPathPoints();

    /// 将路径点重新组织为两两一组
    void reorganizePaths();

    /// 发送路径点到设备
    int sendOptimizedPaths(const QString& ip, quint16 port, int startNom);

    /// 处理 BKBK 类型标志
    void handleBKBKType(int lastNom, const QString& ip);

    /// 发送 nomArray 寻址信息
    int sendNomInfo(int nom, const QString& ip);

    /// 发送时间占位符坐标
    void sendPlaceholderCoords(int nom, const QString& ip, int fontSize);

    RS_Document*    m_doc;
    RS_GraphicView* m_view;
    QWidget*        m_parent;

    /// 路径点数据
    QVector<QVector<QPoint>> m_optimizedPaths;

    /// 激光打标寻址
    int m_begin{ -1 };  ///< 静态部分起始地址
    int m_end{ -1 };    ///< 静态部分结束地址

    /// UDP 通信参数
    static const QString DEFAULT_IP;
    static const quint16 DEFAULT_PORT = 1234;
};
