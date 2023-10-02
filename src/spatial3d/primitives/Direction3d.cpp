#include "Direction3d.h"
#include "Rotation3d.h"
#include "Point3d.h"

Direction3d::Direction3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Direction3d Direction3d::rotate(Rotation3d rotation) const {
    const Point3d &d = Point3d(x, y, z).rotate(rotation, Point3d(0, 0, 0));
    return {d.x, d.y, d.z};
}
