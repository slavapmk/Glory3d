#ifndef GLORY3D_UTILS3D_H
#define GLORY3D_UTILS3D_H

#include <tuple>
#include "primitives/Point3d.h"
#include "primitives/Polygon3d.h"
#include "primitives/Direction3d.h"
#include "primitives/Vector3d.h"

std::tuple<double, double, double> scalarIntersect(
        std::tuple<double, double, double> edge,
        Point3d intersect,
        Point3d polygonPoint
);

Point3d *intersectTriangle(
        Polygon3d polygon,
        Point3d ray_origin,
        Direction3d rayDirection
);

std::tuple<Point3d, Polygon3d> *intersectPolygons(
        Vector3d ray,
        Polygon3d *polygons,
        int polygonsCount
);

#endif
