/*
**********************************************************************************
**
** This file was created for the LibreCAD project (librecad.org), a 2D CAD program.
**
** Copyright (C) 2016 ravas (github.com/r-a-v-a-s)
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
**********************************************************************************
*/

#include "actionlist.h"
#include <QAction>

/**
 * @class ActionList
 * @brief 动作列表控件类
 *
 * 扩展自 QListWidget，用于显示和管理 QAction 动作列表
 * 在 LibreCAD 中用于自定义工具栏、菜单等界面元素的管理
 *
 * @author ravas (github.com/r-a-v-a-s)
 */

 /**
  * @brief ActionList 构造函数
  *
  * 创建动作列表控件实例
  *
  * @param parent 父窗口指针
  */
ActionList::ActionList(QWidget* parent)
    : QListWidget(parent)  // 继承自 QListWidget
{
    // 构造函数体为空，使用基类的默认构造函数
}

/**
 * @brief 添加动作到列表项
 *
 * 创建一个列表项，显示动作的文本和图标
 * 将动作的对象名称存储在 what's this 属性中以便识别
 *
 * @param action 要添加的 QAction 动作指针
 *
 * 示例：
 * @code
 * QAction* saveAction = new QAction("&Save", this);
 * actionList->addActionItem(saveAction);
 * @endcode
 */
void ActionList::addActionItem(QAction* action)
{
    // 创建新的列表项
    auto item = new QListWidgetItem;

    // 设置列表项文本（移除 & 快捷键符号）
    item->setText(action->text().remove("&"));

    // 设置列表项图标
    item->setIcon(action->icon());

    // 将动作的对象名称存储在 what's this 属性中
    // 用于后续识别和激活对应的动作
    item->setWhatsThis(action->objectName());

    // 将列表项添加到列表控件
    addItem(item);
}

/**
 * @brief 从 QAction 列表初始化控件
 *
 * 批量添加 QAction 对象到列表控件
 * 同时保存动作列表的引用供后续使用
 *
 * @param a_list QAction 指针列表
 *
 * 示例：
 * @code
 * QList<QAction*> actions = {saveAction, openAction, newAction};
 * actionList->fromActionList(actions);
 * @endcode
 */
void ActionList::fromActionList(const QList<QAction*>& a_list)
{
    // 保存动作列表引用
    action_list = a_list;

    // 遍历动作列表，逐个添加到列表控件
    foreach(QAction * a, a_list)
    {
        addActionItem(a);
    }
}

/**
 * @brief 从 QAction 映射初始化控件
 *
 * 从 QMap<QString, QAction*> 提取动作并添加到列表控件
 * 适用于从 LibreCAD 的动作映射表初始化
 *
 * @param a_map 动作映射表，键为动作名称，值为动作指针
 *
 * 示例：
 * @code
 * QMap<QString, QAction*> actionMap = {
 *     {"FileSave", saveAction},
 *     {"FileOpen", openAction}
 * };
 * actionList->fromActionMap(actionMap);
 * @endcode
 */
void ActionList::fromActionMap(QMap<QString, QAction*>& a_map)
{
    // 遍历动作映射，逐个添加到列表控件
    foreach(QAction * a, a_map)
    {
        addActionItem(a);
    }
}

/**
 * @brief 激活选中的动作
 *
 * 当用户点击列表项时，查找并触发对应的 QAction
 * 通过动作文本进行匹配
 *
 * @param item 用户点击的列表项指针
 *
 * 示例：
 * @code
 * // 连接列表项的点击信号
 * connect(actionList, &QListWidget::itemClicked,
 *         actionList, &ActionList::activateAction);
 * @endcode
 */
void ActionList::activateAction(QListWidgetItem* item)
{
    // 遍历保存的动作列表
    foreach(QAction * a, action_list)
    {
        // 通过文本匹配找到对应的动作
        if (a->text() == item->text())
        {
            // 触发动作（模拟用户点击）
            a->activate(QAction::Trigger);
            // 找到后即可退出循环
            break;
        }
    }
}