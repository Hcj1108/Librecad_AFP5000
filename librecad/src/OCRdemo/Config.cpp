// Config.cpp
#include "Config.h"
#include <fstream>
#include <io.h>
#include <iostream>

using namespace std;

// 全局变量定义
QString abcaaastr="123";
bool m_isLoggedIn = false;
bool IsOpenAlarm = true;
bool IsOpenBKBK = false;
bool isOpenCam = false;
bool model = true;          //硬触发模式和监控模式
bool IsSettingOpen = false;
bool IsJgadminOpen = false;
bool IsxjadminOpen = false;
bool IsAlarm = false;
bool IsAutoCap = false;
bool IsCloseSoftware = false;
bool IsAlter = false;
int Userindex = 0;
int ExposureTime = 300;
int TriggerDelay = 0;
double Sharpness = 0;
int rot = 0;
int GainValue = 0;
int CodeIndex = 0;
int rectX = 50, rectY = 50, rectW = 100, rectH = 50;
cv::Rect rects(rectX, rectY, rectW, rectH);
cv::Mat image;
cv::Mat resizeImage;
double ImageSize = 0.66;
int GapCount = 7, KeepCount = 3;
int DelayModel = 0;
int DelayTime = 0;
int DelayDistance = 0;
int DCLength = 0;
double FirstOCRSize = 0.7;
double SecOCRSize = 0.5;
int OutputLocationMin = 30;
int OutputLocationMax = 30;
double LocationScale = 0.5;//最大最小距离比例
int R = 255, G = 255, B = 255;
int RGBTime = 10;
int RGBMode = 1;
int CamFilterTime = 100;
int CamFilterLength = 100;
vector<string> ImageList;
int ImageListIndex = 0;
double OKnum = 0;
double NGnum = 0;
double Totalnum = 0;

int ImageWidth ;//相机初始分x辨率
int ImageHeight ;//相机初始分y辨率
int ImageMagnification = 80;//相机图片实体放大倍数
int mtextlowerLeftx=0;//roix偏移，默认0无偏移
int mtextlowerLefty=0;//roiy偏移，默认0无偏移
int mtexttotalWidth;//roi宽，默认无框线
int mtexttotalHeight;//roi高，默认无框选

gxdeviceinfo_vector vectorDeviceInfo;
CGXDevicePointer ObjDevicePtr;
CGXStreamPointer ObjStreamPtr;
CGXFeatureControlPointer ObjFeatureControlPtr;
ICaptureEventHandler* pCaptureEventHandler = NULL;
IDeviceOfflineEventHandler* pDeviceOfflineEventHandler = NULL;
GX_DEVICE_OFFLINE_CALLBACK_HANDLE hDeviceOffline = NULL;

int MaxThresholdAlermOpen = 0;
int MinThresholdAlermOpen = 0;
int cameraAlarmOpen = 0;
int markingOutOfAreaOpen = 0;
int linkTXOpen = 0;
int linkBKBKOpen = 0;
int linkCameraOpen = 0;

// 数据库相关全局变量定义
string dir = "./config.db";
sqlite3* db = nullptr;
char* errmsg = nullptr;
int nResult = 0;
vector<string> SchemeName;
vector<string> FindSchemeName;
int SelectNum = 0;
int TraverseUsernum = 0;
vector<string> Name;
vector<string> FindName;

// 保存栏目内容相关变量定义
string CustomStr, CustomStr_2, CustomStr_3, CustomStr_4, CustomStr_5, CustomStr_6;
QString Start_Data_Time;
QString FH;
int year = 0, month = 0, day = 0;
int Savemonth = 0, Saveyear = 0, save_time = 181;
QString Save_Time;
bool SCenabled = false;
bool BZenabled = false;
bool EWenabled = false;

// 用户相关全局变量定义
string USERname = "";
int PenMa = 0, LiuShuixian = 0, Chufa = 0, FangZhen = 0, PeiFang = 0, xiangJi = 0, CDL = 0, YongHu = 0, BianJi = 0;
string password = "";

// 全局结构体变量定义
Config config ;

RunningStatus runningstatus;

Jgconfig jgconfig ;

SchemeContent schemecontent;

userconfig userinfo;

// 编码转换函数实现
static string encode_convert(const char* fromcode, const char* tocode, const char* text)
{
    char* tmp = (char*)text;
    size_t lenSrc = strlen(tmp);
    size_t lenDst = lenSrc * 5;
    char* out = (char*)malloc(lenDst);
    memset(out, 0, lenDst);
    char* pFreeOut = out;
    iconv_t cd = iconv_open(tocode, fromcode);
    size_t ret = iconv(cd, &tmp, &lenSrc, &out, &lenDst);
    if (ret == -1)
    {
        return "";
    }
    string retStr(pFreeOut);
    iconv_close(cd);
    free(pFreeOut);
    return retStr;
}

string GBK_TO_UTF8(const char* text)
{
    if (strlen(text) == 0)
    {
        return "";
    }
    return encode_convert("GBK", "UTF-8", text);
}

string UTF8_TO_GBK(const char* text)
{
    if (strlen(text) == 0)
    {
        return "";
    }
    return encode_convert("UTF-8", "GBK", text);
}

//回调函数
int callback(void* config, int nCount, char** pValue, char** pName)
{
    (*(Config*)config).SCHEME = UTF8_TO_GBK(pValue[0]);
    (*(Config*)config).ExposureTime = atoi(pValue[1]);
    (*(Config*)config).TriggerDelay = atoi(pValue[2]);
    (*(Config*)config).Sharpness = atof(pValue[3]);
    (*(Config*)config).rectX = atoi(pValue[4]);
    (*(Config*)config).rectY = atoi(pValue[5]);
    (*(Config*)config).rectW = atoi(pValue[6]);
    (*(Config*)config).rectH = atoi(pValue[7]);
    (*(Config*)config).rot = atoi(pValue[8]);
    (*(Config*)config).GapCount = atoi(pValue[9]);
    (*(Config*)config).KeepCount = atoi(pValue[10]);
    (*(Config*)config).GainValue = atoi(pValue[11]);
    (*(Config*)config).CodeIndex = atoi(pValue[12]);
    (*(Config*)config).DelayModel = atoi(pValue[13]);
    (*(Config*)config).DelayTime = atoi(pValue[14]);
    (*(Config*)config).DelayDistance = atoi(pValue[15]);
    (*(Config*)config).DCLength = atoi(pValue[16]);
    (*(Config*)config).FirstOCRSize = atof(pValue[17]);
    (*(Config*)config).SecOCRSize = atof(pValue[18]);
    (*(Config*)config).OutputLocationMin = atof(pValue[19]);
    (*(Config*)config).OutputLocationMax = atof(pValue[20]);
    (*(Config*)config).R = atoi(pValue[21]);
    (*(Config*)config).G = atoi(pValue[22]);
    (*(Config*)config).B = atoi(pValue[23]);
    (*(Config*)config).RGBTime = atoi(pValue[24]);
    (*(Config*)config).RGBMode = atoi(pValue[25]);
    return 0;
}

// 系统状态回调函数
int callback_status(void* runningstatus, int nCount, char** pValue, char** pName)
{
    //(*(Config*)runningstatus).SCHEME = UTF8_TO_GBK(pValue[0]);
    (*(RunningStatus*)runningstatus).MaxThresholdAlermOpen = atoi(pValue[1]);
    (*(RunningStatus*)runningstatus).MinThresholdAlermOpen = atoi(pValue[2]);
    (*(RunningStatus*)runningstatus).cameraAlarmOpen = atoi(pValue[3]);
    (*(RunningStatus*)runningstatus).markingOutOfAreaOpen = atoi(pValue[4]);
    (*(RunningStatus*)runningstatus).linkTXOpen = atoi(pValue[5]);
    (*(RunningStatus*)runningstatus).linkBKBKOpen = atoi(pValue[6]);
    (*(RunningStatus*)runningstatus).linkCameraOpen = atoi(pValue[7]);

    return 0;
}

//激光参数回调函数
int callback_jgconfig(void* jgconfig, int nCount, char** pValue, char** pName)
{
    //(*(Config*)runningstatus).SCHEME = UTF8_TO_GBK(pValue[0]);
    (*(Jgconfig*)jgconfig).BMQzhijing = atoi(pValue[0]);
    (*(Jgconfig*)jgconfig).BMQmaichong = atoi(pValue[1]);

    (*(Jgconfig*)jgconfig).GdFilterTime = atoi(pValue[2]);
    (*(Jgconfig*)jgconfig).MinThresholdMode = atoi(pValue[3]);
    (*(Jgconfig*)jgconfig).MinTriggerTime = atoi(pValue[4]);
    (*(Jgconfig*)jgconfig).MinTriggerDistance = atoi(pValue[5]);
    (*(Jgconfig*)jgconfig).DelayTriggerMode = atoi(pValue[6]);
    (*(Jgconfig*)jgconfig).DelayTriggerTime = atoi(pValue[7]);
    (*(Jgconfig*)jgconfig).DelayTriggerDistance = atoi(pValue[8]);
    (*(Jgconfig*)jgconfig).DelayTriggerModetwo = atoi(pValue[9]);
    (*(Jgconfig*)jgconfig).DelayTriggerTimetwo = atoi(pValue[10]);
    (*(Jgconfig*)jgconfig).DelayTriggerDistancetwo = atoi(pValue[11]);

    (*(Jgconfig*)jgconfig).Dbchoice = atoi(pValue[12]);
    (*(Jgconfig*)jgconfig).interpolationStep = atoi(pValue[13]);

    (*(Jgconfig*)jgconfig).scanW_mm = atoi(pValue[14]);
    (*(Jgconfig*)jgconfig).BMQdirection = atoi(pValue[15]);
    (*(Jgconfig*)jgconfig).FXDBirection = atoi(pValue[16]);
    (*(Jgconfig*)jgconfig).Dbmode = atoi(pValue[17]);

    (*(Jgconfig*)jgconfig).JgFreq = atoi(pValue[18]);
    (*(Jgconfig*)jgconfig).JgPower = atoi(pValue[19]);
    (*(Jgconfig*)jgconfig).KgDelay = atoi(pValue[20]);
    (*(Jgconfig*)jgconfig).GgDelay = atoi(pValue[21]);
    (*(Jgconfig*)jgconfig).firstJumpDelay = atoi(pValue[22]);
    (*(Jgconfig*)jgconfig).jumpDelay = atoi(pValue[23]);
    (*(Jgconfig*)jgconfig).endDelay = atoi(pValue[24]);

    return 0;
}

int callback2(void* counter, int nCount, char** pValue, char** pName)
{
    SchemeName.insert(SchemeName.end(), UTF8_TO_GBK(pValue[0]));
    (*((int*)counter))++;
    return 0;
}

int callback3(void* counter, int nCount, char** pValue, char** pName)
{
    FindSchemeName.insert(FindSchemeName.end(), UTF8_TO_GBK(pValue[0]));
    (*((int*)counter))++;
    return 0;
}

int callback4(void* namecode, int nCount, char** pValue, char** pName)
{
    *((int*)namecode) = atoi(pValue[0]);
    return 0;
}

int callback5(void* ImageSize, int nCount, char** pValue, char** pName)
{
    *((double*)ImageSize) = atof(pValue[0]);
    return 0;
}

int callback6(void* CamFilterTime, int nCount, char** pValue, char** pName)
{
    *((int*)CamFilterTime) = atoi(pValue[0]);
    return 0;
}

//栏目内容回调函数
int callback_schemecontent(void* schemecontent, int nCount, char** pValue, char** pName)
{
    //(*(SchemeContent*)schemecontent).SCHEME = UTF8_TO_GBK(pValue[0]);
    (*(SchemeContent*)schemecontent).CustomStr = UTF8_TO_GBK(pValue[1]);
    (*(SchemeContent*)schemecontent).CustomStr_2 = UTF8_TO_GBK(pValue[2]);
    (*(SchemeContent*)schemecontent).CustomStr_3 = UTF8_TO_GBK(pValue[3]);
    (*(SchemeContent*)schemecontent).CustomStr_4 = UTF8_TO_GBK(pValue[4]);
    (*(SchemeContent*)schemecontent).CustomStr_5 = UTF8_TO_GBK(pValue[5]);
    (*(SchemeContent*)schemecontent).CustomStr_6 = UTF8_TO_GBK(pValue[6]);
    (*(SchemeContent*)schemecontent).SCenabled = atoi(pValue[7]);
    (*(SchemeContent*)schemecontent).BZenabled = atoi(pValue[8]);
    (*(SchemeContent*)schemecontent).EWenabled = atoi(pValue[9]);
    (*(SchemeContent*)schemecontent).save_time = atoi(pValue[10]);
    (*(SchemeContent*)schemecontent).Savemonth = atoi(pValue[11]);
    (*(SchemeContent*)schemecontent).Saveyear = atoi(pValue[12]);



    return 0;
}

int callback_user(void* userinfo, int nCount, char** pValue, char** pName)
{
    (*(userconfig*)userinfo).USERname = UTF8_TO_GBK(pValue[0]);
    (*(userconfig*)userinfo).PenMa = atoi(pValue[1]);
    (*(userconfig*)userinfo).LiuShuixian = atoi(pValue[2]);
    (*(userconfig*)userinfo).Chufa = atoi(pValue[3]);
    (*(userconfig*)userinfo).FangZhen = atoi(pValue[4]);
    (*(userconfig*)userinfo).PeiFang = atoi(pValue[5]);
    (*(userconfig*)userinfo).xiangJi = atoi(pValue[6]);
    (*(userconfig*)userinfo).CDL = atoi(pValue[7]);
    (*(userconfig*)userinfo).YongHu = atoi(pValue[8]);
    (*(userconfig*)userinfo).password = UTF8_TO_GBK(pValue[9]);
    (*(userconfig*)userinfo).BianJi = atoi(pValue[10]);
    return 0;
}

int callback_user2(void* counter, int nCount, char** pValue, char** pName)
{
    Name.insert(Name.end(), UTF8_TO_GBK(pValue[0]));
    (*((int*)counter))++;
    return 0;
}

int callback_user3(void* counter, int nCount, char** pValue, char** pName)
{
    FindName.insert(FindName.end(), UTF8_TO_GBK(pValue[0]));
    (*((int*)counter))++;
    return 0;
}

// 数据库操作函数实现
bool ConnectDB()
{
    int rc = sqlite3_open(dir.c_str(), &db);
    if (rc != SQLITE_OK) {
        cout << "[Sqlite] Open DB Failed!, Detail:" << sqlite3_errmsg(db);
        db = nullptr;
        return false;
    }
    return true;
}

int Traverse()
{
    SchemeName.clear();
    int DBcounters = 0;
    string strSql = "select * from config";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback2, &DBcounters, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return DBcounters;
    }
    return DBcounters;
}

bool SelectDB(string str)
{
    string strSql = "select * from config where SCHEME='" + str + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback, &config, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool InsertDB(string schemeName)
{
    string insertSql = "insert into config(SCHEME,ExposureTime,TriggerDelay,Sharpness,rectX,rectY,rectW,rectH,rot,GapCount,KeepCount,GainValue,CodeIndex,DelayModel,DelayTime,DelayDistance,DCLength,FirstOCRSize,SecOCRSize,OutputLocationMin,OutputLocationMax,R,G,B,RGBTime,RGBMode) values('"
        + schemeName + "'" + "," + to_string(ExposureTime) + "," + to_string(TriggerDelay) + "," + to_string(Sharpness) + "," + to_string(rectX) + "," + to_string(rectY) + ","
        + to_string(rectW) + "," + to_string(rectH) + "," + to_string(rot) + "," + to_string(GapCount) + "," + to_string(KeepCount) + "," + to_string(GainValue)
        + "," + to_string(CodeIndex) + "," + to_string(DelayModel) + "," + to_string(DelayTime) + "," + to_string(DelayDistance) + "," + to_string(DCLength) + "," + to_string(FirstOCRSize)
        + "," + to_string(SecOCRSize) + "," + to_string(OutputLocationMin) + "," + to_string(OutputLocationMax) + "," + to_string(R) + "," + to_string(G) + "," + to_string(B) + "," + to_string(RGBTime) + "," + to_string(RGBMode) + ");";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(insertSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool DeleteDB(string str)
{
    string deleteSql = "delete from config where SCHEME ='" + str + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(deleteSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool AlterDB(string rstr)
{
    string updateSql = "update config set ExposureTime =" + to_string(ExposureTime) + ",TriggerDelay=" + to_string(TriggerDelay) + ",Sharpness=" + to_string(Sharpness) +
        ",rectX=" + to_string(rectX) + ",rectY=" + to_string(rectY) + ",rectW=" + to_string(rectW) + ",rectH=" + to_string(rectH)
        + ",rot=" + to_string(rot) + ",GapCount=" + to_string(GapCount) + ",KeepCount=" + to_string(KeepCount) + ",GainValue=" + to_string(GainValue) + ",CodeIndex=" + to_string(CodeIndex)
        + ",DelayModel=" + to_string(DelayModel) + ",DelayTime=" + to_string(DelayTime) + ",DelayDistance=" + to_string(DelayDistance) + ",DCLength=" + to_string(DCLength)
        + ",FirstOCRSize=" + to_string(FirstOCRSize) + ",SecOCRSize=" + to_string(SecOCRSize) + ",OutputLocationMin=" + to_string(OutputLocationMin) + ",OutputLocationMax=" + to_string(OutputLocationMax)
        + ",R=" + to_string(R) + ",G=" + to_string(G) + ",B=" + to_string(B) + ",RGBTime=" + to_string(RGBTime) + ",RGBMode=" + to_string(RGBMode) + " where SCHEME = '" + rstr + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}
//修改配方名称
bool AlterSchemeName(string pre_name, string altered_name)
{
    string updateSql = "update config set SCHEME='" + altered_name + "' where SCHEME = '" + pre_name + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return 0;
    }
    return 1;
}

bool SelectDB_Status()
{
    string strSql = "select * from RunningStatus where StatusList=0";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_status, &runningstatus, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool AlterDB_Status()
{
    string updateSql = "update RunningStatus set MaxThresholdAlermOpen =" + to_string(MaxThresholdAlermOpen) + ",MinThresholdAlermOpen=" + to_string(MinThresholdAlermOpen) + ",cameraAlarmOpen=" + to_string(cameraAlarmOpen) +
        ",markingOutOfAreaOpen=" + to_string(markingOutOfAreaOpen) + ",linkTXOpen=" + to_string(linkTXOpen) + ",linkBKBKOpen=" + to_string(linkBKBKOpen) + ",linkCameraOpen=" + to_string(linkCameraOpen) + " where StatusList = 0";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool SelectDB_Jgconfig()
{
    string strSql = "select * from Jgconfig where BMQzhijing";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_jgconfig, &jgconfig, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool AlterDB_Jgconfig()
{
    string updateSql = "update Jgconfig set BMQzhijing =" + to_string(jgconfig.BMQzhijing) + ",BMQmaichong=" + to_string(jgconfig.BMQmaichong) + ",GdFilterTime=" + to_string(jgconfig.GdFilterTime) +
        ",MinThresholdMode=" + to_string(jgconfig.MinThresholdMode) + ",MinTriggerTime=" + to_string(jgconfig.MinTriggerTime) + ",MinTriggerDistance=" + to_string(jgconfig.MinTriggerDistance) +
        ",DelayTriggerMode=" + to_string(jgconfig.DelayTriggerMode) + ",DelayTriggerTime=" + to_string(jgconfig.DelayTriggerTime) + ",DelayTriggerDistance=" + to_string(jgconfig.DelayTriggerDistance) +
        ",DelayTriggerModetwo=" + to_string(jgconfig.DelayTriggerModetwo) + ",DelayTriggerTimetwo=" + to_string(jgconfig.DelayTriggerTimetwo) + ",DelayTriggerDistancetwo=" + to_string(jgconfig.DelayTriggerDistancetwo) +
        ",Dbchoice=" + to_string(jgconfig.Dbchoice) + ",interpolationStep=" + to_string(jgconfig.interpolationStep) + ",scanW_mm=" + to_string(jgconfig.scanW_mm) + ",BMQdirection=" + to_string(jgconfig.BMQdirection) +
        ",FXDBirection=" + to_string(jgconfig.FXDBirection) + ",Dbmode=" + to_string(jgconfig.Dbmode) + ",JgFreq=" + to_string(jgconfig.JgFreq) + ",JgPower=" + to_string(jgconfig.JgPower) +
        ",KgDelay=" + to_string(jgconfig.KgDelay) + ",GgDelay=" + to_string(jgconfig.GgDelay) + ",firstJumpDelay=" + to_string(jgconfig.firstJumpDelay) +
        ",jumpDelay=" + to_string(jgconfig.jumpDelay) + ",endDelay=" + to_string(jgconfig.endDelay);

    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

int SelectSchName(string str)
{
    FindSchemeName.clear();
    string strSql = "select * from config";
    int Counter = 0;
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback3, &Counter, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return -1;
    }
    int NameCounter = 0;
    for (int i = 0; i < Counter; i++)
    {
        if (str == FindSchemeName[i])
        {
            //return 1;
            NameCounter++;
        }
    }
    return NameCounter;
}

int FindNameCode()
{
    string strSql = "select * from SchemeNameCode";
    int NameCode = 0;
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback4, &NameCode, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return 0;
    }
    return NameCode;
}

bool SaveNameCode(int code)
{
    string strSql = "delete from SchemeNameCode";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }

    string strSql2 = "insert into SchemeNameCode(NameCode) values(" + to_string(code) + ");";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

double FindImageSize()
{
    string strSql = "select * from ImageSize";
    double ImageSize = 0.1;
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback5, &ImageSize, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return 0;
    }
    return ImageSize;
}

bool SaveImageSize(double ImageSize)
{
    string strSql = "delete from ImageSize";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }

    string strSql2 = "insert into ImageSize(ImageSize) values(" + to_string(ImageSize) + ");";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

int FindCamFilterTime()
{
    string strSql = "select * from CamFilter";
    int CamFilterTime = 1;
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback6, &CamFilterTime, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return 0;
    }
    return CamFilterTime;
}

bool SaveCamFilterTime(int CamFilterTime)
{
    string strSql = "delete from CamFilter";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }

    string strSql2 = "insert into CamFilter(CamFilterTime) values(" + to_string(CamFilterTime) + ");";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql2.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool get_filelist_from_dir(std::string path, std::vector<std::string>& files)
{
    long long  hFile = 0;
    struct _finddata_t fileinfo;
    files.clear();
    if ((hFile = _findfirst(path.c_str(), &fileinfo)) != -1)
    {
        do
        {
            if (!(fileinfo.attrib & _A_SUBDIR))
            {
                files.push_back(fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
        return true;
    }
    else
    {
        return false;
    }
}

vector<string> getImageList(std::string file_path, std::string suffix)
{
    string search_path = file_path + suffix;
    vector<string> file_list;
    if (!get_filelist_from_dir(search_path, file_list))
    {
        // 可以记录日志
    }
    vector<string> image_path_list;
    for (size_t i = 0; i < file_list.size(); i++)
    {
        image_path_list.push_back(file_path + file_list[i]);
    }
    return image_path_list;
}

bool SelectSchemeContent(string schemeName)
{
    string strSql = "select * from SchemeContent where SchemeName='" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_schemecontent, &schemecontent, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool InsertSchemeContent(string schemeName)
{
    string insertSql = "insert into SchemeContent(SchemeName,CustomStr,CustomStr_2,CustomStr_3,CustomStr_4,CustomStr_5,CustomStr_6) values('"
        + schemeName + "','" + CustomStr + "','" + CustomStr_2 + "','" + CustomStr_3 + "','" + CustomStr_4 + "','" + CustomStr_5 + "','" + CustomStr_6 + "');";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(insertSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool DeleteSchemeContent(string schemeName)
{
    string deleteSql = "delete from SchemeContent where SchemeName ='" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(deleteSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool AlterSchemeContent(string schemeName)
{
    string updateSql = "update SchemeContent set CustomStr ='" + CustomStr + "',CustomStr_2='" + CustomStr_2 + "',CustomStr_3='" + CustomStr_3 +
        "',CustomStr_4='" + CustomStr_4 + "',CustomStr_5='" + CustomStr_5 + "',CustomStr_6='" + CustomStr_6 + "',SCenabled='" + to_string(SCenabled) + "',BZenabled='" + to_string(BZenabled) + "',EWenabled='" + to_string(EWenabled) + "',save_time='" + to_string(save_time) + "',Savemonth='" + to_string(Savemonth) + "',Saveyear='" + to_string(Saveyear) + "' where SchemeName = '" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

int TraverseUser()
{
    Name.clear();
    int DBcounters = 0;
    string strSql = "select * from User";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_user2, &DBcounters, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return DBcounters;
    }
    return DBcounters;
}

int SelectSchUserName(string str)
{
    FindName.clear();
    string strSql = "select * from User";
    int Counter = 0;
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_user3, &Counter, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return 0;
    }
    for (int i = 0; i < Counter; i++)
    {
        if (str == FindName[i])
        {
            return 1;
        }
    }
    return 2;
}

bool SelectUser(string schemeName)
{
    string strSql = "select * from User where USERname='" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(strSql.c_str())).c_str(), callback_user, &userinfo, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool InsertUser(string schemeName)
{
    string insertSql = "insert into User(USERname,PenMa,LiuShuixian,Chufa,FangZhen,PeiFang,XiangJi,CDL,YongHu,password,BianJi) values('"
        + schemeName + "','" + to_string(PenMa) + "','" + to_string(LiuShuixian) + "','" + to_string(Chufa) + "','" + to_string(FangZhen) + "','"
        + to_string(PeiFang) + "','" + to_string(xiangJi) + "','" + to_string(CDL) + "','" + to_string(YongHu) + "','" + password + "','" + to_string(BianJi) + "');";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(insertSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool DeleteUser(string schemeName)
{
    string deleteSql = "delete from User where USERname ='" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(deleteSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool AlterUser(string schemeName)
{
    string updateSql = "update User set PenMa ='" + to_string(PenMa) + "',LiuShuixian='" + to_string(LiuShuixian) + "',Chufa='" + to_string(Chufa) +
        "',FangZhen='" + to_string(FangZhen) + "',PeiFang='" + to_string(PeiFang) + "',XiangJi='" + to_string(xiangJi) + "',CDL='" + to_string(CDL) + "',YongHu='" + to_string(YongHu) + "',BianJi='" + to_string(BianJi) + "' where USERname = '" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool AlterPassword(string schemeName, string newpassword)
{
    string updateSql = "update User set password ='" + newpassword + "' where USERname = '" + schemeName + "'";
    nResult = sqlite3_exec(db, (GBK_TO_UTF8(updateSql.c_str())).c_str(), NULL, NULL, &errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        cout << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}