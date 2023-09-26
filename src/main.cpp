#include <iostream>
#include "output/ConsoleFrameOutput.h"


int main() {
    auto out = ConsoleFrameOutput();
    const auto [width, height] = out.getViewportSizes();
    std::cout << width << std::endl << height << std::endl;
//    out.render(1, 1, [[1.0]]);
    int fw;
    std::cin >> fw;
    return 0;
}
