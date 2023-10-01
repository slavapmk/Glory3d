#include "ConsoleFrameOutput.h"
#include "../utils/matrixUtils.h"
#include <windows.h>
#include <cmath>
#include <iostream>
#include <vector>

const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

const char gradient[] = " .:;+=xX$&";
int gradientLength = sizeof(gradient) / sizeof(char) - 1;

std::string multiple(const std::string &input, unsigned int times) {
    std::string output;
    for (int i = 0; i < times; ++i)
        output += input;
    return output;
}

std::vector<std::string> parseDebug(const std::vector<std::string> &info) {
    std::vector<std::string> out;

    unsigned long long max = 0;
    for (const auto &item: info)
        if (max < item.size())
            max = item.size();


    std::string line = multiple("-", max + 4);

    out.push_back(line);

    for (const auto &item: info) {
        out.push_back(
                "| " +
                item +
                multiple(" ", max - item.size()) +
                " |"
        );
    }

    out.push_back(line);

    return out;
}

void ConsoleFrameOutput::render(
        double **frame, std::tuple<int, int> frameSize,
        std::vector<std::string> debugInfo,
        bool showDebug
) {
    const auto [width, height] = getConsoleDimensions();

    const auto resized = resizeMatrix(
            frame,
            frameSize,
            {width, height}
    );
    DWORD charsWritten;
    COORD position = {0, 0};
    SetConsoleCursorPosition(handle, position);

    const std::vector<std::string> &debug = parseDebug(debugInfo);
    unsigned long long int debugSize = debug.size();

    for (short y = 0; y < height; y++) {
        const auto row = new char[width];
        for (short x = 0; x < width; x++)
            row[x] = gradient[(int) (resized[y][x] * (gradientLength - 1))];

        if (showDebug && y < debugSize)
            for (int x = 0; x < debug[y].length(); x++)
                row[x] = debug[y][x];

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
