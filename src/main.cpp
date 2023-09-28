#include <windows.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "output/ConsoleFrameOutput.h"

double fov = 60;
int maxFps = 30;

long long int getTimeMillis();

int main() {
    HWND consoleWindow = GetConsoleWindow();

    auto out = ConsoleFrameOutput();

    double rx = 0, ry = 0;

    bool activeDebug = false;
    std::vector<std::string> debugMenu = {
            "----------------------",
            "| FPS: ",
            "----------------------"
    };
    std::vector<std::string> emptyMenu;

    bool isInFocus;
    double fps;
    while (true) {
        auto startRenderTime = getTimeMillis();

        isInFocus = (GetForegroundWindow() == consoleWindow);
        if (isInFocus && GetAsyncKeyState(VK_ESCAPE) != 0) return 0;
        if (isInFocus && GetAsyncKeyState(VK_F3) & 1) activeDebug = !activeDebug;
        if (isInFocus && GetAsyncKeyState(0x52) != 0)rx = 0, ry = 0;
        if (isInFocus && GetAsyncKeyState(VK_UP) & (1 << 15)) ry -= 0.5;
        if (isInFocus && GetAsyncKeyState(VK_DOWN) & (1 << 15)) ry += 0.5;
        if (isInFocus && GetAsyncKeyState(VK_LEFT) & (1 << 15)) rx -= 0.5;
        if (isInFocus && GetAsyncKeyState(VK_RIGHT) & (1 << 15)) rx += 0.5;
        if (isInFocus && GetAsyncKeyState(VK_OEM_PLUS) & 1) fov++;
        if (isInFocus && GetAsyncKeyState(VK_OEM_MINUS) & 1) fov--;

        if (activeDebug)
            debugMenu[1] = "FPS: " + std::to_string(fps);

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

        out.render(frame, tuple, activeDebug ? debugMenu : emptyMenu);

        if (maxFps > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(
                    (int) floor(1000.0 / maxFps - (double) (getTimeMillis() - startRenderTime))
            ));

        fps = 1.0 / ((double) (getTimeMillis() - startRenderTime) / 1000);
    }
}

long long getTimeMillis() {
    return std::chrono::time_point_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now()
    ).time_since_epoch().count();
}
