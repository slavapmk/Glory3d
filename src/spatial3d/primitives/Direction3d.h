#ifndef GLORY3D_DIRECTION3D_H
#define GLORY3D_DIRECTION3D_H


#include "Rotation3d.h"

class Direction3d {
public:
    double x, y, z;

    Direction3d(double x, double y, double z);

    Direction3d rotate(Rotation3d rotation) const;
};


#endif //GLORY3D_DIRECTION3D_H
