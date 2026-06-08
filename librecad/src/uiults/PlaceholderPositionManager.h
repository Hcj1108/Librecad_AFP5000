#pragma once
#include <QVector>
#include "rs_vector.h" // 假设RS_Vector定义在这里


//单例类,存储变量字符的最终插入位置
class PlaceholderPositionManager {
public:
    static PlaceholderPositionManager& getInstance() {
        static PlaceholderPositionManager instance;
        return instance;
    }

    void setPositions(const QVector<RS_Vector>& positions) {
        m_positions = positions;
    }
    const QVector<RS_Vector>& getPositions() const {
        return m_positions;
    }
    void clear() { m_positions.clear(); }

private:
    PlaceholderPositionManager() = default;
    ~PlaceholderPositionManager() = default;
    PlaceholderPositionManager(const PlaceholderPositionManager&) = delete;
    PlaceholderPositionManager& operator=(const PlaceholderPositionManager&) = delete;

    QVector<RS_Vector> m_positions;
};
