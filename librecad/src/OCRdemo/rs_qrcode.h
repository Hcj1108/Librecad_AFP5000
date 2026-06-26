#pragma once

#include "rs_entitycontainer.h"
#include <QString>

class RS_QRCode : public RS_EntityContainer
{
public:
    RS_QRCode(RS_EntityContainer* parent);
    ~RS_QRCode() override = default;

    RS2::EntityType rtti() const override {
        return RS2::EntityContainer;
    }

    /// 从 ZXing 矩阵生成子实体
    bool generate(const QString& text, double posX, double posY,
                  double moduleSize, int margin, int eccLevel, int shapeIndex);
};
