#pragma once

#include <rs_vector.h>
#include <rs_debug.h>

class RS_Document;
class RS_GraphicView;
class RS_Vector;

/**
 * @brief 实体移动工具类
 *
 * 提供选中的 CAD 实体的移动操作：
 * - 按方向移动（上/下/左/右）
 * - 移动到指定坐标
 * - 计算选中实体中心点
 *
 * 使用方式：
 *   int count = EntityMover::moveSelected(doc, view, RS_Vector(0, 10));
 */
class EntityMover
{
public:
    /// 移动选中的实体（方向偏移），返回移动数量
    static int moveSelected(RS_Document* doc, RS_GraphicView* view,
        const RS_Vector& offset, const char* debugName = nullptr);

    /// 移动选中的实体到指定坐标，返回移动数量
    static int moveToPosition(RS_Document* doc, RS_GraphicView* view,
        const RS_Vector& targetPos, const char* debugName = nullptr);

    /// 计算选中实体的中心点
    static RS_Vector calculateSelectionCenter(RS_Document* doc);

    /// 旋转选中的实体（绕中心点旋转角度），返回旋转数量
    static int rotateSelected(RS_Document* doc, RS_GraphicView* view,
        double angle, const char* debugName = nullptr);
};
