#include "CpuVisualizer.h"

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
            double xDegrees = (x - (double) (width - 1) / 2) / (density - 1) * scene.camera.fov;
            double yDegrees = (y - (double) (height - 1) / 2) / (density - 1) * scene.camera.fov;

            if (-15 <= xDegrees && xDegrees <= 15 && -15 <= yDegrees && yDegrees <= 15)
                frame[y][x] = 1;
            else
                frame[y][x] = 0;
        }
    }

    return frame;
}