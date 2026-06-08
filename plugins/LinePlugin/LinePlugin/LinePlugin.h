#pragma once
#ifndef LINEPLUGIN_H
#define LINEPLUGIN_H

#include "qc_plugininterface.h"
// 确保包含 "qc_plugininterface.h" 的路径正确  
#include "../path_to_qc_plugininterface/qc_plugininterface.h"  
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class LineDialog : public QDialog {
    Q_OBJECT

public:
    explicit LineDialog(QWidget* parent = 0);
    ~LineDialog();

    // 获取输入的起点和终点
    QPointF getStartPoint() const;
    QPointF getEndPoint() const;

private:
    QLineEdit* startXEdit;
    QLineEdit* startYEdit;
    QLineEdit* endXEdit;
    QLineEdit* endYEdit;
    QPushButton* okButton;

private slots:
    void onOkButtonClicked();
};

class LinePlugin : public QObject, QC_PluginInterface
{
    Q_OBJECT
        Q_INTERFACES(QC_PluginInterface)
        Q_PLUGIN_METADATA(IID LC_DocumentInterface_iid FILE "lineplugin.json")

public:
    LinePlugin();
    ~LinePlugin();

    virtual PluginCapabilities getCapabilities() const Q_DECL_OVERRIDE;
    virtual QString name() const Q_DECL_OVERRIDE;
    virtual void execComm(Document_Interface* doc,
        QWidget* parent, QString cmd) Q_DECL_OVERRIDE;
};

#endif // LINEPLUGIN_H
