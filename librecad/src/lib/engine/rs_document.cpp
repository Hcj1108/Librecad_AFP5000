/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2018 A. Stebich (librecad@mail.lordofbikes.de)
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


#include "rs_document.h"
#include "rs_debug.h"


#include "rs_line.h"
#include "rs_polyline.h"
#include "rs_arc.h"
#include "rs_circle.h"

#include <iostream>
#include <stack>



/**
 * Constructor.
 *
 * @param parent Parent of the document. Often that's NULL but
 *        for blocks it's the blocklist.
 */
RS_Document::RS_Document(RS_EntityContainer* parent)
        : RS_EntityContainer(parent), RS_Undo() {

    RS_DEBUG->print("RS_Document::RS_Document() ");

    filename = "";
    autosaveFilename = "Unnamed";
	formatType = RS2::FormatUnknown;
    setModified(false);
    RS_Color col(RS2::FlagByLayer);
    activePen = RS_Pen(col, RS2::WidthByLayer, RS2::LineByLayer);

    gv = NULL;//used to read/save current view

    //showAllPointsInMessageBox();


}

/**
 * Overwritten to set modified flag when undo cycle finished with undoable(s).
 */
void RS_Document::endUndoCycle()
{
    if (hasUndoable()) {
        setModified(true);
    }

    RS_Undo::endUndoCycle();
}




std::vector<std::vector<RS_Vector>> RS_Document::getAllEntityPathPoints(bool separateCharacters) const
{
    std::vector<std::vector<RS_Vector>> allPoints;

    // 使用迭代器模式遍历实体
    for (RS_Entity* e = const_cast<RS_Document*>(this)->firstEntity(RS2::ResolveNone);
        e != nullptr;
        e = const_cast<RS_Document*>(this)->nextEntity(RS2::ResolveNone)) {

        processEntityRecursive(e, allPoints, separateCharacters, 0);
    }

    return allPoints;
}

void RS_Document::processEntityRecursive(RS_Entity* e,
    std::vector<std::vector<RS_Vector>>& allPoints,
    bool separateCharacters,
    int level) const
{
    if (!e || e->isUndone() || !e->isVisible()) {
        return;
    }

    std::string indent(level * 2, ' ');
    std::cout << indent << "处理实体类型: " << e->rtti()
        << " (层级 " << level << ")" << std::endl;

    // 处理 MText 实体
    if (e->rtti() == RS2::EntityMText) {
        RS_MText* mtext = dynamic_cast<RS_MText*>(e);
        if (mtext) {
            processMTextEntity(mtext, allPoints, separateCharacters, level);
        }
        return;
    }

    // 处理容器
    if (e->isContainer()) {
        RS_EntityContainer* container = dynamic_cast<RS_EntityContainer*>(e);
        if (container) {
            for (RS_Entity* child = container->firstEntity(RS2::ResolveNone);
                child != nullptr;
                child = container->nextEntity(RS2::ResolveNone)) {
                processEntityRecursive(child, allPoints, separateCharacters, level + 1);
            }
        }
        return;
    }

    // 处理普通实体
    std::vector<RS_Vector> points = e->getPathPoints();
    if (!points.empty()) {
        std::cout << indent << "  添加实体类型路径点: "
            << e->rtti() << std::endl;
        allPoints.push_back(std::move(points));
    }
}

void RS_Document::processMTextEntity(RS_MText* mtext,
    std::vector<std::vector<RS_Vector>>& allPoints,
    bool separateCharacters,
    int level) const
{
    if (!mtext || !mtext->isContainer()) {
        return;
    }

    std::cout << std::string(level * 2, ' ') << "  MText包含子对象:" << std::endl;

    // 收集所有文本行的字符
    std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>> allCharPathsWithCenter;
    for (RS_Entity* child = mtext->firstEntity(RS2::ResolveNone);
        child != nullptr;
        child = mtext->nextEntity(RS2::ResolveNone)) {

        if (!child || child->isUndone() || !child->isVisible()) {
            continue;
        }

        if (child->rtti() == 1) {  // 文本行
            RS_EntityContainer* type1Container = dynamic_cast<RS_EntityContainer*>(child);
            if (type1Container) {
                if (separateCharacters) {
                    collectCharactersFromLine(type1Container, allCharPathsWithCenter, level);
                }
                else {
                    processTextSegmentAsWhole(type1Container, allPoints, level);
                }
            }
        }
        else {
            processEntityRecursive(child, allPoints, separateCharacters, level + 1);
        }
    }

    if (separateCharacters && !allCharPathsWithCenter.empty()) {
        //std::cout << "\n" << std::string(level * 2, ' ') << "=== 排序字符 ===" << std::endl;

        //// 打印排序前的字符中心坐标
        //std::cout << std::string(level * 2, ' ') << "排序前：" << std::endl;
        //for (size_t i = 0; i < allCharPathsWithCenter.size(); ++i) {
        //    std::cout << std::string(level * 2, ' ')
        //        << "字符 " << i + 1 << " : ("
        //        << allCharPathsWithCenter[i].second.x << ", "
        //        << allCharPathsWithCenter[i].second.y << ")" << std::endl;
        //}

        // 排序字符
        auto sortedCharacters = sortCharactersByXYDescending(allCharPathsWithCenter);

        //// 打印排序后的字符中心坐标
        //std::cout << std::string(level * 2, ' ') << "排序后：" << std::endl;
        //for (size_t i = 0; i < sortedCharacters.size(); ++i) {
        //    std::cout << std::string(level * 2, ' ')
        //        << "字符 " << i + 1 << " : ("
        //        << sortedCharacters[i].second.x << ", "
        //        << sortedCharacters[i].second.y << ")" << std::endl;
        //}

        // 将排序后的字符路径添加到结果
        for (const auto& charPathWithCenter : sortedCharacters) {
            allPoints.push_back(charPathWithCenter.first);
        }
    }
}

// 排序函数：按X从大到小，X相同按Y从大到小
std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>>
RS_Document::sortCharactersByXYDescending(
    const std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>>& characters) const
{
    std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>> sorted = characters;

    const double COLUMN_TOLERANCE = 350.0;  // 定义X坐标相差不超过100为同一列

    std::sort(sorted.begin(), sorted.end(),
        [COLUMN_TOLERANCE](const std::pair<std::vector<RS_Vector>, RS_Vector>& a,
            const std::pair<std::vector<RS_Vector>, RS_Vector>& b) {
                const RS_Vector& centerA = a.second;
                const RS_Vector& centerB = b.second;

                // 1. 如果 X 相差不超过 COLUMN_TOLERANCE，优先按 Y 从大到小排序
                if (std::abs(centerA.x - centerB.x) <= COLUMN_TOLERANCE) {
                    return centerA.y > centerB.y;  // X接近时按Y排序
                }

                // 2. 否则，按 X 从大到小排序
                if (centerA.x != centerB.x) {
                    return centerA.x > centerB.x;  // X大的排前面
                }

                // 3. 如果 X 相同，则按 Y 从大到小排序
                return centerA.y > centerB.y;  // Y大的排前面
        });

    return sorted;
}

// 从文本行收集字符
void RS_Document::collectCharactersFromLine(RS_EntityContainer* type1Container,
    std::vector<std::pair<std::vector<RS_Vector>, RS_Vector>>& allCharPathsWithCenter,
    int level) const
{
    for (RS_Entity* type1Child = type1Container->firstEntity(RS2::ResolveNone);
        type1Child != nullptr;
        type1Child = type1Container->nextEntity(RS2::ResolveNone)) {

        if (!type1Child || type1Child->isUndone() || !type1Child->isVisible()) {
            continue;
        }

        if (type1Child->rtti() == 4) {  // 字符
            RS_EntityContainer* charContainer = dynamic_cast<RS_EntityContainer*>(type1Child);
            if (charContainer) {
                std::vector<RS_Vector> charPath = extractCharContainerPaths(charContainer);
                //  // 两两交换点
                //for (size_t i = 0; i + 1 < charPath.size(); i += 2) {
                //    std::swap(charPath[i], charPath[i + 1]);
                //}
              
                RS_Vector center = calculatePathCenter(charPath);
                if (!charPath.empty()) {
                    allCharPathsWithCenter.push_back({ std::move(charPath), center });
                }
            }
        }
    }
}

// 提取字符容器中的路径点
std::vector<RS_Vector> RS_Document::extractCharContainerPaths(RS_EntityContainer* charContainer) const
{
    std::vector<RS_Vector> charPath;
    if (!charContainer) return charPath;

    std::function<void(RS_EntityContainer*)> extractPaths = [&](RS_EntityContainer* container) {
        for (RS_Entity* subEntity = container->firstEntity(RS2::ResolveNone);
            subEntity != nullptr;
            subEntity = container->nextEntity(RS2::ResolveNone)) {

            if (!subEntity || subEntity->isUndone() || !subEntity->isVisible()) {
                continue;
            }

            if (subEntity->isContainer()) {
                RS_EntityContainer* subContainer = dynamic_cast<RS_EntityContainer*>(subEntity);
                if (subContainer) {
                    extractPaths(subContainer);
                }
            }
            else {

                std::vector<RS_Vector> entityPoints = subEntity->getPathPoints();
                charPath.insert(charPath.end(), entityPoints.begin(), entityPoints.end());
            }
        }
        };

    extractPaths(charContainer);
    return charPath;
}

// 计算路径中心
RS_Vector RS_Document::calculatePathCenter(const std::vector<RS_Vector>& path) const
{
    if (path.empty()) {
        return RS_Vector(0, 0);
    }

    double minX = path[0].x, maxX = path[0].x;
    double minY = path[0].y, maxY = path[0].y;

    for (const RS_Vector& pt : path) {
        if (pt.x < minX) minX = pt.x;
        if (pt.x > maxX) maxX = pt.x;
        if (pt.y < minY) minY = pt.y;
        if (pt.y > maxY) maxY = pt.y;
    }

    return RS_Vector((minX + maxX) / 2, (minY + maxY) / 2);
}
// 文本段整体处理（生产版本）
void RS_Document::processTextSegmentAsWhole(RS_EntityContainer* type1Container,
    std::vector<std::vector<RS_Vector>>& allPoints,
    int level) const
{
    std::vector<RS_Vector> segmentPoints;

    // 收集所有字符的点
    for (RS_Entity* type1Child = type1Container->firstEntity(RS2::ResolveNone);
        type1Child != nullptr;
        type1Child = type1Container->nextEntity(RS2::ResolveNone)) {

        if (!type1Child || type1Child->isUndone() || !type1Child->isVisible()) {
            continue;
        }

        // 处理字符容器
        if (type1Child->rtti() == RS2::EntityInsert) {  // 或适当的类型
            RS_EntityContainer* charContainer = dynamic_cast<RS_EntityContainer*>(type1Child);
            if (charContainer) {
                std::vector<RS_Vector> charPath = extractCharContainerPaths(charContainer);
                if (!charPath.empty()) {
                    segmentPoints.insert(segmentPoints.end(), charPath.begin(), charPath.end());
                }
            }
        }
    }

    // 添加整个文本段
    if (!segmentPoints.empty()) {
        allPoints.push_back(std::move(segmentPoints));
    }
}