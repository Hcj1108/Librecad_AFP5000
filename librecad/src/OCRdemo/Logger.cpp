#include "Logger.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfoList>
#include <QDateTime>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>

static int g_keepDays = 180;

Logger::Logger(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    currentDir = "./Log/Operate";

    connect(ui.fileList, &QListWidget::itemClicked, this, &Logger::onFileClicked);
    connect(ui.btnOperate, &QPushButton::clicked, this, &Logger::showOperateLog);
    connect(ui.btnError, &QPushButton::clicked, this, &Logger::showErrorLog);
    connect(ui.btnComm, &QPushButton::clicked, this, &Logger::showCommLog);
    connect(ui.searchBox, &QLineEdit::textChanged, this, &Logger::searchText);
    connect(ui.searchBox, &QLineEdit::returnPressed, this, &Logger::searchNext);
    connect(ui.btnSearchNext, &QPushButton::clicked, this, &Logger::searchNext);
    connect(ui.btnSearchPrev, &QPushButton::clicked, this, &Logger::searchPrev);

    connect(ui.btnExport, &QPushButton::clicked, this, &Logger::exportLog);


    connect(ui.spinKeepDays, QOverload<int>::of(&QSpinBox::valueChanged), [&](int val) {
        g_keepDays = val;
        QSettings settings;
        settings.setValue("/Logger/KeepDays", g_keepDays);
    });

    SetQSS();

    // 启动时清理一次过期日志
    cleanOldLogs();

    refreshFileList();
}

Logger::~Logger()
{}

void Logger::SetQSS()
{
   
    // 设置窗口标志：保留系统菜单、显示问号(?)按钮、显示关闭(X)按钮
    this->setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
    // 从注册表恢复保留天数
    QSettings settings;
    g_keepDays = settings.value("/Logger/KeepDays", 180).toInt();
    ui.spinKeepDays->setValue(g_keepDays);

    // selection highlight color
    ui.contentView->setStyleSheet(
        "selection-background-color: #FF6B6B; selection-color: white;"
    );
}

void Logger::showEvent(QShowEvent*)
{
    refreshFileList();
  
   
}

void Logger::refreshFileList()
{
    ui.fileList->clear();
    ui.contentView->clear();

    QDir dir(currentDir);
    if (!dir.exists()) return;

    QStringList filters;
    filters << "*.txt";
    QFileInfoList files = dir.entryInfoList(filters, QDir::Files, QDir::Name | QDir::Reversed);

    for (const QFileInfo& fi : files) {
        QListWidgetItem* item = new QListWidgetItem(fi.fileName());
        item->setData(Qt::UserRole, fi.absoluteFilePath());
        ui.fileList->addItem(item);
    }
}

void Logger::showOperateLog()
{
    currentDir = "./Log/Operate";
    refreshFileList();
}

void Logger::showErrorLog()
{
    currentDir = "./Log/Error";
    refreshFileList();
}

void Logger::showCommLog()
{
    currentDir = "./Log/Comm";
    refreshFileList();
}

void Logger::exportLog()
{
    if (currentFile.isEmpty()) return;

    QString savePath = QFileDialog::getSaveFileName(this,
        QString::fromLocal8Bit("导出日志"),
        QFileInfo(currentFile).fileName(),
        QString::fromLocal8Bit("文本文件 (*.txt)"));

    if (savePath.isEmpty()) return;

    if (QFile::copy(currentFile, savePath)) {
        QMessageBox::information(this,
            QString::fromLocal8Bit("导出成功"),
            QString::fromLocal8Bit("日志已导出"));
    } else {
        QMessageBox::warning(this,
            QString::fromLocal8Bit("导出失败"),
            QString::fromLocal8Bit("无法导出日志"));
    }
}


void Logger::write(const QString& text)
{
    // 自动分类
    if (text.contains(QStringLiteral("失败")) ||
        text.contains(QStringLiteral("异常")) ||
        text.contains(QStringLiteral("不足")) ||
        text.contains(QStringLiteral("错误"))) {
        writeError(text);
        return;
    }
    if (text.contains(QStringLiteral("相机")) ||
        text.contains(QStringLiteral("激光")) ||
        text.contains(QStringLiteral("触发")) ||
        text.contains(QStringLiteral("打印")) ||
        text.contains(QStringLiteral("监控")) ||
        text.contains(QStringLiteral("标定"))) {
        writeComm(text);
        return;
    }

    cleanOldLogs();

    QDateTime current_time = QDateTime::currentDateTime();
    QDir().mkpath("./Log/Operate");
    QString logname = "./Log/Operate/" + current_time.toString("yyyy.MM.dd") + ".txt";

    QString timestamp = current_time.toString("yyyy-MM-dd hh:mm:ss");
    QString data = "-------------" + timestamp + "------------- \n" + text + "\n";

    QFile file(logname);
    if (file.open(QFile::Append | QIODevice::Text)) {
        file.write(data.toLocal8Bit());
    }
}
void Logger::write(const std::string& text)
{
    write(QString::fromLocal8Bit(text.c_str()));
}

void Logger::write(const char* text)
{
    write(QString::fromLocal8Bit(text));
}
void Logger::writeError(const QString& text)
{
    cleanOldLogs();

    QDateTime current_time = QDateTime::currentDateTime();
    QDir().mkpath("./Log/Error");
    QString logname = "./Log/Error/" + current_time.toString("yyyy.MM.dd") + ".txt";

    QString timestamp = current_time.toString("yyyy-MM-dd hh:mm:ss");
    QString data = "-------------" + timestamp + "------------- \n" + text + "\n";

    QFile file(logname);
    if (file.open(QFile::Append | QIODevice::Text)) {
        file.write(data.toLocal8Bit());
    }
}

void Logger::writeError(const std::string& text)
{
    writeError(QString::fromLocal8Bit(text.c_str()));
}

void Logger::writeError(const char* text)
{
    writeError(QString::fromLocal8Bit(text));
}

void Logger::writeComm(const QString& text)
{
    cleanOldLogs();

    QDateTime current_time = QDateTime::currentDateTime();
    QDir().mkpath("./Log/Comm");
    QString logname = "./Log/Comm/" + current_time.toString("yyyy.MM.dd") + ".txt";

    QString timestamp = current_time.toString("yyyy-MM-dd hh:mm:ss");
    QString data = "-------------" + timestamp + "------------- \n" + text + "\n";

    QFile file(logname);
    if (file.open(QFile::Append | QIODevice::Text)) {
        file.write(data.toLocal8Bit());
    }
}

void Logger::writeComm(const std::string& text)
{
    writeComm(QString::fromLocal8Bit(text.c_str()));
}

void Logger::writeComm(const char* text)
{
    writeComm(QString::fromLocal8Bit(text));
}

void Logger::cleanOldLogs()
{
    int keepDays = g_keepDays;
    QStringList dirs = { "./Log/Operate", "./Log/Error", "./Log/Comm" };
    QDateTime cutoff = QDateTime::currentDateTime().addDays(-keepDays);

    for (const QString& dirPath : dirs) {
        QDir dir(dirPath);
        if (!dir.exists()) continue;

        QStringList filters;
        filters << "*.txt";
        QFileInfoList files = dir.entryInfoList(filters, QDir::Files, QDir::Name);

        for (const QFileInfo& fi : files) {
            if (fi.birthTime().isValid() && fi.birthTime() < cutoff) {
                QFile::remove(fi.absoluteFilePath());
            } else if (fi.lastModified() < cutoff) {
                QFile::remove(fi.absoluteFilePath());
            }
        }
    }
}

int Logger::keepDaysValue()
{
    return g_keepDays;
}

void Logger::setKeepDaysValue(int days)
{
    g_keepDays = days;
}

void Logger::onFileClicked(QListWidgetItem* item)
{
    if (!item) return;
    QString filePath = item->data(Qt::UserRole).toString();
    currentFile = filePath;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    ui.contentView->setPlainText(in.readAll());
    file.close();

    // 切换文件后重新应用搜索高亮
    QString keyword = ui.searchBox->text();
    if (!keyword.isEmpty()) searchText(keyword);
}

void Logger::searchText(const QString& text)
{
    // 清除旧高亮，恢复原始文本
    QTextDocument* doc = ui.contentView->document();
    QTextCursor cursor(doc);
    cursor.select(QTextCursor::Document);
    cursor.setCharFormat(QTextCharFormat());

    if (text.isEmpty()) return;

    // 高亮所有匹配项
    QTextCharFormat highlight;
    highlight.setBackground(QBrush(QColor(255, 255, 0))); // 亮黄色
    highlight.setForeground(QBrush(QColor(0, 0, 0)));    // 黑色字

    cursor = QTextCursor(doc);
    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = doc->find(text, cursor, QTextDocument::FindCaseSensitively);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(highlight);
        }
    }
}

void Logger::searchNext()
{
    QString keyword = ui.searchBox->text();
    if (keyword.isEmpty()) return;

    searchText(keyword);

    bool found = ui.contentView->find(keyword);
    if (!found) {
        ui.contentView->moveCursor(QTextCursor::Start);
        ui.contentView->find(keyword);
    }
}

void Logger::searchPrev()
{
    QString keyword = ui.searchBox->text();
    if (keyword.isEmpty()) return;

    searchText(keyword);

    bool found = ui.contentView->find(keyword, QTextDocument::FindBackward);
    if (!found) {
        ui.contentView->moveCursor(QTextCursor::End);
        ui.contentView->find(keyword, QTextDocument::FindBackward);
    }
}
