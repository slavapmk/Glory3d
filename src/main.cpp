#include "output/ConsoleFrameOutput.h"

double fov = 60;

int main() {

    auto out = ConsoleFrameOutput();

    while (true) {
        const std::tuple<int, int> &tuple = out.getViewportSizes();
        const auto [width, height] = tuple;

        auto **frame = new double *[width];

        const auto maxSide = width > height ? width : height;

        for (int y = 0; y < height; y++) {
            frame[y] = new double[width];
            for (int x = 0; x < width; x++) {
                double xDegrees = (x - (double) (width - 1) / 2) / (maxSide - 1) * fov;
                double yDegrees = (y - (double) (height - 1) / 2) / (maxSide - 1) * fov;

                if (xDegrees > -10 && xDegrees < 10 && yDegrees > -10 && yDegrees < 10) {
                    frame[y][x] = 1;
                }
            }
        }

        out.render(frame, tuple);
    }
}
