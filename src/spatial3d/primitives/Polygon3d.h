//
// Created by Slava on 27.09.2023.
//

#ifndef GLORY3D_POLYGON3D_H
#define GLORY3D_POLYGON3D_H


#include "Point3d.h"

class Polygon3d {
public:
    Point3d a,b,c;
    Polygon3d(Point3d a, Point3d b, Point3d c);
};


#endif //GLORY3D_POLYGON3D_H
