#include "QRCodeDialog.h"
#include "ui_QRCodeDialog.h"

#include <QPainter>
#include <QDateTime>
#include <QDebug>

#include "rs_document.h"
#include "rs_graphicview.h"
#include "rs_graphic.h"
#include "rs_entitycontainer.h"
#include "rs_line.h"
#include "rs_point.h"

#include <include/ZXing/BarcodeFormat.h>
#include <include/ZXing/BitMatrix.h>
#include <include/ZXing/MultiFormatWriter.h>
using namespace ZXing;

QRCodeDialog::QRCodeDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::QRCodeDialogClass)
{
    ui->setupUi(this);

    connect(ui->timeModeCk, &QCheckBox::toggled, this, &QRCodeDialog::onTimeModeToggled);
    connect(ui->okBtn, &QPushButton::clicked, this, &QRCodeDialog::onAccept);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    onTimeModeToggled(false);
}

QRCodeDialog::~QRCodeDialog()
{
    delete ui;
}

void QRCodeDialog::setParams(const QRCodeParams& p)
{
    m_params = p;
    ui->contentEdit->setPlainText(p.text);
    ui->posXSpb->setValue(p.posX);
    ui->posYSpb->setValue(p.posY);
    ui->moduleSizeSpb->setValue(p.moduleSize);
    ui->marginSpb->setValue(p.margin);
    ui->rotateSpb->setValue(p.rotateAngle);
    ui->eccCbx->setCurrentIndex(p.eccLevel);
    ui->shapeCbx->setCurrentIndex(p.shapeIndex);
    ui->timeModeCk->setChecked(p.timeMode);
    ui->timeFormatCbx->setCurrentText(p.timeFormat);
}

QRCodeParams QRCodeDialog::getParams() const
{
    QRCodeParams p;
    p.text = m_params.text;
    p.posX = ui->posXSpb->value();
    p.posY = ui->posYSpb->value();
    p.moduleSize = ui->moduleSizeSpb->value();
    p.margin = ui->marginSpb->value();
    p.rotateAngle = ui->rotateSpb->value();
    p.eccLevel = ui->eccCbx->currentIndex();
    p.shapeIndex = ui->shapeCbx->currentIndex();
    p.timeMode = ui->timeModeCk->isChecked();
    p.timeFormat = ui->timeFormatCbx->currentText();
    return p;
}

void QRCodeDialog::onTimeModeToggled(bool checked)
{
    ui->timeFormatCbx->setEnabled(checked);
    ui->contentEdit->setEnabled(!checked);
    if (checked) {
        QString fmt = ui->timeFormatCbx->currentText();
        static const QMap<QString, QString> fmtMap = {
            {"YYYY-MM-DD HH:mm:ss", "yyyy-MM-dd hh:mm:ss"},
            {"YYYY/MM/DD HH:mm", "yyyy/MM/dd hh:mm"},
            {"DD-MM-YYYY", "dd-MM-yyyy"},
            {"HH:mm:ss", "hh:mm:ss"},
        };
        QString content = QDateTime::currentDateTime().toString(fmtMap.value(fmt, "yyyy-MM-dd hh:mm:ss"));
        m_params.text = content;
        ui->contentEdit->setPlainText(content);
    }
}

void QRCodeDialog::onAccept()
{
    m_params = getParams();
    accept();
}

bool QRCodeDialog::generateToDocument(RS_Document* doc, RS_GraphicView* view, const QRCodeParams& p)
{
    if (!doc || !view || p.text.isEmpty()) return false;

    RS_EntityContainer* container = doc->getGraphic();
    if (!container) return false;

    try {
        MultiFormatWriter writer(BarcodeFormat::QRCode);
        writer.setMargin(p.margin);
        writer.setEccLevel(p.eccLevel);
        auto matrix = writer.encode(p.text.toUtf8().constData(), 0, 0);

        double tw = matrix.width() * p.moduleSize;
        double th = matrix.height() * p.moduleSize;
        double ox = p.posX - tw / 2.0;
        double oy = p.posY - th / 2.0;

        RS_EntityContainer* group = new RS_EntityContainer(container);

        for (int y = 0; y < matrix.height(); ++y) {
            for (int x = 0; x < matrix.width(); ++x) {
                if (!matrix.get(x, y)) continue;
                double x1 = ox + x * p.moduleSize;
                double y1 = oy + y * p.moduleSize;
                double x2 = x1 + p.moduleSize;
                double y2 = y1 + p.moduleSize;

                if (p.shapeIndex == 0) {
                    RS_LineData segs[] = {
                        RS_LineData(RS_Vector(x1,y1), RS_Vector(x2,y1)),
                        RS_LineData(RS_Vector(x2,y1), RS_Vector(x2,y2)),
                        RS_LineData(RS_Vector(x2,y2), RS_Vector(x1,y2)),
                        RS_LineData(RS_Vector(x1,y2), RS_Vector(x1,y1)),
                    };
                    for (auto& s : segs) {
                        auto* L = new RS_Line(group, s);
                        group->addEntity(L);
                    }
                } else {
                    double cx = (x1+x2)/2, cy = (y1+y2)/2;
                    auto* pt = new RS_Point(group, RS_PointData(RS_Vector(cx,cy)));
                    group->addEntity(pt);
                }
            }
        }

        doc->startUndoCycle();
        doc->addEntity(group);
        doc->addUndoable(group);
        doc->endUndoCycle();
        view->redraw(RS2::RedrawDrawing);

        return true;
    } catch (const std::exception& e) {
        qDebug() << "QRCode generation error:" << e.what();
        return false;
    }
}
