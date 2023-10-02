#include "Cube3d.h"

std::vector<Polygon3d> parsePolygons(double edge) {
    return {
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge)
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge)
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge)
            ),
            Polygon3d(
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, -0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, 0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, 0.5 * edge, -0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(-0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge)
            ),
            Polygon3d(
                    Point3d(-0.5 * edge, -0.5 * edge, -0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, 0.5 * edge),
                    Point3d(0.5 * edge, -0.5 * edge, -0.5 * edge)
            )
    };
}

Cube3d::Cube3d(Point3d position, Rotation3d rotation, double edge) : Renderable3d(
        position, rotation, parsePolygons(edge)
) {}

Cube3d::Cube3d(Point3d position, Rotation3d rotation, Scale3d scale, double edge) : Renderable3d(
        position, rotation, scale, parsePolygons(edge)
) {}