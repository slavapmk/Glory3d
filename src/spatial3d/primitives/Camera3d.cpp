#include "Camera3d.h"

Camera3d::Camera3d(Point3d position, Rotation3d rotation, double fov) :
        Object3d(position, rotation),
        fov(fov) {}

Camera3d::Camera3d(Point3d position, Rotation3d rotation, Scale3d scale, double fov) :
        Object3d(position, rotation, scale),
        fov(fov) {}