/*
** 版权声明和许可证信息
** 这是一个开源项目 LibreCAD 的一部分
** 遵守 GNU GPL v2 开源协议
*/

#include "textfileviewer.h"
#include "ui_textfileviewer.h"

#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QListWidget>

// 构造函数
TextFileViewer::TextFileViewer(QWidget* parent) :
    QFrame(parent),                // 继承自QFrame
    ui(new Ui::TextFileViewer)    // 创建UI
{
    ui->setupUi(this);                          // 设置UI布局
    ui->text_edit->setReadOnly(true);          // 设置文本框为只读

    // 连接信号：当列表项被点击时，加载对应的文件
    connect(ui->list, &QListWidget::itemClicked, this, &TextFileViewer::loadFile);
}

// 析构函数
TextFileViewer::~TextFileViewer()
{
    delete ui;  // 释放UI资源
}

/**
 * 功能：添加文件到查看器中
 * 参数：
 *   name - 文件显示名称（在列表中显示）
 *   path - 文件的实际路径
 * 返回值：添加成功返回true，失败返回false
 */
bool TextFileViewer::addFile(QString name, QString path)
{
    // 打开文件
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;  // 文件打开失败

    // 读取文件全部内容
    QTextStream txt_stream(&file);
    auto txt = txt_stream.readAll();

    // 在列表中创建新项
    auto item = new QListWidgetItem(name, ui->list);
    // 将文件内容存储在项的whatsThis属性中
    item->setWhatsThis(txt);

    return true;  // 添加成功
}

/**
 * 功能：加载并显示选择的文件
 * 参数：item - 用户点击的列表项
 */
void TextFileViewer::loadFile(QListWidgetItem* item)
{
    // 从列表项的whatsThis属性获取文件内容，并显示在文本框中
    ui->text_edit->setPlainText(item->whatsThis());
}

/**
 * 功能：设置当前显示的文件
 * 参数：name - 要显示的文件名称
 */
void TextFileViewer::setFile(QString name)
{
    // 在列表中查找指定名称的项
    auto item = ui->list->findItems(name, Qt::MatchExactly)[0];
    ui->list->setCurrentItem(item);  // 在列表中选中该项
    loadFile(item);                   // 加载并显示文件内容
}