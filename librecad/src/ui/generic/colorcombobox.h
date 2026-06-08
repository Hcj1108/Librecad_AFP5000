#ifndef COLORCOMBOBOX_H
#define COLORCOMBOBOX_H

#include <QComboBox>  // Qt组合框基类

/**
 * @file colorcombobox.h
 * @brief ColorComboBox 类头文件
 *
 * 自定义颜色选择组合框，继承自 QComboBox
 * 在 LibreCAD 中用于选择图形实体的颜色
 */

 /**
  * @class ColorComboBox
  * @brief 颜色选择组合框类
  *
  * 扩展自 QComboBox，提供颜色选择功能：
  * 1. 预定义的颜色列表
  * 2. 颜色预览图标
  * 3. 可能的自定义颜色支持
  *
  * 在 LibreCAD 中的典型用途：
  * - 笔颜色选择
  * - 图层颜色设置
  * - 填充颜色选择
  * - 文本颜色设置
  */
class ColorComboBox : public QComboBox
{
    Q_OBJECT  // Qt 元对象系统宏，启用信号槽机制

public:
    /**
     * @brief 构造函数
     *
     * 创建颜色选择组合框实例，并初始化颜色选项
     *
     * @param parent 父窗口指针，用于内存管理和布局
     *
     * 示例：
     * @code
     * // 在工具栏中创建颜色选择器
     * ColorComboBox* colorBox = new ColorComboBox(this);
     * connect(colorBox, &ColorComboBox::currentIndexChanged,
     *         this, &MyClass::onColorChanged);
     * @endcode
     */
    explicit ColorComboBox(QWidget* parent = nullptr);

    /**
     * 注意：由于继承自 QComboBox，拥有以下可用功能：
     * 1. 标准 QComboBox 信号：
     *    - currentIndexChanged(int)
     *    - currentTextChanged(const QString&)
     *    - activated(int)
     *    - textActivated(const QString&)
     * 2. 标准 QComboBox 方法：
     *    - addItem() / insertItem()
     *    - currentText() / currentIndex()
     *    - setCurrentIndex() / setCurrentText()
     *    - findText() / findData()
     */

  
   
};

#endif // COLORCOMBOBOX_H
