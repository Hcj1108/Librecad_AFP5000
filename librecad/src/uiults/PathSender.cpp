#include "PathSender.h"
#include "rs_document.h"
#include "rs_graphicview.h"
#include "fileuilts.h"
#include "SingletonNomArray.h"
#include "FontSettingsSingleton.h"
#include "PlaceholderPositionManager.h"

#include <QMessageBox>
#include <QDebug>

const QString PathSender::DEFAULT_IP = "192.168.1.10";

PathSender::PathSender(RS_Document* doc, RS_GraphicView* view, QWidget* parent)
    : m_doc(doc)
    , m_view(view)
    , m_parent(parent)
{
}

int PathSender::sendPathPoints()
{
    if (!m_doc || !m_view) {
        if (m_parent) {
            QMessageBox::warning(m_parent,
                QString::fromLocal8Bit("警告"),
                QString::fromLocal8Bit("没有活动文档"));
        }
        return -1;
    }

    // 更新文档
    m_doc->update();

    // 收集并优化路径点
    collectPathPoints();
    reorganizePaths();

    qDebug() << "[PathSender] sending paths:" << m_optimizedPaths.size();

    // 如果没有路径点则返回
    if (m_optimizedPaths.isEmpty()) {
        QMessageBox::warning(m_parent,
            QString::fromLocal8Bit("警告"),
            QString::fromLocal8Bit("没有数据可发送!"));
        return 0;
    }

    SingletonNomArray& nomArray = SingletonNomArray::getInstance();
    QString ip = DEFAULT_IP;
    quint16 port = DEFAULT_PORT;

    // 起始编号
    int startNom = nomArray.getLastNom();
    m_begin = startNom;

    // 发送路径点到设备
    int lastNom = sendOptimizedPaths(ip, port, startNom);

    // 处理 BKBK 类型标志
    handleBKBKType(lastNom, ip);

    if (lastNom == startNom) {
        // 没有数据发送成功（理论上 handleBKBKType 已经处理了提示）
        return 0;
    }

    m_end = lastNom;

    // 发送 nomArray 寻址信息
    int nom = sendNomInfo(m_end, ip);
    if (nom < 0) return 0; // nomArray 为空已处理

    // 获取字体高度
    int fontSize = FontSettingsSingleton::getInstance().getFontHeight()
                 * FontSettingsSingleton::getInstance().gety_scale();

    // 发送时间占位符坐标
    sendPlaceholderCoords(nom, ip, fontSize);

    return 1;
}

// =====================================================================
// 私有方法
// =====================================================================

void PathSender::collectPathPoints()
{
    auto allPoints = m_doc->getAllEntityPathPoints(true);

    m_optimizedPaths.clear();
    for (const auto& entityPoints : allPoints) {
        QVector<QPoint> path;
        path.reserve(static_cast<int>(entityPoints.size()));
        for (const RS_Vector& point : entityPoints) {
            path.append(QPoint(static_cast<int>(point.x),
                               static_cast<int>(point.y)));
        }
        m_optimizedPaths.append(path);
    }
}

void PathSender::reorganizePaths()
{
    QVector<QVector<QPoint>> newOptimizedPaths;

    for (const auto& originalPath : m_optimizedPaths) {
        // 将原始路径中的点两两分组
        for (int j = 0; j + 1 < originalPath.size(); j += 2) {
            QVector<QPoint> newPath;
            newPath.append(originalPath[j]);
            newPath.append(originalPath[j + 1]);
            newOptimizedPaths.append(newPath);
        }

        // 如果点数是奇数，最后一个点单独成一条路径
        if (originalPath.size() % 2 == 1) {
            QVector<QPoint> singlePointPath;
            singlePointPath.append(originalPath.last());
            newOptimizedPaths.append(singlePointPath);
        }
    }

    m_optimizedPaths = newOptimizedPaths;
}

int PathSender::sendOptimizedPaths(const QString& ip, quint16 port, int startNom)
{
    return FileUtils::sendOptimizedPointsUDP_hex(m_optimizedPaths, ip, port, startNom);
}

void PathSender::handleBKBKType(int lastNom, const QString& ip)
{
    if (lastNom == m_begin) {
        // 没有路径点被发送，检查是否有动态时间占位符
        bool hasDynamicTime = false;
        const QVector<RS_Vector>& positions =
            PlaceholderPositionManager::getInstance().getPositions();
        if (!positions.isEmpty()) {
            hasDynamicTime = true;
            FileUtils::SendBKBK("10", "02", 2); // 仅动态时间
        }
        if (!hasDynamicTime) {
            QMessageBox::warning(m_parent,
                QString::fromLocal8Bit("警告"),
                QString::fromLocal8Bit("没有数据可发送!"));
        }
    } else {
        // 路径点已发送
        bool hasDynamicTime = false;
        const QVector<RS_Vector>& positions =
            PlaceholderPositionManager::getInstance().getPositions();
        if (!positions.isEmpty()) {
            hasDynamicTime = true;
            FileUtils::SendBKBK("10", "02", 3); // 静态 + 动态时间
        }
        if (!hasDynamicTime) {
            FileUtils::SendBKBK("10", "02", 1); // 仅静态
        }
    }
}

int PathSender::sendNomInfo(int nom, const QString& ip)
{
    SingletonNomArray& nomArray = SingletonNomArray::getInstance();

    QVector<int> myArray;
    try {
        myArray = nomArray.getNomArray();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(m_parent,
            QString::fromLocal8Bit("错误"),
            QString::fromLocal8Bit("获取数据时抛出异常: %1").arg(e.what()));
        return -1;
    }

    if (myArray.isEmpty()) {
        QMessageBox::warning(m_parent,
            QString::fromLocal8Bit("警告"),
            QString::fromLocal8Bit("没有任何数据"));
        return -1;
    }

    nom = FileUtils::sendquint256(myArray, ip, DEFAULT_PORT, nom);
    nom = FileUtils::sendquint256_static(m_begin, m_end - 1, ip, DEFAULT_PORT, nom);
    return nom;
}

void PathSender::sendPlaceholderCoords(int nom, const QString& ip, int fontSize)
{
    const QVector<RS_Vector>& positions =
        PlaceholderPositionManager::getInstance().getPositions();

    FileUtils::sendquint256_4(positions, ip, DEFAULT_PORT, nom, 8, fontSize);
}
