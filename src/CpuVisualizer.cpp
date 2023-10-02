#include "CpuVisualizer.h"
#include "spatial3d/primitives/Direction3d.h"
#include "spatial3d/utils3d.h"

double **render(const Scene3d &scene, int width, int height) {
    int density = width > height ? width : height;
    std::vector<Polygon3d> allPolygons = {};
    for (auto object: scene.objects) {
        std::vector<Polygon3d> parsedObject = object.finalState();
        allPolygons.insert(allPolygons.end(), parsedObject.begin(), parsedObject.end());
    }

    auto **frame = new double *[width];

    for (int y = 0; y < height; y++) {
        frame[y] = new double[width];
        for (int x = 0; x < width; x++) {
            double xDegrees = (x - (double) (width - 1) / 2) / (density - 1) * *scene.camera.fov;
            double yDegrees = (y - (double) (height - 1) / 2) / (density - 1) * *scene.camera.fov;

            Direction3d direction = Direction3d(0, 1, 0).rotate(Rotation3d(
                    -(scene.camera.rotation.x_axis + yDegrees),
                    0,
                    -(scene.camera.rotation.z_axis + xDegrees)
            ));

            std::tuple<Point3d, Polygon3d> *pTuple = intersectPolygons(
                    Vector3d(scene.camera.position, direction),
                    allPolygons
            );

            frame[y][x] = pTuple == nullptr ? 0 : 1;

//            if (pTuple == nullptr) {
//                frame[y][x] = 0;
//                continue;
//            }
//
//            auto [intersection, polygon] = *pTuple;
//            frame[y][x] = polygon.v;
        }
    }

    return frame;
}