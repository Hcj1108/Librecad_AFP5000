/*#pragma once
#pragma warning(disable:4828)
#include <vector>
#include <string>
#include <Windows.h>
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
namespace fs = std::filesystem;

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


class DLL
{
public:

	//dll变量
	TextDetectionResult** detection_results = nullptr;
	int num_detection_results = 0;
	TextRecognitionResult** recognition_results = nullptr;
	int num_recognition_results = 0;

	//加载dll
	const wchar_t* dll_path = LR"(D:\LibreCAD-2.2\librecad\src\OCRdemo)";

	//HINSTANCE hModule = LoadLibraryExA(dll_path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

	//const wchar_t* dll_path = L"OCRdemo/ppocr.dll";

	HINSTANCE hModule = LoadLibraryEx(dll_path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

	//HINSTANCE hModule = LoadLibraryEx(dll_path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	FreeMemoryFunc FreeMemory = (FreeMemoryFunc)GetProcAddress(hModule, "FreeMemory");
	GetOcrFunc GetOcr = (GetOcrFunc)GetProcAddress(hModule, "GetOcr");

	// 检查文件是否存在且是普通文件（非目录）

	//QLibrary* mainFunDll = new QLibrary("ppocr.dll");
	//GetOcrFunc GetOcr = (GetOcrFunc)mainFunDll->resolve("GetOcr");
	//FreeMemoryFunc FreeMemory = (FreeMemoryFunc)mainFunDll->resolve("FreeMemory");

	DLL();
	~DLL();
};
*/

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

typedef void (*GetOcrDetEnhanceFunc)(cv::Mat, float det_db_thresh, float det_db_box_thresh, float det_db_unclip_ratio,
	const char* det_db_score_mode, int use_dilation, TextDetectionResult*** detection_results, int* num_detection_results,
	TextRecognitionResult*** recognition_results, int* num_recognition_results);

typedef void (*FreeMemoryFunc)(TextDetectionResult** detection_results, int num_detection_results,
	TextRecognitionResult** recognition_results, int num_recognition_results);


class DLL
{
public:

	//dll变量
	TextDetectionResult** detection_results = nullptr;
	int num_detection_results = 0;
	TextRecognitionResult** recognition_results = nullptr;
	int num_recognition_results = 0;

	float thresh = 0.3f;
	float box_thresh = 0.5f;
	float unclip_ratio = 1.8f;
	const char* score_mode = "fast";
	bool use_dilation = true;

	//加载dll
	const char* dll_path = "./ppocr.dll";
	HMODULE hModule = LoadLibraryA(dll_path);

	//HINSTANCE hModule = LoadLibraryEx(dll_path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);


	FreeMemoryFunc FreeMemory = (FreeMemoryFunc)GetProcAddress(hModule, "FreeMemory");
	GetOcrFunc GetOcr = (GetOcrFunc)GetProcAddress(hModule, "GetOcr");
	GetOcrDetEnhanceFunc GetOcrDetEnhance = (GetOcrDetEnhanceFunc)GetProcAddress(hModule, "GetOcrDetEnhance");
	/*QLibrary* mainFunDll = new QLibrary("ppocr.dll");
	GetOcrFunc GetOcr = (GetOcrFunc)mainFunDll->resolve("GetOcr");
	FreeMemoryFunc FreeMemory = (FreeMemoryFunc)mainFunDll->resolve("FreeMemory");*/

	DLL();
	~DLL();
};

