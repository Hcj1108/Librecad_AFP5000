#ifndef SAMPLE_H
#define SAMPLE_H

#include "qc_plugininterface.h"
#include <QDialog>
#include <QVector>
#include <QPointF>
#include <QMap>
#include <QString>
#include <QTextStream>
#include "document_interface.h"  // 包含Document_Interface的完整定义



class QLineEdit;
class Document_Interface;
class Plug_Entity;




class LC_Sample : public QObject, QC_PluginInterface
{
    Q_OBJECT
        Q_INTERFACES(QC_PluginInterface)
        Q_PLUGIN_METADATA(IID LC_DocumentInterface_iid FILE "sample.json")

public:
    virtual PluginCapabilities getCapabilities() const Q_DECL_OVERRIDE;
    virtual QString name() const Q_DECL_OVERRIDE;
    virtual void execComm(Document_Interface* doc,
        QWidget* parent, QString cmd) Q_DECL_OVERRIDE;

    QMap<QString, QVector<QVector<QPointF>>> getAllEntitiesPaths(Document_Interface* doc) const;

    static QVector<QPointF> generateCirclePath(const QPointF& center, double radius, int segments = 36);
    static QVector<QPointF> generateArcPath(const QPointF& center, double radius,
        double startAngle, double endAngle, int segments = 36);

private:
    QVector<QVector<QPointF>> getEntityPaths(Document_Interface* doc, const QString& entityType) const;
};

class lc_Sampledlg : public QDialog
{
    Q_OBJECT

public:
    explicit lc_Sampledlg(QWidget* parent = nullptr);
    ~lc_Sampledlg();

public slots:
    void processAction(Document_Interface* doc);
    void checkAccept();
    void getAllEntitiesAction(Document_Interface* doc);

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    void readSettings();
    void writeSettings();
    bool failGUI(QString* msg);
    QVector<QPointF> generateLinePath(const QPointF& start, const QPointF& end) const;

    QString errmsg;
    QLineEdit* startxedit = nullptr;
    QLineEdit* startyedit = nullptr;
    QLineEdit* endxedit = nullptr;
    QLineEdit* endyedit = nullptr;
};

#endif // SAMPLE_H