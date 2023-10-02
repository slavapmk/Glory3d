#include "Camera3d.h"

Camera3d::Camera3d(Point3d position, Rotation3d rotation, double fov) :
        Object3d(position, rotation),
        position(position),
        rotation(rotation),
        scale(Scale3d(1, 1, 1)),
        fov(new double(fov)) {}

Camera3d::Camera3d(Point3d position, Rotation3d rotation, Scale3d scale, double fov) :
        Object3d(position, rotation, scale),
        position(position),
        rotation(rotation),
        scale(scale),
        fov(new double(fov)) {}