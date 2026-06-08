/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
** 此文件是 LibreCAD 项目的一部分，LibreCAD 是一个 2D CAD 程序
**
** Copyright (C) 2018 A. Stebich (librecad@mail.lordofbikes.de)
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
** 版权信息
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
** 本文件遵循 GNU 通用公共许可证第 2 版分发和/或修改
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 本程序按原样提供，不提供任何明示或暗示的担保
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
** 你应该已收到 GNU 通用公共许可证的副本
**
** This copyright notice MUST APPEAR in all copies of the script!
** 本版权声明必须出现在脚本的所有副本中
**
**********************************************************************/

#ifndef RS_DOCUMENT_H
#define RS_DOCUMENT_H

#include "rs_layerlist.h"          // 图层列表
#include "rs_entitycontainer.h"    // 实体容器
#include "rs_undo.h"               // 撤销/重做功能
#include <QList>                   // Qt列表容器
#include <QPointF>                 // Qt浮点坐标
#include <QMessageBox>             // Qt消息框
#include <qmessagebox.h>          // Qt消息框（头文件）
#include <rs_mtext.h>
// 前向声明
class RS_BlockList;               // 块列表类

/**
 * 文档基类
 * 文档可以是图形或块，通常在图形视图中显示。
 * 文档持有用于绘图的当前激活画笔、文件名，并且知道是否已被修改。
 *
 * @author Andrew Mustun
 */
class RS_Document : public RS_EntityContainer,  // 继承自实体容器
    public RS_Undo {            // 继承自撤销管理器
public:
    // 构造函数
    RS_Document(RS_EntityContainer* parent = nullptr);

    // 虚析构函数
    virtual ~RS_Document() = default;

    // 纯虚函数，子类必须实现

    /**
     * 获取图层列表
     * @return 图层列表指针
     */
    virtual RS_LayerList* getLayerList() = 0;

    /**
     * 获取块列表
     * @return 块列表指针
     */
    virtual RS_BlockList* getBlockList() = 0;

    /**
     * 创建新文档
     */
    virtual void newDoc() = 0;

    /**
     * 保存文档
     * @param isAutoSave 是否为自动保存
     * @return 保存是否成功
     */
    virtual bool save(bool isAutoSave = false) = 0;

    /**
     * 另存为
     * @param filename 文件名
     * @param type 文件格式类型
     * @param force 是否强制覆盖
     * @return 保存是否成功
     */
    virtual bool saveAs(const QString& filename, RS2::FormatType type, bool force) = 0;

    /**
     * 打开文档
     * @param filename 文件名
     * @param type 文件格式类型
     * @return 打开是否成功
     */
    virtual bool open(const QString& filename, RS2::FormatType type) = 0;

    /**
     * 加载模板
     * @param filename 模板文件名
     * @param type 文件格式类型
     * @return 加载是否成功
     */
    virtual bool loadTemplate(const QString& filename, RS2::FormatType type) = 0;

  

    /**
     * 判断是否为文档实体
     * 对于图形或块等文档实体返回true
     * @return 总是返回true
     */
    virtual bool isDocument() const {
        return true;
    }

    /**
     * 从实体容器中移除实体
     * 这是从RS_Undo继承的实现
     * @param u 可撤销对象
     */
    virtual void removeUndoable(RS_Undoable* u) {
        if (u && u->undoRtti() == RS2::UndoableEntity && u->isUndone()) {
            removeEntity(static_cast<RS_Entity*>(u));
        }
    }

    /**
     * 获取当前激活的绘图笔
     * @return 当前激活的画笔
     */
    RS_Pen getActivePen() const {
        return activePen;
    }

    /**
     * 设置当前激活的绘图笔
     * @param p 要设置的画笔
     */
    void setActivePen(RS_Pen p) {
        activePen = p;
    }

    /**
     * 获取当前加载文档的文件名
     * 注意：新文档的默认文件名为空
     * @return 文件名
     */
    QString getFilename() const {
        return filename;
    }

    /**
     * 获取自动保存文件名
     * @return 自动保存文件名
     */
    QString getAutoSaveFilename() const {
        return autosaveFilename;
    }

    /**
     * 设置文件名
     * @param fn 新的文件名
     */
    void setFilename(const QString& fn) {
        filename = fn;
    }

    /**
     * 设置文档的修改状态
     * @param m 是否已修改
     */
    virtual void setModified(bool m) {
        // std::cout << "RS_Document::setModified: %d" << (int)m << std::endl;
        modified = m;
    }

    /**
     * 获取文档的修改状态
     * @retval true 自上次保存后文档已被修改
     * @retval false 自上次保存后文档未被修改
     */
    virtual bool isModified() const {
        return modified;
    }

    /**
     * 覆盖基类函数，在撤销周期结束时设置修改标志
     * 当完成包含可撤销操作的撤销周期时调用
     */
    virtual void endUndoCycle() override;

    /**
     * 设置图形视图
     * @param g 图形视图指针
     */
    void setGraphicView(RS_GraphicView* g) { gv = g; }

    /**
     * 获取图形视图
     * @return 图形视图指针
     */
    RS_GraphicView* getGraphicView() { return gv; }
public:
    // ... 原有函数

    // 修改原有函数，添加字符分离参数
    std::vector<std::vector<RS_Vector>> getAllEntityPathPoints(bool separateCharacters = false) const;

private:
    // 辅助函数声明
    void processEntityRecursive(RS_Entity* e,
        std::vector<std::vector<RS_Vector>>& allPoints,
        bool separateCharacters,
        int level) const;

    void processMTextEntity(RS_MText* mtext,
        std::vector<std::vector<RS_Vector>>& allPoints,
        bool separateCharacters,
        int level) const;

    std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>>
        RS_Document::sortCharactersByXYDescending(
            const std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>>& characters) const;
    void RS_Document::collectCharactersFromLine(RS_EntityContainer* type1Container,
        std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>>& allCharPathsWithCenter,
        int level) const;
    // 提取字符容器中的路径点
    std::vector<RS_Vector> RS_Document::extractCharContainerPaths(RS_EntityContainer* charContainer) const;
    RS_Vector RS_Document::calculatePathCenter(const std::vector<RS_Vector>& path) const;
    // 文本段整体处理
    void RS_Document::processTextSegmentAsWhole(RS_EntityContainer* type1Container,
        std::vector<std::vector<RS_Vector>>& allPoints,
        int level) const;
protected:
    /** 标志位，如果文档被修改且未保存则为true */
    bool modified;

    /** 当前激活的绘图笔 */
    RS_Pen activePen;

    /** 文档的文件名，新文档为空 */
    QString filename;

    /** 文档的自动保存文件名 */
    QString autosaveFilename;

    /** 文档的格式类型 */
    RS2::FormatType formatType;

    /** 用于读取/保存当前视图的图形视图 */
    RS_GraphicView* gv;
};

#endif