/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2018 A. Stebich (librecad@mail.lordofbikes.de)
** Copyright (C) 2018 Simon Wells <simonrwells@gmail.com>
** Copyright (C) 2015-2016 ravas (github.com/r-a-v-a-s)
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!
**
**********************************************************************/
#include <clocale>
#include "main.h"

#include <QDebug>
#include <QApplication>
#include <QSplashScreen>
#include <QSettings>
#include <QMessageBox>
#include <QFileInfo>
#include <QDesktopWidget>
#include "rs_fontlist.h"
#include "rs_patternlist.h"
#include "rs_settings.h"
#include "rs_system.h"
#include "qg_dlginitial.h"

#include "lc_application.h"
#include "qc_applicationwindow.h"
#include "rs_debug.h"

#include "console_dxf2pdf.h"
#include <QSharedMemory>
#include "OCRdemo/DLL.h"

#include "BinaryDataListener.h"



#include "PixelCorrector.h"
/**
 * Main. Creates Application window.
 */








QDebug operator<<(QDebug debug, const Eigen::Matrix3d& matrix)
{
    debug << "\n";
    for (int i = 0; i < 3; ++i) {
        debug << "[";
        for (int j = 0; j < 3; ++j) {
            debug << QString("%1 ").arg(matrix(i, j), 0, 'f', 2);
        }
        debug << "]\n";
    }
    return debug;
}

int main(int argc, char** argv)

{
    
    // 确保中文显示正常
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
#endif

    // 1. 初始化输入数据
    QVector<QPointF> modelCoords = {
        QPointF(8191, 57343),   // 上左
        QPointF(32767, 57343),  // 上中
        QPointF(57343, 57343),  // 上右
        QPointF(8191, 32767),   // 中左
        QPointF(32767, 32767),  // 中中
        QPointF(57343, 32767),  // 中右
        QPointF(8191, 8191),    // 下左
        QPointF(32767, 8191),   // 下中
        QPointF(57343, 8191)    // 下右
    };

    QVector<QPointF> modelMmCoords = {
        QPointF(-47.30, 47.30),  // 上左
        QPointF(0, 47.30),       // 上中
        QPointF(47.30, 47.30),   // 上右
        QPointF(-47.30, 0),      // 中左
        QPointF(0, 0),           // 中中
        QPointF(47.30, 0),       // 中右
        QPointF(-47.30, -47.30), // 下左
        QPointF(0, -47.30),      // 下中
        QPointF(47.30, -47.30)   // 下右
    };

    QVector<QPointF> pixelCoords = modelCoords;  // 实际像素坐标与模型一致

    QVector<QPointF> measuredMmCoords = {
        QPointF(-46.02, 48.48),  // 上左
        QPointF(0, 47.30),       // 上中
        QPointF(46.02, 48.48),   // 上右
        QPointF(-47.80, 0),      // 中左
        QPointF(0, 0),           // 中中
        QPointF(47.80, 0),       // 中右
        QPointF(-46.02, -48.48), // 下左
        QPointF(0, -47.30),      // 下中
        QPointF(46.02, -48.48)   // 下右
    };

    try {
        // 2. 创建校正器实例
        PixelCorrector corrector(modelCoords, modelMmCoords, pixelCoords, measuredMmCoords);

        // 3. 显示网格数据（调试用）
        qDebug() << QString::fromLocal8Bit("误差网格 (X坐标):");
        qDebug() << corrector.deltaX();
        qDebug() << QString::fromLocal8Bit("\n误差网格 (Y坐标):");
        qDebug() << corrector.deltaY();
        // 输出 grid_x
        std::cout << "grid_x: " << corrector.grid_x.transpose() << std::endl;  // 转置后输出（1x3 形式）

        // 输出 grid_y
        std::cout << "grid_y: " << corrector.grid_y.transpose() << std::endl;


        // 4. 测试几个点的补偿效果
        QVector<QPointF> testPoints = {

            QPointF(10, 10),
            QPointF(1000, 1000),
            QPointF(10000, 10000),
            QPointF(40000, 40000),
            QPointF(50000, 50000),
            QPointF(10000, 40000),
            QPointF(7000, 43000),
            QPointF(7000, 47000),
            QPointF(7000, 48000),
            QPointF(7000, 49000),
            QPointF(7000, 50000),
            QPointF(7000, 51000),
            QPointF(7000, 52000),
            QPointF(7000, 53000),
            QPointF(7000, 54000),
            QPointF(7000, 55000),

            QPointF(45000, 49000),
            QPointF(12000, 49000),
            QPointF(12000, 13500),
            QPointF(48000, 11000),
            QPointF(32777, 49000),
            QPointF(32777, 13000),
            QPointF(12000, 38666),
            QPointF(48000, 38666),


            QPointF(57161, 9368),
            QPointF(9368, 57161),
            QPointF(8000, 50000),
            QPointF(8000, 51000),
            QPointF(8000, 52000),
            QPointF(8000, 53000),
            QPointF(8000, 54000),
            QPointF(65535, 0),
            QPointF(0, 0)
        };

        qDebug() << QString::fromLocal8Bit("\n测试点补偿结果:");
        for (const auto& pt : testPoints) {
            QPointF compensated = corrector.compensatePoint(pt.x(), pt.y());
            qDebug() << QString::fromLocal8Bit("目标点(%1, %2) -> 补偿后(%3, %4)")
                .arg(pt.x()).arg(pt.y())
                .arg(compensated.x(), 0, 'f', 2)
                .arg(compensated.y(), 0, 'f', 2);
        }
    }
    catch (const std::exception& e) {
        qCritical() << "程序错误:" << e.what();
        return 1;
    }
    

    qDebug() << "当前工作目录：" << QDir::currentPath();
    // 注册 cv::Mat 类型
    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<cv::Rect>("cv::Rect");

   
    static QSharedMemory* singleApp = new QSharedMemory("SingleApp");//创建“SingleApp”的共享内存块
    if (!singleApp->create(1))//创建失败，说明已经有一个程序运行，
    {
        QMessageBox::information(NULL, ("程序重复启动 "), ("程序正在运行，请勿重复启动！ "));//弹出提示框 注意：该提示应该在 qApp->quit();之前，否则提示框将会一闪而过
        qApp->quit();//退出当前程序
        return -1;
    }



    QDateTime time = QDateTime::currentDateTime();
    QDateTime currentTime = QDateTime::currentDateTime(); //记录当前时间




   
    QT_REQUIRE_VERSION(argc, argv, "5.2.1");

    /* Check first two arguments in order to decide if we want to run librecad
     * as console dxf2pdf tool. On Linux we can create a link to librecad
     * executable and  name it dxf2pdf. So, we can run either:
     *     librecad dxf2pdf [options] ...
     * or just:
     *     dxf2pdf [options] ...
     */


    /*for (int i = 0; i < qMin(argc, 2); i++) {
        QString arg(argv[i]);
        if (i == 0) {
            arg = QFileInfo(QFile::decodeName(argv[i])).baseName();
        }
        if (arg.compare("dxf2pdf") == 0) {
            return console_dxf2pdf(argc, argv);
        }
    }*/

    RS_DEBUG->setLevel(RS_Debug::D_WARNING);


    //初始化应用程序
    LC_Application app(argc, argv);
    QCoreApplication::setOrganizationName("YL_LightB");
    QCoreApplication::setApplicationName ("YL_LightB");
    QCoreApplication::setApplicationVersion(XSTR(LC_VERSION));




  




    QString strStyleSheet = "";
    QFile file(":/QSS/Resources/Aqua.qss");
    if (file.open(QFile::ReadOnly))
    {
        strStyleSheet = file.readAll();
    }
    app.setStyleSheet(strStyleSheet);




#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    QGuiApplication::setDesktopFileName("librecad.desktop");
#endif

    QSettings settings;

    bool first_load = settings.value("Startup/FirstLoad", 1).toBool();
    //检查是否是首次运行（用于显示初始配置对话框）


    const QString lpDebugSwitch0("-d"),lpDebugSwitch1("--debug") ;
    const QString help0("-h"), help1("--help");
    bool allowOptions=true;
    QList<int> argClean;
    for (int i=0; i<argc; i++)
    {
        QString argstr(argv[i]);
        if(allowOptions&&QString::compare("--", argstr)==0)
        {
            allowOptions=false;
            continue;
        }
        if (allowOptions && (help0.compare(argstr, Qt::CaseInsensitive)==0 ||
                             help1.compare(argstr, Qt::CaseInsensitive)==0 ))
        {
            qDebug()<<"Usage: librecad [command] <options> <dxf file>";
            qDebug()<<"";
            qDebug()<<"Commands:";
            qDebug()<<"";
            qDebug()<<"  dxf2pdf\tRun librecad as console dxf2pdf tool. Use -h for help.";
            qDebug()<<"";
            qDebug()<<"Options:";
            qDebug()<<"";
            qDebug()<<"  -h, --help\tdisplay this message";
            qDebug()<<"  -d, --debug <level>";
            qDebug()<<"";
            RS_DEBUG->print( RS_Debug::D_NOTHING, "possible debug levels:");
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Nothing", RS_Debug::D_NOTHING);
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Critical", RS_Debug::D_CRITICAL);
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Error", RS_Debug::D_ERROR);
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Warning", RS_Debug::D_WARNING);
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Notice", RS_Debug::D_NOTICE);
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Informational", RS_Debug::D_INFORMATIONAL);
            RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Debugging", RS_Debug::D_DEBUGGING);
            exit(0);
        }
        if ( allowOptions&& (argstr.startsWith(lpDebugSwitch0, Qt::CaseInsensitive) ||
                             argstr.startsWith(lpDebugSwitch1, Qt::CaseInsensitive) ))
        {
            argClean<<i;

            // to control the level of debugging output use --debug with level 0-6, e.g. --debug3
            // for a list of debug levels use --debug?
            // if no level follows, the debugging level is set
            argstr.remove(QRegExp("^"+lpDebugSwitch0));
            argstr.remove(QRegExp("^"+lpDebugSwitch1));
            char level;
            if(argstr.size()==0)
            {
                if(i+1<argc)
                {
                    if(QRegExp("\\d*").exactMatch(argv[i+1]))
                    {
                        ++i;
                        qDebug()<<"reading "<<argv[i]<<" as debugging level";
                        level=argv[i][0];
                        argClean<<i;
                    }
                    else
                        level='3';
                }
                else
                    level='3'; //default to D_WARNING
            }
            else
                level=argstr.toStdString()[0];

            switch(level)
            {
            case '?' :
                RS_DEBUG->print( RS_Debug::D_NOTHING, "possible debug levels:");
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Nothing", RS_Debug::D_NOTHING);
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Critical", RS_Debug::D_CRITICAL);
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Error", RS_Debug::D_ERROR);
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Warning", RS_Debug::D_WARNING);
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Notice", RS_Debug::D_NOTICE);
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Informational", RS_Debug::D_INFORMATIONAL);
                RS_DEBUG->print( RS_Debug::D_NOTHING, "    %d Debugging", RS_Debug::D_DEBUGGING);
                return 0;

            case '0' + RS_Debug::D_NOTHING :
                RS_DEBUG->setLevel( RS_Debug::D_NOTHING);
                break;

            case '0' + RS_Debug::D_CRITICAL :
                RS_DEBUG->setLevel( RS_Debug::D_CRITICAL);
                break;

            case '0' + RS_Debug::D_ERROR :
                RS_DEBUG->setLevel( RS_Debug::D_ERROR);
                break;

            case '0' + RS_Debug::D_WARNING :
                RS_DEBUG->setLevel( RS_Debug::D_WARNING);
                break;

            case '0' + RS_Debug::D_NOTICE :
                RS_DEBUG->setLevel( RS_Debug::D_NOTICE);
                break;

            case '0' + RS_Debug::D_INFORMATIONAL :
                RS_DEBUG->setLevel( RS_Debug::D_INFORMATIONAL);
                break;

            case '0' + RS_Debug::D_DEBUGGING :
                RS_DEBUG->setLevel( RS_Debug::D_DEBUGGING);
                break;

            default :
                RS_DEBUG->setLevel(RS_Debug::D_DEBUGGING);
                break;
            }
        }
    }
    RS_DEBUG->print("param 0: %s", argv[0]);

    RS_SETTINGS->init(app.organizationName(), app.applicationName());
   
    RS_SYSTEM->init( app.applicationName(), app.applicationVersion(), XSTR(QC_APPDIR), argv[0]);

    // parse command line arguments that might not need a launched program:
    QStringList fileList = handleArgs(argc, argv, argClean);

    QString unit = settings.value("Defaults/Unit", "Invalid").toString();

    // show initial config dialog:
    if (first_load)
    {
        RS_DEBUG->print("main: show initial config dialog..");
        QG_DlgInitial di(nullptr);
        QPixmap pxm(":/PIC/Resources/PICs/logo.png");

        // 旋转图片：顺时针旋转90度
        QTransform transform;
        transform.rotate(90);
        QPixmap rotatedPxm = pxm.transformed(transform, Qt::SmoothTransformation);

        di.setPixmap(rotatedPxm);  // 设置旋转后的图片
        if (di.exec())
        {
            RS_SETTINGS->beginGroup("/Defaults");
            unit = RS_SETTINGS->readEntry("/Unit", "None");
            RS_SETTINGS->endGroup();
        }
        RS_DEBUG->print("main: show initial config dialog: OK");
    }


    //显示启动画面
    auto splash = new QSplashScreen;

    bool show_splash = settings.value("Startup/ShowSplash", 1).toBool();

    if (show_splash)
    {
        QPixmap pixmap(":/main/splash_librecad.png");
        splash->setPixmap(pixmap);
        splash->setAttribute(Qt::WA_DeleteOnClose);
        splash->show();
        splash->showMessage(QObject::tr("Loading.."),
                            Qt::AlignRight|Qt::AlignBottom, Qt::black);
        app.processEvents();
        RS_DEBUG->print("main: splashscreen: OK");
    }


    // 初始化字体列表
    RS_DEBUG->print("main: init fontlist..");
    RS_FONTLIST->init();
    RS_DEBUG->print("main: init fontlist: OK");

    RS_DEBUG->print("main: init patternlist..");
    RS_PATTERNLIST->init();
    RS_DEBUG->print("main: init patternlist: OK");

    RS_DEBUG->print("main: loading translation..");

    settings.beginGroup("Appearance");
    QString lang = settings.value("Language", "en").toString();
    QString langCmd = settings.value("LanguageCmd", "en").toString();
    settings.endGroup();



    // 加载翻译文件
    RS_SYSTEM->loadTranslation(lang, langCmd);
    RS_DEBUG->print("main: loading translation: OK");

    RS_DEBUG->print("main: creating main window..");




    // 创建主窗口
    QC_ApplicationWindow appWin;   //继承自QMainWindow

   
#ifdef Q_OS_MAC
    app.installEventFilter(&appWin);
#endif
    RS_DEBUG->print("main: setting caption");
    appWin.setWindowTitle(app.applicationName());

    RS_DEBUG->print("main: show main window");

    settings.beginGroup("Geometry");
    int windowWidth = settings.value("WindowWidth", 1020).toInt();
    int windowHeight = settings.value("WindowHeight",720).toInt();
   
    settings.endGroup();

    settings.beginGroup("Defaults");
    if( !settings.contains("UseQtFileOpenDialog")) {
#ifdef Q_OS_LINUX
        // on Linux don't use native file dialog
        // because of case insensitive filters (issue #791)
        settings.setValue("UseQtFileOpenDialog", QVariant(1));
#else
        settings.setValue("UseQtFileOpenDialog", QVariant(0));
#endif
    }
    settings.endGroup();

    if (!first_load) {

        appWin.resize(windowWidth, windowHeight);
    }

    bool maximize = settings.value("Startup/Maximize", 0).toBool();

    if (maximize || first_load) {
       // appWin.showMaximized();
        appWin.resize(windowWidth, windowHeight);
        appWin.show();
      
    }
    else {
      
        appWin.show(); //主窗口
        
    }


    RS_DEBUG->print("main: set focus");
    appWin.setFocus();
    RS_DEBUG->print("main: creating main window: OK");

    if (show_splash)
    {
        RS_DEBUG->print("main: updating splash");
        splash->raise();
        splash->showMessage(QObject::tr("Loading..."),
                Qt::AlignRight|Qt::AlignBottom, Qt::black);
        RS_DEBUG->print("main: processing events");
        qApp->processEvents();
        RS_DEBUG->print("main: updating splash: OK");
    }

    // Set LC_NUMERIC so that entering numeric values uses . as the decimal separator
    setlocale(LC_NUMERIC, "C");

    RS_DEBUG->print("main: loading files..");
#ifdef Q_OS_MAC
    // get the file list from LC_Application
    fileList << app.fileList();
#endif
    bool files_loaded = false;
    for (QStringList::Iterator it = fileList.begin(); it != fileList.end(); ++it )
    {
        if (show_splash)
        {
            splash->showMessage(QObject::tr("Loading File %1..")
                    .arg(QDir::toNativeSeparators(*it)),
            Qt::AlignRight|Qt::AlignBottom, Qt::black);
            qApp->processEvents();
        }
        appWin.slotFileOpen(*it);
        files_loaded = true;
    }
    RS_DEBUG->print("main: loading files: OK");

    if (!files_loaded)
    {
        QSettings settings;
        QStringList recentFiles = settings.value("RecentFiles").toStringList();

        if (!recentFiles.isEmpty()) {
            QString lastFile = recentFiles.first();

            if (QFile::exists(lastFile)) {
                qDebug() << "自动打开最近的文件:" << lastFile;

                if (show_splash) {
                    splash->showMessage(QObject::tr("Opening recent file: %1..")
                        .arg(QDir::toNativeSeparators(lastFile)),
                        Qt::AlignRight | Qt::AlignBottom, Qt::black);
                    qApp->processEvents();
                }

                // 直接调用 slotFileOpen
                appWin.slotFileOpen(lastFile, RS2::FormatUnknown);
                files_loaded = true;

            }
            else {
                // 文件不存在，清理列表
                recentFiles.removeAll(lastFile);
                settings.setValue("RecentFiles", recentFiles);

                qDebug() << "最近文件不存在，创建新文档";
                appWin.slotFileNewNew();
            }
        }
        else {
            qDebug() << "没有最近文件，创建新文档";
            appWin.slotFileNewNew();
        }
    }

    if (show_splash)
        splash->finish(&appWin);
    else
        delete splash;

    if (first_load)
        settings.setValue("Startup/FirstLoad", 0);

    RS_DEBUG->print("main: entering Qt event loop");

    int return_code = app.exec();

    RS_DEBUG->print("main: exited Qt event loop");


    return return_code;
}


/**
 * Handles command line arguments that might not require a GUI.
 *
 * @return list of files to load on startup.
 */
QStringList handleArgs(int argc, char** argv, const QList<int>& argClean)
{
    RS_DEBUG->print("main: handling args..");
    QStringList ret;

    bool doexit = false;

    for (int i=1; i<argc; i++)
    {
        if(argClean.indexOf(i)>=0) continue;
        if (!QString(argv[i]).startsWith("-"))
        {
            QString fname = QDir::toNativeSeparators(
            QFileInfo(QFile::decodeName(argv[i])).absoluteFilePath());
            ret.append(fname);
        }
        else if (QString(argv[i])=="--exit")
        {
            doexit = true;
        }
    }
    if (doexit)
    {
        exit(0);
    }
    RS_DEBUG->print("main: handling args: OK");
    return ret;
}

