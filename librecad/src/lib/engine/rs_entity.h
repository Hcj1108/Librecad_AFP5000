/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2015 A. Stebich (librecad@mail.lordofbikes.de)
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!
**
**********************************************************************/


#ifndef RS_ENTITY_H
#define RS_ENTITY_H

#include <map>
#include "rs_vector.h"
#include "rs_pen.h"
#include "rs_undoable.h"

class RS_Arc;
class RS_Block;
class RS_Circle;
class RS_Document;
class RS_EntityContainer;
class RS_Graphic;
class RS_GraphicView;
class RS_Insert;
class RS_Line;
class RS_Painter;
class RS_Point;
class RS_Polyline;
class RS_Text;
class RS_Layer;
class LC_Quadratic;
class RS_Vector;
class RS_VectorSolutions;
class QString;

/**
 * 实体（Entity）基类，是所有图形元素的抽象基类。
 *
 * 实体是 LibreCAD 中所有可绘制图形对象（如直线、圆弧、圆、文本等）的基类。
 * 它继承自 RS_Undoable，支持撤销/重做操作。
 * 每个实体都具有唯一的 ID、笔属性（颜色/线宽/线型）、所在的图层、边界框等基本特征。
 * 子类必须实现纯虚函数以提供具体的几何行为和绘制能力。
 *
 * @author Andrew Mustun
 */
class RS_Entity : public RS_Undoable {
public:

    /**
     * 获取路径点序列。提供默认实现，非纯虚函数。
     * @return 路径点集合，子类可以按实际边界返回实体的关键路径点
     */
    virtual std::vector<RS_Vector> getPathPoints() const {
        return std::vector<RS_Vector>{RS_Vector(0, 0), RS_Vector(0, 0)};
    }

public:
    // 设置/获取临时标记，用于标记临时实体（如预览时的拖动实体、高亮辅助线等）
    void setTemporary(bool temp) { m_isTemporary = temp; }
    bool isTemporary() const { return m_isTemporary; }

private:
    bool m_isTemporary = false;  // 临时标记成员变量

public:

    /**
     * 构造函数。
     * @param parent 父实体容器（如图形 Graphic、多段线 Polyline 等），可为 nullptr
     */
    RS_Entity(RS_EntityContainer* parent=nullptr);
    virtual ~RS_Entity() = default;

    void init();              // 初始化函数，由构造函数调用
    virtual void initId();    // 初始化唯一 ID

    /**
     * 克隆当前实体。
     * @return 实体的深拷贝副本
     */
    virtual RS_Entity* clone() const = 0;

    /**
     * 将实体重新挂接到新的父容器。
     * @param parent 新的父实体容器
     */
    virtual void reparent(RS_EntityContainer* parent) {
        this->parent = parent;
    }

    void resetBorders();                              // 重置边界框
    void moveBorders(const RS_Vector& offset);        // 移动边界框
    void scaleBorders(const RS_Vector& center, const RS_Vector& factor);  // 缩放边界框

    /**
     * 必须由子类重写，返回实体的运行时类型标识（RTTI）。
     * 例如直线返回 RS2::EntityLine，圆弧返回 RS2::EntityArc。
     */
    virtual RS2::EntityType rtti() const{
        return RS2::EntityUnknown;
    }

    /**
     * 将所有实体标识为可撤销实体。
     * @return 始终返回 RS2::UndoableEntity
     */
    virtual RS2::UndoableType undoRtti() const override {
        return RS2::UndoableEntity;
    }

    /**
     * @return 实体的唯一标识 ID
     */
    unsigned long int getId() const {
        return id;
    }

    /**
     * 必须由子类重写，返回该实体包含的原子实体数量。
     * 对于简单实体（如直线、圆），通常返回 1。
     * 对于容器实体（如多段线），返回其包含的子实体数量。
     */
    virtual unsigned int count() const= 0;

    /**
     * 必须由子类重写，返回包含子容器在内的所有原子实体总数。
     * 与 count() 不同，此方法会递归统计所有嵌套层级。
     */
    virtual unsigned int countDeep() const= 0;

    /**
     * 必须由子类实现，返回实体的总长度。
     * @return 长度值；如果实体没有长度概念（如文本、填充图案），返回负数。
     */
    virtual double getLength() const {
        return -1.0;
    }

    /**
     * @return 实体的父容器，若为根实体则返回 nullptr
     */
    RS_EntityContainer* getParent() const {
        return parent;
    }

    /**
     * 设置实体的父容器。
     * @param p 新的父实体容器
     */
    void setParent(RS_EntityContainer* p) {
        parent = p;
    }

    /**
     * @return 实体的中心点（适用于弧、圆、椭圆等）
     */
    virtual RS_Vector getCenter() const;
    virtual double getRadius() const;                // @return 实体的半径
    RS_Graphic* getGraphic() const;                  // @return 所属的图形对象
    RS_Block* getBlock() const;                      // @return 所属的图块对象
    RS_Insert* getInsert() const;                    // @return 所属的插入对象
    RS_Entity* getBlockOrInsert() const;             // @return 所属的图块或插入对象
    RS_Document* getDocument() const;                // @return 所属的文档对象

    void setLayer(const QString& name);              // 按名称设置图层
    void setLayer(RS_Layer* l);                      // 设置图层指针
    void setLayerToActive();                         // 设置为当前活动图层
    RS_Layer* getLayer(bool resolve = true) const;   // 获取图层（resolve=true 时解析 ByBlock 引用）

    /**
     * 设置实体的笔属性（颜色、线宽、线型）。
     * 支持设置为 ByLayer（随层）、ByBlock（随块）等特殊属性。
     * @param pen 笔属性对象
     */
    void setPen(const RS_Pen& pen) {
        this->pen = pen;
    }

    void setPenToActive();               // 设置为当前活动笔属性
    RS_Pen getPen(bool resolve = true) const;  // 获取笔属性（resolve=true 时解析引用）

    /**
     * 必须由子类重写，判断该实体是否为容器类型。
     * @return true 表示容器实体（如多段线、组），可包含子实体
     */
    virtual bool isContainer() const = 0;

    /**
     * 必须由子类重写，判断该实体是否为原子实体。
     * @return true 表示原子实体（如直线、圆），不可再分
     */
    virtual bool isAtomic() const = 0;

    /**
     * 必须由子类重写，判断该实体是否为轮廓的潜在边。
     * 默认返回 false。
     */
    virtual bool isEdge() const {
        return false;
    }

    /**
     * @return true 如果是文档实体（如 Graphics 或 Blocks），否则返回 false
     */
    virtual bool isDocument() const {
        return false;
    }

    virtual bool setSelected(bool select);        // 设置选中状态
    virtual bool toggleSelected();                // 切换选中状态
    virtual bool isSelected() const;              // 是否被选中
    bool isParentSelected() const;                // 父实体是否被选中
    virtual bool isProcessed() const;             // 是否已被处理
    virtual void setProcessed(bool on);           // 设置已处理标记
    bool isInWindow(RS_Vector v1, RS_Vector v2) const;  // 是否在指定窗口内
    virtual bool hasEndpointsWithinWindow(const RS_Vector& /*v1*/, const RS_Vector& /*v2*/) {
        return false;  // 是否有端点在窗口内
    }
    virtual bool isVisible() const;               // 是否可见
    virtual void setVisible(bool v);              // 设置可见性
    virtual void setHighlighted(bool on);         // 设置高亮状态
    virtual bool isHighlighted() const;           // 是否高亮

    bool isLocked() const;                        // 所在图层是否被锁定

    void undoStateChanged(bool undone) override;  // 撤销状态变化的回调
    virtual bool isUndone() const;                // 是否已被撤销

    /**
     * 由子类实现，更新实体的临时子实体。
     * 当实体的参数或撤销状态发生变化时，会调用 update()。
     */
    virtual void update() {}

    virtual void setUpdateEnabled(bool on) {      // 启用/禁用自动更新
        updateEnabled = on;
    }

    /**
     * 获取实体边界框的最小坐标（不进行计算，直接返回值）。
     * @return 最小坐标值
     * @see calculateBorders()
     */
    RS_Vector getMin() const {
        return minV;
    }

    /**
     * 获取实体边界框的最大坐标（不进行计算，直接返回值）。
     * @return 最大坐标值
     * @see calculateBorders()
     */
    RS_Vector getMax() const {
        return maxV;
    }

    /**
     * 返回边界框的最大与最小坐标的差值，即实体的大小。
     * @return 实体尺寸向量
     * @see getMin()
     * @see getMax()
     */
    RS_Vector getSize() const;

    void addGraphicVariable(const QString& key, double val, int code);     // 添加图形变量（double）
    void addGraphicVariable(const QString& key, int val, int code);        // 添加图形变量（int）
    void addGraphicVariable(const QString& key, const QString& val, int code); // 添加图形变量（QString）

    double getGraphicVariableDouble(const QString& key, double def);       // 获取图形变量（double）
    int getGraphicVariableInt(const QString& key, int def) const;          // 获取图形变量（int）
    QString getGraphicVariableString(const QString& key,
                                     const QString& def) const;           // 获取图形变量（QString）
    virtual RS_Vector getStartpoint() const;  // 获取起点
    virtual RS_Vector getEndpoint() const;    // 获取终点

    // 查找端点的局部方向；如果实体类型支持方向，子类必须实现此方法
    virtual double getDirection1() const {
        return 0.;  // 起点处方向角
    }
    virtual double getDirection2() const {
        return 0.;  // 终点处方向角
    }

    // 查找从给定点到实体的切点
    virtual RS_VectorSolutions getTangentPoint(const RS_Vector& /*point*/) const;
    virtual RS_Vector getTangentDirection(const RS_Vector& /*point*/)const;
    RS2::Unit getGraphicUnit() const;  // 获取父图形的单位

    /**
     * 必须由子类重写，获取实体的所有参考点。
     * 参考点用于实体选取和编辑时的控制点显示。
     */
    virtual RS_VectorSolutions getRefPoints() const;

    /**
     * 获取离给定坐标最近的端点。
     *
     * @param coord 坐标（通常是鼠标位置）
     * @param dist 指向存储测量距离的变量的指针；可为 nullptr
     *
     * @return 最近的端点
     */
    virtual RS_Vector getNearestEndpoint(const RS_Vector& coord,
                                         double* dist = nullptr)const = 0;

    /**
     * 获取离给定坐标最近的、位于实体上的点。
     *
     * @param coord 坐标（通常是鼠标位置）
     * @param onEntity 是否限定在实体上
     * @param dist 指向距离变量的指针；可为 nullptr
     * @param entity 最接近的子实体指针；可为 nullptr
     *
     * @return 实体上最近的坐标点
     */
    virtual RS_Vector getNearestPointOnEntity(const RS_Vector& /*coord*/,
                                              bool onEntity = true, double* dist = nullptr,
                                              RS_Entity** entity = nullptr) const = 0;

    /**
     * 获取离给定坐标最近的中心点。
     *
     * @param coord 坐标（通常是鼠标位置）
     * @param dist 指向距离变量的指针；可为 nullptr
     *
     * @return 最近的中心点
     */
    virtual RS_Vector getNearestCenter(const RS_Vector& coord,
                                       double* dist = nullptr) const= 0;

    /**
     * 获取实体的中点。
     * @return 中点坐标，默认返回无效向量
     */
    virtual RS_Vector getMiddlePoint(void)const{
        return RS_Vector(false);
    }

    /**
     * 获取离给定坐标最近的中点。
     *
     * @param coord 坐标（通常是鼠标位置）
     * @param dist 指向距离变量的指针；可为 nullptr
     * @param middlePoints 中点数量
     *
     * @return 最近的中点
     */
    virtual RS_Vector getNearestMiddle(const RS_Vector& coord,
                                       double* dist = nullptr,
                                       int middlePoints = 1
            ) const= 0;

    /**
     * 获取离给定坐标最近的、距端点给定距离的点。
     *
     * @param distance 距端点的距离
     * @param coord 坐标（通常是鼠标位置）
     * @param dist 指向距离变量的指针；可为 nullptr
     *
     * @return 距端点指定距离的最近点
     */
    virtual RS_Vector getNearestDist(double distance,
                                     const RS_Vector& coord,
                                     double* dist = nullptr) const= 0;

    /**
     * 获取距起点或终点给定距离的点。
     *
     * @param distance 距端点的距离
     * @param startp true = 从起点测量，false = 从终点测量
     *
     * @return 距起点或终点指定距离的点
     */
    virtual RS_Vector getNearestDist(double /*distance*/,
                                     bool /*startp*/) const{
        return RS_Vector(false);
    }

    /**
     * 获取离给定坐标最近的参考点。
     *
     * @param coord 坐标（通常是鼠标位置）
     * @param dist 指向距离变量的指针；可为 nullptr
     *
     * @return 最近的参考点
     */
    virtual RS_Vector getNearestRef(const RS_Vector& coord,
                                    double* dist = nullptr) const;

    /**
     * 获取当前实体（若被选中）的最近参考点。
     * 容器类重写此方法以返回选中子实体的最近参考点。
     *
     * @param coord 坐标（通常是鼠标位置）
     * @param dist 指向距离变量的指针；可为 nullptr
     *
     * @return 最近的参考点
     */
    virtual RS_Vector getNearestSelectedRef(const RS_Vector& coord,
                                            double* dist = nullptr) const;

    /**
     * 获取最近的与给定直线正交的切点。
     * 返回与指定法线正交的、实体上的切线方向的点。
     */
    virtual RS_Vector getNearestOrthTan(const RS_Vector& /*coord*/,
                                        const RS_Line& /*normal*/,
                                        bool onEntity = false) const;

    /**
     * 获取实体到指定坐标点的最短距离。
     *
     * @param coord 坐标点
     * @param entity 输出参数，最近的子实体指针
     * @param level 解析层级
     * @param solidDist 实体距离阈值
     *
     * @return 最短距离
     */
    virtual double getDistanceToPoint(const RS_Vector& coord,
                                      RS_Entity** entity = nullptr,
                                      RS2::ResolveLevel level = RS2::ResolveNone,
                                      double solidDist = RS_MAXDOUBLE) const;

    /**
     * 判断指定点是否位于实体上。
     * @param coord 坐标点
     * @param tolerance 容差，默认 20 * RS_TOLERANCE
     * @return true 如果点在实体上
     */
    virtual bool isPointOnEntity(const RS_Vector& coord,
                                 double tolerance=20.*RS_TOLERANCE) const;

    /**
     * 沿给定方向和距离偏移实体。
     * @return true 如果偏移成功
     */
    virtual bool offset(const RS_Vector& /*coord*/, const double& /*distance*/) {return false;}

    /**
     * 沿两侧按指定距离偏移实体，用于生成相切圆。
     * @return 偏移后的实体列表
     */
    virtual std::vector<RS_Entity* > offsetTwoSides(const double& /*distance*/) const
    {
        return std::vector<RS_Entity* >();
    }

    /**
     * 反转原子实体的方向（起点和终点互换）。
     */
    virtual void revertDirection(){}

    /**
     * 按指定偏移向量移动实体。
     */
    virtual void move(const RS_Vector& offset) = 0;

    /**
     * 按指定角度绕指定中心点旋转实体。
     */
    virtual void rotate(const RS_Vector& center, const double& angle) = 0;
    virtual void rotate(const RS_Vector& center, const RS_Vector& angleVector) = 0;

    /**
     * 按指定因子缩放实体。
     */
    virtual void scale(const RS_Vector& center, const RS_Vector& factor) = 0;

    /**
     * 等比例缩放，等效于 scale(center, RS_Vector(factor, factor))。
     */
    virtual void scale(const RS_Vector& center, const double& factor) {
        scale(center, RS_Vector(factor, factor));
    }
    virtual void scale(const RS_Vector& factor) {
        scale(RS_Vector(0.,0.), factor);
    }

    /**
     * 按指定轴镜像实体。
     */
    virtual void mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2) = 0;

    /**
     * 拉伸实体在指定范围内的部分。
     * 默认实现：如果实体完全在窗口内，则整体移动。
     */
    virtual void stretch(const RS_Vector& firstCorner,
                         const RS_Vector& secondCorner,
                         const RS_Vector& offset);

    /**
     * 拖动与参考点相近的参考点。
     */
    virtual void moveRef(const RS_Vector& /*ref*/,
                         const RS_Vector& /*offset*/) {
        return;
    }

    /**
     * 拖动被选中实体的参考点。
     */
    virtual void moveSelectedRef(const RS_Vector& /*ref*/,
                                 const RS_Vector& /*offset*/) {
        return;
    }

    /**
     * 判断实体的边界框是否与图形视图的可见部分相交。
     */
    virtual bool isVisibleInWindow(RS_GraphicView* view) const;

    /**
     * 在指定设备上绘制实体。
     * @param painter 绘制工具
     * @param view 图形视图
     * @param patternOffset 线型图案偏移量
     */
    virtual void draw(RS_Painter* painter, RS_GraphicView* view,
                      double& patternOffset ) = 0;

    double getStyleFactor(RS_GraphicView* view);  // 获取线型样式缩放因子

    QString getUserDefVar(const QString& key) const;       // 获取用户自定义变量
    std::vector<QString> getAllKeys() const;                // 获取所有自定义变量的键名列表
    void setUserDefVar(QString key, QString val);           // 设置用户自定义变量
    void delUserDefVar(QString key);                        // 删除用户自定义变量

    friend std::ostream& operator << (std::ostream& os, RS_Entity& e);  // 输出运算符重载

    /** 重新计算实体边界框。 */
    virtual void calculateBorders() = 0;

    /**
     * 判断实体是否位于构造图层上。
     * 构造图层包含无限长实体，打印时不显示。
     * @param typeCheck true 时忽略某些实体类型（除 Line 外的实体返回 false）
     */
    bool isConstruction(bool typeCheck = false) const;

    /** @return 实体所在图层是否启用了打印 */
    bool isPrint(void) const;

    /**
     * 返回实体的方程。
     * 二次曲线：m0 x^2 + m1 xy + m2 y^2 + m3 x + m4 y + m5 = 0
     * 直线：m0 x + m1 y + m2 = 0
     */
    virtual LC_Quadratic getQuadratic() const;

    /**
     * 基于格林定理的轮廓面积计算的线积分。
     * 轮廓面积 = ∮ x dy
     * @return 沿实体的线积分值
     */
    virtual double areaLineIntegral() const;

    /**
     * @brief 判断实体类型是否可修剪。
     * @return true 对于可修剪的实体类型
     * 当前可修剪类型：RS_Line, RS_Circle, RS_Arc, RS_Ellipse
     */
    bool trimmable() const;

    /**
     * @brief 判断实体是否为弧、圆或椭圆类型。
     * @return true 如果是 Arc、Circle 或 Ellipse
     */
    virtual bool isArc() const;

    /**
     * @brief 判断实体是否为弧、圆或直线类型。
     * @return true 如果是 Arc、Circle 或 Line
     */
    virtual bool isArcCircleLine() const;

protected:
    RS_EntityContainer* parent = nullptr;  // 实体的父容器，根实体的 parent 为 nullptr
    RS_Vector minV;                        // 边界框最小坐标
    RS_Vector maxV;                        // 边界框最大坐标

    RS_Layer* layer;                       // 实体所在的图层指针

    unsigned long int id;                  // 实体唯一标识 ID

    RS_Pen pen;                            // 实体的笔属性（颜色、线宽、线型）

    bool updateEnabled;                    // 是否启用自动更新

private:
    std::map<QString, QString> varList;    // 用户自定义变量映射表
};

#endif
