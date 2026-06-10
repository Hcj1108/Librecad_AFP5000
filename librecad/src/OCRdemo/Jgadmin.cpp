#include "Jgadmin.h"
#include <QPushButton>
#include <QCloseEvent>

/**
 * @brief 构造函数
 * @param parent 父窗口指针
 *
 * 初始化激光参数配置界面：
 * - 设置 UI 布局（Qt Designer 生成的界面）
 * - 绑定最小化按钮事件
 * - 配置系统标题栏（含关闭按钮）
 * - 固定窗口大小
 */
Jgadmin::Jgadmin(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // 最小化按钮
   /* connect(ui.MIN, &QPushButton::clicked, this, [=] {
        this->setWindowState(Qt::WindowMinimized);
    });*/

    // 窗口样式：标准系统标题栏（含关闭按钮）
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    this->setFixedSize(821, 421);     // 固定窗口大小
}

Jgadmin::~Jgadmin() = default;

/**
 * @brief 设置所有激光参数到界面控件
 * @param p 激光参数结构体引用
 *
 * 将参数结构体中的数据同步显示到各输入控件中。
 * 调用时机：打开界面时从数据库读取配置后调用。
 */
void Jgadmin::setParams(const JgParam& p)
{
    ui.spinBox->setValue(p.power);              // 激光功率(%)
    ui.spinBox_2->setValue(p.freq);             // 激光频率(kHz)
    ui.spinBox_3->setValue(p.kgDelay);          // 开光延时(ms)
    ui.spinBox_4->setValue(p.ggDelay);          // 关光延时(ms)
    ui.spinBox_5->setValue(p.jumpDelay);        // 跳转延时(ms)
    ui.spinBox_7->setValue(p.endDelay);         // 结束延时(ms)
    ui.spinBox_8->setValue(p.gdFilterTime);     // 光电滤波时间(ms)
    ui.spinBox_10->setValue(p.scanW_mm);        // 飞行振镜幅面(mm)
    ui.comboBox_4->setCurrentIndex(p.bmqDirection);      // 编码器方向
    ui.comboBox_5->setCurrentIndex(p.fxdDirection);      // 飞行轴方向
    ui.comboBox_6->setCurrentIndex(p.dbMode);            // 飞行模式
    ui.spinBox_14->setValue(p.bmqZhijing);      // 编码器直径(mm)
    ui.spinBox_15->setValue(p.bmqMaichong);     // 编码器脉冲数(脉冲/转)
    ui.comboBox->setCurrentIndex(p.minThresholdMode);    // 最小触发模式
    ui.spinBox_17->setValue(p.minTriggerTime);           // 最小触发时间(ms)
    ui.spinBox_18->setValue(p.minTriggerDistance);       // 最小触发距离(mm)
    ui.comboBox_2->setCurrentIndex(p.delayTriggerMode);  // 标刻延后触发模式
    ui.spinBox_20->setValue(p.delayTriggerTime);         // 标刻延后触发时间(ms)
    ui.spinBox_21->setValue(p.delayTriggerDistance);     // 标刻延后触发距离(mm)
}

/**
 * @brief 从界面控件读取所有激光参数
 * @return JgParam 结构体
 *
 * 调用时机：保存配置到数据库前调用。
 */
JgParam Jgadmin::getParams() const
{
    JgParam p;
    p.power = ui.spinBox->value();                  // 激光功率(%)
    p.freq = ui.spinBox_2->value();                 // 激光频率(kHz)
    p.kgDelay = ui.spinBox_3->value();              // 开光延时(ms)
    p.ggDelay = ui.spinBox_4->value();              // 关光延时(ms)
    p.jumpDelay = ui.spinBox_5->value();            // 跳转延时(ms)
    p.endDelay = ui.spinBox_7->value();             // 结束延时(ms)
    p.gdFilterTime = ui.spinBox_8->value();         // 光电滤波时间(ms)
    p.scanW_mm = ui.spinBox_10->value();            // 飞行振镜幅面(mm)
    p.bmqDirection = ui.comboBox_4->currentIndex(); // 编码器方向
    p.fxdDirection = ui.comboBox_5->currentIndex(); // 飞行轴方向
    p.dbMode = ui.comboBox_6->currentIndex();       // 飞行模式
    p.bmqZhijing = ui.spinBox_14->value();          // 编码器直径(mm)
    p.bmqMaichong = ui.spinBox_15->value();         // 编码器脉冲数(脉冲/转)
    p.minThresholdMode = ui.comboBox->currentIndex();       // 最小触发模式
    p.minTriggerTime = ui.spinBox_17->value();              // 最小触发时间(ms)
    p.minTriggerDistance = ui.spinBox_18->value();          // 最小触发距离(mm)
    p.delayTriggerMode = ui.comboBox_2->currentIndex();     // 标刻延后触发模式
    p.delayTriggerTime = ui.spinBox_20->value();            // 标刻延后触发时间(ms)
    p.delayTriggerDistance = ui.spinBox_21->value();        // 标刻延后触发距离(mm)
    return p;
}

/**
 * @brief 设置激光参数各面板的启用/禁用权限
 * @param penMa       喷码权限(0:禁用,1:启用)
 * @param liuShuixian 流水线设置权限(0:禁用,1:启用)
 * @param chuFa       触发优化权限(0:禁用,1:启用)
 *
 * 根据用户权限控制三个 GroupBox 的可编辑状态。
 * 该函数由主窗口在用户登录/切换时调用。
 */
void Jgadmin::setupLaserPermissions(int penMa, int liuShuixian, int chuFa)
{
    ui.groupBox->setEnabled(penMa == 1);        // 喷码参数
    ui.groupBox_2->setEnabled(liuShuixian == 1); // 流水线设置
    ui.groupBox_3->setEnabled(chuFa == 1);       // 触发优化
}

/**
 * @brief 重写关闭事件
 *
 * 点击窗口标题栏的关闭按钮时，隐藏窗口并发射 showmain 信号，
 * 通知主窗口重新显示，而非销毁窗口。
 */
void Jgadmin::closeEvent(QCloseEvent* event)
{
    //this->hide();
    emit showmain();
    event->ignore();  // 阻止真正关闭，只是隐藏
}
