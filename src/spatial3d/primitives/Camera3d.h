#ifndef GLORY3D_CAMERA3D_H
#define GLORY3D_CAMERA3D_H


#include "Object3d.h"

class Camera3d : Object3d {
public:
    double *fov;
    Point3d position;
    Rotation3d rotation;
    Scale3d scale;

    Camera3d(Point3d position, Rotation3d rotation, double fov);

    Camera3d(Point3d position, Rotation3d rotation, Scale3d scale, double fov);
};

#endif
