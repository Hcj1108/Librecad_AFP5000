#pragma once
#include <vector>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#ifndef IMAGE_API
#define IMAGE_API


struct TextDetectionResult {
    std::vector<std::vector<int>> boxes;
};

struct TextRecognitionResult {
    std::string text;
    double score;

};

extern "C" {
    // OCR识别
    __declspec(dllexport) void GetOcr(cv::Mat img, TextDetectionResult*** detection_results, int* num_detection_results,
        TextRecognitionResult*** recognition_results, int* num_recognition_results);
    //释放结构体内存
    __declspec(dllexport) void FreeMemory(TextDetectionResult** detection_results, int num_detection_results,
        TextRecognitionResult** recognition_results, int num_recognition_results);
}
#endif