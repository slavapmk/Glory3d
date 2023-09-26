//
// Created by Slava Petrov on 27.09.2023.
//

#ifndef GLORY3D_FRAMEOUTPUT_H
#define GLORY3D_FRAMEOUTPUT_H


#include <tuple>

class FrameOutput {
public:
    virtual void render(int cols, int rows, double** frame) {}

    virtual std::tuple<int, int> getViewportSizes() { return {}; }
};


#endif //GLORY3D_FRAMEOUTPUT_H
