

#ifndef RS_POLYLINE_H
#define RS_POLYLINE_H
#include <QDebug> // 添加此头文件以定义 Debug
#include "rs_entity.h"
#include "rs_entitycontainer.h"
#include "rs_line.h"
#include "rs_arc.h"

/**
 * Holds the data that defines a polyline.
 */
struct RS_PolylineData : public RS_Flags {
	RS_PolylineData();
	~RS_PolylineData()=default;
	RS_PolylineData(const RS_Vector& startpoint,
                    const RS_Vector& endpoint,
					bool closed);

    RS_Vector startpoint;
    RS_Vector endpoint;
};

std::ostream& operator << (std::ostream& os, const RS_PolylineData& pd);

/**
 * Class for a poly line entity (lots of connected lines and arcs).
 *
 * @author Andrew Mustun
 */
class RS_Polyline : public RS_EntityContainer {
public:



   
	std::vector<std::vector<RS_Vector>> RS_Polyline::getPathPoints(int step) const {
		std::vector<std::vector<RS_Vector>> allPoints; // 存储所有子实体的点集

		// 遍历所有子实体
		for (RS_Entity* e : entities) {
			// 调用子实体的 getPathPoints 方法获取该段的点集
			auto segmentPoints = e->getPathPoints();

			// 将当前子实体的点集作为一个独立的 vector 存入总点集
			allPoints.push_back(segmentPoints);
		}

		return allPoints; // 返回所有子实体的点集（按子实体分组）
	}
















	RS_Polyline(RS_EntityContainer* parent=nullptr);
    RS_Polyline(RS_EntityContainer* parent,
                const RS_PolylineData& d);

	RS_Entity* clone() const override;

    /**	@return RS2::EntityPolyline */
	RS2::EntityType rtti() const  override{
        return RS2::EntityPolyline;
    }

    /** @return Copy of data that defines the polyline. */
    RS_PolylineData getData() const {
        return data;
    }

    /** sets a new start point of the polyline */
	void setStartpoint(RS_Vector const& v);

    /** @return Start point of the entity */
	RS_Vector getStartpoint() const override;

    /** sets a new end point of the polyline */
	void setEndpoint(RS_Vector const& v);

    // set layer for polyline and sub-entities
    void setLayer(const QString& name);
    void setLayer(RS_Layer* l);

    /** @return End point of the entity */
	RS_Vector getEndpoint() const override;

	double getClosingBulge() const;

	void updateEndpoints();

    /** @return true if the polyline is closed. false otherwise */
	bool isClosed() const;

	void setClosed(bool cl);

    void setClosed(bool cl, double bulge);//RLZ: rewrite this:

	RS_VectorSolutions getRefPoints() const override;
	RS_Vector getMiddlePoint(void)const override{
            return RS_Vector(false);
	}
	RS_Vector getNearestRef( const RS_Vector& coord,
									 double* dist = nullptr) const override;
	RS_Vector getNearestSelectedRef( const RS_Vector& coord,
											 double* dist = nullptr) const override;
	RS_Entity* addVertex(const RS_Vector& v,
                double bulge=0.0, bool prepend=false);

	void appendVertexs(const std::vector< std::pair<RS_Vector, double> >& vl);

	void setNextBulge(double bulge) {
                nextBulge = bulge;
        }
	void addEntity(RS_Entity* entity) override;
	//void addSegment(RS_Entity* entity) override;
	void removeLastVertex();
	void endPolyline();

	//void reorder() override;

	bool offset(const RS_Vector& coord, const double& distance) override;
	void move(const RS_Vector& offset) override;
	void rotate(const RS_Vector& center, const double& angle) override;
	void rotate(const RS_Vector& center, const RS_Vector& angleVector) override;
	void scale(const RS_Vector& center, const RS_Vector& factor) override;
	void mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2) override;
	void stretch(const RS_Vector& firstCorner,
                         const RS_Vector& secondCorner,
						 const RS_Vector& offset) override;

	void moveRef(const RS_Vector& ref, const RS_Vector& offset) override;
	void revertDirection() override;


	void draw(RS_Painter* painter, RS_GraphicView* view,
					  double& patternOffset) override;

    friend std::ostream& operator << (std::ostream& os, const RS_Polyline& l);

protected:
	RS_Entity* createVertex(const RS_Vector& v,
                double bulge=0.0, bool prepend=false);

protected:
    RS_PolylineData data;
    RS_Entity* closingEntity;
	double nextBulge;
};

#endif
