#pragma once

#include <QDialog>
#include <string>
#include <vector>
#include "ui_Simulator.h"

/**
 * @brief 仿真文件夹选择对话框
 *
 * 选择一个包含 .bmp 文件的文件夹，加载其中的图片列表。
 * 提供文件夹路径显示、选择、确认功能。
 */
class Simulator : public QDialog
{
    Q_OBJECT

public:
    explicit Simulator(QWidget* parent = nullptr);
    ~Simulator() override;

    /// 获取选中的文件夹路径
    QString getFolderPath() const { return m_folderPath; }

    /// 获取图片文件列表（全路径）
    std::vector<std::string> getImageList() const { return m_imageList; }

private slots:
    void onSelectFolder();
    void onAccept();

private:
    void loadImages(const QString& folderPath);

    Ui::SimulatorClass ui;
    QString m_folderPath;
    std::vector<std::string> m_imageList;
    QStringList m_imageFilters;
};
