#include "XJadmin.h"
#include <QPushButton>
#include <QCloseEvent>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QFrame>
#include <QApplication>
#include <QScreen>

/**
 * @brief 构造函数
 * @param parent 父窗口指针
 *
 * 初始化相机参数配置界面：
 * - 设置 UI 布局
 * - 绑定最小化按钮和颜色选择按钮
 * - 配置系统标题栏（含关闭按钮）
 * - 固定窗口大小
 */
XJadmin::XJadmin(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);

    // 颜色选择按钮
    connect(ui.toolButton, &QPushButton::clicked, this, &XJadmin::onColorButtonClicked);

    // 窗口样式：标准系统标题栏（含关闭按钮）
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    
}

XJadmin::~XJadmin() = default;

/**
 * @brief 设置所有参数到界面控件
 * @param p 相机参数结构体引用
 *
 * 调用时机：打开界面时从数据库读取配置后调用。
 */
void XJadmin::setParams(const XjParam& p)
{
    // 光源设置
    ui.spinBox->setValue(p.r);
    ui.spinBox_2->setValue(p.g);
    ui.spinBox_3->setValue(p.b);
    ui.spinBox_4->setValue(p.rgbTime);
    ui.comboBox_2->setCurrentIndex(p.rgbMode);
    // 更新颜色按钮样式
    QColor color(p.r, p.g, p.b);
    if (color.isValid()) {
        ui.toolButton->setStyleSheet(
            "background-color: " + color.name() + ";"
            "color: " + (color.lightness() > 128 ? "black" : "white") + ";"
        );
    }

    // 剔除设置
    ui.spinBox_6->setValue(p.dcLength);
    ui.spinBox_7->setValue(p.outputLocationMin);
    ui.spinBox_8->setValue(p.outputLocationMax);
    ui.spinBox_9->setValue(p.gapCount);
    ui.spinBox_10->setValue(p.keepCount);
    ui.spinBox_14->setValue(p.bmqZhijing);
    ui.spinBox_15->setValue(p.bmqMaichong);

    // 触发设置
    ui.comboBox_4->setCurrentIndex(p.minThresholdMode);
    ui.spinBox_17->setValue(p.minTriggerTime);
    ui.spinBox_18->setValue(p.minTriggerDistance);
    ui.comboBox_3->setCurrentIndex(p.delayTriggerMode);
    ui.spinBox_23->setValue(p.delayTriggerTime);
    ui.spinBox_24->setValue(p.delayTriggerDistance);
}

/**
 * @brief 从界面控件读取所有参数
 * @return XjParam 结构体
 *
 * 调用时机：保存配置到数据库前调用。
 */
XjParam XJadmin::getParams() const
{
    XjParam p;
    // 光源设置
    p.r = ui.spinBox->value();
    p.g = ui.spinBox_2->value();
    p.b = ui.spinBox_3->value();
    p.rgbTime = ui.spinBox_4->value();
    p.rgbMode = ui.comboBox_2->currentIndex();

    // 剔除设置
    p.dcLength = ui.spinBox_6->value();
    p.outputLocationMin = ui.spinBox_7->value();
    p.outputLocationMax = ui.spinBox_8->value();
    p.gapCount = ui.spinBox_9->value();
    p.keepCount = ui.spinBox_10->value();
    p.bmqZhijing = ui.spinBox_14->value();
    p.bmqMaichong = ui.spinBox_15->value();

    // 触发设置
    p.minThresholdMode = ui.comboBox_4->currentIndex();
    p.minTriggerTime = ui.spinBox_17->value();
    p.minTriggerDistance = ui.spinBox_18->value();
    p.delayTriggerMode = ui.comboBox_3->currentIndex();
    p.delayTriggerTime = ui.spinBox_23->value();
    p.delayTriggerDistance = ui.spinBox_24->value();
    return p;
}

/**
 * @brief 重写关闭事件
 *
 * 点击窗口标题栏的关闭按钮时，隐藏窗口并发射 showmain 信号，
 * 通知主窗口重新显示，而非销毁窗口。
 */
void XJadmin::closeEvent(QCloseEvent* event)
{
    // 隐藏当前窗口，而非销毁
  /*  this->hide();*/
    // 通知主窗口重新显示
    emit showmain();
    // 阻止真正关闭
    event->ignore();
}

/**
 * @brief 颜色选择按钮点击事件
 *
 * 弹出自定义颜色选择对话框，包含 R/G/B 三个滑块和实时预览。
 * 替代 Qt 自带的复杂 QColorDialog。
 */
void XJadmin::onColorButtonClicked()
{
    // 创建自定义对话框
    QDialog dlg(this);
    dlg.setWindowTitle(QString::fromLocal8Bit("\xd1\xa1\xd4\xf1\xd1\xd5\xc9\xab"));
    dlg.setFixedSize(360, 300);

    QVBoxLayout* mainLayout = new QVBoxLayout(&dlg);
    mainLayout->setSpacing(12);
    mainLayout->setContentsMargins(20, 16, 20, 16);

    // 颜色预览区域
    QFrame* preview = new QFrame(&dlg);
    preview->setMinimumHeight(60);
    preview->setStyleSheet(
        "background-color: rgb(" +
        QString::number(ui.spinBox->value()) + "," +
        QString::number(ui.spinBox_2->value()) + "," +
        QString::number(ui.spinBox_3->value()) + ");" +
        "border: 2px solid #bdc3c7; border-radius: 6px;"
    );
    mainLayout->addWidget(preview);

    // 当前颜色十六进制显示
    QLabel* hexLabel = new QLabel(&dlg);
    hexLabel->setAlignment(Qt::AlignCenter);
    hexLabel->setStyleSheet("font: bold 14px 'Microsoft YaHei'; color: #2c3e50;");
    mainLayout->addWidget(hexLabel);

    // R/G/B 滑块
    struct Channel {
        QString name;
        int* value;
        QSlider* slider;
        QLabel* label;
        int initVal;
    };

    int r0 = ui.spinBox->value();
    int g0 = ui.spinBox_2->value();
    int b0 = ui.spinBox_3->value();

    auto refreshColor = [&]() {
        int r = r0, g = g0, b = b0;

        // 查找滑块找到当前值（lambda 内无法直接访问 channel 数组）
        QList<QSlider*> sliders = dlg.findChildren<QSlider*>();
        for (QSlider* s : sliders) {
            if (s->objectName() == "sliderR") r = s->value();
            if (s->objectName() == "sliderG") g = s->value();
            if (s->objectName() == "sliderB") b = s->value();
        }

        preview->setStyleSheet(
            "background-color: rgb(" + QString::number(r) + "," +
            QString::number(g) + "," + QString::number(b) + ");" +
            "border: 2px solid #bdc3c7; border-radius: 6px;"
        );
        hexLabel->setText(QString("#%1%2%3")
            .arg(r, 2, 16, QChar('0'))
            .arg(g, 2, 16, QChar('0'))
            .arg(b, 2, 16, QChar('0')).toUpper());
    };

    auto makeSlider = [&](const QString& name, int initVal, const QString& color) {
        QHBoxLayout* row = new QHBoxLayout();

        QLabel* lbl = new QLabel(name + ":", &dlg);
        lbl->setFixedWidth(20);
        lbl->setStyleSheet("font: bold 13px 'Microsoft YaHei'; color: " + color + ";");
        row->addWidget(lbl);

        QSlider* slider = new QSlider(Qt::Horizontal, &dlg);
        slider->setObjectName("slider" + name);
        slider->setRange(0, 255);
        slider->setValue(initVal);
        slider->setStyleSheet(
            "QSlider::groove:horizontal { height: 8px; border-radius: 4px; background: #dcdde1; }"
            "QSlider::handle:horizontal { width: 18px; height: 18px; margin: -5px 0; "
            "border-radius: 9px; background: " + color + "; }"
            "QSlider::sub-page:horizontal { background: " + color + "; border-radius: 4px; }"
        );
        row->addWidget(slider);

        QLabel* valLabel = new QLabel(QString::number(initVal), &dlg);
        valLabel->setFixedWidth(28);
        valLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        valLabel->setStyleSheet("font: bold 13px 'Microsoft YaHei'; color: #2c3e50;");
        row->addWidget(valLabel);

        mainLayout->addLayout(row);

        connect(slider, &QSlider::valueChanged, &dlg, [=](int v) {
            valLabel->setText(QString::number(v));
            refreshColor();
        });
    };

    makeSlider("R", r0, "#e74c3c");
    makeSlider("G", g0, "#27ae60");
    makeSlider("B", b0, "#3498db");

    refreshColor();

    // 按钮
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addStretch();

    QPushButton* okBtn = new QPushButton(QString::fromLocal8Bit("\xc8\xb7\xb6\xa8"), &dlg);
    okBtn->setStyleSheet("QPushButton{font: bold 13px 'Microsoft YaHei'; background: #3498db; color: white; border-radius: 6px; padding: 8px 24px;}QPushButton:hover{background: #2980b9;}");
    btnLayout->addWidget(okBtn);

    QPushButton* cancelBtn = new QPushButton(QString::fromLocal8Bit("\xc8\xa1\xcf\xfb"), &dlg);
    cancelBtn->setStyleSheet("QPushButton{font: bold 13px 'Microsoft YaHei'; background: #95a5a6; color: white; border-radius: 6px; padding: 8px 24px;}QPushButton:hover{background: #7f8c8d;}");
    btnLayout->addWidget(cancelBtn);

    mainLayout->addLayout(btnLayout);

    connect(okBtn, &QPushButton::clicked, &dlg, &QDialog::accept);
    connect(cancelBtn, &QPushButton::clicked, &dlg, &QDialog::reject);

    if (dlg.exec() == QDialog::Accepted) {
        // 读取滑块值
        QList<QSlider*> sliders = dlg.findChildren<QSlider*>();
        int r = r0, g = g0, b = b0;
        for (QSlider* s : sliders) {
            if (s->objectName() == "sliderR") r = s->value();
            if (s->objectName() == "sliderG") g = s->value();
            if (s->objectName() == "sliderB") b = s->value();
        }

        ui.spinBox->setValue(r);
        ui.spinBox_2->setValue(g);
        ui.spinBox_3->setValue(b);

        ui.toolButton->setStyleSheet(
            "background-color: rgb(" + QString::number(r) + "," +
            QString::number(g) + "," + QString::number(b) + ");"
            "color: " + ((r * 299 + g * 587 + b * 114) / 1000 > 128 ? "black" : "white") + ";"
        );
    }
}
