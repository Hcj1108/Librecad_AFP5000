#include "EntityMover.h"
#include "rs_document.h"
#include "rs_graphicview.h"
#include "rs_entity.h"

/**
 * @brief 移动选中的实体（方向偏移）
 * @param doc   CAD 文档指针
 * @param view  CAD 图形视图指针
 * @param offset 移动偏移量（上/下/左/右）
 * @param debugName 调试日志中的函数名
 * @return 实际移动的实体数量
 */
int EntityMover::moveSelected(RS_Document* doc, RS_GraphicView* view,
    const RS_Vector& offset, const char* debugName)
{
    if (!doc || !view) return 0;

    doc->startUndoCycle();

    int movedCount = 0;
    for (RS_Entity* e = doc->firstEntity(RS2::ResolveNone);
        e != nullptr;
        e = doc->nextEntity(RS2::ResolveNone))
    {
        if (e && e->isVisible() && !e->isLocked() && e->isSelected()) {
            e->move(offset);
            e->update();
            e->setSelected(true);
            movedCount++;
        }
    }

    doc->endUndoCycle();

    if (movedCount > 0) {
        view->redraw();
        if (debugName) {
            RS_DEBUG->print(RS_Debug::D_DEBUGGING,
                "%s: Moved %d entities", debugName, movedCount);
        }
    } else if (debugName) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
            "%s: No selected and movable entities found", debugName);
    }

    return movedCount;
}

/**
 * @brief 移动选中的实体到指定坐标
 * @param doc   CAD 文档指针
 * @param view  CAD 图形视图指针
 * @param targetPos 目标坐标（例如 33000, 33000）
 * @param debugName 调试日志中的函数名
 * @return 实际移动的实体数量
 */
int EntityMover::moveToPosition(RS_Document* doc, RS_GraphicView* view,
    const RS_Vector& targetPos, const char* debugName)
{
    if (!doc || !view) return 0;

    doc->startUndoCycle();

    int movedCount = 0;
    for (RS_Entity* e = doc->firstEntity(RS2::ResolveNone);
        e != nullptr;
        e = doc->nextEntity(RS2::ResolveNone))
    {
        if (e && e->isVisible() && !e->isLocked() && e->isSelected()) {
            RS_Vector min = e->getMin();
            RS_Vector max = e->getMax();
            RS_Vector center = (min + max) * 0.5;

            if (center.valid) {
                RS_Vector offset = targetPos - center;
                e->move(offset);
                e->update();
                movedCount++;
            }
        }
    }

    doc->endUndoCycle();

    if (movedCount > 0) {
        view->redraw();
        if (debugName) {
            RS_DEBUG->print(RS_Debug::D_DEBUGGING,
                "%s: Moved %d entities to (%.0f, %.0f)",
                debugName, movedCount, targetPos.x, targetPos.y);
        }
    } else if (debugName) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
            "%s: No selected and movable entities found", debugName);
    }

    return movedCount;
}

/**
 * @brief 计算选中实体的中心点
 * @param doc CAD 文档指针
 * @return 选中实体的中心点坐标（没有选中则返回无效向量）
 */
RS_Vector EntityMover::calculateSelectionCenter(RS_Document* doc)
{
    if (!doc) return RS_Vector(false);

    RS_Vector center(0, 0);
    int count = 0;

    for (RS_Entity* e = doc->firstEntity(RS2::ResolveAll);
        e != nullptr;
        e = doc->nextEntity(RS2::ResolveAll))
    {
        if (e && e->isSelected() && e->isVisible() && !e->isLocked()) {
            RS_Vector min = e->getMin();
            RS_Vector max = e->getMax();
            center += (min + max) / 2.0;
            count++;
        }
    }

    return count > 0 ? center / count : RS_Vector(false);
}

/**
 * @brief 旋转选中的实体（绕中心点旋转角度）
 * @param doc   CAD 文档指针
 * @param view  CAD 图形视图指针
 * @param angle 旋转角度（度），正值为顺时针
 * @param debugName 调试日志中的函数名
 * @return 实际旋转的实体数量
 */
int EntityMover::rotateSelected(RS_Document* doc, RS_GraphicView* view,
    double angle, const char* debugName)
{
    if (!doc || !view) return 0;

    RS_Vector center = calculateSelectionCenter(doc);
    if (!center.valid) return 0;

    doc->startUndoCycle();

    int rotatedCount = 0;
    for (RS_Entity* e = doc->firstEntity(RS2::ResolveNone);
        e != nullptr;
        e = doc->nextEntity(RS2::ResolveNone))
    {
        if (e && e->isSelected() && e->isVisible() && !e->isLocked()) {
            e->rotate(center, angle);
            e->update();
            rotatedCount++;
        }
    }

    doc->endUndoCycle();

    if (rotatedCount > 0) {
        view->redraw();
        if (debugName) {
            RS_DEBUG->print(RS_Debug::D_DEBUGGING,
                "%s: Rotated %d entities around (%.2f, %.2f)",
                debugName, rotatedCount, center.x, center.y);
        }
    } else if (debugName) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
            "%s: No rotatable entities found", debugName);
    }

    return rotatedCount;
}
