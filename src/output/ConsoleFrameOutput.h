//
// Created by Slava Petrov on 27.09.2023.
//

#ifndef GLORY3D_CONSOLEFRAMEOUTPUT_H
#define GLORY3D_CONSOLEFRAMEOUTPUT_H

#include <vector>
#include <string>
#include "FrameOutput.h"

class ConsoleFrameOutput : public FrameOutput {
public:
    ConsoleFrameOutput();

    void render(double **frame, std::tuple<int, int> frameSize, std::vector<std::string> debug) override;

    std::tuple<int, int> getViewportSizes() override;

private:
    static std::tuple<short, short> getConsoleDimensions();

    static double getCharProportion();

    static void setConsoleChar(short x, short y, char newChar);
};


#endif //GLORY3D_CONSOLEFRAMEOUTPUT_H
