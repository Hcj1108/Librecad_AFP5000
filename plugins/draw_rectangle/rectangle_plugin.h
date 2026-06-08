#ifndef RECTANGLE_PLUGIN_H
#define RECTANGLE_PLUGIN_H

#include <QtPlugin>
#include <QDialog>
#include <QLineEdit>
#include <QDoubleValidator>

#include "document_interface.h"
#include "qc_plugininterface.h"

class RectangleDialog : public QDialog {
    Q_OBJECT

public:
    explicit RectangleDialog(QWidget* parent = nullptr);
    void processAction(Document_Interface* doc);

private slots:
    void checkInputs();

private:
    QLineEdit* startXEdit;
    QLineEdit* startYEdit;
    QLineEdit* widthEdit;
    QLineEdit* heightEdit;
};

class RectanglePlugin : public QObject, public QC_PluginInterface {
    Q_OBJECT
        Q_INTERFACES(QC_PluginInterface)
        Q_PLUGIN_METADATA(IID "org.librecad.PluginInterface/1.0")

public:
    QString name() const override;
    PluginCapabilities getCapabilities() const override;
    void execComm(Document_Interface* doc, QWidget* parent, QString cmd) override;
};

#endif // RECTANGLE_PLUGIN_H