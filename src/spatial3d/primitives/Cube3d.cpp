#include "Cube3d.h"

std::vector<Polygon3d> parsePolygons(double edge) {
    return {
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    0.2
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, -0.5 * edge),
                    0.2
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    0.21
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    0.21
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    0.22
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    0.22
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    0.23
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, -0.5 * edge),
                    0.23
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    0.24
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, -0.5 * edge),
                    0.24
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    0.25
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    0.25
            )
    };
}

Cube3d::Cube3d(Point3d position, Rotation3d rotation, double edge) : Renderable3d(
        position, rotation, parsePolygons(edge)
) {}

Cube3d::Cube3d(Point3d position, Rotation3d rotation, Scale3d scale, double edge) : Renderable3d(
        position, rotation, scale, parsePolygons(edge)
) {}