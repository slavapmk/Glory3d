//
// Created by Slava Petrov on 27.09.2023.
//

#ifndef GLORY3D_FRAMEOUTPUT_H
#define GLORY3D_FRAMEOUTPUT_H


#include <tuple>
#include <vector>
#include <string>

class FrameOutput {
public:
    virtual void render(double **frame, std::tuple<int, int> dimension, std::vector<std::string> debug, bool b) {}

    virtual std::tuple<int, int> getViewportSizes() { return {}; }
};


#endif //GLORY3D_FRAMEOUTPUT_H
