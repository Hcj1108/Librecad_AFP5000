#include "OcrFilterRules.h"
#include "ui_OcrFilterRules.h"

#include <QValidator>

OcrFilterRules::OcrFilterRules(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::OcrFilterRulesClass())
{
	ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [=] {
        this->hide();
        emit showmain();
        });
	// 转发控件事件
	connect(ui->zdybutton_2, &QPushButton::clicked, this, &OcrFilterRules::clearCustomFields);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &OcrFilterRules::SelectTime);
    connect(ui->pushButton_4, &QPushButton::clicked, this, [=] {

        CustomStr_6 = "";
        CustomStr_6.append(std::string(ui->lineEdit_9->text().toLocal8Bit()));
        string delestr = std::string(SCHEMEtext.toLocal8Bit());
        if (AlterSchemeContent(delestr))
        {
            QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("保存成功  "), QString::fromLocal8Bit("保存成功 "), QMessageBox::Ok, this);
            msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBox->show();
        }
        string Log_Str = "*保存检测额外代码内容:\n" + CustomStr_6;
      
        });
    // 第一个comboBox连接
    connect(ui->comboBox_2, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        [=](int index) {
            CodeIndex = index;  // 使用传递的index参数而不是再次获取
            FH = ui->comboBox_2->currentText();
          /*  if (IsSchemeComboBoxcode) {
                IsSchemeComboBoxcode = false;
            }
            else {*/
                bool result = AlterDB(SCHEMEtext.toStdString());
            //}
        });

     // 使用函数指针的Qt5兼容方式
    connect(ui->spinBox,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        [=](int value) {
            save_time = value;  // 使用传递的值而不是再次获取
            UpdataTime();
        });
    connect(ui->spinBox_2,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        [=](int value) {
            Savemonth = value;  // 使用传递的值而不是再次获取
            UpdataTime();
        });
    connect(ui->spinBox_3,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        [=](int value) {
            Saveyear = value;  // 使用传递的值而不是再次获取
            UpdataTime();
        });
    connect(ui->toolButton_18, &QPushButton::clicked, this, [=] {
        toggleSchemeButton(ui->toolButton_18, ui->toolButton_20, SCenabled, true);
        });
    connect(ui->toolButton_20, &QPushButton::clicked, this, [=] {
        toggleSchemeButton(ui->toolButton_20, ui->toolButton_18, SCenabled, false);
        });
    connect(ui->toolButton_22, &QPushButton::clicked, this, [=] {
        toggleSchemeButton(ui->toolButton_22, ui->toolButton_23, BZenabled, true);
        });
    connect(ui->toolButton_23, &QPushButton::clicked, this, [=] {
        toggleSchemeButton(ui->toolButton_23, ui->toolButton_22, BZenabled, false);
        });
    connect(ui->toolButton_24, &QPushButton::clicked, this, [=] {
        toggleSchemeButton(ui->toolButton_24, ui->toolButton_29, EWenabled, true);
        });
    connect(ui->toolButton_29, &QPushButton::clicked, this, [=] {
        toggleSchemeButton(ui->toolButton_29, ui->toolButton_24, EWenabled, false);
        });
	
	connect(ui->pushButton_6, &QPushButton::clicked, this, &OcrFilterRules::saveCustomFields);
	
}

OcrFilterRules::~OcrFilterRules()
{
	delete ui;
}


void  OcrFilterRules::closeEvent(QCloseEvent* event)
{
    this->hide();
    emit showmain();
    event->ignore();
}
// ─── 设置配方参数 ─────────────────────────────────────────────

void OcrFilterRules::SetOcrFilterRules(QString _SCHEME, std::string CustomStr, std::string CustomStr_2,
    std::string CustomStr_3, std::string CustomStr_4,std::string CustomStr_5, std::string CustomStr_6,
    bool SCenabled ,bool BZenabled ,bool EWenabled, int Savemonth, int Saveyear, int save_time , QString Start_Data_Time ,QString Save_Time , int CodeIndex , bool Page)
{
    SCHEMEtext = _SCHEME;

	ui->stackedWidget->setCurrentIndex(Page);

	auto setText = [&](QLineEdit* edit, const
		std::string& str) {

			edit->setText(QString::fromLocal8Bit(str.c_str()));
		};
    setText(ui->lineEdit_4, CustomStr);
    setText(ui->lineEdit_7, CustomStr_2);
    setText(ui->lineEdit_6, CustomStr_3);
    setText(ui->lineEdit_8, CustomStr_4);
    setText(ui->lineEdit_5, CustomStr_5);
    setText(ui->lineEdit_9, CustomStr_6);


    ui->spinBox->setValue(save_time);
    ui->spinBox_2->setValue(Savemonth);
    ui->spinBox_3->setValue(Saveyear);
	ui->comboBox_2->setCurrentIndex(CodeIndex);
    FH = ui->comboBox_2->currentText();
	ui->lineEdit->setText(Start_Data_Time);
	ui->lineEdit_3->setText(Save_Time);

    auto setToggle = [&](QWidget* onBtn, QWidget* offBtn, bool enabled) {
        onBtn->setStyleSheet(enabled ? "background-color:  #87CEEB;" : "background-color:  #FFFFFF;");
        offBtn->setStyleSheet(enabled ? "background-color:  #FFFFFF;" : "background-color:  #87CEEB;");
        };
    setToggle(ui->toolButton_18, ui->toolButton_20, SCenabled);
    setToggle(ui->toolButton_22, ui->toolButton_23, BZenabled);
    setToggle(ui->toolButton_24, ui->toolButton_29, EWenabled);
}

void OcrFilterRules::SelectTime()
{
    //确认弹窗
    QDialog dialog;
    dialog.setWindowTitle(QString::fromLocal8Bit("选择日期 "));
    dialog.resize(700, 350);

    RollingBox timebox(&dialog);

    //使用QDialogButtonBox简化按钮的创建和连接
    QDialogButtonBox* buttonBox = new QDialogButtonBox(&dialog);
    buttonBox->setGeometry(220, 200, 300, 200);

    QPushButton* okButton = new QPushButton(QString::fromLocal8Bit("确定 "));
    QPushButton* cancelButton = new QPushButton(QString::fromLocal8Bit("取消 "));
    buttonBox->addButton(okButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::ActionRole);
    buttonBox->setStyleSheet("QPushButton { margin-right: 50px; width: 100px; height: 50px; }");

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    int ret = dialog.exec();
    //根据选择进行响应
    if (ret == QDialog::Accepted) {
        year = timebox.readYear();
        month = timebox.readMonth();
        day = timebox.readDay();
        QString year_str, month_str, day_str;
        if (year < 10)
        {
            year_str = "0" + QString::number(year);
        }
        else {
            year_str = QString::number(year);
        }
        if (month < 10)
        {
            month_str = "0" + QString::number(month);
        }
        else {
            month_str = QString::number(month);
        }
        if (day < 10)
        {
            day_str = "0" + QString::number(day);
        }
        else {
            day_str = QString::number(day);
        }

        Start_Data_Time = year_str + month_str + day_str;
        ui->lineEdit->setText(Start_Data_Time);
        Save_Time = CaculateTime(year, month, day, save_time, Savemonth, Saveyear);
        ui->lineEdit_3->setText(Save_Time);
    }
}

QString OcrFilterRules::CaculateTime(int year, int month, int day,
    int save_days, int save_months, int save_years)
{

    QDate baseDate(year, month, day);
    QDate expiryDate = baseDate
        .addYears(save_years)
        .addMonths(save_months);

    // 只有日期没被月末钳位时，才减1天
    if (expiryDate.day() == baseDate.day()) {
        expiryDate = expiryDate.addDays(-1);
    }

    expiryDate = expiryDate.addDays(save_days);
    return expiryDate.toString("yyyyMMdd");
}
void OcrFilterRules::UpdataTime()
{
    auto pad = [](int v) { return QString("%1").arg(v, 2, 10, QChar('0')); };
    Start_Data_Time = pad(year) + pad(month) + pad(day);
    ui->lineEdit->setText(Start_Data_Time);
    save_time = ui->spinBox->value();
    Save_Time = CaculateTime(year, month, day, save_time, Savemonth, Saveyear);
    ui->lineEdit_3->setText(Save_Time);
  
}
//标记开关按钮单选待理
void OcrFilterRules::toggleSchemeButton(QWidget* activeBtn, QWidget* inactiveBtn, bool& flag, bool value)
{
    activeBtn->setStyleSheet("background-color:  #87CEEB;");
    inactiveBtn->setStyleSheet("background-color:  #FFFFFF;");
    flag = value;
    
    string str = std::string(SCHEMEtext.toLocal8Bit());
    AlterSchemeContent(str);
}

void  OcrFilterRules::clearCustomFields() {
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
}
void  OcrFilterRules::saveCustomFields() {
    CustomStr = "";
    CustomStr.append(std::string(ui->lineEdit_4->text().toLocal8Bit()));
    CustomStr_2 = "";
    CustomStr_2.append(std::string(ui->lineEdit_7->text().toLocal8Bit()));
    CustomStr_3 = "";
    CustomStr_3.append(std::string(ui->lineEdit_6->text().toLocal8Bit()));
    CustomStr_4 = "";
    CustomStr_4.append(std::string(ui->lineEdit_8->text().toLocal8Bit()));
    CustomStr_5 = "";
    CustomStr_5.append(std::string(ui->lineEdit_5->text().toLocal8Bit()));

    string delestr = std::string(SCHEMEtext.toLocal8Bit());
    AlterSchemeContent(delestr);

}