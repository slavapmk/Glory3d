#include "Vector3d.h"

Vector3d::Vector3d(Point3d point, Direction3d direction) : point(point), direction(direction), length(1) {}

Vector3d::Vector3d(Point3d point, Direction3d direction, double length) : point(point), direction(direction),
                                                                          length(length) {}
