#pragma once

#include <QDialog>
#include <QString>
#include <QPixmap>

class RS_Document;
class RS_GraphicView;

namespace Ui {
class QRCodeDialogClass;
}

struct QRCodeParams {
    QString text = "LibreCAD";
    double posX = 33000.0;
    double posY = 33000.0;
    double moduleSize = 200.0;
    int margin = 2;
    double rotateAngle = 0.0;
    int eccLevel = 2;
    int shapeIndex = 0;
    int version = 0;
    bool timeMode = false;
    QString timeFormat = "YYYY-MM-DD HH:mm:ss";
};

class QRCodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRCodeDialog(QWidget* parent = nullptr);
    ~QRCodeDialog();

    void setParams(const QRCodeParams& p);
    QRCodeParams getParams() const;

    /// 直接生成二维码实体到文档
    static bool generateToDocument(RS_Document* doc, RS_GraphicView* view, const QRCodeParams& p);

private slots:
    void onTimeModeToggled(bool checked);
    void onAccept();

private:
    Ui::QRCodeDialogClass* ui;
    QRCodeParams m_params;
};
