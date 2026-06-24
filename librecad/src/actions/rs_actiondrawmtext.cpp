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

#include <QAction>
#include <QMouseEvent>
#include "rs_actiondrawmtext.h"
#include "rs_settings.h"
#include "rs_mtext.h"
#include "rs_text.h"
#include "rs_dialogfactory.h"
#include "rs_graphicview.h"
#include "rs_commandevent.h"
#include "rs_coordinateevent.h"
#include "rs_preview.h"
#include "rs_debug.h"
#include "rs_graphic.h"
#include<QDebug>
#include<QTimer>
#include "qg_actionhandler.h"
#include "fileuilts.h"
#include <rs_modification.h>
#include "FontSettingsSingleton.h"
#include"PlaceholderPositionManager.h"
enum HAlign {
    HALeft,     /**< Left */
    HACenter,   /**< Centered */
    HARight     /**< Right */
};

enum VAlign {
    VATop,      /**< Top.   */
    VAMiddle,   /**< Middle */
    VABottom    /**< Bottom */
};
RS_ActionDrawMText::RS_ActionDrawMText(RS_EntityContainer& container,
                                     RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw Text",
						   container, graphicView)
		,pos(new RS_Vector{})
		,textChanged(true)
{
	actionType=RS2::ActionDrawMText;
  
}

RS_ActionDrawMText::~RS_ActionDrawMText() = default;

void RS_ActionDrawMText::init(int status) {//ShowDialog → SetPos → 触发动作
    RS_ActionInterface::init(status);

	switch (status) {
	case ShowDialog: {

		reset();                                                    // 这里会初始化一个默认的 data
		RS_MText tmp(NULL, *data);                                  // 1. 创建临时 RS_MText 对象 tmp

        
		if (RS_DIALOGFACTORY->requestMTextDialog(&tmp)) {           // 2. 传递 tmp 指针给对话框工厂
           
            data.reset(new RS_MTextData(tmp.getData()));            // 4. 如果用户点击确认，从 tmp 获取新数据并更新 action 的 data
  
            //setStatus(SetPos);
            //showOptions();
            createAtDefaultPosition();
            finish(false);
			
		} else {
			hideOptions();
			finish(true);
		}
	}
		break;

	case SetPos:
		RS_DIALOGFACTORY->requestOptions(this, true, true);
		deletePreview();
		preview->setVisible(true);
		preparePreview();
		break;

	default:
		break;
	}
}



void RS_ActionDrawMText::reset() {
	const QString text=data.get()?data->text:"";
	data.reset(new RS_MTextData(RS_Vector(0.0,0.0),
                       1.0, 100.0,
                       RS_MTextData::VATop,
                       RS_MTextData::HALeft,
                       RS_MTextData::LeftToRight,
                       RS_MTextData::Exact,
                       1.0,
					   text,
                       "standard",
                       0.0,
					   RS2::Update)
			   );
}




void RS_ActionDrawMText::trigger() {
    RS_DEBUG->print("RS_ActionDrawText::trigger()");

    // 使用 data->insertionPoint 而不是 pos->valid
    if (data->insertionPoint.valid) {
        deletePreview();
      /*  qDebug() << "RS_ActionDrawMText::trigger() - insertionPoint: "
            << data->insertionPoint.x << "," << data->insertionPoint.y;*/

        // 1. 清空文档
        //document->clear();
  

        // 2. UDP 数据发送逻辑
        SingletonNomArray& nomArray = SingletonNomArray::getInstance();
        nomArray.clearNomArray();

        const QString characters = "0123456789:";
        QString ip = "192.168.1.10";
        quint16 port = 1234;
        int startNom = 0;
        nomArray.appendNom(startNom);

        for (int i = 0; i < characters.size(); ++i) {
            QChar ch = characters.at(i);

            // 创建文本实体
            RS_TextData textData(
                RS_Vector(5000, 5000), RS_Vector(0, 0),
                data->height * data->y_scale, data->x_scale / data->y_scale,
                RS_TextData::VATop, RS_TextData::HALeft, RS_TextData::None,
                QString(ch), data->style, 0, RS2::Update
            );
           
            // 传给单例类
            FontSettingsSingleton::getInstance().sety_scale(data->y_scale);
            FontSettingsSingleton::getInstance().setx_scale(data->x_scale);

           /* qDebug() << "data->y_scale:" << data->y_scale;
            qDebug() << "data->x_scale:" << data->x_scale;*/
            
            RS_Text* textEntity = new RS_Text(container, textData);
            document->startUndoCycle();
            document->addEntity(textEntity);
            document->addUndoable(textEntity);
          
            // 获取路径点并优化
            auto allPoints = textEntity->getAllEntityPathPoints();
            QVector<QVector<QPoint>> optimizedPaths;

            for (const auto& entityPoints : allPoints) {
                QVector<QPoint> path;
                for (const RS_Vector& point : entityPoints) {
                    path.append(QPoint(static_cast<int>(point.x), static_cast<int>(point.y)));
                }
                optimizedPaths.append(path);
            }

            // 发送数据并存储结果
            startNom = FileUtils::sendOptimizedPointsUDP_hex(optimizedPaths, ip, port, startNom);
            qDebug() << QString::fromLocal8Bit("发送数据并存储结果 All nom values:") << nomArray.getNomArray();
            nomArray.appendNom(startNom);
            qDebug() << "Processed" << ch;
            qDebug() << "next start startNom:" << startNom;

            // 清理
            document->removeEntity(textEntity);//删除实体1234567890
            document->endUndoCycle();
            
        }
        qDebug() << "========================================\n";
        // 调试输出最终结果
        qDebug() << "All nom values:" << nomArray.getNomArray();

        // 3. 创建多行文字实体
        // 创建数据副本（避免污染原始数据）
        RS_MTextData textData(*data);
        //RS_MTextData textData(
        //    RS_Vector(35000, 35000),              // insertionPoint                                                    
        //    data->height * data->y_scale,       // height                                                            
        //    data->x_scale / data->y_scale,      // width                                                             
        //    RS_MTextData::VATop,                // valign                                                            
        //    RS_MTextData::HALeft,               // halign                                                            
        //    RS_MTextData::LeftToRight,          // drawingDirection                                                  
        //    RS_MTextData::Exact,                // lineSpacingStyle                                                  
        //    1.0,                                // lineSpacingFactor                                                 
        //    "abcdef",                           // text                                                              
        //    data->style,                        // style                                                             
        //    0.0,                                // angle                                                             
        //    RS2::Update                         // updateMode                                                        
        //);
        // 占位符替换
        if (textData.text.contains("hh:mm:ss")) {
            int placeholderPos = textData.text.indexOf("hh:mm:ss");
            textData.hasDynamicPlaceholders = true;
            textData.timePlaceholderPos = placeholderPos;
            qDebug() << QString::fromLocal8Bit("在以下位置找到了:") << placeholderPos;

            QString timeStr = QTime::currentTime().toString("hh:mm:ss");
            textData.text.replace("hh:mm:ss", timeStr);
            textData.timePlaceholderReplacedLength = timeStr.length();
            qDebug() << QString::fromLocal8Bit("占位符被替换为:") << timeStr;

            textData.timePlaceholderPositions.clear();
            textData.hasDynamicPlaceholders = true;
        }

        // 创建实体
        RS_MText* text = new RS_MText(container, textData);
        text->update();  // 触发布局计算

        double fontHeight = text->getHeight();
        double textWidth = text->getUsedTextWidth();

        text->update();

        // Debug output with actual coordinates
        qDebug() << "Actual document coordinates - X:" << data->insertionPoint.x
            << "Y:" << data->insertionPoint.y
            << "(Font height:" << fontHeight
            << "Text width:" << textWidth << ")";

        qDebug() << "_~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        qDebug() << "Font width set to:" << FontSettingsSingleton::getInstance().getFontWidth();

        FontSettingsSingleton::getInstance().setFontHeight(fontHeight);

        // 添加到容器和撤销栈
        container->addEntity(text);

        if (document) {
            document->startUndoCycle();
            document->addUndoable(text);
            document->endUndoCycle();
        }

        // 4. 重绘视图
        graphicView->redraw(RS2::RedrawDrawing);

        textChanged = true;
        setStatus(SetPos);
    }
    else {
        qDebug() << "错误：插入点无效，跳过实体创建";
    }
}
void RS_ActionDrawMText::preparePreview() {
	data->insertionPoint = *pos;
	RS_MText* text = new RS_MText(preview.get(), *data);
    text->update();
    preview->addEntity(text);
    textChanged = false;
}


void RS_ActionDrawMText::mouseMoveEvent(QMouseEvent* e) {
    RS_DEBUG->print("RS_ActionDrawText::mouseMoveEvent begin");

    if (getStatus()==SetPos) {
        RS_Vector mouse = snapPoint(e);
		RS_Vector mov = mouse-*pos;
		*pos = mouse;
		if (textChanged || pos->valid == false || preview->isEmpty()) {
            deletePreview();
            preparePreview();
        } else {
            preview->move(mov);
            preview->setVisible(true);
        }
        drawPreview();
    }

    RS_DEBUG->print("RS_ActionDrawText::mouseMoveEvent end");
}



void RS_ActionDrawMText::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button()==Qt::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent();
        deletePreview();//触摸屏时用
        finish(false);//触摸屏时用，不用再次触发
    } else if (e->button()==Qt::RightButton) {
        deletePreview();
        //init(getStatus()-1);
        finish(false);
    }
}



void RS_ActionDrawMText::coordinateEvent() {
 
    switch (getStatus()) {
    case ShowDialog:
       
        break;

    case SetPos:
		//data->insertionPoint = mouse;
        //trigger();
        createAtDefaultPosition();
        break;

    default:
        break;
    }
}

/**
 * 在默认坐标创建文本实体
 */
void RS_ActionDrawMText::createAtDefaultPosition() {
    // 1. 设置默认插入点
    RS_Vector defaultPos(33000.0, 34700.0);  // 默认坐标
    //RS_Vector Pos(33000.0, 34700.0);  // 默认坐标
    // 或者从配置读取
    // double x = RS_SETTINGS->readEntry("/MText/DefaultX", "33000.0").toDouble();
    //double y = RS_SETTINGS->readEntry("/MText/DefaultY", "33000.0").toDouble();
     //RS_Vector defaultPos(x, y);

    data->insertionPoint = defaultPos;

    // 2. 创建实体
    trigger();
    // 3. 执行自动缩放
    if (graphicView) {
        //graphicView->zoomAuto(false, true);  // 单轴缩放，保持宽高比
        //// 使用缩小功能
        //graphicView->zoomOut(1.88, data->insertionPoint);  // 默认坐标
    }
    // 3. 重置状态
    finish(false);
}

void RS_ActionDrawMText::commandEvent(RS_CommandEvent* e) {
    QString c = e->getCommand().toLower();

    if (checkCommand("help", c)) {
            RS_DIALOGFACTORY->commandMessage(msgAvailableCommands()
                                             + getAvailableCommands().join(", "));
        return;
    }

    switch (getStatus()) {
    case SetPos:
        if (checkCommand("text", c)) {
            deletePreview();
            graphicView->disableCoordinateInput();
            setStatus(SetText);
        }
        break;

    case SetText: {
            setText(e->getCommand());
			RS_DIALOGFACTORY->requestOptions(this, true, true);
            graphicView->enableCoordinateInput();
            setStatus(SetPos);
        }
        break;

    default:
        break;
    }
}



QStringList RS_ActionDrawMText::getAvailableCommands() {
    QStringList cmd;
    if (getStatus()==SetPos) {
        cmd += command("text");
    }
    return cmd;
}



void RS_ActionDrawMText::showOptions() {
    RS_ActionInterface::showOptions();

	RS_DIALOGFACTORY->requestOptions(this, true, true);
}



void RS_ActionDrawMText::hideOptions() {
    RS_ActionInterface::hideOptions();

	RS_DIALOGFACTORY->requestOptions(this, false);
}



void RS_ActionDrawMText::updateMouseButtonHints() {
	switch (getStatus()) {
	case SetPos:
		RS_DIALOGFACTORY->updateMouseWidget(tr("Specify insertion point"),
											tr("Cancel"));
		break;
	case ShowDialog:
	case SetText:
		RS_DIALOGFACTORY->updateMouseWidget(tr("Enter text:"),
											tr("Back"));
		break;
	default:
		RS_DIALOGFACTORY->updateMouseWidget();
		break;
	}
}



void RS_ActionDrawMText::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}

void RS_ActionDrawMText::setText(const QString& t) {
	data->text = t;
    textChanged = true;
}



QString RS_ActionDrawMText::getText() {
	return data->text;
}


void RS_ActionDrawMText::setAngle(double a) {
	data->angle = a;
    textChanged = true;
}

double RS_ActionDrawMText::getAngle() {
	return data->angle;
}


// EOF
