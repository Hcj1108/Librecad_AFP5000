//
//
//#include"GalaxyIncludes.h"
//#include<opencv2/core.hpp>
//#include<opencv2/imgproc.hpp>
//#include <opencv.hpp>
//#include <opencv2/highgui.hpp>
//
//#include"sqlite3.h"
//#include<string>
//#include<iostream>
//#include "iconv.h"
//#include <io.h>
//using namespace std;
//
//
//bool m_isLoggedIn = false;//登录状态
//bool IsOpenAlarm = true;// 
//bool IsOpenBKBK = false;//标刻是否启动
//bool isOpenCam = false;//相机是否启动
//bool model = true;//触发模式是否启动，默认true
//bool IsSettingOpen = false;//设置页面是否打开
////bool IsAdminOpen = false;//管理员页面是否打开
//bool IsJgadminOpen = false;//激光页面是否打开
//bool IsxjadminOpen = false;
//bool IsAlarm = false;//是否正在报警，用于报警按钮的状态显示
//bool IsAutoCap = false;//当前是否开启自动采集
//bool IsCloseSoftware = false;//关闭软件标志位，用于程序关闭时写入日志
//bool IsAlter = false;//是否修改了参数
//int Userindex;//用户索引值让user界面和主界面的用户同步
//int ExposureTime = 300.0000;//曝光时间us
//int TriggerDelay = 0.0000;//拍照延迟us
//double Sharpness = 0;//锐度值0-3
//int rot = 0;//图片旋转角度
//int GainValue = 0;//增益值
//int CodeIndex = 0;//字符代码索引值
//
//
//int rectX = 50, rectY = 50, rectW = 100, rectH = 50;//ROI区域
//cv::Rect rects(rectX, rectY, rectW, rectH);//临时保存ROI区域
//
//
//cv::Mat image;//主程序图片变量
//cv::Mat resizeImage;// 缩放后的图像
//
//double ImageSize = 0.66;
//
//
//
//int GapCount = 7, KeepCount = 3;//GapCount间隔数；KeepCount报警时长
///*int AlarmCounter = KeepCount;//报警计数器
//int PreCounter = GapCount - 1, EndCounter = 0;
////int PreCounter = 0;    // 起始位置计数器
////int EndCounter = 0;    // 结束位置计数器
//bool Count[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };*/
//
//
//int DelayModel = 0;
//int DelayTime = 0;
//int DelayDistance = 0;
//int DCLength = 0;
//double FirstOCRSize = 0.7;
//double SecOCRSize = 0.5;
//int OutputLocationMin = 30;
//int OutputLocationMax = 30;
//int R = 255;
//int G = 255;
//int B = 255;
//int RGBTime = 10;
//int RGBMode = 1;
//
//int CamFilterTime = 100;
//int CamFilterLength = 100;
//
//vector<string> ImageList;//仿真图片列表
//int ImageListIndex = 0;//仿真图片索引
//
//double OKnum = 0;//数据栏OK数量
//double NGnum = 0;//数据栏NG数量
//double Totalnum = 0;//识别图片总数
//
//
//gxdeviceinfo_vector vectorDeviceInfo;//相机设备列表
//CGXDevicePointer ObjDevicePtr;//相机设备指针
//CGXStreamPointer ObjStreamPtr;//相机数据流指针
//CGXFeatureControlPointer ObjFeatureControlPtr;//相机属性控制指针
//ICaptureEventHandler* pCaptureEventHandler = NULL;///<采集回调对象
//IDeviceOfflineEventHandler* pDeviceOfflineEventHandler = NULL;//<掉线事件回调对象
//GX_DEVICE_OFFLINE_CALLBACK_HANDLE hDeviceOffline = NULL;//相机掉线事件
//
//
//int MaxThresholdAlermOpen;//上限报警
//int MinThresholdAlermOpen;//下限报警
//int cameraAlarmOpen;//相机报警
//int markingOutOfAreaOpen;//标刻区域外报警
//
//int linkTXOpen ;//通讯联机功能启用
//int linkBKBKOpen;//标刻联机功能启用
//int linkCameraOpen ;//相机联机功能启用
//
//
////数据库相关
////用于接收数据库查询结果
//struct Config
//{
//    string SCHEME;
//    int ExposureTime;
//    int TriggerDelay;
//    double Sharpness;
//    int rectX;
//    int rectY;
//    int rectW;
//    int rectH;
//    int rot;
//    int GapCount;
//    int KeepCount;
//    int GainValue = 0;//增益值
//    int CodeIndex = 0;
//    int DelayModel = 0;
//    int DelayTime = 0;
//    int DelayDistance = 0;
//    int DCLength = 0;
//    double FirstOCRSize = 0.7;
//    double SecOCRSize = 0.5;
//    int OutputLocationMin = 30;
//    int OutputLocationMax = 30;
//    int R;
//    int G;
//    int B;
//    int RGBTime;
//    int RGBMode;
//
//    int MinThresholdMode;//最小触发模式
//    int MinTriggerTime;//最小触发时间
//    int MinTriggerDistance;//最小触发距离
//    int DelayTriggerMode;//延迟触发模式
//    int DelayTriggerTime;//延迟触发时间
//    int DelayTriggerDistance;//延迟触发距离
//    int DelayTriggerModetwo;//二次延迟触发模式
//    int DelayTriggerTimetwo;//二次延迟触发时间
//    int DelayTriggerDistancetwo;//二次延迟触发距离
//
//    int Dbmode;//打标模式
//};
//struct RunningStatus   //运行状态
//{
//  
//    int MaxThresholdAlermOpen = 1;//上限报警
//    int MinThresholdAlermOpen = 1;//下限报警
//    int cameraAlarmOpen = 1;//相机报警
//    int markingOutOfAreaOpen = 1;//标刻区域外报警
//
//    int linkTXOpen = 1;//相机联机功能启用
//    int linkBKBKOpen = 1;//标刻联机功能启用
//    int linkCameraOpen = 1;//通讯联机功能启用
//};
//struct Jgconfig   //报警状态
//{
//    int BMQzhijing;//编码器直径
//    int BMQmaichong;//编码器脉冲
//
//    int GdFilterTime;//光电滤波时间
//    int MinThresholdMode;//最小触发模式
//    int MinTriggerTime;//最小触发时间
//    int MinTriggerDistance;//最小触发距离
//    int DelayTriggerMode;//延迟触发模式
//    int DelayTriggerTime;//延迟触发时间
//    int DelayTriggerDistance;//延迟触发距离
//    int DelayTriggerModetwo;//二次延迟触发模式
//    int DelayTriggerTimetwo;//二次延迟触发时间
//    int DelayTriggerDistancetwo;//二次延迟触发距离
//
//    int Dbchoice;//打标内容选择
//    int interpolationStep;//插值步长
//
//    int scanW_mm;//飞行振镜幅面
//    int BMQdirection;//飞行编码器方向
//    int FXDBirection;//飞行方向
//    int Dbmode;//打标模式
//
//    int JgFreq;//激光频率
//    int JgPower;//激光功率
//    int KgDelay;//开关延时
//    int GgDelay;//关光延时
//    int firstJumpDelay;//首跳延时
//    int jumpDelay;//跳转延时
//    int endDelay;//结束延时
//
//};
//
//
//// 编码转换函数
//static std::string encode_convert(const char* fromcode, const char* tocode, const char* text)
//{
//    char* tmp = (char*)text;
//    size_t lenSrc = strlen(tmp);
//    size_t lenDst = lenSrc * 5;
//    char* out = (char*)malloc(lenDst);
//    memset(out, 0, lenDst);
//    char* pFreeOut = out;
//    iconv_t cd = iconv_open(tocode, fromcode);
//    size_t ret = iconv(cd, &tmp, &lenSrc, &out, &lenDst);
//    if (ret == -1)
//    {
//        return "";
//    }
//    std::string retStr(pFreeOut);
//    iconv_close(cd);
//    free(pFreeOut);
//    return retStr;
//}
//
//// GBK转utf-8
//static std::string GBK_TO_UTF8(const char* text)
//{
//
//    if (strlen(text) == 0)
//    {
//        return "";
//    }
//    return encode_convert("GBK", "UTF-8", text);
//}
//// utf-8转GBK
//static std::string UTF8_TO_GBK(const char* text)
//{
//    if (strlen(text) == 0)
//    {
//        return "";
//    }
//    return encode_convert("UTF-8", "GBK", text);
//}
//
//string dir = "./config.db";
//sqlite3* db;//数据库句柄
//char* errmsg;//存储错误信息
//Config config;//用于临时存储参数信息的结构体，实现数据库内参数与内存内参数交换
//RunningStatus runningstatus;//用于存储运行时是否启用某项设备状态
//Jgconfig jgconfig;//用于存储激光参数信息的结构体，实现数据库内参数与内存内参数交换
//int nResult;//错误码
//vector<string> SchemeName;//存储所有方案名
//vector<string> FindSchemeName;//存储所有方案名,用于存储查询方案名
//int SelectNum = 0;//方案索引值
//
////回调函数
//int callback(void* config, int nCount, char** pValue, char** pName)
//{
//    (*(Config*)config).SCHEME = UTF8_TO_GBK(pValue[0]);
//    (*(Config*)config).ExposureTime = atoi(pValue[1]);
//    (*(Config*)config).TriggerDelay = atoi(pValue[2]);
//    (*(Config*)config).Sharpness = atof(pValue[3]);
//    (*(Config*)config).rectX = atoi(pValue[4]);
//    (*(Config*)config).rectY = atoi(pValue[5]);
//    (*(Config*)config).rectW = atoi(pValue[6]);
//    (*(Config*)config).rectH = atoi(pValue[7]);
//    (*(Config*)config).rot = atoi(pValue[8]);
//    (*(Config*)config).GapCount = atoi(pValue[9]);
//    (*(Config*)config).KeepCount = atoi(pValue[10]);
//    (*(Config*)config).GainValue = atoi(pValue[11]);
//    (*(Config*)config).CodeIndex = atoi(pValue[12]);
//    (*(Config*)config).DelayModel = atoi(pValue[13]);
//    (*(Config*)config).DelayTime = atoi(pValue[14]);
//    (*(Config*)config).DelayDistance = atoi(pValue[15]);
//    (*(Config*)config).DCLength = atoi(pValue[16]);
//    (*(Config*)config).FirstOCRSize = atof(pValue[17]);
//    (*(Config*)config).SecOCRSize = atof(pValue[18]);
//    (*(Config*)config).OutputLocationMin = atof(pValue[19]);
//    (*(Config*)config).OutputLocationMax = atof(pValue[20]);
//    (*(Config*)config).R = atoi(pValue[21]);
//    (*(Config*)config).G = atoi(pValue[22]);
//    (*(Config*)config).B = atoi(pValue[23]);
//    (*(Config*)config).RGBTime = atoi(pValue[24]);
//    (*(Config*)config).RGBMode = atoi(pValue[25]);
//  
//
//
//    return 0;
//}
//// 系统状态回调函数
//int callback_status(void* runningstatus, int nCount, char** pValue, char** pName)
//{
//    //(*(Config*)runningstatus).SCHEME = UTF8_TO_GBK(pValue[0]);
//    (*(RunningStatus*)runningstatus).MaxThresholdAlermOpen = atoi(pValue[1]);
//    (*(RunningStatus*)runningstatus).MinThresholdAlermOpen = atoi(pValue[2]);
//    (*(RunningStatus*)runningstatus).cameraAlarmOpen = atoi(pValue[3]);
//    (*(RunningStatus*)runningstatus).markingOutOfAreaOpen = atoi(pValue[4]);
//    (*(RunningStatus*)runningstatus).linkTXOpen = atoi(pValue[5]);
//    (*(RunningStatus*)runningstatus).linkBKBKOpen = atoi(pValue[6]);
//    (*(RunningStatus*)runningstatus).linkCameraOpen = atoi(pValue[7]);
//
//    return 0;
//}
////激光参数回调函数
//int callback_jgconfig(void* jgconfig, int nCount, char** pValue, char** pName)
//{
//    //(*(Config*)runningstatus).SCHEME = UTF8_TO_GBK(pValue[0]);
//    (*(Jgconfig*)jgconfig).BMQzhijing = atoi(pValue[0]);
//    (*(Jgconfig*)jgconfig).BMQmaichong = atoi(pValue[1]);
//
//    (*(Jgconfig*)jgconfig).GdFilterTime = atoi(pValue[2]);
//    (*(Jgconfig*)jgconfig).MinThresholdMode = atoi(pValue[3]);
//    (*(Jgconfig*)jgconfig).MinTriggerTime = atoi(pValue[4]);
//    (*(Jgconfig*)jgconfig).MinTriggerDistance = atoi(pValue[5]);
//    (*(Jgconfig*)jgconfig).DelayTriggerMode = atoi(pValue[6]);
//    (*(Jgconfig*)jgconfig).DelayTriggerTime = atoi(pValue[7]);
//    (*(Jgconfig*)jgconfig).DelayTriggerDistance = atoi(pValue[8]);
//    (*(Jgconfig*)jgconfig).DelayTriggerModetwo = atoi(pValue[9]);
//    (*(Jgconfig*)jgconfig).DelayTriggerTimetwo = atoi(pValue[10]);
//    (*(Jgconfig*)jgconfig).DelayTriggerDistancetwo = atoi(pValue[11]);
//
//    (*(Jgconfig*)jgconfig).Dbchoice = atoi(pValue[12]);
//    (*(Jgconfig*)jgconfig).interpolationStep = atoi(pValue[13]);
//
//    (*(Jgconfig*)jgconfig).scanW_mm = atoi(pValue[14]);
//    (*(Jgconfig*)jgconfig).BMQdirection = atoi(pValue[15]);
//    (*(Jgconfig*)jgconfig).FXDBirection = atoi(pValue[16]);
//    (*(Jgconfig*)jgconfig).Dbmode = atoi(pValue[17]);
//
//    (*(Jgconfig*)jgconfig).JgFreq = atoi(pValue[18]);
//    (*(Jgconfig*)jgconfig).JgPower = atoi(pValue[19]);
//    (*(Jgconfig*)jgconfig).KgDelay = atoi(pValue[20]);
//    (*(Jgconfig*)jgconfig).GgDelay = atoi(pValue[21]);
//    (*(Jgconfig*)jgconfig).firstJumpDelay = atoi(pValue[22]);
//    (*(Jgconfig*)jgconfig).jumpDelay = atoi(pValue[23]);
//    (*(Jgconfig*)jgconfig).endDelay = atoi(pValue[24]);
//
//    return 0;
//}
//
//int callback2(void* counter, int nCount, char** pValue, char** pName)
//{
//
//    SchemeName.insert(SchemeName.end(), UTF8_TO_GBK(pValue[0]));
//    (*((int*)counter))++;
//    return 0;
//}
//int callback3(void* counter, int nCount, char** pValue, char** pName)
//{
//    FindSchemeName.insert(FindSchemeName.end(), UTF8_TO_GBK(pValue[0]));
//    (*((int*)counter))++;
//    return 0;
//}
//int callback4(void* namecode, int nCount, char** pValue, char** pName)
//{
//
//    *((int*)namecode) = atoi(pValue[0]);
//    return 0;
//}
//int callback5(void* ImageSize, int nCount, char** pValue, char** pName)
//{
//
//    *((double*)ImageSize) = atof(pValue[0]);
//    return 0;
//}
//int callback6(void* CamFilterTime, int nCount, char** pValue, char** pName)
//{
//
//    *((int*)CamFilterTime) = atoi(pValue[0]);
//    return 0;
//}
//
////打开数据库
//bool ConnectDB()
//{
//    int rc = sqlite3_open(dir.c_str(), &db);
//    if (rc != SQLITE_OK) {
//        cout << "[Sqlite] Open DB Failed!, Detail:" << sqlite3_errmsg(db);
//        db = nullptr;
//        return false;
//    }
//    return true;
//}
//
////遍历数据表
//int Traverse()
//{
//    SchemeName.clear();
//    int DBcounters = 0;
//    string strSql = "select * from config";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback2, &DBcounters, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return DBcounters;
//    }
//    return DBcounters;
//}
//
////查询数据库
//bool SelectDB(string str)
//{
//    string strSql = "select * from config where SCHEME='" + str + "'";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback, &config, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////插入数据
//bool InsertDB(string schemeName)
//{
//    string insertSql = "insert into config(SCHEME,ExposureTime,TriggerDelay,Sharpness,rectX,rectY,rectW,rectH,rot,GapCount,KeepCount,GainValue,CodeIndex,DelayModel,DelayTime,DelayDistance,DCLength,FirstOCRSize,SecOCRSize,OutputLocationMin,OutputLocationMax,R,G,B,RGBTime,RGBMode) values('"
//        + schemeName + "'" + "," + to_string(ExposureTime) + "," + to_string(TriggerDelay) + "," + to_string(Sharpness) + "," + to_string(rectX) + "," + to_string(rectY) + ","
//        + to_string(rectW) + "," + to_string(rectH) + "," + to_string(rot) + "," + to_string(GapCount) + "," + to_string(KeepCount) + "," + to_string(GainValue)
//        + "," + to_string(CodeIndex) + "," + to_string(DelayModel) + "," + to_string(DelayTime) + "," + to_string(DelayDistance) + "," + to_string(DCLength) + "," + to_string(FirstOCRSize)
//        + "," + to_string(SecOCRSize) + "," + to_string(OutputLocationMin) + "," + to_string(OutputLocationMax) + "," + to_string(R) + "," + to_string(G) + "," + to_string(B) + "," + to_string(RGBTime) + "," + to_string(RGBMode) + ");";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(insertSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
//
////删除数据
//bool DeleteDB(string str)
//{
//    string deleteSql = "delete from config where SCHEME ='" + str + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(deleteSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////修改数据库
//bool AlterDB(string rstr)
//{
//    string updateSql = "update config set ExposureTime =" + to_string(ExposureTime) + ",TriggerDelay=" + to_string(TriggerDelay) + ",Sharpness=" + to_string(Sharpness) +
//        ",rectX=" + to_string(rectX) + ",rectY=" + to_string(rectY) + ",rectW=" + to_string(rectW) + ",rectH=" + to_string(rectH)
//        + ",rot=" + to_string(rot) + ",GapCount=" + to_string(GapCount) + ",KeepCount=" + to_string(KeepCount) + ",GainValue=" + to_string(GainValue) + ",CodeIndex=" + to_string(CodeIndex)
//        + ",DelayModel=" + to_string(DelayModel) + ",DelayTime=" + to_string(DelayTime) + ",DelayDistance=" + to_string(DelayDistance) + ",DCLength=" + to_string(DCLength)
//        + ",FirstOCRSize=" + to_string(FirstOCRSize) + ",SecOCRSize=" + to_string(SecOCRSize) + ",OutputLocationMin=" + to_string(OutputLocationMin) + ",OutputLocationMax=" + to_string(OutputLocationMax)
//        + ",R=" + to_string(R) + ",G=" + to_string(G) + ",B=" + to_string(B) + ",RGBTime=" + to_string(RGBTime) + ",RGBMode=" + to_string(RGBMode) + " where SCHEME = '" + rstr + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////查询设备状态
//bool SelectDB_Status()
//{
//    string strSql = "select * from RunningStatus where StatusList=0";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_status, &runningstatus, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////修改设备监控状态数据库
//bool AlterDB_Status()
//{
//    string updateSql = "update RunningStatus set MaxThresholdAlermOpen =" + to_string(MaxThresholdAlermOpen) + ",MinThresholdAlermOpen=" + to_string(MinThresholdAlermOpen) + ",cameraAlarmOpen=" + to_string(cameraAlarmOpen) +
//        ",markingOutOfAreaOpen=" + to_string(markingOutOfAreaOpen) + ",linkTXOpen=" + to_string(linkTXOpen) + ",linkBKBKOpen=" + to_string(linkBKBKOpen)+",linkCameraOpen="+to_string(linkCameraOpen) + " where StatusList = 0";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////查询激光参数
//bool SelectDB_Jgconfig()
//{
//    string strSql = "select * from Jgconfig where BMQzhijing";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_jgconfig, &jgconfig, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////修改激光参数数据库
//bool AlterDB_Jgconfig()
//{
//
//    string updateSql = "update Jgconfig set BMQzhijing =" + to_string(jgconfig.BMQzhijing) + ",BMQmaichong=" + to_string(jgconfig.BMQmaichong) + ",GdFilterTime=" + to_string(jgconfig.GdFilterTime) +
//        ",MinThresholdMode=" + to_string(jgconfig.MinThresholdMode) + ",MinTriggerTime=" + to_string(jgconfig.MinTriggerTime) + ",MinTriggerDistance=" + to_string(jgconfig.MinTriggerDistance) +
//        ",DelayTriggerMode=" + to_string(jgconfig.DelayTriggerMode) + ",DelayTriggerTime=" + to_string(jgconfig.DelayTriggerTime) + ",DelayTriggerDistance=" + to_string(jgconfig.DelayTriggerDistance) +
//        ",DelayTriggerModetwo=" + to_string(jgconfig.DelayTriggerModetwo) + ",DelayTriggerTimetwo=" + to_string(jgconfig.DelayTriggerTimetwo) + ",DelayTriggerDistancetwo=" + to_string(jgconfig.DelayTriggerDistancetwo) +
//        ",Dbchoice=" + to_string(jgconfig.Dbchoice) + ",interpolationStep=" + to_string(jgconfig.interpolationStep) + ",scanW_mm=" + to_string(jgconfig.scanW_mm) + ",BMQdirection=" + to_string(jgconfig.BMQdirection) +
//        ",FXDBirection=" + to_string(jgconfig.FXDBirection) + ",Dbmode=" + to_string(jgconfig.Dbmode) + ",JgFreq=" + to_string(jgconfig.JgFreq) + ",JgPower=" + to_string(jgconfig.JgPower) +
//        ",KgDelay=" + to_string(jgconfig.KgDelay) + ",GgDelay=" + to_string(jgconfig.GgDelay) + ",firstJumpDelay=" + to_string(jgconfig.firstJumpDelay) +
//        ",jumpDelay=" + to_string(jgconfig.jumpDelay) + ",endDelay=" + to_string(jgconfig.endDelay);
//
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
//
//
////查询方案名是否存在
//int SelectSchName(string str)
//{
//    FindSchemeName.clear();
//    string strSql = "select * from config";
//    int Counter = 0;
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback3, &Counter, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    for (int i = 0; i < Counter; i++)
//    {
//        if (str == FindSchemeName[i])
//        {
//            return 1;
//        }
//    }
//    return 2;
//}
//
////查询保存的方案索引
//int FindNameCode()
//{
//    string strSql = "select * from SchemeNameCode";
//    int NameCode = 0;
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback4, &NameCode, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return NameCode;
//}
//
////更新保存的方案索引
//bool SaveNameCode(int code)
//{
//
//    string strSql = "delete from SchemeNameCode";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
//
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//
//    string strSql2 = "insert into SchemeNameCode(NameCode) values(" + to_string(code) + ");";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
//
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////查询保存的图片放缩比
//double FindImageSize()
//{
//    string strSql = "select * from ImageSize";
//    double ImageSize = 0.1;
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback5, &ImageSize, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return ImageSize;
//}
//
////更新保存的图片缩放比
//bool SaveImageSize(double ImageSize)
//{
//    string strSql = "delete from ImageSize";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
//
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//
//    string strSql2 = "insert into ImageSize(ImageSize) values(" + to_string(ImageSize) + ");";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
//
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////查询拍照滤波时间
//int FindCamFilterTime()
//{
//    string strSql = "select * from CamFilter";
//    int CamFilterTime = 1;
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback6, &CamFilterTime, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return CamFilterTime;
//}
////更新拍照滤波时间
//bool SaveCamFilterTime(int CamFilterTime)
//{
//    string strSql = "delete from CamFilter";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
//
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//
//    string strSql2 = "insert into CamFilter(CamFilterTime) values(" + to_string(CamFilterTime) + ");";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
//
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////int callback7(void* CamFilterLength, int nCount, char** pValue, char** pName)
////{
////
////    *((int*)CamFilterLength) = atoi(pValue[0]);
////    return 0;
////}
////查询拍照滤波距离
////int FindCamFilterLength()
////{
////    string strSql = "select * from CamFilterLength";
////    int CamFilterLength = 100;
////    //回调函数
////    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback7, &CamFilterLength, &errmsg);
////    if (nResult != SQLITE_OK)
////    {
////        sqlite3_close(db);
////        cout << errmsg << endl;
////        sqlite3_free(errmsg);
////        return 0;
////    }
////    return CamFilterLength;
////}
////更新拍照滤波距离
////bool SaveCamFilterLength(int CamFilterLength)
////{
////    string strSql = "delete from CamFilterLength";
////    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
////
////    if (nResult != SQLITE_OK)
////    {
////        sqlite3_close(db);
////        cout << errmsg << endl;
////        sqlite3_free(errmsg);
////        return 0;
////    }
////
////    string strSql2 = "insert into CamFilterLength(CamFilterLength) values(" + to_string(CamFilterLength) + ");";
////    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
////
////    if (nResult != SQLITE_OK)
////    {
////        sqlite3_close(db);
////        cout << errmsg << endl;
////        sqlite3_free(errmsg);
////        return 0;
////    }
////    return 1;
////}
//
////获取文件夹内所有图片名
//bool get_filelist_from_dir(std::string path, std::vector<std::string>& files)
//{
//    long long  hFile = 0;
//    //_findnext()第一个参数”路径句柄”，返回的类型为intptr_t（long long），
//    //如果定义为long，在win7中是没有问题，但是在win10中就要改为long long或者intptr_t
//    struct _finddata_t fileinfo;
//    files.clear();
//    if ((hFile = _findfirst(path.c_str(), &fileinfo)) != -1)
//    {
//        do
//        {
//            if (!(fileinfo.attrib & _A_SUBDIR))
//            {
//                files.push_back(fileinfo.name);
//            }
//        } while (_findnext(hFile, &fileinfo) == 0);
//        _findclose(hFile);
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//vector<string> getImageList(std::string file_path, std::string suffix)
//{
//    string search_path = file_path + suffix;
//    vector<string> file_list;//保存遍历到的文件name
//    if (!get_filelist_from_dir(search_path, file_list))
//    {
//        //std::cout << "open file error!" << std::endl;
//    }
//    vector<string> image_path_list;//保存文件绝对路径
//    for (int i = 0; i < file_list.size(); i++)
//    {
//        image_path_list.push_back(file_path + file_list[i]);
//
//    }
//    return image_path_list;
//}
//
////保存栏目内容--------------------------------------------------------------
//string CustomStr, CustomStr_2, CustomStr_3, CustomStr_4, CustomStr_5, CustomStr_6;//内容栏保存的格式string SchemeName;
//QString Start_Data_Time;
//QString FH;
//int year, month,day;
//int Savemonth, Saveyear, save_time = 181;
//QString Save_Time;
//bool SCenabled;
//bool BZenabled;
//bool EWenabled;
//
//struct SchemeContent
//{
//    string CustomStr;
//    string CustomStr_2;
//    string CustomStr_3;
//    string CustomStr_4; 
//    string CustomStr_5;
//    string CustomStr_6;
//    bool SCenabled;
//    bool BZenabled;
//    bool EWenabled;
//    int save_time;
//    int Savemonth;
//    int Saveyear;
//};
//SchemeContent schemecontent;
////栏目内容回调函数
//int callback_schemecontent(void* schemecontent, int nCount, char** pValue, char** pName)
//{
//    //(*(SchemeContent*)schemecontent).SCHEME = UTF8_TO_GBK(pValue[0]);
//    (*(SchemeContent*)schemecontent).CustomStr = UTF8_TO_GBK(pValue[1]);
//    (*(SchemeContent*)schemecontent).CustomStr_2 = UTF8_TO_GBK(pValue[2]);
//    (*(SchemeContent*)schemecontent).CustomStr_3 = UTF8_TO_GBK(pValue[3]);
//    (*(SchemeContent*)schemecontent).CustomStr_4 = UTF8_TO_GBK(pValue[4]);
//    (*(SchemeContent*)schemecontent).CustomStr_5 = UTF8_TO_GBK(pValue[5]);
//    (*(SchemeContent*)schemecontent).CustomStr_6 = UTF8_TO_GBK(pValue[6]);
//    (*(SchemeContent*)schemecontent).SCenabled = atoi(pValue[7]);
//    (*(SchemeContent*)schemecontent).BZenabled = atoi(pValue[8]);
//    (*(SchemeContent*)schemecontent).EWenabled = atoi(pValue[9]);
//    (*(SchemeContent*)schemecontent).save_time = atoi(pValue[10]);
//    (*(SchemeContent*)schemecontent).Savemonth = atoi(pValue[11]);
//    (*(SchemeContent*)schemecontent).Saveyear = atoi(pValue[12]);
//
//
//
//    return 0;
//}
////查询栏目内容数据库
//bool SelectSchemeContent(string schemeName)
//{
//
//    string strSql = "select * from SchemeContent where SchemeName='" + schemeName + "'";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_schemecontent, &schemecontent, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////插入栏目内容
//bool InsertSchemeContent(string schemeName)
//{
//    string insertSql = "insert into SchemeContent(SchemeName,CustomStr,CustomStr_2,CustomStr_3,CustomStr_4,CustomStr_5,CustomStr_6) values('"
//        + schemeName + "','" + CustomStr + "','" + CustomStr_2 + "','" + CustomStr_3 + "','" + CustomStr_4 + "','" + CustomStr_5 + "','" + CustomStr_6 + "');";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(insertSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////删除栏目内容
//bool DeleteSchemeContent(string schemeName)
//{
//    string deleteSql = "delete from SchemeContent where SchemeName ='" + schemeName + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(deleteSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////修改栏目内容
//bool AlterSchemeContent(string schemeName)
//{
//    string updateSql = "update SchemeContent set CustomStr ='" + CustomStr + "',CustomStr_2='" + CustomStr_2 + "',CustomStr_3='" + CustomStr_3 +
//        "',CustomStr_4='" + CustomStr_4 + "',CustomStr_5='" + CustomStr_5 + "',CustomStr_6='" + CustomStr_6 + "',SCenabled='" + to_string(SCenabled) + "',BZenabled='" + to_string(BZenabled) + "',EWenabled='" + to_string(EWenabled)+"',save_time='" + to_string(save_time) + "',Savemonth='" + to_string(Savemonth) + "',Saveyear='" + to_string(Saveyear) + "' where SchemeName = '" + schemeName + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////*******************************user数据库******************************************************************
//string USERname;
//int PenMa;
//int LiuShuixian;
//int Chufa;
//int FangZhen;
//int PeiFang;
//int xiangJi;
//int CDL;
//int YongHu;
//int BianJi;
//string password;
//vector<string> Name;//存储所有用户名
//vector<string> FindName;//存储所有用户名,用于存储查询用户名
//int TraverseUsernum;
//struct userconfig
//{
//    string USERname;
//    int PenMa;
//    int LiuShuixian;
//    int Chufa;
//    int FangZhen;
//    int PeiFang;
//    int xiangJi;
//    int CDL;
//    int YongHu;
//    string password;
//    int BianJi ;
//};
//
//userconfig userinfo;
//
////栏目内容回调函数
//int callback_user(void* userinfo, int nCount, char** pValue, char** pName)
//{
//    (*(userconfig*)userinfo).USERname = UTF8_TO_GBK(pValue[0]);
//    (*(userconfig*)userinfo).PenMa = atoi(pValue[1]);
//    (*(userconfig*)userinfo).LiuShuixian = atoi(pValue[2]);
//    (*(userconfig*)userinfo).Chufa = atoi(pValue[3]);
//    (*(userconfig*)userinfo).FangZhen = atoi(pValue[4]);
//    (*(userconfig*)userinfo).PeiFang = atoi(pValue[5]);
//    (*(userconfig*)userinfo).xiangJi = atoi(pValue[6]);
//    (*(userconfig*)userinfo).CDL = atoi(pValue[7]);
//    (*(userconfig*)userinfo).YongHu = atoi(pValue[8]);
//    (*(userconfig*)userinfo).password = UTF8_TO_GBK(pValue[9]);
//    (*(userconfig*)userinfo).BianJi = atoi(pValue[10]);
//
//    return 0;
//}
//int callback_user2(void* counter, int nCount, char** pValue, char** pName)
//{
//
//    Name.insert(Name.end(), UTF8_TO_GBK(pValue[0]));
//    (*((int*)counter))++;
//    return 0;
//}
//int callback_user3(void* counter, int nCount, char** pValue, char** pName)
//{
//    FindName.insert(FindName.end(), UTF8_TO_GBK(pValue[0]));
//    (*((int*)counter))++;
//    return 0;
//}
//
//
////遍历数据表
//int TraverseUser()
//{
//    Name.clear();
//    int DBcounters = 0;
//    string strSql = "select * from User";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_user2, &DBcounters, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return DBcounters;
//    }
//    return DBcounters;
//}
////查询方案名是否存在
//int SelectSchUserName(string str)
//{
//    FindName.clear();
//    string strSql = "select * from User";
//    int Counter = 0;
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_user3, &Counter, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    for (int i = 0; i < Counter; i++)
//    {
//        if (str == FindName[i])
//        {
//            return 1;
//        }
//    }
//    return 2;
//}
////查询栏目内容数据库
//bool SelectUser(string schemeName)
//{
//
//    string strSql = "select * from User where USERname='" + schemeName + "'";
//    //回调函数
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_user, &userinfo, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////插入栏目内容
//bool InsertUser(string schemeName)
//{
//    string insertSql = "insert into User(USERname,PenMa,LiuShuixian,Chufa,FangZhen,PeiFang,XiangJi,CDL,YongHu,password,BianJi) values('"
//        + schemeName + "','" + to_string(PenMa) + "','" + to_string(LiuShuixian) + "','" + to_string(Chufa) + "','" + to_string(FangZhen) + "','"
//        + to_string(PeiFang) + "','" + to_string(xiangJi) + "','" + to_string(CDL) + "','" + to_string(YongHu) + "','" + password + "','" + to_string(BianJi) + "');";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(insertSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////删除栏目内容
//bool DeleteUser(string schemeName)
//{
//    string deleteSql = "delete from User where USERname ='" + schemeName + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(deleteSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
//
////修改栏目内容
//bool AlterUser(string schemeName)
//{
//    string updateSql = "update User set PenMa ='" + to_string(PenMa) + "',LiuShuixian='" + to_string(LiuShuixian) + "',Chufa='" + to_string(Chufa) +
//        "',FangZhen='" + to_string(FangZhen) + "',PeiFang='" + to_string(PeiFang) + "',XiangJi='" + to_string(xiangJi) + "',CDL='" + to_string(CDL) + "',YongHu='" + to_string(YongHu) + "',BianJi='" + to_string(BianJi) + "' where USERname = '" + schemeName + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
////修改密码
//bool AlterPassword(string schemeName, string newpassword)
//{
//    string updateSql = "update User set password ='" + newpassword + "' where USERname = '" + schemeName + "'";
//    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
//    if (nResult != SQLITE_OK)
//    {
//        sqlite3_close(db);
//        cout << errmsg << endl;
//        sqlite3_free(errmsg);
//        return 0;
//    }
//    return 1;
//}
// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "sqlite3.h"
#include <string>
#include <vector>
#include "iconv.h"
#include "GalaxyIncludes.h"
#include "QString"
// 使用命名空间
using namespace std;

// 全局变量声明（外部变量）
extern QString abcaaastr;
extern bool m_isLoggedIn;
extern bool IsOpenAlarm;
extern bool IsOpenBKBK;
extern bool isOpenCam;
extern bool model;
extern bool IsSettingOpen;
extern bool IsJgadminOpen;
extern bool IsxjadminOpen;
extern bool IsAlarm;
extern bool IsAutoCap;
extern bool IsCloseSoftware;
extern bool IsAlter;
extern int Userindex;
extern int ExposureTime;
extern int TriggerDelay;
extern double Sharpness;
extern int rot;
extern int GainValue;
extern int CodeIndex;
extern int rectX, rectY, rectW, rectH;
extern cv::Rect rects;
extern cv::Mat image;
extern cv::Mat resizeImage;
extern double ImageSize;
extern int GapCount, KeepCount;
extern int DelayModel;
extern int DelayTime;
extern int DelayDistance;
extern int DCLength;
extern double FirstOCRSize;
extern double SecOCRSize;
extern int OutputLocationMin;
extern int OutputLocationMax;
extern double LocationScale;//最大最小距离比例
extern int R, G, B;
extern int RGBTime;
extern int RGBMode;
extern int CamFilterTime;
extern int CamFilterLength;
extern vector<string> ImageList;
extern int ImageListIndex;
extern double OKnum, NGnum, Totalnum;
extern gxdeviceinfo_vector vectorDeviceInfo;
extern CGXDevicePointer ObjDevicePtr;
extern CGXStreamPointer ObjStreamPtr;
extern CGXFeatureControlPointer ObjFeatureControlPtr;
extern ICaptureEventHandler* pCaptureEventHandler;
extern IDeviceOfflineEventHandler* pDeviceOfflineEventHandler;
extern GX_DEVICE_OFFLINE_CALLBACK_HANDLE hDeviceOffline;
extern int MaxThresholdAlermOpen;
extern int MinThresholdAlermOpen;
extern int cameraAlarmOpen;
extern int markingOutOfAreaOpen;
extern int linkTXOpen;
extern int linkBKBKOpen;
extern int linkCameraOpen;

extern int ImageWidth;
extern int ImageHeight;
extern int ImageMagnification;
extern int mtextlowerLeftx;
extern int mtextlowerLefty;
extern int mtexttotalWidth;
extern int mtexttotalHeight;

// 数据库相关全局变量
extern string dir;
extern sqlite3* db;
extern char* errmsg;
extern int nResult;
extern vector<string> SchemeName;
extern vector<string> FindSchemeName;
extern int SelectNum;
extern int TraverseUsernum;
extern vector<string> Name;
extern vector<string> FindName;

// 保存栏目内容相关变量
extern string CustomStr, CustomStr_2, CustomStr_3, CustomStr_4, CustomStr_5, CustomStr_6;
extern QString Start_Data_Time;
extern QString FH;
extern int year, month, day;
extern int Savemonth, Saveyear, save_time;
extern QString Save_Time;
extern bool SCenabled, BZenabled, EWenabled;

// 用户相关全局变量
extern string USERname;
extern int PenMa, LiuShuixian, Chufa, FangZhen, PeiFang, xiangJi, CDL, YongHu, BianJi;
extern string password;

// 结构体声明
struct Config
{
    string SCHEME;
    int ExposureTime;
    int TriggerDelay;
    double Sharpness;
    int rectX;
    int rectY;
    int rectW;
    int rectH;
    int rot;
    int GapCount;
    int KeepCount;
    int GainValue = 0;//增益值
    int CodeIndex = 0;
    int DelayModel = 0;
    int DelayTime = 0;
    int DelayDistance = 0;
    int DCLength = 0;
    double FirstOCRSize = 0.7;
    double SecOCRSize = 0.5;
    int OutputLocationMin = 30;
    int OutputLocationMax = 30;
    int R;
    int G;
    int B;
    int RGBTime;
    int RGBMode;
    //int MinThresholdMode;//最小触发模式
    //int MinTriggerTime;//最小触发时间
    //int MinTriggerDistance;//最小触发距离
    //int DelayTriggerMode;//延迟触发模式
    //int DelayTriggerTime;//延迟触发时间
    //int DelayTriggerDistance;//延迟触发距离
    //int DelayTriggerModetwo;//二次延迟触发模式
    //int DelayTriggerTimetwo;//二次延迟触发时间
    //int DelayTriggerDistancetwo;//二次延迟触发距离
    int Dbmode;//打标模式
};

struct RunningStatus
{
    int MaxThresholdAlermOpen = 1;//上限报警
    int MinThresholdAlermOpen = 1;//下限报警
    int cameraAlarmOpen = 1;//相机报警
    int markingOutOfAreaOpen = 1;//标刻区域外报警

    int linkTXOpen = 1;//相机联机功能启用
    int linkBKBKOpen = 1;//标刻联机功能启用
    int linkCameraOpen = 1;//通讯联机功能启用
};

struct Jgconfig
{
    int BMQzhijing;//编码器直径
    int BMQmaichong;//编码器脉冲

    int GdFilterTime;//光电滤波时间
    int MinThresholdMode;//最小触发模式
    int MinTriggerTime;//最小触发时间
    int MinTriggerDistance;//最小触发距离
    int DelayTriggerMode;//延迟触发模式
    int DelayTriggerTime;//延迟触发时间
    int DelayTriggerDistance;//延迟触发距离
    int DelayTriggerModetwo;//二次延迟触发模式
    int DelayTriggerTimetwo;//二次延迟触发时间
    int DelayTriggerDistancetwo;//二次延迟触发距离

    int Dbchoice;//打标内容选择
    int interpolationStep;//插值步长

    int scanW_mm;//飞行振镜幅面
    int BMQdirection;//飞行编码器方向
    int FXDBirection;//飞行方向
    int Dbmode;//打标模式

    int JgFreq;//激光频率
    int JgPower;//激光功率
    int KgDelay;//开关延时
    int GgDelay;//关光延时
    int firstJumpDelay;//首跳延时
    int jumpDelay;//跳转延时
    int endDelay;//结束延时
};

struct SchemeContent
{
    string CustomStr;
    string CustomStr_2;
    string CustomStr_3;
    string CustomStr_4;
    string CustomStr_5;
    string CustomStr_6;
    bool SCenabled;
    bool BZenabled;
    bool EWenabled;
    int save_time;
    int Savemonth;
    int Saveyear;
};

struct userconfig
{
    string USERname;
    int PenMa;
    int LiuShuixian;
    int Chufa;
    int FangZhen;
    int PeiFang;
    int xiangJi;
    int CDL;
    int YongHu;
    string password;
    int BianJi;
};

// 全局结构体变量声明
extern Config config;
extern RunningStatus runningstatus;
extern Jgconfig jgconfig;
extern SchemeContent schemecontent;
extern userconfig userinfo;

// 编码转换函数声明
string GBK_TO_UTF8(const char* text);
string UTF8_TO_GBK(const char* text);

// 数据库操作函数声明
bool ConnectDB();
int Traverse();
bool SelectDB(string str);
bool InsertDB(string schemeName);
bool DeleteDB(string str);
bool AlterDB(string rstr);
bool AlterSchemeName(string pre_name, string altered_name);
bool SelectDB_Status();
bool AlterDB_Status();
bool SelectDB_Jgconfig();
bool AlterDB_Jgconfig();
int SelectSchName(string str);
int FindNameCode();
bool SaveNameCode(int code);
double FindImageSize();
bool SaveImageSize(double ImageSize);
int FindCamFilterTime();
bool SaveCamFilterTime(int CamFilterTime);
bool get_filelist_from_dir(std::string path, std::vector<std::string>& files);
vector<string> getImageList(std::string file_path, std::string suffix);

// 方案内容相关函数声明
bool SelectSchemeContent(string schemeName);
bool InsertSchemeContent(string schemeName);
bool DeleteSchemeContent(string schemeName);
bool AlterSchemeContent(string schemeName);

// 用户管理相关函数声明
int TraverseUser();
int SelectSchUserName(string str);
bool SelectUser(string schemeName);
bool InsertUser(string schemeName);
bool DeleteUser(string schemeName);
bool AlterUser(string schemeName);
bool AlterPassword(string schemeName, string newpassword);

// 回调函数声明
int callback(void* config, int nCount, char** pValue, char** pName);
int callback_status(void* runningstatus, int nCount, char** pValue, char** pName);
int callback_jgconfig(void* jgconfig, int nCount, char** pValue, char** pName);
int callback2(void* counter, int nCount, char** pValue, char** pName);
int callback3(void* counter, int nCount, char** pValue, char** pName);
int callback4(void* namecode, int nCount, char** pValue, char** pName);
int callback5(void* ImageSize, int nCount, char** pValue, char** pName);
int callback6(void* CamFilterTime, int nCount, char** pValue, char** pName);
int callback_schemecontent(void* schemecontent, int nCount, char** pValue, char** pName);
int callback_user(void* userinfo, int nCount, char** pValue, char** pName);
int callback_user2(void* counter, int nCount, char** pValue, char** pName);
int callback_user3(void* counter, int nCount, char** pValue, char** pName);

#endif // CONFIG_H