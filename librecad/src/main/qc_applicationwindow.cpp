/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
** 
** Copyright (C) 2019 Shawn Curry (noneyabiz@mail.wasent.cz)
** Copyright (C) 2018 Simon Wells (simonrwells@gmail.com)
** Copyright (C) 2015-2016 ravas (github.com/r-a-v-a-s)
** Copyright (C) 2015 A. Stebich (librecad@mail.lordofbikes.de)
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

// Changes: https://github.com/LibreCAD/LibreCAD/commits/master/librecad/src/main/qc_applicationwindow.cpp

#include "qc_applicationwindow.h"

#include <QStatusBar>
#include <QMenuBar>
#include <QDockWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QSplitter>
#include <QMdiArea>
#include <QPluginLoader>
#include <QImageWriter>
#include <QtSvg>
#include <QStyleFactory>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include <QRegExp>
#include <QSysInfo>

#include "main.h"

#include "rs_actionprintpreview.h"
#include "rs_settings.h"
#include "rs_staticgraphicview.h"
#include "rs_system.h"
#include "rs_actionlibraryinsert.h"
#include "rs_painterqt.h"
#include "rs_selection.h"
#include "rs_document.h"

#include "lc_centralwidget.h"
#include "qc_mdiwindow.h"
#include "qg_graphicview.h"

#include "lc_actionfactory.h"
#include "qg_actionhandler.h"

#include "lc_widgetfactory.h"
#include "qg_snaptoolbar.h"
#include "qg_blockwidget.h"
#include "qg_layerwidget.h"
#include "qg_librarywidget.h"
#include "qg_commandwidget.h"
#include "qg_pentoolbar.h"

#include "qg_coordinatewidget.h"
#include "qg_selectionwidget.h"
#include "qg_activelayername.h"
#include "qg_mousewidget.h"
#include "twostackedlabels.h"

#include "qg_recentfiles.h"
#include "qg_dlgimageoptions.h"
#include "qg_filedialog.h"
#include "qg_exitdialog.h"

#include "rs_dialogfactory.h"
#include "qc_dialogfactory.h"
#include "doc_plugin_interface.h"
#include "qc_plugininterface.h"
#include "rs_commands.h"

#include "lc_simpletests.h"
#include "rs_debug.h"

#include "lc_widgetoptionsdialog.h"
#include "comboboxoption.h"

#include "lc_printing.h"
#include "actionlist.h"
#include "widgetcreator.h"
#include "lc_actiongroupmanager.h"
#include "linklist.h"
#include "colorwizard.h"
#include "lc_penwizard.h"
#include "textfileviewer.h"
#include "lc_undosection.h"

#include <boost/version.hpp>
#include<ui_QC_ApplicationWindow.h>



#include<QInputDialog>
#include <QDesktopServices>
#include<QMouseEvent>
#include<QPainter>
#include<QByteArray>
#include<QStorageInfo>
#include <QDialogButtonBox>

#include <direct.h>


QC_ApplicationWindow* QC_ApplicationWindow::appWindow = nullptr;

//相机采集回调函数
void CSampleCaptureEventHandler::DoOnImageCaptured(CImageDataPointer& objImageDataPointer, void* pUserParam)
{
  
    if (GX_FRAME_STATUS_SUCCESS == objImageDataPointer->GetStatus())
    {
        void* pRGB24Buffer = NULL;
        //假设原始数据是BayerRG8图像
        
       // pRGB24Buffer = objImageDataPointer->GetBuffer();
        pRGB24Buffer = objImageDataPointer->ConvertToRGB24(GX_BIT_0_7, GX_RAW2RGB_NEIGHBOUR, true);
        cv::Mat test, dst;
        test.create(objImageDataPointer->GetHeight(), objImageDataPointer->GetWidth(), CV_8UC3);
        memcpy(test.data, pRGB24Buffer, objImageDataPointer->GetPayloadSize()*3);
       
        flip(test, dst, 0);//上下翻转
        dst.copyTo(image);
        //cv::Mat binary; 
        //double threshold_value = 80; // 可以调整的阈值 
        //cv::threshold(dst, binary, threshold_value, 255, cv::THRESH_BINARY); // 二值化
        //binary.copyTo(image);
        pdemo->objImageDataPointer = objImageDataPointer;
        pdemo->resizeimage();
    }
}
//相机掉线回调函数
void CSampleDeivceOfflineEventHandler::DoOnDeviceOfflineEvent(void* pUserParam)
{
    pdemo->CamError();
}


// </ocrdemo__________________________________________^^^^^^^^^^^^^^^^^^^_______________________>


#ifndef QC_APP_ICON
# define QC_APP_ICON ":/main/librecad.png"
#endif
#ifndef QC_ABOUT_ICON
# define QC_ABOUT_ICON ":/main/intro_librecad.png"
#endif

/*	- Window Title Bar Extra (character) Size.
 *	- Notes: Extra characters appearing in the windows title bar
 *	  are " - [", ... "]" (5), and sometimes "Print preview of " (17).
 *	*/
#define WTB_EXTRA_SIZE        (5 + 17)

/*	Window Title Bar Maximum Size.
 *	Notes: On Windows XP, this is 79.
 *	*/
#define WTB_MAX_SIZE        79


 





/**
 * Constructor. Initializes the app.
 */



//libreCAD 主窗口类的构造函数
QC_ApplicationWindow::QC_ApplicationWindow()
    : ui(new Ui::QC_ApplicationWindow),
    ag_manager(new LC_ActionGroupManager(this))   // 动作组管理器
   
    , autosaveTimer(nullptr)                        // 自动保存定时器
    , actionHandler(new QG_ActionHandler(this))     // 动作处理器
    , current_subwindow(nullptr)                    // 当前子窗口
    , pen_wiz(new LC_PenWizard(QObject::tr("Pen Wizard"), this))// 笔属性向导
{
    

    if (!ConnectDB())
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, tr("数据库连接失败!"), tr("请检查数据库文件是否存在或损坏"), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(tr("确定 "));
        msgBoxs->show();
    }

    ui->setupUi(this);
    // 将图表添加到graphicsView
    QVBoxLayout* layout1 = new QVBoxLayout(ui->graphicsView);
    layout1->setContentsMargins(0, 0, 0, 0);
    layout1->addWidget(chart);
    ui->graphicsView->setLayout(layout1);
 
    serialmanager.setWindowModality(Qt::ApplicationModal);
    viewer.setWindowModality(Qt::ApplicationModal);
    guide.setWindowModality(Qt::ApplicationModal);
    setting.setWindowModality(Qt::ApplicationModal);
    xjadmin.setWindowModality(Qt::ApplicationModal);
    jgadmin.setWindowModality(Qt::ApplicationModal);
    addscheme.setWindowModality(Qt::ApplicationModal);
    alterscheme.setWindowModality(Qt::ApplicationModal);
    loggerView.setWindowModality(Qt::ApplicationModal);

    Logger::write("***********************程序开始*************************");

    OCRT->moveToThread(T);
    T->start();//触发线程开始执行
    connect(OCRT, &OCRruning::running, OCRT, &OCRruning::getocr);
    QObject::connect(&manager, &DeletionManager::deletionCompleted, [this](bool success) {
        if (success) {
            Logger::writeError("存储空间不足，删除文件夹: " + std::string(manager.OldestFolderPath.toLocal8Bit()));
        }
        else {
            Logger::writeError("存储空间不足，删除文件夹失败! ");
        }
        });

    //创建线程共用的互斥锁
    m_mutex = new QMutex;
    OCRT->setMutex(m_mutex);
   
 
  
   
    //上下左右平移
    connect(ui->moveUpBtn, &QToolButton::clicked, this, &QC_ApplicationWindow::onMoveUpButtonClicked);
    connect(ui->moveDownBtn, &QToolButton::clicked, this, &QC_ApplicationWindow::onMoveDownButtonClicked);
    connect(ui->moveLeftBtn, &QToolButton::clicked, this, &QC_ApplicationWindow::onMoveLeftButtonClicked);
    connect(ui->moveRighBtn, &QToolButton::clicked, this, &QC_ApplicationWindow::onMoveRightButtonClicked);
    connect(ui->moveToPosition, &QToolButton::clicked, this, &QC_ApplicationWindow::onMoveToPositionButtonClicked);
    connect(ui->moveDownBtn_2, &QToolButton::clicked, this, [=] {
        if (!getMDIWindow()) return;
        RS_GraphicView* graphicView = getGraphicView();
        RS_Document* document = getDocument();
        if (!graphicView || !document) return;
            // 计算选中实体的中心点
        calculateSelectionBounds(document);

        SetROISimple( mtexttotalWidth, mtexttotalHeight, mtextlowerLeftx, mtextlowerLefty);
    });
    connect(ui->moveDownBtn_3, &QToolButton::clicked, this, [=] {
        mtextlowerLeftx = 0;
        mtextlowerLefty = 0;
        mtexttotalWidth = ImageWidth;
        mtexttotalHeight = ImageHeight;
        SetROISimple(mtexttotalWidth, mtexttotalHeight, mtextlowerLeftx, mtextlowerLefty);
        });
    //主程序退出按钮
    connect(ui->EXIT, &QPushButton::clicked, this, &QC_ApplicationWindow::slotFileQuit);

    //主程序最小化
    connect(ui->MIN, &QPushButton::clicked, this, [=] {
        this->setWindowState(Qt::WindowMinimized);
    });
    connect(this, &QC_ApplicationWindow::camlog, this, [=] {
        Logger::writeComm("拍照!");
    });
    connect(this, &QC_ApplicationWindow::resizeimage, this, &QC_ApplicationWindow::processImageAndControls);
  
    // 第一个comboBox连接
    connect(ui->comboBox_2,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        [=](int index) {
            CodeIndex = index;  // 使用传递的index参数而不是再次获取
            FH = ui->comboBox_2->currentText();
            if (IsSchemeComboBoxcode) {
                IsSchemeComboBoxcode = false;
            }
            else {
                QString schemeName = ui->comboBox->currentText();
                bool result = AlterDB(schemeName.toStdString());
                // 建议添加错误处理
                if (!result) {
                    qWarning() << "Failed to alter database for scheme:" << schemeName;
                }
            }
        });

   
    listener->start(); // 正确捕获listener对象
    connect(listener, &BinaryDataListener::dataReceived, this, &QC_ApplicationWindow::processBinaryData);
 
   
    connect(ui->zdybutton, &QPushButton::clicked,this, &QC_ApplicationWindow::CustomModeButtonClicked);
    connect(ui->zdybutton_3, &QPushButton::clicked, this, &QC_ApplicationWindow::CustomModeButtonClicked);
    connect(ui->zdybutton_2, &QPushButton::clicked,this, &QC_ApplicationWindow::clearCustomFields);
  
    //OCR结果后续显示
    connect(OCRT, &OCRruning::ocrend, this,&QC_ApplicationWindow::showOCRResults);
 
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &QC_ApplicationWindow::onTabWidgetPageChanged);

    connect(ui->toolButton, &QPushButton::clicked, this, &QC_ApplicationWindow::CamerButton);
    connect(ui->toolButton_2, &QPushButton::clicked, this, &QC_ApplicationWindow::Simulate);
    connect(ui->toolButton_3, &QPushButton::clicked, this, [=] {
        // 获取当前索引
        if (!model) {
            TriggerLine0();
        }
        int currentIndex = ui->stackedWidget_3->currentIndex();

        // 切换索引：0→1，1→0
        int newIndex = (currentIndex == 0) ? 1 : 0;
        // 设置新索引
        ui->stackedWidget_3->setCurrentIndex(newIndex);
        });

    connect(ui->toolButton_4, &QPushButton::clicked, this, &QC_ApplicationWindow::OnlyOcr);
    connect(ui->toolButton_5, &QPushButton::clicked, this, &QC_ApplicationWindow::ViewRecord);
    connect(ui->toolButton_6, &QPushButton::clicked, this, [=] {

        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_4->setCurrentIndex(1);
        });
    connect(ui->toolButton_7, &QPushButton::clicked, this, &QC_ApplicationWindow::ShowSetting);
    connect(ui->toolButton_33, &QPushButton::clicked, this, &QC_ApplicationWindow::ShowJgadmain);
    connect(ui->toolButton_8, &QPushButton::clicked, this, &QC_ApplicationWindow::RateClear);
    connect(ui->toolButton_9, &QPushButton::clicked, this, [=] {
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_4->setCurrentIndex(0);
        });

    connect(ui->toolButton_11, &QPushButton::clicked, this, [=] {
        addscheme.SetAddScheme(LocationScale);
        addscheme.show();
        addscheme.move(QApplication::desktop()->screen()->rect().center() - addscheme.rect().center());
        });

    connect(ui->toolButton_14, &QPushButton::clicked, this, [=] {
      /*  if (ui->comboBox->currentIndex() != 0)
        {*/
            OpenAlterScheme();
      /*  }
        else
        {
            QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("未选择配方 "), QString::fromLocal8Bit("请先选择对应配方! "), QMessageBox::Ok);
            msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBoxs->show();
        }*/
        });

    /*******************************************************************************新建配方**************************************************************************************/
    connect(&addscheme, &AddScheme::CheckSchemeOverlap, this, [=] {
        //判断方案名是否存在
        int findname = SelectSchName(std::string(addscheme.SCHEME.toLocal8Bit()));
        if (findname != 0)
        {
            addscheme.IsSchemeOK = false;
        }
        else
        {
            addscheme.IsSchemeOK = true;
        }
    });
    connect(&addscheme, &AddScheme::FinalAddScheme, this, &QC_ApplicationWindow::CreateScheme);
    connect(&alterscheme, &AlterScheme::saveAlterScheme, this, &QC_ApplicationWindow::SaveAlterScheme);
    connect(&alterscheme, &AlterScheme::deleteScheme, this, &QC_ApplicationWindow::DeleteCombobox);
    connect(&alterscheme, &AlterScheme::changeschemename, this, &QC_ApplicationWindow::ChangeSchemeName);

    connect(ui->toolButton_12, &QPushButton::clicked, &guide, &Guide::show);
    connect(ui->toolButton_13, &QPushButton::clicked, &loggerView, &Logger::show);
   /* connect(ui->toolButton_14, &QPushButton::clicked, this, &QC_ApplicationWindow::LockScreen);*/
    connect(ui->toolButton_15, &QPushButton::clicked, this, [=] {
        if (IsOpenBKBK == false){
            enableBKBKPrinting();
        }else{
            disableBKBKPrinting();}
        });
    connect(ui->toolButton_16, &QPushButton::clicked, this, [=] {
        if ( SelectDB_Status())
        {
            serialmanager.setSerialNum( MaxThresholdAlermOpen,  MinThresholdAlermOpen,  cameraAlarmOpen,  markingOutOfAreaOpen,  linkTXOpen,  linkBKBKOpen,  linkCameraOpen);
        }
        serialmanager.show();
        } );
    connect(ui->toolButton_17, &QPushButton::clicked, this, [=] {


        TraverseUsernum = TraverseUser();//用户数量更新
        // 创建登录对话框
        QDialog* loginDialog = new QDialog(this);
        loginDialog->setWindowTitle(QString::fromLocal8Bit("用户登录"));
        loginDialog->setFixedSize(350, 200);
        loginDialog->setModal(true);

        // 主布局
        QVBoxLayout* mainLayout = new QVBoxLayout(loginDialog);

        // 标题
        QLabel* titleLabel = new QLabel(QString::fromLocal8Bit("用户登录"), loginDialog);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin: 15px;");
        mainLayout->addWidget(titleLabel);

        // 表单布局
        QFormLayout* formLayout = new QFormLayout();

        // 用户名（ComboBox格式）
        QComboBox* usernameCombo = new QComboBox(loginDialog);
        usernameCombo->setEditable(false); // 允许编辑
        usernameCombo->clear();
        usernameCombo->setMinimumHeight(35);  // 增加高度
        usernameCombo->setMinimumWidth(170);  // 增加宽度
        usernameCombo->setStyleSheet(
            "QComboBox {"
            "    padding: 2px 12px;"           // 内边距
            "    font-size: 22px;"             // 字体大小
            "    border: 1px solid #ccc;"      // 边框
            "    border-radius: 4px;"          // 圆角
          
            "}"
            "QComboBox::drop-down {"
            "    width: 35px;"                 // 下拉按钮宽度
            "}"
        );
        for (int i = 0; i < TraverseUser(); i++)
        {
            usernameCombo->addItem(QString::fromLocal8Bit(Name[i].c_str()));
        }

        usernameCombo->setCurrentText(""); // 清空默认值
        usernameCombo->setPlaceholderText(QString::fromLocal8Bit("选择或输入用户名"));

        // 密码
        QLineEdit* passwordEdit = new QLineEdit(loginDialog);
        passwordEdit->setPlaceholderText(QString::fromLocal8Bit("请输入密码"));
        passwordEdit->setEchoMode(QLineEdit::Password);
        // 设置密码框尺寸和样式
        passwordEdit->setMinimumHeight(35);    // 增加高度
        passwordEdit->setMinimumWidth(170);    // 增加宽度
        passwordEdit->setStyleSheet(
            "QLineEdit {"
            "    padding: 2px 12px;"           // 内边距
            "    font-size: 22px;"             // 字体大小
            "    border: 1px solid #ccc;"      // 边框
            "    border-radius: 4px;"          // 圆角
            "}"
        );
        formLayout->addRow(QString::fromLocal8Bit("用户名:"), usernameCombo);
        formLayout->addRow(QString::fromLocal8Bit("密　码:"), passwordEdit);
        mainLayout->addLayout(formLayout);

        // 按钮布局
        QHBoxLayout* buttonLayout = new QHBoxLayout();

        // 根据登录状态显示不同按钮
        QPushButton* loginBtn;
        QPushButton* logoutBtn;
        QPushButton* cancelBtn = new QPushButton(QString::fromLocal8Bit("退出"), loginDialog);

        if (m_isLoggedIn) {
            // 已登录状态：显示注销和退出
            logoutBtn = new QPushButton(QString::fromLocal8Bit("注销"), loginDialog);
            logoutBtn->setStyleSheet("background-color: #f44336; color: white;");

            buttonLayout->addWidget(logoutBtn);
            buttonLayout->addWidget(cancelBtn);
        }
        else {
            // 未登录状态：显示登录和退出
            loginBtn = new QPushButton(QString::fromLocal8Bit("登录"), loginDialog);
            loginBtn->setStyleSheet("background-color: #4CAF50; color: white;");

            buttonLayout->addWidget(loginBtn);
            buttonLayout->addWidget(cancelBtn);
        }

        mainLayout->addLayout(buttonLayout);

        // 连接信号
        if (m_isLoggedIn) {
            // 注销按钮点击
            connect(logoutBtn, &QPushButton::clicked, loginDialog, [=] {
                m_isLoggedIn = false;

                loginDialog->accept();
                USERname = "未登录";
                PenMa = 0;
                LiuShuixian = 0;
                Chufa = 0;
                FangZhen = 0;
                PeiFang = 0;
                xiangJi = 0;
                CDL = 0;
                YongHu = 0;
                BianJi = 0;
                ui->toolButton_17->setText(QString::fromLocal8Bit("未登录"));
                manageUserPermissions();
                QMessageBox::information(this, QString::fromLocal8Bit("注销成功"), QString::fromLocal8Bit("您已成功注销"));
                Logger::write("未登录");
                });
        }
        else {
            // 登录按钮点击
            connect(loginBtn, &QPushButton::clicked, loginDialog, [=] {
                string username = usernameCombo->currentText().toLocal8Bit();
                password = passwordEdit->text().toStdString();
                SelectUser(username);
                qDebug() << "输入的密码:" << QString::fromStdString(password);
                qDebug() << "数据库密码:" << QString::fromStdString(userinfo.password);
                if (username == "") {
                    QMessageBox::warning(loginDialog, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("请输入用户名"));
                    return;
                }

                if (password == "") {
                    QMessageBox::warning(loginDialog, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("请输入密码"));
                    return;
                }
                else
                {
                    if (password == userinfo.password)
                    {
                        Userindex = usernameCombo->currentIndex();
                        m_isLoggedIn = true;
                        loginDialog->hide();
                        USERname = userinfo.USERname;
                        PenMa = userinfo.PenMa;
                        LiuShuixian = userinfo.LiuShuixian;
                        Chufa = userinfo.Chufa;
                        FangZhen = userinfo.FangZhen;
                        PeiFang = userinfo.PeiFang;
                        xiangJi = userinfo.xiangJi;
                        CDL = userinfo.CDL;
                        YongHu = userinfo.YongHu;
                        BianJi = userinfo.BianJi;
                        User.setUser(Userindex, userinfo.PenMa, userinfo.LiuShuixian, userinfo.Chufa, userinfo.FangZhen, userinfo.PeiFang, userinfo.xiangJi, userinfo.CDL, userinfo.YongHu, userinfo.BianJi, TraverseUsernum, Name);
                        manageUserPermissions();
                        ui->toolButton_17->setText(QString::fromLocal8Bit(USERname.c_str()));
                        Logger::write(USERname.c_str() );
                        return;
                    }
                    else
                    {
                        QMessageBox::warning(loginDialog, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("密码错误"));
                        return;
                    }
                }


                });
        }

        // 退出按钮
        connect(cancelBtn, &QPushButton::clicked, loginDialog, &QDialog::reject);

        // 回车键登录
        if (!m_isLoggedIn) {
            connect(passwordEdit, &QLineEdit::returnPressed, loginBtn, &QPushButton::click);
        }

        // 显示对话框
        loginDialog->exec();

        // 清理内存
        loginDialog->deleteLater();
        });
    connect(ui->toolButton_18, &QPushButton::clicked, this, [=] {
        ui->toolButton_18->setStyleSheet("background-color:  #87CEEB;");
        ui->toolButton_20->setStyleSheet("background-color:  #FFFFFF;");
        SCenabled = true;
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->toolButton_20, &QPushButton::clicked, this, [=] {
        ui->toolButton_18->setStyleSheet("background-color:  #FFFFFF;");
        ui->toolButton_20->setStyleSheet("background-color:  #87CEEB;");
        SCenabled = false;
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->toolButton_22, &QPushButton::clicked, this, [=] {
        ui->toolButton_22->setStyleSheet("background-color:  #87CEEB;");
        ui->toolButton_23->setStyleSheet("background-color:  #FFFFFF;");
        BZenabled = true;
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->toolButton_23, &QPushButton::clicked, this, [=] {
        ui->toolButton_22->setStyleSheet("background-color:  #FFFFFF;");
        ui->toolButton_23->setStyleSheet("background-color:  #87CEEB;");
        BZenabled = false;
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->toolButton_24, &QPushButton::clicked, this, [=] {
        ui->toolButton_24->setStyleSheet("background-color:  #87CEEB;");
        ui->toolButton_29->setStyleSheet("background-color:  #FFFFFF;");
        EWenabled = true;
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->toolButton_25, &QPushButton::clicked, this, &QC_ApplicationWindow::ShowXJadmain);
    connect(ui->toolButton_29, &QPushButton::clicked, this, [=] {
        ui->toolButton_24->setStyleSheet("background-color:  #FFFFFF;");
        ui->toolButton_29->setStyleSheet("background-color:  #87CEEB;");
        EWenabled = false;
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->toolButton_30, &QPushButton::clicked, this, &QC_ApplicationWindow::ShowUser);
 
   
    connect(ui->toolButton_21, &QPushButton::clicked, this, [=] {
        ui->stackedWidget_2->setCurrentIndex(3);
        //ui->stackedWidget_3->setCurrentIndex(1);
        TriggerLine0();
    });
  
    connect(ui->toolButton_36, &QPushButton::clicked, this, [=] {
        ui->stackedWidget_2->setCurrentIndex(2);
        ui->stackedWidget_3->setCurrentIndex(0);
        TriggerLine0();
        });
   // connect(ui->toolButton_37, &QPushButton::clicked, this, [=] {
    //    createSimplePieChart();

    //    });
    connect(ui->toolButton_34, &QPushButton::clicked, this, [=] {
        if (IsOpenBKBK == true)
        {
            FileUtils::SendBKBK("02", "F0",1);//单次打码
            Logger::writeComm("单次打码");
        }
        else
        {
            QMessageBox* msgBox = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("打印失败  "), QString::fromLocal8Bit("打印未开启! "), QMessageBox::Ok, this);
            msgBox->setFixedSize(400, 400);
            msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBox->show();
        }
        });
    connect(ui->toolButton_35, &QPushButton::clicked, this, [=] {
        if (isOpenCam)
        {
            FileUtils::SendBKBK("02", "F1", 1);//单次拍照
            Logger::writeComm("单次拍照");
        }
        else
        {
            QMessageBox* msgBox = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("拍照失败  "), QString::fromLocal8Bit("相机未开启! "), QMessageBox::Ok, this);
            msgBox->setFixedSize(400, 400);
            msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBox->show();
        }
        });

    connect(ui->toolButton_10, &QPushButton::clicked, this, [=] {
        FileUtils::SendBKBK("21", "F0", 1);//取消报警
        Logger::writeError("取消报警");
        });
 
    
  
    connect(ui->toolButton_42, &QToolButton::clicked,actionHandler, &QG_ActionHandler::slotDrawMText);//编辑文本
    connect(ui->toolButton_43, &QToolButton::clicked, actionHandler, &QG_ActionHandler::slotZoomIn);
    connect(ui->toolButton_44, &QToolButton::clicked, actionHandler, &QG_ActionHandler::slotZoomOut);
    connect(ui->toolButton_45, &QToolButton::clicked, actionHandler, &QG_ActionHandler::slotZoomAuto);
   
    connect(ui->toolButton_46, &QToolButton::clicked, actionHandler, &QG_ActionHandler::slotModifyDeleteQuick);


    connect(ui->toolButton_26, &QToolButton::clicked, this, [=] {
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->stackedWidget_3->setCurrentIndex(0);
        if (!model) {
            TriggerLine0();
        }
        });
    connect(ui->toolButton_47, &QToolButton::clicked, this, [=] {
      
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_3->setCurrentIndex(0);
        //AutoCap();

        });

    connect(ui->pushButton_3, &QPushButton::clicked, this, &QC_ApplicationWindow::SelectTime);
    connect(ui->pushButton_4, &QPushButton::clicked, this, [=] {

        CustomStr_6 = "";
        CustomStr_6.append(std::string(ui->lineEdit_9->text().toLocal8Bit()));

        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        if (AlterSchemeContent(delestr))
        {
            QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("保存成功  "), QString::fromLocal8Bit("保存成功 "), QMessageBox::Ok, this);
            msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBox->show();
        }
        string Log_Str = "*保存检测额外代码内容:\n" + CustomStr_6;
        Logger::write(Log_Str);
        });
    connect(ui->pushButton_5, &QPushButton::clicked, this, [=] {
        if (SCenabled != 0) {
            if (FH != "*") {
                ui->lineEdit_2->setText(FH + Start_Data_Time);
            }
            else {
                ui->lineEdit_2->setText(Start_Data_Time);
            }
        }
        else {
            ui->lineEdit_2->setText(QString::fromLocal8Bit("生产日期未启用"));
        }
        if (BZenabled != 0) {
            ui->lineEdit_10->setText(Save_Time);
        }
        else {
            ui->lineEdit_10->setText(QString::fromLocal8Bit("保质日期未启用"));
        }
        if (EWenabled != 0) {
            ui->lineEdit_12->setText(CustomStr_6.c_str());
        }
        else {
            ui->lineEdit_12->setText(QString::fromLocal8Bit("额外代码未启用"));
        }
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(2);
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);
        });
    connect(ui->pushButton_6, &QPushButton::clicked, this, &QC_ApplicationWindow::saveCustomFields);
    connect(ui->comboBox,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,&QC_ApplicationWindow::ChangeScheme);
    connect(this, &QC_ApplicationWindow::RunOcr, this, &QC_ApplicationWindow::CapAndOcr);
    connect(this, &QC_ApplicationWindow::RunShow, this, &QC_ApplicationWindow::SubCapture);
   // connect(this, &QC_ApplicationWindow::AlarmSignal, this, &QC_ApplicationWindow::Alarm);
   // connect(this, &QC_ApplicationWindow::UNAlarmSignal, this, &QC_ApplicationWindow::UNAlarm);
    connect(this, &QC_ApplicationWindow::CamError, this, &QC_ApplicationWindow::CamErrorAct);//相机掉线动作);
   
    connect(&User, &user::showmain, this, [=] {
        GatUser();
        this->show();
        User.hide();
        Logger::write("关闭用户界面 "); });
    connect(&User, &user::addUser, this, &QC_ApplicationWindow::AddUser);//添加用户动作);
    connect(&User, &user::delUser, this, &QC_ApplicationWindow::DelUser); //删除用户动作);
    connect(&User, &user::alterpassword, this, &QC_ApplicationWindow::Alterpassword); //修改用户动作);

    connect(&jgadmin, &Jgadmin::showmain, this, [=] { 
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Question, QString::fromLocal8Bit("是否保存方案 "), QString::fromLocal8Bit("是否保存修改内容？ "), QMessageBox::Ok, &setting);
        msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("保存并返回 "));
        msgBox->setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("直接返回 "));
        if (msgBox->exec() == QMessageBox::Ok)
        {
            GatJgadmin();
            AlterDB_Jgconfig();//更新数据库
            FileUtils::Sendmarking();
            FileUtils::Sendkey();
            FileUtils::Sendall();
            this->show();
            jgadmin.hide();
            Logger::write("保存方案并返回 ");

        }
        else
        {
            this->show();
            jgadmin.hide();
        }

        Logger::write("关闭参数设置界面 ");

        });
    connect(&serialmanager, &SerialManager::showmain, this, [=] {

        serialmanager.hide();
        
      
        });
    connect(&serialmanager, &SerialManager::setzhuangtai, this, [=] {
        int date = serialmanager.getSerialNum();
        int date2 = serialmanager.getSerialNum2();

        linkCameraOpen = (date & 0x04) != 0;
        linkBKBKOpen = (date & 0x02) != 0;
        linkTXOpen = (date & 0x01) != 0;

        markingOutOfAreaOpen = (date2 & 0x01) != 0;
        cameraAlarmOpen = (date2 & 0x02) != 0;
        MinThresholdAlermOpen = (date2 & 0x04) != 0;
        MaxThresholdAlermOpen = (date2 & 0x08) != 0;
        AlterDB_Status();
       // FileUtils::SendBKBK(75, date);
       // FileUtils::SendBKBK(76, date2);
        FileUtils::SendBKBK("20","00", date);
        FileUtils::SendBKBK("21","02", date2);

        });
    connect(&setting, &Setting::showmain, this, &QC_ApplicationWindow::ShowThis);
    connect(&setting, &Setting::getrect, this, &QC_ApplicationWindow::SetRect);
    connect(&setting, &Setting::setExposureTime, this, &QC_ApplicationWindow::SetExposureTime);
    connect(&setting, &Setting::setGainValue, this, &QC_ApplicationWindow::SetGainValue);
    connect(&setting, &Setting::setRot, this, &QC_ApplicationWindow::SetRot);
    connect(&setting, &Setting::autocap, this, &QC_ApplicationWindow::AutoCap);
    connect(&setting, &Setting::closeautocap, this, &QC_ApplicationWindow::TriggerLine0);
    connect(&setting, &Setting::caponepic, this, &QC_ApplicationWindow::TriggerSoftware);
    connect(&setting, &Setting::setSharpness, this, &QC_ApplicationWindow::SetSharpness);
    connect(&setting, &Setting::firstopen, this, [=] {
        if (IsAlter)
        {
            IsAlter = false;
        }
        });
    connect(&xjadmin, &XJadmin::showmain, this, [=] {
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Question, QString::fromLocal8Bit("是否保存方案 "), QString::fromLocal8Bit("是否保存修改内容？ "), QMessageBox::Ok, &setting);
        msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("保存并返回 "));
        msgBox->setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("直接返回 "));
        if (msgBox->exec() == QMessageBox::Ok)
        {
            GatXJadmin();
            FileUtils::Sendphoto();
            FileUtils::Sendalarm();
            FileUtils::Sendall();
            FileUtils::Sendkey();

            AlterDB_Jgconfig();//更新数据库
           
            AlterScheme();
            IsxjadminOpen = false;
            this->show();
            //AlterScheme();
            xjadmin.hide();
            Logger::write("保存方案并返回 ");
        }
        else
        {
            IsxjadminOpen = false;
            this->show();
            xjadmin.hide();
        }
        Logger::write("关闭参数设置界面 ");
        });

  
    connect(TimerLongPressSub, &QTimer::timeout, this, [=] {
        TimerLongPressSub->stop();
        CamTimerEnd = true;
    });

    ImageSize = FindImageSize();
    //CamFilterTime = FindCamFilterTime();
    //CamFilterLength = FindCamFilterLength();
 
    RateClear();
    UpdateCombobox();

    CamerButton();


    if (FindNameCode() != 0)
    {
        ui->comboBox->setCurrentIndex(FindNameCode());
    }
    else
    {
        SetScheme(ui->comboBox->currentText());
    }
    //ui.comboBox->setCurrentIndex(FindNameCode());

   // 使用函数指针的Qt5兼容方式
    connect(ui->spinBox,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        [=](int value) {
            save_time = value;  // 使用传递的值而不是再次获取
            UpdataTime();
        });
    connect(ui->spinBox_2,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        [=](int value) {
            Savemonth = value;  // 使用传递的值而不是再次获取
            UpdataTime();
        });
    connect(ui->spinBox_3,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        [=](int value) {
            Saveyear = value;  // 使用传递的值而不是再次获取
            UpdataTime();
        });
    QDateTime datetime = QDateTime::currentDateTime(); //当前时间
    year = datetime.date().year();             //年
    month = datetime.date().month();			   //月
    day = datetime.date().day();				   //日
    ui->spinBox->setMaximum(10000);
    ui->spinBox->setMinimum(-10000);
    ui->spinBox->setValue(save_time);
    UpdataTime();

    getSerialNum3();
   
   

    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow");

#ifdef _WINDOWS
    qt_ntfs_permission_lookup++; // turn checking on
#endif

    //accept drop events to open files
    setAcceptDrops(false);  //禁用拖放功能,拖放是指从外面把一个文件拖过来

    // make the left and right dock areas dominant
    // 设置停靠区域主导方向
    /*这部分用于设置 Qt 主窗口（QMainWindow）的停靠区域（Dock）优先级，控制角落属于哪个 dock 区域。*/
    /*                如果左上角/左下角存在多个 dock widget，
    那么左边的 dock（LeftDockWidgetArea）优先于顶部 dock                              ------------*/


    /*              左上/左下角绑定左侧停靠区（放置图层、图块面板）。
                    右上/右下角绑定右侧停靠区（放置命令窗口、属性面板
                                                                                   */
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    appWindow = this;// 设置单例实例

    //QSettings settings;

    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow: setting icon");
    setWindowIcon(QIcon(QC_APP_ICON));// 设置窗口图标

    pen_wiz->setObjectName("pen_wiz");
    connect(this, &QC_ApplicationWindow::windowsChanged,
        pen_wiz, &LC_PenWizard::setEnabled);
    addDockWidget(Qt::RightDockWidgetArea, pen_wiz);
    //
    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow: init status bar");




    //状态栏(左下角)初始化
    QStatusBar* status_bar = statusBar();

    //coordinateWidget = new QG_CoordinateWidget(status_bar, "coordinates");// 坐标显示
    //status_bar->addWidget(coordinateWidget);
    mouseWidget = new QG_MouseWidget(status_bar, "mouse info");           // 鼠标状态
    status_bar->addWidget(mouseWidget);
    selectionWidget = new QG_SelectionWidget(status_bar, "selections");   // 选择计数
    status_bar->addWidget(selectionWidget);
    m_pActiveLayerName = new QG_ActiveLayerName(this);                    // 当前图层名  
    status_bar->addWidget(m_pActiveLayerName);
    grid_status = new TwoStackedLabels(status_bar);                       // 网格状态
    grid_status->setTopLabel(tr("Grid Status"));
    status_bar->addWidget(grid_status);

    settings.beginGroup("Widgets");
    int allow_statusbar_fontsize = settings.value("AllowStatusbarFontSize", 0).toInt();
    int allow_statusbar_height = settings.value("AllowStatusbarHeight", 0).toInt();

    if (allow_statusbar_fontsize)
    {
        int fontsize = settings.value("StatusbarFontSize", 12).toInt();
        QFont font;
        font.setPointSize(fontsize);
        status_bar->setFont(font);
    }
    int height{ 20 };
    if (allow_statusbar_height) {
        height = settings.value("StatusbarHeight", 20).toInt();
    }
    status_bar->setMinimumHeight(height);
    status_bar->setMaximumHeight(height);
    settings.endGroup();

    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow: creating LC_CentralWidget");

    status_bar->hide();
  
    // 1. 移除状态栏中的坐标控件（注释掉原有代码） 
    // 这部分和状态栏的样式文件冲突了,好在状态栏这几个用途不大
    // status_bar->addWidget(coordinateWidget);



    mdiAreaCAD = ui->mdiArea;  // 将UI中的mdiArea赋值给成员变量
  //  mdiAreaCAD->setDocumentMode(false);// 启用标签页模式

    //中央部件与 MDI 管理
//auto central = new LC_CentralWidget(this);
   // central作为中央容器，管理多个绘图子窗口
    //setCentralWidget(central);

   // mdiAreaCAD = central->getMdiArea();
 //   mdiAreaCAD->setDocumentMode(true);// 启用标签页模式

    RS_SETTINGS->beginGroup("/WindowOptions");
    setTabLayout(static_cast<RS2::TabShape>(RS_SETTINGS->readNumEntry("/TabShape", RS2::Triangular)),
        static_cast<RS2::TabPosition>(RS_SETTINGS->readNumEntry("/TabPosition", RS2::West)));
    RS_SETTINGS->endGroup();

    settings.beginGroup("Startup");
    if (settings.value("TabMode", 0).toBool()) {
        mdiAreaCAD->setViewMode(QMdiArea::TabbedView);
        QList<QTabBar*> tabBarList = mdiAreaCAD->findChildren<QTabBar*>();
        QTabBar* tabBar = tabBarList.at(0);
        if (tabBar)
            tabBar->setExpanding(false);
    }

    bool enable_left_sidebar = settings.value("EnableLeftSidebar", 1).toBool();
    bool enable_cad_toolbars = settings.value("EnableCADToolbars", 1).toBool();
    settings.endGroup();

    connect(mdiAreaCAD, SIGNAL(subWindowActivated(QMdiSubWindow*)),
        this, SLOT(slotWindowActivated(QMdiSubWindow*)));


    //默认图标大小
    settings.beginGroup("Widgets");
    bool custom_size = settings.value("AllowToolbarIconSize", 1).toBool();
    int icon_size = custom_size ? settings.value("ToolbarIconSize", 40).toInt() : 40;
    settings.endGroup();

    if (custom_size)
        setIconSize(QSize(icon_size, icon_size));



    //工具栏与菜单栏
    LC_ActionFactory a_factory(this, actionHandler);
    a_factory.using_theme = settings.value("Widgets/AllowTheme", 0).toBool();
    a_factory.fillActionContainer(a_map, ag_manager);//// 填充动作集合

    LC_WidgetFactory widget_factory(this, a_map, ag_manager);
    // GUI 构建器类，负责集中创建窗口控件
    if (enable_left_sidebar)
        widget_factory.createLeftSidebar(5, icon_size);         //左侧工具栏（绘图工具）
    if (enable_cad_toolbars)
        widget_factory.createCADToolbars();                     // 创建 CAD 工具栏
    widget_factory.createRightSidebar(actionHandler);           // / 右侧属性/图层/块工具栏
    widget_factory.createCategoriesToolbar();                   //分类工具栏
    widget_factory.createStandardToolbars(actionHandler);       // 标准工具栏


   


    //加载自定义工具栏从用户设置中读取工具栏配置
    settings.beginGroup("CustomToolbars");
    foreach(auto key, settings.childKeys())
    {
        auto toolbar = new QToolBar(key, this);
        toolbar->setObjectName(key);
        foreach(auto action, settings.value(key).toStringList())
        {
            toolbar->addAction(a_map[action]);
        }
        addToolBar(toolbar);

    }
    settings.endGroup();

    /*默认工具栏:在添加多行文本那里                                                
    如果是首次启动，会创建一个包含部分默认指令的工具栏，如：
    list << "DrawMText" << "DrawHatch" << "DrawImage" << "BlocksCreate" << "DrawPoint";
    */
    if (settings.value("Startup/FirstLoad", 1).toBool())
    {
        // 调试：打印所有可用的动作名称
        qDebug() << "=== 所有可用的动作 ===";
        QStringList allActions = a_map.keys();
        allActions.sort();
        foreach(const QString& actionName, allActions) {
            qDebug() << actionName;
        }
        qDebug() << "====================";
        QStringList list;
        list << "DrawMText"
            << "DrawHatch"
            << "ModifyDeleteQuick"
            << "ZoomIn"
            << "ZoomOut"
            << "ZoomAuto"
           
            << "FileNew"
            << "FileOpen";

        auto toolbar = new QToolBar("DefaultCustom", this);
        toolbar->setObjectName("DefaultCustom");
        foreach(auto action, list)
        {
            toolbar->addAction(a_map[action]);
        }
        settings.setValue("CustomToolbars/DefaultCustom", list);
        addToolBar(Qt::LeftToolBarArea, toolbar);
    }


    //创建菜单栏
    widget_factory.createMenus(menuBar());

    undoButton = a_map["EditUndo"];
    redoButton = a_map["EditRedo"];
    previousZoom = a_map["ZoomPrevious"];

    //管理 Dock 区域可见性控制按钮
    dock_areas.left = a_map["LeftDockAreaToggle"];
    dock_areas.right = a_map["RightDockAreaToggle"];
    dock_areas.top = a_map["TopDockAreaToggle"];
    dock_areas.bottom = a_map["BottomDockAreaToggle"];
    dock_areas.floating = a_map["FloatingDockwidgetsToggle"];


    //工具栏和小部件引用保存
    snapToolBar = widget_factory.snap_toolbar;
    penToolBar = widget_factory.pen_toolbar;
    optionWidget = widget_factory.options_toolbar;

    layerWidget = widget_factory.layer_widget;
    blockWidget = widget_factory.block_widget;
    commandWidget = widget_factory.command_widget;

    file_menu = widget_factory.file_menu;
    windowsMenu = widget_factory.windows_menu;


    //连接信号槽：关闭文档、修改画笔、快捷键
    connect(a_map["FileClose"], SIGNAL(triggered(bool)),
        mdiAreaCAD, SLOT(closeActiveSubWindow()));

    connect(penToolBar, SIGNAL(penChanged(RS_Pen)),
        this, SLOT(slotPenChanged(RS_Pen)));

    auto ctrl_l = new QShortcut(QKeySequence("Ctrl+L"), this);
    connect(ctrl_l, SIGNAL(activated()), actionHandler, SLOT(slotLayersAdd()));

    auto ctrl_m = new QShortcut(QKeySequence("Ctrl+M"), this);
    connect(ctrl_m, SIGNAL(activated()), this, SLOT(slotFocusCommandLine()));

    // This event filter allows sending key events to the command widget, therefore, no
    // need to activate the command widget before typing commands.
    // Since this nice feature causes a bug of lost key events when the command widget is on
    // a screen different from the main window, disabled for the time being
    // send key events for mdiAreaCAD to command widget by default


    // 安装事件过滤器,用于将按键事件直接发往命令行输入框。
    mdiAreaCAD->installEventFilter(commandWidget);

    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow: creating dialogFactory");
    dialogFactory = new QC_DialogFactory(this, optionWidget);
    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow: creating dialogFactory: OK");

    RS_DEBUG->print("setting dialog factory object");
    if (RS_DialogFactory::instance() == nullptr) {
        RS_DEBUG->print("no RS_DialogFactory instance");
    }
    else {
        RS_DEBUG->print("got RS_DialogFactory instance");
    }

    // 创建并绑定对话框工厂,用于统一管理对话框创建（比如属性编辑、块插入等）
    RS_DialogFactory::instance()->setFactoryObject(dialogFactory);
    RS_DEBUG->print("setting dialog factory object: OK");

    //最近文件列表菜单构建
    recentFiles = new QG_RecentFiles(this, 9);
    auto recent_menu = new QMenu(tr("Recent Files"), file_menu);
    file_menu->addMenu(recent_menu);
    recentFiles->addFiles(recent_menu);

    RS_DEBUG->print("QC_ApplicationWindow::QC_ApplicationWindow: init settings");
    initSettings();


    //加载用户命令文件（可选）
    auto command_file = settings.value("Paths/VariableFile", "").toString();
    if (!command_file.isEmpty())
        commandWidget->leCommand->readCommandFile(command_file);

    // Activate autosave timer启动自动保存定时器
    if (settings.value("Defaults/AutoBackupDocument", 0).toBool())
    {
        autosaveTimer = new QTimer(this);
        autosaveTimer->setObjectName("autosave");
        connect(autosaveTimer, SIGNAL(timeout()), this, SLOT(slotFileAutoSave()));
        int ms = 60000 * settings.value("Defaults/AutoSaveTime", 5).toInt();
        autosaveTimer->start(ms);
    }

    // Disable menu and toolbar items

    emit windowsChanged(false);

    RS_COMMANDS->updateAlias();
    //plugin load
    loadPlugins();

    statusBar()->showMessage(qApp->applicationName() + " Ready", 2000);

    
    
    SetQSS();
    initializeUserPermissions();
    setupImageButtonEvents();
   
   
}

/**
  * Find a menu entry in the current menu list. This function will try to recursively find the menu
  * searchMenu for example foo/bar
  * thisMenuList list of Widgets
  * currentEntry only used internally during recursion
  * returns 0 when no menu was found
  */
QMenu *QC_ApplicationWindow::findMenu(const QString &searchMenu, const QObjectList thisMenuList, const QString& currentEntry) {
    if (searchMenu==currentEntry)
        return ( QMenu *)thisMenuList.at(0)->parent();

    QList<QObject*>::const_iterator i=thisMenuList.begin();
    while (i != thisMenuList.end()) {
        if ((*i)->inherits ("QMenu")) {
            QMenu *ii=(QMenu*)*i;
            if (QMenu *foundMenu=findMenu(searchMenu, ii->children(), currentEntry+"/"+ii->objectName().replace("&", ""))) {
                return foundMenu;
            }
        }
        ++i;
    }
    return 0;
}

/**
 * Arrange the sub-windows as specified, and set the setting.
 * Note: Tab mode always uses (and sets) the RS2::Maximized mode.
 * @param m the layout mode; if set to RS2::CurrentMode, read the current setting
 * @param actuallyDont just set the setting, don't actually do the arrangement
 */
void QC_ApplicationWindow::doArrangeWindows(RS2::SubWindowMode m, bool actuallyDont)
{
	RS_SETTINGS->beginGroup("/WindowOptions");
	int mode = m != RS2::CurrentMode ? m : RS_SETTINGS->readNumEntry("/SubWindowMode", RS2::Maximized);
	RS_SETTINGS->endGroup();
	if (!actuallyDont) switch (mode) {
	case RS2::Maximized:
		if (mdiAreaCAD->currentSubWindow())
			mdiAreaCAD->currentSubWindow()->showMaximized();
		break;
	case RS2::Cascade:
		slotCascade();
		break;
	case RS2::Tile:
		slotTile();
		break;
	case RS2::TileHorizontal:
		slotTileHorizontal();
		break;
	case RS2::TileVertical:
		slotTileVertical();
		break;
	}
	
	RS_SETTINGS->beginGroup("/WindowOptions");
	RS_SETTINGS->writeEntry("/SubWindowMode", mode);
	RS_SETTINGS->endGroup();
}

/**
 * Set the QTabWidget shape and position for the MDI area; also the settings.
 * Note: setting a Tab layout always sets the window arrangement to RS2::Maximized
 * Used by the Drawing > Layout menu.
 * @param s the tab shape; if RS2::AnyShape read the current setting
 * @param p the tab bar position; if RS2::AnyPosition read the current setting
 */
void QC_ApplicationWindow::setTabLayout(RS2::TabShape s, RS2::TabPosition p)
{
	RS_SETTINGS->beginGroup("/WindowOptions");
	int shape = s != RS2::AnyShape ? s : RS_SETTINGS->readNumEntry("/TabShape", RS2::Triangular);
	int position = p != RS2::AnyPosition ? p : RS_SETTINGS->readNumEntry("/TabPosition", RS2::West);
	RS_SETTINGS->endGroup();
	mdiAreaCAD->setTabShape(static_cast<QTabWidget::TabShape>(shape));
	mdiAreaCAD->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
	doArrangeWindows(RS2::Maximized);
	RS_SETTINGS->beginGroup("/WindowOptions");
	RS_SETTINGS->writeEntry("/TabShape", shape);
	RS_SETTINGS->writeEntry("/TabPosition", position);
	RS_SETTINGS->endGroup();
}

/**
 * Force-Save(as) the content of the sub window.  Retry on failure.
 * @return true success (or window was not modified)
 * @return false user cancelled (or window was null)
 */
bool QC_ApplicationWindow::doSave(QC_MDIWindow * w, bool forceSaveAs)
{
	QString name, msg;
	bool cancelled;
	if (!w) return false;
    if (w->getDocument()->isModified() || forceSaveAs) {
		name = w->getDocument()->getFilename();
		if (name.isEmpty())
			doActivate(w); // show the user the drawing for save as
		msg = name.isEmpty() ? tr("Saving drawing...") : tr("Saving drawing: %1").arg(name);
		statusBar()->showMessage(msg);
		bool res = forceSaveAs ? w->slotFileSaveAs(cancelled) : w->slotFileSave(cancelled);
		if (res) {
			if (cancelled) {
				statusBar()->showMessage(tr("Save cancelled"), 2000);
				return false;
			}
			name = w->getDocument()->getFilename();			
			msg = tr("Saved drawing: %1").arg(name);
			statusBar()->showMessage(msg, 2000);
			commandWidget->appendHistory(msg);

			if (recentFiles->indexOf(name) == -1) recentFiles->add(name);

			w->setWindowTitle(format_filename_caption(name) + "[*]");
			if (w->getGraphicView()->isDraftMode())
				w->setWindowTitle(w->windowTitle() + " [" + tr("Draft Mode") + "]");

			if (autosaveTimer && !autosaveTimer->isActive())
			{
				RS_SETTINGS->beginGroup("/Defaults");
				autosaveTimer->start(RS_SETTINGS->readNumEntry("/AutoSaveTime", 5) * 60 * 1000);
				RS_SETTINGS->endGroup();
			}
		}
		else {
			msg = tr("Cannot save the file ") +
				w->getDocument()->getFilename()
				+ tr(" , please check the filename and permissions.");
			statusBar()->showMessage(msg, 2000);
			commandWidget->appendHistory(msg);
			return doSave(w, true);
		}
	}
	return true;
}

/**
 * Force-Close this sub window.
 * @param activateNext also activate the next window in the window_list, if any
 */
void QC_ApplicationWindow::doClose(QC_MDIWindow * w, bool activateNext)
{
	RS_DEBUG->print("QC_ApplicationWindow::doClose begin");
	w->getGraphicView()->killAllActions();
	QC_MDIWindow* parentWindow = w->getParentWindow();
	if (parentWindow)
	{
		RS_DEBUG->print("QC_ApplicationWindow::doClose closing block or print preview");
		parentWindow->removeChildWindow(w);
	}
	else
	{
		RS_DEBUG->print("QC_ApplicationWindow::doClose closing graphic");
	}
	for (auto child : w->getChildWindows()) // block editors and print previews; just force these closed
		doClose(child, false); // they belong to the document (changes already saved there)
	w->getChildWindows().clear();
	mdiAreaCAD->removeSubWindow(w);
	window_list.removeOne(w);

	if (!activedMdiSubWindow || activedMdiSubWindow == w)
	{
		layerWidget->setLayerList(nullptr, false);
		blockWidget->setBlockList(nullptr);
		//coordinateWidget->setGraphic(nullptr);
	}

	openedFiles.removeAll(w->getDocument()->getFilename());

	activedMdiSubWindow = nullptr;
	actionHandler->set_view(nullptr);
	actionHandler->set_document(nullptr);

    if (activateNext && window_list.count() > 0) {
        if (nullptr != parentWindow) {
            doActivate(parentWindow);
        }
        else {
            doActivate(window_list.front());
        }
    }

    RS_DEBUG->print("QC_ApplicationWindow::doClose end");
}

/**
 * Force-Activate this sub window.
 */
void QC_ApplicationWindow::doActivate(QMdiSubWindow * w)
{
	RS_SETTINGS->beginGroup("/WindowOptions");
	bool maximized = RS_SETTINGS->readNumEntry("/Maximized");
	RS_SETTINGS->endGroup();
	if (w) {
		slotWindowActivated(w);
		w->activateWindow();
		w->raise();
		w->setFocus();
        if (maximized || QMdiArea::TabbedView == mdiAreaCAD->viewMode()) {
            w->showMaximized();
        }
        else {
            w->show();
        }
    }
	if (mdiAreaCAD->viewMode() == QMdiArea::SubWindowView)
		doArrangeWindows(RS2::CurrentMode);
	enableFileActions(qobject_cast<QC_MDIWindow*>(w));
}

/**
 * Show a Save/Close/Cancel(All) dialog for the content of this sub-window.
 * The window handle must not be null, and the document must actually have been modified.
 *
 * @param showSaveAll show a Save All button and rename Close -> Close All
 * @return QG_ExitDialog::ExitDialogResult the button that was pressed, or -1 if invoked in error
 * @see QG_ExitDialog
 */
int QC_ApplicationWindow::showCloseDialog(QC_MDIWindow * w, bool showSaveAll)
{
	QG_ExitDialog dlg(this);
	dlg.setShowSaveAll(showSaveAll);
	dlg.setTitle(tr("Closing Drawing"));
	if (w && w->getDocument()->isModified()) {
		QString fn = w->getDocument()->getFilename();
		if (fn.isEmpty())
			fn = w->windowTitle();
		else if (fn.length() > 50)
			fn = QString("%1...%2").arg(fn.left(24)).arg(fn.right(24));
        RS_Document* document = getDocument();
       
		dlg.setText(QString::fromLocal8Bit("是否保存对以下项目的更改?\n%1").arg(fn));
		return dlg.exec();
	}
	return -1; // should never get here; please send only modified documents
}

/**
 * Enable the available file actions for this sub-window.
 */
void QC_ApplicationWindow::enableFileActions(QC_MDIWindow* w)
{
	if (!w || w->getDocument()->getFilename().isEmpty()) {
		a_map["FileSave"]->setText(tr("&Save"));
		a_map["FileSaveAs"]->setText(tr("Save &as..."));
	}
	else {
		QString name = format_filename_caption(w->getDocument()->getFilename());
		a_map["FileSave"]->setText(tr("&Save %1").arg(name));
		a_map["FileSaveAs"]->setText(tr("Save %1 &as...").arg(name));
	}
	a_map["FileSave"]->setEnabled(w);
	a_map["FileSaveAs"]->setEnabled(w);
	a_map["FileSaveAll"]->setEnabled(w && window_list.count() > 1);
	a_map["FileExportMakerCam"]->setEnabled(w);
	a_map["FilePrintPDF"]->setEnabled(w);
	a_map["FileExport"]->setEnabled(w);
	a_map["FilePrint"]->setEnabled(w);
	a_map["FilePrintPreview"]->setEnabled(w);
	a_map["FileClose"]->setEnabled(w);
	a_map["FileCloseAll"]->setEnabled(w && window_list.count() > 1);
}

/**
 * Loads the found plugins.
 */
void QC_ApplicationWindow::loadPlugins() {

    loadedPlugins.clear();
    QStringList lst = RS_SYSTEM->getDirectoryList("plugins");
    // Keep track of plugin filenames loaded to skip duplicate plugins.
    QStringList loadedPluginFileNames;

    for (int i = 0; i < lst.size(); ++i) {
        QDir pluginsDir(lst.at(i));
        for(const QString& fileName: pluginsDir.entryList(QDir::Files)) {
            // Skip loading a plugin if a plugin with the same
            // filename has already been loaded.
            #ifdef Q_OS_MAC
            if (!fileName.contains(".dylib"))
                continue;
            #endif
            #ifdef Q_OS_WIN32
            if (!fileName.contains(".dll"))
                continue;
            #endif

            if (loadedPluginFileNames.contains(fileName)) {
                continue;
            }
            QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = pluginLoader.instance();
            if (plugin) {
                QC_PluginInterface *pluginInterface = qobject_cast<QC_PluginInterface *>(plugin);
                if (pluginInterface) {
                    loadedPlugins.push_back(pluginInterface);
                    loadedPluginFileNames.push_back(fileName);
                    PluginCapabilities pluginCapabilities=pluginInterface->getCapabilities();
                    for(const PluginMenuLocation& loc: pluginCapabilities.menuEntryPoints) {
                        QAction *actpl = new QAction(loc.menuEntryActionName, plugin);
                        actpl->setData(loc.menuEntryActionName);
                        connect(actpl, SIGNAL(triggered()), this, SLOT(execPlug()));
                        connect(this, SIGNAL(windowsChanged(bool)), actpl, SLOT(setEnabled(bool)));
                        QMenu *atMenu = findMenu("/"+loc.menuEntryPoint, menuBar()->children(), "");
                        if (atMenu) {
                            atMenu->addAction(actpl);
                        } else {
                            QStringList treemenu = loc.menuEntryPoint.split('/', QString::SkipEmptyParts);
                            QString currentLevel="";
                            QMenu *parentMenu=0;
                            do {
                                QString menuName=treemenu.at(0); treemenu.removeFirst();
                                currentLevel=currentLevel+"/"+menuName;
                                atMenu = findMenu(currentLevel, menuBar()->children(), "");
                                if (atMenu==0) {
                                    if (parentMenu==0) {
                                        parentMenu=menuBar()->addMenu(menuName);
                                    } else {
                                        parentMenu=parentMenu->addMenu(menuName);
                                    }
                                    parentMenu->setObjectName(menuName);
                                }
                            } while(treemenu.size()>0);
							if (parentMenu) parentMenu->addAction(actpl);
                        }
                    }
                }
            } else {
                QMessageBox::information(this, "Info", pluginLoader.errorString());
                RS_DEBUG->print("QC_ApplicationWindow::loadPlugin: %s", pluginLoader.errorString().toLatin1().data());
            }
        }
    }
}

/**
 * Execute the plugin.
 */
void QC_ApplicationWindow::execPlug() {

    QAction *action = qobject_cast<QAction *>(sender());
    QC_PluginInterface *plugin = qobject_cast<QC_PluginInterface *>(action->parent());
//get actual drawing
    QC_MDIWindow* w = getMDIWindow();
    RS_Document* currdoc = w->getDocument();
//create document interface instance
    Doc_plugin_interface pligundoc(currdoc, w->getGraphicView(), this);
//execute plugin
    LC_UndoSection undo(currdoc);
    
  
    plugin->execComm(&pligundoc, this, action->data().toString());
//TODO call update view
w->getGraphicView()->redraw();
}


/**
 * Destructor.
 */
QC_ApplicationWindow::~QC_ApplicationWindow() {
    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow");

    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow: "
                    "deleting dialog factory");

#ifdef _WINDOWS
	qt_ntfs_permission_lookup--; // turn it off again
#endif

    delete dialogFactory;

    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow: "
                    "deleting dialog factory: OK");
}


/**
 * Close Event. Called when the user tries to close the app.
 */
void QC_ApplicationWindow::closeEvent(QCloseEvent* ce)
{
    RS_DEBUG->print("QC_ApplicationWindow::closeEvent()");

    //queryExit(false) ? ce->accept() : ce->ignore();
    slotFileQuit();
    RS_DEBUG->print("QC_ApplicationWindow::closeEvent(): OK");
}

void QC_ApplicationWindow::dropEvent(QDropEvent* event)
{
    event->acceptProposedAction();

    //limit maximum number of dropped files to be opened
    unsigned counts=0;
    for(QUrl const& url: event->mimeData()->urls()) {
        const QString &fileName = url.toLocalFile();
        if(QFileInfo(fileName).exists() && fileName.endsWith(R"(.dxf)", Qt::CaseInsensitive)){
            slotFileOpen(fileName);
            if(++counts>32) return;
        }
    }
}

void 	QC_ApplicationWindow::dragEnterEvent(QDragEnterEvent * event)
{
    if (event->mimeData()->hasUrls()){
        for(QUrl const& url: event->mimeData()->urls()) {
            const QString &fileName = url.toLocalFile();
            if(QFileInfo(fileName).exists() && fileName.endsWith(R"(.dxf)", Qt::CaseInsensitive)){
                event->acceptProposedAction();
                return;
            }
        }
    }
}

/**
 * @return Pointer to the currently active MDI Window or nullptr if no
 * MDI Window is active.
 */
QC_MDIWindow const* QC_ApplicationWindow::getMDIWindow() const{
    if (mdiAreaCAD) {
        QMdiSubWindow* w=mdiAreaCAD->currentSubWindow();
        if(w) {
            return qobject_cast<QC_MDIWindow*>(w);
        }
    }
    return nullptr;
}

QC_MDIWindow* QC_ApplicationWindow::getMDIWindow(){
    if (mdiAreaCAD) {
        QMdiSubWindow* w=mdiAreaCAD->currentSubWindow();
        if(w) {
            return qobject_cast<QC_MDIWindow*>(w);
        }
    }
    return nullptr;
}

void QC_ApplicationWindow::setPreviousZoomEnable(bool enable){
    previousZoomEnable=enable;
    if(previousZoom){
        previousZoom->setEnabled(enable);
    }
}

void QC_ApplicationWindow::setUndoEnable(bool enable){
    undoEnable=enable;
    if(undoButton){
        undoButton->setEnabled(enable);
    }
}

void QC_ApplicationWindow::setRedoEnable(bool enable){
    redoEnable=enable;
    if(redoButton){
        redoButton->setEnabled(enable);
    }
}

void QC_ApplicationWindow::slotEnableActions(bool enable) {
    if(previousZoom){
        previousZoom->setEnabled(enable&& previousZoomEnable);
        undoButton->setEnabled(enable&& undoEnable);
        redoButton->setEnabled(enable&& redoEnable);
    }
}

void QC_ApplicationWindow::slotUpdateActiveLayer()
{
    if(layerWidget&&m_pActiveLayerName)
        m_pActiveLayerName->activeLayerChanged(layerWidget->getActiveName());
}

/**
 * Initializes the global application settings from the
 * config file (unix, mac) or registry (windows).
 */
void QC_ApplicationWindow::initSettings()
{
    RS_DEBUG->print("QC_ApplicationWindow::initSettings()");

    QSettings settings;

    settings.beginGroup("Geometry");
    restoreState(settings.value("StateOfWidgets", "").toByteArray());
    dock_areas.left->setChecked(settings.value("LeftDockArea", 0).toBool());
    dock_areas.right->setChecked(settings.value("RightDockArea", 0).toBool());
    dock_areas.top->setChecked(settings.value("TopDockArea", 0).toBool());
    dock_areas.bottom->setChecked(settings.value("BottomDockArea", 0).toBool());
    dock_areas.floating->setChecked(settings.value("FloatingDockwidgets", 0).toBool());
    settings.endGroup();

    settings.beginGroup("Widgets");

    int allow_style = settings.value("AllowStyle", 0).toInt();
    if (allow_style)
    {
        QString style = settings.value("Style", "").toString();
        QApplication::setStyle(QStyleFactory::create(style));
    }

    QString sheet_path = settings.value("StyleSheet", "").toString();
    if (loadStyleSheet(sheet_path))
        style_sheet_path = sheet_path;
    settings.endGroup();

    a_map["ViewDraft"]->setChecked(settings.value("Appearance/DraftMode", 0).toBool());
    // 隐藏所有停靠面板
    foreach(QDockWidget * dock, findChildren<QDockWidget*>()) {
        dock->hide();
    }
    // 检查 DefaultCustom 工具栏是否存在
    QToolBar* defaultCustomToolbar = nullptr;
    foreach(QToolBar* toolbar, findChildren<QToolBar*>()) {
        if (toolbar->objectName() == "DefaultCustom") {
            defaultCustomToolbar = toolbar;
            break;
        }
    }
    // 隐藏所有工具栏
    foreach(QToolBar* toolbar, findChildren<QToolBar*>()) {
        toolbar->hide();
    }
 
}


/**
 * Stores the global application settings to file or registry.
 */
void QC_ApplicationWindow::storeSettings() {
    RS_DEBUG->print("QC_ApplicationWindow::storeSettings()");

    if (RS_Settings::save_is_allowed)
    {
        RS_SETTINGS->beginGroup("/Geometry");
        RS_SETTINGS->writeEntry("/WindowWidth", width());
        RS_SETTINGS->writeEntry("/WindowHeight", height());
        RS_SETTINGS->writeEntry("/WindowX", x());
        RS_SETTINGS->writeEntry("/WindowY", y());
        RS_SETTINGS->writeEntry("/StateOfWidgets", QVariant (saveState()));
        RS_SETTINGS->writeEntry("/LeftDockArea", dock_areas.left->isChecked());
        RS_SETTINGS->writeEntry("/RightDockArea", dock_areas.right->isChecked());
        RS_SETTINGS->writeEntry("/TopDockArea", dock_areas.top->isChecked());
        RS_SETTINGS->writeEntry("/BottomDockArea", dock_areas.bottom->isChecked());
        RS_SETTINGS->writeEntry("/FloatingDockwidgets", dock_areas.floating->isChecked());
        RS_SETTINGS->endGroup();
        //save snapMode
        snapToolBar->saveSnapMode();
    }

    RS_DEBUG->print("QC_ApplicationWindow::storeSettings(): OK");
}

/**
 * Goes back to the previous menu or one step in the current action.
 */
void QC_ApplicationWindow::slotBack() {
    RS_GraphicView* graphicView = getGraphicView();
    if (graphicView) {
        graphicView->back();
    }
}

void QC_ApplicationWindow::slotKillAllActions() {
    RS_GraphicView* gv = getGraphicView();
    QC_MDIWindow* m = getMDIWindow();
    if (gv && m && m->getDocument()) {
        gv->killAllActions();

        RS_Selection s((RS_EntityContainer&)*m->getDocument(), gv);
        s.selectAll(false);
        RS_DIALOGFACTORY->updateSelectionWidget(
                    m->getDocument()->countSelected()
                    ,
                    m->getDocument()->totalSelectedLength()
                    );

        gv->redraw(RS2::RedrawAll);
    }
}


/**
 * Goes one step further in the current action.
 */
void QC_ApplicationWindow::slotEnter()
{
    RS_DEBUG->print("QC_ApplicationWindow::slotEnter(): begin\n");
    RS_GraphicView* graphicView = getGraphicView();
    if (graphicView)
    {
        graphicView->enter();
    }
    RS_DEBUG->print("QC_ApplicationWindow::slotEnter(): end\n");
}

/**
 * Sets the keyboard focus on the command line.
 */
void QC_ApplicationWindow::slotFocusCommandLine() {
//    if (commandWidget->isVisible()) {
        commandWidget->show();
        commandWidget->setFocus();
//    }
}


/**
 * Shows the given error on the command line.
 */
void QC_ApplicationWindow::slotError(const QString& msg) {
        commandWidget->appendHistory(msg);
}

/**
 * Hands focus back to the application window. In the rare event
 * of a escape press from the layer widget (e.g after switching desktops
 * in XP).
 */
void QC_ApplicationWindow::slotFocus() {
    setFocus();
}

void QC_ApplicationWindow::slotWindowActivated(int index){
    if(index < 0 || index >= mdiAreaCAD->subWindowList().size()) return;

    slotWindowActivated(mdiAreaCAD->subWindowList().at(index));

}

/**
 * Called when a document window was activated.
 */
void QC_ApplicationWindow::slotWindowActivated(QMdiSubWindow* w) {

    RS_DEBUG->print("QC_ApplicationWindow::slotWindowActivated begin");

    if(w==nullptr) {
        emit windowsChanged(false);
        activedMdiSubWindow=w;
        return;
    }

    if(w==activedMdiSubWindow) return;
    activedMdiSubWindow=w;

    QC_MDIWindow* m = qobject_cast<QC_MDIWindow*>(w);
    enableFileActions(m);

    if (m && m->getDocument()) {

        RS_DEBUG->print("QC_ApplicationWindow::slotWindowActivated: "
                        "document: %d", m->getDocument()->getId());

        bool showByBlock = m->getDocument()->rtti()==RS2::EntityBlock;

        layerWidget->setLayerList(m->getDocument()->getLayerList(),
                                  showByBlock);

        //coordinateWidget->setGraphic(m->getGraphic());

        blockWidget->setBlockList(m->getDocument()->getBlockList());

        // Update all inserts in this graphic (blocks might have changed):
        m->getDocument()->updateInserts();
        // whether to enable undo/redo buttons
        m->getDocument()->setGUIButtons();
        m->getGraphicView()->redraw();

        // set snapmode from snap toolbar
        //actionHandler->updateSnapMode();

        // set pen from pen toolbar
        slotPenChanged(penToolBar->getPen());

        pen_wiz->mdi_win = m;

        // update toggle button status:
        if (m->getGraphic()) {
            emit(gridChanged(m->getGraphic()->isGridOn()));
        }
        QG_GraphicView* view = m->getGraphicView();
        if (view)
        {
            actionHandler->set_view(view);
            actionHandler->set_document(m->getDocument());
            emit printPreviewChanged(view->isPrintPreview());
        }

        if(snapToolBar){
            actionHandler->slotSetSnaps(snapToolBar->getSnaps());
        }else {
            RS_DEBUG->print(RS_Debug::D_ERROR,"snapToolBar is nullptr\n");
        }
    }

    // show action options for active window only
    foreach (QMdiSubWindow* sw, mdiAreaCAD->subWindowList()) {
        QC_MDIWindow* sm = qobject_cast<QC_MDIWindow*>(sw);
        RS_ActionInterface* ai = sm->getGraphicView()->getCurrentAction();
        if (ai) {
            ai->hideOptions();
        }
    }
    if (m && m->getGraphicView()->getCurrentAction()) {
        m->getGraphicView()->getCurrentAction()->showOptions();
    }

    // Disable/Enable menu and toolbar items
    emit windowsChanged(m && m->getDocument());

    RS_DEBUG->print("RVT_PORT emit windowsChanged(true);");

    RS_DEBUG->print("QC_ApplicationWindow::slotWindowActivated end");
}

/**
 * Called when the menu 'windows' is about to be shown.
 * This is used to update the window list in the menu.
 */
void QC_ApplicationWindow::slotWindowsMenuAboutToShow() {

    RS_DEBUG->print( RS_Debug::D_NOTICE, "QC_ApplicationWindow::slotWindowsMenuAboutToShow");
	RS_SETTINGS->beginGroup("/WindowOptions");

	QMenu* menu;
	QAction* menuItem;
	bool tabbed = mdiAreaCAD->viewMode() == QMdiArea::TabbedView;
    windowsMenu->clear(); // this is a temporary menu; constructed on-demand

	menuItem = windowsMenu->addAction(tr("Ta&b mode"), this, SLOT(slotToggleTab()));
	menuItem->setCheckable(true);
	menuItem->setChecked(tabbed);

	menuItem = windowsMenu->addAction( tr("&Window mode"), this, SLOT(slotToggleTab()));
	menuItem->setCheckable(true);
	menuItem->setChecked(!tabbed);

	
	if (mdiAreaCAD->viewMode() == QMdiArea::TabbedView) {
		menu = new QMenu(tr("&Layout"), windowsMenu);
		windowsMenu->addMenu(menu);

		menuItem = menu->addAction(tr("Rounded"), this, SLOT(slotTabShapeRounded()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/TabShape") == RS2::Rounded);

		menuItem = menu->addAction(tr("Triangular"), this, SLOT(slotTabShapeTriangular()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/TabShape") == RS2::Triangular);

		menu->addSeparator();

		menuItem = menu->addAction(tr("North"), this, SLOT(slotTabPositionNorth()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/TabPosition") == RS2::North);

		menuItem = menu->addAction(tr("South"), this, SLOT(slotTabPositionSouth()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/TabPosition") == RS2::South);

		menuItem = menu->addAction(tr("East"), this, SLOT(slotTabPositionEast()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/TabPosition") == RS2::East);

		menuItem = menu->addAction(tr("West"), this, SLOT(slotTabPositionWest()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/TabPosition") == RS2::West);

	} else {
		menu = new QMenu(tr("&Arrange"), windowsMenu);
		windowsMenu->addMenu(menu);

		menuItem = menu->addAction(tr("&Maximized"), this, SLOT(slotSetMaximized()));
		menuItem->setCheckable(true);
		menuItem->setChecked(RS_SETTINGS->readNumEntry("/SubWindowMode") == RS2::Maximized);

        menu->addAction(tr("&Cascade"), this, SLOT(slotCascade()));
        menu->addAction(tr("&Tile"), this, SLOT(slotTile()));
        menu->addAction(tr("Tile &Vertically"), this, SLOT(slotTileVertical()));
        menu->addAction(tr("Tile &Horizontally"), this, SLOT(slotTileHorizontal()));
	}
	

	RS_SETTINGS->endGroup();
        
    windowsMenu->addSeparator();
    QMdiSubWindow* active= mdiAreaCAD->activeSubWindow();






    for (int i=0; i< window_list.size(); ++i) {
        QString title = window_list.at(i)->windowTitle();
        if (title.contains("[*]")) { // modification mark placeholder
            int idx = title.lastIndexOf("[*]");
            if (window_list.at(i)->isWindowModified()) {
                title.replace(idx, 3, "*");
            } else {
                title.remove(idx, 3);
            }
        }
        QAction *id = windowsMenu->addAction(title,
                                         this, SLOT(slotWindowsMenuActivated(bool)));
        id->setCheckable(true);
        id->setData(i);
        id->setChecked(window_list.at(i)==active);
    }
}

/**
 * Called when the user selects a document window from the
 * window list.
 */
void QC_ApplicationWindow::slotWindowsMenuActivated(bool /*id*/) {
    RS_DEBUG->print("QC_ApplicationWindow::slotWindowsMenuActivated");

    int ii = qobject_cast<QAction*>(sender())->data().toInt();
    QMdiSubWindow* w = mdiAreaCAD->subWindowList().at(ii);
    if (w) {
        if(w==mdiAreaCAD->activeSubWindow()) {
            return;
        }

		doActivate(w);
    }
}

/**
 * Cascade MDI windows
 */
void QC_ApplicationWindow::slotTile() {
	doArrangeWindows(RS2::Tile, true);
        mdiAreaCAD->tileSubWindows();
        slotZoomAuto();
}
//auto zoom the graphicView of sub-windows
void QC_ApplicationWindow::slotZoomAuto() {
    QList<QMdiSubWindow *> windows = mdiAreaCAD->subWindowList();
    for(int i=0;i<windows.size();i++){
        QMdiSubWindow *window = windows.at(i);
        qobject_cast<QC_MDIWindow*>(window)->slotZoomAuto();
    }
}

/**
 * Cascade MDI windows
 */
void QC_ApplicationWindow::slotCascade() {
//    mdiAreaCAD->cascadeSubWindows();
//return;
	doArrangeWindows(RS2::Cascade, true);
	QList<QMdiSubWindow *> windows = mdiAreaCAD->subWindowList();
    switch(windows.size()){
    case 1:
        //mdiAreaCAD->tileSubWindows();
		slotTile();
    case 0:
        return;
    default: {
        QMdiSubWindow* active=mdiAreaCAD->activeSubWindow();
        for (int i=0; i<windows.size(); ++i) {
            windows.at(i)->showNormal();
        }
        mdiAreaCAD->cascadeSubWindows();
        //find displacement by linear-regression
        double mi=0.,mi2=0.,mw=0.,miw=0.,mh=0.,mih=0.;
        for (int i=0; i<windows.size(); ++i) {
                mi += i;
                mi2 += i*i;
                double w=windows.at(i)->pos().x();
                mw += w;
                miw += i*w;
                double h=windows.at(i)->pos().y();
                mh += h;
                mih += i*h;
        }
        mi2 *= windows.size();
        miw *= windows.size();
        mih *= windows.size();
        double d=1./(mi2 - mi*mi);
        double disX=(miw-mi*mw)*d;
        double disY=(mih-mi*mh)*d;
        //End of Linear Regression
        //
        QMdiSubWindow *window = windows.first();
        QRect geo=window->geometry();
        QRect frame=window->frameGeometry();
//        std::cout<<"Frame=:"<<( frame.height() - geo.height())<<std::endl;
        int width= mdiAreaCAD->width() -( frame.width() - geo.width())- disX*(windows.size()-1);
        int height= mdiAreaCAD->height() -( frame.width() - geo.width())- disY*(windows.size()-1);
        if(width<=0 || height<=0) {
            return;
        }
        for (int i=0; i<windows.size(); ++i) {
            window = windows.at(i);
//            std::cout<<"window:("<<i<<"): pos()="<<(window->pos().x())<<" "<<(window->pos().y())<<std::endl;
            geo=window->geometry();
//            if(i==active) {
//                    window->setWindowState(Qt::WindowActive);
//            }else{
//                    window->setWindowState(Qt::WindowNoState);
//            }
            window->setGeometry(geo.x(),geo.y(),width,height);
            qobject_cast<QC_MDIWindow*>(window)->slotZoomAuto();
        }
        mdiAreaCAD->setActiveSubWindow(active);
//        windows.at(active)->activateWindow();
//        windows.at(active)->raise();
//        windows.at(active)->setFocus();
    }
    }
}


/**
 * Tiles MDI windows horizontally.
 */
void QC_ApplicationWindow::slotTileHorizontal() {

    RS_DEBUG->print("QC_ApplicationWindow::slotTileHorizontal");
	doArrangeWindows(RS2::TileHorizontal, true);
	
    // primitive horizontal tiling
    QList<QMdiSubWindow *> windows = mdiAreaCAD->subWindowList();
    if (windows.count()<=1) {
		slotTile();
        return;
    }
    for (int i=0; i<windows.count(); ++i) {
        QMdiSubWindow *window = windows.at(i);
        window->lower();
        window->showNormal();
    }
    int heightForEach = mdiAreaCAD->height() / windows.count();
    int y = 0;
    for (int i=0; i<windows.count(); ++i) {
        QMdiSubWindow *window = windows.at(i);
        int preferredHeight = window->minimumHeight()
                              + window->parentWidget()->baseSize().height();
        int actHeight = qMax(heightForEach, preferredHeight);

        window->setGeometry(0, y, mdiAreaCAD->width(), actHeight);
         qobject_cast<QC_MDIWindow*>(window)->slotZoomAuto();
        y+=actHeight;
    }
    mdiAreaCAD->activeSubWindow()->raise();
}


/**
 * Tiles MDI windows vertically.
 */
void QC_ApplicationWindow::slotTileVertical() {
	
    RS_DEBUG->print("QC_ApplicationWindow::slotTileVertical()");
	doArrangeWindows(RS2::TileVertical, true);
	
    // primitive horizontal tiling
    QList<QMdiSubWindow *> windows = mdiAreaCAD->subWindowList();
    if (windows.count()<=1) {
		slotTile();
        return;
    }
    for (int i=0; i<windows.count(); ++i) {
        QMdiSubWindow *window = windows.at(i);
        window->lower();
        window->showNormal();
    }
    int widthForEach = mdiAreaCAD->width() / windows.count();
    int x = 0;
    for (int i=0; i<windows.count(); ++i) {
        QMdiSubWindow *window = windows.at(i);
        int preferredWidth = window->minimumWidth()
                              + window->parentWidget()->baseSize().width();
        int actWidth = qMax(widthForEach, preferredWidth);

        window->setGeometry(x, 0, actWidth, mdiAreaCAD->height());
         qobject_cast<QC_MDIWindow*>(window)->slotZoomAuto();
        x+=actWidth;
    }
    mdiAreaCAD->activeSubWindow()->raise();
}

void QC_ApplicationWindow::slotSetMaximized()
{
	doArrangeWindows(RS2::Maximized);
}

void QC_ApplicationWindow::slotTabShapeRounded()
{
	setTabLayout(RS2::Rounded, RS2::AnyPosition);
}

void QC_ApplicationWindow::slotTabShapeTriangular()
{
	setTabLayout(RS2::Triangular, RS2::AnyPosition);
}

void QC_ApplicationWindow::slotTabPositionNorth()
{
	setTabLayout(RS2::AnyShape, RS2::North);
}

void QC_ApplicationWindow::slotTabPositionSouth()
{
	setTabLayout(RS2::AnyShape, RS2::South);
}

void QC_ApplicationWindow::slotTabPositionEast()
{
	setTabLayout(RS2::AnyShape, RS2::East);
}

void QC_ApplicationWindow::slotTabPositionWest()
{
	setTabLayout(RS2::AnyShape, RS2::West);
}

/**
 * toggles between subwindow and tab mode for the MdiArea
 */
void QC_ApplicationWindow::slotToggleTab()
{
    if (mdiAreaCAD->viewMode() == QMdiArea::SubWindowView)
    {
		RS_SETTINGS->beginGroup("Startup");
		RS_SETTINGS->writeEntry("/TabMode", 1);
		RS_SETTINGS->endGroup();
        mdiAreaCAD->setViewMode(QMdiArea::TabbedView);
		QList<QTabBar *> tabBarList = mdiAreaCAD->findChildren<QTabBar*>();
		QTabBar *tabBar = tabBarList.at(0);
		if (tabBar) {
			tabBar->setExpanding(false);
		}
        QList<QMdiSubWindow *> windows = mdiAreaCAD->subWindowList();
        QMdiSubWindow* active=mdiAreaCAD->activeSubWindow();
        for(int i=0;i<windows.size();i++){
            QMdiSubWindow* m=windows.at(i);
            m->hide();
            if(m!=active){
                m->lower();
            }else{
                m->raise();
            }
			slotSetMaximized();
            qobject_cast<QC_MDIWindow*>(m)->slotZoomAuto();
        }
    }
    else
    {
		RS_SETTINGS->beginGroup("Startup");
		RS_SETTINGS->writeEntry("/TabMode", 0);
		RS_SETTINGS->endGroup();
        mdiAreaCAD->setViewMode(QMdiArea::SubWindowView);
		doArrangeWindows(RS2::CurrentMode);
    }
}

/**
 * Called when something changed in the pen tool bar
 * (e.g. color, width, style).
 */
void QC_ApplicationWindow::slotPenChanged(RS_Pen pen) {
    RS_DEBUG->print("QC_ApplicationWindow::slotPenChanged() begin");

    RS_DEBUG->print("Setting active pen...");

    QC_MDIWindow* m = getMDIWindow();
    if (m) {
        m->slotPenChanged(pen);
    }

    RS_DEBUG->print("QC_ApplicationWindow::slotPenChanged() end");
}

/**
 * Called when something changed in the snaps tool bar
 */
void QC_ApplicationWindow::slotSnapsChanged(RS_SnapMode snaps) {
    RS_DEBUG->print("QC_ApplicationWindow::slotSnapsChanged() begin");

    actionHandler->slotSetSnaps(snaps);
}



/**
 * Creates a new MDI window with the given document or a new
 *  document if 'doc' is nullptr.
 */

QC_MDIWindow* QC_ApplicationWindow::slotFileNew(RS_Document* doc) {

    RS_DEBUG->print("QC_ApplicationWindow::slotFileNew() begin");

    QSettings settings;
    static int id = 0;
    id++;

    statusBar()->showMessage(tr("Creating new file..."));

    RS_DEBUG->print("  creating MDI window");

    QC_MDIWindow* w = new QC_MDIWindow(doc, mdiAreaCAD, 0);

    window_list << w;

    // 设置子窗口的窗口标志，移除系统按钮
    Qt::WindowFlags flags = w->windowFlags();
    flags &= ~Qt::WindowSystemMenuHint;      // 移除系统菜单
    flags &= ~Qt::WindowMinMaxButtonsHint;   // 移除最小化/最大化按钮
    flags &= ~Qt::WindowCloseButtonHint;    // 移除关闭按钮
    flags &= ~Qt::WindowTitleHint;       // 移除标题栏
    flags |= Qt::FramelessWindowHint;   // 无边框窗口
    w->setWindowFlags(flags);
   
    RS_SETTINGS->beginGroup("/Appearance");
    int aa = RS_SETTINGS->readNumEntry("/Antialiasing", 0);
    int scrollbars = RS_SETTINGS->readNumEntry("/ScrollBars", 1);
    int cursor_hiding = RS_SETTINGS->readNumEntry("/cursor_hiding", 0);
    RS_SETTINGS->endGroup();

    QG_GraphicView* view = w->getGraphicView();

    view->setAntialiasing(aa);
    view->setCursorHiding(cursor_hiding);
    view->device = settings.value("Hardware/Device", "Mouse").toString();
    if (scrollbars) view->addScrollbars();

    settings.beginGroup("Activators");
    auto activators = settings.childKeys();
    settings.endGroup();

    foreach (auto activator, activators)
    {
        auto menu_name = settings.value("Activators/" + activator).toString();
        auto path = QString("CustomMenus/%1").arg(menu_name);
        auto a_list = settings.value(path).toStringList();
        auto menu = new QMenu(activator, view);
        menu->setObjectName(menu_name);
        foreach (auto key, a_list)
        {
            menu->addAction(a_map[key]);
        }
        view->setMenu(activator, menu);
    }

    connect(view, SIGNAL(gridStatusChanged(const QString&)),
            this, SLOT(updateGridStatus(const QString&)));

    actionHandler->set_view(view);
    actionHandler->set_document(w->getDocument());

    connect(w, SIGNAL(signalClosing(QC_MDIWindow*)),
            this, SLOT(slotFileClosing(QC_MDIWindow*)));

    if (w->getDocument()->rtti()==RS2::EntityBlock) {
        w->setWindowTitle(tr("Block '%1'").arg(((RS_Block*)(w->getDocument()))->getName()) + "[*]");
    } else {
        w->setWindowTitle(tr("unnamed document %1").arg(id) + "[*]");
    }

    //check for draft mode

    if (settings.value("Appearance/DraftMode", 0).toBool())
    {
        QString draft_string = " ["+tr("Draft Mode")+"]";
        w->getGraphicView()->setDraftMode(true);
        QString title = w->windowTitle();
        w->setWindowTitle(title + draft_string);
    }

    w->setWindowIcon(QIcon(":/main/document.png"));

    RS_DEBUG->print("  adding listeners");
    RS_Graphic* graphic = w->getDocument()->getGraphic();

    if(layerWidget) {
        layerWidget->setLayerList(w->getDocument()->getLayerList(), false);
    }

    if(blockWidget) {
        blockWidget->setBlockList(w->getDocument()->getBlockList());
    }
    if (graphic) {
        // Link the graphic's layer list to the pen tool bar
        graphic->addLayerListListener(penToolBar);
        // Link the layer list to the layer widget
        graphic->addLayerListListener(layerWidget);

        // Link the block list to the block widget
        graphic->addBlockListListener(blockWidget);
    }
	// Link the dialog factory to the coordinate widget:
	//if( coordinateWidget){
	//	coordinateWidget->setGraphic(graphic );
	//}
	// Link the dialog factory to the mouse widget:
	QG_DIALOGFACTORY->setMouseWidget(mouseWidget);
	//QG_DIALOGFACTORY->setCoordinateWidget(coordinateWidget);
	QG_DIALOGFACTORY->setSelectionWidget(selectionWidget);
	// Link the dialog factory to the option widget:
	//QG_DIALOGFACTORY->setOptionWidget(optionWidget);
	// Link the dialog factory to the command widget:
	QG_DIALOGFACTORY->setCommandWidget(commandWidget);

    mdiAreaCAD->addSubWindow(w);

    RS_DEBUG->print("  showing MDI window");
	doActivate(w);
	doArrangeWindows(RS2::CurrentMode);
    statusBar()->showMessage(tr("New Drawing created."), 2000);

    layerWidget->activateLayer(0);

    RS_DEBUG->print("QC_ApplicationWindow::slotFileNew() OK");

    return w;
}

/**
 * Helper function for Menu file -> New & New....
 */
bool QC_ApplicationWindow::slotFileNewHelper(QString fileName, QC_MDIWindow* w) {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewHelper()");
    bool ret = false;
    RS2::FormatType type = RS2::FormatDXFRW;

    QApplication::setOverrideCursor( QCursor(Qt::WaitCursor) );

    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewHelper: creating new doc window");
    /*QC_MDIWindow* */ w = slotFileNew();
    qApp->processEvents(QEventLoop::AllEvents, 1000);

    // link the layer widget to the new document:
    layerWidget->setLayerList(w->getDocument()->getLayerList(), false);
    // link the block widget to the new document:
    blockWidget->setBlockList(w->getDocument()->getBlockList());
    // link coordinate widget to graphic
   // coordinateWidget->setGraphic(w->getGraphic());

    qApp->processEvents(QEventLoop::AllEvents, 1000);

    // loads the template file in the new view:
    if (!fileName.isEmpty()) {
        ret = w->slotFileNewTemplate(fileName, type);
    } else
        //new without template is OK;
        ret = true;

    if (!ret) {
        // error loading template
        QApplication::restoreOverrideCursor();
        return ret;
    }

    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewHelper: load Template: OK");

    layerWidget->slotUpdateLayerList();

    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewHelper: update coordinate widget");
    // update coordinate widget format:
    RS_DIALOGFACTORY->updateCoordinateWidget(RS_Vector(0.0,0.0),
                                             RS_Vector(0.0,0.0), true);

    if (!fileName.isEmpty()) {
        QString message=tr("New document from template: ")+fileName;
        commandWidget->appendHistory(message);
        statusBar()->showMessage(message, 2000);
    }
    if (w->getGraphic()) {
        emit(gridChanged(w->getGraphic()->isGridOn()));
    }

    QApplication::restoreOverrideCursor();
    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewHelper() OK");
    return ret;
}

/**
 * Menu file -> New (using a predefined Template).
 */
void QC_ApplicationWindow::slotFileNewNew() {
    // 输出调试信息，标记函数开始执行
    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewNew()");

    // 注释掉的代码：原本尝试设置默认文件格式为DXF
    // RS2::FormatType type = RS2::FormatDXFRW;

    // 从应用程序设置中读取模板文件路径
    RS_SETTINGS->beginGroup("/Paths");           // 进入设置中的路径分组
    QString fileName = RS_SETTINGS->readEntry("/Template");  // 读取模板文件路径
    RS_SETTINGS->endGroup();                     // 结束设置分组

    /* 注释掉的模板文件检查逻辑：
    QFileInfo finfo(fileName);
    if (!fileName.isEmpty() && finfo.isReadable()) {
        // 如果模板文件存在且可读，使用模板创建新文档
        slotFileNewTemplate(fileName, RS2::FormatDXFRW);
        return;
    }
    */

    // 调用辅助函数创建新文档
    if (!slotFileNewHelper(fileName)) {
        // 如果创建新文档失败，输出错误信息
        RS_DEBUG->print("QC_ApplicationWindow::slotFileNewNew: load Template failed");
    }
    else {
        // 创建成功，输出调试信息
        RS_DEBUG->print("QC_ApplicationWindow::slotFileNewNew() OK");
    }
}

/**
 * Menu file -> New with Template.
 */
void QC_ApplicationWindow::slotFileNewTemplate() {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewTemplate()");

    RS2::FormatType type = RS2::FormatDXFRW;
    QG_FileDialog dlg(this);
    QString fileName = dlg.getOpenFile(&type);

    if (fileName.isEmpty()) {
           statusBar()->showMessage(tr("Select Template aborted"), 2000);
           return;
       }

    RS_DEBUG->print("QC_ApplicationWindow::slotFileNewTemplate: creating new doc window");
    // Create new document window:
    QMdiSubWindow* old=activedMdiSubWindow;
    QRect geo;
    bool maximized=false;
    if(old != nullptr ) {//save old geometry
        geo=old->geometry();
        maximized=old->isMaximized();
    }
    QC_MDIWindow* w =nullptr;
	if (!slotFileNewHelper(fileName, w)) {
        // error
        QString msg=tr("Cannot open the file\n%1\nPlease "
                       "check the permissions.").arg(fileName);
        commandWidget->appendHistory(msg);
        QMessageBox::information(this, QMessageBox::tr("Warning"),
                                 msg,QMessageBox::Ok);
        //file opening failed, clean up QC_MDIWindow and QMdiSubWindow
        if (w) {
            slotFilePrintPreview(false);
            doClose(w); //force closing, without asking user for confirmation
        }
        QMdiSubWindow* active=mdiAreaCAD->currentSubWindow();
        activedMdiSubWindow=nullptr; //to allow reactivate the previous active
        if( active){//restore old geometry
            mdiAreaCAD->setActiveSubWindow(active);
            active->raise();
            active->setFocus();
            if(old==nullptr || maximized){
                active->showMaximized();
            }else{
                active->setGeometry(geo);
            }
        }
        RS_DEBUG->print("QC_ApplicationWindow::slotFileNewTemplate: load Template failed");
    } else
        RS_DEBUG->print("QC_ApplicationWindow::slotFileNewTemplate() OK");
}


/**
 * Menu file -> open.
 */
void QC_ApplicationWindow::slotFileOpen() {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen()");

    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen() 001");
    RS2::FormatType type = RS2::FormatUnknown;
    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen() 002");
    QG_FileDialog dlg(this);
    QString fileName = dlg.getOpenFile(&type);

    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen() 003");
    slotFileOpen(fileName, type);
    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen(): OK");
} 


/**
 *
 *	\brief	- Format a string that hold a file name path
 *						  such a way that it can displayed on the
 *						  windows title bar.
 *
 *	\author		Claude Sylvain
 *	\date			30 July 2011
 *	Last modified:
 *
 *	Parameters:		const QString &qstring_in:
 *							String to format (in).
 *
 *						QString &qstring_out:
 *							Formatted string (out).
 *
 *	Returns:			void
 *	*/

QString QC_ApplicationWindow::
    format_filename_caption(const QString &qstring_in)
{
	QFileInfo info = QFileInfo(qstring_in);
	return info.fileName(); // don't include the full path
}

/*	*
 *	Function name:
 *	Description:
 *	Author(s):		..., Claude Sylvain
 *	Created:			?
 *	Last modified:	30 July 2011
 *
 *	Parameters:		const QString& fileName:
 *							...
 *
 *						RS2::FormatType type:
 *							...
 *
 *	Returns:			void
 *	Notes:			Menu file -> open.
 *	*/
void QC_ApplicationWindow::
        slotFileOpen(const QString& fileName, RS2::FormatType type)
{
    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen(..)");

    QSettings settings;

    QApplication::setOverrideCursor( QCursor(Qt::WaitCursor) );

    if ( QFileInfo(fileName).exists())
         {
        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: creating new doc window");
        if (openedFiles.indexOf(fileName) >=0) {
            QString message=tr("Warning: File already opened : ")+fileName;
            commandWidget->appendHistory(message);
            statusBar()->showMessage(message, 2000);
        }
        // Create new document window:
		QMdiSubWindow* old=activedMdiSubWindow;
        QRect geo;
        bool maximized=false;

        QC_MDIWindow* w = slotFileNew(nullptr);
        // RVT_PORT qApp->processEvents(1000);
        qApp->processEvents(QEventLoop::AllEvents, 1000);

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: linking layer list");
        // link the layer widget to the new document:
        layerWidget->setLayerList(w->getDocument()->getLayerList(), false);
        // link the block widget to the new document:
        blockWidget->setBlockList(w->getDocument()->getBlockList());
        // link coordinate widget to graphic
        //coordinateWidget->setGraphic(w->getGraphic());

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: open file");

        qApp->processEvents(QEventLoop::AllEvents, 1000);

        if(old != nullptr) {//save old geometry
            geo=old->geometry();
            maximized=old->isMaximized();
        }

        // open the file in the new view:
        bool success=false;
        if (QFileInfo( fileName).exists()) {
            success = w->slotFileOpen( fileName, type);
        }
        else {
            QString msg=tr("Cannot open the file\n%1\nPlease "
                           "check its existence and permissions.")
                    .arg( fileName);
            commandWidget->appendHistory( msg);
            QMessageBox::information( this, QMessageBox::tr("Warning"), msg, QMessageBox::Ok);
        }
        if (!success) {
               // error
               QApplication::restoreOverrideCursor();

               //file opening failed, clean up QC_MDIWindow and QMdiSubWindow
               slotFilePrintPreview(false);
               doClose(w); //force closing, without asking user for confirmation
               return;
        }

		slotWindowActivated(w);

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: open file: OK");

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: update recent file menu: 1");

        // update recent files menu:
        recentFiles->add(fileName);
        openedFiles.push_back(fileName);
        layerWidget->slotUpdateLayerList();
        auto graphic = w->getGraphic();
        if (graphic)
        {
            if (int objects_removed = graphic->clean())
            {
                auto msg = QObject::tr("Invalid objects removed:");
                commandWidget->appendHistory(msg + " " + QString::number(objects_removed));
            }
           emit(gridChanged(graphic->isGridOn()));
        }

        recentFiles->updateRecentFilesMenu();

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: set caption");


                /*	Format and set caption.
                 *	----------------------- */
        w->setWindowTitle(format_filename_caption(fileName) + "[*]");

		if (mdiAreaCAD->viewMode() == QMdiArea::TabbedView) {
			QList<QTabBar *> tabBarList = mdiAreaCAD->findChildren<QTabBar*>();
			QTabBar *tabBar = tabBarList.at(0);
			if (tabBar) {
				tabBar->setExpanding(false);
				tabBar->setTabToolTip(tabBar->currentIndex(), fileName);
			}
		}
		else
			doArrangeWindows(RS2::CurrentMode);

		RS_SETTINGS->beginGroup("/CADPreferences");
		if (RS_SETTINGS->readNumEntry("/AutoZoomDrawing"))
			w->getGraphicView()->zoomAuto(false);
		RS_SETTINGS->endGroup();

        if (settings.value("Appearance/DraftMode", 0).toBool())
        {
            QString draft_string = " ["+tr("Draft Mode")+"]";
            w->getGraphicView()->setDraftMode(true);
            w->getGraphicView()->redraw();
            QString title = w->windowTitle();
            w->setWindowTitle(title + draft_string);
        }

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: set caption: OK");

        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: update coordinate widget");
        // update coordinate widget format:
        RS_DIALOGFACTORY->updateCoordinateWidget(RS_Vector(0.0,0.0),
                RS_Vector(0.0,0.0),
                true);
        RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen: update coordinate widget: OK");

        QString message=tr("Loaded document: ")+fileName;
        commandWidget->appendHistory(message);
        statusBar()->showMessage(message, 2000);

	} else {
		QG_DIALOGFACTORY->commandMessage(tr("File '%1' does not exist. Opening aborted").arg(fileName));
        statusBar()->showMessage(tr("Opening aborted"), 2000);
    }

    QApplication::restoreOverrideCursor();
    RS_DEBUG->print("QC_ApplicationWindow::slotFileOpen(..) OK");
}

void QC_ApplicationWindow::slotFileOpen(const QString& fileName) {
    slotFileOpen(fileName, RS2::FormatUnknown);
}


/**
 * Menu file -> save.
 */
void QC_ApplicationWindow::slotFileSave() {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileSave()");

	if (doSave(getMDIWindow()))
		recentFiles->updateRecentFilesMenu();
}



/**
 * Menu file -> save as.
 */
void QC_ApplicationWindow::slotFileSaveAs() {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileSaveAs()");
	if (doSave(getMDIWindow(), true))
		recentFiles->updateRecentFilesMenu();
}

bool QC_ApplicationWindow::slotFileSaveAll()
{
	QC_MDIWindow* current = getMDIWindow();
    bool result {true};
	for (auto w : window_list) {
		if (w && w->getDocument()->isModified()) {
			result = doSave(w);
			if (!result) {
				statusBar()->showMessage(tr("Save All cancelled"), 2000);
				break;
			}
		}
	}
	doActivate(current);
	recentFiles->updateRecentFilesMenu();
	return result;
}



/**
 * Autosave.
 */
void QC_ApplicationWindow::slotFileAutoSave() {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileAutoSave()");

    statusBar()->showMessage(tr("Auto-saving drawing..."), 2000);

    QC_MDIWindow* w = getMDIWindow();
    if (w) {
        bool cancelled;
        if (w->slotFileSave(cancelled, true)) {
            // auto-save cannot be cancelled by user, so the
            // "cancelled" parameter is a dummy
            statusBar()->showMessage(tr("Auto-saved drawing"), 2000);
        } else {
            // error
            autosaveTimer->stop();
            QMessageBox::information(this, QMessageBox::tr("Warning"),
                                     tr("Cannot auto-save the file\n%1\nPlease "
                                        "check the permissions.\n"
                                        "Auto-save disabled.")
                                     .arg(w->getDocument()->getAutoSaveFilename()),
                                     QMessageBox::Ok);
            statusBar()->showMessage(tr("Auto-saving failed"), 2000);
        }
    }
}



/**
 * Menu file -> export.
 */
void QC_ApplicationWindow::slotFileExport() {
    RS_DEBUG->print("QC_ApplicationWindow::slotFileExport()");

    statusBar()->showMessage(tr("Exporting drawing..."), 2000);

    QC_MDIWindow* w = getMDIWindow();
    QString fn;
    if (w) {

        // read default settings:
        RS_SETTINGS->beginGroup("/Export");
        QString defDir = RS_SETTINGS->readEntry("/ExportImage", RS_SYSTEM->getHomeDir());
		QString defFilter = RS_SETTINGS->readEntry("/ExportImageFilter",
													   QString("%1 (%2)(*.%2)").arg(QG_DialogFactory::extToFormat("png")).arg("png"));
        RS_SETTINGS->endGroup();

        bool cancel = false;

        QStringList filters;
        QList<QByteArray> supportedImageFormats = QImageWriter::supportedImageFormats();
        supportedImageFormats.push_back("svg"); // add svg

        for (QString format: supportedImageFormats) {
            format = format.toLower();
            QString st;
            if (format=="jpeg" || format=="tiff") {
                // Don't add the aliases
			} else {
				st = QString("%1 (%2)(*.%2)")
						.arg(QG_DialogFactory::extToFormat(format))
						.arg(format);
            }
            if (st.length()>0)
                filters.push_back(st);
        }
        // revise list of filters
        filters.removeDuplicates();
        filters.sort();

        // set dialog options: filters, mode, accept, directory, filename
        QFileDialog fileDlg(this, tr("Export as"));

        fileDlg.setNameFilters(filters);
        fileDlg.setFileMode(QFileDialog::AnyFile);
        fileDlg.selectNameFilter(defFilter);
        fileDlg.setAcceptMode(QFileDialog::AcceptSave);
        fileDlg.setDirectory(defDir);
        fn = QFileInfo(w->getDocument()->getFilename()).baseName();
        if(fn==nullptr)
            fn = "unnamed";
        fileDlg.selectFile(fn);

        if (fileDlg.exec()==QDialog::Accepted) {
            QStringList files = fileDlg.selectedFiles();
            if (!files.isEmpty())
                fn = files[0];
            cancel = false;
        } else {
            cancel = true;
        }

        // store new default settings:
        if (!cancel) {
            RS_SETTINGS->beginGroup("/Export");
            RS_SETTINGS->writeEntry("/ExportImage", QFileInfo(fn).absolutePath());
            RS_SETTINGS->writeEntry("/ExportImageFilter",
                                    fileDlg.selectedNameFilter());
            RS_SETTINGS->endGroup();

            // find out extension:

            QString filter = fileDlg.selectedNameFilter();
            QString format = "";
            int i = filter.indexOf("(*.");
            if (i!=-1) {
                int i2 = filter.indexOf(QRegExp("[) ]"), i);
                format = filter.mid(i+3, i2-(i+3));
                format = format.toUpper();
            }

            // append extension to file:
            if (!QFileInfo(fn).fileName().contains(".")) {
                fn.push_back("." + format.toLower());
            }

            // show options dialog:
            QG_ImageOptionsDialog dlg(this);
            w->getGraphic()->calculateBorders();
            dlg.setGraphicSize(w->getGraphic()->getSize()*2.);
            if (dlg.exec()) {
                bool ret = slotFileExport(fn, format, dlg.getSize(), dlg.getBorders(),
                            dlg.isBackgroundBlack(), dlg.isBlackWhite());
                if (ret) {
                    QString message = tr("Exported: %1").arg(fn);
                    statusBar()->showMessage(message, 2000);
                    commandWidget->appendHistory(message);
                }
            }
        }
    }

}



/**
 * Exports the drawing as a bitmap or another picture format.
 *
 * @param name File name.
 * @param format File format (e.g. "png")
 * @param size Size of the bitmap in pixel
 * @param black true: Black background, false: white
 * @param bw true: black/white export, false: color
 */
bool QC_ApplicationWindow::slotFileExport(const QString& name,
        const QString& format, QSize size, QSize borders, bool black, bool bw) {

    QC_MDIWindow* w = getMDIWindow();
    if (w==nullptr) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
                "QC_ApplicationWindow::slotFileExport: "
                "no window opened");
        return false;
    }

    RS_Graphic* graphic = w->getDocument()->getGraphic();
    if (graphic==nullptr) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
                "QC_ApplicationWindow::slotFileExport: "
                "no graphic");
        return false;
    }

    statusBar()->showMessage(tr("Exporting..."));
    QApplication::setOverrideCursor( QCursor(Qt::WaitCursor) );

    bool ret = false;
    // set vars for normal pictures and vectors (svg)
    QPixmap* picture = new QPixmap(size);

    QSvgGenerator* vector = new QSvgGenerator();

    // set buffer var
    QPaintDevice* buffer;

    if(format.toLower() != "svg") {
        buffer = picture;
    } else {
        vector->setSize(size);
        vector->setViewBox(QRectF(QPointF(0,0),size));
        vector->setFileName(name);
        buffer = vector;
    }

    // set painter with buffer
    RS_PainterQt painter(buffer);

    if (black) {
        painter.setBackground( Qt::black);
        if (bw) {
            painter.setDrawingMode( RS2::ModeWB);
        }
    }
    else {
        painter.setBackground(Qt::white);
        if (bw) {
            painter.setDrawingMode( RS2::ModeBW);
        }
    }

    painter.eraseRect(0,0, size.width(), size.height());

	RS_StaticGraphicView gv(size.width(), size.height(), &painter, &borders);
    if (black) {
		gv.setBackground(Qt::black);
    } else {
		gv.setBackground(Qt::white);
    }
    gv.setContainer(graphic);
    gv.zoomAuto(false);
	gv.drawEntity(&painter, gv.getContainer());

    // end the picture output
    if(format.toLower() != "svg")
    {
        // RVT_PORT QImageIO iio;
        QImageWriter iio;
        QImage img = picture->toImage();
        // RVT_PORT iio.setImage(img);
        iio.setFileName(name);
        iio.setFormat(format.toLatin1());
        // RVT_PORT if (iio.write()) {
        if (iio.write(img)) {
            ret = true;
        }
//        QString error=iio.errorString();
    }
    QApplication::restoreOverrideCursor();

    // GraphicView deletes painter
    painter.end();
    // delete vars
    delete picture;
    delete vector;

    if (ret) {
        statusBar()->showMessage(tr("Export complete"), 2000);
    } else {
        statusBar()->showMessage(tr("Export failed!"), 2000);
    }

    return ret;
}


/**
 * Called when a sub window is about to close. 
 * If modified, show the Save/Close/Cancel dialog, then do the request.
 * If a save is needed but the user cancels, the window is not closed.
 */
void QC_ApplicationWindow::slotFileClosing(QC_MDIWindow* win)
{
    RS_DEBUG->print("QC_ApplicationWindow::slotFileClosing()");
   
	bool cancel = false;
	bool hasParent = win->getParentWindow() != nullptr;
	if (win && win->getDocument()->isModified() && !hasParent) {
		switch (showCloseDialog(win)) {
		case QG_ExitDialog::Save:
			cancel = !doSave(win);
			break;
		case QG_ExitDialog::Cancel:
			cancel = true;
			break;
		}
	}
	if (!cancel)
	{
		doClose(win);
		doArrangeWindows(RS2::CurrentMode);
	}
}

/**
 * File > Close All - loop through all open windows, and close them.
 * Prompt user to save changes for modified documents.  If the user cancels
 * the remaining unsaved documents will not be closed.
 *
 * @return true success
 * @return false the user cancelled.
 */
bool QC_ApplicationWindow::slotFileCloseAll()
{
	bool cancel(false), closeAll(false), hasParent(false);
	for (auto w : window_list) if (w) {

		hasParent = w->getParentWindow() != nullptr;

		if (w->getDocument()->isModified() && !hasParent && !closeAll) {
			doActivate(w);
			switch (showCloseDialog(w, window_list.count() > 1)) {
			case QG_ExitDialog::Close:
				closeAll = true;
				break;
			case QG_ExitDialog::SaveAll:
				closeAll = slotFileSaveAll();
				break;
			case QG_ExitDialog::Save:
				cancel = !doSave(w);
				break;
			case QG_ExitDialog::Cancel:
				cancel = true;
				break;
			}
		}
		if (cancel) {
			statusBar()->showMessage(tr("Close All cancelled"), 2000);
			return false;
		}

		doClose(w);
		doArrangeWindows(RS2::CurrentMode);
	}
	return true;
}


/**
 * Menu file -> print.
 */
void QC_ApplicationWindow::slotFilePrint(bool printPDF) {
    RS_DEBUG->print(RS_Debug::D_INFORMATIONAL,"QC_ApplicationWindow::slotFilePrint(%s)", printPDF ? "PDF" : "Native");

    QC_MDIWindow* w = getMDIWindow();
    if (w==nullptr) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
                "QC_ApplicationWindow::slotFilePrint: "
                "no window opened");
        return;
    }

    RS_Graphic* graphic = w->getDocument()->getGraphic();
    if (graphic==nullptr) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
                "QC_ApplicationWindow::slotFilePrint: "
                "no graphic");
        return;
    }

    statusBar()->showMessage(tr("Printing..."));
    QPrinter printer(QPrinter::HighResolution);

    bool landscape = false;
    RS2::PaperFormat pf = graphic->getPaperFormat(&landscape);
    QPrinter::PageSize paperSizeName = LC_Printing::rsToQtPaperFormat(pf);
    RS_Vector paperSize = graphic->getPaperSize();
    if(paperSizeName==QPrinter::Custom){
        RS_Vector&& s=RS_Units::convert(paperSize, graphic->getUnit(),RS2::Millimeter);
        if(landscape) s=s.flipXY();
        printer.setPaperSize(QSizeF(s.x,s.y),QPrinter::Millimeter);
        // RS_DEBUG->print(RS_Debug::D_ERROR, "set Custom paper size to (%g, %g)\n", s.x,s.y);
    }else{
        printer.setPaperSize(paperSizeName);
    }
    // qDebug()<<"paper size=("<<printer.paperSize(QPrinter::Millimeter).width()<<", "<<printer.paperSize(QPrinter::Millimeter).height()<<")";
    if (landscape) {
        printer.setOrientation(QPrinter::Landscape);
    } else {
        printer.setOrientation(QPrinter::Portrait);
    }
    QPagedPaintDevice::Margins paperMargins{graphic->getMarginLeft(),
                                            graphic->getMarginRight(),
                                            graphic->getMarginTop(),
                                            graphic->getMarginBottom()};
    printer.setMargins(paperMargins);

    QString strDefaultFile("");
    RS_SETTINGS->beginGroup("/Print");
    strDefaultFile = RS_SETTINGS->readEntry("/FileName", "");
    printer.setOutputFileName(strDefaultFile);
    printer.setColorMode((QPrinter::ColorMode)RS_SETTINGS->readNumEntry("/ColorMode", (int)QPrinter::Color));
    RS_SETTINGS->endGroup();

    // printer setup:
    bool    bStartPrinting = false;
    if(printPDF) {
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setColorMode(QPrinter::Color);
        QFileInfo   infDefaultFile(strDefaultFile);
        QFileDialog fileDlg(this, tr("Export as PDF"));
        QString     defFilter("PDF files (*.pdf)");
        QStringList filters;

        filters << defFilter
                << "Any files (*)";

        fileDlg.setNameFilters(filters);
        fileDlg.setFileMode(QFileDialog::AnyFile);
        fileDlg.selectNameFilter(defFilter);
        fileDlg.setAcceptMode(QFileDialog::AcceptSave);
        fileDlg.setDefaultSuffix("pdf");
        fileDlg.setDirectory(infDefaultFile.dir().path());
		// bug#509 setting default file name restricts selection
//        strPdfFileName = infDefaultFile.baseName();
//        if( strPdfFileName.isEmpty())
//            strPdfFileName = "unnamed";
		//fileDlg.selectFile(strPdfFileName);

        if( QDialog::Accepted == fileDlg.exec()) {
            QStringList files = fileDlg.selectedFiles();
            if (!files.isEmpty()) {
                if(!files[0].endsWith(R"(.pdf)",Qt::CaseInsensitive)) files[0]=files[0]+".pdf";
                printer.setOutputFileName(files[0]);
                bStartPrinting = true;
            }
        }
    } else {
        printer.setOutputFileName(""); // uncheck 'Print to file' checkbox
        printer.setOutputFormat(QPrinter::NativeFormat);

        QPrintDialog printDialog(&printer, this);
        printDialog.setOption(QAbstractPrintDialog::PrintToFile);
        printDialog.setOption(QAbstractPrintDialog::PrintShowPageSize);
        bStartPrinting = (QDialog::Accepted == printDialog.exec());

        // fullPage must be set to true to get full width and height
        // (without counting margins).
        printer.setFullPage(true);
        QPagedPaintDevice::Margins printerMargins = printer.margins();
        RS_Vector printerSize(printer.widthMM(), printer.heightMM());
        if (bStartPrinting
                && (paperSize != printerSize
                    || paperMargins.left != printerMargins.left
                    || paperMargins.top != printerMargins.top
                    || paperMargins.right != printerMargins.right
                    || paperMargins.bottom != printerMargins.bottom)) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Paper settings");
            msgBox.setText("Paper size and/or margins have been changed!");
            msgBox.setInformativeText("Do you want to apply changes to current drawing?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Cancel);
            QString detailedText = QString("Drawing settings:\n"
                "\tsize: %1 x %2 (%3)\n"
                "\tmargins: %4, %5, %6, %7\n"
                "\n"
                "Printer settings:\n"
                "\tsize: %8 x %9 (%10)\n"
                "\tmargins: %11, %12, %13, %14\n")
                .arg(paperSize.x)
                .arg(paperSize.y)
                .arg(RS_Units::paperFormatToString(pf))
                .arg(RS_Units::convert(paperMargins.left, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(paperMargins.top, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(paperMargins.right, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(paperMargins.bottom, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(printerSize.x, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(printerSize.y, RS2::Millimeter, graphic->getUnit()))
                .arg(printer.paperName())
                .arg(RS_Units::convert(printerMargins.left, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(printerMargins.top, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(printerMargins.right, RS2::Millimeter, graphic->getUnit()))
                .arg(RS_Units::convert(printerMargins.bottom, RS2::Millimeter, graphic->getUnit()));
            msgBox.setDetailedText(detailedText);
            int answer = msgBox.exec();
            switch (answer) {
            case QMessageBox::Yes:
                graphic->setPaperSize(RS_Units::convert(printerSize, RS2::Millimeter, graphic->getUnit()));
                graphic->setMargins(printerMargins.left, printerMargins.top,
                                    printerMargins.right, printerMargins.bottom);
                break;
            case QMessageBox::No:
                break;
            case QMessageBox::Cancel:
                bStartPrinting = false;
                break;
            }
        }
    }

    if (bStartPrinting) {
        // Try to set the printer to the highest resolution
        //todo: handler printer resolution better
        if(printer.outputFormat() == QPrinter::NativeFormat ){
            //bug#3448560
            //fixme: supportedResolutions() only reports resolution of 72dpi
            //this seems to be a Qt bug up to Qt-4.7.4
            //we might be ok to keep the default resolution

//            QList<int> res=printer.supportedResolutions ();
//            if (res.size()>0)
//                printer.setResolution(res.last());
            //        for(int i=0;i<res.size();i++){
            //        std::cout<<"res.at(i)="<<res.at(i)<<std::endl;
            //        }
        }else{//pdf or postscript format
            //fixme: user should be able to set resolution output to file
            printer.setResolution(1200);
        }

        RS_DEBUG->print(RS_Debug::D_INFORMATIONAL,"QC_ApplicationWindow::slotFilePrint: resolution is %d", printer.resolution());
        QApplication::setOverrideCursor( QCursor(Qt::WaitCursor) );
        printer.setFullPage(true);

        RS_PainterQt painter(&printer);
        painter.setDrawingMode(w->getGraphicView()->getDrawingMode());

        QPagedPaintDevice::Margins margins = printer.margins();

        double printerFx = (double)printer.width() / printer.widthMM();
        double printerFy = (double)printer.height() / printer.heightMM();

        painter.setClipRect(margins.left * printerFx, margins.top * printerFy,
                            printer.width() - (margins.left + margins.right) * printerFx,
                            printer.height() - (margins.top + margins.bottom) * printerFy);

        RS_StaticGraphicView gv(printer.width(), printer.height(), &painter);
        gv.setPrinting(true);
        gv.setBorders(0,0,0,0);
        gv.setLineWidthScaling(w->getGraphicView()->getLineWidthScaling());

        double fx = printerFx * RS_Units::getFactorToMM(graphic->getUnit());
        double fy = printerFy * RS_Units::getFactorToMM(graphic->getUnit());
//RS_DEBUG->print(RS_Debug::D_ERROR, "paper size=(%d, %d)\n",
//                printer.widthMM(),printer.heightMM());

        double f = (fx+fy)/2.0;

        double scale = graphic->getPaperScale();

        gv.setFactor(f*scale);
//RS_DEBUG->print(RS_Debug::D_ERROR, "PaperSize=(%d, %d)\n",printer.widthMM(), printer.heightMM());
        gv.setContainer(graphic);

        double baseX = graphic->getPaperInsertionBase().x;
        double baseY = graphic->getPaperInsertionBase().y;
        int numX = graphic->getPagesNumHoriz();
        int numY = graphic->getPagesNumVert();
        RS_Vector printArea = graphic->getPrintAreaSize(false);

        for (int pY = 0; pY < numY; pY++) {
            double offsetY = printArea.y * pY;
            for (int pX = 0; pX < numX; pX++) {
                double offsetX = printArea.x * pX;
                // First page is created automatically.
                // Extra pages must be created manually.
                if (pX > 0 || pY > 0) printer.newPage();
                gv.setOffset((int)((baseX - offsetX) * f),
                             (int)((baseY - offsetY) * f));
//fixme, I don't understand the meaning of 'true' here
//        gv.drawEntity(&painter, graphic, true);
                painter.setDrawSelectedOnly(true);
                gv.drawEntity(&painter, graphic);
                painter.setDrawSelectedOnly(false);
                gv.drawEntity(&painter, graphic);
            }
        }

        // GraphicView deletes painter
        painter.end();

        RS_SETTINGS->beginGroup("/Print");
        RS_SETTINGS->writeEntry("/ColorMode", (int)printer.colorMode());
        RS_SETTINGS->writeEntry("/FileName", printer.outputFileName());
        RS_SETTINGS->endGroup();
        QApplication::restoreOverrideCursor();
    }

    statusBar()->showMessage(tr("Printing complete"), 2000);
}

void QC_ApplicationWindow::slotFilePrintPDF() {
    slotFilePrint(true);
}



/*	*
 *	Function name:
 *	Description:
 *	Author(s):		..., Claude Sylvain
 *	Created:			?
 *	Last modified:	30 July 2011
 *
 *	Parameters:		bool on:
 *							...
 *
 *	Returns:			void
 *	Notes:			Menu file -> print preview.
 *	*/

void QC_ApplicationWindow::slotFilePrintPreview(bool on)
{
    RS_DEBUG->print("QC_ApplicationWindow::slotFilePrintPreview()");

    QC_MDIWindow* parent = getMDIWindow();

	if (!parent)
    {
        RS_DEBUG->print(RS_Debug::D_WARNING,
                "QC_ApplicationWindow::slotFilePrintPreview: "
                "no window opened");
        return;
    }

    // close print preview:
	if (!on)
    {
        RS_DEBUG->print("QC_ApplicationWindow::slotFilePrintPreview(): off");

        if (parent->getGraphicView()->isPrintPreview())
        {
            RS_DEBUG->print("QC_ApplicationWindow::slotFilePrintPreview(): close");
            emit(printPreviewChanged(false));
            doClose(parent);
            doArrangeWindows(RS2::CurrentMode);
            return;
        }
    }

    // open print preview:
    else {
        // look for an existing print preview:
        QC_MDIWindow* ppv = parent->getPrintPreview();
        if (ppv)
        {
            RS_DEBUG->print("QC_ApplicationWindow::slotFilePrintPreview(): show existing");

            doActivate(ppv);
            doArrangeWindows(RS2::CurrentMode);
            emit(printPreviewChanged(true));
        }
        else
        {
            if (!parent->getGraphicView()->isPrintPreview())
            {
                QSettings settings;
                //generate a new print preview
                RS_DEBUG->print("QC_ApplicationWindow::slotFilePrintPreview(): create");

                QC_MDIWindow* w = new QC_MDIWindow(parent->getDocument(), mdiAreaCAD, 0);
                mdiAreaCAD->addSubWindow(w);
                parent->addChildWindow(w);
                connect(w, SIGNAL(signalClosing(QC_MDIWindow*)),
                        this, SLOT(slotFileClosing(QC_MDIWindow*)));

                w->setWindowTitle(tr("Print preview for %1").arg(parent->windowTitle()));
                w->setWindowIcon(QIcon(":/main/document.png"));
                QG_GraphicView* gv = w->getGraphicView();
                gv->device = settings.value("Hardware/Device", "Mouse").toString();
                gv->setPrintPreview(true);
                gv->setBackground(RS_Color(255,255,255));
                gv->setDefaultAction(new RS_ActionPrintPreview(*w->getDocument(), *w->getGraphicView()));

                // only graphics offer block lists, blocks don't
                RS_DEBUG->print("  adding listeners");
                RS_Graphic* graphic = w->getDocument()->getGraphic();
                if (graphic) {
                    // Link the layer list to the pen tool bar
                    graphic->addLayerListListener(penToolBar);
                    // Link the layer list to the layer widget
                    graphic->addLayerListListener(layerWidget);

                    // Link the block list to the block widget
                    graphic->addBlockListListener(blockWidget);

                }

				// Link the graphic view to the mouse widget:
				QG_DIALOGFACTORY->setMouseWidget(mouseWidget);
				// Link the graphic view to the coordinate widget:
				//QG_DIALOGFACTORY->setCoordinateWidget(coordinateWidget);
				QG_DIALOGFACTORY->setSelectionWidget(selectionWidget);
				// Link the graphic view to the option widget:
				//QG_DIALOGFACTORY->setOptionWidget(optionWidget);
				// Link the graphic view to the command widget:
				QG_DIALOGFACTORY->setCommandWidget(commandWidget);

                RS_DEBUG->print("  showing MDI window");

                doActivate(w);
                doArrangeWindows(RS2::CurrentMode);

                gv->zoomAuto(false);

                if(graphic){
                    bool bigger = graphic->isBiggerThanPaper();
                    bool fixed = graphic->getPaperScaleFixed();

                    graphic->fitToPage();

                    // Calling zoomPage() after fitToPage() always fits
                    // preview paper in preview window. The only reason not
                    // to call zoomPage() is when drawing is bigger than paper,
                    // plus it is fixed. In that case, not calling zoomPage()
                    // prevents displaying empty paper (when drawing is actually
                    // outside the paper and the preview window) and displays
                    // full drawing and smaller paper inside it.
                    if (bigger && fixed) {
                        RS_DEBUG->print("%s: don't call zoomPage()", __func__);
                    } else {
                        RS_DEBUG->print("%s: call zoomPage()", __func__);
                        gv->zoomPage();
                    }
                }

                emit(printPreviewChanged(true));
            }
        }
    }
}





/**
 * Menu file -> quit.
 */
void QC_ApplicationWindow::slotFileQuit() {
    QMessageBox* msgBox = new QMessageBox(QMessageBox::Question, QString::fromLocal8Bit("提示 "), QString::fromLocal8Bit("是否退出程序？ "), QMessageBox::Ok, this);
    msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("是 "));
    msgBox->setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("取消 "));
    if (msgBox->exec() == QMessageBox::Ok)
    {
        RS_DEBUG->print("QC_ApplicationWindow::slotFileQuit()");
        statusBar()->showMessage(tr("Exiting application..."));

        if (queryExit(true)) {
            // 2. 停止线程
            if (T && T->isRunning()) {
                T->quit();  // 请求退出
                T->wait();  // 等待线程结束
            }
            // 4. 关闭所有模态窗口（强制）
            serialmanager.close();
            viewer.close();
            guide.close();

            // 5. 标记退出并关闭主窗口
            IsCloseSoftware = true;
           // this->close();
            qApp->quit();
        }
    }
}


/**
 * Shows / hides the grid.
 *
 * @param toggle true: show, false: hide.
 */
void QC_ApplicationWindow::slotViewGrid(bool toggle) {
    RS_DEBUG->print("QC_ApplicationWindow::slotViewGrid()");

    QC_MDIWindow* m = getMDIWindow();
    if (m) {
        RS_Graphic* g = m->getGraphic();
        if (g) {
            g->setGridOn(false);
        }
    }

    updateGrids();
    redrawAll();

    RS_DEBUG->print("QC_ApplicationWindow::slotViewGrid() OK");
}

/**
 * Enables / disables the draft mode.
 *
 * @param toggle true: enable, false: disable.
 */
void QC_ApplicationWindow::slotViewDraft(bool toggle)
{
    RS_DEBUG->print("QC_ApplicationWindow::slotViewDraft()");

    RS_SETTINGS->beginGroup("/Appearance");
    RS_SETTINGS->writeEntry("/DraftMode", (int)toggle);
    RS_SETTINGS->endGroup();

    //handle "Draft Mode" in window titles
    QString draft_string = " ["+tr("Draft Mode")+"]";

    foreach (QC_MDIWindow* win, window_list)
    {
        win->getGraphicView()->setDraftMode(toggle);
        QString title = win->windowTitle();

        if (toggle && !title.contains(draft_string))
        {
            win->setWindowTitle(title + draft_string);
        }
        else if (!toggle && title.contains(draft_string))
        {
            title.remove(draft_string);
            win->setWindowTitle(title);
        }
    }
    redrawAll();
}

/**
 * Redraws all mdi windows.
 */
void QC_ApplicationWindow::redrawAll()
{
    if (mdiAreaCAD)
    {
        foreach (const QC_MDIWindow* win, window_list)
        {
            if (win)
            {
                QG_GraphicView* gv = win->getGraphicView();
                if (gv) {gv->redraw();}
            }
        }
    }
}



/**
 * Updates all grids of all graphic views.
 */
void QC_ApplicationWindow::updateGrids() {
    if (mdiAreaCAD) {
        QList<QMdiSubWindow*> windows = mdiAreaCAD->subWindowList();
        for (int i = 0; i < windows.size(); ++i) {
            QC_MDIWindow* m = qobject_cast<QC_MDIWindow*>(windows.at(i));
            if (m) {
                QG_GraphicView* gv = m->getGraphicView();
                if (gv) {
                    // gv->updateGrid();
                    gv->redraw(RS2::RedrawGrid);
                }
            }
        }
    }
}



/**
 * Shows / hides the status bar.
 *
 * @param toggle true: show, false: hide.
 */
void QC_ApplicationWindow::slotViewStatusBar(bool toggle) {
    RS_DEBUG->print("QC_ApplicationWindow::slotViewStatusBar()");

    statusBar()->setVisible(toggle);
}

/**
 * Shows the dialog for general application preferences.
 */
void QC_ApplicationWindow::slotOptionsGeneral() {
    RS_DIALOGFACTORY->requestOptionsGeneralDialog();

    RS_SETTINGS->beginGroup("Colors");
    QColor background(RS_SETTINGS->readEntry("/background", Colors::background));
    QColor gridColor(RS_SETTINGS->readEntry("/grid", Colors::grid));
    QColor metaGridColor(RS_SETTINGS->readEntry("/meta_grid", Colors::meta_grid));
    QColor selectedColor(RS_SETTINGS->readEntry("/select", Colors::select));
    QColor highlightedColor(RS_SETTINGS->readEntry("/highlight", Colors::highlight));
    QColor startHandleColor(RS_SETTINGS->readEntry("/start_handle", Colors::start_handle));
    QColor handleColor(RS_SETTINGS->readEntry("/handle", Colors::handle));
	QColor endHandleColor(RS_SETTINGS->readEntry("/end_handle", Colors::end_handle));
    RS_SETTINGS->endGroup();

    RS_SETTINGS->beginGroup("/Appearance");
    int antialiasing = RS_SETTINGS->readNumEntry("/Antialiasing");
    RS_SETTINGS->endGroup();

    QList<QMdiSubWindow*> windows = mdiAreaCAD->subWindowList();
    for (int i = 0; i < windows.size(); ++i) {
        QC_MDIWindow* m = qobject_cast<QC_MDIWindow*>(windows.at(i));
        if (m) {
            QG_GraphicView* gv = m->getGraphicView();
            if (gv) {
                gv->setBackground(background);
                gv->setGridColor(gridColor);
                gv->setMetaGridColor(metaGridColor);
                gv->setSelectedColor(selectedColor);
                gv->setHighlightedColor(highlightedColor);
                gv->setStartHandleColor(startHandleColor);
                gv->setHandleColor(handleColor);
                gv->setEndHandleColor(endHandleColor);
                gv->setAntialiasing(antialiasing?true:false);
                gv->redraw(RS2::RedrawGrid);
            }
        }
    }
}


/**
 * Menu File -> import -> importBlock
 */
void QC_ApplicationWindow::slotImportBlock() {

    if (getMDIWindow() == nullptr) {
        RS_DEBUG->print(RS_Debug::D_WARNING,
                "QC_ApplicationWindow::slotImportBlock: "
                "no window opened");
        return;
    }

    QG_FileDialog dlg(this);
    RS2::FormatType type = RS2::FormatDXFRW;
    QString dxfPath = dlg.getOpenFile(&type);
    if (dxfPath.isEmpty()) {
        return;
    }

    if (QFileInfo(dxfPath).isReadable()) {
        if (actionHandler) {
            RS_ActionInterface* a =
                actionHandler->setCurrentAction(RS2::ActionLibraryInsert);
            if (a) {
                RS_ActionLibraryInsert* action = (RS_ActionLibraryInsert*)a;
                action->setFile(dxfPath);
            } else {
                RS_DEBUG->print(RS_Debug::D_ERROR,
                                "QC_ApplicationWindow::slotImportBlock:"
                                "Cannot create action RS_ActionLibraryInsert");
            }
        }
    } else {
        RS_DEBUG->print(RS_Debug::D_ERROR,
                        "QC_ApplicationWindow::slotImportBlock: Can't read file: '%s'", dxfPath.toLatin1().data());
    }
}


void QC_ApplicationWindow::showAboutWindow()
{
    // author: ravas

    QDialog dlg;
    dlg.setWindowTitle(tr("About"));

    auto layout = new QVBoxLayout;
    dlg.setLayout(layout);

    auto frame = new QGroupBox(qApp->applicationName());
    layout->addWidget(frame);

    auto f_layout = new QVBoxLayout;
    frame->setLayout(f_layout);

    // Compiler macro list in Qt source tree
    // Src/qtbase/src/corelib/global/qcompilerdetection.h

    QString info
    (
        tr("Version: %1").arg(XSTR(LC_VERSION)) + "\n" +
        #if defined(Q_CC_CLANG)
            tr("Compiler: Clang %1.%2.%3").arg(__clang_major__).arg(__clang_minor__).arg(__clang_patchlevel__) + "\n" +
        #elif defined(Q_CC_GNU)
            tr("Compiler: GNU GCC %1.%2.%3").arg(__GNUC__).arg(__GNUC_MINOR__).arg(__GNUC_PATCHLEVEL__) + "\n" +
        #elif defined(Q_CC_MSVC)
            tr("Compiler: Microsoft Visual C++") + "\n" +
        #endif
        tr("Compiled on: %1").arg(__DATE__) + "\n" +
        tr("Qt Version: %1").arg(qVersion()) + "\n" +
        tr("Boost Version: %1.%2.%3").arg(BOOST_VERSION / 100000).arg(BOOST_VERSION / 100 % 1000).arg(BOOST_VERSION % 100)
    );

    auto app_info = new QLabel(info);
    app_info->setTextInteractionFlags(Qt::TextSelectableByMouse);
    f_layout->addWidget(app_info);

    auto copy_button = new QPushButton(tr("Copy"));
    // copy_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    f_layout->addWidget(copy_button);

    connect(copy_button, SIGNAL(released()), &dlg, SLOT(accept()));

    QLabel *links_label = new QLabel( QString( "<a href=\"https://github.com/LibreCAD/LibreCAD/graphs/contributors\">%1</a>"
                                               "<br/>"
                                               "<a href=\"https://github.com/LibreCAD/LibreCAD/blob/master/LICENSE\">%2</a>"
                                               "<br/>"
                                               "<a href=\"https://github.com/LibreCAD/LibreCAD/\">%3</a>")
                                      .arg( tr("Contributors"))
                                      .arg( tr("License"))
                                      .arg( tr("The Code")) );
    links_label->setOpenExternalLinks(true);
    links_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    f_layout->addWidget(links_label);

    if (dlg.exec())
    {
        QClipboard* clipboard = QApplication::clipboard();
        #if QT_VERSION >= 0x050400
           info += "\n" + tr("System") + ": " + QSysInfo::prettyProductName();
        #endif
        clipboard->setText(info);
    }
}

/**
 * overloaded for Message box on last window exit.
 * 重载函数，用于在最后一个窗口退出时显示消息框
 */
bool QC_ApplicationWindow::queryExit(bool force) {
    // 输出调试信息，标记函数开始执行
    RS_DEBUG->print("QC_ApplicationWindow::queryExit()");

    // 初始化返回值，默认为成功
    bool succ = true;

    // 强制退出模式：不询问用户，直接关闭所有窗口
    if (force) {
        for (auto w : window_list) {
            doClose(w);  // 强制关闭每个窗口
        }
    }
    // 正常退出模式：显示保存对话框，让用户选择
    else {
        succ = slotFileCloseAll();  // 调用"关闭所有文件"功能
    }

    // 如果退出操作成功，保存应用程序设置
    if (succ) {
        storeSettings();  // 保存窗口位置、工具栏状态等设置
    }

    // 输出调试信息，标记函数执行完成
    RS_DEBUG->print("QC_ApplicationWindow::queryExit(): OK");

    // 返回退出操作是否成功
    return succ;
}

/**
 * Handle hotkeys. Don't let it to the default handler of Qt.
 * it will consume them also if a text field is active
 * which means it's impossible to enter a command.
 */
void QC_ApplicationWindow::keyPressEvent(QKeyEvent* e)
{
    switch (e->key()) {
    case Qt::Key_Escape:
        slotKillAllActions();
        // fall-through
    case Qt::Key_Return:
    case Qt::Key_Enter:
        slotEnter();
        e->accept();
        break;

    case Qt::Key_Plus:
    case Qt::Key_Equal:
        actionHandler->slotZoomIn();
        e->accept();
        break;

    case Qt::Key_Minus:
        actionHandler->slotZoomOut();
        e->accept();
        break;

    default:
        e->ignore();
        RS_DEBUG->print("QC_ApplicationWindow::KeyPressEvent: IGNORED");
        break;
    }

    if (e->isAccepted()) {
        RS_DEBUG->print("QC_ApplicationWindow::KeyPressEvent: Accepted");
        return;
    }

    QMainWindow::keyPressEvent(e);
}

QMdiArea const* QC_ApplicationWindow::getMdiArea() const{
    return mdiAreaCAD;
}

QMdiArea* QC_ApplicationWindow::getMdiArea(){
    return mdiAreaCAD;
}

RS_GraphicView const* QC_ApplicationWindow::getGraphicView() const{
    QC_MDIWindow const* m = getMDIWindow();
    if (m) {
        return m->getGraphicView();
    }
    return nullptr;
}

RS_GraphicView * QC_ApplicationWindow::getGraphicView() {
    QC_MDIWindow* m = getMDIWindow();
    if (m) {
        return m->getGraphicView();
    }
    return nullptr;
}

RS_Document const* QC_ApplicationWindow::getDocument() const{
    QC_MDIWindow const* m = getMDIWindow();
    if (m) {
        return m->getDocument();
    }
    return nullptr;
}

RS_Document* QC_ApplicationWindow::getDocument(){
    QC_MDIWindow* m = getMDIWindow();
    if (m) {
        return m->getDocument();
    }
    return nullptr;
}

void QC_ApplicationWindow::createNewDocument(
        const QString& fileName, RS_Document* doc) {

    slotFileNew(doc);
    if (fileName!=QString() && getDocument()) {
        getDocument()->setFilename(fileName);
    }
}

void QC_ApplicationWindow::updateWindowTitle(QWidget *w)
{
    RS_DEBUG->print("QC_ApplicationWindow::slotViewDraft()");

    RS_SETTINGS->beginGroup("/Appearance");
    bool draftMode = RS_SETTINGS->readNumEntry("/DraftMode", 0);
    RS_SETTINGS->endGroup();

    if (draftMode)
    {
        QString draft_string = " ["+tr("Draft Mode")+"]";
        if (!w->windowTitle().contains(draft_string))
            w->setWindowTitle(w->windowTitle() + draft_string);
    }
}

void QC_ApplicationWindow::relayAction(QAction* q_action)
{
    // 1. 获取当前活跃窗口的图形视图
    auto view = getMDIWindow()->getGraphicView();
    if (!view)
    {
        // 异常情况：当从其他程序切换回 LibreCAD 时，
        // 偶尔没有激活的绘图窗口
        qWarning("relayAction: graphicView is nullptr");
        return;
    }

    // 2. 将动作设置为图形视图的当前动作
    // 这将触发相应的绘图命令
    view->setCurrentQAction(q_action);

    // 3. 记录命令到历史记录
    const QString commands(q_action->data().toString());
    if (!commands.isEmpty())
    {
        // 获取动作标题（移除快捷键前缀'&'）
        const QString title(q_action->text().remove("&"));

        // 将命令添加到命令历史记录控件
        commandWidget->appendHistory(title + " : " + commands);
    }
}

/**
 * Called by Qt after a toolbar or dockwidget right-click.
 * See QMainWindow::createPopupMenu() for more information.
 */
QMenu* QC_ApplicationWindow::createPopupMenu()
{
    // author: ravas

    QMenu* context_menu = new QMenu("Context");
    context_menu->setAttribute(Qt::WA_DeleteOnClose);

    QMenu* tb_menu = menuBar()->findChild<QMenu*>("toolbars_menu");
    QMenu* temp_tb_menu = new QMenu(tr("Toolbars"), context_menu);
    temp_tb_menu->addActions(tb_menu->actions());
    context_menu->addMenu(temp_tb_menu);

    QMenu* dw_menu = menuBar()->findChild<QMenu*>("dockwidgets_menu");
    QMenu* temp_dw_menu = new QMenu(tr("Dockwidgets"), context_menu);
    temp_dw_menu->addActions(dw_menu->actions());
    context_menu->addMenu(temp_dw_menu);

    context_menu->addAction(a_map["ViewStatusBar"]);

    return context_menu;
}

void QC_ApplicationWindow::toggleFullscreen(bool checked)
{
    // author: ravas

    checked?showFullScreen():showMaximized();
}

void QC_ApplicationWindow::hideOptions(QC_MDIWindow* win)
{
    // author: ravas

    win->getGraphicView()->getDefaultAction()->hideOptions();
}

void QC_ApplicationWindow::slotFileOpenRecent(QAction* action)
{
	RS_DEBUG->print("QC_ApplicationWindow::slotFileOpenRecent()");

    statusBar()->showMessage(tr("Opening recent file..."));
    QString fileName = action->data().toString();
    slotFileOpen(fileName, RS2::FormatUnknown);
}

/**
 * This slot manipulates the widget options dialog,
 * and reads / writes the associated settings.
 */
void QC_ApplicationWindow::widgetOptionsDialog()
{
    // author: ravas

    LC_WidgetOptionsDialog dlg;

    QSettings settings;
    settings.beginGroup("Widgets");

    int allow_style = settings.value("AllowStyle", 0).toInt();
    dlg.style_checkbox->setChecked(allow_style);
    dlg.style_combobox->addItems(QStyleFactory::keys());
    if (allow_style)
    {
        QString a_style = settings.value("Style", "").toString();
        if (!a_style.isEmpty())
        {
            int index = dlg.style_combobox->findText(a_style);
            dlg.style_combobox->setCurrentIndex(index);
        }
    }

    QString sheet_path = settings.value("StyleSheet", "").toString();
    if (!sheet_path.isEmpty() && QFile::exists(sheet_path))
        dlg.stylesheet_field->setText(sheet_path);

    int allow_theme = settings.value("AllowTheme", 0).toInt();
    dlg.theme_checkbox->setChecked(allow_theme);

    int allow_toolbar_icon_size = settings.value("AllowToolbarIconSize", 0).toInt();
    dlg.toolbar_icon_size_checkbox->setChecked(allow_toolbar_icon_size);
    int toolbar_icon_size = settings.value("ToolbarIconSize", 24).toInt();
    dlg.toolbar_icon_size_spinbox->setValue(toolbar_icon_size);

    int allow_statusbar_height = settings.value("AllowStatusbarHeight", 0).toInt();
    dlg.statusbar_height_checkbox->setChecked(allow_statusbar_height);
    int statusbar_height = settings.value("StatusbarHeight", 32).toInt();
    dlg.statusbar_height_spinbox->setValue(statusbar_height);

    int allow_statusbar_fontsize = settings.value("AllowStatusbarFontSize", 0).toInt();
    dlg.statusbar_fontsize_checkbox->setChecked(allow_statusbar_fontsize);
    int statusbar_fontsize = settings.value("StatusbarFontSize", 12).toInt();
    dlg.statusbar_fontsize_spinbox->setValue(statusbar_fontsize);

    if (dlg.exec())
    {
        int allow_style = dlg.style_checkbox->isChecked();
        settings.setValue("AllowStyle", allow_style);
        if (allow_style)
        {
            QString style = dlg.style_combobox->currentText();
            settings.setValue("Style", style);
            QApplication::setStyle(QStyleFactory::create(style));
        }

        QString sheet_path = dlg.stylesheet_field->text();
        settings.setValue("StyleSheet", sheet_path);
        if (loadStyleSheet(sheet_path))
            style_sheet_path = sheet_path;

        int allow_theme = dlg.theme_checkbox->isChecked();
        settings.setValue("AllowTheme", allow_theme);

        int allow_toolbar_icon_size = dlg.toolbar_icon_size_checkbox->isChecked();
        settings.setValue("AllowToolbarIconSize", allow_toolbar_icon_size);
        if (allow_toolbar_icon_size)
        {
            int toolbar_icon_size = dlg.toolbar_icon_size_spinbox->value();
            settings.setValue("ToolbarIconSize", toolbar_icon_size);
            setIconSize(QSize(toolbar_icon_size, toolbar_icon_size));
        }

        int allow_statusbar_fontsize = dlg.statusbar_fontsize_checkbox->isChecked();
        settings.setValue("AllowStatusbarFontSize", allow_statusbar_fontsize);
        if (allow_statusbar_fontsize)
        {
            int statusbar_fontsize = dlg.statusbar_fontsize_spinbox->value();
            settings.setValue("StatusbarFontSize", statusbar_fontsize);
            QFont font;
            font.setPointSize(statusbar_fontsize);
            statusBar()->setFont(font);
        }

        int allow_statusbar_height = dlg.statusbar_height_checkbox->isChecked();
        settings.setValue("AllowStatusbarHeight", allow_statusbar_height);
        if (allow_statusbar_height)
        {
            int statusbar_height = dlg.statusbar_height_spinbox->value();
            settings.setValue("StatusbarHeight", statusbar_height);
            statusBar()->setMinimumHeight(statusbar_height);
        }
    }
    settings.endGroup();
}

/**
 * This slot modifies the commandline's title bar
 * depending on the dock area it is moved to.
 */
void QC_ApplicationWindow::modifyCommandTitleBar(Qt::DockWidgetArea area)
{
    // author: ravas

    QDockWidget* cmd_dockwidget = findChild<QDockWidget*>("command_dockwidget");

    if (area == Qt::BottomDockWidgetArea || area == Qt::TopDockWidgetArea)
    {
        cmd_dockwidget->setWindowTitle("Cmd");
        cmd_dockwidget->setFeatures(QDockWidget::DockWidgetClosable
                                   |QDockWidget::DockWidgetMovable
                                   |QDockWidget::DockWidgetFloatable
                                   |QDockWidget::DockWidgetVerticalTitleBar);
    }
    else
    {
        cmd_dockwidget->setWindowTitle(tr("Command line"));
        cmd_dockwidget->setFeatures(QDockWidget::DockWidgetClosable
                                   |QDockWidget::DockWidgetMovable
                                   |QDockWidget::DockWidgetFloatable);
    }
}

bool QC_ApplicationWindow::loadStyleSheet(QString path)
{
    // author: ravas

    if (!path.isEmpty() && QFile::exists(path))
    {
        QFile file(path);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qApp->setStyleSheet(QString::fromLatin1(file.readAll()));
            return true;
        }
    }
    return false;
}

void QC_ApplicationWindow::reloadStyleSheet()
{
    // author: ravas

    loadStyleSheet(style_sheet_path);
}

//bool QC_ApplicationWindow::eventFilter(QObject *obj, QEvent *event)
//{
//    if (QEvent::FileOpen == event->type()) {
//        QFileOpenEvent *openEvent = static_cast<QFileOpenEvent *>(event);
//        slotFileOpen(openEvent->file(), RS2::FormatUnknown);
//        return true;
//    }
//
//    return QObject::eventFilter(obj, event);
//}

void QC_ApplicationWindow::updateGridStatus(const QString & status)
{
    // author: ravas

   grid_status->setBottomLabel(status);
}

void QC_ApplicationWindow::showDeviceOptions()
{
    // author: ravas

    QSettings settings;

    QDialog dlg;
    dlg.setWindowTitle(tr("Device Options"));
    auto layout = new QVBoxLayout;
    auto device_combo = new ComboBoxOption(&dlg);
    device_combo->setTitle(tr("Device"));
    device_combo->setOptionsList(QStringList({"Mouse", "Tablet", "Trackpad", "Touchscreen"}));
    device_combo->setCurrentOption(settings.value("Hardware/Device", "Mouse").toString());
    layout->addWidget(device_combo);
    dlg.setLayout(layout);
    connect(device_combo, &ComboBoxOption::optionToSave,
            this, &QC_ApplicationWindow::updateDevice);
    dlg.exec();
}

void QC_ApplicationWindow::updateDevice(QString device)
{
    // author: ravas
    QSettings settings;
    settings.setValue("Hardware/Device", device);
    foreach (auto win, window_list)
    {
        win->getGraphicView()->device = device;
    }
}

void QC_ApplicationWindow::invokeToolbarCreator()
{
    // author: ravas

    auto tb_creator = findChild<QDialog*>("Toolbar Creator");
    if (tb_creator)
    {
        tb_creator->raise();
        tb_creator->activateWindow();
        return;
    }

    auto dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setWindowTitle(tr("Toolbar Creator"));
    dlg->setObjectName("Toolbar Creator");

    auto toolbar_creator = new WidgetCreator(dlg, a_map, ag_manager->allGroups());
    toolbar_creator->addCustomWidgets("CustomToolbars");

    connect(toolbar_creator, SIGNAL(widgetToCreate(QString)),
            this, SLOT(createToolbar(QString)));
    connect(toolbar_creator, SIGNAL(widgetToDestroy(QString)),
            this, SLOT(destroyToolbar(QString)));

    auto layout = new QVBoxLayout;
    layout->addWidget(toolbar_creator);
    dlg->setLayout(layout);

    dlg->show();
}

void QC_ApplicationWindow::createToolbar(const QString& toolbar_name)
{
    // author: ravas

    QSettings settings;
    auto tb = QString("CustomToolbars/%1").arg(toolbar_name);
    auto a_list = settings.value(tb).toStringList();

    auto toolbar = findChild<QToolBar*>(toolbar_name);

    if (toolbar)
        toolbar->clear();
    else
    {
        toolbar = new QToolBar(toolbar_name, this);
        toolbar->setObjectName(toolbar_name);
        addToolBar(Qt::BottomToolBarArea, toolbar);
    }

    foreach (auto key, a_list)
    {
        toolbar->addAction(a_map[key]);
    }
}

void QC_ApplicationWindow::destroyToolbar(const QString& toolbar_name)
{
    // author: ravas

    auto toolbar = findChild<QToolBar*>(toolbar_name);
    if (toolbar) delete toolbar;
}


void QC_ApplicationWindow::invokeMenuCreator()
{
    // author: ravas

    auto menu_creator = findChild<QDialog*>("Menu Creator");
    if (menu_creator)
    {
        menu_creator->raise();
        menu_creator->activateWindow();
        return;
    }

    auto dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setWindowTitle(tr("Menu Creator"));
    auto layout = new QVBoxLayout;
    auto widget_creator = new WidgetCreator(dlg, a_map, ag_manager->allGroups(), true);
    widget_creator->addCustomWidgets("CustomMenus");

    connect(widget_creator, SIGNAL(widgetToDestroy(QString)),
            this, SLOT(destroyMenu(QString)));
    connect(widget_creator, SIGNAL(widgetToAssign(QString)),
            this, SLOT(invokeMenuAssigner(QString)));
    connect(widget_creator, SIGNAL(widgetToUpdate(QString)),
            this, SLOT(updateMenu(QString)));

    layout->addWidget(widget_creator);
    dlg->setLayout(layout);
    dlg->show();
}

void QC_ApplicationWindow::invokeMenuAssigner(const QString& menu_name)
{
    //author: ravas

    QSettings settings;
    settings.beginGroup("Activators");

    QDialog dlg;
    dlg.setWindowTitle(tr("Menu Assigner"));

    auto cb_1 = new QCheckBox("Double-Click");
    auto cb_2 = new QCheckBox("Right-Click");
    auto cb_3 = new QCheckBox("Ctrl+Right-Click");
    auto cb_4 = new QCheckBox("Shift+Right-Click");
    cb_1->setChecked(settings.value("Double-Click").toString() == menu_name);
    cb_2->setChecked(settings.value("Right-Click").toString() == menu_name);
    cb_3->setChecked(settings.value("Ctrl+Right-Click").toString() == menu_name);
    cb_4->setChecked(settings.value("Shift+Right-Click").toString() == menu_name);

    auto button_box = new QDialogButtonBox;
    button_box->setStandardButtons(QDialogButtonBox::Save|QDialogButtonBox::Cancel);

    connect(button_box, SIGNAL(accepted()), &dlg, SLOT(accept()));
    connect(button_box, SIGNAL(rejected()), &dlg, SLOT(reject()));

    auto layout = new QVBoxLayout;
    dlg.setLayout(layout);

    auto frame = new QFrame;
    layout->addWidget(frame);

    auto f_layout = new QVBoxLayout;
    frame->setLayout(f_layout);

    f_layout->addWidget(cb_1);
    f_layout->addWidget(cb_2);
    f_layout->addWidget(cb_3);
    f_layout->addWidget(cb_4);
    f_layout->addWidget(button_box);

    if (dlg.exec())
    {
        if (cb_1->isChecked())
            assignMenu("Double-Click", menu_name);
        else
            unassignMenu("Double-Click", menu_name);

        if (cb_2->isChecked())
            assignMenu("Right-Click", menu_name);
        else
            unassignMenu("Right-Click", menu_name);

        if (cb_3->isChecked())
            assignMenu("Ctrl+Right-Click", menu_name);
        else
            unassignMenu("Ctrl+Right-Click", menu_name);

        if (cb_4->isChecked())
            assignMenu("Shift+Right-Click", menu_name);
        else
            unassignMenu("Shift+Right-Click", menu_name);
    }
    settings.endGroup();
}

void QC_ApplicationWindow::unassignMenu(const QString& activator, const QString& menu_name)
{
    // author: ravas

    QSettings settings;
    settings.beginGroup("Activators");

    if (settings.value(activator).toString() == menu_name)
    {
        settings.remove(activator);
    }
    settings.endGroup();

    foreach (auto win, window_list)
    {
        auto view = win->getGraphicView();
        view->destroyMenu(activator);
    }
}

void QC_ApplicationWindow::assignMenu(const QString& activator, const QString& menu_name)
{
    // author: ravas

    QSettings settings;

    settings.beginGroup("Activators");
    settings.setValue(activator, menu_name);
    settings.endGroup();

    auto menu_key = QString("CustomMenus/%1").arg(menu_name);
    auto a_list = settings.value(menu_key).toStringList();

    foreach (auto win, window_list)
    {
        auto view = win->getGraphicView();
        auto menu = new QMenu(activator, view);
        menu->setObjectName(menu_name);
        foreach (auto key, a_list)
        {
            menu->addAction(a_map[key]);
        }
        view->setMenu(activator, menu);
    }
}

void QC_ApplicationWindow::updateMenu(const QString& menu_name)
{
    // author: ravas

    QSettings settings;

    auto menu_key = QString("CustomMenus/%1").arg(menu_name);
    auto a_list = settings.value(menu_key).toStringList();

    settings.beginGroup("Activators");
    auto activators = settings.childKeys();

    foreach (auto activator, activators)
    {
        if (settings.value(activator).toString() == menu_name)
        {
            foreach (auto win, window_list)
            {
                auto view = win->getGraphicView();
                auto menu = new QMenu(activator, view);
                menu->setObjectName(menu_name);
                foreach (auto key, a_list)
                {
                    menu->addAction(a_map[key]);
                }
                view->setMenu(activator, menu);
            }
        }
    }
}

void QC_ApplicationWindow::destroyMenu(const QString& menu_name)
{
    //author: ravas

    QSettings settings;
    settings.beginGroup("Activators");
    auto activators = settings.childKeys();

    foreach (auto activator, activators)
    {
        if (settings.value(activator).toString() == menu_name)
        {
            settings.remove(activator);
            foreach (auto win, window_list)
            {
                auto view = win->getGraphicView();
                view->destroyMenu(activator);
            }
        }
    }
    settings.endGroup();
}

void QC_ApplicationWindow::changeEvent(QEvent* event)
{
    // author: ravas
    // returning to LC via Command+Tab won't always activate a subwindow #821

    #if defined(Q_OS_OSX)
        if (event->type() == QEvent::ActivationChange)
        {
            if (isActiveWindow())
            {
                if (current_subwindow)
                    mdiAreaCAD->setActiveSubWindow(current_subwindow);
            }
            else
            {
                current_subwindow = mdiAreaCAD->currentSubWindow();
            }
        }
    #else
    Q_UNUSED( event)
    #endif
}


void QC_ApplicationWindow::invokeLicenseWindow()
{
    // author: ravas

    QDialog dlg;

    dlg.setWindowTitle(QObject::tr("License"));

    auto viewer = new TextFileViewer(&dlg);
    auto layout = new QVBoxLayout;
    layout->addWidget(viewer);
    dlg.setLayout(layout);

    viewer->addFile("readme", ":/readme.md");
    viewer->addFile("GPLv2", ":/gpl-2.0.txt");

    viewer->setFile("readme");

    dlg.exec();
}


QC_MDIWindow* QC_ApplicationWindow::getWindowWithDoc(const RS_Document* doc)
{
    QC_MDIWindow* wwd = nullptr;

    if (doc) {
        foreach (QC_MDIWindow* w, window_list) {
            if (w && w->getDocument() == doc) {
                wwd = w;
                break;
            }
        }
    }

    return wwd;
}



/*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
											   下面是Ocrdemo中的代码
*/




//设置主界面QSS样式表
void QC_ApplicationWindow::SetQSS()
{
 
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    qApp->installEventFilter(this);                   //给自己加事件过滤器,用来实现拖动窗口
  /*  mtextlowerLeftx = 0;
    mtextlowerLefty = 0;
    mtexttotalWidth = 1920;
    mtexttotalHeight = 1200;
    SetROISimple(mtexttotalWidth, mtexttotalHeight, mtextlowerLeftx, mtextlowerLefty);*/
   
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(1);
    ui->stackedWidget_4->setStyleSheet(QString::fromUtf8("#stackedWidget_4{border:1px solid rgb(52, 62, 79)}"));
    // 禁用所有工具栏动作
    //foreach(QToolBar * toolbar, findChildren<QToolBar*>()) {
    //    foreach(QAction * action, toolbar->actions()) {
    //        action->setEnabled(false);  // 禁用单个动作
    //    }
    //    toolbar->setStyleSheet("QToolBar { background: #f0f0f0; }"); // 视觉灰化
    //}
    QRegularExpressionValidator* alnumValidator = new QRegularExpressionValidator(
        QRegularExpression("^[A-Za-z0-9]*$"),  // 正则表达式
        this                                   // 父对象
    );

    // 应用到所有自定义字段
    ui->lineEdit_4->setValidator(alnumValidator);
    ui->lineEdit_5->setValidator(alnumValidator);
    ui->lineEdit_6->setValidator(alnumValidator);
    ui->lineEdit_7->setValidator(alnumValidator);
    ui->lineEdit_8->setValidator(alnumValidator);
    ui->lineEdit_9->setValidator(alnumValidator);

    //ui->toolButton_3->setStyleSheet("background-color:  #87CEEB;");
    //ui->toolButton_14->setStyleSheet("background-color:  #87CEEB;");
 

  
    ui->lineEdit->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_3->setFocusPolicy(Qt::NoFocus);
    ui->zdybutton->setIcon(QIcon("Resources/PICs/close2.png"));
    ui->zdybutton->setIconSize(QSize(31, 31));
    ui->zdybutton->setText(QString::fromLocal8Bit("关闭 "));
    ui->zdybutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->zdybutton_3->setIcon(QIcon("Resources/PICs/close2.png"));
    ui->zdybutton_3->setIconSize(QSize(31, 31));
    ui->zdybutton_3->setText(QString::fromLocal8Bit("关闭 "));
    ui->zdybutton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->zdybutton_2->setEnabled(true);

    SelectDB_Jgconfig();
    ui->lineEdit_15->setText(QString::number(jgconfig.interpolationStep));//设置插值步长
  
  
}





//控制界面拖动
bool QC_ApplicationWindow::eventFilter(QObject* obj, QEvent* evt)
{
    // 处理文件打开事件
    if (QEvent::FileOpen == evt->type()) {
        QFileOpenEvent* openEvent = static_cast<QFileOpenEvent*>(evt);
        slotFileOpen(openEvent->file(), RS2::FormatUnknown);
        return true;
    }

    // 处理鼠标拖动事件
    QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(evt);
    if (obj == this && mouse) {
        if (this->isMaximized()) {
            return true;
        }
        static bool dragFlag = false;
        static QPoint dragPoint(0, 0);
        if (mouse->button() == Qt::LeftButton && mouse->type() == QEvent::MouseButtonPress) {
            dragFlag = true;
            dragPoint = mouse->pos();
            return true;
        }
        else if (dragFlag && mouse->type() == QEvent::MouseMove) {
            this->move(mouse->globalPos() - dragPoint);
            return true;
        }
        else if (mouse->type() == QEvent::MouseButtonRelease) {
            dragFlag = false;
            return true;
        }
    }

    return QWidget::eventFilter(obj, evt);
}

//相机开关按钮
void QC_ApplicationWindow::CamerButton()
{
    if (!isOpenCam)
    {
        bool openresult = OpenCamer();
        if (openresult)
        {
            ui->toolButton->setText(QString::fromLocal8Bit("相机已连接"));
            ui->toolButton->setIcon(QIcon(":/PIC/Resources/PICs/online (2).png"));
            ui->toolButton->setIconSize(QSize(30, 30));
            ui->toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
           // ui->toolButton->setStyleSheet("background-color: rgb(0, 255, 0);");
           // ui->label_2->setStyleSheet("border-width: 15px;border-style: solid;border-color: rgb(0, 255, 0);");
            ui->label->setStyleSheet("background-color: rgb(0,255, 0);""color: black;");
            ui->label->setText(QString::fromLocal8Bit("相机就绪"));
            mtextlowerLeftx = 0;
            mtextlowerLefty = 0;
            mtexttotalWidth = ImageWidth;
            mtexttotalHeight = ImageHeight;
            SetROISimple(mtexttotalWidth, mtexttotalHeight, mtextlowerLeftx, mtextlowerLefty);
        }
        else
        {
            ui->toolButton->setText(QString::fromLocal8Bit("相机未连接"));
            ui->toolButton->setIcon(QIcon(":/PIC/Resources/PICs/offline (2).png"));
            ui->toolButton->setIconSize(QSize(30, 30));
            ui->toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
            ui->label->setStyleSheet("background-color: rgb(255,210,75);""color: black;");
          
            ui->label->setText(QString::fromLocal8Bit("相机断开"));
           // ui->toolButton->setStyleSheet("background-color: rgb(255, 0, 0);");
        }


    }
    else
    {
        CloseCamer();

        ui->toolButton->setText(QString::fromLocal8Bit("相机未连接"));
        ui->toolButton->setIcon(QIcon(":/PIC/Resources/PICs/offline (2).png"));
        ui->toolButton->setIconSize(QSize(30, 30));
        ui->toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui->label->setStyleSheet("background-color: rgb(255,210,75);""color: black;");
       
        ui->label->setText(QString::fromLocal8Bit("相机断开"));
      
    }
}
//打开相机
bool QC_ApplicationWindow::OpenCamer()
{
    if (!isOpenCam)
    {
        try
        {
            //UpdateCombobox();
            //初始化相机
            IGXFactory::GetInstance().Init();
           
            //枚举设备
            IGXFactory::GetInstance().UpdateDeviceList(1900, vectorDeviceInfo);
          
            if (0 == vectorDeviceInfo.size())
            {
                //ui->label->setText(QString::fromLocal8Bit("无可用相机!"));
                QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("初始化失败 "), QString::fromLocal8Bit("未检测到相机连接！ "), QMessageBox::Ok, this);
                msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
                msgBoxs->show();
                return 0;
            }
            //打开第一台设备以及设备下面第一个流
            ObjDevicePtr = IGXFactory::GetInstance().OpenDeviceBySN(
                vectorDeviceInfo[0].GetSN(),
                GX_ACCESS_EXCLUSIVE);
          
            ObjStreamPtr = ObjDevicePtr->OpenStream(0);

            //<采集回调对象
            pCaptureEventHandler = new CSampleCaptureEventHandler(this);
            ObjStreamPtr->RegisterCaptureCallback(pCaptureEventHandler, NULL);
            //注册设备掉线事件(目前只有千兆网系列相机支持此事件通知 )
            pDeviceOfflineEventHandler = new CSampleDeivceOfflineEventHandler(this);
            hDeviceOffline = ObjDevicePtr->RegisterDeviceOfflineCallback(pDeviceOfflineEventHandler, NULL);
            
            //获取远端设备属性控制器
            ObjFeatureControlPtr = ObjDevicePtr->GetRemoteFeatureControl();
            //设置心跳超时时间 6s
            ObjFeatureControlPtr->GetIntFeature("GevHeartbeatTimeout")->SetValue(1000);

            //获取相机最大分辨率
            ImageWidth = ObjFeatureControlPtr->GetIntFeature("WidthMax")->GetValue();
            ImageHeight = ObjFeatureControlPtr->GetIntFeature("HeightMax")->GetValue();
           
            //设置曝光时间(示例中写死us,只是示例,并不代表真正可工作参数，可以尝试，但是不要乱用)
            ObjFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(ExposureTime);
            //设置相机为触发模式并为软触发
            ObjFeatureControlPtr->GetEnumFeature("TriggerMode")->SetValue("On");
            ObjFeatureControlPtr->GetEnumFeature("TriggerSource")->SetValue("Line0");
            ObjFeatureControlPtr->GetEnumFeature("SharpnessMode")->SetValue("On");
            ObjFeatureControlPtr->GetFloatFeature("TriggerDelay")->SetValue(TriggerDelay);
            ObjFeatureControlPtr->GetEnumFeature("GainSelector")->SetValue("AnalogAll");
            ObjFeatureControlPtr->GetFloatFeature("Gain")->SetValue(GainValue);
            ObjFeatureControlPtr->GetFloatFeature("Sharpness")->SetValue(Sharpness);
           
            // ============ 新增：Line2连接控制 ============
        // 设置Line2为输出模式，用于联机状态指示
            ObjFeatureControlPtr->GetEnumFeature("LineSelector")->SetValue("Line2");
            ObjFeatureControlPtr->GetEnumFeature("LineMode")->SetValue("Output");

            // 明确设置Line2为TRUE（联机状态）
            ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(true);

            // 验证Line2状态
            Line2Status = ObjFeatureControlPtr->GetBoolFeature("LineStatus")->GetValue();
            if (Line2Status) {
                Logger::writeComm("相机打开 - Line2联机状态: TRUE");
            }
            else {
                Logger::writeComm("相机打开 - Line2联机状态: FALSE（警告）");
            }
            // ============Line1控制（原有功能） ============
            ObjFeatureControlPtr->GetEnumFeature("LineSelector")->SetValue("Line1");
            ObjFeatureControlPtr->GetEnumFeature("LineMode")->SetValue("Output");
           
            if (!ObjFeatureControlPtr->GetBoolFeature("LineStatus")->GetValue())
            {
                if (ObjFeatureControlPtr->GetBoolFeature("LineInverter")->GetValue())
                {
                    ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(false);
                }
                else
                {
                    ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(true);
                }
            }
            
            //判断图像对象是否为空
            if (m_pBitmap != NULL)
            {
             
                delete m_pBitmap;
            
                m_pBitmap = NULL;
            }
          
            //为画图对象分配内存
            m_pBitmap = new CGXBitmap(ObjDevicePtr);//为单帧采集开辟空间
            
            //提高网络相机的采集性能,设置方法参考以下代码（目前只有千兆网系列相机支持设置最优包长）
            GX_DEVICE_CLASS_LIST objDeviceClass = ObjDevicePtr->GetDeviceInfo().GetDeviceClass();
            if (GX_DEVICE_CLASS_GEV == objDeviceClass)
            {
                //判断设备是否支持流通道数据包功能
                if (true == ObjFeatureControlPtr->IsImplemented("GevSCPSPacketSize"))
                {
                    //获取当前网络环境的最优包长值
                    int nPacketSize = ObjStreamPtr->GetOptimalPacketSize();
                    //将最优包长值设置为当前设备的流通道包长值
                    ObjFeatureControlPtr->GetIntFeature("GevSCPSPacketSize")->SetValue(
                        nPacketSize);
                }
            }

            //发送开采命令
            ObjStreamPtr->StartGrab();
            ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
            statusBar()->showMessage(QString::fromLocal8Bit("相机连接成功!"), 3000); // 显示临时信息，时间3秒钟.
            isOpenCam = true;
            Logger::writeComm("打开相机");
           
            return 1;
        }
        catch (CGalaxyException& e)
        {
            QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("相机连接失败! "), QString::fromLocal8Bit("连接相机出错! "), QMessageBox::Ok);
            msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBoxs->show();
            Logger::writeComm("相机连接出错! ");
            return 0;
        }
    }
}
//关闭相机
void QC_ApplicationWindow::CloseCamer()
{
    if (isOpenCam)
    {
        try
        {
            //发送停采命令
            ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
            ObjStreamPtr->StopGrab();

            // ============ 新增：Line2断开连接 ============
            // 设置Line2为FALSE（脱机状态）
            if (ObjFeatureControlPtr->GetBoolFeature("LineStatus")->GetValue())
            {
                if (ObjFeatureControlPtr->GetBoolFeature("LineInverter")->GetValue())
                {
                    ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(false);
                }
                else
                {
                    ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(true);
                }
            }
            ObjFeatureControlPtr->GetEnumFeature("LineSelector")->SetValue("Line2");
            ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(false);

            //释放pCaptureEventHandler
            ObjStreamPtr->UnregisterCaptureCallback();
            delete pCaptureEventHandler;
            pCaptureEventHandler = NULL;

            //注销设备掉线事件
            ObjDevicePtr->UnregisterDeviceOfflineCallback(hDeviceOffline);

            if (m_pBitmap != NULL)//释放图片内存空间
            {
                delete m_pBitmap;
                m_pBitmap = NULL;
            }

            //释放资源
            ObjStreamPtr->Close();
            ObjDevicePtr->Close();
            if (vectorDeviceInfo.size() != 0)
            {
                vectorDeviceInfo.clear();
            }
            //反初始化库
            IGXFactory::GetInstance().Uninit();
            statusBar()->showMessage(QString::fromLocal8Bit("已断开相机连接！ "), 3000); // 显示临时信息，时间3秒钟.
            isOpenCam = false;
            Logger::writeComm("关闭相机");
        }
        catch (CGalaxyException& e)
        {
            Logger::writeComm("相机连接出错! ");
        }
    }
}

//拍照并运行OCR线程
void QC_ApplicationWindow::CapAndOcr()
{

    if (OCRT->isfinash)
    {
        if (CamTimerEnd)//滤波
        {
            OCRT->isfinash = false;
            emit OCRT->running(image, rot, rects, &RawResult, &RawResult2, &Time_str, &ocrresult, SCenabled, BZenabled, EWenabled, Start_Data_Time, 
                Save_Time, ui->comboBox_2->currentText(), IsCustom, QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr)), 
                QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_2)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_3)),
                QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_4)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_5)), 
                QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_6)), &ocr_time, FirstOCRSize, SecOCRSize);//触发working流程开始执行
         
        }
    }
    else
    {
        Logger::writeComm("检测过程中拍照 ");
    }
}
/**
 * @brief 简化版ROI设置（快速修复）
 */
bool QC_ApplicationWindow::SetROISimple(int width, int height,int x, int y ) {
    try {
        try {
            //发送停采命令
            ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
            ObjStreamPtr->StopGrab();
            QThread::msleep(200);
            // 2. 设置ROI
            ObjFeatureControlPtr->GetIntFeature("OffsetX")->SetValue(x);
            ObjFeatureControlPtr->GetIntFeature("OffsetY")->SetValue(y);
            ObjFeatureControlPtr->GetIntFeature("Width")->SetValue(width);
            ObjFeatureControlPtr->GetIntFeature("Height")->SetValue(height);
            // 4. 重新开始数据流
            ObjStreamPtr->StartGrab();
            // 3. 关键：重新发送采集开始命令
            ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();

            return true;
        }
        catch (const std::exception& e) {
            //发送停采命令
            ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
            ObjStreamPtr->StopGrab();
            QThread::msleep(200);
            // 2. 设置ROI
            ObjFeatureControlPtr->GetIntFeature("Width")->SetValue(width);
            ObjFeatureControlPtr->GetIntFeature("Height")->SetValue(height);
            ObjFeatureControlPtr->GetIntFeature("OffsetX")->SetValue(x);
            ObjFeatureControlPtr->GetIntFeature("OffsetY")->SetValue(y);
            // 4. 重新开始数据流
            ObjStreamPtr->StartGrab();
            // 3. 关键：重新发送采集开始命令
            ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();

            return true;
        }
    }
    catch (CGalaxyException& e)
    {
        isOpenCam = false;
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("相机连接出错! "), QString::fromLocal8Bit("相机连接出错,请重启打码软件\n和视觉软件! "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        Logger::writeComm("相机连接出错! ");
       
    }
    
}


//设置为硬触发
void QC_ApplicationWindow::TriggerLine0()
{
    if (!model && isOpenCam)
    {
        //发送停采命令
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
        ObjStreamPtr->StopGrab();
        ObjFeatureControlPtr->GetEnumFeature("TriggerMode")->SetValue("On");
        ObjFeatureControlPtr->GetEnumFeature("TriggerSource")->SetValue("Line0");
        model = 1;
        //发送开采命令
        ObjStreamPtr->StartGrab();
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
        statusBar()->showMessage(QString::fromLocal8Bit("当前为触发模式 "), 3000); // 显示临时信息，时间3秒钟.
        //setting.statusBar()->showMessage(QString::fromLocal8Bit("当前为触发模式 "), 3000); // 显示临时信息，时间3秒钟.
    }
    else if (isOpenCam) {
        //发送停采命令
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
        ObjStreamPtr->StopGrab();
        ObjFeatureControlPtr->GetEnumFeature("TriggerSource")->SetValue("Line0");
        model = 1;
        //发送开采命令
        ObjStreamPtr->StartGrab();
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
        statusBar()->showMessage(QString::fromLocal8Bit("当前为触发模式 "), 3000); // 显示临时信息，时间3秒钟.
        //setting.statusBar()->showMessage(QString::fromLocal8Bit("当前为触发模式 "), 3000); // 显示临时信息，时间3秒钟.
    }
    if (IsAutoCap)
    {
        Logger::write("关闭监控模式 ");
        IsAutoCap = false;
    }
}

void QC_ApplicationWindow::TriggerSoftware()
{
    if (isOpenCam)
    {
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
        ObjStreamPtr->StopGrab();
        ObjFeatureControlPtr->GetEnumFeature("TriggerSource")->SetValue("Software");
       
        //发送开采命令
        ObjStreamPtr->StartGrab();
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();

        Is_Cap_Finshed = true;
        ObjFeatureControlPtr->GetCommandFeature("TriggerSoftware")->Execute();
       
    }
}


//设置为自动采集
void QC_ApplicationWindow::AutoCap()
{
    try {
        //发送停采命令
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
        ObjStreamPtr->StopGrab();
        ObjFeatureControlPtr->GetEnumFeature("TriggerMode")->SetValue("Off");
        model = false;
        // 延时
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //发送开采命令
        ObjStreamPtr->StartGrab();
        ObjFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
    }
    catch (CGalaxyException& e)
    {
        isOpenCam = false;
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("相机连接出错! "), QString::fromLocal8Bit("相机连接出错,请重启打码软件\n和视觉软件! "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        Logger::writeComm("相机连接出错! ");
      
    }

    IsAutoCap = true;
    Logger::write("开启监控模式 ");

}

//显示设置页面
void QC_ApplicationWindow::ShowSetting()
{

  /*  if (!isOpenCam)
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Warning, QString::fromLocal8Bit("请先连接相机！"), QString::fromLocal8Bit("相机未连接，打开失败！"), QMessageBox::Ok, this);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        return;
    }*/
    if (!model) {
        TriggerLine0();
    }
    //FileUtils::SendBKBK(60, 1);
    FileUtils::SendBKBK("11","00", 1);
    string str = std::string(ui->comboBox->currentText().toLocal8Bit());
    if (str != "")
    {
        if (SelectDB(str) && SelectDB_Status())
        {
            setting.SetSetting(ExposureTime, rot, GainValue, Sharpness);

        }
    }

    IsSettingOpen = true;
    setting.schemeName = ui->comboBox->currentText();

    setting.show();
    setting.move(QApplication::desktop()->screen()->rect().center() - setting.rect().center());
    //this->hide();
    Logger::write("打开参数调整界面 ");
        
    
}

void QC_ApplicationWindow::ShowJgadmain()
{
  
    if (SelectDB_Jgconfig())
    {
        ui->lineEdit_15->setText(QString::number(jgconfig.interpolationStep));//扫描宽度
        jgadmin.setJgadmin(jgconfig.BMQzhijing, jgconfig.BMQmaichong, jgconfig.GdFilterTime, jgconfig.MinThresholdMode, jgconfig.MinTriggerTime, jgconfig.MinTriggerDistance,jgconfig.DelayTriggerMode, jgconfig.DelayTriggerTime, jgconfig.DelayTriggerDistance, jgconfig.DelayTriggerModetwo, jgconfig.DelayTriggerTimetwo, jgconfig.DelayTriggerDistancetwo, jgconfig.Dbchoice, jgconfig.interpolationStep, jgconfig.scanW_mm, jgconfig.BMQdirection, jgconfig.FXDBirection, jgconfig.Dbmode, jgconfig.JgFreq, jgconfig.JgPower,jgconfig.KgDelay,jgconfig.GgDelay, jgconfig.firstJumpDelay, jgconfig.jumpDelay, jgconfig.endDelay);
    }
    IsJgadminOpen = true;
    jgadmin.show();
    jgadmin.move(QApplication::desktop()->screen()->rect().center() - jgadmin.rect().center());
    //this->hide();
    Logger::write("打开激光参数界面 ");
}
void QC_ApplicationWindow::ShowXJadmain()
{

    string str = std::string(ui->comboBox->currentText().toLocal8Bit());
    if (str != "")
    {
        if (SelectDB(str) && SelectDB_Status())
        {
            xjadmin.SetSetting(jgconfig.BMQzhijing, jgconfig.BMQmaichong, GapCount, DelayModel, DelayTime, DelayDistance, DCLength, OutputLocationMin, OutputLocationMax, KeepCount, R, G, B, RGBTime, RGBMode, jgconfig.MinThresholdMode, jgconfig.MinTriggerTime, jgconfig.MinTriggerDistance, jgconfig.DelayTriggerModetwo, jgconfig.DelayTriggerTimetwo, jgconfig.DelayTriggerDistancetwo);

        }
    }
    IsxjadminOpen = true;
    xjadmin.show();
    xjadmin.move(QApplication::desktop()->screen()->rect().center() - jgadmin.rect().center());
    //this->hide();
    Logger::write("打开检测参数界面 ");
}

void QC_ApplicationWindow::ShowUser()
{
    User.show();

    SelectUser(USERname);
    User.setUser(Userindex, userinfo.PenMa, userinfo.LiuShuixian, userinfo.Chufa, userinfo.FangZhen, userinfo.PeiFang, userinfo.xiangJi, userinfo.CDL, userinfo.YongHu, userinfo.BianJi, TraverseUsernum, Name);

    User.move(QApplication::desktop()->screen()->rect().center() - User.rect().center());
    //this->hide();
    Logger::write("打开用户界面 ");

}
//显示主页面
void QC_ApplicationWindow::ShowThis()
{
    if (IsAutoCap)
    {
        TriggerLine0();
    }
    if (IsSettingOpen)
    {
        
            QMessageBox* msgBox = new QMessageBox(QMessageBox::Question, QString::fromLocal8Bit("是否保存方案 "), QString::fromLocal8Bit("是否保存修改内容？ "), QMessageBox::Ok, &setting);
            msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("保存并返回 "));
            msgBox->setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("直接返回 "));
            if (msgBox->exec() == QMessageBox::Ok)
            {
              
               
               // AlterDB_Jgconfig();//更新数据库
                AlterScheme();
                IsSettingOpen = false;
                this->show();
                setting.hide();
                IsAlter = false;
                SetScheme(ui->comboBox->currentText());
               
                Logger::write("保存方案并返回 ");
              
            }
            else
            {
                IsSettingOpen = false;
                this->show();
                setting.hide();
                IsAlter = false;
                SetScheme(ui->comboBox->currentText());
            }

         //FileUtils::SendBKBK(60, RGBMode);
         FileUtils::SendBKBK("11","00", RGBMode);
        Logger::write("关闭参数设置界面 ");
    }
   
   
}



//向设置页面传图像
void QC_ApplicationWindow::SubCapture()
{
    if (!CamTimerEnd)
    {
        return;
    }
    //判断ROI区域是否过界
    //QImage SubImage = QImage((unsigned char*)resizeImage.data, resizeImage.cols, resizeImage.rows, resizeImage.step, QImage::Format_BGR888);
    QImage SubImage = QImage((unsigned char*)image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    QTransform matrix;
    matrix.rotate(rot);
    SubImage = SubImage.transformed(matrix, Qt::FastTransformation);
    if (IsSettingOpen)
    {
        setting.setbackground(SubImage);
        if (Is_Cap_Finshed)
        {
            TriggerLine0();
            Is_Cap_Finshed = false;
        }
    }
   
}
//设置ROI参数
void QC_ApplicationWindow::SetRect()
{
    QRect OCRrect = setting.mygetrect();
    // 1. 获取旋转后的图像尺寸
    QImage SubImage = QImage((unsigned char*)image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    QTransform matrix;
    matrix.rotate(rot);
    SubImage = SubImage.transformed(matrix, Qt::FastTransformation);
    // 直接计算反向映射
    int originalX = static_cast<int>(OCRrect.x() / ImageSize);
    int originalY = static_cast<int>(OCRrect.y() / ImageSize);
    int originalWidth = static_cast<int>(OCRrect.width() / ImageSize);
    int originalHeight = static_cast<int>(OCRrect.height() / ImageSize);

    // 边界检查（针对原始图像）
    if (originalX < 0 || originalY < 0 ||
        originalX + originalWidth >  SubImage.width() ||
        originalY + originalHeight > SubImage.height() ||
        originalWidth == 0 || originalHeight == 0) {

        setting.alarmrect(false);
       
        return;
    }
    // 设置ROI
    rectX = originalX;
    rectY = originalY;
    rectW = originalWidth;
    rectH = originalHeight;
    cv::Rect rect2(rectX, rectY, rectW, rectH);
    rects = rect2;
    setting.alarmrect(true);
    IsAlter = true;

}

//设置曝光时间
void QC_ApplicationWindow::SetExposureTime()
{
    if (IsSettingOpen)
    {
        ExposureTime = setting.getExposureTime();
    }
  

    if (isOpenCam)
    {
        ObjFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(ExposureTime);
    }

    IsAlter = true;
}


//设置锐度值
void QC_ApplicationWindow::SetSharpness()
{
    if (setting.getSharpness() == "")
    {
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("锐化数值不能为空  "), QString::fromLocal8Bit("锐化数值不能为空,请\n重试! "), QMessageBox::Ok, &setting);
        msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBox->show();
        return;
    }
    QRegularExpression regex("^\\d+$");
    QRegularExpressionMatch match = regex.match(setting.getSharpness());
    if (!match.hasMatch())
    {
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("锐化数值错误  "), QString::fromLocal8Bit("锐化数值必须为纯数字,请\n重试! "), QMessageBox::Ok, &setting);
        msgBox->button(QMessageBox::Ok)->setText(tr("确定 "));
        msgBox->show();
        return;
    }
    if (setting.getSharpness().toDouble() < 0 || setting.getSharpness().toDouble() > 3)
    {
        if (IsSettingOpen)
        {
            setting.alarmSharpness(false);
        }
        return;
    }
    Sharpness = setting.getSharpness().toDouble();
    if (isOpenCam)
    {
        ObjFeatureControlPtr->GetFloatFeature("Sharpness")->SetValue(Sharpness);
    }

    if (IsSettingOpen)
    {
        setting.alarmSharpness(true);
        IsAlter = true;
    }
}
//设置增益值
void QC_ApplicationWindow::SetGainValue()
{
    if (IsSettingOpen)
    {
        GainValue = setting.getGainValue();
    }
    if (isOpenCam)
    {
        ObjFeatureControlPtr->GetFloatFeature("Gain")->SetValue(GainValue);
    }
    IsAlter = true;
}
//设置旋转角
void QC_ApplicationWindow::SetRot()
{
    int index = setting.getRot();
    if (index == 1) {
        rot = 90;
    }
    else if (index == 2) {
        rot = 180;
    }
    else if (index == 3) {
        rot = 270;
    }
    else if (index == 0) {
        rot = 0;
    }
    IsAlter = true;

    rectX = 50;
    rectY = 50;
    rectW = 100;
    rectH = 50;
    cv::Rect rect2(rectX, rectY, rectW, rectH);
    rects = rect2;
    QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("操作完成 "), QString::fromLocal8Bit("已旋转图像,请重新框选区域 "), QMessageBox::Ok, &setting);
    msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
    msgBox->show();

}

//void QC_ApplicationWindow::SetFirstOCRSize()
//{
//    FirstOCRSize = setting.getFirstOCRSize();
//    IsAlter = true;
//}
//void QC_ApplicationWindow::SetSecOCRSize()
//{
//    SecOCRSize = setting.getSecOCRSize();
//    IsAlter = true;
//}
//
//void QC_ApplicationWindow::SetImageSize()
//{
//    if (!setting.isfistopen)
//    {
//        ImageSize = setting.getImageSize();
//        SaveImageSize(ImageSize);
//        rectX = 10;
//        rectY = 10;
//        rectW = 20;
//        rectH = 20;
//        cv::Rect rect2(rectX, rectY, rectW, rectH);
//        rects = rect2;
//        IsAlter = true;
//    }
//}



//OK操作
void QC_ApplicationWindow::Pass()
{
    //ui->label_2->setStyleSheet("border-width: 15px;border-style: solid;border-color: rgb(0, 255, 0);");
    ui->label->setStyleSheet("background-color: rgb(0, 255, 0);""color: black;");
  
    ui->label->setText(QString::fromLocal8Bit("OK"));
  

    OKnum++;
    Totalnum++;
    RateUpdate();
}
//NG操作
void QC_ApplicationWindow::NG()
{
   // ui->label_2->setStyleSheet("border-width: 15px;border-style: solid;border-color: rgb(255, 0, 0);");
    ui->label->setStyleSheet("background-color: rgb(255, 0, 0);""color: black;");
   
    ui->label->setText(QString::fromLocal8Bit("NG"));
   // Count[PreCounter % 20] = false;

    if (IsOpenAlarm && isOpenCam)
    {
        if (ObjFeatureControlPtr->GetBoolFeature("LineStatus")->GetValue())
        {
            if (ObjFeatureControlPtr->GetBoolFeature("LineInverter")->GetValue())
            {
                ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(false);
                Sleep(100);
                ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(true);
            
              
            }
            else
            {
                ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(true);
                Sleep(100);
                ObjFeatureControlPtr->GetBoolFeature("LineInverter")->SetValue(false);
         
               
               
            }
        }
    }

  
    NGnum++;
    Totalnum++;
    RateUpdate();
}


//重新刷新方案栏项
void QC_ApplicationWindow::UpdateCombobox()
{
    ComboxMark = true;
    ui->comboBox->clear();
    QString qstr;
    for (int i = 0; i < Traverse(); i++)
    {
        qstr = QString::fromLocal8Bit(SchemeName[i].c_str());
        ui->comboBox->addItem(qstr);
    }
    ComboxMark = false;
}
//删除方案
void QC_ApplicationWindow::DeleteCombobox()
{
    //输入密码
    QInputDialog inputpsw(&alterscheme);
    inputpsw.setFixedSize(350, 300);
    inputpsw.setWindowTitle(QString::fromLocal8Bit("输入密码"));
    //inputpsw.setLabelText(QString::fromLocal8Bit("请输入密码:"));
    inputpsw.setStyleSheet("QLabel { font-size: 18pt; } QLineEdit { font-size: 18pt; }");
    inputpsw.setLabelText(QString::fromLocal8Bit("请输入111111确认删除配方!"));
    inputpsw.setOkButtonText(QString::fromLocal8Bit("确定"));
    inputpsw.setCancelButtonText(QString::fromLocal8Bit("取消"));
    QLineEdit* lineEdit = inputpsw.findChild<QLineEdit*>();
    if (lineEdit)
    {
        lineEdit->setStyleSheet("QLineEdit{width:200px;height:30px}");
    }
    inputpsw.setInputMode(QInputDialog::TextInput);
    if (inputpsw.exec() == QInputDialog::Accepted)
    {
        char* finaltime = const_cast<char*>("%Y%m%d");
        string thistime = get_date(finaltime, 0);
        /*if (inputpsw.textValue() != QString::fromLocal8Bit(thistime))*/
        if (inputpsw.textValue() != "111111")
        {
            QMessageBox* errorBox = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("密码错误 "), QString::fromLocal8Bit("密码错误!请重试 "), QMessageBox::Ok, &setting);
            errorBox->setFixedSize(400, 400);
            errorBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            errorBox->show();
            return;
        }
    }
    else
    {
        return;
    }

    if (ui->comboBox->currentIndex() != 0)
    {
        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        if (DeleteDB(delestr) && DeleteSchemeContent(delestr))
        {
            QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("操作完成 "), QString::fromLocal8Bit("成功删除配方！ "), QMessageBox::Ok, &setting);
            msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBoxs->show();

            UpdateCombobox();
            IsAlter = false;
            alterscheme.hide();
            SetScheme(ui->comboBox->currentText());
            Logger::write("删除配方:" + delestr);
        }
        else
        {
            QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("删除配方失败！ "), QMessageBox::Ok, &setting);
            msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBoxs->show();
        }
    }
    else {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("无法删除默认配方！ "), QMessageBox::Ok, &setting);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
    }
}
//设置方案
void QC_ApplicationWindow::SetScheme(QString schemetext)
{
    string str = std::string(schemetext.toLocal8Bit());
    if (str == "")
    {
        return;
    }
    if (SelectDB(str) && SelectDB_Status()&& SelectDB_Jgconfig())
    {
        ExposureTime = config.ExposureTime;
      //  TriggerDelay = config.TriggerDelay;
        Sharpness = config.Sharpness;
        rectX = config.rectX;
        rectY = config.rectY;
        rectW = config.rectW;
        rectH = config.rectH;
        rot = config.rot;
        GapCount = config.GapCount;
        KeepCount = config.KeepCount;
        GainValue = config.GainValue;
        CodeIndex = config.CodeIndex;
        DelayModel = config.DelayModel;
        DelayTime = config.DelayTime;
        DCLength = config.DCLength;
        FirstOCRSize = config.FirstOCRSize;
        SecOCRSize = config.SecOCRSize;
        OutputLocationMin = config.OutputLocationMin;
        OutputLocationMax = config.OutputLocationMax;
        R = config.R;
        G = config.G;
        B = config.B;
        RGBTime = config.RGBTime;
        RGBMode = config.RGBMode;
      
        cv::Rect rect2(rectX, rectY, rectW, rectH);
        rects = rect2;


         MaxThresholdAlermOpen = runningstatus.MaxThresholdAlermOpen;//上限报警
         MinThresholdAlermOpen = runningstatus.MinThresholdAlermOpen;//下限报警
         cameraAlarmOpen = runningstatus.cameraAlarmOpen;//相机报警
         markingOutOfAreaOpen = runningstatus.markingOutOfAreaOpen;//标刻区域外报警

         linkTXOpen = runningstatus.linkTXOpen;//通讯联机功能启用
         linkBKBKOpen = runningstatus.linkBKBKOpen;//标刻联机功能启用
         linkCameraOpen = runningstatus.linkCameraOpen;//相机联机功能启用

       
        ///////////////////////////////////////////////////////////////////////////////
       /* if (IsFirstOpenSoft)
        {*/
             FileUtils::Sendmarking();
             QThread::msleep(10); // 短暂延迟
             FileUtils::Sendkey();
             QThread::msleep(10); // 短暂延迟
             FileUtils::Sendall();
             QThread::msleep(10); // 短暂延迟
             FileUtils::Sendphoto();
             QThread::msleep(10); // 短暂延迟
             FileUtils::Sendalarm();
     
           /* IsFirstOpenSoft = false;
        }*/
    
        if (isOpenCam)
        {
            ObjFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(ExposureTime);
            ObjFeatureControlPtr->GetFloatFeature("TriggerDelay")->SetValue(TriggerDelay * 1000);
            ObjFeatureControlPtr->GetFloatFeature("Sharpness")->SetValue(Sharpness);
            ObjFeatureControlPtr->GetFloatFeature("Gain")->SetValue(GainValue);
        }
        statusBar()->showMessage(QString::fromLocal8Bit("当前配方为: ") + schemetext, 3000); // 显示临时信息，时间3秒钟.

        SetSchemeContent(schemetext);

        if (!ComboxMark)
        {
            SaveNameCode(ui->comboBox->currentIndex());
        }
        IsSchemeComboBoxcode = true;
        ui->comboBox_2->setCurrentIndex(CodeIndex);
        FH = ui->comboBox_2->currentText();
        IsSchemeComboBoxcode = false;
      
    }
    else
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("更改配方失败！ "), QMessageBox::Ok, this);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
    }
}
//更改方案
void QC_ApplicationWindow::ChangeScheme()
{
    if (!ComboxMark)
    {
        SetScheme(ui->comboBox->currentText());
        if (ui->comboBox->currentIndex() != 0)
        {
           // ui->comboBox_3->setCurrentIndex(1);
            ui->tabWidget->setCurrentIndex(1);
        }
        else
        {
            //ui->comboBox_3->setCurrentIndex(0);
            ui->tabWidget->setCurrentIndex(0);
        }
        IsCustom = false;
        ui->zdybutton_2->setEnabled(true);
       

        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);

        ui->zdybutton->setIcon(QIcon("Resources/PICs/close2.png"));
        ui->zdybutton->setIconSize(QSize(31, 31));
        ui->zdybutton->setText(QString::fromLocal8Bit("关闭 "));
        ui->zdybutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->zdybutton_3->setIcon(QIcon("Resources/PICs/close2.png"));
        ui->zdybutton_3->setIconSize(QSize(31, 31));
        ui->zdybutton_3->setText(QString::fromLocal8Bit("关闭 "));
        ui->zdybutton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        Logger::write("切换当前配方为:" + std::string(ui->comboBox->currentText().toLocal8Bit()));
    }
}

//创建方案
void QC_ApplicationWindow::CreateScheme()
{
   
        CustomStr = "";
        CustomStr_2 = "";
        CustomStr_3 = "";
        CustomStr_4 = "";
        CustomStr_5 = "";
        CustomStr_6 = "";
        string str = std::string(addscheme.SCHEME.toLocal8Bit());
       
        rectX = addscheme.rectX;
        rectY = addscheme.rectY;
        rectW = addscheme.rectW;
        rectH = addscheme.rectH;
        GapCount = addscheme.GapCount;
        DCLength = addscheme.DCLength;
        OutputLocationMin = addscheme.OutputLocationMin;
        OutputLocationMax = addscheme.OutputLocationMax;
        
        jgconfig.DelayTriggerMode= addscheme.DelayTriggerMode;
        jgconfig.DelayTriggerTime= addscheme.DelayTriggerTime;
        jgconfig.DelayTriggerDistance= addscheme.DelayTriggerDistance;
        jgconfig.DelayTriggerModetwo= addscheme.DelayTriggerModetwo;
        jgconfig.DelayTriggerTimetwo= addscheme.DelayTriggerTimetwo;
        jgconfig.DelayTriggerDistancetwo= addscheme.DelayTriggerDistancetwo;
        cv::Rect rect2(rectX, rectY, rectW, rectH);
        rects = rect2;
        bool result0 = InsertSchemeContent(str);
        bool result = InsertDB(str);
        bool result1 = AlterDB_Jgconfig();
        if (result0 && result)
        {
            setting.insertDBresult(result);
            std::string defaultstr = "新增配方:" + str + "\n配方参数为:\n ";
            defaultstr.append("\t曝光时间: " + to_string(ExposureTime) + "\n");
            defaultstr.append("\t拍照延迟: " + to_string(TriggerDelay) + "\n");
            defaultstr.append("\t增益: " + to_string(GainValue) + "\n");
            defaultstr.append("\t锐度值: " + to_string(Sharpness) + "\n");
            defaultstr.append("\tROI区域: " + to_string(rectX) + "," + to_string(rectY) + "," + to_string(rectW) + "," + to_string(rectH) + "\n");
            defaultstr.append("\t旋转角度: " + to_string(rot) + "\n");
            defaultstr.append("\t间隔数: " + to_string(GapCount) + "\n");
            defaultstr.append("\t报警时长: " + to_string(KeepCount) + "\n");
            defaultstr.append("\t延迟模式: " + to_string(DelayModel) + "\n");
            defaultstr.append("\t时间延迟值: " + to_string(DelayTime) + "\n");
            defaultstr.append("\t距离延迟值: " + to_string(DelayDistance) + "\n");
            defaultstr.append("\t袋长: " + to_string(DCLength) + "\n");
            defaultstr.append("\t首次缩放比: " + to_string(FirstOCRSize) + "\n");
            defaultstr.append("\t二次缩放比: " + to_string(SecOCRSize) + "\n");
            defaultstr.append("\t输出位置: " + to_string(OutputLocationMin) + "," + to_string(OutputLocationMax));
            //defaultstr.append("\t字符代码: " + setting.getFH().toStdString());

            ui->comboBox->addItem(addscheme.SCHEME);
            int schemeindex = ui->comboBox->findText(addscheme.SCHEME);
            ui->comboBox->setCurrentIndex(schemeindex);

            SaveNameCode(ui->comboBox->currentIndex());
            IsAlter = false;
            this->show();
            addscheme.hide();
            Logger::write(defaultstr);
        }
        else
        {
            setting.insertDBresult(result);
            Logger::writeError("新增配方失败 ");
        }
    
}
//打开配方参数修改界面
void QC_ApplicationWindow::OpenAlterScheme()
{
    alterscheme.SetAlterScheme(ui->comboBox->currentText(), DCLength, GapCount, LocationScale, OutputLocationMax, OutputLocationMin, jgconfig.DelayTriggerMode, jgconfig.DelayTriggerModetwo, jgconfig.DelayTriggerTime, jgconfig.DelayTriggerTimetwo, jgconfig.DelayTriggerDistance, jgconfig.DelayTriggerDistancetwo);
    alterscheme.show();
    Logger::write("打开现场人员配方参数管理页面 ");
}

void QC_ApplicationWindow::ChangeSchemeName()
{
    QString waitaltername = alterscheme.GetSchemeName();
    //判断方案名是否存在
    string str = std::string(waitaltername.toLocal8Bit());
    int findname = SelectSchName(str);
    if (findname > 0)
    {
        alterscheme.AlterSchemeNameResult(false);
    }
    else
    {
        if (ui->comboBox->currentIndex() != 0)
        {
            QString pre_alter_name = ui->comboBox->currentText();
            string Pre_Alter_Name = std::string(pre_alter_name.toLocal8Bit());
            int altername_result = AlterSchemeName(Pre_Alter_Name, str);
            if (altername_result)
            {
                alterscheme.SCHEME = waitaltername;
                ui->comboBox->setItemText(ui->comboBox->currentIndex(), waitaltername);
                alterscheme.AlterSchemeNameResult(true);
            }
        }
    }
}
//修改配方后保存参数
void QC_ApplicationWindow::SaveAlterScheme()
{
    QString SCHEME;
   

    GapCount = alterscheme.GapCount;
    DCLength = alterscheme.DCLength;//袋长
    LocationScale = alterscheme.LocationScale;//最大最小距离比例
    OutputLocationMax = alterscheme.OutputLocationMax;
    OutputLocationMin = alterscheme.OutputLocationMin;
    jgconfig.DelayTriggerMode = alterscheme.DelayTriggerMode;
    jgconfig.DelayTriggerTime = alterscheme.DelayTriggerTime;
    jgconfig.DelayTriggerDistance = alterscheme.DelayTriggerDistance;
    jgconfig.DelayTriggerModetwo = alterscheme.DelayTriggerModetwo;
    jgconfig.DelayTriggerTimetwo = alterscheme.DelayTriggerTimetwo;
    jgconfig.DelayTriggerDistancetwo = alterscheme.DelayTriggerDistancetwo;


    bool result = AlterDB(std::string(alterscheme.SCHEME.toLocal8Bit()));
    bool result1 = AlterDB_Jgconfig();
    if (result && result1)
    {
        //SetScheme(ui.comboBox->currentText());
        //IsAlter = false;
        std::string defaultstr = "现场人员修改配方:" + std::string(setting.schemeName.toLocal8Bit()) + "\n修改后配方参数为:\n ";
        defaultstr.append("\t曝光时间: " + to_string(ExposureTime) + "\n");
        defaultstr.append("\t拍照延迟: " + to_string(TriggerDelay) + "\n");
        defaultstr.append("\t增益: " + to_string(GainValue) + "\n");
        defaultstr.append("\t锐度值: " + to_string(Sharpness) + "\n");
        defaultstr.append("\tROI区域: " + to_string(rectX) + "," + to_string(rectY) + "," + to_string(rectW) + "," + to_string(rectH) + "\n");
        defaultstr.append("\t旋转角度: " + to_string(rot) + "\n");
        defaultstr.append("\t间隔数: " + to_string(GapCount) + "\n");
        defaultstr.append("\t报警时长: " + to_string(KeepCount) + "\n");
        defaultstr.append("\t袋长: " + to_string(DCLength) + "\n");
        defaultstr.append("\t间隔距离比例: " + to_string(LocationScale) + "\n");
        Logger::write(defaultstr);
    }
    
}
void QC_ApplicationWindow::AlterScheme()
{
    string schemename;
    bool result = 0;
    if (IsSettingOpen)
    {
        schemename = std::string(setting.schemeName.toLocal8Bit());
       
            result = AlterDB(std::string(setting.schemeName.toLocal8Bit()));
            if (result)
            {
              
                QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("修改成功 "), QString::fromLocal8Bit("配方更新成功! "), QMessageBox::Ok, &setting);
                msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
                msgBoxs->show();
                IsAlter = false;
                std::string defaultstr = "修改配方:" + schemename + "\n修改后配方参数为:\n ";
                defaultstr.append("\t曝光时间: " + to_string(ExposureTime) + "\n");
                defaultstr.append("\t拍照延迟: " + to_string(TriggerDelay) + "\n");
                defaultstr.append("\t增益: " + to_string(GainValue) + "\n");
                defaultstr.append("\t锐度值: " + to_string(Sharpness) + "\n");
                defaultstr.append("\tROI区域: " + to_string(rectX) + "," + to_string(rectY) + "," + to_string(rectW) + "," + to_string(rectH) + "\n");
                defaultstr.append("\t旋转角度: " + to_string(rot) + "\n");
                defaultstr.append("\t间隔数: " + to_string(GapCount) + "\n");
                defaultstr.append("\t报警时长: " + to_string(KeepCount) + "\n");
                defaultstr.append("\t延迟模式: " + to_string(DelayModel) + "\n");
                defaultstr.append("\t时间延迟值: " + to_string(DelayTime) + "\n");
                defaultstr.append("\t距离延迟值: " + to_string(DelayDistance) + "\n");
                defaultstr.append("\t袋长: " + to_string(DCLength) + "\n");
                defaultstr.append("\t首次缩放比: " + to_string(FirstOCRSize) + "\n");
                defaultstr.append("\t二次缩放比: " + to_string(SecOCRSize) + "\n");
              
                defaultstr.append("\t输出位置: " + to_string(OutputLocationMin) + "," + to_string(OutputLocationMax));
                Logger::write(defaultstr);
            }
     
    }
    if (IsxjadminOpen)
    {
       
        schemename = std::string(ui->comboBox->currentText().toLocal8Bit());
        result = AlterDB(schemename);
       
        if (result)
        {
           
            IsAlter = false;
            std::string defaultstr = "修改配方:" + schemename + "\n修改后配方参数为:\n ";
            defaultstr.append("\t曝光时间: " + to_string(ExposureTime) + "\n");
            defaultstr.append("\t拍照延迟: " + to_string(TriggerDelay) + "\n");
            defaultstr.append("\t增益: " + to_string(GainValue) + "\n");
            defaultstr.append("\t锐度值: " + to_string(Sharpness) + "\n");
            defaultstr.append("\tROI区域: " + to_string(rectX) + "," + to_string(rectY) + "," + to_string(rectW) + "," + to_string(rectH) + "\n");
            defaultstr.append("\t旋转角度: " + to_string(rot) + "\n");
            defaultstr.append("\t间隔数: " + to_string(GapCount) + "\n");
            defaultstr.append("\t报警时长: " + to_string(KeepCount) + "\n");
            defaultstr.append("\t延迟模式: " + to_string(DelayModel) + "\n");
            defaultstr.append("\t时间延迟值: " + to_string(DelayTime) + "\n");
            defaultstr.append("\t距离延迟值: " + to_string(DelayDistance) + "\n");
            defaultstr.append("\t袋长: " + to_string(DCLength) + "\n");
            defaultstr.append("\t首次缩放比: " + to_string(FirstOCRSize) + "\n");
            defaultstr.append("\t二次缩放比: " + to_string(SecOCRSize) + "\n");
          
            defaultstr.append("\t输出位置: " + to_string(OutputLocationMin) + "," + to_string(OutputLocationMax));
            Logger::write(defaultstr);
        }
    }

}
//保存NG图片
void QC_ApplicationWindow::SaveNG()
{
    // 获取C盘的可用空间
    QStorageInfo storageInfo("D:");
    qint64 availableSpace = storageInfo.bytesAvailable();

    if (availableSpace <= 10737418240) {
        QString path = "./NG_Pictures";  // 替换为你要查找的路径
        manager.startDeletion(path);
    }

    std::string DirName = get_date(const_cast<char*>("%Y_%m_%d"), 0);
    std::string PicName = get_date(const_cast<char*>("%Y_%m_%d_%H_%M_%S"), 0);
    std::string dir = "./NG_Pictures/" + DirName; //PAHT为文件夹路径
    if (access(dir.c_str(), 0) == -1)
    { //判断该文件夹是否存在
#ifdef WIN32
        int flag = mkdir(dir.c_str());  //Windows创建文件夹
#else
        int flag = mkdir(dir.c_str(), S_IRWXU);  //Linux创建文件夹
#endif
        if (flag == 0)
        {  //创建成功
            Logger::write("新建当日NG图片文件夹成功! ");
            //std::cout << "Create directory successfully." << std::endl;
        }
        else
        { //创建失败
            Logger::writeError("新建当日NG图片文件夹失败! ");
            //std::cout << "Fail to create directory." << std::endl;
            throw std::exception();
        }
    }
    else
    {
        //std::cout << "This directory already exists." << std::endl;
    }
    string save_pic = dir + "/bad_" + PicName + ".bmp";
    m_pBitmap->SaveBmp(objImageDataPointer, save_pic);   
}


void QC_ApplicationWindow::ViewRecord()
{
    viewer.show();
}
//选择仿真文件夹
void QC_ApplicationWindow::Simulate()
{
    ImageList.clear();
    ImageListIndex = 0;
    // 获取文件夹路径
    QString Qfilepath = QFileDialog::getExistingDirectory(this,
        "Select Dir",
        "./NG_Pictures/");
    string filepath = std::string(Qfilepath.toLocal8Bit()) + "/";
    string suffix = "*.bmp";//后缀名
    ImageList = getImageList(filepath, suffix);
    QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("操作完成 "), QString::fromLocal8Bit("成功选择文件夹 "), QMessageBox::Ok, this);
    msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
    msgBoxs->show();
    Logger::write("选择仿真文件夹 ");
}

//只OCR不报警，用于仿真
void QC_ApplicationWindow::OnlyOcr()
{
    if (ImageList.size() != 0 && ImageListIndex < ImageList.size())
    {
        cv::Mat simulateImg;                    // OpenCV矩阵，存储仿真图片
        simulateImg = cv::imread(ImageList[ImageListIndex]);
       
        if (OCRT->isfinash)
        {
            OCRT->isfinash = false;
            emit OCRT->running(simulateImg, rot, rects, &RawResult, &RawResult2, &Time_str, &ocrresult, SCenabled, BZenabled, EWenabled, Start_Data_Time, Save_Time, ui->comboBox_2->currentText(), IsCustom, QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_2)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_3)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_4)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_5)), QString::fromLocal8Bit(QByteArray::fromStdString(CustomStr_6)), &ocr_time, FirstOCRSize, SecOCRSize);//触发working流程开始执行
 
        }
        IsOnlyOcr = true;
      
    }
    else
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("全部仿真完成 "), QString::fromLocal8Bit("请重新选择文件夹 "), QMessageBox::Ok, this);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        Logger::write("仿真完成 ");
    }
}
//更新数据栏
void QC_ApplicationWindow::RateUpdate()
{
   
    //ui->label_13->setText(QString::number((double(int(OKnum * 10000 / Totalnum))) / 100) + "%");
    // 设置数据（与图片中类似）
    QMap<QString, double> data;
    data["NG"] = NGnum;
    data["OK"] = OKnum;
    data[QString::fromLocal8Bit("总数")] = Totalnum;
  
    chart->setData(data);
   
  
}
//清空数据栏
void QC_ApplicationWindow::RateClear()
{
    std::string defaultstr = "清空数据栏，清空前数据为:\n总数: " + to_string((int)Totalnum) + "\t合格数:" + to_string((int)OKnum) + "\t不良数:" + to_string((int)NGnum);
    Totalnum = 0;
    OKnum = 0;
    NGnum = 0;
    //ui->label_10->setText(QString::number(Totalnum));
  
    //ui->label_13->setText("0%");
    // 设置数据（与图片中类似）
    QMap<QString, double> data;
    data["NG"] = NGnum;
    data["OK"] = OKnum;
    data[QString::fromLocal8Bit("Sum")] = Totalnum;
    
    chart->setData(data);
   

    Logger::write(defaultstr);
}

void QC_ApplicationWindow::SelectTime()
{
    //确认弹窗
    QDialog dialog;
    dialog.setWindowTitle(QString::fromLocal8Bit("选择日期 "));
    dialog.resize(700, 350);

    RollingBox timebox(&dialog);

    //使用QDialogButtonBox简化按钮的创建和连接
    QDialogButtonBox* buttonBox = new QDialogButtonBox(&dialog);
    buttonBox->setGeometry(220, 200, 300, 200);

    QPushButton* okButton = new QPushButton(QString::fromLocal8Bit("确定 "));
    QPushButton* cancelButton = new QPushButton(QString::fromLocal8Bit("取消 "));
    buttonBox->addButton(okButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::ActionRole);
    buttonBox->setStyleSheet("QPushButton { margin-right: 50px; width: 100px; height: 50px; }");

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    int ret = dialog.exec();
    //根据选择进行响应
    if (ret == QDialog::Accepted) {
        year = timebox.readYear();
        month = timebox.readMonth();
        day = timebox.readDay();
        QString year_str, month_str, day_str;
        if (year < 10)
        {
            year_str = "0" + QString::number(year);
        }
        else {
            year_str = QString::number(year);
        }
        if (month < 10)
        {
            month_str = "0" + QString::number(month);
        }
        else {
            month_str = QString::number(month);
        }
        if (day < 10)
        {
            day_str = "0" + QString::number(day);
        }
        else {
            day_str = QString::number(day);
        }

        Start_Data_Time = year_str + month_str + day_str;
        ui->lineEdit->setText(Start_Data_Time);
        Save_Time = CaculateTime(year, month, day, save_time, Savemonth, Saveyear);
        ui->lineEdit_3->setText(Save_Time);
    }
}

QString QC_ApplicationWindow::CaculateTime(int year, int month, int day, int save_days, int save_months, int save_years)
{
   

    QDate originalDate(year, month, day);
  
    // 1. 先应用年偏移
    QDate targetDate = originalDate.addYears(save_years);
  
   // . 先计算月份偏移

    targetDate = targetDate.addMonths(save_months);
 
  // 2. 判断原日期是否为月末

    bool isOriginalEndOfMonth = (originalDate.day() == originalDate.daysInMonth());
    // 3. 处理日期调整
    if (isOriginalEndOfMonth) {
        // 原日期是月末：目标日期也应该是月末，但需要处理2月等特殊情况
        int targetDaysInMonth = targetDate.daysInMonth();
        int originalDay = originalDate.day();

        // 如果目标月的天数 >= 原日期的天数，使用原日期的天数
        if (targetDaysInMonth >= originalDay) {
            targetDate = QDate(targetDate.year(), targetDate.month(), originalDay);

            // 特殊处理：如果设置日期后无效（如2月30日），则使用目标月最后一天
            if (!targetDate.isValid()) {
                targetDate = QDate(targetDate.year(), targetDate.month(), targetDaysInMonth);
            }
        }
        else {
            // 如果目标月的天数 < 原日期的天数，使用目标月的最后一天
            targetDate = QDate(targetDate.year(), targetDate.month(), targetDaysInMonth);
        }

        // 额外规则：如果原日期是30日或31日，且目标月是2月，需要使用2月的最后一天（考虑闰年）
        if ((originalDay == 30 || originalDay == 31) && targetDate.month() == 2) {
            targetDate = QDate(targetDate.year(), 2, targetDate.daysInMonth());
        }
        if (targetDate.day() == originalDate.day())
        {
            targetDate = targetDate.addDays(-1);
        }
    }

    else {

        // 额外规则
        if (targetDate.month() == 2 && day > targetDate.daysInMonth()) {
            // 检查减1天后是否有效（处理2月29日→2月28日等情况）
            if (!targetDate.isValid()) {
                // 回退到2月最后一天
                int lastDayOfFeb = QDate(targetDate.year(), 2, 1).daysInMonth();
                targetDate = QDate(targetDate.year(), 2, lastDayOfFeb);
            }
        }
        else {
            // 非月末：减1天（行业标准做法）
            targetDate = targetDate.addDays(-1);
        }


    }

    // 5. 应用日偏移
    targetDate = targetDate.addDays(save_days);
    // 4. 格式化结果
    return targetDate.toString("yyyyMMdd");

}
void QC_ApplicationWindow::UpdataTime()
{
    QString year_str, month_str, day_str;
    if (year < 10)
    {
        year_str = "0" + QString::number(year);
    }
    else {
        year_str = QString::number(year);
    }
    if (month < 10)
    {
        month_str = "0" + QString::number(month);
    }
    else {
        month_str = QString::number(month);
    }
    if (day < 10)
    {
        day_str = "0" + QString::number(day);
    }
    else {
        day_str = QString::number(day);
    }

    Start_Data_Time = year_str + month_str + day_str;
    ui->lineEdit->setText(Start_Data_Time);
    if (SCenabled != 0) {
        if (FH != "*") {
            ui->lineEdit_2->setText(FH + Start_Data_Time);
        }
        else {
            ui->lineEdit_2->setText(Start_Data_Time);
        }
    }
    else {
        ui->lineEdit_2->setText(QString::fromLocal8Bit("生产日期未启用"));
    }
    save_time = ui->spinBox->value();
    Save_Time = CaculateTime(year, month, day, save_time, Savemonth, Saveyear);
    ui->lineEdit_3->setText(Save_Time);
    if (BZenabled != 0) {
        ui->lineEdit_10->setText(Save_Time);
    }
    else {
        ui->lineEdit_10->setText(QString::fromLocal8Bit("保质日期未启用"));
    }
    
}

void QC_ApplicationWindow::CamErrorAct()
{
    isOpenCam = false;
   
    ui->toolButton->setIcon(QIcon(":/PIC/Resources/PICs/offline (2).png"));
    ui->toolButton->setIconSize(QSize(30, 30));
    ui->toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
    ui->label->setStyleSheet("background-color: rgb(255,210,75);""color: black;");
  
    ui->label->setText(QString::fromLocal8Bit("相机断开"));
    Logger::writeError("相机异常断开! ");
    QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("相机掉线 "), QString::fromLocal8Bit("检测到相机掉线，请检查相机\n连接并重启软件！ "), QMessageBox::Ok, this);
    msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
    msgBoxs->show();
}

void QC_ApplicationWindow::SetSchemeContent(QString schemename)
{
    string schemeName = std::string(schemename.toLocal8Bit());
    int result = SelectSchemeContent(schemeName);

    CustomStr = schemecontent.CustomStr;
    CustomStr_2 = schemecontent.CustomStr_2;
    CustomStr_3 = schemecontent.CustomStr_3;
    CustomStr_4 = schemecontent.CustomStr_4;
    CustomStr_5 = schemecontent.CustomStr_5;
    CustomStr_6 = schemecontent.CustomStr_6;
    SCenabled = schemecontent.SCenabled;
    BZenabled = schemecontent.BZenabled;
    EWenabled = schemecontent.EWenabled;
    save_time = schemecontent.save_time;
    Savemonth = schemecontent.Savemonth;
    Saveyear = schemecontent.Saveyear;

    ui->lineEdit_4->setText(QString::fromLocal8Bit(CustomStr.c_str()));
    ui->lineEdit_7->setText(QString::fromLocal8Bit(CustomStr_2.c_str()));
    ui->lineEdit_6->setText(QString::fromLocal8Bit(CustomStr_3.c_str()));
    ui->lineEdit_8->setText(QString::fromLocal8Bit(CustomStr_4.c_str()));
    ui->lineEdit_5->setText(QString::fromLocal8Bit(CustomStr_5.c_str()));

    ui->lineEdit_13->setText(QString::fromLocal8Bit(CustomStr.c_str()));
    ui->lineEdit_17->setText(QString::fromLocal8Bit(CustomStr_2.c_str()));
    ui->lineEdit_14->setText(QString::fromLocal8Bit(CustomStr_3.c_str()));
    ui->lineEdit_18->setText(QString::fromLocal8Bit(CustomStr_4.c_str()));
    ui->lineEdit_16->setText(QString::fromLocal8Bit(CustomStr_5.c_str()));

    ui->lineEdit_9->setText(QString::fromLocal8Bit(CustomStr_6.c_str()));
    if (EWenabled != 0) {
        ui->lineEdit_12->setText(CustomStr_6.c_str());
    }
    else {
        ui->lineEdit_12->setText(QString::fromLocal8Bit("额外代码未启用"));
    }
    ui->spinBox->setValue(save_time);
    ui->spinBox_2->setValue(Savemonth);
    ui->spinBox_3->setValue(Saveyear);

    if (SCenabled)
    {
        ui->toolButton_18->setStyleSheet("background-color:  #87CEEB;");
        ui->toolButton_20->setStyleSheet("background-color:  #FFFFFF;");
    }
    else
    {
        ui->toolButton_18->setStyleSheet("background-color:  #FFFFFF;");
        ui->toolButton_20->setStyleSheet("background-color:  #87CEEB;");
    }
    if (BZenabled)
    {
        ui->toolButton_22->setStyleSheet("background-color:  #87CEEB;");
        ui->toolButton_23->setStyleSheet("background-color:  #FFFFFF;");
    }
    else
    {
        ui->toolButton_22->setStyleSheet("background-color:  #FFFFFF;");
        ui->toolButton_23->setStyleSheet("background-color:  #87CEEB;");
    }
    if (EWenabled)
    {
        ui->toolButton_24->setStyleSheet("background-color:  #87CEEB;");
        ui->toolButton_29->setStyleSheet("background-color:  #FFFFFF;");
    }
    else
    {
        ui->toolButton_24->setStyleSheet("background-color:  #FFFFFF;");
        ui->toolButton_29->setStyleSheet("background-color:  #87CEEB;");
    }
}
////打开相机锁定界面
//void QC_ApplicationWindow::LockScreen()
//{
//    // 禁用所有工具栏动作
//    foreach(QToolBar * toolbar, findChildren<QToolBar*>()) {
//        foreach(QAction * action, toolbar->actions()) {
//            action->setEnabled(false);  // 禁用单个动作
//        }
//        toolbar->setStyleSheet("QToolBar { background: #f0f0f0; }"); // 视觉灰化
//    }
//   // ui->stackedWidget_3->setCurrentIndex(0);
//    ui->stackedWidget->setCurrentIndex(1);
//    ui->toolButton_14->setStyleSheet("background-color:  #87CEEB;");
//    ui->toolButton_3->setStyleSheet("background-color:  #FFFFFF;");
//    TriggerLine0();
//    //ui.page_3->setStyleSheet("background-color: #333333;");
//}
// 解锁至主界面
void QC_ApplicationWindow::UnlockScreen()
{
    ui->stackedWidget->setCurrentIndex(0);
}








/********************************************************************************************************************************************************************************************************
****************************************************************************************激光相关********************************************************************************************************/
void QC_ApplicationWindow::AddUser()
{
    PenMa = User.getPenMa1();
    LiuShuixian = User.getLiuShuixian1();
    Chufa = User.getChufa1();
    FangZhen = User.getFangZhen1();
    PeiFang = User.getPeiFang1();
    xiangJi = User.getXiangJi1();
    CDL = User.getOCR1();
    YongHu = User.getYongHu1();
    BianJi = User.getZhuangTai1();
    password = User.getpassword1();
    if (User.getTraverseUsername1() != "") {
        int findname = SelectSchUserName(User.getTraverseUsername1());
        if (findname == 0)
        {
            QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("新增配方失败，请重试 "), QMessageBox::Ok);
            msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBoxs->show();
            return;
        }
        else if (findname == 1)
        {
            QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("配方名已存在，请重试 "), QMessageBox::Ok);
            msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBoxs->show();
            return;
        }
    }
    else
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("用户名为空，请重试 "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        return;
    }
    InsertUser(User.getTraverseUsername1());
    QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("操作成功 "), QString::fromLocal8Bit("新增用户成功 "), QMessageBox::Ok);
    msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
    msgBoxs->show();
    TraverseUsernum = TraverseUser();//用户数量更新
    User.setUser(Userindex, userinfo.PenMa, userinfo.LiuShuixian, userinfo.Chufa, userinfo.FangZhen, userinfo.PeiFang, userinfo.xiangJi, userinfo.CDL, userinfo.YongHu, userinfo.BianJi, TraverseUsernum, Name);
    Logger::write("添加用户 ");
}
void QC_ApplicationWindow::DelUser()
{
    if (User.getTraverseUsername() != "管理员") {
        DeleteUser(User.getTraverseUsername());
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("操作成功 "), QString::fromLocal8Bit("删除用户成功 "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        TraverseUsernum = TraverseUser();//用户数量更新
        User.setUser(Userindex, userinfo.PenMa, userinfo.LiuShuixian, userinfo.Chufa, userinfo.FangZhen, userinfo.PeiFang, userinfo.xiangJi, userinfo.CDL, userinfo.YongHu, userinfo.BianJi, TraverseUsernum, Name);
        Logger::write("删除用户 ");
    }
    else
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("不能删除管理员 "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        return;
    }
}
void QC_ApplicationWindow::Alterpassword()
{
    password = User.getpassword();
    if (password != "")
    {

        AlterPassword(User.getTraverseUsername(), password);
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Information, QString::fromLocal8Bit("操作成功 "), QString::fromLocal8Bit("修改密码成功 "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();

        Logger::write("修改密码 ");
    }
    else {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("密码不能为空"), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
        return;
    }
}
void QC_ApplicationWindow::GatUser()
{
    PenMa = User.getPenMa();
    LiuShuixian = User.getLiuShuixian();
    Chufa = User.getChufa();
    FangZhen = User.getFangZhen();
    PeiFang = User.getPeiFang();
    xiangJi = User.getXiangJi();
    CDL = User.getOCR();
    YongHu = User.getYongHu();
    BianJi = User.getZhuangTai();
    string userstr = User.getTraverseUsername();
    if (YongHu == 0&&userstr== "管理员")
    {
        QMessageBox* msgBoxs = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("操作失败 "), QString::fromLocal8Bit("不能修改管理员用户权限 "), QMessageBox::Ok);
        msgBoxs->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
        msgBoxs->show();
    }
    else
    {
        AlterUser(userstr);
        //刷新用户信息当前页
        if (userstr == USERname) {
            manageUserPermissions();
        }
       
    }
  
}
void QC_ApplicationWindow::GatJgadmin()   //从激光设置界面中读取激光配置 并在保存数据库中更新
{
    jgconfig.BMQzhijing = jgadmin.getBMQzhijing();//获取激光参数
    jgconfig.BMQdirection = jgadmin.getBMQdirection();//获取激光参数
    jgconfig.BMQmaichong = jgadmin.getBMQmaichong();//获取激光参数
    jgconfig.GdFilterTime = jgadmin.getGdFilterTime();
    jgconfig.MinThresholdMode = jgadmin.getMinThresholdMode();
    jgconfig.MinTriggerTime = jgadmin.getMinTriggerTime();
    jgconfig.MinTriggerDistance = jgadmin.getMinTriggerDistance();
    jgconfig.DelayTriggerMode = jgadmin.getDelayTriggerMode();
    jgconfig.DelayTriggerTime = jgadmin.getDelayTriggerTime();
    jgconfig.DelayTriggerDistance = jgadmin.getDelayTriggerDistance();

    jgconfig.interpolationStep=ui->lineEdit_15->text().toInt();;
    jgconfig.scanW_mm = jgadmin.getscanW_mm();
    jgconfig.FXDBirection = jgadmin.getFXDBirection();
    jgconfig.Dbmode = jgadmin.getDbmode();
    jgconfig.JgFreq = jgadmin.getJgFreq();
    jgconfig.JgPower = jgadmin.getJgPower();
    jgconfig.KgDelay = jgadmin.getKgDelay();
    jgconfig.GgDelay = jgadmin.getGgDelay();
    jgconfig.firstJumpDelay = jgadmin.getFirstJumpDelay();
    jgconfig.endDelay = jgadmin.getEndDelay();
   
}
void QC_ApplicationWindow::GatXJadmin()   //将激光配置写入激光设置界面
{
    R = xjadmin.getR();
    G = xjadmin.getG();
    B = xjadmin.getB();
    RGBTime = xjadmin.getRGBTime();
    RGBMode = xjadmin.getRGBMode();
    DCLength = xjadmin.getDCLength();
    OutputLocationMin = xjadmin.getOutputLocationMin();
    OutputLocationMax = xjadmin.getOutputLocationMax();
    GapCount = xjadmin.getGapCount();
    KeepCount = xjadmin.getKeepCount();
    jgconfig.MinThresholdMode = xjadmin.getMinThresholdMode();
    jgconfig.MinTriggerTime = xjadmin.getMinTriggerTime();
    jgconfig.MinTriggerDistance = xjadmin.getMinTriggerDistance();
    jgconfig.DelayTriggerModetwo = xjadmin.getDelayTriggerMode_2();
    jgconfig.DelayTriggerTimetwo = xjadmin.getDelayTriggerTime_2();
    jgconfig.DelayTriggerDistancetwo = xjadmin.getDelayTriggerDistance_2();
    jgconfig.BMQzhijing = xjadmin.getBMQzhijing();//获取激光参数
    jgconfig.BMQmaichong = xjadmin.getBMQmaichong();//获取激光参数
}


//管理用户权限
void QC_ApplicationWindow::manageUserPermissions() {

    jgadmin.setupLaserPermissions(PenMa, LiuShuixian, Chufa);
    if (PenMa == 0 && LiuShuixian == 0 && Chufa == 0) {
        ui->toolButton_33->setEnabled(false);
    }
    else {
        ui->toolButton_33->setEnabled(true);
    }

    if (FangZhen == 1) {
        ui->toolButton_2->setEnabled(true);
    }
    else {
        ui->toolButton_2->setEnabled(false);
    }
    if (PeiFang == 1) {
        ui->toolButton_7->setEnabled(true);
    }
    else {
        ui->toolButton_7->setEnabled(true);
    }
    if (xiangJi == 1) {
        ui->toolButton_25->setEnabled(true);
    }
    else {
        ui->toolButton_25->setEnabled(false);
    }
    if (CDL == 1) {
        menuBar()->show();
    }
    else {
        menuBar()->hide();
    }
    if (YongHu == 1) {
        ui->toolButton_30->setEnabled(true);
    }
    else {
        ui->toolButton_30->setEnabled(false);
    }
    if (BianJi == 1) {
        ui->toolButton_16->setEnabled(true);
    }
    else {
        ui->toolButton_16->setEnabled(false);
    }

}
void QC_ApplicationWindow::initializeUserPermissions() {

    ui->toolButton_33->setEnabled(false);
    ui->toolButton_2->setEnabled(false);
   // ui->toolButton_7->setEnabled(false);
    ui->toolButton_25->setEnabled(false);
    menuBar()->hide();
    ui->toolButton_30->setEnabled(false);
    ui->toolButton_16->setEnabled(false);
    jgadmin.setupLaserPermissions(0, 0, 0);


}

/**
 * @brief 处理图像缩放、报警控制和运行模式
 *
 * 这个函数综合处理以下功能：
 * 1. 根据缩放比例对图像进行缩放处理
 * 2. 管理报警系统的计数和控制
 * 3. 根据运行模式执行不同的处理逻辑
 * 4. 相机定时器控制
 *
 * 注意：这个函数修改多个成员变量状态
 */
void QC_ApplicationWindow::processImageAndControls() {
    //// 1. 图像缩放处理
    //if (ImageSize < 1.0) {
    //    // 缩小图像：使用LANCZOS4插值（最高质量）
    //    cv::resize(image, resizeImage, cv::Size(), ImageSize, ImageSize, cv::INTER_LANCZOS4);
    //}
    //else if (ImageSize > 1.0) {
    //    // 放大图像：使用CUBIC插值（平衡质量和速度）
    //    cv::resize(image, resizeImage, cv::Size(), ImageSize, ImageSize, cv::INTER_CUBIC);
    //}
    //else {
    //    // 不缩放
    //    resizeImage = image.clone();
    //}
    // 获取原图的宽高
    int imageWidth = image.cols;
    int imageHeight = image.rows;

    // 计算宽高比例
    double widthRatio = (double)561 / imageWidth;
    double heightRatio = (double)491 / imageHeight;

    // 使用较小的比例来确保图像不超出label范围
    ImageSize = std::min(widthRatio, heightRatio);
   
   
    // 根据计算的比例进行缩放
    cv::resize(image, resizeImage, cv::Size(), ImageSize, ImageSize, cv::INTER_LINEAR); // 使用线性插值
    ui->toolButton_38->setStyleSheet(
        "QToolButton {"
        "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "      stop:0 #69f0ae, "       // 顶部：极亮绿（高光）
        "      stop:0.15 #00e676, "    // 过渡：鲜绿
        "      stop:0.85 #00c853, "    // 底部过渡：深绿（阴影）
        "      stop:1 #64dd17); "      // 底部：亮绿（反光）
        "}"
    );
    serialmanager.updateAlarmStatusUI2();

    // === 设置新图片到背景 ===
    QG_GraphicView* graphicView = qobject_cast<QG_GraphicView*>(getGraphicView());
    if (graphicView && !image.empty()) {
        // 直接使用原始image
        QImage qImage;
        if (image.channels() == 3) {
            cv::Mat rgbImage;
            cv::cvtColor(image, rgbImage, cv::COLOR_BGR2RGB);
            qImage = QImage((const uchar*)rgbImage.data, rgbImage.cols, rgbImage.rows,
                QImage::Format_RGB888).copy();
        }
        else if (image.channels() == 1) {
            qImage = QImage((const uchar*)image.data, image.cols, image.rows,
                QImage::Format_Grayscale8).copy();
        }

        if (!qImage.isNull()) {
            graphicView->setCameraImage2(qImage, mtextlowerLeftx, mtextlowerLefty, mtexttotalWidth, mtexttotalHeight, ImageMagnification, ImageWidth, ImageHeight);
        }
    }
  
    // 4. 运行模式处理
    if (model) {
        // 模式1：根据窗口状态决定运行方式
        if (IsSettingOpen ) {
            RunShow();
        }
        else {
            RunOcr();
        }
      
    }
    else {
        // 模式2：总是运行显示
        RunShow();
    }
}

/**
 * @brief 计算文档中所有可见实体的包围盒，并转换为相机ROI参数
 *
 * 此函数遍历文档中所有可见且未锁定的实体，计算它们的最小包围矩形，
 * 然后根据相机参数（放大倍率、图像尺寸）和系统偏移量转换为相机ROI参数。
 * 转换过程中会确保ROI参数满足相机的对齐要求（宽度/偏移为8的倍数，高度/偏移为2的倍数）。
 *
 * 主要功能：
 * 1. 遍历文档实体，计算整体包围盒
 * 2. 添加安全边距（5000单位）
 * 3. 转换为相机坐标系（考虑原点偏移和镜像）
 * 4. 应用图像放大倍率缩放
 * 5. 对齐到相机硬件要求（8像素/2像素对齐）
 * 6. 边界检查，防止超出有效区域
 */
int QC_ApplicationWindow::calculateSelectionBounds(RS_Document* doc) {
    RS_Vector lowerLeft(0, 0);
    RS_Vector upperRight(0, 0); // 用于存储最大右上角坐标
    int count = 0;

    // 遍历所有实体
    for (RS_Entity* e = doc->firstEntity(RS2::ResolveAll);
        e != nullptr;
        e = doc->nextEntity(RS2::ResolveAll)) {

        if (e && e->isVisible() && !e->isLocked()) {  // 不再依赖于选中状态
            // 获取实体的包围盒
            RS_Vector min = e->getMin();
            RS_Vector max = e->getMax();

            // 更新左下角和右上角坐标
            if (count == 0) {
                // 第一次初始化
                lowerLeft = min;
                upperRight = max;
            }
            else {
                // 更新最小左下角和最大右上角
                lowerLeft.x = std::min(lowerLeft.x, min.x);
                lowerLeft.y = std::min(lowerLeft.y, min.y);
                upperRight.x = std::max(upperRight.x, max.x);
                upperRight.y = std::max(upperRight.y, max.y);
            }

            count++;
        }
    }
    // 如果有实体，计算宽度和高度，并添加偏移
    if (count > 0) {
        // 计算宽度和高度
        double width = upperRight.x - lowerLeft.x;
        double height = upperRight.y - lowerLeft.y;

        if (lowerLeft.x < 0 || lowerLeft.y < 0 || upperRight.x>65000 || upperRight.y>65000) {
            QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("打码内容超区域!"));
            mtextlowerLeftx = 0;//roix偏移，默认0无偏移
            mtextlowerLefty = 0;//roiy偏移，默认0无偏移
            mtexttotalWidth = ImageWidth;//roi宽，默认无框线
            mtexttotalHeight = ImageHeight;//roi高，默认无框选
            return false;
        }
        else {
            // 向四周添加5000的偏移
            double offset = 5000.0;
            lowerLeft.x -= offset;  // 左下角X向左偏移
            lowerLeft.y -= offset;  // 左下角Y向下偏移
            upperRight.x += offset; // 右上角X向左偏移
            upperRight.y += offset; // 右上角Y向下偏移
            width += 2 * offset;    // 宽度增加两倍偏移量
            height += 2 * offset;   // 高度增加两倍偏移量

            if (lowerLeft.x < 32500- ImageWidth * ImageMagnification / 2 || lowerLeft.y < 32500 - ImageHeight * ImageMagnification / 2 || upperRight.x>32500 + ImageWidth * ImageMagnification / 2 || upperRight.y>32500 + ImageHeight * ImageMagnification / 2) {
                QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("ROI超相机区域!"));
                mtextlowerLeftx = 0;//roix偏移，默认0无偏移
                mtextlowerLefty = 0;//roiy偏移，默认0无偏移
                mtexttotalWidth = ImageWidth;//roi宽，默认无框线
                mtexttotalHeight = ImageHeight;//roi高，默认无框选
                return false;
            }

            lowerLeft.x = lowerLeft.x + (-32500 + ImageWidth * ImageMagnification / 2);
            lowerLeft.y = -(lowerLeft.y - (32500 + ImageHeight * ImageMagnification / 2));
            // 将坐标和宽高先除以80
            mtextlowerLeftx = lowerLeft.x / ImageMagnification;
            mtexttotalWidth = width / ImageMagnification;
            mtexttotalHeight = height / ImageMagnification;
            mtextlowerLefty = lowerLeft.y / ImageMagnification - mtexttotalHeight;
        }
        // 判断 mtextlowerLeftx 和 mtexttotalWidth 是否为 8 的倍数
        if (static_cast<int>(mtextlowerLeftx) % 8 != 0) {
            mtextlowerLeftx = std::floor(mtextlowerLeftx / 8.0) * 8; // 如果不是8的倍数，调整到最近的8的倍数
        }
        if (static_cast<int>(mtexttotalWidth) % 8 != 0) {
            mtexttotalWidth = std::floor(mtexttotalWidth / 8.0) * 8; // 同样处理mtexttotalWidth
        }

        // 判断 mtextlowerLefty 和 mtexttotalHeight 是否为 2 的倍数
        if (static_cast<int>(mtextlowerLefty) % 2 != 0) {
            mtextlowerLefty = std::floor(mtextlowerLefty / 2.0) * 2; // 如果不是2的倍数，调整到最近的2的倍数
        }
        if (static_cast<int>(mtexttotalHeight) % 2 != 0) {
            mtexttotalHeight = std::floor(mtexttotalHeight / 2.0) * 2; // 同样处理mtexttotalHeight
        }

        // 保存调整后的数据
        qDebug() << "Adjusted Lower Left (scaled by 80):" << mtextlowerLeftx << mtextlowerLefty;
        qDebug() << "Adjusted Width (scaled by 80):" << mtexttotalWidth;
        qDebug() << "Adjusted Height (scaled by 80):" << mtexttotalHeight;

        // 返回修改后的左下角坐标
        return true;
    }
    else {
        // 如果没有任何实体，返回无效向量
        return false;
    }
}

void QC_ApplicationWindow::processBinaryData(const QBitArray& bits, const QHostAddress& sender, quint16 port)
{
    qDebug() << "Received data size:" << bits;
    if (bits.size() != 256) return;

    // 快速解析
    quint8 msgType = listener->extractBitsToUInt(bits, 7, 0);
    quint16 funcCode = listener->extractBitsToUInt(bits, 15, 0);
    quint32 data = listener->extractBitsToUInt(bits, 255, 224);

    QStringList output;
    output << QString("From: %1:%2").arg(sender.toString()).arg(port);
    output << QString("Type: 0x%1").arg(msgType, 2, 16, QLatin1Char('0'));
    output << QString("Func: 0x%1").arg(funcCode, 4, 16, QLatin1Char('0'));
    output << QString("Data: 0x%1").arg(data, 8, 16, QLatin1Char('0'));

    // 根据功能码添加描述
    switch (funcCode) {

    case 0x0000:
        output << QString::fromLocal8Bit("擦除完成: %1").arg(static_cast<qint32>(data));
        if (static_cast<qint32>(data) == 1) { // 使用 == 进行比较，并将 data 转换为 qint32

            emit User.usereraseCompleteSignal();

        }
        break;
    case 0x0001:
        output << QString::fromLocal8Bit("写入完成: %1").arg(static_cast<qint32>(data));
        if (static_cast<qint32>(data) == 1) { // 使用 == 进行比较，并将 data 转换为 qint32

            emit User.userwriteCompleteSignal();
        }
        break;
    case 0x0002:
        output << QString::fromLocal8Bit("读取完成: %1").arg(static_cast<qint32>(data));
        if (static_cast<qint32>(data) == 1) { // 使用 == 进行比较，并将 data 转换为 qint32

            emit User.userreadCompleteSignal();
        }
        break;
    case 0x2000:
        output << QString::fromLocal8Bit("联机状态:") << listener->parseSimpleStatus(data, { "1", "2", "3" });
        serialmanager.updateDeviceStatus(data);
        if (bool allConnected = (data & 0x04) && (data & 0x02) && (data & 0x01)) {
            // 情况1：所有设备都正常连接 - 绿色
            ui->toolButton_32->setStyleSheet(
                "QToolButton {"
                "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                "      stop:0 #69f0ae, "       // 顶部：极亮绿（高光）
                "      stop:0.15 #00e676, "    // 过渡：鲜绿
                "      stop:0.85 #00c853, "    // 底部过渡：深绿（阴影）
                "      stop:1 #64dd17); "      // 底部：亮绿（反光）
                "}"
            );
            ui->toolButton_32->setText(QString::fromLocal8Bit("联机\n正常"));
        }
        else {
            // 情况2：至少有一个设备未连接
            // 检查未连接的设备是否被屏蔽
            bool cameraOK = (data & 0x04) || linkCameraOpen;   // 相机已连接或被屏蔽
            bool markingOK = (data & 0x02) || linkBKBKOpen;     // 标刻已连接或被屏蔽
            bool commOK = (data & 0x01) || linkTXOpen;          // 通讯已连接或被屏蔽

            if (cameraOK && markingOK && commOK) {
                // 情况2a：虽然有的设备没连接，但都被屏蔽了 - 绿色
                ui->toolButton_32->setStyleSheet(
                    "QToolButton {"
                    "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                    "      stop:0 #69f0ae, "       // 顶部：极亮绿（高光）
                    "      stop:0.15 #00e676, "    // 过渡：鲜绿
                    "      stop:0.85 #00c853, "    // 底部过渡：深绿（阴影）
                    "      stop:1 #64dd17); "      // 底部：亮绿（反光）
                    "}"
                );
                ui->toolButton_32->setText(QString::fromLocal8Bit("联机\n正常"));
            }
            else {
                // 情况2b：有未连接且未被屏蔽的设备 - 红色
                ui->toolButton_38->setStyleSheet(
                    "QToolButton {"
                    "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                    "      stop:0 #ff5252, "       // 顶部：亮红（高光）
                    "      stop:0.15 #d32f2f, "    // 过渡：正红
                    "      stop:0.85 #b71c1c, "    // 底部过渡：深红（阴影）
                    "      stop:1 #ff867c); "      // 底部：亮红（反光）

                    "}"
                );
                ui->toolButton_32->setText(QString::fromLocal8Bit("联机\n异常"));

                // 添加tooltip提示具体问题设备
                QStringList problems;
                if (!(data & 0x04) && !linkCameraOpen) problems << QString::fromLocal8Bit("相机");
                if (!(data & 0x02) && !linkBKBKOpen) problems << QString::fromLocal8Bit("标刻");
                if (!(data & 0x01) && !linkTXOpen) problems << QString::fromLocal8Bit("通讯");

                if (!problems.isEmpty()) {
                    ui->toolButton_32->setToolTip(problems.join("、") + QString::fromLocal8Bit("未连接且未屏蔽"));
                }
            }
        }

        break;
    case 0x2100:
        output << QString::fromLocal8Bit("报警状态:") << listener->parseSimpleStatus(data, { "1", "2", "3", "4" });
        Logger::write(output.join(" | ").toLocal8Bit().toStdString());
        serialmanager.updateAlarmStatusUI(data, markingOutOfAreaOpen, cameraAlarmOpen, MinThresholdAlermOpen, MaxThresholdAlermOpen);
        // 直接使用位掩码设置样式
        // 报警状态逻辑 - 类似于联机状态
        if (bool allNormal = !(data & 0x01) && !(data & 0x02) && !(data & 0x04) && !(data & 0x08)) {
            // 情况1：所有报警都正常 - 绿色
            ui->toolButton_38->setStyleSheet(
                "QToolButton {"
                "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                "      stop:0 #69f0ae, "       // 顶部：极亮绿（高光）
                "      stop:0.15 #00e676, "    // 过渡：鲜绿
                "      stop:0.85 #00c853, "    // 底部过渡：深绿（阴影）
                "      stop:1 #64dd17); "      // 底部：亮绿（反光）
                "}"
            );
            ui->toolButton_38->setText(QString::fromLocal8Bit("报警\n正常"));
        }
        else {
            // 情况2：至少有一个报警触发
            // 检查触发的报警是否被屏蔽
            bool alarm1OK = !(data & 0x01) || markingOutOfAreaOpen;   // 报警1正常或被屏蔽
            bool alarm2OK = !(data & 0x02) || cameraAlarmOpen;        // 报警2正常或被屏蔽
            bool alarm3OK = !(data & 0x04) || MinThresholdAlermOpen;  // 报警3正常或被屏蔽
            bool alarm4OK = !(data & 0x08) || MaxThresholdAlermOpen;   // 报警4正常或被屏蔽

            if (alarm1OK && alarm2OK && alarm3OK && alarm4OK) {
                // 情况2a：虽有报警触发，但都被屏蔽了 - 绿色
                ui->toolButton_38->setStyleSheet(
                    "QToolButton {"
                    "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                    "      stop:0 #69f0ae, "       // 顶部：极亮绿（高光）
                    "      stop:0.15 #00e676, "    // 过渡：鲜绿
                    "      stop:0.85 #00c853, "    // 底部过渡：深绿（阴影）
                    "      stop:1 #64dd17); "      // 底部：亮绿（反光）

                    "}"
                );
                ui->toolButton_38->setText(QString::fromLocal8Bit("报警\n正常"));
            }
            else {
                // 情况2b：有报警触发且未被屏蔽 - 红色
                ui->toolButton_38->setStyleSheet(
                    "QToolButton {"
                    "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                    "      stop:0 #ff5252, "       // 顶部：亮红（高光）
                    "      stop:0.15 #d32f2f, "    // 过渡：正红
                    "      stop:0.85 #b71c1c, "    // 底部过渡：深红（阴影）
                    "      stop:1 #ff867c); "      // 底部：亮红（反光）

                    "}"
                );
                ui->toolButton_38->setText(QString::fromLocal8Bit("报警\n触发"));

                // 添加tooltip提示具体报警设备
                QStringList alarms;
                if ((data & 0x01) && !markingOutOfAreaOpen) alarms << QString::fromLocal8Bit("标刻超范围");
                if ((data & 0x02) && !cameraAlarmOpen) alarms << QString::fromLocal8Bit("相机报警");
                if ((data & 0x04) && !MinThresholdAlermOpen) alarms << QString::fromLocal8Bit("最小阈值");
                if ((data & 0x08) && !MaxThresholdAlermOpen) alarms << QString::fromLocal8Bit("最大阈值");

                if (!alarms.isEmpty()) {
                    ui->toolButton_38->setToolTip(alarms.join("、") + QString::fromLocal8Bit("报警未屏蔽"));
                }
            }
        }
        break;
    case 0x1001:
        output << QString::fromLocal8Bit("%1 次").arg(data);

        //ui->label_33->setText(QString::fromLocal8Bit("%1 次").arg(data));
        break;
    case 0x1000:
        output << QString::fromLocal8Bit("打标时间: %1 us").arg(data * 10 / 1000.0, 0, 'f', 2);
        //ui->label_24->setText(QString::fromLocal8Bit("%1 us").arg(data * 10 / 1000.0, 0, 'f', 2));
        break;
    case 0x0204:
        output << QString::fromLocal8Bit("编码器值: %1").arg(static_cast<qint32>(data));

        //ui->label_36->setText(QString::fromLocal8Bit("%1").arg(static_cast<qint32>(data)));
        break;
    }
    qDebug().noquote() << output.join(" | ");
}





void QC_ApplicationWindow::CustomModeButtonClicked() {
    if (!IsCustom)
    {
        if (ui->lineEdit_6->text() == "" && ui->lineEdit_4->text() == "" && ui->lineEdit_5->text() == "" && ui->lineEdit_7->text() == "" && ui->lineEdit_8->text() == "")
        {
            QMessageBox* msgBox = new QMessageBox(QMessageBox::Critical, QString::fromLocal8Bit("日期格式错误 "), QString::fromLocal8Bit("日期字符不能为空 "), QMessageBox::Ok, this);
            msgBox->setFixedSize(400, 400);
            msgBox->button(QMessageBox::Ok)->setText(QString::fromLocal8Bit("确定 "));
            msgBox->show();
            return;
        }
        CustomStr = "";
        CustomStr.append(std::string(ui->lineEdit_4->text().toLocal8Bit()));
        CustomStr_2 = "";
        CustomStr_2.append(std::string(ui->lineEdit_7->text().toLocal8Bit()));
        CustomStr_3 = "";
        CustomStr_3.append(std::string(ui->lineEdit_6->text().toLocal8Bit()));
        CustomStr_4 = "";
        CustomStr_4.append(std::string(ui->lineEdit_8->text().toLocal8Bit()));
        CustomStr_5 = "";
        CustomStr_5.append(std::string(ui->lineEdit_5->text().toLocal8Bit()));

        QString deletestr = ui->comboBox->currentText();
        string delestr = std::string(deletestr.toLocal8Bit());
        AlterSchemeContent(delestr);

        IsCustom = true;
        ui->zdybutton_2->setEnabled(false);
      
        ui->zdybutton->setIcon(QIcon("Resources/PICs/open2.png"));
        ui->zdybutton->setIconSize(QSize(31, 31));
        ui->zdybutton->setText(QString::fromLocal8Bit("开启 "));
        ui->zdybutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->zdybutton_3->setIcon(QIcon("Resources/PICs/open2.png"));
        ui->zdybutton_3->setIconSize(QSize(31, 31));
        ui->zdybutton_3->setText(QString::fromLocal8Bit("开启 "));
        ui->zdybutton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_6->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
        ui->lineEdit_8->setEnabled(false);

        Logger::write("开启自定义模式!");
    }
    else
    {
        IsCustom = false;
        ui->zdybutton_2->setEnabled(true);
       

        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);

        ui->zdybutton->setIcon(QIcon("Resources/PICs/close2.png"));
        ui->zdybutton->setIconSize(QSize(31, 31));
        ui->zdybutton->setText(QString::fromLocal8Bit("关闭 "));
        ui->zdybutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->zdybutton_3->setIcon(QIcon("Resources/PICs/close2.png"));
        ui->zdybutton_3->setIconSize(QSize(31, 31));
        ui->zdybutton_3->setText(QString::fromLocal8Bit("关闭 "));
        ui->zdybutton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        Logger::write("关闭自定义模式!");
    }
}
void QC_ApplicationWindow::clearCustomFields() {
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
}

void QC_ApplicationWindow::saveCustomFields() {
    CustomStr = "";
    CustomStr.append(std::string(ui->lineEdit_4->text().toLocal8Bit()));
    CustomStr_2 = "";
    CustomStr_2.append(std::string(ui->lineEdit_7->text().toLocal8Bit()));
    CustomStr_3 = "";
    CustomStr_3.append(std::string(ui->lineEdit_6->text().toLocal8Bit()));
    CustomStr_4 = "";
    CustomStr_4.append(std::string(ui->lineEdit_8->text().toLocal8Bit()));
    CustomStr_5 = "";
    CustomStr_5.append(std::string(ui->lineEdit_5->text().toLocal8Bit()));

    QString deletestr = ui->comboBox->currentText();
    string delestr = std::string(deletestr.toLocal8Bit());
    AlterSchemeContent(delestr);
    string Log_Str = "*保存检测栏内容:\n" + CustomStr + " " + CustomStr_2 + "\n" + CustomStr_3 + " " + CustomStr_4 + "\n" + CustomStr_5;
    Logger::write(Log_Str);
    ui->lineEdit_13->setText(QString::fromLocal8Bit(CustomStr.c_str()));
    ui->lineEdit_17->setText(QString::fromLocal8Bit(CustomStr_2.c_str()));
    ui->lineEdit_14->setText(QString::fromLocal8Bit(CustomStr_3.c_str()));
    ui->lineEdit_18->setText(QString::fromLocal8Bit(CustomStr_4.c_str()));
    ui->lineEdit_16->setText(QString::fromLocal8Bit(CustomStr_5.c_str()));
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(2);
    if (IsCustom) {
        ui->tabWidget->setCurrentIndex(0);
    }

}

void QC_ApplicationWindow::showOCRResults() {
    //文本框汇总结果信息
    if (IsOnlyOcr != true)
    {

        if (ocrresult == 1 || ocrresult == 2 || ocrresult == 3)
        {
            Pass();
            updateHistoryImage(OCRT->ocrimg, 0, RawResult, RawResult2, Time_str);
        }
        else
        {

            NG();
            SaveNG();
            updateHistoryImage(OCRT->ocrimg, 1, RawResult, RawResult2, Time_str);

            if (IsCustom)
            {
                string NG_Str = "*应检测内容:\n" + CustomStr + " " + CustomStr_2 + "\n" + CustomStr_3 + " " + CustomStr_4 + "\n" + CustomStr_5 + "\n*识别结果为:\n" + RawResult.toStdString() + "\n**********二次识别结果***********\n" + RawResult2.toStdString();
                Logger::writeError(NG_Str);
                ui->textEdit->setText(QString::fromLocal8Bit("末次识别异常\n") + QString::fromLocal8Bit("----------------\n") + RawResult + QString::fromLocal8Bit("----------------\n") + RawResult2);
            }
            else
            {
                string NG_Str = "*应匹配日期字符为:生产日期:" + Start_Data_Time.toStdString() + " 保质期:" + Save_Time.toStdString() + "\n*识别结果为:\n" + RawResult.toStdString() + "\n**********二次识别结果***********\n" + RawResult2.toStdString();
                Logger::writeError(NG_Str);
                ui->textEdit->setText(QString::fromLocal8Bit("末次识别异常\n") + QString::fromLocal8Bit("----------------\n") + RawResult + QString::fromLocal8Bit("----------------\n") + RawResult2);
            }
        }
        // 获取当前索引
     
        if (ui->stackedWidget_3->currentIndex()==1) {
            QImage showimg = QImage((unsigned char*)OCRT->ocrimg.data, OCRT->ocrimg.cols, OCRT->ocrimg.rows, OCRT->ocrimg.step, QImage::Format_BGR888);
            ui->label_2->setPixmap(QPixmap::fromImage(showimg.scaled(ui->label_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)));

        }
       ui->label_21->setText(QString::number(ocr_time, 'f', 2) + "ms");
       
    }
    else
    {
        if (ocrresult == 4 || ocrresult == 5)
        {
           // SaveSimNG(simulateImg);

            updateHistoryImage(OCRT->ocrimg, 3, RawResult, RawResult2, Time_str);
            ui->label->setStyleSheet("background-color: rgb(255,152, 0);""color: black;");
          
            ui->label->setText(QString::fromLocal8Bit("模拟NG"));
        }
        else
        {
            updateHistoryImage(OCRT->ocrimg, 2, RawResult, RawResult2, Time_str);
            ui->label->setStyleSheet("background-color: rgb(33, 150, 243);""color: black;");
           
            ui->label->setText(QString::fromLocal8Bit("模拟OK"));

        }
        //文本框汇总结果信息
       // QImage showimg = OCRT->MatToImage(OCRT->ocrimg);
        QImage showimg = QImage((unsigned char*)OCRT->ocrimg.data, OCRT->ocrimg.cols, OCRT->ocrimg.rows, OCRT->ocrimg.step, QImage::Format_BGR888);
        ui->label_2->setPixmap(QPixmap::fromImage(showimg.scaled(ui->label_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)));
      
        IsOnlyOcr = false;
        ImageListIndex++;
        ui->label_21->setText(QString::number(ocr_time, 'f', 2) + "ms");

    }
}

void QC_ApplicationWindow::onTabWidgetPageChanged(int index)
{
    qDebug() << QString::fromLocal8Bit("切换到页面索引:") << index;

    if (ui->tabWidget) {
        IsCustom = false;
        ui->zdybutton_2->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);

        ui->zdybutton->setIcon(QIcon("Resources/PICs/close2.png"));
        ui->zdybutton->setIconSize(QSize(31, 31));
        ui->zdybutton->setText(QString::fromLocal8Bit("关闭 "));
        ui->zdybutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->zdybutton_3->setIcon(QIcon("Resources/PICs/close2.png"));
        ui->zdybutton_3->setIconSize(QSize(31, 31));
        ui->zdybutton_3->setText(QString::fromLocal8Bit("关闭 "));
        ui->zdybutton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    }
}



void QC_ApplicationWindow::getSerialNum3() {

    int serialNum = 0;
    // 使用位移运算
    serialNum |= (linkCameraOpen ? 1 : 0) << 2;   // 第2位
    serialNum |= (linkBKBKOpen ? 1 : 0) << 1; // 第1位
    serialNum |= (linkCameraOpen ? 1 : 0) << 0; // 第0位


    int serialNum2 = 0;
    // 使用位移运算
    serialNum2 |= (MaxThresholdAlermOpen ? 1 : 0) << 3;   // 第3位
    serialNum2 |= (MinThresholdAlermOpen ? 1 : 0) << 2;   // 第2位
    serialNum2 |= (cameraAlarmOpen ? 1 : 0) << 1; // 第1位
    serialNum2 |= (markingOutOfAreaOpen ? 1 : 0) << 0; // 第0位
    
    //FileUtils::SendBKBK(75, serialNum);
    //FileUtils::SendBKBK(76, serialNum2);
    FileUtils::SendBKBK("20","00", serialNum);
    FileUtils::SendBKBK("21","02", serialNum2);

}

void QC_ApplicationWindow::updateHistoryImage(cv::Mat newImage, int pass, QString RawResult, QString RawResult2, QString Time_str) {
    // 将cv::Mat转换为QImage
    QImage newQImage = QImage((unsigned char*)newImage.data,
        newImage.cols,
        newImage.rows,
        newImage.step,
        QImage::Format_BGR888);

    // 将新图片转换为QPixmap
    QPixmap newPixmap = QPixmap::fromImage(newQImage);
    QSize thumbnailSize = ui->timg5->size();  // 假设timg5是标准大小

    // 获取当前所有工具按钮的图标
    QPixmap currentImg5 = ui->timg5->icon().isNull() ? QPixmap() : ui->timg5->icon().pixmap(thumbnailSize);
    QPixmap currentImg4 = ui->timg4->icon().isNull() ? QPixmap() : ui->timg4->icon().pixmap(thumbnailSize);
    QPixmap currentImg3 = ui->timg3->icon().isNull() ? QPixmap() : ui->timg3->icon().pixmap(thumbnailSize);
    QPixmap currentImg2 = ui->timg2->icon().isNull() ? QPixmap() : ui->timg2->icon().pixmap(thumbnailSize);
    QPixmap currentImg1 = ui->timg1->icon().isNull() ? QPixmap() : ui->timg1->icon().pixmap(thumbnailSize);

    // 实现先进先出(FIFO)效果：新图片放timg1，旧图片依次后移
    // 顺序：timg1(最新) ← 新图片
    //      timg2 ← 原来的timg1
    //      timg3 ← 原来的timg2
    //      timg4 ← 原来的timg3
    //      timg5(最旧) ← 原来的timg4
    // 原来的timg5被丢弃

    // 更新timg5显示原来的timg4
    if (!currentImg4.isNull()) {
        ui->timg5->setIcon(QIcon(currentImg4.scaled(thumbnailSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        ui->timg5->setIconSize(thumbnailSize);
    }
    else {
        ui->timg5->setIcon(QIcon());  // 清空图标
    }

    // 更新timg4显示原来的timg3
    if (!currentImg3.isNull()) {
        ui->timg4->setIcon(QIcon(currentImg3.scaled(thumbnailSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        ui->timg4->setIconSize(thumbnailSize);
    }
    else {
        ui->timg4->setIcon(QIcon());
    }

    // 更新timg3显示原来的timg2
    if (!currentImg2.isNull()) {
        ui->timg3->setIcon(QIcon(currentImg2.scaled(thumbnailSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        ui->timg3->setIconSize(thumbnailSize);
    }
    else {
        ui->timg3->setIcon(QIcon());
    }

    // 更新timg2显示原来的timg1
    if (!currentImg1.isNull()) {
        ui->timg2->setIcon(QIcon(currentImg1.scaled(thumbnailSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        ui->timg2->setIconSize(thumbnailSize);
    }
    else {
        ui->timg2->setIcon(QIcon());
    }

    // 更新timg1显示新图片
    ui->timg1->setIcon(QIcon(newPixmap.scaled(thumbnailSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    ui->timg1->setIconSize(thumbnailSize);

    // 设置工具提示
    updateHistoryToolTips(pass, RawResult, RawResult2, Time_str);
}

// 修改updateHistoryToolTips函数来处理QToolButton
void QC_ApplicationWindow::updateHistoryToolTips(int pass, QString RawResult, QString RawResult2, QString Time_str) {
    static int imageCounter = 0;
    imageCounter++;

    // 保存当前检测结果
    struct TempResult {
        int number;
        QString timestamp;
        int pass;
        QString rawResult1;
        QString rawResult2;
        QString timeStr;
    };

    static QList<TempResult> tempHistory;

    TempResult newResult;
    newResult.number = imageCounter;
    newResult.timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    newResult.pass = pass;
    newResult.rawResult1 = RawResult;
    newResult.rawResult2 = RawResult2;
    newResult.timeStr = Time_str;

    // 保存到历史
    tempHistory.prepend(newResult);

    // 只保留最近的5条记录
    if (tempHistory.size() > 5) {
        tempHistory.removeLast();
    }

    // 工具按钮数组
    QToolButton* imgButtons[] = {
        ui->timg1,  // 最新图片
        ui->timg2,  // 历史图片1
        ui->timg3,  // 历史图片2
        ui->timg4,  // 历史图片3
        ui->timg5   // 最旧图片
    };

    for (int i = 0; i < 5; i++) {
        QToolButton* button = imgButtons[i];

        if (!button) {
            continue;
        }

        // 检查按钮是否有图标
        bool hasImage = !button->icon().isNull();

        // 检查是否有历史记录
        if (i < tempHistory.size() && hasImage) {
            const TempResult& result = tempHistory[i];

            // 根据pass值确定结果信息
            struct ResultInfo {
                QString text;
                QString color;
                QString status;
            } resultInfo;

            if (result.pass == 0) {
                // 实际检测 - OK
                resultInfo.text = QString::fromLocal8Bit("OK");
                resultInfo.color = "#4CAF50";  // 绿色
                resultInfo.status = QString::fromLocal8Bit("生产日期检测通过");
            }
            else if (result.pass == 1) {
                // 实际检测 - NG
                resultInfo.text = QString::fromLocal8Bit("NG");
                resultInfo.color = "#F44336";  // 红色
                resultInfo.status = QString::fromLocal8Bit("生产日期检测失败");
            }
            else if (result.pass == 2) {
                // 模拟检测 - OK
                resultInfo.text = QString::fromLocal8Bit("MK");
                resultInfo.color = "#2196F3";  // 蓝色
                resultInfo.status = QString::fromLocal8Bit("模拟检测通过");
            }
            else if (result.pass == 3) {
                // 模拟检测 - NG
                resultInfo.text = QString::fromLocal8Bit("MN");
                resultInfo.color = "#FF9800";  // 橙色
                resultInfo.status = QString::fromLocal8Bit("模拟检测失败");
            }
            else {
                // 其他状态
                resultInfo.text = QString::fromLocal8Bit("UN");
                resultInfo.color = "#9E9E9E";  // 灰色
                resultInfo.status = QString::fromLocal8Bit("未知状态");
            }
            //  修改后：合并所有样式
            QString borderStyle = QString(
                "QToolButton {"
                "  background-color: rgb(100,100,100);"  // 纯黑色背景
                "  opacity: 1;"                    // 完全不透明
                "  border: 3px solid %1;"         // 动态边框颜色
                "  border-radius: 5px;"           // 5像素圆角
                "}"
            ).arg(resultInfo.color);
            button->setStyleSheet(borderStyle);
          
         
            // 构建工具提示
            QString tooltip = QString::fromLocal8Bit(
                "%1图片\n"
                "编号: #%2\n"
                "时间: %3\n"
                "状态: %4\n"
                "第一次识别: %5\n"
                "第二次识别: %6\n"
                "结果: %7"
            ).arg(i == 0 ? QString::fromLocal8Bit("最新") : QString::fromLocal8Bit("历史"))
                .arg(result.number)
                .arg(result.timestamp)
                .arg(resultInfo.status)
                .arg(result.rawResult1)
                .arg(result.rawResult2)
                .arg(result.timeStr);

           
            // 在图片上添加OK/NG标记
            addResultMarkToButton(button, resultInfo.text, tooltip , resultInfo.color);
        }
        else {
            // 没有历史记录的情况
            //button->setStyleSheet("border: 2px solid #CCCCCC; border-radius: 5px;");
           // button->setToolTip(QString::fromLocal8Bit("等待图片..."));
           
        }
    }
}
// 在按钮上添加结果标记
void QC_ApplicationWindow::addResultMarkToButton(QToolButton* button, const QString& mark, QString tooltip, const QString& color) {
    if (!button || button->icon().isNull()) return;
    button->setToolTip(tooltip);
    QPixmap original = button->icon().pixmap(button->iconSize());
    if (original.isNull()) return;

    QPixmap marked = original.copy();

    QPainter painter(&marked);
    painter.setRenderHint(QPainter::Antialiasing);

    // 在左上角添加标记
    int markerSize = qMin(original.width(), original.height()) * 0.2;  // 标记大小为图片尺寸的20%
    int margin = 5;

    if (markerSize < 20) markerSize = 20;  // 最小20像素
    if (markerSize > 40) markerSize = 40;  // 最大40像素

    // 绘制圆形背景
    painter.setBrush(QColor(color));
    painter.setPen(Qt::white);
    painter.drawEllipse(margin, margin, markerSize, markerSize);

    // 绘制标记文字
    QFont font = painter.font();
    font.setPointSize(markerSize * 0.5);
    font.setBold(true);
    painter.setFont(font);

    QRect textRect(margin, margin, markerSize, markerSize);
    painter.drawText(textRect, Qt::AlignCenter, mark);

    painter.end();

    // 更新按钮图标
    button->setIcon(QIcon(marked));
}
// 为按钮添加点击事件处理
void QC_ApplicationWindow::setupImageButtonEvents() {
    // 连接按钮点击信号
    connect(ui->timg1, &QToolButton::clicked, this, [this]() { showImageDetail(0); });
    connect(ui->timg2, &QToolButton::clicked, this, [this]() { showImageDetail(1); });
    connect(ui->timg3, &QToolButton::clicked, this, [this]() { showImageDetail(2); });
    connect(ui->timg4, &QToolButton::clicked, this, [this]() { showImageDetail(3); });
    connect(ui->timg5, &QToolButton::clicked, this, [this]() { showImageDetail(4); });

    // 设置光标样式
    ui->timg1->setCursor(Qt::PointingHandCursor);
    ui->timg2->setCursor(Qt::PointingHandCursor);
    ui->timg3->setCursor(Qt::PointingHandCursor);
    ui->timg4->setCursor(Qt::PointingHandCursor);
    ui->timg5->setCursor(Qt::PointingHandCursor);
}

// 显示图片详情
void QC_ApplicationWindow::showImageDetail(int index) {
    QToolButton* imgButtons[] = {
        ui->timg1, ui->timg2, ui->timg3, ui->timg4, ui->timg5
    };

    if (index < 0 || index >= 5) return;

    QToolButton* button = imgButtons[index];
    if (!button || button->icon().isNull()) {
        return;  // 没有图片
    }
    QString tooltip = button->toolTip();
    if (tooltip.isEmpty() || tooltip == QString::fromLocal8Bit("等待图片...")) {
        return;
    }

    // 显示详细信息对话框
    QDialog* detailDialog = new QDialog(this);
    detailDialog->setWindowTitle(QString::fromLocal8Bit("图片详情 - %1").arg(index + 1));
    detailDialog->setMinimumSize(500, 400);

    QVBoxLayout* layout = new QVBoxLayout(detailDialog);

    // 显示大图
    QLabel* imageLabel = new QLabel(detailDialog);
    QPixmap originalPixmap = button->icon().pixmap(button->iconSize() * 2);  // 显示2倍大小
    imageLabel->setPixmap(originalPixmap);
    imageLabel->setAlignment(Qt::AlignCenter);

    // 显示详细信息
    QTextEdit* infoText = new QTextEdit(detailDialog);
    infoText->setReadOnly(true);
    infoText->setText(tooltip);
    infoText->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Microsoft YaHei', 'SimSun';"
        "  font-size: 12px;"
        "  border: 1px solid #ccc;"
        "  border-radius: 5px;"
        "  padding: 10px;"
        "}"
    );

    // 关闭按钮
    QPushButton* closeButton = new QPushButton(QString::fromLocal8Bit("关闭"), detailDialog);
    connect(closeButton, &QPushButton::clicked, detailDialog, &QDialog::accept);

    layout->addWidget(imageLabel);
    layout->addWidget(infoText);
    layout->addWidget(closeButton, 0, Qt::AlignCenter);

    detailDialog->exec();
    detailDialog->deleteLater();
}

void QC_ApplicationWindow::enableBKBKPrinting() {
    if (!getMDIWindow()) return;
    RS_GraphicView* graphicView = getGraphicView();
    RS_Document* document = getDocument();
    if (!graphicView || !document) return;
    // 计算选中实体的中心点
    //if (!calculateSelectionBounds(document)) return;
    //SetROISimple(mtexttotalWidth, mtexttotalHeight, mtextlowerLeftx, mtextlowerLefty);
    // 禁用所有工具栏动作
    if (slotCustomFunction1())
    {
        foreach(QToolBar * toolbar, findChildren<QToolBar*>()) {
            foreach(QAction * action, toolbar->actions()) {
                action->setEnabled(false);  // 禁用单个动作
            }
            toolbar->setStyleSheet("QToolBar { background: #f0f0f0; }"); // 视觉灰化
        }
        ui->moveUpBtn->setEnabled(false);
        ui->moveDownBtn->setEnabled(false);
        ui->moveLeftBtn->setEnabled(false);
        ui->moveRighBtn->setEnabled(false);
        ui->moveToPosition->setEnabled(false);
        ui->toolButton_42->setEnabled(false);
       /* ui->toolButton_43->setEnabled(false);
        ui->toolButton_44->setEnabled(false);
        ui->toolButton_45->setEnabled(false);*/
        ui->toolButton_46->setEnabled(false);
        //ui->toolButton_47->setEnabled(false);
        // ui->toolButton_48->setEnabled(false);

        IsOpenBKBK = true;
        //ui->toolButton_15->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->toolButton_15->setStyleSheet(
            "QToolButton {"
            "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "      stop:0 #ff7675, "       // 顶部：亮红/粉红（高光）
            "      stop:0.15 #d63031, "    // 过渡：正红
            "      stop:0.85 #b71c1c, "    // 底部过渡：深红（阴影）
            "      stop:1 #ff5252); "      // 底部：鲜红（反光）
            "  border-radius: 15px;"
            "  border: 2px solid #4CAF50;" // 保留了你之前的绿色边框，形成红绿对比
            "  padding: 5px 15px;"
            "  min-width: 100px;"
            "  min-height: 40px;"
            "  color: white; "             // 建议：红色背景下，白色文字更清晰
            "}"
        );
        ui->toolButton_15->setText(QString::fromLocal8Bit("打印中"));
        Logger::write("打印中 ");

        FileUtils::SendBKBK("10", "F1", IsOpenBKBK);
    }
}
void QC_ApplicationWindow::disableBKBKPrinting() {

    // 启用时反向操作
    foreach(QToolBar * toolbar, findChildren<QToolBar*>()) {
        foreach(QAction * action, toolbar->actions()) {
            action->setEnabled(true);
        }
        toolbar->setStyleSheet(""); // 恢复样式
    }
    ui->moveUpBtn->setEnabled(true);
    ui->moveDownBtn->setEnabled(true);
    ui->moveLeftBtn->setEnabled(true);
    ui->moveRighBtn->setEnabled(true);
    ui->moveToPosition->setEnabled(true);
    ui->toolButton_42->setEnabled(true);
   /* ui->toolButton_43->setEnabled(true);
    ui->toolButton_44->setEnabled(true);
    ui->toolButton_45->setEnabled(true);*/
    ui->toolButton_46->setEnabled(true);
    // ui->toolButton_47->setEnabled(true);
    // ui->toolButton_48->setEnabled(true);

    mtextlowerLeftx = 0;
    mtextlowerLefty = 0;
    mtexttotalWidth = ImageWidth;
    mtexttotalHeight = ImageHeight;
    //SetROISimple(mtexttotalWidth, mtexttotalHeight, mtextlowerLeftx, mtextlowerLefty);

    IsOpenBKBK = false;
    //ui->toolButton_15->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->toolButton_15->setStyleSheet(
        "QToolButton {"
        "  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "      stop:0 #ffffff, "       // 顶部：纯白（高光）
        "      stop:0.15 #dcdcdc, "    // 过渡：浅灰
        "      stop:0.85 #a9a9a9, "    // 底部过渡：中灰
        "      stop:1 #e8e8e8); "      // 底部：亮灰（反光）
        "  border-radius: 15px;"
        "  border: 2px solid #4CAF50;"
        "  padding: 5px 15px;"
        "  min-width: 100px;"
        "  min-height: 40px;"
        "}"
    );
    ui->toolButton_15->setText(QString::fromLocal8Bit("打印"));
    Logger::write("关闭打印 ");
    FileUtils::SendBKBK("10", "F1", IsOpenBKBK);
    FileUtils::SendBKBK("02", "F1", 1);//单次拍照
}
