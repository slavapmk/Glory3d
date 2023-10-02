#include <windows.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "output/ConsoleFrameOutput.h"
#include "CpuVisualizer.h"

double fov = 60;
int maxFps = 00;

long long int getTimeMillis();

int main() {
    Scene3d scene = Scene3d(
            {},
            Camera3d(
                    Point3d(0, 0, 0),
                    Rotation3d(0, 0, 0),
                    30
            )
    );

    HWND consoleWindow = GetConsoleWindow();

    auto out = ConsoleFrameOutput();

    double rx = 0, ry = 0;

    bool activeDebug = false;

    bool isInFocus;
    double fps;
    while (true) {
        auto startRenderTime = getTimeMillis();

        isInFocus = (GetForegroundWindow() == consoleWindow);
        if (isInFocus && GetAsyncKeyState(VK_ESCAPE) != 0) return 0;
        if (isInFocus && GetAsyncKeyState(VK_F3) & 1) activeDebug = !activeDebug;
        if (isInFocus && GetAsyncKeyState(0x52) != 0) rx = 0, ry = 0;
        if (isInFocus && GetAsyncKeyState(VK_UP) & (1 << 15)) ry -= 20 / fps;
        if (isInFocus && GetAsyncKeyState(VK_DOWN) & (1 << 15)) ry += 20 / fps;
        if (isInFocus && GetAsyncKeyState(VK_LEFT) & (1 << 15)) rx -= 20 / fps;
        if (isInFocus && GetAsyncKeyState(VK_RIGHT) & (1 << 15)) rx += 20 / fps;
        if (isInFocus && GetAsyncKeyState(VK_OEM_PLUS) & 1) fov++;
        if (isInFocus && GetAsyncKeyState(VK_OEM_MINUS) & 1) fov--;

        const std::tuple<int, int> &tuple = out.getViewportSizes();
        const auto [width, height] = tuple;

        out.render(render(scene, width, height), tuple, {"FPS: " + std::to_string(fps)}, activeDebug);

        if (maxFps > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(
                    (int) floor(1000.0 / maxFps - (double) (getTimeMillis() - startRenderTime))
            ));

        double d = (double) (getTimeMillis() - startRenderTime) / 1000;
        if (d != 0)
            fps = 1.0 / d;
    }
}

long long getTimeMillis() {
    return std::chrono::time_point_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now()
    ).time_since_epoch().count();
}
