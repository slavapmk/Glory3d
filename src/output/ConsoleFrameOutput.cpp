#include "ConsoleFrameOutput.h"
#include <windows.h>
#include <cmath>
#include <iostream>

void ConsoleFrameOutput::render(int cols, int rows, double **frame) {
    std::cout << "Helloooo!!1" << std::endl;
}

std::tuple<int, int> ConsoleFrameOutput::getViewportSizes() {
    const auto [charWidth, charHeight] = getPixelDimensions();
    const auto [consoleWidth, consoleHeight] = getConsoleDimensions();
    double charProportion = getCharProportion(charWidth, charHeight);
    return {consoleWidth, consoleHeight / charProportion};
}

static int lastCharWidth = 0;
static int lastCharHeight = 0;
static double lastCharProportion = 0;

double ConsoleFrameOutput::getCharProportion(int charWidth, int charHeight) {
    if (lastCharHeight != charHeight || lastCharWidth != charWidth) {
        lastCharWidth = charWidth;
        lastCharHeight = charHeight;
        return sqrt(((double) charHeight) / ((double) charWidth) / 2.0) / 2.0;
    }
    return lastCharProportion;
}

std::tuple<int, int> ConsoleFrameOutput::getPixelDimensions() {
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);

    return {fontInfo.dwFontSize.X, fontInfo.dwFontSize.Y};
}

std::tuple<int, int> ConsoleFrameOutput::getConsoleDimensions() {
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

    return {
            bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1,
            bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1
    };
}

ConsoleFrameOutput::ConsoleFrameOutput() = default;
