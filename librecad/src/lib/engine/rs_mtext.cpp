/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
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
#include"FontSettingsSingleton.h"
#include"PlaceholderPositionManager.h"
#include<iostream>
#include<cmath>
#include "rs_font.h"
#include "rs_mtext.h"

#include "rs_fontlist.h"
#include "rs_insert.h"
#include "rs_math.h"
#include "rs_debug.h"
#include "rs_graphicview.h"
#include "rs_painter.h"
#include <QDebug>


/**
*   C++ 类 RS_MTextData 的构造函数,它的主要作用是在创建一个
*   新的多行文本（MText）实体对象时，对它进行初始化设置。
*/
RS_MTextData::RS_MTextData(const RS_Vector& _insertionPoint,
    double _height,
    double _width,
    VAlign _valign,
    HAlign _halign,
    MTextDrawingDirection _drawingDirection,
    MTextLineSpacingStyle _lineSpacingStyle,
    double _lineSpacingFactor,
    const QString& _text,
    const QString& _style,
    double _angle,
    RS2::UpdateMode _updateMode) :
    insertionPoint(_insertionPoint)
    , height(_height)
    , width(_width)
    , valign(_valign)
    , halign(_halign)
    , drawingDirection(_drawingDirection)
    , lineSpacingStyle(_lineSpacingStyle)
    , lineSpacingFactor(_lineSpacingFactor)
    , text(_text)
    , style(_style)
    , angle(_angle)
    , updateMode(_updateMode),

    hasDynamicPlaceholders(false) // 默认无占位符
{
    //// 自动检测占位符
    //if (text.contains("hh:mm:ss")) {
    //    hasDynamicPlaceholders = true;
    //    timePlaceholderPos = text.indexOf("hh:mm:ss");
    //    qDebug() << "RS_MTextData: timePlaceholderPos 'hh:mm:ss' is  " << timePlaceholderPos;
    //    qDebug() << "RS_MTextData: Detected dynamic placeholder 'hh:mm:ss' in text.";
    //}
}
/*
*  运算符重载，具体来说是重载了输出流运算符 <<,它的核心作用是：让 RS_MTextData 这个自定义的类对象，
*  能够像 int、double 或 string 一样，直接被 std::cout 打印出来。
*/
std::ostream& operator << (std::ostream& os, const RS_MTextData& td) {
	os << "("
	   <<td.insertionPoint<<','
	  <<td.height<<','
	 <<td.width<<','
	<<td.valign<<','
	<<td.halign<<','
	<<td.drawingDirection<<','
	<<td.lineSpacingStyle<<','
	<<td.lineSpacingFactor<<','
	<<td.text.toLatin1().data() <<','
	<<td.style.toLatin1().data()<<','
	<<td.angle<<','
	<<td.updateMode<<','
	<<")";
	return os;
}

/**
 *  创建一个新的多行文本实体（Entity）时，完成初始化设置，
 *  并再次对文本中的动态占位符进行识别和检测
 */
RS_MText::RS_MText(RS_EntityContainer* parent,
                 const RS_MTextData& d)
        : RS_EntityContainer(parent), data(d) {//在对象被创建的同时，直接对成员变量进行初始化

    usedTextHeight = 0.0;
    usedTextWidth = 0.0;
    setText(data.text);
    if (data.text.contains("hh:mm:ss")) {
        data.timePlaceholderPos = data.text.indexOf("hh:mm:ss");
        qDebug() << "RS_MTextData: timePlaceholderPos 'hh:mm:ss' is  " << data.timePlaceholderPos;
        qDebug() << "RS_MTextData: Detected dynamic placeholder 'hh:mm:ss' in text.";
        data.hasDynamicPlaceholders = true;
    }
    // 新功能使用
}

/*
*  创建当前 RS_MText 对象的一个完整、独立的副本（深拷贝），并返回这个新对象的指针
*/
RS_Entity* RS_MText::clone() const{
	RS_MText* t = new RS_MText(*this);
	t->setOwner(isOwner());
	t->initId();
	t->detach();
	return t;
}

/**
 * 为文本实体设置新的文字内容，并自动解析其中嵌入的特殊格式指令
 * 隐形的排版指令它只识别并剥离了以 \A 开头的特殊前缀（例如 \A0;、\A1;）
 * 并将这些代码转换成程序能听懂的垂直对齐属性（底部、居中或顶部）。
 */
void RS_MText::setText(const QString& t) {
    data.text = t;

    // handle some special flags embedded in the text:
    if (data.text.left(4)=="\\A0;") {
        data.text = data.text.mid(4);
        data.valign = RS_MTextData::VABottom;
    } else if (data.text.left(4)=="\\A1;") {
        data.text = data.text.mid(4);
        data.valign = RS_MTextData::VAMiddle;
    } else if (data.text.left(4)=="\\A2;") {
        data.text = data.text.mid(4);
        data.valign = RS_MTextData::VATop;
    }

    if (data.updateMode==RS2::Update) {
        update();
        //calculateBorders();
    }
}



/**
 * 将文本的垂直对齐（valign）和水平对齐（halign）这两个独立的属性，
 * 组合并转换成一个1到9的数字编码。
 * 7 8 9 （对应左上、中上、右上）
 * 4 5 6 （对应左中、正中、右中）
 * 1 2 3 （对应左下、中下、右下）
 */
int RS_MText::getAlignment() {
    if (data.valign==RS_MTextData::VATop) {
        if (data.halign==RS_MTextData::HALeft) {
            return 1;
        } else if (data.halign==RS_MTextData::HACenter) {
            return 2;
        } else if (data.halign==RS_MTextData::HARight) {
            return 3;
        }
    } else if (data.valign==RS_MTextData::VAMiddle) {
        if (data.halign==RS_MTextData::HALeft) {
            return 4;
        } else if (data.halign==RS_MTextData::HACenter) {
            return 5;
        } else if (data.halign==RS_MTextData::HARight) {
            return 6;
        }
    } else if (data.valign==RS_MTextData::VABottom) {
        if (data.halign==RS_MTextData::HALeft) {
            return 7;
        } else if (data.halign==RS_MTextData::HACenter) {
            return 8;
        } else if (data.halign==RS_MTextData::HARight) {
            return 9;
        }
    }

    return 1;
}



/**
 * 接收一个 1到9的数字编码，通过数学运算将其“翻译”
 * 回对应的水平对齐（halign）和垂直对齐（valign）属性。
 */
void RS_MText::setAlignment(int a) {
    switch (a%3) {
    default:
    case 1:
        data.halign = RS_MTextData::HALeft;
        break;
    case 2:
        data.halign = RS_MTextData::HACenter;
        break;
    case 0:
        data.halign = RS_MTextData::HARight;
        break;
    }

    switch ((int)ceil(a/3.0)) {
    default:
    case 1:
        data.valign = RS_MTextData::VATop;
        break;
    case 2:
        data.valign = RS_MTextData::VAMiddle;
        break;
    case 3:
        data.valign = RS_MTextData::VABottom;
        break;
    }

}



/**
 * 计算当前文本中一共有多少行
 */
int RS_MText::getNumberOfLines() {
    int c=1;

    for (int i=0; i<(int)data.text.length(); ++i) {
        if (data.text.at(i).unicode()==0x0A) {
            c++;
        }
    }
    return c;
}




/**
 * 更新此文本的插入项（字母）。当
 * 文本或其数据、位置、对齐方式等发生改变时调用此方法。
 * 此方法同时也会更新 usedTextWidth / usedTextHeight 属性。
 */
void RS_MText::update()
{
    placeholderCharNames.clear();//清除占位符字符名缓存
	data.timePlaceholderPositions.clear();//清除时间占位符位置缓存
    RS_DEBUG->print("RS_MText::update");

    clear();// // 清空当前所有图形实体

    // 如果对象状态为“已撤销”，则不再继续处理
    if (isUndone()) {
        return;
    }
    // 重置文本总宽高
    usedTextWidth = 0.0;
    usedTextHeight = 0.0;

    // 根据文本样式获取字体对象
    RS_Font* font {RS_FONTLIST->requestFont( data.style)};

    // 如果找不到字体，直接返回
    if (nullptr == font) {
        return;
    }
    // 初始化第一个字符的相对位置（Y轴向下偏移9个单位）
    RS_Vector letterPos {RS_Vector( 0.0, -9.0)};
    // 获取字体定义的字符间距
    RS_Vector letterSpace {RS_Vector( font->getLetterSpacing(), 0.0)};
    // 获取单词间距
    RS_Vector space {RS_Vector( font->getWordSpacing(), 0.0)};//空格补偿间距
    // 行计数器，用于计算行间位置
	int lineCounter{ 0 };

    // 创建一个容器来临时存储当前正在构建的这一行的所有字符实体
    // 这样便于之后对整行进行统一操作（如对齐、移动）
    RS_EntityContainer* oneLine {new RS_EntityContainer(this)};

    // 字符处理循环前，创建一个列表用于临时存储动态占位符相关的字符实体
    QList<RS_Insert*> placeholderLetters;  

    // 开始遍历文本中的每一个字符，处理占字符
    for (int i = 0; i < static_cast<int>(data.text.length()); ++i) {
       
     
        // 标记当前字符是否已被处理
        bool handled {false};

        // 根据当前字符的 Unicode 码点进行分类处理
        switch (data.text.at(i).unicode()) {
        case 0x0A://换行符'\n'
        {   

            // 创建一个空的插入实体来表示换行
            RS_InsertData d("",  // 空字符串
                letterPos,
                RS_Vector(1.0, 1.0),
                0.0,
                1,
                1,
                RS_Vector(0.0, 0.0),
                nullptr,  // 不使用字体列表
                RS2::NoUpdate);
            RS_Insert* newlineEntity = new RS_Insert(oneLine, d);
            newlineEntity->setPen(RS_Pen(RS2::FlagInvalid));
            newlineEntity->setLayer(nullptr);
            newlineEntity->update();
            newlineEntity->forcedCalculateBorders();
            //将新创建的“空插入实体”（newlineEntity）添加到当前行的实体容器（oneLine）中
            oneLine->addEntity(newlineEntity);

            // 1. 调用 updateAddLine 处理当前行- 应用对齐方式- 计算并存储到主容器- 行计数器加一
            updateAddLine(oneLine, lineCounter++);
            // 2. 创建新的容器用于下一行
            oneLine = new RS_EntityContainer(this);
            // 3. 重置下一行的起始相对位置
            letterPos = RS_Vector(0.0, -9.0);
            break;
        }
        case 0x20:// 空格符 ' '
        {
            // 创建一个空的插入实体来表示空格
            RS_InsertData d("",  // 空字符串
                letterPos,
                RS_Vector(1.0, 1.0),
                0.0,
                1,
                1,
                RS_Vector(0.0, 0.0),
                nullptr,  // 不使用字体列表
                RS2::NoUpdate);

            RS_Insert* spaceEntity = new RS_Insert(oneLine, d);
            spaceEntity->setPen(RS_Pen(RS2::FlagInvalid));
            spaceEntity->setLayer(nullptr);
            spaceEntity->update();
            spaceEntity->forcedCalculateBorders();
            // 将空格实体添加到当前行容器中
            oneLine->addEntity(spaceEntity);
            // 移动下一个字符的位置：加上单词间距和用户定义的字间距补偿
            letterPos += space;
            //增加字间距
            letterPos.x += data.wordSpacing;
            break;
        }
        case 0x5C: {// 反斜杠 '\'，表示特殊控制码开始
            // code (e.g. \S, \P, ..)
            ++i;
            if (static_cast<int>(data.text.length()) <= i) {
                continue;
            }
            int ch {data.text.at(i).unicode()};
            switch (ch) {
            case 'P':
                updateAddLine( oneLine, lineCounter++);
                oneLine = new RS_EntityContainer(this);
                letterPos = RS_Vector( 0.0, -9.0);
                handled = true;
                break;

            case 'f':
            case 'F': {
                //font change
                // \f{symbol} changes font to symbol
                // \f{} sets font to standard
                ++i;
                if ('{' != data.text.at(i).unicode()) {
                    --i;
                    continue;
                }

                int j {data.text.indexOf( '}', i)};
                if (j > i) {
                    QString fontName;
                    if (i + 1 == j) {
                        fontName = "standard";
                    }
                    else {
                        fontName = data.text.mid( i + 1, j - i - 1);
                    }

                    RS_Font* fontNew {RS_FONTLIST->requestFont( fontName)};
                    if (nullptr != fontNew) {
                        font = fontNew;
                    }
                    if (nullptr == font) {
                        font = RS_FONTLIST->requestFont( "standard");
                    }
                    i = j;
                }
                continue;
            } // inner case 'f','F'

            case 'S': {
                QString upperText;
                QString lowerText;

                // get upper string:
                ++i;
                while (static_cast<int>(data.text.length()) > i
                       && data.text.at(i).unicode()!='^'
                       && data.text.at(i).unicode()!='\\') {
                    upperText += data.text.at(i);
                    ++i;
                }

                ++i;
                if (static_cast<int>(data.text.length()) > i
                        && '^' == data.text.at(i - 1).unicode()
                        && ' ' == data.text.at(i).unicode() ) {
                    ++i;
                }

                // 解析下标部分
                while (static_cast<int>(data.text.length()) > i
                       && ';' != data.text.at(i).unicode()) {
                    lowerText += data.text.at(i);
                    ++i;
                }
                // --- 创建上标 MText 实体 ---
                double upperWidth {0.0};
                if (! upperText.isEmpty()) {
                    RS_MText* upper { new RS_MText( oneLine,
                                                    RS_MTextData( letterPos + RS_Vector( 0.0, 9.0),
                                                                  4.0,
                                                                  100.0,
                                                                  RS_MTextData::VATop,
                                                                  RS_MTextData::HALeft,
                                                                  RS_MTextData::LeftToRight,
                                                                  RS_MTextData::Exact,
                                                                  1.0,
                                                                  upperText,
                                                                  data.style,
                                                                  0.0,
                                                                  RS2::Update)) };
                    upper->setLayer( nullptr);
                    upper->setPen( RS_Pen( RS2::FlagInvalid));
                    upper->calculateBorders();
                    oneLine->addEntity(upper);
                    upperWidth = upper->getSize().x;
                }
                // --- 创建下标 MText 实体 ---
                double lowerWidth {0.0};
                if (! lowerText.isEmpty()) {
                    RS_MText* lower { new RS_MText( oneLine,
                                                    RS_MTextData( letterPos + RS_Vector( 0.0, 4.0),
                                                                  4.0,
                                                                  100.0,
                                                                  RS_MTextData::VATop,
                                                                  RS_MTextData::HALeft,
                                                                  RS_MTextData::LeftToRight,
                                                                  RS_MTextData::Exact,
                                                                  1.0,
                                                                  lowerText,
                                                                  data.style,
                                                                  0.0,
                                                                  RS2::Update)) };
                    lower->setLayer( nullptr);
                    lower->setPen( RS_Pen( RS2::FlagInvalid));
                    lower->calculateBorders();
                    oneLine->addEntity(lower);
                    lowerWidth = lower->getSize().x;
                }
                // --- 更新下一个字符的位置 ---
                // 取上标和下标中最宽的那个作为占用宽度
                if (upperWidth > lowerWidth) {
                    letterPos += RS_Vector( upperWidth, 0.0);
                }
                else {
                    letterPos += RS_Vector( lowerWidth, 0.0);
                }
                letterPos += letterSpace;
                handled = true;

                break;
            } // inner case 'S'

            default:
                --i;
                break;
            } // inner switch (ch)

            if (handled) {
                break;
            }
        } // outer case 0x5C

        /*检查字体中是否有该字符若无则替换为特殊字符(0xfffd)创建RS_Insert实体表示该字符计算字符宽度并更新位置*/
        default: {
            // One Letter:

            // 保存当前字符的原始位置
            RS_Vector originalPos = letterPos;

            QString letterText {QString(data.text.at(i))};//获取一个字符并检查字体支持
            if (nullptr == font->findLetter( letterText))
            {
                RS_DEBUG->print("RS_MText::update: missing font for letter( %s ), replaced it with QChar(0xfffd)",qPrintable( letterText));
                letterText = QChar( 0xfffd);//Unicode 替换字符,用来替换字体缺失的字符
            }

            RS_DEBUG->print("RS_MText::update: insert a letter at pos: %f/%f", letterPos.x, letterPos.y);
            
            
            // 保存当前相对位置（用于后续宽度计算）
            RS_Vector relativePosBefore = letterPos;

            RS_InsertData d( letterText,//文本字符
                             letterPos,//插入位置
				             RS_Vector(data.x_scale, data.y_scale),//缩放因子
                             0,//旋转角度
                             1,
                             1,
                             RS_Vector( 0.0, 0.0),
                             font->getLetterList(),
                             RS2::NoUpdate);

            RS_Insert* letter {new RS_Insert(this, d)};
            RS_Vector letterWidth;
            letter->setPen( RS_Pen( RS2::FlagInvalid));
            letter->setLayer( nullptr);
            letter->update();
            letter->forcedCalculateBorders();

            letterWidth = RS_Vector( letter->getMax().x - letterPos.x, 0.0);
            if (0 > letterWidth.x) {
                letterWidth.x = -letterSpace.x;
            }
            oneLine->addEntity( letter);

            //// 使用updateAddLine中的完整计算逻辑
            //RS_Vector pos = originalPos;
            //// 1. 行位置偏移（来自updateAddLine）
            //double ls = 5.0 / 3.0;
            //pos += RS_Vector(0.0, -9.0 * lineCounter * data.lineSpacingFactor * ls);

            //// 2. 计算当前行的实际宽度（模拟updateAddLine中的逻辑）
            //// 这里需要根据当前行中已处理的字符来计算宽度
            //double currentLineWidth = 0.0;
            //// 遍历当前行容器中的所有实体来计算宽度
            //if (oneLine) {
            //    for (RS_Entity* entity : oneLine->getEntityList()) {
            //        if (RS_Insert* charEntity = dynamic_cast<RS_Insert*>(entity)) {
            //            charEntity->forcedCalculateBorders();
            //            currentLineWidth = std::max(currentLineWidth, charEntity->getMax().x);
            //        }
            //    }
            //}
            //// 加上当前字符的宽度
            //currentLineWidth = std::max(currentLineWidth, letterPos.x + letterWidth.x);

            //RS_Vector textSize = RS_Vector(currentLineWidth, 9.0);

            //// 3. 水平对齐（来自updateAddLine）
            //switch (data.halign) {
            //case RS_MTextData::HACenter:
            //    pos += RS_Vector(-textSize.x / 2.0, 0.0);
            //    break;
            //case RS_MTextData::HARight:
            //    pos += RS_Vector(-textSize.x, 0.0);
            //    break;
            //default:
            //    break;
            //}

            //// 4. 垂直对齐计算（来自updateAddLine）
            //double vSize = getNumberOfLines() * 9.0 * data.lineSpacingFactor * ls
            //    - (9.0 * data.lineSpacingFactor * ls - 9.0);

            //// 5. 垂直对齐应用（来自updateAddLine）
            //switch (data.valign) {
            //case RS_MTextData::VAMiddle:
            //    pos += RS_Vector(0.0, vSize / 2.0);
            //    break;
            //case RS_MTextData::VABottom:
            //    pos += RS_Vector(0.0, vSize);
            //    break;
            //default:
            //    break;
            //}

            //// 6. 缩放（来自updateAddLine）
            //pos = pos.scale(RS_Vector(0.0, 0.0), RS_Vector(data.height / 9.0, data.height / 9.0));

            //// 7. 旋转（来自updateAddLine）
            //pos = pos.rotate(RS_Vector(0.0, 0.0), data.angle);

            //// 8. 最终移动（来自updateAddLine）
            //pos += data.insertionPoint;

            //double scaleFactor = data.height / (9.0 * font->getLineSpacingFactor());
            //RS_Vector charAbsPos;

            /*qDebug() << "Char[" << i << "] (" << data.text.at(i)
                << ") at DOC: (" << pos.x << "," << pos.y << ")";*/
              

            //记录占位符的最终位置
            if (data.hasDynamicPlaceholders &&
                data.timePlaceholderPos != -1 &&
                i >= data.timePlaceholderPos &&
                i < data.timePlaceholderPos + data.timePlaceholderReplacedLength) {
     
                placeholderLetters.append(letter);
            }

            //if (data.hasDynamicPlaceholders)
            //{
            //    //qDebug() << "^***************************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
            //    if (data.timePlaceholderPos != -1&& data.timePlaceholderPos==i){
            //       /* qDebug() << "Char[" << i << "] (" << data.text.at(i)
            //        << ") at DOC: (" << pos.x << "," << pos.y << ")"
            //        << " REL: (" << letterPos.x << "," << letterPos.y << ")";*/

            //        data.insertionPoint_timePlace = pos;
            //   
            //    } 
            //}
           
                
            //qDebug() << "data.lineSpacingFactor:" << data.lineSpacingFactor;


            // --- 更新下一个字符的相对位置 ---
            letterPos += letterWidth; //当前字宽
            letterPos += letterSpace; //字间距(一个空格)
			letterPos.x += data.wordSpacing;// 添加字间距补偿,由用户确定的
          
            break;
        } // outer default
        } // outer switch (data.text.at(i).unicode())

    } // for (i) loop

    // 处理最后一行（因为循环结束后，最后一行还没有被提交给 updateAddLine）
    double tt {updateAddLine( oneLine, lineCounter)};
    if (RS_MTextData::VABottom == data.valign) {
        RS_Vector ot {RS_Vector( 0.0, -tt).rotate( data.angle)};
        RS_EntityContainer::move( ot);
    }


    // 在所有变换完成后记录最终位置
    if (data.hasDynamicPlaceholders) {
        data.timePlaceholderPositions.clear();
        for (RS_Insert* letter : placeholderLetters) {
            data.timePlaceholderPositions.append(letter->getInsertionPoint());
            qDebug() << "**********************************************************";
            qDebug() << "Final placeholder position:" << letter->getInsertionPoint().x
                << letter->getInsertionPoint().y;
        }
        // 新增：从实际实体中读取第一个占位符的位置
        if (!placeholderLetters.isEmpty()) {
            data.insertionPoint_timePlace = placeholderLetters.first()->getInsertionPoint();
        }
    }

    usedTextHeight -= data.height * data.lineSpacingFactor * 5.0 / 3.0 - data.height;
    // 强制重新计算整个 MText 对象的边界框
    forcedCalculateBorders();

    RS_DEBUG->print("RS_MText::update: OK");

    // 将占位符位置同步到全局单例管理器
    PlaceholderPositionManager::getInstance().clear();
    PlaceholderPositionManager::getInstance().setPositions(data.timePlaceholderPositions);
   
  
}


/**
 * updateAddLine 是 update() 函数的核心助手，
 * 专门负责处理已经生成好（包含多个字符实体）的一行文本。
 * @param textLine 里面装着组成这一行的所有字符实体（比如字母、数字等）
 * @param lineCounter 当前是第几行（行号/行索引）。这是一个从 0 开始的整数
 * ，用来告诉函数现在处理的是第 1 行、第 2 行还是第 N 行。
 *
 * @return  distance over the text base-line
 */
double RS_MText::updateAddLine(RS_EntityContainer* textLine, int lineCounter) {
    double ls =5.0/3.0;

    RS_DEBUG->print("RS_MText::updateAddLine: width: %f", textLine->getSize().x);

        //textLine->forcedCalculateBorders();
    //RS_DEBUG->print("RS_MText::updateAddLine: width 2: %f", textLine->getSize().x);

    // Move to correct line position:
    textLine->move(RS_Vector(0.0, -9.0 * lineCounter
                             * data.lineSpacingFactor * ls));

    if( ! RS_EntityContainer::autoUpdateBorders) {
        //only update borders when needed
        textLine->forcedCalculateBorders();
    }
    RS_Vector textSize = textLine->getSize();

        RS_DEBUG->print("RS_MText::updateAddLine: width 2: %f", textSize.x);

    // Horizontal Align:
    switch (data.halign) {
    case RS_MTextData::HACenter:
                RS_DEBUG->print("RS_MText::updateAddLine: move by: %f", -textSize.x/2.0);
        textLine->move(RS_Vector(-textSize.x/2.0, 0.0));
        break;

    case RS_MTextData::HARight:
        textLine->move(RS_Vector(-textSize.x, 0.0));
        break;

    default:
        break;
    }

    // Vertical Align:
    double vSize = getNumberOfLines()*9.0*data.lineSpacingFactor*ls
                   - (9.0*data.lineSpacingFactor*ls - 9.0);

    switch (data.valign) {
    case RS_MTextData::VAMiddle:
        textLine->move(RS_Vector(0.0, vSize/2.0));
        break;

    case RS_MTextData::VABottom:
        textLine->move(RS_Vector(0.0, vSize));
        break;

    default:
        break;
    }

    // Scale:
    textLine->scale(RS_Vector(0.0,0.0),
                    RS_Vector(data.height/9.0, data.height/9.0));

    textLine->forcedCalculateBorders();

    // Update actual text size (before rotating, after scaling!):
    if (textLine->getSize().x>usedTextWidth) {
        usedTextWidth = textLine->getSize().x;
    }

    usedTextHeight += data.height*data.lineSpacingFactor*ls;

    // Gets the distance over text base-line (before rotating, after scaling!):
    double textTail = textLine->getMin().y;

    // Rotate:
    textLine->rotate(RS_Vector(0.0,0.0), data.angle);

    // Move:
    textLine->move(data.insertionPoint);
	
	//输出所有字符的最终位置和边界框信息
    for (RS_Entity* entity : entities) {
        if (RS_EntityContainer* line = dynamic_cast<RS_EntityContainer*>(entity)) {
            // 遍历每行中的字符

            const QList<RS_Entity*>& list = line->getEntityList();
            for (RS_Entity* entity : list) {
                // 处理 entity
            
                if (RS_Insert* letter = dynamic_cast<RS_Insert*>(entity)) {
                    // 获取字符的最终插入点
                    RS_Vector finalPos = letter->getInsertionPoint();

                    // 获取字符的边界框
                    RS_Vector min = letter->getMin();
                    RS_Vector max = letter->getMax();

                    // 获取字符的中心点
                    RS_Vector center = (min + max) / 2.0;

                    // 输出字符信息
                  /* qDebug() << "Character:" << letter->getName()
						<< "Final Position.x:" << finalPos.x
						<< "Center:" << center.x
                        << "Bounds:" << min.x  << "to" << max.x;
                    qDebug() << "Character:" << letter->getName()
                        << "Final Position.y:" << finalPos.y
                        << "Center:" << center.y
                        << "Bounds:" << min.y << "to" << max.y;*/
                }
            }
        }
    }

    textLine->setPen(RS_Pen(RS2::FlagInvalid));
    textLine->setLayer(NULL);
    textLine->forcedCalculateBorders();

    addEntity(textLine);
  
    return textTail;
}

/**
* 获取当前 MText 对象上，距离指定坐标点最近的那个“端点”（即插入点），并计算出具体的距离
*/
RS_Vector RS_MText::getNearestEndpoint(const RS_Vector& coord, double* dist)const {
    if (dist) {
        *dist = data.insertionPoint.distanceTo(coord);
    }
    return data.insertionPoint;
}

/*
* 返回该文本对象的所有参考点（Reference Points）
*/
RS_VectorSolutions RS_MText::getRefPoints() const{
		return RS_VectorSolutions({data.insertionPoint});
}

/**
* 将整个 MText 对象（包括文本内容和定位点）在图纸上移动指定的偏移量
*/
void RS_MText::move(const RS_Vector& offset) {
    RS_EntityContainer::move(offset);
    data.insertionPoint.move(offset);
	if (data.hasDynamicPlaceholders)
	{             
                  //之前写的,这个没用
		data.insertionPoint_timePlace.move(offset);// 如果有动态占位符，移动占位符位置
		//qDebug() << "RS_MText::move: moving insertionPoint_timePlace by offset" << offset.x << offset.y;
	}
    //qDebug() << "RS_MText::move: old  insertionPoint_timePlace is   " << data.insertionPoint_timePlace.x << data.insertionPoint_timePlace.y;

   
   
}


/*旋转文本内容,用弧度值 double 直接指定角度
* center旋转中心点（基点）
* angle旋转方向的单位向量（直接角度值）
*/
void RS_MText::rotate(const RS_Vector& center, const double& angle) {
    RS_Vector angleVector(angle);
    RS_EntityContainer::rotate(center, angleVector);
    data.insertionPoint.rotate(center, angleVector);
    data.angle = RS_Math::correctAngle(data.angle+angle);
//    update();
}
/*旋转文本内容,用方向向量 RS_Vector 表示旋转
* center旋转中心点（基点）
* angleVector旋转方向的单位向量（非直接角度值）
*/
void RS_MText::rotate(const RS_Vector& center, const RS_Vector& angleVector) {
    RS_EntityContainer::rotate(center, angleVector);
    data.insertionPoint.rotate(center, angleVector);
    data.angle = RS_Math::correctAngle(data.angle+angleVector.angle());
//    update();
}


/**
* RS_MText 类（多行文本实体）的 缩放操作实现，用于按指定比例调整文本对象的大小和位置
* center 参数：缩放基点
* factor 参数：缩放因子向量
*/
void RS_MText::scale(const RS_Vector& center, const RS_Vector& factor) {
    data.insertionPoint.scale(center, factor);
    data.width*=factor.x;
    data.height*=factor.x;
    update();
}


/* RS_MText（多行文本对象）的 镜像操作实现，核心目标是在保持文字可读性的前提下完成几何镜像
*  将文字的插入点（文本定位基准点）关于镜像轴（由 axisPoint1 和 axisPoint2 定义）进行几何镜像。
*/
void RS_MText::mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2) {
    data.insertionPoint.mirror(axisPoint1, axisPoint2);
    //double ang = axisPoint1.angleTo(axisPoint2);
    bool readable = RS_Math::isAngleReadable(data.angle);

	RS_Vector vec = RS_Vector::polar(1.0, data.angle);
    vec.mirror(RS_Vector(0.0,0.0), axisPoint2-axisPoint1);
    data.angle = vec.angle();

    bool corr;
    data.angle = RS_Math::makeAngleReadable(data.angle, readable, &corr);

    if (corr) {
        if (data.halign==RS_MTextData::HALeft) {
            data.halign=RS_MTextData::HARight;
        } else if (data.halign==RS_MTextData::HARight) {
            data.halign=RS_MTextData::HALeft;
        }
    } else {
        if (data.valign==RS_MTextData::VATop) {
            data.valign=RS_MTextData::VABottom;
        } else if (data.valign==RS_MTextData::VABottom) {
            data.valign=RS_MTextData::VATop;
        }
    }
    update();
}



bool RS_MText::hasEndpointsWithinWindow(const RS_Vector& /*v1*/, const RS_Vector& /*v2*/) {
    return false;
}



/**
 *  CAD 系统中多行文本（MText）对象的"拉伸"操作实现，核心作用是 仅当整个文本完全位于拉伸窗口内时，
 *  仅当整个文本完全位于拉伸窗口内时，才执行整体平移；否则忽略部分重叠情况
 * by the given offset.
 */
void RS_MText::stretch(const RS_Vector& firstCorner, const RS_Vector& secondCorner, const RS_Vector& offset) {

    if (getMin().isInWindow(firstCorner, secondCorner) &&
            getMax().isInWindow(firstCorner, secondCorner)) {

        move(offset);
    }
}



/**
 * 多行文本对象（RS_MText）重载的流输出运算符，核心作用是 将文本对象的关键数据以人类可读的格式输出到标准流
 *（如控制台/日志文件），专为调试、日志记录和开发诊断设计
 */
std::ostream& operator << (std::ostream& os, const RS_MText& p) {
    os << " Text: " << p.getData() << "\n";
    return os;
}
/*负责将文本内容分解为底层图形元素并绘制到视图上*/
void RS_MText::draw(RS_Painter* painter, RS_GraphicView* view, double& /*patternOffset*/)
{
    if (!(painter && view)) {
        return;
    }

   /* if (!view->isPrintPreview() && !view->isPrinting())
    {
        if (view->isPanning() || view->toGuiDY(getHeight()) < 1)
        {
            painter->drawRect(view->toGui(getMin()), view->toGui(getMax()));
            return;
        }
    }*/

    foreach (auto e, entities)
    {
        view->drawEntity(painter, e);// 1. 委托视图绘制每个子图元
        qDebug() << "  - Entity:" << (e->rtti())
           ;
        
    }
}
