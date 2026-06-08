#include "fileuilts.h"
// FileUtils.cpp


#include <iomanip> // 注意要加这个头文件

#include <iostream>
#include <QUdpSocket>
#include <QtEndian>
#include <QPainter>
#include<QPainterPath>



#include <QString>
#include <QDebug>
#include <QtNetwork/qudpsocket.h>
#include <QDateTime>
#include <QDebug>
#include <QThread>
//#include "PixelCorrector.h"


// 实现时必须明确指定命名空间
namespace FileUtils {


	//目前再用的版本储存坐标
    //重发尾点,尾点发了两次
	int sendOptimizedPointsUDP_hex(QVector<QVector<QPoint>>& optimizedPaths, const QString& ip,
		quint16 port, int nom)
	{
		

		// 创建一条路径，包含正方形的顶点
		QVector<QPoint> squarePath;
		squarePath.append(QPoint(10000, 30768)); // 左下
		squarePath.append(QPoint(10000, 34768)); // 左上
		squarePath.append(QPoint(15000, 34768)); // 右上
		squarePath.append(QPoint(15000, 30768)); // 右下
		squarePath.append(QPoint(10000, 30768)); // 左下 (重复)

		// 将这条路径添加到 optimizedPaths 中
		optimizedPaths.append(squarePath);

		QUdpSocket udpSocket;
		const int MAX_POINTS_PER_PACKET = 46;  // 46 * 32 = 1472 bytes

		QByteArray batchBuffer;
		batchBuffer.reserve(MAX_POINTS_PER_PACKET * 32);
		int pointsInBatch = 0;

		auto flushBatch = [&]() {
			if (pointsInBatch > 0) {
				//qDebug() << "[UDP] batch hex:\n" << batchBuffer.toHex(' ').toUpper();
				udpSocket.writeDatagram(batchBuffer, QHostAddress(ip), port);
				batchBuffer.clear();
				pointsInBatch = 0;
			}
		};

		auto appendPoint = [&](quint64 hh, quint64 hl, quint64 lh, quint64 ll) {
			hh = qToBigEndian(hh);
			hl = qToBigEndian(hl);
			lh = qToBigEndian(lh);
			ll = qToBigEndian(ll);
			batchBuffer.append(reinterpret_cast<const char*>(&hh), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&hl), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&lh), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&ll), 8);
			if (++pointsInBatch >= MAX_POINTS_PER_PACKET) flushBatch();
		};

		const int stepThreshold = 10;
		const int stepThresholdSquared = stepThreshold * stepThreshold;

		bool hasPreviousPath = false;
		QPoint lastPoint;
		quint64 lastPackedData = 0;
		int i = 0;

		for (int pathIndex = optimizedPaths.size() - 1; pathIndex >= 0; --pathIndex) {

			QVector<QPoint>& path = optimizedPaths[pathIndex];
			i++;

			bool is_first = true;

			for (int i = 0; i < path.size(); ++i) {
				const QPoint& point = path[i];
				bool is_last = (i == path.size() - 1);
				bool is_last_path = (pathIndex == 0);
				bool is_graph_end_point = is_last_path && is_last;

				if (hasPreviousPath && point.x() == lastPoint.x() && point.y() == lastPoint.y()) {
					is_first = false;
					continue;
				}

				bool is_close = false;
				if (!is_first && hasPreviousPath) {
					qint64 dx = static_cast<qint64>(point.x()) - lastPoint.x();
					qint64 dy = static_cast<qint64>(point.y()) - lastPoint.y();
					qint64 distance_squared = dx * dx + dy * dy;
					is_close = (distance_squared <= stepThresholdSquared);
				}

				if (is_first && hasPreviousPath) {
					qint64 dx = static_cast<qint64>(point.x()) - lastPoint.x();
					qint64 dy = static_cast<qint64>(point.y()) - lastPoint.y();
					qint64 distance_squared = dx * dx + dy * dy;

					if (distance_squared <= stepThresholdSquared) {
						is_first = false;// 不视为第一个点
					}
					else {
						quint64 hh = (1ULL << 56);
						quint64 hl = quint64(nom) * 8;
						quint64 lh = 0;
						quint64 packedData = lastPackedData;

						packedData &= ~(1ULL << 39);
						packedData &= ~(1ULL << 38);
						packedData |= (1ULL << 37);

						appendPoint(hh, hl, lh, packedData);
						nom++;
					}
				}
				quint64 hh = (1ULL << 56);
				quint64 hl = quint64(nom) * 8;
				quint64 lh = 0;
				quint64 packedData = 0;

				quint64 x = static_cast<quint16>(point.x());
				qint64 y = static_cast<qint16>(point.y());

				packedData |= (x & 0xFFFF) << 1;
				packedData |= (static_cast<quint64>(y) & 0xFFFF) << 21;

				if (is_first) {
					packedData |= (1ULL << 39);
					is_first = false;
				}
				else {
					if (!is_close) {
						packedData |= (1ULL << 38);
					}
				}

				lastPackedData = packedData;

				appendPoint(hh, hl, lh, packedData);
				nom++;
				lastPoint = point;

				if (packedData & (1ULL << 39)) {
					packedData &= ~(1ULL << 39);
					quint64 hl = quint64(nom) * 8;
					appendPoint(hh, hl, lh, packedData);
					nom++;
				}

				if (is_graph_end_point) {
					quint64 hh = (1ULL << 56);
					quint64 hl = quint64(nom) * 8;
					quint64 lh = 0;
					quint64 packedData = lastPackedData;

					packedData &= ~(1ULL << 39);
					packedData &= ~(1ULL << 38);
					packedData |= (1ULL << 37);

					appendPoint(hh, hl, lh, packedData);
					nom++;
				}
			}

			hasPreviousPath = true;
		}

		flushBatch();
		return nom;
}

	//发送0~9：的起止位信息()
	int sendquint256(QVector<int>& Array, const QString& ip, quint16 port, int nom)
	{
		QUdpSocket udpSocket;
		const int MAX_ENTRIES_PER_PACKET = 46;

		QByteArray batchBuffer;
		batchBuffer.reserve(MAX_ENTRIES_PER_PACKET * 32);
		int entriesInBatch = 0;

		auto flushBatch = [&]() {
			if (entriesInBatch > 0) {
				qDebug() << "[UDP] batch hex:\n" << batchBuffer.toHex(' ').toUpper();
				udpSocket.writeDatagram(batchBuffer, QHostAddress(ip), port);
				batchBuffer.clear();
				entriesInBatch = 0;
			}
		};

		auto appendEntry = [&](const QString& hhStr, quint64 hl, quint64 lh, quint64 ll) {
			QByteArray hh = QByteArray::fromHex(hhStr.toUtf8());
			batchBuffer.append(hh);
			hl = qToBigEndian(hl);
			lh = qToBigEndian(lh);
			ll = qToBigEndian(ll);
			batchBuffer.append(reinterpret_cast<const char*>(&hl), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&lh), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&ll), 8);
			if (++entriesInBatch >= MAX_ENTRIES_PER_PACKET) flushBatch();
		};

		QString hhStr[] = { "1000000000000000", "1000010000000000", "1000020000000000", "1000030000000000",
		 "1000040000000000",
		 "1000050000000000", "1000060000000000", "1000070000000000", "1000080000000000",
		 "1000090000000000","10000A0000000000","1000FF0000000000" };

		quint64 lh = 0;

		for (size_t i = 0; i < Array.size() - 1; ++i) {
			quint64 hl = quint64(nom) * 8;
			nom++;
			quint64 ll = (static_cast<quint64>(static_cast<quint32>(Array[i]) * 8) << 32) | (static_cast<quint64>(static_cast<quint32>(Array[i + 1] - 1) * 8));
			appendEntry(hhStr[i], hl, lh, ll);
		}

		flushBatch();
		qDebug() << "[UDP] quint256 done, nom:" << nom;
		return nom;
}



	//发送静态数据起止位信息()
	int sendquint256_static(int begin, int end, const QString& ip, quint16 port, int nom)
	{
		QUdpSocket udpSocket;

		QString hhStr = "1000FF0000000000";
		quint64 hl = quint64(nom) * 8;
		quint64 lh = 0;
		nom++;
		quint64 ll = (static_cast<quint64>(static_cast<quint32>(begin) * 8) << 32) | (static_cast<quint64>(static_cast<quint32>(end) * 8));

		QByteArray packet;
		packet.append(QByteArray::fromHex(hhStr.toUtf8()));
		packet.append(reinterpret_cast<const char*>(&hl), 8);
		packet.append(reinterpret_cast<const char*>(&lh), 8);
		packet.append(reinterpret_cast<const char*>(&ll), 8);

		udpSocket.writeDatagram(packet, QHostAddress(ip), port);
		qDebug() << "[UDP] static addr:" << begin << end;
		return nom;
}

	//发送八个坐标,hh:mm:ss八个字符的坐标
	void sendquint256_4(const QVector<RS_Vector>& positions, const QString& ip, quint16 port, int nom, int num_item,int fondsize)
	{
		QUdpSocket udpSocket;
		const int MAX_ENTRIES_PER_PACKET = 46;

		QByteArray batchBuffer;
		batchBuffer.reserve(MAX_ENTRIES_PER_PACKET * 32);
		int entriesInBatch = 0;

		auto flushBatch = [&]() {
			if (entriesInBatch > 0) {
				qDebug() << "[UDP] batch hex:" << batchBuffer.toHex(' ').toUpper();
		udpSocket.writeDatagram(batchBuffer, QHostAddress(ip), port);
				batchBuffer.clear();
				entriesInBatch = 0;
			}
		};

		auto appendEntry = [&](const QString& hhStr, quint64 hl, quint64 lh, quint64 ll) {
			QByteArray hh = QByteArray::fromHex(hhStr.toUtf8());
			batchBuffer.append(hh);
			hl = qToBigEndian(hl);
			lh = qToBigEndian(lh);
			ll = qToBigEndian(ll);
			batchBuffer.append(reinterpret_cast<const char*>(&hl), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&lh), 8);
			batchBuffer.append(reinterpret_cast<const char*>(&ll), 8);
			if (++entriesInBatch >= MAX_ENTRIES_PER_PACKET) flushBatch();
		};

		QString hhStr[] = { "1001000000000000", "1001010000000000", "1001020000000000", "1001030000000000",
		 "1001040000000000",
		 "1001050000000000", "1001060000000000", "1001070000000000", "1001080000000000","1001090000000000" ,"10010A0000000000" };
		quint64 lh = 0;
		int i = 0;
		for (const RS_Vector& v : positions) {
			quint64 hl = quint64(nom) * 8;
			nom++;
			int x_true = (v.x-5000);
			int y_true = ((v.y - 5000)) + fondsize;
			quint64 ll = (static_cast<quint64>(static_cast<quint32>(y_true) << 16) | (static_cast<quint64>(static_cast<quint32>(x_true))));
			appendEntry(hhStr[i], hl, lh, ll);
			i++;
		}
		flushBatch();
		qDebug() << "[UDP] dynamic positions done";
}

	//单发模块############################################################################
	int SendBKBK(QString positionCommandHeader, QString cmdHex, int ParamValue)
	{
		QString ip = "192.168.1.10";
		quint16 port = 1234;
		//QString cmdHex = QString::number(ParamType, 16).toUpper(); // 转换为"5E"
	
		QUdpSocket udpSocket;

		// 构建参数发送列表（与结构体成员对应）
		QVector<QPair<QString, int>> params = {
			{cmdHex, ParamValue},
		};
		// 发送所有参数
		for (const auto& param : params) {
			// 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
			QString headerStr = positionCommandHeader + param.first + "000000000000";
			QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

			// 固定值 hl 和 lh (各8字节，全0)
			quint64 hl = 0;
			quint64 lh = 0;

			// ll 参数值 (8字节，低4字节为参数值，大端序)
			quint64 ll = qToBigEndian(static_cast<quint64>(param.second));

			// 构建完整数据包 (32字节)
			QByteArray packet;
			packet.append(header); // 8字节
			packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
			packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
			packet.append(reinterpret_cast<const char*>(&ll), sizeof(ll)); // 8字节

			// 发送UDP数据包
			if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
				qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
			}
			else {
				qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
					<< QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
			}
		}
		return 0; // 成功返回0
	}


	//灯光模块############################################################################
	int Sendphoto()
	{
		QString ip = "192.168.1.10";
		quint16 port = 1234;

		// 参数校验函数
		auto checkParam = [](const QString& name, int value, int min, int max) -> bool {
			if (value < min || value > max) {
				qWarning() << QString::fromLocal8Bit("参数 '%1' 值 %2 超出范围 (%3-%4)")
					.arg(name).arg(value).arg(min).arg(max);
				return false;
			}
			return true;
			};

		// 校验所有参数


		if (!checkParam(QString::fromLocal8Bit("红色"), R, 0, 255)) return -1;
		if (!checkParam(QString::fromLocal8Bit("绿色"), G, 0, 255)) return -1;
		if (!checkParam(QString::fromLocal8Bit("蓝色"), B, 0, 255)) return -1;
		if (!checkParam(QString::fromLocal8Bit("RGB模式"), RGBMode, 0, 1)) return -1;
		if (!checkParam(QString::fromLocal8Bit("RGB时间"), RGBTime, 0, 2000)) return -1;

		QUdpSocket udpSocket;

		// 构建参数发送列表
		QVector<QPair<QString, int>> params = {

			{"00", RGBMode},      // RGB模式
			{"01", R},            // 红色
			{"02", G},            // 绿色
			{"03", B},            // 蓝色
			{"04", RGBTime},      // RGB时间
			{"05", 100}           //渐灭时长
			
		};

		// 发送所有参数
		for (const auto& param : params) {
			// 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
			QString headerStr = "11" + param.first + "000000000000";
			QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

			// 固定值 hl 和 lh (各8字节，全0)
			quint64 hl = 0;
			quint64 lh = 0;

			// ll 参数值 (8字节，低4字节为参数值，大端序)
			quint64 ll = qToBigEndian(static_cast<quint64>(param.second));

			// 构建完整数据包 (32字节)
			QByteArray packet;
			packet.append(header); // 8字节
			packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
			packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
			packet.append(reinterpret_cast<const char*>(&ll), sizeof(ll)); // 8字节

			// 发送UDP数据包
			if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
				qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
			}
			else {
				qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
					<< QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
			}
		}
		return 0; // 成功返回0
	}
	//触发优化############################################################################
	int Sendkey()
	{
		QString ip = "192.168.1.10";
		quint16 port = 1234;

		// 参数校验函数
		auto checkParam = [](const QString& name, int value, int min, int max) -> bool {
			if (value < min || value > max) {
				qWarning() << QString::fromLocal8Bit("参数 '%1' 值 %2 超出范围 (%3-%4)")
					.arg(name).arg(value).arg(min).arg(max);
				return false;
			}
			return true;
			};

		// 校验所有参数
		if (!checkParam(QString::fromLocal8Bit("光电滤波时间"), jgconfig.GdFilterTime, 1, 999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("最小触发模式"), jgconfig.MinThresholdMode, 0, 2)) return -1;
		if (!checkParam(QString::fromLocal8Bit("最小触发时间"), jgconfig.MinTriggerTime, 1, 9999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("最小触发距离"), jgconfig.MinTriggerDistance, 1, 9999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("延迟触发模式"), jgconfig.DelayTriggerMode, 0, 2)) return -1;
		if (!checkParam(QString::fromLocal8Bit("延迟触发时间"), jgconfig.DelayTriggerTime, 1, 9999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("延迟触发距离"), jgconfig.DelayTriggerDistance, 1, 9999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("二次延迟触发模式"), jgconfig.DelayTriggerModetwo, 0, 2)) return -1;
		if (!checkParam(QString::fromLocal8Bit("二次延迟触发时间"), jgconfig.DelayTriggerTimetwo, 1, 9999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("二次延迟触发距离"), jgconfig.DelayTriggerDistancetwo, 1, 9999)) return -1;

		
		QUdpSocket udpSocket;

		// 构建参数发送列表（与结构体成员对应）
		QVector<QPair<QString, int>> params = {
			
			{"00", jgconfig.GdFilterTime},       // 光电滤波时间

			{"01", jgconfig.MinThresholdMode},   // 最小触发模式
			{"02", jgconfig.MinTriggerTime},     // 最小触发时间
			{"03", jgconfig.MinTriggerDistance}, // 最小触发距离
			{"04", jgconfig.DelayTriggerMode},   // 延迟触发模式
			{"05", jgconfig.DelayTriggerTime},   // 延迟触发时间
			{"06", jgconfig.DelayTriggerDistance}, // 延迟触发距离
			{"07", jgconfig.DelayTriggerModetwo}, // 二次延迟触发模式
			{"08", jgconfig.DelayTriggerTimetwo}, // 二次延迟触发时间
			{"09", jgconfig.DelayTriggerDistancetwo}, // 二次延迟触发距离
			{"0A", DCLength},                     // 触发长度
			{"0B", OutputLocationMin},            // 触发下限冗余长度
			{"0C", OutputLocationMax}           // 触发上限冗余长度
			
		};

		// 发送所有参数
		for (const auto& param : params) {
			// 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
			QString headerStr = "02" + param.first + "000000000000";

			QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

			// 固定值 hl 和 lh (各8字节，全0)
			quint64 hl = 0;
			quint64 lh = 0;

			// ll 参数值 (8字节，低4字节为参数值，大端序)
			quint64 ll = qToBigEndian(static_cast<quint64>(param.second));

			// 构建完整数据包 (32字节)
			QByteArray packet;
			packet.append(header); // 8字节
			packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
			packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
			packet.append(reinterpret_cast<const char*>(&ll), sizeof(ll)); // 8字节

			// 发送UDP数据包
			if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
				qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
			}
			else {
				qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
					<< QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
			}
		}

		return 0; // 成功返回0
	}
	//打标参数############################################################################
	int Sendmarking()
	{
		QString ip = "192.168.1.10";
		quint16 port = 1234;

		// 参数校验函数
		auto checkParam = [](const QString& name, int value, int min, int max) -> bool {
			if (value < min || value > max) {
				qWarning() << QString::fromLocal8Bit("参数 '%1' 值 %2 超出范围 (%3-%4)")
					.arg(name).arg(value).arg(min).arg(max);
				return false;
			}
			return true;
			};

		// 校验所有参数
		if (!checkParam(QString::fromLocal8Bit("打标内容选择"), jgconfig.Dbchoice, 0, 3)) return -1;
		if (!checkParam(QString::fromLocal8Bit("插补步长"), jgconfig.interpolationStep, 1, 100)) return -1;

		if (!checkParam(QString::fromLocal8Bit("飞行振镜幅面"), jgconfig.scanW_mm, 1, 999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("飞行编码器方向"), jgconfig.BMQdirection, 0, 1)) return -1;
		if (!checkParam(QString::fromLocal8Bit("飞行方向"), jgconfig.FXDBirection, 0, 1)) return -1;
		if (!checkParam(QString::fromLocal8Bit("打标模式"), jgconfig.Dbmode, 0, 1)) return -1;

		if (!checkParam(QString::fromLocal8Bit("激光频率"), jgconfig.JgFreq, 5, 400)) return -1;
		if (!checkParam(QString::fromLocal8Bit("激光功率"), jgconfig.JgPower, 5, 95)) return -1;
		if (!checkParam(QString::fromLocal8Bit("开光延时"), jgconfig.KgDelay, 0, 30)) return -1;
		if (!checkParam(QString::fromLocal8Bit("关光延时"), jgconfig.GgDelay, 0, 30)) return -1;
		if (!checkParam(QString::fromLocal8Bit("跳转延时"), jgconfig.jumpDelay, 0, 30)) return -1;
		if (!checkParam(QString::fromLocal8Bit("结束延时"), jgconfig.endDelay, 0, 30)) return -1;


		QUdpSocket udpSocket;

		// 构建参数发送列表（与结构体成员对应）
		QVector<QPair<QString, int>> params = {

	 // 打标参数
	  //{"02", jgconfig.Dbchoice},           // 打标内容选择
	  {"03", 10},  // 插补步长

	  // 飞行参数
	  {"04", jgconfig.scanW_mm},           // 飞行振镜幅面
	  {"05", jgconfig.BMQdirection},       // 飞行编码器方向
	  {"06", jgconfig.FXDBirection},       // 飞行方向
	  {"07", jgconfig.Dbmode},             // 打标模式

	  // 激光参数
	  // 激光参数
	  {"08", jgconfig.jumpDelay},          // 跳转延时
	  {"09", jgconfig.endDelay},         // 结束延时
	  {"0A", jgconfig.JgFreq},            // 激光频率
	  {"0B", jgconfig.JgPower},            // 激光功率
	  {"0C", jgconfig.KgDelay},            // 开光延时
	  {"0D", jgconfig.GgDelay}          // 关光延时
		};

		// 发送所有参数
		for (const auto& param : params) {
			// 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
			QString headerStr = "10" + param.first + "000000000000";

			QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

			// 固定值 hl 和 lh (各8字节，全0)
			quint64 hl = 0;
			quint64 lh = 0;

			// ll 参数值 (8字节，低4字节为参数值，大端序)
			quint64 ll = qToBigEndian(static_cast<quint64>(param.second));

			// 构建完整数据包 (32字节)
			QByteArray packet;
			packet.append(header); // 8字节
			packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
			packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
			packet.append(reinterpret_cast<const char*>(&ll), sizeof(ll)); // 8字节

			// 发送UDP数据包
			if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
				qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
			}
			else {
				qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
					<< QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
			}
		}

		return 0; // 成功返回0
	}

	int Sendalarm()
	{
		QString ip = "192.168.1.10";
		quint16 port = 1234;

		// 参数校验函数
		auto checkParam = [](const QString& name, int value, int min, int max) -> bool {
			if (value < min || value > max) {
				qWarning() << QString::fromLocal8Bit("参数 '%1' 值 %2 超出范围 (%3-%4)")
					.arg(name).arg(value).arg(min).arg(max);
				return false;
			}
			return true;
			};

		if (!checkParam(QString::fromLocal8Bit("报警间隔数"), GapCount, 1, 30)) return -1;
		if (!checkParam(QString::fromLocal8Bit("报警保持数"), KeepCount, 1, 30)) return -1;

		QUdpSocket udpSocket;

		// 构建参数发送列表（与结构体成员对应）
		QVector<QPair<QString, int>> params = {

			 {"00", GapCount},         // 报警间隔数
		     {"01", KeepCount}        // 报警保持数
		};

		// 发送所有参数
		for (const auto& param : params) {
			// 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
			QString headerStr = "21" + param.first + "000000000000";

			QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

			// 固定值 hl 和 lh (各8字节，全0)
			quint64 hl = 0;
			quint64 lh = 0;

			// ll 参数值 (8字节，低4字节为参数值，大端序)
			quint64 ll = qToBigEndian(static_cast<quint64>(param.second));

			// 构建完整数据包 (32字节)
			QByteArray packet;
			packet.append(header); // 8字节
			packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
			packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
			packet.append(reinterpret_cast<const char*>(&ll), sizeof(ll)); // 8字节

			// 发送UDP数据包
			if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
				qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
			}
			else {
				qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
					<< QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
			}
		}

		return 0; // 成功返回0
	}
	//编码参数############################################################################
	int Sendall()
	{
		QString ip = "192.168.1.10";
		quint16 port = 1234;

		// 参数校验函数
		auto checkParam = [](const QString& name, int value, int min, int max) -> bool {
			if (value < min || value > max) {
				qWarning() << QString::fromLocal8Bit("参数 '%1' 值 %2 超出范围 (%3-%4)")
					.arg(name).arg(value).arg(min).arg(max);
				return false;
			}
			return true;
			};

		// 校验所有参数
		if (!checkParam(QString::fromLocal8Bit("编码器直径"), jgconfig.BMQzhijing, 1, 999)) return -1;
		if (!checkParam(QString::fromLocal8Bit("编码器周脉冲"), jgconfig.BMQmaichong, 1, 9999)) return -1;

		QUdpSocket udpSocket;

		// 构建参数发送列表（与结构体成员对应）
		QVector<QPair<QString, int>> params = {

			  {"00", jgconfig.BMQzhijing},         // 编码器直径
		      {"01", jgconfig.BMQmaichong}       // 编码器周脉冲
		};

		// 发送所有参数
		for (const auto& param : params) {
			// 构建固定头: "02" + 子命令ID + "0000000000" (共16个字符，8字节)
			QString headerStr = "FF" + param.first + "000000000000";

			QByteArray header = QByteArray::fromHex(headerStr.toUtf8());

			// 固定值 hl 和 lh (各8字节，全0)
			quint64 hl = 0;
			quint64 lh = 0;

			// ll 参数值 (8字节，低4字节为参数值，大端序)
			quint64 ll = qToBigEndian(static_cast<quint64>(param.second));

			// 构建完整数据包 (32字节)
			QByteArray packet;
			packet.append(header); // 8字节
			packet.append(reinterpret_cast<const char*>(&hl), sizeof(hl)); // 8字节
			packet.append(reinterpret_cast<const char*>(&lh), sizeof(lh)); // 8字节
			packet.append(reinterpret_cast<const char*>(&ll), sizeof(ll)); // 8字节

			// 发送UDP数据包
			if (udpSocket.writeDatagram(packet, QHostAddress(ip), port) == -1) {
				qWarning() << "发送参数失败:" << param.first << udpSocket.errorString();
			}
			else {
				qDebug() << QString::fromLocal8Bit("成功发送参数:") << param.first << QString::fromLocal8Bit("值:") << param.second
					<< QString::fromLocal8Bit("数据包:") << packet.toHex(' ').toUpper();
			}
		}
		return 0; // 成功返回0
	}




}










