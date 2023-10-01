#include "Rotation3d.h"

Rotation3d::Rotation3d() {
    this->x_axis = 0;
    this->y_axis = 0;
    this->z_axis = 0;
}

Rotation3d::Rotation3d(double x_axis, double y_axis, double z_axis) {
    this->x_axis = x_axis;
    this->y_axis = y_axis;
    this->z_axis = z_axis;
}
