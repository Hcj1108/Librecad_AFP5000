#pragma once

#include <QWidget>
#include <QListWidgetItem>
#include <QShowEvent>
#include <QCloseEvent>
#include <string>
#include "ui_Logger.h"

class Logger : public QWidget
{
    Q_OBJECT

public:
    Logger(QWidget *parent = nullptr);
    ~Logger();

    void SetQSS();

    static void write(const std::string& text);
    static void write(const QString& text);
    static void write(const char* text);
    static void writeError(const QString& text);
    static void writeError(const std::string& text);
    static void writeError(const char* text);
    static void writeComm(const QString& text);
    static void writeComm(const std::string& text);
    static void writeComm(const char* text);

    static int keepDaysValue();
    static void setKeepDaysValue(int days);
    static void cleanOldLogs();

    void refreshFileList();

protected:
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onFileClicked(QListWidgetItem* item);
    void searchText(const QString& text);
    void searchNext();
    void searchPrev();
    void showOperateLog();
    void showErrorLog();
    void showCommLog();
    void exportLog();

private:
    Ui::LoggerClass ui;
    QString currentDir;
    QString currentFile;

signals:
    void showmain();
};
