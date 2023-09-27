#include "ConsoleFrameOutput.h"
#include "../utils/matrixUtils.h"
#include <windows.h>
#include <cmath>
#include <iostream>

const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleFrameOutput::render(double **frame, std::tuple<int, int> frameSize) {
    const auto [width, height] = getConsoleDimensions();

    const auto resized = resizeMatrix(
            frame,
            frameSize,
            {width, height}
    );

    DWORD charsWritten;
    COORD position = {0, 0};
    SetConsoleCursorPosition(handle, position);
    for (short y = 0; y < height; y++) {
        const auto row = new char[width];
        for (short x = 0; x < width; x++)
            row[x] = resized[y][x] > 0.5 ? 'X' : '.';
        WriteConsoleOutputCharacter(
                handle,
                row,
                width,
                position,
                &charsWritten
        );
        position.Y++;
    }
}

std::tuple<int, int> ConsoleFrameOutput::getViewportSizes() {
    const auto [consoleWidth, consoleHeight] = getConsoleDimensions();
    double charProportion = getCharProportion();
    return {consoleWidth, round((double) consoleHeight / charProportion)};
}

static double lastCharWidth = 0;
static double lastCharHeight = 0;
static double lastCharProportion = 0;

CONSOLE_FONT_INFOEX fontInfo;

double ConsoleFrameOutput::getCharProportion() {
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(handle, FALSE, &fontInfo);

    double charHeight = fontInfo.dwFontSize.Y + 1;
    double charWidth = fontInfo.dwFontSize.X + 1;

    if (lastCharHeight != charHeight || lastCharWidth != charWidth) {
        lastCharWidth = charWidth;
        lastCharHeight = charHeight;
        lastCharProportion = sqrt(charHeight / charWidth / 2) / 2;
    }

    return lastCharProportion;
}

std::tuple<short, short> ConsoleFrameOutput::getConsoleDimensions() {
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    GetConsoleScreenBufferInfo(handle, &bufferInfo);

    return {
            bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1,
            bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1
    };
}

ConsoleFrameOutput::ConsoleFrameOutput() = default;
