/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
** LibreCAD项目的一部分，一个2D CAD程序
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
** 版权所有 (C) 2010 R. van Twisk
** 版权所有 (C) 2001-2003 RibbonSoft. 保留所有权利。
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
** 本文件可根据自由软件基金会发布的GNU通用公共许可证第2版条款分发和/或修改，
** 许可证文本包含在文件gpl-2.0.txt中。
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 本程序按原样分发，希望有用，但不提供任何明示或暗示的担保，
** 包括适销性或特定用途适用性的担保。更多细节请参阅GNU通用公共许可证。
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
** 您应该已收到GNU通用公共许可证的副本。如果没有，请写信至：
** 自由软件基金会，51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
**
** This copyright notice MUST APPEAR in all copies of the script!
** 此版权声明必须出现在脚本的所有副本中！
**
**********************************************************************/


#ifndef RS_SETTINGS_H
#define RS_SETTINGS_H

#include <QString>
#include <map>

class QVariant;

// ---------------------------------------------------------------------------
// 默认设置 Default Settings
// ---------------------------------------------------------------------------

// 颜色定义命名空间
namespace Colors
{
    const QString snap_indicator = "#FFC200";   // 捕捉指示器颜色（橙色）
    const QString background = "Black";     // 背景颜色（黑色）
    const QString grid = "Gray";      // 网格颜色（灰色）
    const QString meta_grid = "#404040";   // 主网格颜色（深灰色）
    const QString select = "#A54747";   // 选择颜色（暗红色）
    const QString highlight = "#739373";   // 高亮颜色（暗绿色）
    const QString start_handle = "Cyan";      // 起始句柄颜色（青色）
    const QString handle = "Blue";      // 句柄颜色（蓝色）
    const QString end_handle = "Blue";      // 结束句柄颜色（蓝色）
}

// ---------------------------------------------------------------------------

// 单例对象访问宏
#define RS_SETTINGS RS_Settings::instance()

/**
 * 此类可以从配置文件或Windows注册表中存储和重新加载设置。
 * 请注意，Qt的默认实现不按预期工作。因此，此类覆盖了大部分默认行为。
 *
 * This class can store and reload settings from a
 * configuration file or the Windows registry.
 * Please note that the Qt default implementation doesn't
 * work as one would expect. That's why this class overwrites
 * most of the default behaviour.
 */
class RS_Settings {

public:
    ~RS_Settings();  // 析构函数

    /**
     * 返回唯一设置对象的实例
     * @return Instance to the unique settings object.
     */
    static RS_Settings* instance();

    /**
     * 初始化系统
     * Initialize the system.
     *
     * @param companyKey 公司键名 Company Key
     * @param appKey 应用程序键名 Application key
     */
    void init(const QString& companyKey, const QString& appKey);

    // 配置组操作 Configuration group operations
    void beginGroup(const QString& group);  // 开始配置组
    void endGroup();                        // 结束配置组

    // 写入配置项 Write entries
    bool writeEntry(const QString& key, int value);              // 写入整数
    bool writeEntry(const QString& key, double value);           // 写入浮点数
    bool writeEntry(const QString& key, const QVariant& value);  // 写入任意类型
    bool writeEntry(const QString& key, const QString& value);   // 写入字符串

    // 读取配置项 Read entries
    QString readEntry(const QString& key,
        const QString& def = QString(),
        bool* ok = 0);                          // 读取字符串

    QByteArray readByteArrayEntry(const QString& key,
        const QString& def = QString(),
        bool* ok = 0);                          // 读取字节数组

    int readNumEntry(const QString& key, int def = 0);            // 读取整数（快捷方法）

    // 清理操作 Cleanup operations
    void clear_all();       // 清除所有配置
    void clear_geometry();  // 清除几何相关配置（如窗口位置大小）

    static bool save_is_allowed;  // 静态标志，指示是否允许保存设置

private:
    RS_Settings();  // 私有构造函数，确保单例模式
    // 删除复制构造函数和赋值运算符，防止复制
    RS_Settings(RS_Settings const&) = delete;
    RS_Settings& operator = (RS_Settings const&) = delete;

    // 缓存相关方法 Cache related methods
    QVariant readEntryCache(const QString& key);           // 从缓存读取
    void addToCache(const QString& key, const QVariant& value);  // 添加到缓存

protected:
    static RS_Settings* uniqueInstance;  // 静态单例实例指针

    std::map<QString, QVariant> cache;  // 配置缓存，提高读取性能

    // 配置存储相关 Configuration storage related
    QString companyKey;  // 公司标识（用于注册表路径或ini文件路径）
    QString appKey;      // 应用程序标识
    QString group;       // 当前配置组（如"General"、"Window"等）

    bool initialized;    // 是否已初始化标志
};

#endif