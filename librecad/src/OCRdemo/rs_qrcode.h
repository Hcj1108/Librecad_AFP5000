#pragma once

#include "rs_entitycontainer.h"
#include <QString>

struct RS_QRCodeData {
    QString text;
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

class RS_QRCode : public RS_EntityContainer
{
public:
    RS_QRCode(RS_EntityContainer* parent);
    RS_QRCode(RS_EntityContainer* parent, const RS_QRCodeData& d);
    ~RS_QRCode() override = default;

    RS2::EntityType rtti() const override {
        return RS2::EntityQRCode;
    }

    RS_Entity* clone() const override;

    RS_QRCodeData getData() const { return data; }

    /// 从 ZXing 矩阵生成子实体
    bool generate(const QString& text, double posX, double posY,
                  double moduleSize, int margin, int eccLevel, int shapeIndex);

    void update() override;

    virtual void move(const RS_Vector& offset) override;
    virtual void rotate(const RS_Vector& center, const double& angle) override;
    virtual void rotate(const RS_Vector& center, const RS_Vector& angleVector) override;
    virtual void scale(const RS_Vector& center, const RS_Vector& factor) override;
    virtual void mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2) override;

    virtual RS_Vector getNearestEndpoint(const RS_Vector& coord,
                                         double* dist = NULL) const override;
    virtual RS_VectorSolutions getRefPoints() const override;

protected:
    RS_QRCodeData data;
};
