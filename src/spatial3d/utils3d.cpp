#include "utils3d.h"
#include <cmath>
#include <vector>

using namespace std;

std::tuple<double, double, double> scalarIntersect(
        std::tuple<double, double, double> edge,
        Point3d intersect,
        Point3d polygonPoint
) {
    const auto [edge0, edge1, edge2] = edge;
    return {
            edge1 * (intersect.z - polygonPoint.z) - edge2 * (intersect.y - polygonPoint.y),
            edge2 * (intersect.x - polygonPoint.x) - edge0 * (intersect.z - polygonPoint.z),
            edge0 * (intersect.y - polygonPoint.y) - edge1 * (intersect.x - polygonPoint.x)
    };
}

Point3d *intersectTriangle(
        Polygon3d polygon,
        Point3d ray_origin,
        Direction3d rayDirection
) {
    const tuple<double, double, double> normal = {
            (polygon.b.y - polygon.a.y) * (polygon.c.z - polygon.a.z)
            - (polygon.c.y - polygon.a.y) * (polygon.b.z - polygon.a.z),
            (polygon.b.z - polygon.a.z) * (polygon.c.x - polygon.a.x)
            - (polygon.c.z - polygon.a.z) * (polygon.b.x - polygon.a.x),
            (polygon.b.x - polygon.a.x) * (polygon.c.y - polygon.a.y)
            - (polygon.c.x - polygon.a.x) * (polygon.b.y - polygon.a.y)
    };

    const double dotProduct = get<0>(normal) * rayDirection.x +
                              get<1>(normal) * rayDirection.y +
                              get<2>(normal) * rayDirection.z;

    if (abs(dotProduct) < 1e-6)
        return nullptr;

    double d = get<0>(normal) * polygon.a.x + get<1>(normal) * polygon.a.y + get<2>(normal) * polygon.a.z;
    double t = (d - get<0>(normal) * ray_origin.x - get<1>(normal) * ray_origin.y - get<2>(normal) * ray_origin.z) /
               dotProduct;
    if (t < 0)
        return nullptr;

    double x = ray_origin.x + rayDirection.x * t;
    double y = ray_origin.y + rayDirection.y * t;
    double z = ray_origin.z + rayDirection.z * t;

    auto intersect = Point3d(x, y, z);

    tuple<double, double, double> edge0 = {polygon.b.x - polygon.a.x, polygon.b.y - polygon.a.y,
                                           polygon.b.z - polygon.a.z};
    tuple<double, double, double> edge1 = {polygon.c.x - polygon.b.x, polygon.c.y - polygon.b.y,
                                           polygon.c.z - polygon.b.z};
    tuple<double, double, double> edge2 = {polygon.a.x - polygon.c.x, polygon.a.y - polygon.c.y,
                                           polygon.a.z - polygon.c.z};

    const auto cp0 = scalarIntersect(edge0, intersect, polygon.a);
    const auto cp1 = scalarIntersect(edge1, intersect, polygon.b);
    const auto cp2 = scalarIntersect(edge2, intersect, polygon.c);

    if (get<0>(cp0) * get<0>(normal) + get<1>(cp0) * get<1>(normal) + get<2>(cp0) * get<2>(normal) >= 0 ||
        get<0>(cp1) * get<0>(normal) + get<1>(cp1) * get<1>(normal) + get<2>(cp1) * get<2>(normal) >= 0 ||
        get<0>(cp2) * get<0>(normal) + get<1>(cp2) * get<1>(normal) + get<2>(cp2) * get<2>(normal) >= 0) {
        static Point3d *pD = &intersect;
        return pD;
    } else return nullptr;
}

std::tuple<Point3d, Polygon3d> *intersectPolygons(
        Vector3d ray,
        const std::vector<Polygon3d> &polygons
) {
    Point3d *closestIntersection = nullptr;
    Polygon3d *closestPolygon = nullptr;
    double *closestDistance = nullptr;
    for (auto polygon: polygons) {
        auto intersection = intersectTriangle(polygon, ray.point, ray.direction);
        if (intersection != nullptr) {
            auto distance =
                    pow(intersection->x - ray.point.x, 2) +
                    pow(intersection->y - ray.point.y, 2) +
                    pow(intersection->z - ray.point.z, 2);

            if (closestIntersection == nullptr || distance < *closestDistance) {
                closestIntersection = intersection;
                closestPolygon = &polygon;
                closestDistance = &distance;
            }
        }
    }
    if (closestIntersection != nullptr) {
        std::tuple<Point3d, Polygon3d> d = {*closestIntersection, *closestPolygon};
        static std::tuple<Point3d, Polygon3d> *pTuple = &d;
        return pTuple;
    } else
        return nullptr;
}