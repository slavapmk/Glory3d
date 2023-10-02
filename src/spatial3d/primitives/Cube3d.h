#ifndef GLORY3D_CUBE3D_H
#define GLORY3D_CUBE3D_H


#include "Renderable3d.h"

class Cube3d : public Renderable3d {
public:
    Cube3d(Point3d position, Rotation3d rotation, double edge);

    Cube3d(Point3d position, Rotation3d rotation, Scale3d scale, double edge);
};

#endif