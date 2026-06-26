#include "rs_qrcode.h"
#include "rs_line.h"
#include "rs_point.h"
#include "rs_graphic.h"
#include "rs_math.h"

#include <include/ZXing/BarcodeFormat.h>
#include <include/ZXing/BitMatrix.h>
#include <include/ZXing/MultiFormatWriter.h>
using namespace ZXing;

RS_QRCode::RS_QRCode(RS_EntityContainer* parent)
    : RS_EntityContainer(parent)
{
}

RS_QRCode::RS_QRCode(RS_EntityContainer* parent, const RS_QRCodeData& d)
    : RS_EntityContainer(parent), data(d)
{
    update();
}

RS_Entity* RS_QRCode::clone() const {
    RS_QRCode* qr = new RS_QRCode(*this);
    qr->setOwner(isOwner());
    qr->initId();
    qr->detach();
    return qr;
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
        calculateBorders();
        return true;
    } catch (const std::exception& e) {
        (void)e;
        return false;
    }
}

void RS_QRCode::update()
{
    if (updateEnabled == false) return;

    // 从 data 重新生成子实体
    if (data.text.isEmpty()) return;
    generate(data.text, data.posX, data.posY,
             data.moduleSize, data.margin, data.eccLevel, data.shapeIndex);
}

void RS_QRCode::move(const RS_Vector& offset)
{
    data.posX += offset.x;
    data.posY += offset.y;
    RS_EntityContainer::move(offset);
}

void RS_QRCode::rotate(const RS_Vector& center, const double& angle)
{
    RS_Vector angleVector(angle);
    rotate(center, angleVector);
}

void RS_QRCode::rotate(const RS_Vector& center, const RS_Vector& angleVector)
{
    RS_Vector v(data.posX, data.posY);
    v.rotate(center, angleVector);
    data.posX = v.x;
    data.posY = v.y;
    data.rotateAngle += angleVector.angle();
    RS_EntityContainer::rotate(center, angleVector);
}

void RS_QRCode::scale(const RS_Vector& center, const RS_Vector& factor)
{
    RS_Vector v(data.posX, data.posY);
    v.scale(center, factor);
    data.posX = v.x;
    data.posY = v.y;
    data.moduleSize *= factor.x;
    RS_EntityContainer::scale(center, factor);
}

void RS_QRCode::mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2)
{
    RS_Vector v(data.posX, data.posY);
    v.mirror(axisPoint1, axisPoint2);
    data.posX = v.x;
    data.posY = v.y;
    RS_EntityContainer::mirror(axisPoint1, axisPoint2);
}

RS_Vector RS_QRCode::getNearestEndpoint(const RS_Vector& coord,
                                         double* dist) const
{
    // 返回中心点作为端点
    RS_Vector center(data.posX, data.posY);
    if (dist) {
        *dist = center.distanceTo(coord);
    }
    return center;
}

RS_VectorSolutions RS_QRCode::getRefPoints() const
{
    RS_VectorSolutions ret;
    ret.push_back(RS_Vector(data.posX, data.posY));
    return ret;
}
