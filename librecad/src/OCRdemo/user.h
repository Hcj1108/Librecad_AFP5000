#pragma once

#include <QMainWindow>
#include "ui_user.h"
#include <QLineEdit>  // 必须包含的头文件
#include<QDebug>
#include<QTimer>
#include <QToolTip>  // 必须包含的头文件
#include <QUdpSocket>
#include <qendian.h>
#include<QPushButton>
#include "Config.h"
#include "udptimesender.h"
#include "SenderBinUdp.h"
class user : public QMainWindow
{
	Q_OBJECT

public:


	user(QWidget* parent = nullptr);
	~user();
	void SetQSS();
	bool eventFilter(QObject* obj, QEvent* evt);//用于拖动设置页面
	QString openBinFilePath;
	//SimpleUdpSender* simpsender = SimpleUdpSender::instance(); // 获取SimpleUdpSender的实例
	UdpTimeSender timeSender;        //看门狗功能,持续发送时间戳
	SenderBinUdp senderBinUdp;
	
	void openBinFile();
	void setUser(int userindex, int PenMa, int LiuShuixian, int Chufa, int FangZhen, int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi,int TraverseUser, std::vector<std::string> Name);
	void setSwitchUser(int PenMa, int LiuShuixian, int Chufa, int FangZhen, int PeiFang, int xiangJi, int OCR, int YongHu, int BianJi);
	int getPenMa();
	int getLiuShuixian();
	int getChufa();
	int getFangZhen();
	int getPeiFang();
	int getXiangJi();
	int getOCR();
	int getYongHu();
	int getZhuangTai();
	std::string getTraverseUsername();
	std::string getpassword();
	int getPenMa1();
	int getLiuShuixian1();
	int getChufa1();
	int getFangZhen1();
	int getPeiFang1();
	int getXiangJi1();
	int getOCR1();
	int getYongHu1();
	int getZhuangTai1();

	void eraseCompleteSignal();
	void writeCompleteSignal();
	//void readCompleteSignal();
	
	std::string getTraverseUsername1();
	std::string getpassword1();
private:
	Ui::userClass ui;

signals:

	void showmain();
	void addUser();
	void delUser();
	void SwitchUser();
	void alterpassword();
	void stopSend();
	void startSend();
	void usereraseCompleteSignal();  // 擦除完成信号
	void userwriteCompleteSignal(); // 写入完成信号
	void userreadCompleteSignal();  // 读取完成信号
};

