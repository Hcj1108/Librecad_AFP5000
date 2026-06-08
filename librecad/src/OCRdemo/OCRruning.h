#pragma once
#pragma warning(disable:4996)
#ifndef OCRrun
#define OCRrun
#include<QObject>
#include<QVector>
#include<QImage>
#include<QMutex>
#include"Setting.h"

#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv.hpp>
#include <opencv2/highgui.hpp>
#include"DLL.h"

#include <regex>
#include <io.h>


class OCRruning :public QObject
{
    Q_OBJECT
signals:
    void running(cv::Mat image, double rot, cv::Rect rects, QString* rawResult, QString* rawResult2, QString* time_str, int* result, bool SCenabled, bool BZenabled, bool EWenabled, QString Start_Data_Time, QString Save_Time, QString FH, bool IsCustom, QString CustomStr, QString CustomStr_2, QString CustomStr_3, QString CustomStr_4, QString CustomStr_5, QString CustomStr_6, double* ocr_time, double FirstOCRSize, double SecOCRSize);
    void ocrend();

public:
    OCRruning();
    ~OCRruning();
    void getocr(cv::Mat image, double rot, cv::Rect rects, QString* rawResult, QString* rawResult2, QString* time_str, int* result, bool SCenabled, bool BZenabled, bool EWenabled, QString Start_Data_Time, QString Save_Time, QString FH, bool IsCustom, QString CustomStr, QString CustomStr_2, QString CustomStr_3, QString CustomStr_4, QString CustomStr_5, QString CustomStr_6, double* ocr_time, double FirstOCRSize, double SecOCRSize);
    void setMutex(QMutex* mutex);

    bool isfinash = true;//线程是否结束
    cv::Mat ocrimg;//临时保存OCR图片

    DLL Loaddll;//paddle动态库类
    QMutex* m_mutex;            //定义一个线程锁变量
    QImage MatToImage(cv::Mat& m);   //Mat格式转化QImage类型
    int MatchCounter = 0;
};
std::string Filter(std::string RawString);//过滤字符串
string get_date(char* cType, int iDay);//获取日期字符串
string GetPubStr(string s1, string s2, int* Start, int* End);//获取公共字符串
void CompareStr(string dataStr, string ocrResult, bool ComArray[]);//程序判断日期
bool isSubstringMatchWithOneMismatch(const QString& A, const QString& B);

#endif // TASK_H