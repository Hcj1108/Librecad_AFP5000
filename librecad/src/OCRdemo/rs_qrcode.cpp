#include "rs_qrcode.h"
#include "rs_line.h"
#include "rs_point.h"
#include "rs_graphic.h"

#include <include/ZXing/BarcodeFormat.h>
#include <include/ZXing/BitMatrix.h>
#include <include/ZXing/MultiFormatWriter.h>
using namespace ZXing;

RS_QRCode::RS_QRCode(RS_EntityContainer* parent)
    : RS_EntityContainer(parent)
{
}

bool RS_QRCode::generate(const QString& text, double posX, double posY,
                          double moduleSize, int margin, int eccLevel, int shapeIndex)
{
    clear();
    if (text.isEmpty()) return false;

    try {
        MultiFormatWriter writer(BarcodeFormat::QRCode);
        writer.setMargin(margin);
        writer.setEccLevel(eccLevel);
        auto matrix = writer.encode(text.toUtf8().constData(), 0, 0);

        double tw = matrix.width() * moduleSize;
        double th = matrix.height() * moduleSize;
        double ox = posX - tw / 2.0;
        double oy = posY - th / 2.0;

        for (int y = 0; y < matrix.height(); ++y) {
            for (int x = 0; x < matrix.width(); ++x) {
                if (!matrix.get(x, y)) continue;
                double x1 = ox + x * moduleSize;
                double y1 = oy + y * moduleSize;
                double x2 = x1 + moduleSize;
                double y2 = y1 + moduleSize;

                if (shapeIndex == 0) {
                    RS_LineData segs[] = {
                        RS_LineData(RS_Vector(x1,y1), RS_Vector(x2,y1)),
                        RS_LineData(RS_Vector(x2,y1), RS_Vector(x2,y2)),
                        RS_LineData(RS_Vector(x2,y2), RS_Vector(x1,y2)),
                        RS_LineData(RS_Vector(x1,y2), RS_Vector(x1,y1)),
                    };
                    for (auto& s : segs) {
                        auto* L = new RS_Line(this, s);
                        addEntity(L);
                    }
                } else {
                    double cx = (x1+x2)/2, cy = (y1+y2)/2;
                    auto* pt = new RS_Point(this, RS_PointData(RS_Vector(cx,cy)));
                    addEntity(pt);
                }
            }
        }
        update();
        return true;
    } catch (const std::exception& e) {
        (void)e;
        return false;
    }
}
