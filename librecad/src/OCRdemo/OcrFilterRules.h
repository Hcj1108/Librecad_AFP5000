#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QToolButton>
#include <QPushButton>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>
#include "rollingbox.h"             // 滚动条部件日期选择器
#include <string>
#include "Config.h"                  // 数据库模块

QT_BEGIN_NAMESPACE
namespace Ui { class OcrFilterRulesClass; };
QT_END_NAMESPACE

class OcrFilterRules : public QWidget
{
	Q_OBJECT

public:
	OcrFilterRules(QWidget *parent = nullptr);
	~OcrFilterRules();

	QString SCHEMEtext;
	bool IsSchemeComboBoxcode = true;       // 配方组合框代码标志

	void  closeEvent(QCloseEvent* event);

	void SetOcrFilterRules(QString _SCHEME, std::string CustomStr, std::string CustomStr_2,
		std::string CustomStr_3, std::string CustomStr_4, std::string CustomStr_5, std::string CustomStr_6,
		bool SCenabled, bool BZenabled, bool EWenabled, int Savemonth, int Saveyear, int save_time, QString Start_Data_Time, QString Save_Time, int CodeIndex ,bool Page);
	void SelectTime();
	QString CaculateTime(int year, int month, int day,int save_days, int save_months, int save_years);
	void UpdataTime();
	void toggleSchemeButton(QWidget* activeBtn, QWidget* inactiveBtn, bool& flag, bool value);
	void clearCustomFields();               //清除自定义字段内容
	void saveCustomFields();                //保存自定义字段内容

signals:
	void showmain();
private:
	Ui::OcrFilterRulesClass *ui;
};
