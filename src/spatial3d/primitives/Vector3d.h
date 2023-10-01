#ifndef GLORY3D_VECTOR3D_H
#define GLORY3D_VECTOR3D_H


#include "Direction3d.h"
#include "Point3d.h"

class Vector3d {
public:
    Direction3d direction;
    Point3d point;
    double length;

    Vector3d(Point3d *point, Direction3d *direction);

    Vector3d(Point3d *point, Direction3d *direction, double length);
};


#endif //GLORY3D_VECTOR3D_H
