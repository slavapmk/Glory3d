#include "Light3d.h"

Light3d::Light3d(Point3d position, Rotation3d rotation) :
        Object3d(position, rotation),
        power(1) {}

Light3d::Light3d(Point3d position, Rotation3d rotation, Scale3d scale) :
        Object3d(position, rotation, scale),
        power(1) {}

Light3d::Light3d(Point3d position, Rotation3d rotation, double power) :
        Object3d(position, rotation),
        power(power) {}

Light3d::Light3d(Point3d position, Rotation3d rotation, Scale3d scale, double power) :
        Object3d(position, rotation, scale),
        power(power) {}
