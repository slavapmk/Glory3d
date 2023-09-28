#include <windows.h>
#include <chrono>
#include "output/ConsoleFrameOutput.h"


double fov = 60;



int main() {

    auto out = ConsoleFrameOutput();

    double rx = 0, ry = 0;

    bool active = true;
    while (active) {

        short u = GetAsyncKeyState(VK_UP);
        short d = GetAsyncKeyState(VK_DOWN);
        short l = GetAsyncKeyState(VK_LEFT);
        short r = GetAsyncKeyState(VK_RIGHT);

        if (GetAsyncKeyState(VK_ESCAPE) != 0) active = false;

        if (u != 0) ry -= 0.5;
        if (d != 0) ry += 0.5;
        if (l != 0) rx -= 0.5;
        if (r != 0) rx += 0.5;

        const std::tuple<int, int> &tuple = out.getViewportSizes();
        const auto [width, height] = tuple;

        auto **frame = new double *[width];

        const auto maxSide = width > height ? width : height;

        for (int y = 0; y < height; y++) {
            frame[y] = new double[width];
            for (int x = 0; x < width; x++) {
                double xDegrees = (x - (double) (width - 1) / 2) / (maxSide - 1) * fov;
                double yDegrees = (y - (double) (height - 1) / 2) / (maxSide - 1) * fov;

                if (xDegrees > rx - 10 && xDegrees < rx + 10 && yDegrees > ry - 10 && yDegrees < ry + 10) {
                    frame[y][x] = 1;
                }
            }
        }

        out.render(frame, tuple);
    }
}
