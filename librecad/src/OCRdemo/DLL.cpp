
#include "DLL.h"

DLL::DLL()
{

	/*QLibrary* mainFunDll = new QLibrary("./ppocr.dll");
	if (mainFunDll->load()) {

	}
	else {
		cout << "LoadFail" << endl;
	}*/

	try
	{
		if (hModule == NULL) {
			std::cout << "Failed to load the DLL." << std::endl;
		}
		if (FreeMemory == NULL) {
			std::cout << "Failed to get the function address." << std::endl;
			FreeLibrary(hModule);
		}
		if (GetOcr == NULL) {
			std::cout << "Failed to get the function address." << std::endl;
			FreeLibrary(hModule);
		}
		if (GetOcrDetEnhance == NULL) {
			std::cout << "Failed to get the function address." << std::endl;
			FreeLibrary(hModule);
		}
	}
	catch (std::exception& e)
	{
		cout << "错误描述信息: " << e.what() << endl;
	}
}

DLL::~DLL()
{
	try
	{
		FreeMemory(detection_results, num_detection_results, recognition_results, num_recognition_results);
		// 卸载 DLL
		//FreeLibrary(hModule);
	}
	catch (std::exception& e)
	{
		cout << "错误描述信息: " << e.what() << endl;
	}
}

