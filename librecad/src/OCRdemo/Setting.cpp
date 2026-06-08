#include "Setting.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QInputDialog>
#include <QDebug>
#include <QColorDialog>
#include "Config.h"

Setting::Setting(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);

  /*  connect(ui.BACK, &QPushButton::clicked, this, [=] {
        if (isautocap) {
            closeautocap();
            ui.toolButton_2->setEnabled(true);
            isautocap = false;
        }
        ui.label->setBackImage(QImage());
        showmain();
    });*/
    connect(ui.toolButton_3, &QPushButton::clicked, this, &Setting::getrect);
    connect(ui.toolButton_6, &QPushButton::clicked, this, &Setting::RaiseGainValue);
    connect(ui.toolButton_8, &QPushButton::clicked, this, &Setting::ReduceGainValue);
    connect(ui.pushButton_12, &QPushButton::clicked, this, &Setting::setRot);
    connect(ui.toolButton_2, &QPushButton::clicked, this, &Setting::caponepic);
    connect(ui.toolButton_5, &QPushButton::clicked, this, &Setting::RaiseExposureTime);
    connect(ui.toolButton_7, &QPushButton::clicked, this, &Setting::ReduceExposureTime);
    connect(ui.pushButton_8, &QPushButton::clicked, this, &Setting::setSharpness);

    SetQSS();
}

Setting::~Setting()
{
}

void Setting::SetQSS()
{
    // 设置窗口标志：保留系统菜单、显示问号(?)按钮、显示关闭(X)按钮
    setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    qApp->installEventFilter(this);

    // 设置按钮图标
    auto setIconBtn = [&](QToolButton* btn, const QString& icon) {
        btn->setIcon(QIcon(icon));
        btn->setIconSize(QSize(51, 51));
    };
  
    ui.lineEdit->setEnabled(false);
    ui.lineEdit_2->setEnabled(false);
    ui.toolButton_2->setEnabled(true);
}


// 在您的窗口类实现文件（如 settingsdialog.cpp）中
void Setting::closeEvent(QCloseEvent* event)
{
    // 复用原有的退出逻辑
    if (isautocap) {
        closeautocap();
        ui.toolButton_2->setEnabled(true);
        isautocap = false;
    }
    ui.label->setBackImage(QImage());
    showmain();

    // 关键：阻止窗口真正关闭（因为您只需要返回主界面）
    event->ignore();
}



void Setting::setbackground(const QImage& img)
{
    if (img.isNull()) return;

    int labelWidth = ui.label->width();
    int labelHeight = ui.label->height();

    if (labelWidth > 0 && labelHeight > 0) {
        QPixmap pixmap = QPixmap::fromImage(img);
        QPixmap scaled = pixmap.scaled(labelWidth, labelHeight,
            Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ImageSize = static_cast<double>(scaled.width()) / img.width();
        ui.label->setBackImage(scaled.toImage());
    } else {
        ImageSize = 1.0;
        ui.label->setBackImage(img);
    }
}

// ─── 获取参数 ─────────────────────────────────────────────────

double Setting::getExposureTime()     { return ui.lineEdit->text().toDouble(); }
double Setting::getTriggerDelay()     { return ui.lineEdit_2->text().toDouble(); }
double Setting::getGainValue()        { return ui.lineEdit_2->text().toDouble(); }
int    Setting::getRot()              { return ui.comboBox->currentIndex(); }
QString Setting::getSharpness()       { return ui.lineEdit_3->text(); }
QRect  Setting::mygetrect()          { return ui.label->getRoiRect(); }

// ─── 统一消息框 ───────────────────────────────────────────────

void Setting::showResult(bool result, const QString& successMsg, const QString& failMsg)
{
    QMessageBox msgBox(
        result ? QMessageBox::Information : QMessageBox::Critical,
        result ? QString::fromLocal8Bit("操作完成") : QString::fromLocal8Bit("操作失败"),
        result ? successMsg : failMsg,
        QMessageBox::Ok, this);
    msgBox.button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定"));
    msgBox.exec();
}

// ─── 各报警回调 ───────────────────────────────────────────────

void Setting::alarmrect(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("设置成功！"),
        QString::fromLocal8Bit("请重新框选范围"));
}
void Setting::alarmexposuretime(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("设置成功！"),
        QString::fromLocal8Bit("请重新输入"));
}
void Setting::alarmGainValue(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("设置成功！"),
        QString::fromLocal8Bit("请重新输入"));
}
void Setting::alarmupdata(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("成功更新配方！"),
        QString::fromLocal8Bit("请检查输入值!"));
}
void Setting::updateDBresult(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("成功更新默认配方！"),
        QString::fromLocal8Bit("请检查输入值!"));
}
void Setting::insertDBresult(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("新建配方成功！"),
        QString::fromLocal8Bit("请检查输入值!"));
}
void Setting::alarmSharpness(bool result)
{
    showResult(result,
        QString::fromLocal8Bit("设置成功！"),
        QString::fromLocal8Bit("锐化值范围0-3"));
}

// ─── 设置参数 ─────────────────────────────────────────────────

void Setting::SetSetting(int ExposureTime, double rot, double GainValue, double Sharpness)
{
    ui.lineEdit_3->setText(QString::number(Sharpness));
    ui.lineEdit->setText(QString::number(ExposureTime));
    ui.lineEdit_2->setText(QString::number(GainValue));

    if (isfistopen) {
        firstopen();
        isfistopen = false;
    }

    if      (rot == 0)   ui.comboBox->setCurrentIndex(0);
    else if (rot == 90)  ui.comboBox->setCurrentIndex(1);
    else if (rot == 180) ui.comboBox->setCurrentIndex(2);
    else if (rot == 270) ui.comboBox->setCurrentIndex(3);
}

// ─── 参数微调 ─────────────────────────────────────────────────

void Setting::RaiseExposureTime()
{
    int val = ui.lineEdit->text().toInt();
    if (val + 50 <= 3000) {
        ui.lineEdit->setText(QString::number(val + 50));
        setExposureTime();
    }
}

void Setting::ReduceExposureTime()
{
    int val = ui.lineEdit->text().toInt();
    if (val - 50 >= 50) {
        ui.lineEdit->setText(QString::number(val - 50));
        setExposureTime();
    }
}

void Setting::RaiseGainValue()
{
    int val = ui.lineEdit_2->text().toInt();
    if (val + 1 <= 24) {
        ui.lineEdit_2->setText(QString::number(val + 1));
        setGainValue();
    }
}

void Setting::ReduceGainValue()
{
    int val = ui.lineEdit_2->text().toInt();
    if (val - 1 >= 0) {
        ui.lineEdit_2->setText(QString::number(val - 1));
        setGainValue();
    }
}
