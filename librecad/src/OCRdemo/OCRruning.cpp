#include "OCRruning.h"


OCRruning::OCRruning()
{
}

OCRruning::~OCRruning()
{
}

void OCRruning::getocr(cv::Mat image, double rot, cv::Rect rects, QString* rawResult, QString* rawResult2, QString* time_str, int* result, bool SCenabled, bool BZenabled, bool EWenabled, QString Start_Data_Time, QString Save_Time, QString FH, bool IsCustom, QString CustomStr, QString CustomStr_2, QString CustomStr_3, QString CustomStr_4, QString CustomStr_5, QString CustomStr_6, double* ocr_time, double FirstOCRSize, double SecOCRSize)
{
	m_mutex->lock();

	std::string RawResult;
	std::string RawResult2;
	std::string Time_str;

	auto start_time = chrono::high_resolution_clock::now(); // 记录总程序开始时间
	//Mat转QImage旋转分割
	cv::Mat rot_image, imaged, img_vis;
	QImage qimage, q_rot_image;
	qimage = QImage((unsigned char*)image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);

	
	// 应用旋转变换
	QTransform matrix;
	matrix.rotate(rot);
	q_rot_image = qimage.transformed(matrix, Qt::FastTransformation);
	rot_image = cv::Mat(q_rot_image.height(), q_rot_image.width(), CV_8UC3, (void*)q_rot_image.constBits(), q_rot_image.bytesPerLine());
	// 简洁的ROI边界检查
	int imgW = rot_image.cols;
	int imgH = rot_image.rows;

	// 如果ROI超出边界，调整为整个图片
	if (rects.x < 0 || rects.y < 0 ||
		rects.x >= imgW || rects.y >= imgH ||
		rects.width <= 0 || rects.height <= 0) {

		// 使用整个图片
		rects = cv::Rect(0, 0, imgW, imgH);
	}
	else {
		// 调整宽度和高度
		if (rects.x + rects.width > imgW) {
			rects.width = imgW - rects.x;
		}
		if (rects.y + rects.height > imgH) {
			rects.height = imgH - rects.y;
		}
		
		// 再次验证
		if (rects.width <= 0 || rects.height <= 0) {
			rects = cv::Rect(0, 0, imgW, imgH);
		}
	}
	// 提取ROI
	imaged = rot_image(rects);
	cv::Mat resizeImage0;
	cv::resize(imaged, resizeImage0, cv::Size(imaged.cols * 1, imaged.rows * 1), 0, 0, cv::INTER_LINEAR);

	//获取OCR结果并展示
	std::string FiltedResult;
	std::string FiltedResult2;
	bool ResultArr[3] = { 0,0,0 };
	bool ResultCusArr[5] = { 0,0,0,0,0 };
	
	//Loaddll.GetOcr(resizeImage0, &Loaddll.detection_results, &Loaddll.num_detection_results, &Loaddll.recognition_results, &Loaddll.num_recognition_results);
	Loaddll.GetOcrDetEnhance(resizeImage0, Loaddll.thresh, Loaddll.box_thresh, Loaddll.unclip_ratio , Loaddll.score_mode , Loaddll.use_dilation ,&Loaddll.detection_results, &Loaddll.num_detection_results, &Loaddll.recognition_results, &Loaddll.num_recognition_results);
	if (Loaddll.num_detection_results > 0) {
		for (int i = 0; i <= Loaddll.num_detection_results - 1; i++) {

			RawResult.append(Loaddll.recognition_results[i]->text);
			RawResult.append("\n");
		}
		//图片上显示识别框
		resizeImage0.copyTo(img_vis);
		for (int n = 0; n < Loaddll.num_detection_results; n++) {
			cv::Point rook_points[4];
			for (int m = 0; m < Loaddll.detection_results[n]->boxes.size(); m++) {
				rook_points[m] =
					cv::Point(int(Loaddll.detection_results[n]->boxes[m][0]), int(Loaddll.detection_results[n]->boxes[m][1]));
			}
			const cv::Point* ppt[1] = { rook_points };
			int npt[] = { 4 };
			cv::polylines(img_vis, ppt, npt, 1, 1, CV_RGB(0, 255, 0), 1, 8, 0);
		}

		FiltedResult = Filter(RawResult);

		//对功能字符进行初始化
		if (FH != "*")
		{
			Start_Data_Time = FH + Start_Data_Time;
		}
		if (CustomStr == "")
		{
			ResultCusArr[0] = true;
		}
		if (CustomStr_2 == "")
		{
			ResultCusArr[1] = true;
		}
		if (CustomStr_3 == "")
		{
			ResultCusArr[2] = true;
		}
		if (CustomStr_4 == "")
		{
			ResultCusArr[3] = true;
		}
		if (CustomStr_5 == "")
		{
			ResultCusArr[4] = true;
		}
		// 使用正则表达式只保留字母和数字
		QRegularExpression re("[^a-zA-Z0-9]");  // 匹配非字母和数字的字符
		CustomStr = CustomStr.remove(re);   // 移除非字母和数字的字符
		CustomStr_2 = CustomStr_2.remove(re);
		CustomStr_3 = CustomStr_3.remove(re);
		CustomStr_4 = CustomStr_4.remove(re);
		CustomStr_5 = CustomStr_5.remove(re);
		CustomStr_6 = CustomStr_6.remove(re);

		int res = 0;
		if (FiltedResult != "")
		{
			if (IsCustom)
			{
				QRegularExpression re(CustomStr);
				QRegularExpressionMatch match = re.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
				QRegularExpression re2(CustomStr_2);
				QRegularExpressionMatch match2 = re2.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
				QRegularExpression re3(CustomStr_3);
				QRegularExpressionMatch match3 = re3.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
				QRegularExpression re4(CustomStr_4);
				QRegularExpressionMatch match4 = re4.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
				QRegularExpression re5(CustomStr_5);
				QRegularExpressionMatch match5 = re5.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));

				if (CustomStr != "")
				{
					if (match.hasMatch())
					{
						ResultCusArr[0] = true;
					}
					
				}
				if (CustomStr_2 != "")
				{
					if (match2.hasMatch())
					{
						ResultCusArr[1] = true;
					}
					
				}
				if (CustomStr_3 != "")
				{
					if (match3.hasMatch())
					{
						ResultCusArr[2] = true;
					}
					
				}
				if (CustomStr_4 != "")
				{
					if (match4.hasMatch())
					{
						ResultCusArr[3] = true;
					}
				}
				if (CustomStr_5 != "")
				{
					if (match5.hasMatch())
					{
						ResultCusArr[4] = true;
					}
				}
				res = ResultCusArr[0] && ResultCusArr[1] && ResultCusArr[2] && ResultCusArr[3] && ResultCusArr[4];
			}
			else
			{

				res = true;

				// 短路判断：一旦失败立即停止后续检测
				if (SCenabled) {
					QRegularExpression re(Start_Data_Time);
					QRegularExpressionMatch match = re.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
					if (!match.hasMatch()) {
						res = false;
					}
				}

				if (BZenabled && res) { 
					QRegularExpression re2(Save_Time);
					QRegularExpressionMatch match2 = re2.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
					if (!match2.hasMatch()) {
						res = false;
					}
				}

				if (EWenabled && res) {
					QRegularExpression re3(CustomStr_6);
					QRegularExpressionMatch match3 = re3.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult)));
					if (!match3.hasMatch()) {
						res = false;
					}
				}
			}
		}

		if (res)
		{
			
			Time_str.append("首次匹配成功!");
			auto end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
			double duration_millsecond = std::chrono::duration<double, std::milli>(end_time - start_time).count();
			*ocr_time = duration_millsecond;

			*result = 1;
			img_vis.copyTo(ocrimg);
			*rawResult = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult));
			*rawResult2 = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult2));
			*time_str = QString::fromLocal8Bit(QByteArray::fromStdString(Time_str));
			ocrend();
			isfinash = true;
			m_mutex->unlock();
			return;
		}
		else {
			auto fist_end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
			double fist_duration_millsecond = std::chrono::duration<double, std::milli>(fist_end_time - start_time).count();
			//cout << fist_duration_millsecond << endl;
			if (fist_duration_millsecond >= 350)
			{
				Time_str.append("匹配失败！");
				auto end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
				double duration_millsecond = std::chrono::duration<double, std::milli>(end_time - start_time).count();
				*ocr_time = duration_millsecond;

				*result = 4;
				img_vis.copyTo(ocrimg);
				*rawResult = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult));
				*rawResult2 = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult2));
				*time_str = QString::fromLocal8Bit(QByteArray::fromStdString(Time_str));
				ocrend();
				isfinash = true;
				m_mutex->unlock();
				return;
			}

			//第二次识别
			cv::Mat resizeImage;
			cv::resize(imaged, resizeImage, cv::Size(imaged.cols * 1.2, imaged.rows * 1.2), 0, 0, cv::INTER_LINEAR);
			//Loaddll.GetOcr(resizeImage, &Loaddll.detection_results, &Loaddll.num_detection_results, &Loaddll.recognition_results, &Loaddll.num_recognition_results);
			Loaddll.GetOcrDetEnhance(resizeImage, Loaddll.thresh, Loaddll.box_thresh, Loaddll.unclip_ratio , Loaddll.score_mode , Loaddll.use_dilation ,&Loaddll.detection_results, &Loaddll.num_detection_results, &Loaddll.recognition_results, &Loaddll.num_recognition_results);
			if (Loaddll.num_detection_results > 0) {
				for (int i = 0; i <= Loaddll.num_detection_results - 1; i++) {

					RawResult2.append(Loaddll.recognition_results[i]->text);
					RawResult2.append("\n");
				}
				//图片上显示识别框
				resizeImage.copyTo(img_vis);
				for (int n = 0; n < Loaddll.num_detection_results; n++) {
					cv::Point rook_points[4];
					for (int m = 0; m < Loaddll.detection_results[n]->boxes.size(); m++) {
						rook_points[m] =
							cv::Point(int(Loaddll.detection_results[n]->boxes[m][0]), int(Loaddll.detection_results[n]->boxes[m][1]));
					}
					const cv::Point* ppt[1] = { rook_points };
					int npt[] = { 4 };
					cv::polylines(img_vis, ppt, npt, 1, 1, CV_RGB(0, 255, 0), 1, 8, 0);
				}

				FiltedResult2 = Filter(RawResult2);

				int res2 = 0;
				if (FiltedResult2 != "")
				{
					if (IsCustom)
					{
						QRegularExpression re(CustomStr);
						QRegularExpressionMatch match = re.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
						QRegularExpression re2(CustomStr_2);
						QRegularExpressionMatch match2 = re2.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
						QRegularExpression re3(CustomStr_3);
						QRegularExpressionMatch match3 = re3.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
						QRegularExpression re4(CustomStr_4);
						QRegularExpressionMatch match4 = re4.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
						QRegularExpression re5(CustomStr_5);
						QRegularExpressionMatch match5 = re5.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));

						if (CustomStr != "")
						{
							if (match.hasMatch())
							{
								ResultCusArr[0] = true;
							}
							
						}
						if (CustomStr_2 != "")
						{
							if (match2.hasMatch())
							{
								ResultCusArr[1] = true;
							}
							
						}
						if (CustomStr_3 != "")
						{
							if (match3.hasMatch())
							{
								ResultCusArr[2] = true;
							}
							
						}
						if (CustomStr_4 != "")
						{
							if (match4.hasMatch())
							{
								ResultCusArr[3] = true;
							}
						}
						if (CustomStr_5 != "")
						{
							if (match5.hasMatch())
							{
								ResultCusArr[4] = true;
							}
						}
						res2 = ResultCusArr[0] && ResultCusArr[1] && ResultCusArr[2] && ResultCusArr[3] && ResultCusArr[4];
					}
					else
					{
						res2 = true;

						// 短路判断：一旦失败立即停止后续检测
						if (SCenabled) {
							QRegularExpression re(Start_Data_Time);
							QRegularExpressionMatch match = re.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
							if (!match.hasMatch()) {
								res2 = false;
							}
						}

						if (BZenabled && res2) { 
							QRegularExpression re2(Save_Time);
							QRegularExpressionMatch match2 = re2.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
							if (!match2.hasMatch()) {
								res2 = false;
							}
						}

						if (EWenabled && res2) {
							QRegularExpression re3(CustomStr_6);
							QRegularExpressionMatch match3 = re3.match(QString::fromLocal8Bit(QByteArray::fromStdString(FiltedResult2)));
							if (!match3.hasMatch()) {
								res2 = false;
							}
						}
					}
				}

				if (res2)
				{
					
					Time_str.append("二次匹配成功!");
					auto end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
					double duration_millsecond = std::chrono::duration<double, std::milli>(end_time - start_time).count();
					*ocr_time = duration_millsecond;

					*result = 2;
					img_vis.copyTo(ocrimg);
					*rawResult = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult));
					*rawResult2 = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult2));
					*time_str = QString::fromLocal8Bit(QByteArray::fromStdString(Time_str));
					ocrend();
					isfinash = true;
					m_mutex->unlock();
					return;
				}
				else
				{
					auto sec_end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
					double sec_duration_millsecond = std::chrono::duration<double, std::milli>(sec_end_time - fist_end_time).count();

					Time_str.append("二次匹配失败！");
					auto end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
					double duration_millsecond = std::chrono::duration<double, std::milli>(end_time - start_time).count();
					*ocr_time = duration_millsecond;

					*result = 4;
					img_vis.copyTo(ocrimg);
					*rawResult = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult));
					*rawResult2 = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult2));
					*time_str = QString::fromLocal8Bit(QByteArray::fromStdString(Time_str));
					ocrend();
					isfinash = true;
					m_mutex->unlock();
					return;
				}
			}
			else
			{
				Time_str.append("二次匹配失败！");
				auto end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
				double duration_millsecond = std::chrono::duration<double, std::milli>(end_time - start_time).count();
				*ocr_time = duration_millsecond;

				*result = 4;
				resizeImage.copyTo(ocrimg);
				*rawResult = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult));
				*rawResult2 = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult2));
				*time_str = QString::fromLocal8Bit(QByteArray::fromStdString(Time_str));
				ocrend();
				isfinash = true;
				m_mutex->unlock();
				return;
			}
		}
	}
	else {
		RawResult.append("无识别结果！\n");
		auto end_time = chrono::high_resolution_clock::now(); // 记录总程序结束时间
		double duration_millsecond = std::chrono::duration<double, std::milli>(end_time - start_time).count();
		*ocr_time = duration_millsecond;

		*result = 5;
		resizeImage0.copyTo(ocrimg);
		*rawResult = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult));
		*rawResult2 = QString::fromLocal8Bit(QByteArray::fromStdString(RawResult2));
		*time_str = QString::fromLocal8Bit(QByteArray::fromStdString(Time_str));
		ocrend();
		isfinash = true;
		m_mutex->unlock();
		return;
	}
}

void OCRruning::setMutex(QMutex* mutex)
{
	m_mutex = mutex;
}

//字符串过滤(提取数字及字母)--------------------------------------------------------------
std::string Filter(std::string RawString)
{
	std::smatch m;
	std::regex e("([a-z0-9A-Z]?)");
	std::string result;
	for (int i = 0; i < RawString.size(); i++) {
		string x(1, RawString[i]);
		regex_search(x, m, e);
		if (m.str() != " ")
			result += m.str();
	}
	return result;
}
//获得日期   iDay=0今天 iDay=-1昨天 iDay=1明天
string get_date(char* cType, int iDay)
{
	char cTimePARTNUMBER[256] = "";
	time_t rawtime;
	struct tm* timeinfo;
	rawtime = time(NULL) + iDay * 24 * 3600;
	timeinfo = localtime(&rawtime);
	char buffer1[256];
	strftime(cTimePARTNUMBER, sizeof(buffer1), cType, timeinfo);//20180623
	string strTimePARTNUMBER = "";
	strTimePARTNUMBER = cTimePARTNUMBER;
	return strTimePARTNUMBER;
	//20190419    "%Y%m%d"
	//2019-04-19    "%Y-%m-%d"
	//20180623092858    "%Y%m%d%H%M%S"
	//%a    缩写的星期几名称
	//%A    完整的星期几名称    Sunday
	//%b    缩写的月份名称    Mar
	//%B    完整的月份名称    March
	//%c    日期和时间表示法    Sun Aug 19 02:56:02 2012
	//%d    一月中的第几天(01-31)    19
	//%H    24 小时格式的小时(00-23)    14
	//%I    12 小时格式的小时(01-12)    05
	//%j    一年中的第几天(001-366)    231
	//%m    十进制数表示的月份(01-12)    08
	//%M    分(00-59)    55
	//%S    秒(00-61)    02
	//%U    一年中的第几周，以第一个星期日作为第一周的第一天(00-53)    33
	//%w    十进制数表示的星期几，星期日表示为 0(0-6)    4
	//%W    一年中的第几周，以第一个星期一作为第一周的第一天(00-53)    34
	//%x    日期表示法    08/19/12
	//%X    时间表示法    02:50:06
	//%y    年份，最后两个数字(00-99)    01
	//%Y    年份    2012
}
string GetPubStr(string s1, string s2, int* Start, int* End)
{
	int len1 = s1.size(), len2 = s2.size();
	int start = 0, mx = 0; //记录结果
	vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			if (dp[i][j] > mx) {
				mx = dp[i][j];
				start = i - mx;
			}
		}
	}
	*Start = start;
	*End = start + mx - 1;
	return s1.substr(start, mx);
}
void CompareStr(string dataStr, string ocrResult, bool ComArray[])
{
	string month = "01";
	string day = "0123";
	string publicStr;
	int Ocr1Start = 0, Ocr1End = 0;
	int DataStart = 0, DataEnd = 0;

	if (dataStr.size() > ocrResult.size()) //以短的作为s1
	{
		publicStr = GetPubStr(ocrResult, dataStr, &Ocr1Start, &Ocr1End);
		DataStart = publicStr.find(publicStr);
		DataEnd = DataStart + publicStr.size() - 1;

		if (publicStr == "")
		{
			return;
		}

		for (int i = DataStart; i <= DataEnd; i++)
		{
			ComArray[i] = true;
		}
		//前半部分判断
		if (Ocr1Start >= DataStart)
		{
			for (int i = DataStart - 1; i >= 0; i--)
			{
				Ocr1Start--;
				if (i == 0 || i == 1 || i == 2 || i == 3 || i == 5 || i == 7)
				{
					if (ocrResult[Ocr1Start] == dataStr[i])
					{
						ComArray[i] = true;
					}
				}
				else if (i == 4)
				{
					if (ocrResult[Ocr1Start] == month[0] || ocrResult[Ocr1Start] == month[1])
					{
						if (ocrResult[Ocr1Start] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (i == 6)
				{
					if (ocrResult[Ocr1Start] == day[0] || ocrResult[Ocr1Start] == day[1] || ocrResult[Ocr1Start] == day[2]
						|| ocrResult[Ocr1Start] == day[3])
					{
						if (ocrResult[Ocr1Start] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
		else
		{
			for (int i = Ocr1Start - 1; i > 0; i--) {
				DataStart--;
				if (DataStart == 0 || DataStart == 1 || DataStart == 2 || DataStart == 3 || DataStart == 5 || DataStart == 7)
				{
					if (dataStr[DataStart] == ocrResult[i])
					{
						ComArray[i] = true;
					}
				}
				else if (DataStart == 4)
				{
					if (ocrResult[i] == month[0] || ocrResult[i] == month[1])
					{
						if (dataStr[DataStart] == ocrResult[i])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (DataStart == 6)
				{
					if (ocrResult[i] == day[0] || ocrResult[i] == day[1] || ocrResult[i] == day[2]
						|| ocrResult[i] == day[3])
					{
						if (dataStr[DataStart] == ocrResult[i])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
		//后半部分判断
		if ((ocrResult.size() - 1 - Ocr1End) >= (7 - DataEnd)) {
			for (int i = DataEnd + 1; i <= 7; i++)
			{
				Ocr1End++;
				if (i == 0 || i == 1 || i == 2 || i == 3 || i == 5 || i == 7)
				{
					if (ocrResult[Ocr1End] == dataStr[i])
					{
						ComArray[i] = true;
					}
				}
				else if (i == 4)
				{
					if (ocrResult[Ocr1End] == month[0] || ocrResult[Ocr1End] == month[1])
					{
						if (ocrResult[Ocr1End] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (i == 6)
				{
					if (ocrResult[Ocr1End] == day[0] || ocrResult[Ocr1End] == day[1] || ocrResult[Ocr1End] == day[2]
						|| ocrResult[Ocr1End] == day[3])
					{
						if (ocrResult[Ocr1End] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
		else
		{
			for (int i = Ocr1End + 1; i <= ocrResult.size() - 1; i++)
			{
				DataEnd++;
				if (DataEnd == 0 || DataEnd == 1 || DataEnd == 2 || DataEnd == 3 || DataEnd == 5 || DataEnd == 7)
				{
					if (ocrResult[i] == dataStr[DataEnd])
					{
						ComArray[i] = true;
					}
				}
				else if (DataEnd == 4)
				{
					if (ocrResult[i] == month[0] || ocrResult[i] == month[1])
					{
						if (ocrResult[i] == dataStr[DataEnd])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (DataEnd == 6)
				{
					if (ocrResult[i] == day[0] || ocrResult[i] == day[1] || ocrResult[i] == day[2]
						|| ocrResult[i] == day[3])
					{
						if (ocrResult[i] == dataStr[DataEnd])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
	}
	else
	{
		publicStr = GetPubStr(dataStr, ocrResult, &DataStart, &DataEnd);
		Ocr1Start = ocrResult.find(publicStr);
		Ocr1End = Ocr1Start + publicStr.size() - 1;

		for (int i = DataStart; i <= DataEnd; i++)
		{
			ComArray[i] = true;
		}
		//前半部分判断
		if (Ocr1Start >= DataStart)
		{
			for (int i = DataStart - 1; i >= 0; i--)
			{
				Ocr1Start--;
				if (i == 0 || i == 1 || i == 2 || i == 3 || i == 5 || i == 7)
				{
					if (ocrResult[Ocr1Start] == dataStr[i])
					{
						ComArray[i] = true;
					}
				}
				else if (i == 4)
				{
					if (ocrResult[Ocr1Start] == month[0] || ocrResult[Ocr1Start] == month[1])
					{
						if (ocrResult[Ocr1Start] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (i == 6)
				{
					if (ocrResult[Ocr1Start] == day[0] || ocrResult[Ocr1Start] == day[1] || ocrResult[Ocr1Start] == day[2]
						|| ocrResult[Ocr1Start] == day[3])
					{
						if (ocrResult[Ocr1Start] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
		else
		{
			for (int i = Ocr1Start - 1; i > 0; i--) {
				DataStart--;
				if (DataStart == 0 || DataStart == 1 || DataStart == 2 || DataStart == 3 || DataStart == 5 || DataStart == 7)
				{
					if (dataStr[DataStart] == ocrResult[i])
					{
						ComArray[i] = true;
					}
				}
				else if (DataStart == 4)
				{
					if (ocrResult[i] == month[0] || ocrResult[i] == month[1])
					{
						if (dataStr[DataStart] == ocrResult[i])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (DataStart == 6)
				{
					if (ocrResult[i] == day[0] || ocrResult[i] == day[1] || ocrResult[i] == day[2]
						|| ocrResult[i] == day[3])
					{
						if (dataStr[DataStart] == ocrResult[i])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
		//后半部分判断
		if ((ocrResult.size() - 1 - Ocr1End) >= (7 - DataEnd)) {
			for (int i = DataEnd + 1; i <= 7; i++)
			{
				Ocr1End++;
				if (i == 0 || i == 1 || i == 2 || i == 3 || i == 5 || i == 7)
				{
					if (ocrResult[Ocr1End] == dataStr[i])
					{
						ComArray[i] = true;
					}
				}
				else if (i == 4)
				{
					if (ocrResult[Ocr1End] == month[0] || ocrResult[Ocr1End] == month[1])
					{
						if (ocrResult[Ocr1End] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (i == 6)
				{
					if (ocrResult[Ocr1End] == day[0] || ocrResult[Ocr1End] == day[1] || ocrResult[Ocr1End] == day[2]
						|| ocrResult[Ocr1End] == day[3])
					{
						if (ocrResult[Ocr1End] == dataStr[i])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
		else
		{
			for (int i = Ocr1End + 1; i <= ocrResult.size() - 1; i++)
			{
				DataEnd++;
				if (DataEnd == 0 || DataEnd == 1 || DataEnd == 2 || DataEnd == 3 || DataEnd == 5 || DataEnd == 7)
				{
					if (ocrResult[i] == dataStr[DataEnd])
					{
						ComArray[i] = true;
					}
				}
				else if (DataEnd == 4)
				{
					if (ocrResult[i] == month[0] || ocrResult[i] == month[1])
					{
						if (ocrResult[i] == dataStr[DataEnd])
						{
							ComArray[i] = true;
						}
					}
				}
				else if (DataEnd == 6)
				{
					if (ocrResult[i] == day[0] || ocrResult[i] == day[1] || ocrResult[i] == day[2]
						|| ocrResult[i] == day[3])
					{
						if (ocrResult[i] == dataStr[DataEnd])
						{
							ComArray[i] = true;
						}
					}
				}
			}
		}
	}
}

bool isSubstringMatchWithOneMismatch(const QString& A, const QString& B)
{
	int lenA = A.length();
	int lenB = B.length();

	// 如果B的长度小于A，则不可能匹配
	if (lenB < lenA) {
		return false;
	}

	// 遍历B中的每个可能的子串
	for (int i = 0; i <= lenB - lenA; ++i) {
		int mismatchCount = 0;

		// 逐字符比较A和B的子串
		for (int j = 0; j < lenA; ++j) {
			if (A[j] != B[i + j]) {
				++mismatchCount;
				// 如果超过一个字符不匹配，则跳出循环
				if (mismatchCount > 1) {
					break;
				}
			}
		}

		// 如果有一个或零个字符不匹配，则认为匹配成功
		if (mismatchCount <= 1) {
			return true;
		}
	}

	// 没有找到满足条件的子串
	return false;
}


QImage OCRruning::MatToImage(cv::Mat& m)
{
	switch (m.type()) {    //判断Mat的类型，从而返回不同类型的img
	case CV_8UC1: {
		// 通过QImage::QImage(uchar *data, int width, int height, int bytesPerLine,
		 // QImage::Format format, QImageCleanupFunction cleanupFunction = nullptr,
		 //void *cleanupInfo = nullptr)，主要修改后两个非默认的参数
		QImage img((uchar*)m.data, m.cols, m.rows, m.cols * 1, QImage::Format_Grayscale8);
		return img;
	}
	case CV_8UC3: {
		QImage img((uchar*)m.data, m.cols, m.rows, m.cols * 3, QImage::Format_RGB888);
		return img.rgbSwapped();
	}
	case CV_8UC4: {
		QImage img((uchar*)m.data, m.cols, m.rows, m.cols * 4, QImage::Format_ARGB32);
		return img;
	}
	default: {
		QImage img;
		return img;
	}
	}
}