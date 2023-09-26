//
// Created by Slava Petrov on 27.09.2023.
//

#ifndef GLORY3D_CONSOLEFRAMEOUTPUT_H
#define GLORY3D_CONSOLEFRAMEOUTPUT_H


#include "FrameOutput.h"

class ConsoleFrameOutput : public FrameOutput {
public:
    ConsoleFrameOutput();

    void render(int cols, int rows, double **frame) override;

    std::tuple<int, int> getViewportSizes() override;

private:
    static std::tuple<int, int> getPixelDimensions();

    static std::tuple<int, int> getConsoleDimensions();

    static double getCharProportion(int charWidth, int charHeight);
};


#endif //GLORY3D_CONSOLEFRAMEOUTPUT_H
