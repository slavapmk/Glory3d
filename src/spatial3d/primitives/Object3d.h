#ifndef GLORY3D_OBJECT3D_H
#define GLORY3D_OBJECT3D_H


#include "Rotation3d.h"
#include "Point3d.h"
#include "Scale3d.h"

class Object3d {
public:
    Point3d position;
    Rotation3d rotation;
    Scale3d scale;

    Object3d(Point3d position, Rotation3d rotation);

    Object3d(Point3d position, Rotation3d rotation, Scale3d scale);
};


#endif //GLORY3D_OBJECT3D_H
