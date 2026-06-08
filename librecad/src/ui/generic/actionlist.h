#ifndef ACTIONLIST_H
#define ACTIONLIST_H

#include <QListWidget>  // 基础列表控件

/**
 * @file actionlist.h
 * @brief ActionList 类头文件
 *
 * ActionList 是一个扩展的 QListWidget，专门用于显示和管理 QAction 对象
 * 在 LibreCAD 中用于自定义工具栏、菜单编辑等功能
 */

 /**
  * @class ActionList
  * @brief 动作列表控件类
  *
  * 继承自 QListWidget，提供以下功能：
  * 1. 显示 QAction 列表（包含图标和文本）
  * 2. 支持从多种数据结构初始化
  * 3. 点击列表项触发对应的 QAction
  * 4. 用于用户界面自定义编辑器
  *
  * 使用场景：
  * - 自定义工具栏编辑器
  * - 动作选择器
  * - 快捷键设置界面
  */
class ActionList : public QListWidget
{
    Q_OBJECT  // Qt 元对象系统宏，启用信号槽机制

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口指针，用于内存管理和布局
     *
     * 创建一个空的 ActionList 控件实例
     */
    explicit ActionList(QWidget* parent = nullptr);

    /**
     * @brief 添加单个动作到列表
     *
     * 创建一个列表项来表示指定的 QAction，
     * 显示动作的图标和文本（移除 & 快捷键符号）
     * 将动作的对象名称存储在 what's this 属性中
     *
     * @param action 要添加的 QAction 指针
     */
    void addActionItem(QAction* action);

    /**
     * @brief 从 QList<QAction*> 初始化列表
     *
     * 批量添加动作到列表，并保存列表引用供后续使用
     * 通过 activateAction() 方法可以触发这些动作
     *
     * @param a_list QAction 指针列表
     */
    void fromActionList(const QList<QAction*>& a_list);

    /**
     * @brief 从 QMap<QString, QAction*> 初始化列表
     *
     * 从动作映射表中提取所有动作并添加到列表
     * 常用于从主窗口的动作映射表初始化
     *
     * @param a_map 动作映射表，键为动作标识符，值为动作指针
     */
    void fromActionMap(QMap<QString, QAction*>& a_map);

public slots:
    /**
     * @brief 激活指定列表项对应的动作
     *
     * 当用户点击列表项时调用此槽函数，
     * 通过文本匹配找到对应的 QAction 并触发它
     *
     * 典型用法：
     * @code
     * connect(actionList, &QListWidget::itemClicked,
     *         actionList, &ActionList::activateAction);
     * @endcode
     *
     * @param item 被点击的列表项指针
     */
    void activateAction(QListWidgetItem* item);

protected:
    /**
     * @brief 动作列表容器
     *
     * 存储从 fromActionList() 传入的动作指针，
     * 供 activateAction() 方法查找和触发使用
     *
     * 注意：此容器只在使用 fromActionList() 初始化时有效
     * 使用 fromActionMap() 初始化时，此容器为空
     */
    QList<QAction*> action_list;

    /**
     * 继承的方法说明：
     *
     * 继承自 QListWidget 的重要方法：
     * - addItem(): 添加列表项
     * - item(): 获取指定索引的列表项
     * - count(): 获取列表项数量
     * - clear(): 清空列表
     * - selectedItems(): 获取选中的列表项
     */
};

#endif // ACTIONLIST_H
