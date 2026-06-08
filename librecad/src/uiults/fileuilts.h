
#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <QString>
#include <QDebug>
#include"rs_vector.h"
#include <QPainter>
#include "OCRdemo/Jgtext.h"
#include"OCRdemo/Config.h"


namespace FileUtils {

	

	


/**			sendOptimizedPointsUDP_hex
 *		@brief 发送优化后的点集
 *		@param optimizedPaths    点集路径
 * 
 */
	int sendOptimizedPointsUDP_hex(QVector<QVector<QPoint>>& optimizedPaths, const QString& ip = "192.168.1.10", quint16 port = 1234, int nom = 0);
	

	//发送0~9的地址信息 ,即第几个地址到第几个表示0,1,2
	int sendquint256(QVector<int>& Array, const QString& ip = "192.168.1.10", quint16 port = 1234, int nom = 0);

	//静态起始地址
	int sendquint256_static(int begin, int end, const QString& ip = "192.168.1.10", quint16 port = 1234, int nom = 0);


	//发送八个坐标,hh:mm:ss八个字符的坐标
	void sendquint256_4(const QVector<RS_Vector>& positions, const QString& ip, quint16 port, int nom, int num_item,int fondsize=0);


	//发送编码器参数
	int Sendall();

	//发送报警间隔
	int Sendalarm();

	//发送打标参数
	int Sendmarking();

	//发送触发优化
	int Sendkey();

	//发送灯光参数
	int Sendphoto();

	//单发按键
	int SendBKBK(QString positionCommandHeader, QString cmdHex, int ParamValue);

	QByteArray hexStringToByteArray(const QString& hexString);


}
#endif // FILEUTILS_H