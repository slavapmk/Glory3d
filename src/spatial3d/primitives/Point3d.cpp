#include "Point3d.h"
#include <cmath>

Point3d::Point3d(double x, double y, double z) : x(x), y(y), z(z) {}

Point3d Point3d::add(Point3d point) const {
    return {
            x + point.x,
            y + point.y,
            z + point.z
    };
}

Point3d Point3d::multiply(Scale3d scale) const {
    return {
            x * scale.x,
            y * scale.y,
            z * scale.z
    };
}

Point3d Point3d::rotate(Rotation3d rotation, Point3d axis) const {
    double r = M_PI / 180;
    double sinX = sin(rotation.x_axis * r);
    double sinY = sin(rotation.y_axis * r);
    double sinZ = sin(rotation.z_axis * r);
    double cosX = cos(rotation.x_axis * r);
    double cosY = cos(rotation.y_axis * r);
    double cosZ = cos(rotation.z_axis * r);

    double regardX = x - axis.x;
    double regardY = y - axis.y;
    double regardZ = z - axis.z;

    return {
            regardX * (cosY * cosZ) -
            regardY * (sinZ * cosY) +
            regardZ * sinY +
            axis.x,
            regardX * (sinX * sinY * cosZ + sinZ * cosX) +
            regardY * (-sinX * sinY * sinZ + cosX * cosZ) +
            regardZ * (-sinX * cosY) +
            axis.y,
            regardX * (sinX * sinZ - sinY * cosX * cosZ) +
            regardY * (sinX * cosZ + sinY * sinZ * cosX) +
            regardZ * cosX * cosY +
            axis.z
    };
}