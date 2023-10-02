//
// Created by Slava on 27.09.2023.
//

#ifndef GLORY3D_POINT3D_H
#define GLORY3D_POINT3D_H


#include "Scale3d.h"
#include "Rotation3d.h"

class Point3d {
public:
    Point3d(double x, double y, double z);

    double z, x, y;

    Point3d multiply(Scale3d scale) const;

    Point3d rotate(Rotation3d rotation, Point3d axis) const;

    Point3d add(Point3d point) const;
};


#endif //GLORY3D_POINT3D_H
