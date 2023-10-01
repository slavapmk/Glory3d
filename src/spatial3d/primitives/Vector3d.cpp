#include "Vector3d.h"

Vector3d::Vector3d(Point3d *point, Direction3d *direction) {
    this->point = *point;
    this->direction = *direction;
    this->length = 1;
}

Vector3d::Vector3d(Point3d *point, Direction3d *direction, double length) {
    this->point = *point;
    this->direction = *direction;
    this->length = length;
}
