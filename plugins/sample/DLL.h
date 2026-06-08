#pragma once
#pragma warning(disable:4828)
#include <vector>
#include <string>
#include <Windows.h>
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv.hpp>
#include <opencv2/highgui.hpp>
#include<QDebug>

#include<QCoreApplication>
#include <QDir>
using namespace std;

//定义dll数据结构
struct TextDetectionResult {
	std::vector<std::vector<int>> boxes;
};
struct TextRecognitionResult {
	std::string text;
	double score;
};
typedef void (*GetOcrFunc)(cv::Mat, TextDetectionResult*** detection_results, int* num_detection_results,
	TextRecognitionResult*** recognition_results, int* num_recognition_results);
typedef void (*FreeMemoryFunc)(TextDetectionResult** detection_results, int num_detection_results,
	TextRecognitionResult** recognition_results, int num_recognition_results);


//class DLL
//{
//public:
//
//	//dll变量
//	TextDetectionResult** detection_results = nullptr;
//	int num_detection_results = 0;
//	TextRecognitionResult** recognition_results = nullptr;
//	int num_recognition_results = 0;
//
//	//加载dll
//	const wchar_t* dll_path = L"ppocr.dll";
//	//HMODULE hModule = LoadLibraryA(dll_path);
//
//	HINSTANCE hModule = LoadLibraryEx(dll_path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
//
//
//	FreeMemoryFunc FreeMemory = (FreeMemoryFunc)GetProcAddress(hModule, "FreeMemory");
//	GetOcrFunc GetOcr = (GetOcrFunc)GetProcAddress(hModule, "GetOcr");
//
//	/*QLibrary* mainFunDll = new QLibrary("ppocr.dll");
//	GetOcrFunc GetOcr = (GetOcrFunc)mainFunDll->resolve("GetOcr");
//	FreeMemoryFunc FreeMemory = (FreeMemoryFunc)mainFunDll->resolve("FreeMemory");*/
//
//	DLL();
//	~DLL();
//};


class DLL
{
public:
    // DLL函数指针类型
    typedef int(__stdcall* GetOcrFunc)(cv::Mat&, TextDetectionResult***, int*, TextRecognitionResult***, int*); typedef void(__stdcall* FreeMemoryFunc)(void*);

    // DLL变量
    TextDetectionResult**detection_results = nullptr;
    int num_detection_results = 0;
    TextRecognitionResult**recognition_results = nullptr;
    int num_recognition_results = 0;

    // DLL函数指针
    FreeMemoryFunc FreeMemory = nullptr;
    GetOcrFunc GetOcr = nullptr;

    // 状态标志
    bool isLoaded() const { return m_loaded; }
    QString errorString() const { return m_error; }

    DLL()
    {
        // 获取应用程序所在目录
        QString appDir = QCoreApplication::applicationDirPath();

        // 构造DLL完整路径
        QString dllPath = QDir(appDir).filePath("ppocr.dll");

        // 检查DLL文件是否存在
        if (!QFile::exists(dllPath))
        {
            m_error = QString("DLL file not found at: %1").arg(dllPath);
            qWarning() << m_error;
            return;
        }

        // 加载DLL (使用宽字符版本)
        hModule = LoadLibraryExW(reinterpret_cast<LPCWSTR>(dllPath.utf16()),
            NULL,
            LOAD_WITH_ALTERED_SEARCH_PATH);

        if (!hModule)
        {
            DWORD errorCode = GetLastError();
            m_error = QString("Failed to load DLL (Error %1): %2").arg(errorCode).arg(dllPath);
            qWarning() << m_error;
            return;
        }

        // 获取函数地址
        GetOcr = reinterpret_cast<GetOcrFunc>(GetProcAddress(hModule, "GetOcr"));
        FreeMemory = reinterpret_cast<FreeMemoryFunc>(GetProcAddress(hModule, "FreeMemory"));

        if (!GetOcr || !FreeMemory)
        {
            DWORD errorCode = GetLastError();
            m_error = QString("Failed to get function addresses (Error %1)").arg(errorCode);
            FreeLibrary(hModule);
            hModule = nullptr;
            qWarning() << m_error;
            return;
        }

        m_loaded = true;
        qDebug() << "DLL loaded successfully from:" << dllPath;
    }

    ~DLL()
    {
        if (hModule)
        {
            FreeLibrary(hModule);
            hModule = nullptr;
        }
    }

private:
    HINSTANCE hModule = nullptr;
    bool m_loaded = false;
    QString m_error;
};

