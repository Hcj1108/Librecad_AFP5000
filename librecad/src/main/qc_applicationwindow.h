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

// Changes: https://github.com/LibreCAD/LibreCAD/commits/master/librecad/src/main/qc_applicationwindow.h

#ifndef QC_APPLICATIONWINDOW_H
#define QC_APPLICATIONWINDOW_H

// =======================================================================
// 1. 基础包含文件
// =======================================================================
#include "SingletonNomArray.h"       // 序号数组单例类，管理激光打标数据编号
#include "FontSettingsSingleton.h"  // 字体设置单例类，管理激光打标字体参数
#include "mainwindowx.h"            // 主窗口基类，提供窗口框架功能

// LibreCAD核心库
#include "rs_pen.h"                 // CAD笔属性类，定义线型、颜色、宽度
#include "rs_snapper.h"             // 捕捉工具类，实现精确点捕捉
#include <QMap>                     // Qt映射容器
#include <QMessageBox>              // Qt消息框
#include <QComboBox>                // Qt组合框
#include <QPlainTextEdit>           // Qt纯文本编辑框
#include <QCheckBox>                // Qt复选框
#include <QStatusBar>               // Qt状态栏
#include "rs_document.h"            // CAD文档类，管理所有图形实体
#include "rs_entity.h"              // CAD实体基类，所有图形元素的父类
#include "rs_vector.h"              // 二维向量类，表示坐标点
#include <QSettings>                // Qt设置管理，读写配置
#include <vector>                   // C++标准向量容器
#include "qg_graphicview.h"         // Qt图形视图
#include "rs_graphicview.h"         // CAD图形视图，提供渲染和交互

#include "rs_polyline.h"            // 多段线类，激光打标常用实体

// 标准库
#include <iostream>                 // C++输入输出流
#include <fstream>                  // C++文件流

// 二维码生成库 (ZXing)
#include <include/ZXing/BarcodeFormat.h>    // 条码格式定义
#include <include/ZXing/BitMatrix.h>        // 位矩阵，存储二维码数据
#include <include/ZXing/MultiFormatWriter.h>// 多格式条码生成器

using namespace ZXing;  // 使用ZXing命名空间简化代码

// =======================================================================
// 2. Qt UI命名空间
// =======================================================================
namespace Ui {
    class QC_ApplicationWindow;  // Qt UI编译器生成的类
    // 注意：这里声明的是QC_ApplicationWindow，不是QC_ApplicationWindowClass
    // 这是Qt Designer生成的UI类命名约定
}

// =======================================================================
// 3. 前向声明（避免循环依赖）
// =======================================================================

// 多文档界面(MDI)相关
class QMdiArea;                     // MDI区域，管理多个子窗口
class QMdiSubWindow;                // MDI子窗口
class QC_MDIWindow;                 // CAD专用的MDI窗口

// 工具栏和部件
class QG_LibraryWidget;            // 库部件，显示符号库
class QG_CadToolBar;               // CAD工具栏
class QG_SnapToolBar;              // 捕捉工具栏
class QC_DialogFactory;            // 对话框工厂，创建各种对话框
class QG_LayerWidget;              // 图层部件
class QG_BlockWidget;              // 块部件
class QG_CommandWidget;            // 命令部件
class QG_MouseWidget;              // 鼠标部件，显示坐标
class QG_SelectionWidget;          // 选择部件
class QG_RecentFiles;              // 最近文件列表
class QG_PenToolBar;               // 笔工具栏
class QC_PluginInterface;          // 插件接口
class QG_ActiveLayerName;          // 活动图层名显示
class LC_SimpleTests;              // 简单测试
class LC_CustomToolbar;            // 自定义工具栏
class QG_ActionHandler;            // 动作处理器
class RS_GraphicView;              // CAD图形视图
class RS_Document;                 // CAD文档
class TwoStackedLabels;            // 双层标签部件
class LC_ActionGroupManager;       // 动作组管理器
class LC_PenWizard;                // 笔向导

// =======================================================================
// 4. LibreCAD核心包含
// =======================================================================
#include <rs_modification.h>        // 修改操作，如移动、旋转、缩放
#include <rs_debug.h>               // 调试工具
#include<rs_text.h>                 // 文本实体
#include <rs_dialogfactory.h>       // 对话框工厂
#include <QInputDialog>             // Qt输入对话框
#include <QDoubleSpinBox>           // Qt双精度微调框
#include <QFormLayout>              // Qt表单布局
#include <QDialogButtonBox>         // Qt对话框按钮盒
#include<rs_graphic.h>              // CAD图形


#include "qg_dlgmtext.h"
// =======================================================================
// 5. OCR模块包含文件
// =======================================================================
/*
OCRdemo模块导入区域
这个模块集成了图像采集、OCR识别、激光控制等功能
使得LibreCAD具备了工业视觉检测能力
*/
#include <QtWidgets/QMainWindow>    // Qt主窗口
#include "ui_QC_ApplicationWindow.h"// Qt Designer生成的UI头文件
#include <QFile>                    // Qt文件操作
#include <QQueue>                   // Qt队列容器
#include <QTranslator>              // Qt翻译器，支持多语言
#include<QThread>                   // Qt线程
#include<QTimer>                    // Qt定时器
#include <QUdpSocket>               // Qt UDP套接字，用于网络通信
#include <qendian.h>                // Qt字节序处理
#include <QVBoxLayout>;


// OCR模块自定义类
#include "GXBitmap.h"               // 大华相机位图处理
#include"GalaxyIncludes.h"          // 大华相机SDK头文件
#include "deletionmanager.h"        // 删除管理器，清理临时文件
#include "Config.h"                  // 数据库模块
#include "ImageViewer.h"            // 图像查看器
#include "Guide.h"                  // 引导界面
#include "SerialManager.h"          // 串口管理器，连接外部设备
#include "OCRruning.h"              // OCR运行类，实现字符识别
#include "Jgadmin.h"                // 激光管理员界面
#include "XJadmin.h" 
#include "user.h"                   // 用户界面
#include "AddScheme.h"              // 添加配方
#include "AlterScheme.h"            // 修改配方
#include "SimpleBarChart.h"         // 简单柱状图
#include "rollingbox.h"             // 滚动条部件日期选择器
#include "Logger.h"                 // 日志查看器


#include "PlaceholderPositionManager.h" // 占位符位置管理器
#include "BinaryDataListener.h"
#include "fileuilts.h"              // 文件工具类，处理文件操作
#include "EntityMover.h"           // 实体移动工具类
#include "PathSender.h"           // 路径点发送类

using namespace std;  // 使用标准命名空间

// =======================================================================
// 6. 结构体定义
// =======================================================================

/**
 * @struct DockAreas
 * @brief 停靠区域结构体
 *
 * 管理Qt停靠部件的显示位置控制
 * 每个成员对应一个方向的停靠动作
 */
struct DockAreas
{
    QAction* left{ nullptr };    // 左侧停靠动作
    QAction* right{ nullptr };   // 右侧停靠动作
    QAction* top{ nullptr };     // 顶部停靠动作
    QAction* bottom{ nullptr };  // 底部停靠动作
    QAction* floating{ nullptr };// 浮动停靠动作
};

// =======================================================================
// 7. 主应用程序窗口类
// =======================================================================

/**
 * @class QC_ApplicationWindow
 * @brief 主应用程序窗口类
 *
 * 这是激光打标系统的核心控制类，集成了：
 * 1. CAD绘图功能（基于LibreCAD）
 * 2. 图像采集和OCR识别
 * 3. 激光打标控制
 * 4. 设备通信
 * 5. 用户界面管理
 *
 * 继承自MainWindowX，提供完整的窗口框架
 *
 * @author Andrew Mustun
 */
class QC_ApplicationWindow : public MainWindowX
{
    Q_OBJECT  // Qt元对象系统宏，启用信号槽机制


    // =======================================================================
    // 8. OCR模块公开成员
    // =======================================================================
public:
 
    bool IsCustom = false;           // 自定义日期匹配标识符
    QString thisPassword;            // 操作密码，用于权限验证
    QSettings settings;              // 应用程序设置，存储在注册表或ini文件
    bool IsFirstOpenSoft = true;     // 是否第一次打开软件，用于初始化设置

    // 界面对象实例
    Setting setting;                 // 参数设置界面          
    XJadmin xjadmin;                 // 相机管理员界面
    Jgadmin jgadmin;                 // 激光管理员界面
    user User;                       // 用户界面
    SerialManager serialmanager;     // 状态显示设备界面
    ImageViewer viewer;              // 图像查看器
    Guide guide;                     // 引导界面，提供操作指引
    Logger loggerView;               // 日志查看器
    AddScheme addscheme;             //新建配方界面
    AlterScheme alterscheme;         //修改配方界面
    // 定时器（用于各种定时任务）
    QTimer* TimerLongPressSub = new QTimer(this);      // 长按计时器1
    QTimer* TimerLongPressSub2 = new QTimer(this);     // 长按计时器2
    bool CamTimerEnd = true;         // 相机滤波标志，控制采样频率
    QTimer* TimerLongPressSub_Alarm = new QTimer(this); // 报警灯显示定时器

    // 图像处理相关
    CImageDataPointer objImageDataPointer;  // 大华相机图像数据指针
    CGXBitmap* m_pBitmap = nullptr;         // 位图对象指针，存储相机图像
    OCRruning* OCRT = new OCRruning();      // OCR识别线程对象
    QThread* T = new QThread;               // 工作线程，运行OCR识别
    QMutex* m_mutex;                        // 线程同步互斥锁
    DeletionManager manager;                // 文件夹清理管理器，防止磁盘满
    SimpleBarChart* chart = new SimpleBarChart(this);
    // OCR识别结果
    int ocrresult;                          // OCR识别结果代码
    double ocr_time;                        // OCR识别耗时（单位：毫秒）
    QLabel* label = nullptr;                // 耗时显示标签
    QString Time_str;                       // 耗时字符串
    QString RawResult, FiltedResult;        // 第一次识别原始结果和过滤后结果
    QString RawResult2, FiltedResult2;      // 第二次识别结果（双识别验证）

    //接收二进制数据的监听器
    BinaryDataListener* listener = new BinaryDataListener(1234);

    int currentIndex = 0;                   // 界面切换索引，用于StackedWidget
  
   
    bool IsOnlyOcr = false;                 // 只OCR不报警标志，用于测试模式
    bool ComboxMark = 1;                    // 配方切换标志
    bool Is_Cap_Finshed = false;            // 拍照完成标志
    bool IsSchemeComboBoxcode = true;       // 配方组合框代码标志
    bool Line2Status = false;               // 相机Line2状态，用于触发控制

//private:
//    /**
//     * @brief 将OpenCV Mat转换为Qt QImage
//     *
//     * 线程安全的图像格式转换，确保在多线程环境下安全使用
//     * 创建深拷贝，避免内存访问冲突
//     *
//     * @param mat OpenCV矩阵对象
//     * @return QImage Qt图像对象
//     */
//    QImage matToQImage(const cv::Mat& mat) {
//        if (mat.empty()) {
//            return QImage();  // 返回空图像
//        }
//
//        // 创建深拷贝，避免原数据被修改
//        cv::Mat rgb;
//        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);  // BGR转RGB
//
//        // 创建QImage（深拷贝），确保线程安全
//        return QImage(rgb.data, rgb.cols, rgb.rows,
//            static_cast<int>(rgb.step),
//            QImage::Format_RGB888).copy();
//    }

public:
    // =======================================================================
    // 9. OCR模块公共方法声明
    // =======================================================================

    void SetQSS();                          // 设置界面样式表(QSS)
    bool eventFilter(QObject* obj, QEvent* evt);  // 事件过滤器

    // 相机控制
    void CamerButton();                     // 相机开关按钮处理
    //bool setROI(int offsetX, int offsetY, int width, int height);
    bool OpenCamer();                       // 打开相机
    void CloseCamer();                      // 关闭相机
    void CapAndOcr();                       // 拍照并进行OCR识别
    void TriggerLine0();                    // 设置line0硬件触发
    void TriggerSoftware();                 // 设置软件触发
    void AutoCap();                         // 自动采集模式
    //void SetROI(int x, int y, int width, int height);
    bool SetROISimple(int width, int height, int x, int y );

    //打标开关
    void enableBKBKPrinting();                                                
    void disableBKBKPrinting();
  
    // 界面控制
    void ShowSetting();                     // 显示设置界面   
    void ShowJgadmain();                    // 显示激光参数界面
    void ShowXJadmain();                    //显示相机参数界面
    void ShowUser();                        // 显示用户权限界面
    void ShowThis();                        // 显示主界面
    void ViewRecord();                      // 查看历史记录界面

    // 参数设置
    void SubCapture();                      // 向设置界面发送图片
    void SetRect();                         // 设置ROI区域
   
    void SetExposureTime();                 // 设置曝光时间
    void SetSharpness();                    // 设置锐度值
    void SetGainValue();                    // 设置增益
    void SetRot();                          // 设置旋转角度
 
    //void SetFirstOCRSize();                 // 设置第一级OCR尺寸
    //void SetSecOCRSize();                   // 设置第二级OCR尺寸
    //void SetImageSize();                    // 设置图像尺寸

    // 报警和控制
    void Pass();                            // OK图片处理
    void NG();                              // NG图片处理
    void updateHistoryImage(cv::Mat newImage, int pass, QString RawResult, QString RawResult2, QString Time_str);
    void updateHistoryToolTips(int pass, QString RawResult, QString RawResult2, QString Time_str);
  //  void addResultMark(QLabel* label, const QString& mark, QString tooltip, QString color);
    void addResultMarkToButton(QToolButton* button, const QString& mark, QString tooltip, const QString& color);
    void setupImageButtonEvents();
    void showImageDetail(int index);
   
   //void Alarm();                           // 输出报警信号
    //void UNAlarm();                         // 取消报警
    void processImageAndControls();         //处理图像缩放、报警控制和运行模式
    void processBinaryData(const QBitArray& bits, const QHostAddress& sender, quint16 port);//处理接收到的二进制数据
    void CustomModeButtonClicked();         //自定义模式按钮点击事件
    void clearCustomFields();               //清除自定义字段内容
    void saveCustomFields();                //保存自定义字段内容
    void showOCRResults();                  //显示OCR识别结果
    void onTabWidgetPageChanged(int index);   //处理工具箱页面切换
    // 方案管理
    void UpdateCombobox();                  // 更新方案下拉框
    void DeleteCombobox();                  // 删除方案
    void SetScheme(QString schemetext);     // 根据方案名设置参数
    void ChangeScheme();                    // 切换方案
    void CreateScheme();                    // 创建新方案
    void ChangeSchemeName();                // 修改配方名
    void AlterScheme();                     // 修改方案
    void SaveAlterScheme();                 // 快捷修改方案
    void OpenAlterScheme();                 //打开配方参数修改界面
   
    // 数据处理
    void SaveNG();                          // 保存NG图片
   
  
    void Simulate();                        // 模拟仿真加载目录
    void OnlyOcr();                         // 只OCR识别不报警
    void getSerialNum3();
    // 界面更新
    void RateUpdate();                      // 更新数据仪表盘
    void RateClear();                       // 数据仪表盘清零

    // 时间处理
    void SelectTime();                      // 选择时间对话框
    QString CaculateTime(int year, int month, int day,
        int save_days, int save_months, int save_years);  // 计算时间
    void UpdataTime();                      // 更新时间显示

    // 相机事件
    void CamErrorAct();                     // 相机掉线处理动作
    int calculateSelectionBounds(RS_Document* doc);//转换相机图片ROI裁剪

    // 系统管理
    void SetSchemeContent(QString schemename);  // 设置方案内容
    //void LockScreen();                     // 锁屏
    void UnlockScreen();                   // 解锁
    void showLoginDialog();                  // 弹出登录/注销对话框
    void toggleSchemeButton(QWidget* activeBtn, QWidget* inactiveBtn, bool& flag, bool value);
    void manageUserPermissions();          // 管理用户权限
    void initializeUserPermissions();      // 初始化用户权限

    // 用户管理
    void AddUser();                        // 添加用户
    void DelUser();                        // 删除用户
    void Alterpassword();                  // 修改密码
    void GatUser();                        // 获取用户权限参数

    // 激光控制
    void GatJgadmin();                     // 获取激光参数
    void GatXJadmin();
   

signals:
    // OCR模块信号
    void RunOcr();                         // 运行OCR识别信号
    void RunShow();                        // 运行显示信号
    void RunRotate();                      // 运行旋转信号
    void AlarmSignal();                    // 报警信号
    void UNAlarmSignal();                  // 取消报警信号
    void camlog();                         // 相机日志信号
    void resizeimage();                    // 调整图像尺寸信号
    void CamError();                       // 相机错误信号
   // void SetCodeIndexSignal(int index);    // 设置代码索引信号

    // =======================================================================
    // 10. LibreCAD原生公共方法
    // =======================================================================
public:
    QC_ApplicationWindow();                // 构造函数
    ~QC_ApplicationWindow();               // 析构函数

    void initSettings();                   // 初始化应用程序设置
    void storeSettings();                  // 保存应用程序设置
    bool queryExit(bool force);            // 查询退出，提示保存
    virtual void keyPressEvent(QKeyEvent* e) override;  // 按键事件处理
    void setRedoEnable(bool enable);       // 设置重做按钮启用状态
    void setUndoEnable(bool enable);       // 设置撤销按钮启用状态
    bool loadStyleSheet(QString path);     // 加载样式表文件
   // RS_MText* mtext;
   // void editExistingMText(RS_MText* mtext);
 
    QMap<QString, QAction*> a_map;         // 动作映射表，按键快捷键绑定
    LC_ActionGroupManager* ag_manager{ nullptr };  // 动作组管理器

public slots:
    // LibreCAD槽函数声明
    void relayAction(QAction* q_action);   // 转发动作
    void slotFocus();                      // 聚焦
    void slotBack();                       // 返回
    void slotKillAllActions();             // 终止所有动作
    void slotEnter();                      // 回车确认
    void slotFocusCommandLine();           // 聚焦命令行
    void slotError(const QString& msg);    // 错误处理

    // 窗口管理
    void slotWindowActivated(int);
    void slotWindowActivated(QMdiSubWindow* w);
    void slotWindowsMenuAboutToShow();
    void slotWindowsMenuActivated(bool);
    void slotCascade();                    // 层叠窗口
    void slotTile();                       // 平铺窗口
    void slotTileHorizontal();             // 水平平铺
    void slotTileVertical();               // 垂直平铺
    void slotSetMaximized();               // 最大化

    // 标签页管理
    void slotTabShapeRounded();            // 圆角标签
    void slotTabShapeTriangular();         // 三角形标签
    void slotTabPositionNorth();           // 标签在顶部
    void slotTabPositionSouth();           // 标签在底部
    void slotTabPositionEast();            // 标签在右侧
    void slotTabPositionWest();            // 标签在左侧
    void slotToggleTab();                  // 切换标签
    void slotZoomAuto();                   // 自动缩放

    // 属性变化
    void slotPenChanged(RS_Pen p);         // 笔属性变化
    void slotSnapsChanged(RS_SnapMode s);  // 捕捉模式变化
    void slotEnableActions(bool enable);   // 启用/禁用动作

    // 文件操作
    QC_MDIWindow* slotFileNew(RS_Document* doc = nullptr);  // 新建文件
    void slotFileNewNew();                 // 新建（基于模板）
    void slotFileNewTemplate();            // 从模板新建
    void slotFileOpen();                   // 打开文件
    void slotFileOpen(const QString& fileName, RS2::FormatType type);  // 打开指定类型
    void slotFileOpen(const QString& fileName);  // 打开文件（自动检测类型）
    void slotFileOpenRecent(QAction* action);  // 打开最近文件
    void slotFileSave();                   // 保存文件
    void slotFileSaveAs();                 // 另存为
    bool slotFileSaveAll();                // 保存所有文件
    void slotFileAutoSave();               // 自动保存
    void slotFileExport();                 // 导出文件
    bool slotFileExport(const QString& name,
        const QString& format,
        QSize size,
        QSize borders,
        bool black,
        bool bw = true);                   // 导出为位图
    void slotFileClosing(QC_MDIWindow*);   // 文件关闭中
    bool slotFileCloseAll();               // 关闭所有文件
    void slotFilePrint(bool printPDF = false);  // 打印
    void slotFilePrintPDF();               // 打印为PDF
    void slotFilePrintPreview(bool on);    // 打印预览
    void slotFileQuit();                   // 退出程序

    // 视图控制
    void slotViewGrid(bool toggle);        // 切换网格显示
    void slotViewDraft(bool toggle);       // 切换草稿模式
    void slotViewStatusBar(bool toggle);   // 切换状态栏

    void slotOptionsGeneral();             // 常规选项
    void slotImportBlock();                // 导入块
    void showAboutWindow();                // 显示关于窗口
    void slotUpdateActiveLayer();          // 更新活动图层
    void execPlug();                       // 执行插件
    void toggleFullscreen(bool checked);   // 切换全屏
    void setPreviousZoomEnable(bool enable);  // 设置前一个缩放启用
    void hideOptions(QC_MDIWindow*);       // 隐藏选项
    void widgetOptionsDialog();            // 部件选项对话框
    void modifyCommandTitleBar(Qt::DockWidgetArea area);  // 修改命令标题栏
    void reloadStyleSheet();               // 重新加载样式表
    void showDeviceOptions();              // 显示设备选项
    void updateDevice(QString);            // 更新设备
    void invokeMenuCreator();              // 调用菜单创建器
    void invokeToolbarCreator();           // 调用工具栏创建器
    void createToolbar(const QString& toolbar_name);  // 创建工具栏
    void destroyToolbar(const QString& toolbar_name); // 销毁工具栏
    void destroyMenu(const QString& activator);  // 销毁菜单
    void unassignMenu(const QString& activator, const QString& menu_name);  // 取消分配菜单
    void assignMenu(const QString& activator, const QString& menu_name);  // 分配菜单
    void invokeMenuAssigner(const QString& menu_name);  // 调用菜单分配器
    void updateMenu(const QString& menu_name);  // 更新菜单
    void invokeLicenseWindow();            // 调用许可证窗口

signals:
    void gridChanged(bool on);             // 网格变化信号
    void draftChanged(bool on);            // 草稿模式变化信号
    void printPreviewChanged(bool on);     // 打印预览变化信号
    void windowsChanged(bool windowsLeft); // 窗口变化信号

public:
    /**
     * @brief 获取应用程序窗口实例
     *
     * 单例模式访问点，提供全局访问
     *
     * @return QC_ApplicationWindow* 应用程序窗口指针
     */
    static QC_ApplicationWindow* getAppWindow() {
        return appWindow;
    }

    /**
     * @brief 获取MDI区域
     */
    QMdiArea const* getMdiArea() const;
    QMdiArea* getMdiArea();

    /**
     * @brief 获取当前活动的MDI窗口
     */
    const QC_MDIWindow* getMDIWindow() const;
    QC_MDIWindow* getMDIWindow();

    /**
     * @brief 获取当前活动的图形视图
     */
    const RS_GraphicView* getGraphicView() const;
    RS_GraphicView* getGraphicView();

    /**
     * @brief 获取当前活动的文档
     */
    const RS_Document* getDocument() const;
    RS_Document* getDocument();

    /**
     * @brief 创建新文档
     */
    void createNewDocument(const QString& fileName = QString(), RS_Document* doc = nullptr);

    void redrawAll();                      // 重绘所有
    void updateGrids();                    // 更新网格

    QG_BlockWidget* getBlockWidget(void) { return blockWidget; }  // 获取块部件
    QG_SnapToolBar* getSnapToolBar(void) { return snapToolBar; }  // 获取捕捉工具栏
    QG_SnapToolBar const* getSnapToolBar(void) const { return snapToolBar; }

    /**
     * @brief 查找包含指定文档的窗口
     */
    QC_MDIWindow* getWindowWithDoc(const RS_Document* doc);

protected:
    void closeEvent(QCloseEvent*) override;  // 关闭事件
    virtual void dropEvent(QDropEvent* e) override;  // 拖放事件
    virtual void dragEnterEvent(QDragEnterEvent* event) override;  // 拖入事件
    void changeEvent(QEvent* event) override;  // 变化事件

private:
    QMenu* createPopupMenu() override;  // 创建弹出菜单
    QString format_filename_caption(const QString& qstring_in);  // 格式化文件名标题
    bool slotFileNewHelper(QString fileName, QC_MDIWindow* w = nullptr);  // 新建文件助手
    void doArrangeWindows(RS2::SubWindowMode mode, bool actuallyDont = false);  // 排列窗口
    void setTabLayout(RS2::TabShape s, RS2::TabPosition p);  // 设置标签布局
    bool doSave(QC_MDIWindow* w, bool forceSaveAs = false);  // 执行保存
    void doClose(QC_MDIWindow* w, bool activateNext = true);  // 执行关闭
    void doActivate(QMdiSubWindow* w);  // 执行激活
    int showCloseDialog(QC_MDIWindow* w, bool showSaveAll = false);  // 显示关闭对话框
    void enableFileActions(QC_MDIWindow* w);  // 启用文件动作
    void updateWindowTitle(QWidget* w);  // 更新窗口标题
    void loadPlugins();  // 加载插件
    QMenu* findMenu(const QString& searchMenu, const QObjectList thisMenuList, const QString& currentEntry);  // 查找菜单

#ifdef LC_DEBUGGING
    LC_SimpleTests* m_pSimpleTest{ nullptr };  // 调试模式下的简单测试
#endif

    // =======================================================================
    // 11. LibreCAD私有成员
    // =======================================================================
    static QC_ApplicationWindow* appWindow;  // 应用程序窗口单例实例指针
    QTimer* autosaveTimer{ nullptr };        // 自动保存定时器
    QG_ActionHandler* actionHandler{ nullptr };  // 动作处理

    // MDI相关
    QMdiArea* mdiAreaCAD{ nullptr };         // CAD MDI区域
    QMdiSubWindow* activedMdiSubWindow{ nullptr };  // 激活的MDI子窗口
    QMdiSubWindow* current_subwindow{ nullptr };    // 当前子窗口

    // 对话框和文件
    QC_DialogFactory* dialogFactory{ nullptr };  // 对话框工厂
    QG_RecentFiles* recentFiles{ nullptr };      // 最近文件列表

    // 停靠部件
    DockAreas dock_areas;                       // 停靠区域动作

    // 界面部件
    QG_LayerWidget* layerWidget{ nullptr };     // 图层部件
    QG_BlockWidget* blockWidget{ nullptr };     // 块部件
    QG_LibraryWidget* libraryWidget{ nullptr }; // 库部件
    QG_CommandWidget* commandWidget{ nullptr }; // 命令部件
    LC_PenWizard* pen_wiz{ nullptr };           // 笔向导

    // 状态栏部件
    //QG_CoordinateWidget* coordinateWidget{ nullptr };  // 坐标部件
    QG_MouseWidget* mouseWidget{ nullptr };            // 鼠标部件
    QG_SelectionWidget* selectionWidget{ nullptr };    // 选择部件
    QG_ActiveLayerName* m_pActiveLayerName{ nullptr }; // 活动图层名
    TwoStackedLabels* grid_status{ nullptr };          // 网格状态显示

    // 菜单
    QMenu* windowsMenu{ nullptr };              // 窗口菜单
    QMenu* testMenu{ nullptr };                 // 测试菜单
    QMenu* file_menu{ nullptr };                // 文件菜单

    // 工具栏
    QG_SnapToolBar* snapToolBar{ nullptr };     // 捕捉工具栏
    QG_PenToolBar* penToolBar{ nullptr };       // 笔工具栏
    QToolBar* optionWidget{ nullptr };          // 选项部件

    // 动作
    QAction* previousZoom{ nullptr };           // 前一个缩放动作
    QAction* undoButton{ nullptr };             // 撤销按钮动作
    QAction* redoButton{ nullptr };             // 重做按钮动作
    QAction* scriptOpenIDE{ nullptr };          // 打开脚本IDE动作
    QAction* scriptRun{ nullptr };              // 运行脚本动作
    QAction* helpAboutApp{ nullptr };           // 关于应用动作

    // 状态标志
    bool previousZoomEnable{ false };           // 前一个缩放启用标志
    bool undoEnable{ false };                   // 撤销启用标志
    bool redoEnable{ false };                   // 重做启用标志

    // 列表
    QList<QC_PluginInterface*> loadedPlugins;   // 已加载插件列表
    QList<QAction*> toolbar_view_actions;       // 工具栏视图动作列表
    QList<QAction*> dockwidget_view_actions;    // 停靠部件视图动作列表
    QList<QC_MDIWindow*> window_list;           // 窗口列表
    QList<QAction*> recentFilesAction;          // 最近文件动作列表

    QStringList openedFiles;                    // 打开的文件列表

    // 字符串
    QString style_sheet_path;                   // 样式表文件路径

private:
    // =======================================================================
    // 12. 自定义扩展成员
    // =======================================================================
    QToolBar* extensionsToolBar;   // 扩展工具栏，添加激光打标功能
    QAction* actionCustom1;        // 自定义动作1：发送图形到激光设备
    QAction* actionCustom2;        // 自定义动作2：拆分实体
    QAction* actionCustom3;        // 自定义动作3：绘制校准网格
    QAction* actionCustom4;        // 自定义动作4：生成二维码
    QMenu* extensionsMenu;         // 扩展菜单


public:
  

	//发送当前所有的实体的路径点
    int QC_ApplicationWindow::slotCustomFunction1() {
        PathSender sender(getDocument(), getGraphicView(), this);
        return sender.sendPathPoints();
    }

  
    private:
        Ui::QC_ApplicationWindow *ui;  // 新增UI指针
   

public:
    void onMoveToPositionButtonClicked() {
        EntityMover::moveToPosition(getDocument(), getGraphicView(),
            RS_Vector(33000.0, 33000.0),
            "QC_ApplicationWindow::onMoveToPositionButtonClicked");
    }
    void onMoveUpButtonClicked() {
        int step = ui->lineEdit_15->text().toInt() * 10;
        EntityMover::moveSelected(getDocument(), getGraphicView(),
            RS_Vector(0.0, step),
            "QC_ApplicationWindow::onMoveUpButtonClicked");
    }
    void onMoveDownButtonClicked() {
        int step = ui->lineEdit_15->text().toInt() * 10;
        EntityMover::moveSelected(getDocument(), getGraphicView(),
            RS_Vector(0.0, -step),
            "QC_ApplicationWindow::onMoveDownButtonClicked");
    }
    void onMoveLeftButtonClicked() {
        int step = ui->lineEdit_15->text().toInt() * 10;
        EntityMover::moveSelected(getDocument(), getGraphicView(),
            RS_Vector(-step, 0),
            "QC_ApplicationWindow::onMoveLeftButtonClicked");
    }
    void onMoveRightButtonClicked() {
        int step = ui->lineEdit_15->text().toInt() * 10;
        EntityMover::moveSelected(getDocument(), getGraphicView(),
            RS_Vector(step, 0),
            "QC_ApplicationWindow::onMoveRightButtonClicked");
    }

	////	// 计算选中实体的中心点
 //   RS_Vector calculateSelectionCenter(RS_Document* doc) {
 //       return EntityMover::calculateSelectionCenter(doc);
 //   }

    void onRotateClockwiseButtonClicked() {
        EntityMover::rotateSelected(getDocument(), getGraphicView(), 90.0,
            "QC_ApplicationWindow::onRotateClockwiseButtonClicked");
    }

    
};







//相机回调函数
class CSampleCaptureEventHandler : public ICaptureEventHandler
{
private:
    QC_ApplicationWindow* pdemo;

public:
    CSampleCaptureEventHandler(QC_ApplicationWindow* demo)
        :pdemo(demo)
    {
    }
    void DoOnImageCaptured(CImageDataPointer& objImageDataPointer, void* pUserParam);
};
// 用户定义掉线的处理事件，设备掉线会自动调用的程序
// 需要继承并实现虚基类：IDeviceOfflineEventHandler
class CSampleDeivceOfflineEventHandler :public IDeviceOfflineEventHandler {

private:
    QC_ApplicationWindow* pdemo;
public:
    CSampleDeivceOfflineEventHandler(QC_ApplicationWindow* demo)
        :pdemo(demo)
    {
    }
public:
    // pUserParam用户传入的参数
    void DoOnDeviceOfflineEvent(void* pUserParam);
};


    


#ifdef _WINDOWS
extern Q_CORE_EXPORT int qt_ntfs_permission_lookup;
#endif

#endif

