#include <windows.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "output/ConsoleFrameOutput.h"
#include "CpuVisualizer.h"
#include "utils/timeUtils.h"
#include "spatial3d/primitives/Cube3d.h"
#include "spatial3d/utils3d.h"

int maxFps = 100;

int main() {
    Camera3d camera = Camera3d(
            Point3d(0, 0, 0),
            Rotation3d(0, 0, 0),
            60
    );
    const Cube3d &d1 = Cube3d(
            {0, 5, 0},
            {0, 0, 0},
            0.1
    );
    Scene3d scene = Scene3d(
            {d1},
            camera
    );

    HWND consoleWindow = GetConsoleWindow();

    auto out = ConsoleFrameOutput();

    bool activeDebug = false;

    bool isInFocus;
    double fps;
    while (true) {
        auto startRenderTime = getTimeMillis();

        isInFocus = (GetForegroundWindow() == consoleWindow);
        if (isInFocus && GetAsyncKeyState(VK_ESCAPE) != 0) return 0;
        if (isInFocus && GetAsyncKeyState(VK_F3) & 1) activeDebug = !activeDebug;
        if (isInFocus && GetAsyncKeyState(0x52) != 0) scene.reset();
        *camera.fov = (isInFocus && GetAsyncKeyState(0x5A) != 0) ? 30 : 60;

        const std::tuple<int, int> &tuple = out.getViewportSizes();
        const auto [width, height] = tuple;

        out.render(
                render(scene, width, height), tuple, {
                        "FPS: " + std::to_string(fps)
                },
                activeDebug
        );

        if (maxFps > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(
                    (int) floor(1000.0 / maxFps - (double) (getTimeMillis() - startRenderTime))
            ));

        double d = (double) (getTimeMillis() - startRenderTime) / 1000;
        if (d != 0) fps = 1.0 / d;
    }
}

int main_() {
//    auto g = Point3d(0, 1, 0).rotate({0, 0, 90}, {0, 0, 0});


    const Cube3d &d = Cube3d(
            {0, 0, 0},
            {0, 0, 0},
            0.1
    );

    auto A = intersectPolygons(
            {{0, 0, 1},
             {0, 1, 0}},
            {
                    {{-3, -2, 0},
                     {3, -2, 0},
                     {0, 2, 0},
                     1}
            }
    );

    return 0;
}