#ifndef GLORY3D_CONSOLEFRAMEOUTPUT_H
#define GLORY3D_CONSOLEFRAMEOUTPUT_H

#include <vector>
#include <string>
#include "FrameOutput.h"

class ConsoleFrameOutput : public FrameOutput {
public:
    ConsoleFrameOutput();

    void render(double **frame, std::tuple<int, int> frameSize, std::vector<std::string> debug, bool showDebug) override;

    std::tuple<int, int> getViewportSizes() override;

private:
    static std::tuple<short, short> getConsoleDimensions();

    static double getCharProportion();
};


#endif