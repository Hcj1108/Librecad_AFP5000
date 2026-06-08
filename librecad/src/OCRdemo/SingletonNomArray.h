#ifndef SINGLETON_NOMARRAY_H
#define SINGLETON_NOMARRAY_H

#include <QVector>
#include <QDebug>

class SingletonNomArray {
private:
    QVector<int> m_nomArray;  // 私有成员变量

    // 私有构造函数和拷贝控制
    SingletonNomArray() = default;  // 禁止外部构造
    ~SingletonNomArray() = default;
    SingletonNomArray(const SingletonNomArray&) = delete;
    SingletonNomArray& operator=(const SingletonNomArray&) = delete;

public:
    // 获取单例实例
    static SingletonNomArray& getInstance() {
        static SingletonNomArray instance;  // 线程安全的局部静态变量 (C++11)
        return instance;
    }

    // 公共接口  //
    const QVector<int>& getNomArray() const { return m_nomArray; }
    void clearNomArray() { m_nomArray.clear(); }

    int getLastNom() const {
        if (m_nomArray.isEmpty()) {
            qWarning() << "nomArray is empty!";
            return -1;
        }
        return m_nomArray.last();
    }

    void appendNom(int value) {
        m_nomArray.append(value);
    }
};

#endif // SINGLETON_NOMARRAY_H