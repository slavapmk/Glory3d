#ifndef GLORY3D_LIGHT3D_H
#define GLORY3D_LIGHT3D_H


#include "Object3d.h"

class Light3d : Object3d {
public:
    double power;

    Light3d(Point3d position, Rotation3d rotation);

    Light3d(Point3d position, Rotation3d rotation, Scale3d scale);

    Light3d(Point3d position, Rotation3d rotation, double power);

    Light3d(Point3d position, Rotation3d rotation, Scale3d scale, double power);
};


#endif //GLORY3D_LIGHT3D_H
