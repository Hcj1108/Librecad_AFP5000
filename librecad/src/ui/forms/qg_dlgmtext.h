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
#ifndef QG_DLGMTEXT_H
#define QG_DLGMTEXT_H
#include <QDebug>
#include "ui_qg_dlgmtext.h"
#include "rs_mtext.h"
#include "rollingbox.h"

#include <QVBoxLayout>   
#include <QHBoxLayout>    //  
#include <QLabel>         // 
#include <QSpinBox>       // 
#include <QPushButton>    // 
#include <QDialog>        // 
#include <QDate>          //


class QG_DlgMText : public QDialog, public Ui::QG_DlgMText
{
    Q_OBJECT

public:
    QG_DlgMText(QWidget* parent = 0, bool modal = false, Qt::WindowFlags fl = 0);
    ~QG_DlgMText();

   
private:
    QDate m_selectedDate;  // 存储选择的日期
    QDate m_mfgDate;      // 存储生产日期
    int m_expYears = 0;   // 保质期年偏移
    int m_expMonths = 12; // 保质期月偏移
    int m_expDays = 0;    // 保质期日偏移
public slots:
    // 插入占位符
    virtual void setMFGDate();      // 插入 {MFG} 占位符并存储生产日期
    virtual void setEXPDate();      // 插入 {EXP+XM} 占位符
    virtual void setQuickTime();    // 插入 hh:mm:ss
  
    // 文本标签
    virtual void setMFGDateText();  // 插入"生产日期："
    virtual void setEXPDateText();  // 插入"保质期至："
    virtual void setLineBreak();    // 插入换行
    virtual void insertSymbol(int); // 插入特殊符号
    // 对话框操作
    virtual void setText(RS_MText& t, bool isNew);
    virtual void updateText();
    virtual void reject();
    virtual int getAlignmentcom();
    virtual void setAlignment(int a);
    virtual void setFont(const QString& f);
    virtual void defaultChanged(bool);
    virtual void loadText();
    virtual void load(const QString& fn);
    virtual void saveText();
    virtual void save(const QString& fn);
    // Unicode
    virtual void updateUniCharComboBox(int);
    virtual void updateUniCharButton(int);
    virtual void insertChar();

public:
    QString replaceDatePlaceholders(const QString& input);

protected slots:
    virtual void languageChange();

public:
    bool isNew;
    bool saveSettings;
    RS_MText* text;
    RS_Font* font;
    //QString m_rawPlaceholderText; // 保存原始占位符文本，用于持久化到注册表
    void init();
    void destroy();

};

#endif // QG_DLGMTEXT_H
