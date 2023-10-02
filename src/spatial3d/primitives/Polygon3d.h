#ifndef GLORY3D_POLYGON3D_H
#define GLORY3D_POLYGON3D_H

#include "Point3d.h"

class Polygon3d {
public:
    Point3d a, b, c;
    double v;

    Polygon3d(Point3d a, Point3d b, Point3d c, double v);
};


#endif