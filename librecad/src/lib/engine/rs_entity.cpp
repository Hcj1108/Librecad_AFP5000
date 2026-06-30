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


#include <iostream>
#include <utility>
#include <QPolygon>
#include <QString>

#include "rs_entity.h"
#include "rs_arc.h"
#include "rs_block.h"
#include "rs_circle.h"
#include "rs_ellipse.h"
#include "rs_graphic.h"
#include "rs_graphicview.h"
#include "rs_insert.h"
#include "rs_layer.h"
#include "rs_line.h"
#include "rs_mtext.h"
#include "rs_point.h"
#include "rs_polyline.h"
#include "rs_text.h"
#include "rs_vector.h"
#include "rs_information.h"
#include "lc_quadratic.h"
#include "rs_debug.h"

/**
 * 默认构造函数。
 * @param parent 实体的父实体。例如，一条线可能以图形实体或多段线实体为父实体。
 */
RS_Entity::RS_Entity(RS_EntityContainer* parent) {

    this->parent = parent;
    init();              
}


/**
 * 拷贝构造函数（已注释掉）。
 */
/*RS_Entity::RS_Entity(const RS_Entity& e) : RS_Flags(e.getFlags()) {
        cout << "copy constructor called\n";
        init();
        parent = e.parent;
        layer = e.layer;
        //setFlag(e.getFlags());
    minV = e.minV;
    maxV = e.maxV;
    pen = e.pen;
}*/

/**
 * 初始化函数。从所有构造函数调用。
 * 重置边界框、设置可见标志、启用更新、设置活动图层和笔属性，并分配 ID。
 */
void RS_Entity::init() {
    resetBorders();//重置实体的边界框

    setFlag(RS2::FlagVisible);//将实体设置为“可见”状态。
    //layer = nullptr;
    //pen = RS_Pen();
        updateEnabled = true;
    setLayerToActive();
    setPenToActive();
    initId();
}

/**
 * 为该实体分配一个新的唯一 ID。
 * ID 使用静态计数器自增生成。
 */
void RS_Entity::initId() {
    static unsigned long int idCounter=0;
    id = idCounter++;
}

/**
 * 重置元素的边界框。
 * 将最小坐标设为极大值，最大坐标设为极小值，
 * 以便后续通过 calculateBorders() 正确计算实际边界。
 */
void RS_Entity::resetBorders() {
    // TODO: Check that. windoze XP crashes with MAXDOUBLE
    double maxd = RS_MAXDOUBLE;
    double mind = RS_MINDOUBLE;

    minV.set(maxd, maxd);
    maxV.set(mind, mind);
}

/**
 * 平移包围盒。
 * 把 minV 和 maxV 这两个点，按照 offset（偏移量向量）进行移动
 */
void RS_Entity::moveBorders(const RS_Vector& offset){
    minV.move(offset);
    maxV.move(offset);
}
/**
 * 缩放包围盒。
 * 以 center（中心点）为基准，按照 offset（偏移量向量）进行缩放
 */
void RS_Entity::scaleBorders(const RS_Vector& center, const RS_Vector& factor){
    minV.scale(center,factor);
    maxV.scale(center,factor);
}


/**
 * 选择或取消选择此实体。
 *
 * @param select true 为选择，false 为取消选择。
 * @return 如果实体所在图层被锁定则返回 false。
 */
bool RS_Entity::setSelected(bool select) {
    // layer is locked:
    if (select && isLocked()) {
        return false;
    }

    if (select) {
        setFlag(RS2::FlagSelected);
    } else {
        delFlag(RS2::FlagSelected);
    }

    return true;
}



/**
 * 切换实体的选择状态。
 */
bool RS_Entity::toggleSelected() {
    return setSelected(!isSelected());
    //toggleFlag(RS2::FlagSelected);
}



/**
 * @return 如果实体被选中则返回 true。
 * 注意：如果实体本身未选中但其父实体被选中，此函数返回 false。
 */
bool RS_Entity::isSelected() const {
    //bug 557, Selected entities in invisible layers are deleted
    return isVisible() && getFlag(RS2::FlagSelected);
}



/**
 * @return 如果该实体的父实体被选中，则返回 true。
 */
bool RS_Entity::isParentSelected() const
{
    RS_Entity const* p = this;

    while(p) {
        p = p->getParent();
        if (p && p->isSelected()==true) {
            return true;
        }
    }

    return false;
}



/**
 * 设置或重置实体的已处理标记。
 *
 * @param on true 为设置标记，false 为重置标记。
 */
void RS_Entity::setProcessed(bool on) {
    if (on) {
        setFlag(RS2::FlagProcessed);
    } else {
        delFlag(RS2::FlagProcessed);
    }
}



/**
 * @return 如果已处理标记被设置则返回 true。
 */
bool RS_Entity::isProcessed() const {
    return getFlag(RS2::FlagProcessed);
}



/**
 * 当撤销状态发生变化时调用。
 *
 * @param undone true: 实体变为不可见。
 *               false: 实体变为可见。
 */
void RS_Entity::undoStateChanged(bool undone)
{
    Q_UNUSED( undone);

    setSelected(false);
    update();
}


/**
 * @return 如果此实体或其任何父实体被撤销，则返回 true。
 */
bool RS_Entity::isUndone() const {
        if (!parent) {
                return RS_Undoable::isUndone();
        }
        else {
                return RS_Undoable::isUndone() || parent->isUndone();
        }
}


/**
 * @return 如果实体在给定的矩形范围内则返回 true。
 */
bool RS_Entity::isInWindow(RS_Vector v1, RS_Vector v2) const
{
    double right, left, top, bottom;

    right = std::max(v1.x, v2.x);
    left = std::min(v1.x, v2.x);
    top = std::max(v1.y, v2.y);
    bottom = std::min(v1.y, v2.y);

    return (getMin().x>=left &&
            getMax().x<=right &&
            getMin().y>=bottom &&
            getMax().y<=top);
}

/**
 * 基于格林定理计算轮廓面积线积分。
 * 默认实现返回 0，子类可以按需重写。
 */
double RS_Entity::areaLineIntegral() const
{
    return 0.;
}

/**
 * 判断实体是否为弧、圆或椭圆类型。
 */
bool RS_Entity::isArc() const
{
    switch (rtti()) {
    case RS2::EntityArc:
    case RS2::EntityCircle:
        //ellipse implements its own test
    case RS2::EntityEllipse:
        return true;
    default:
        return false;
    }
}

/**
 * 判断实体是否为弧、圆、直线或点类型。
 */
 bool RS_Entity::isArcCircleLine() const
 {
     switch (rtti()) {
     case RS2::EntityArc:
     case RS2::EntityCircle:
     case RS2::EntityLine:
     case RS2::EntityPoint:
         return true;
     default:
         return false;
     }
 }

/** 判断实体的边界框是否与图形视图的可见部分相交 */
bool RS_Entity::isVisibleInWindow(RS_GraphicView* view) const
{
    RS_Vector vpMin(view->toGraph(0,view->getHeight()));
    RS_Vector vpMax(view->toGraph(view->getWidth(),0));
    if( getStartpoint().isInWindowOrdered(vpMin, vpMax) ) return true;
    if( getEndpoint().isInWindowOrdered(vpMin, vpMax) ) return true;
    QPolygonF visualBox(QRectF(vpMin.x,vpMin.y,vpMax.x-vpMin.x, vpMax.y-vpMin.y));
    std::vector<RS_Vector> vps;
    for(unsigned short i=0;i<4;i++){
        const QPointF& vp(visualBox.at(i));
        vps.emplace_back(vp.x(),vp.y());
    }
    for(unsigned short i=0;i<4;i++){
        RS_Line const line{vps.at(i),vps.at((i+1)%4)};
        if( RS_Information::getIntersection(this, &line, true).size()>0) return true;
    }
    if( minV.isInWindowOrdered(vpMin,vpMax)||maxV.isInWindowOrdered(vpMin,vpMax)) return true;
    return false;
}

/**
 * 判断给定点是否在此实体上。
 *
 * @param tolerance 容差。
 * @retval true 如果给定点在此实体上。
 * @retval false 否则。
 */
bool RS_Entity::isPointOnEntity(const RS_Vector& coord,
                                double tolerance) const {
    double dist = getDistanceToPoint(coord, nullptr, RS2::ResolveNone);
    return (dist<=fabs(tolerance));
}

/**
 * 计算实体到指定坐标点的最短距离。
 * 会同时计算到实体自身的距离和到中心点的距离，取最小值。
 */
double RS_Entity::getDistanceToPoint(const RS_Vector& coord,
                                  RS_Entity** entity,
                                  RS2::ResolveLevel /*level*/,
                                  double /*solidDist*/) const
{
    if (entity) {
        *entity=const_cast<RS_Entity*>(this);
    }
    double dToEntity = RS_MAXDOUBLE;
    (void) getNearestPointOnEntity(coord, true, &dToEntity, entity);

    // RVT 6 Jan 2011 : Add selection by center point
    if(getCenter().valid){
        double dToCenter=getCenter().distanceTo(coord);
        return std::min(dToEntity,dToCenter);
    }else
        return dToEntity;
}

/**
 * 判断此实体是否可见。
 *
 * @return 仅当实体本身及其所在图层都可见时才返回 true。
 * 图层指针可能为 nullptr，此时忽略图层可见性检查。
 */
bool RS_Entity::isVisible() const{

    if (!getFlag(RS2::FlagVisible)) {
        return false;
    }

    if (isUndone()) {
        return false;
    }

    /*RS_EntityContainer* parent = getParent();
    if (parent && parent->isUndone()) {
            return false;
    }*/

    if (!getLayer()) {
        return true;
    }

    // inserts are usually visible - the entities in them have their own
    //   layers which might be frozen
    // upd: i'm not sure if that is the best behaviour
    //if (rtti()==RS2::EntityInsert) {
    //	return true;
    //}
    // blocks are visible in editing window, issue#253
    if( isDocument() && (rtti()==RS2::EntityBlock || rtti()==RS2::EntityInsert)) {
        return true;
    }

    if (layer /*&& layer->getName()!="ByBlock"*/) {

        if (!layer->isFrozen()) {
            return true;
        } else {
            return false;
        }
    }

    if (!layer /*&& getLayer()->getName()!="ByBlock"*/) {
        if (!getLayer()) {
            return true;
        } else {
            if (!getLayer()->isFrozen()) {
                return true;
            } else {
                return false;
            }
        }
    }

    if (!getBlockOrInsert()) {
        return true;
    }

    if (getBlockOrInsert()->rtti()==RS2::EntityBlock) {
        return !(getLayer(false) && getLayer(false)->isFrozen());
    }


    if (!getBlockOrInsert()->getLayer()) {
        return true;
    }

    if (!getBlockOrInsert()->getLayer()->isFrozen()) {
        return true;
    }

    return false;
}

/**
 * 设置实体的可见性。
 */
void RS_Entity::setVisible(bool v) {
    if (v) {
        setFlag(RS2::FlagVisible);
    } else {
        delFlag(RS2::FlagVisible);
    }
}

/**
 * 设置实体的高亮状态。
 * 高亮实体通常用于向用户反馈操作结果。
 */
void RS_Entity::setHighlighted(bool on) {
    if (on) {
        setFlag(RS2::FlagHighlighted);
    } else {
        delFlag(RS2::FlagHighlighted);
    }
}

/**
 * @return 实体的起点，默认返回无效向量。
 */
RS_Vector RS_Entity::getStartpoint() const {
    return {};
}

/**
 * @return 实体的终点，默认返回无效向量。
 */
RS_Vector RS_Entity::getEndpoint() const {
    return {};
}

/**
 * 获取从给定点到实体的切点，默认返回空解集。
 */
RS_VectorSolutions RS_Entity::getTangentPoint(const RS_Vector& /*point*/) const {
    return {};
}

/**
 * 获取从给定点出发的切线方向，默认返回无效向量。
 */
RS_Vector RS_Entity::getTangentDirection(const RS_Vector& /*point*/)const{
    return {};
}

/**
 * @return 如果实体被高亮则返回 true。
 */
bool RS_Entity::isHighlighted() const{
    return getFlag(RS2::FlagHighlighted);
}


/**
 * @return 边界框的大小（maxV - minV）。
 */
RS_Vector RS_Entity::getSize() const {
    return maxV-minV;
}

/**
 * @return 如果实体所在图层被锁定则返回 true。
 */
bool RS_Entity::isLocked() const
{
    return getLayer(true) && getLayer()->isLocked();
}

/**
 * 获取实体的中心点，默认返回无效向量。
 */
RS_Vector RS_Entity::getCenter() const {
    return RS_Vector{};
}

/**
 * 获取实体的半径，默认返回极大值。
 */
double RS_Entity::getRadius() const {
    return RS_MAXDOUBLE;
}

/**
 * @return 存储此实体的父 Graphic 对象，
 * 或父级的父级 Graphic，如果没有任何父级存储在 Graphic 中则返回 nullptr。
 */
RS_Graphic* RS_Entity::getGraphic() const{
    if (rtti()==RS2::EntityGraphic) {
        RS_Graphic const* ret=static_cast<RS_Graphic const*>(this);
        return const_cast<RS_Graphic*>(ret);
    } else if (!parent) {
        return nullptr;
    }
    return parent->getGraphic();
}



/**
 * @return 存储此实体的父 Block 对象，
 * 或父级的父级 Block，如果没有任何父级存储在 Block 中则返回 nullptr。
 */
RS_Block* RS_Entity::getBlock() const{
    if (rtti()==RS2::EntityBlock) {
        RS_Block const* ret=static_cast<RS_Block const*>(this);
        return const_cast<RS_Block*>(ret);
    } else if (!parent) {
        return nullptr;
    }
    return parent->getBlock();
}


/** 返回实体的二次方程。
 * 对于二次曲线，返回向量包含：
 * m0 x^2 + m1 xy + m2 y^2 + m3 x + m4 y + m5 = 0
 * 对于直线：
 * m0 x + m1 y + m2 = 0
 **/
LC_Quadratic RS_Entity::getQuadratic() const
{
        return LC_Quadratic{};
}

/**
 * @return 存储此实体的父 Insert 对象，
 * 或父级的父级，如果没有任何父级存储在 Insert 中则返回 nullptr。
 */
RS_Insert* RS_Entity::getInsert() const
{
    if (rtti()==RS2::EntityInsert) {
        RS_Insert const* ret=static_cast<RS_Insert const*>(this);
        return const_cast<RS_Insert*>(ret);
    } else if (!parent) {
        return nullptr;
    } else {
        return parent->getInsert();
    }
}

/**
 * @return 存储此实体的父 Block 或 Insert 对象，
 * 或父级的父级，如果没有任何父级存储在 Block 或 Insert 中则返回 nullptr。
 */
RS_Entity* RS_Entity::getBlockOrInsert() const
{
    RS_Entity* ret{nullptr};
    switch(rtti()){
    case RS2::EntityBlock:
    case RS2::EntityInsert:
        ret=const_cast<RS_Entity*>(this);
        break;
    default:
        if(parent) {
            return parent->getBlockOrInsert();
        }
    }
    return ret;
}

/**
 * @return 存储此实体的父 Document 对象。
 * 注意：Document 通常是 Graphic 或 Block。
 */
RS_Document* RS_Entity::getDocument() const{
    if (isDocument()) {
        RS_Document const* ret=static_cast<RS_Document const*>(this);
        return const_cast<RS_Document*>(ret);
    } else if (!parent) {
        return nullptr;
    }
    return parent->getDocument();
}



/**
 * 为父 Graphic 对象设置变量值。
 *
 * @param key 变量名（如 "$DIMASZ"）
 * @param val 默认值（double 类型）
 * @param code DXF 组码
 */
void RS_Entity::addGraphicVariable(const QString& key, double val, int code) {
    RS_Graphic* graphic = getGraphic();
    if (graphic) {
        graphic->addVariable(key, val, code);
    }
}



/**
 * 为父 Graphic 对象设置变量值。
 *
 * @param key 变量名（如 "$DIMASZ"）
 * @param val 默认值（int 类型）
 * @param code DXF 组码
 */
void RS_Entity::addGraphicVariable(const QString& key, int val, int code) {
    RS_Graphic* graphic = getGraphic();
    if (graphic) {
        graphic->addVariable(key, val, code);
    }
}



/**
 * 为父 Graphic 对象设置变量值。
 *
 * @param key 变量名（如 "$DIMASZ"）
 * @param val 默认值（字符串类型）
 * @param code DXF 组码
 */
void RS_Entity::addGraphicVariable(const QString& key,
                                   const QString& val, int code) {
    RS_Graphic* graphic = getGraphic();
    if (graphic) {
        graphic->addVariable(key, val, code);
    }
}



/**
 * 安全地返回指定变量的 double 值。
 *
 * @param key 变量名（如 "$DIMASZ"）
 * @param def 默认值
 *
 * @return 变量值，如果变量不存在则返回默认值。
 */
double RS_Entity::getGraphicVariableDouble(const QString& key, double def) {
    RS_Graphic* graphic = getGraphic();
    double ret=def;
    if (graphic) {
        ret = graphic->getVariableDouble(key, def);
    }
    return ret;
}



/**
 * 安全地返回指定变量的 int 值。
 *
 * @param key 变量名（如 "$DIMASZ"）
 * @param def 默认值
 *
 * @return 变量值，如果变量不存在则返回默认值。
 */
int RS_Entity::getGraphicVariableInt(const QString& key, int def) const{
    RS_Graphic* graphic = getGraphic();
    int ret=def;
    if (graphic) {
        ret = graphic->getVariableInt(key, def);
    }
    return ret;
}



/**
 * 安全地返回指定变量的字符串值。
 *
 * @param key 变量名（如 "$DIMASZ"）
 * @param def 默认值
 *
 * @return 变量值，如果变量不存在则返回默认值。
 */
QString RS_Entity::getGraphicVariableString(const QString& key,
        const QString&  def) const
{
    RS_Graphic* graphic = getGraphic();
    QString ret=def;
    if (graphic) {
        ret = graphic->getVariableString(key, def);
    }
    return ret;
}



/**
 * @return 父 Graphic 所使用的单位，如果没有父 Graphic 则返回 None。
 */
RS2::Unit RS_Entity::getGraphicUnit() const
{
    RS_Graphic* graphic = getGraphic();
    RS2::Unit ret = RS2::None;
    if (graphic) {
        ret = graphic->getUnit();
    }
    return ret;
}



/**
 * 返回指向此实体所在图层的指针或 nullptr。
 *
 * @param resolve true: 如果图层为 ByBlock，则返回该实体所在块中的图层。
 *               false: 返回实体本身的图层。
 *
 * @return 指向此实体所在图层的指针。
 * 如果图层设置为 nullptr，则返回下一个 parent 中非 nullptr 的图层。
 * 如果所有 parent 的图层都是 nullptr，则返回 nullptr。
 */
RS_Layer* RS_Entity::getLayer(bool resolve) const {
    if (resolve) {
        // we have no layer but a parent that might have one.
        // return parent's layer instead:
        if (!layer /*|| layer->getName()=="ByBlock"*/) {
            if (parent) {
                return parent->getLayer(true);
            } else {
                return nullptr;
            }
        }
    }

    // return our layer. might still be nullptr:
    return layer;
}



/**
 * 将此实体的图层设置为指定名称的图层。
 */
void RS_Entity::setLayer(const QString& name) {
    RS_Graphic* graphic = getGraphic();
    if (graphic) {
        layer = graphic->findLayer(name);
    } else {
        layer = nullptr;
    }
}



/**
 * 将此实体的图层设置为指定的图层对象。
 */
void RS_Entity::setLayer(RS_Layer* l) {
    layer = l;
}



/**
 * 将此实体的图层设置为该实体所属 Graphic 的当前活动图层。
 * 如果此实体（及其所有父级）都不在 Graphic 中，则将图层设置为 nullptr。
 */
void RS_Entity::setLayerToActive() {
    RS_Graphic* graphic = getGraphic();

    if (graphic) {
        layer = graphic->getActiveLayer();
    } else {
        layer = nullptr;
    }
}



/**
 * 获取绘制此实体所需的笔属性。
 * 如果标志位相应设置，属性也可以来自该实体所在的图层。
 *
 * @param resolve true: 将笔属性解析为可绘制的笔（例如来自图层或父级的笔）。
 *         false: 不解析，返回笔属性（可能是 ByLayer、ByBlock 等）。
 *
 * @return 此实体的笔属性。
 */
RS_Pen RS_Entity::getPen(bool resolve) const {

    if (!resolve) {
        return pen;
    } else {

        RS_Pen p = pen;
        RS_Layer* l = getLayer(true);

        // use parental attributes (e.g. vertex of a polyline, block
        // entities when they are drawn in block documents):
        if (parent) {
            //if pen is invalid gets all from parent
            if (!p.isValid() ) {
                p = parent->getPen();
            }
            //pen is valid, verify byBlock parts
            RS_EntityContainer* ep = parent;
            //If parent is byblock check parent.parent (nested blocks)
            while (p.getColor().isByBlock()){
                if (ep) {
                    p.setColor(parent->getPen().getColor());
                    ep = ep->parent;
                } else
                    break;
            }
            ep = parent;
            while (p.getWidth()==RS2::WidthByBlock){
                if (ep) {
                    p.setWidth(parent->getPen().getWidth());
                    ep = ep->parent;
                } else
                    break;
            }
            ep = parent;
            while (p.getLineType()==RS2::LineByBlock){
                if (ep) {
                    p.setLineType(parent->getPen().getLineType());
                    ep = ep->parent;
                } else
                    break;
            }
        }
        // check byLayer attributes:
        if (l) {
            // use layer's color:
            if (p.getColor().isByLayer()) {
                p.setColor(l->getPen().getColor());
            }

            // use layer's width:
            if (p.getWidth()==RS2::WidthByLayer) {
                p.setWidth(l->getPen().getWidth());
            }

            // use layer's linetype:
            if (p.getLineType()==RS2::LineByLayer) {
                p.setLineType(l->getPen().getLineType());
            }
            //}
        }

        return p;
    }
}



/**
 * 将此实体的笔属性设置为该实体所属 Graphic 的当前活动笔属性。
 * 如果此实体（及其所有父级）都不在 Graphic 中，则不修改笔属性。
 */
void RS_Entity::setPenToActive() {
    RS_Document* doc = getDocument();
    if (doc) {
        pen = doc->getActivePen();
    } else {
        //RS_DEBUG->print(RS_Debug::D_WARNING, "RS_Entity::setPenToActive(): "
        //                "No document / active pen linked to this entity.");
    }
    //else {
    //   pen = RS_Pen();
    //}
}



/**
 * 拉伸实体在指定范围内的部分。
 * 默认实现：如果实体完全在给定范围内，则整体移动。
 */
void RS_Entity::stretch(const RS_Vector& firstCorner,
                        const RS_Vector& secondCorner,
                        const RS_Vector& offset) {

    //e->calculateBorders();
    if (getMin().isInWindow(firstCorner, secondCorner) &&
            getMax().isInWindow(firstCorner, secondCorner)) {

        move(offset);
    }
}



/**
 * @return 用于缩放线型的因子，考虑当前纸张缩放比例和
 * 线型以毫米为单位存储的事实。
 */
double RS_Entity::getStyleFactor(RS_GraphicView* view) {
    double styleFactor = 1.0;
    if (!view) return styleFactor;


    if (view->isPrinting()==false && view->isDraftMode()) {
        styleFactor = 1.0/view->getFactor().x;
    } else {
        //styleFactor = getStyleFactor();
        // the factor caused by the unit:
        RS2::Unit unit = RS2::None;
        RS_Graphic* g = getGraphic();
        if (g) {
            unit = g->getUnit();
            //double scale = g->getPaperScale();
            styleFactor = RS_Units::convert(1.0, RS2::Millimeter, unit);
            // / scale;
        }

        // the factor caused by the line width:
        if (((int)getPen(true).getWidth())>0) {
            styleFactor *= ((double)getPen(true).getWidth()/100.0);
        } else if (((int)getPen(true).getWidth())==0) {
            styleFactor *= 0.01;
        }
    }

    if (view->isPrinting() || view->isPrintPreview() || view->isDraftMode()==false) {
        RS_Graphic* graphic = getGraphic();
        if (graphic && graphic->getPaperScale()>1.0e-6) {
            styleFactor /= graphic->getPaperScale();
        }
    }

    //RS_DEBUG->print("stylefactor: %f", styleFactor);
    //RS_DEBUG->print("viewfactor: %f", view->getFactor().x);

    if (styleFactor*view->getFactor().x<0.2) {
        styleFactor = -1.0;
    }

    return styleFactor;
}


/**
 * @return 与此实体关联的用户自定义变量，如果未找到则返回 nullptr。
 */
QString RS_Entity::getUserDefVar(const QString& key) const {
    auto it=varList.find(key);
    if(it==varList.end()) return nullptr;
    return varList.at(key);
}

/**
 * 获取与给定法线正交的切点。
 * @return 一条与实体相切且与直线 (*normal) 正交的线上的点。
 */
RS_Vector RS_Entity::getNearestOrthTan(const RS_Vector& /*coord*/,
                    const RS_Line& /*normal*/,
                    bool /*onEntity = false*/) const{
        return RS_Vector(false);
}


/**
 * 向此实体添加用户自定义变量。
 */
void RS_Entity::setUserDefVar(QString key, QString val) {
    varList.insert(std::make_pair(key, val));
}

/**
 * 删除指定键的用户自定义变量。
 */
void RS_Entity::delUserDefVar(QString key) {
    varList.erase(key);
}

/**
 * @return 与此实体关联的所有变量键名的列表。
 */
std::vector<QString> RS_Entity::getAllKeys() const{
    std::vector<QString> ret(0);
    for(auto const& v: varList){
        ret.push_back(v.first);
    }
    return ret;
}

/**
 * 判断实体是否位于构造图层上。
 * 构造图层包含无限长实体，打印时不显示。
 * @param typeCheck 如果为 true，除 Line 外的其他实体类型不计入构造图层判断
 */
bool RS_Entity::isConstruction(bool typeCheck) const{
    if(typeCheck
        &&  getParent()
        &&  rtti() != RS2::EntityLine){
            // do not expand entities on construction layers, except lines
            return false;
    }
    if (layer) return layer->isConstruction();
    return false;
}

/**
 * @return 实体所在图层是否启用了打印。
 */
bool RS_Entity::isPrint(void) const{
    if (nullptr != layer) return layer->isPrint();
    return true;
}

/**
 * 判断实体类型是否可修剪。
 * @return true 对于可修剪的实体类型（Line、Circle、Arc、Ellipse、SplinePoints）
 */
bool RS_Entity::trimmable() const
{
    switch(rtti()){
    case RS2::EntityArc:
    case RS2::EntityCircle:
    case RS2::EntityEllipse:
    case RS2::EntityLine:
    case RS2::EntitySplinePoints:
        return true;
    default:
        return false;
    }
}

/**
 * 获取实体的参考点集合。
 * @return 参考点列表，默认返回空集
 */
RS_VectorSolutions RS_Entity::getRefPoints() const
{
    return RS_VectorSolutions();
}

/**
 * 获取离给定坐标最近的参考点。
 */
RS_Vector RS_Entity::getNearestRef(const RS_Vector& coord,
                                   double* dist) const{
    RS_VectorSolutions const&& s = getRefPoints();

    return s.getClosest(coord, dist);
}

/**
 * 获取被选中的实体的最近参考点。
 * 如果实体未被选中，返回无效向量。
 */
RS_Vector RS_Entity::getNearestSelectedRef(const RS_Vector& coord,
                                           double* dist) const{
    if (isSelected()) {
        return getNearestRef(coord, dist);
    }
    else {
        return RS_Vector(false);
    }
}

/**
 * 将元素数据输出到 stdout。
 * 用于调试输出实体信息，包括 ID、标志位、图层、笔属性和变量列表。
 */
std::ostream& operator << (std::ostream& os, RS_Entity& e) {
    //os << "Warning: Virtual entity!\n";
    //return os;

    os << " {Entity id: " << e.id;
    if (e.parent) {
        os << " | parent id: " << e.parent->getId() << "\n";
    } else {
        os << " | no parent\n";
    }

    os << " flags: " << (e.getFlag(RS2::FlagVisible) ? "RS2::FlagVisible" : "");
    os << (e.getFlag(RS2::FlagUndone) ? " RS2::FlagUndone" : "");
    os << (e.getFlag(RS2::FlagSelected) ? " RS2::FlagSelected" : "");
    os << "\n";

    if (!e.layer) {
        os << " layer: nullptr ";
    } else {
        os << " layer: " << e.layer->getName().toLatin1().data() << " ";
        os << " layer address: " << e.layer << " ";
    }

    os << e.pen << "\n";

        os << "variable list:\n";
    for(auto const& v: e.varList){
        os << v.first.toLatin1().data()<< ": "
           << v.second.toLatin1().data()
               << ", ";
    }

    // There should be a better way then this...
    switch(e.rtti()) {
    case RS2::EntityPoint:
        os << (RS_Point&)e;
        break;

    case RS2::EntityLine:
        os << (RS_Line&)e;
        break;

    case RS2::EntityPolyline:
        os << (RS_Polyline&)e;
        break;

    case RS2::EntityArc:
        os << (RS_Arc&)e;
        break;

    case RS2::EntityCircle:
        os << (RS_Circle&)e;
        break;

    case RS2::EntityEllipse:
        os << (RS_Ellipse&)e;
        break;

    case RS2::EntityInsert:
        os << (RS_Insert&)e;
        break;

    case RS2::EntityMText:
        os << (RS_MText&)e;
        break;

    case RS2::EntityText:
        os << (RS_Text&)e;
        break;

    default:
        os << "Unknown Entity";
        break;
    }
    os << "}\n\n";

    return os;
}
