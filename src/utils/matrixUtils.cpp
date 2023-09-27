#include <tuple>
#include <iostream>
#include <cmath>
#include "matrixUtils.h"

double **resizeMatrix(
        double **toResize,
        std::tuple<int, int> inputSizes, std::tuple<int, int> outputSizes
) {
    const auto [inputWidth, inputHeight] = inputSizes;
    const auto [outputWidth, outputHeight] = outputSizes;
    auto **matrix = new double *[outputHeight];

    for (int newY = 0; newY < outputHeight; newY++) {
        matrix[newY] = new double[outputWidth];
        for (int newX = 0; newX < outputWidth; newX++) {
            double sourceX = newX * (double) (inputWidth - 1) / (double) (outputWidth - 1);
            double sourceY = newY * (double) (inputHeight - 1) / (double) (outputHeight - 1);

            int leftX = static_cast<int>(std::floor(sourceX));
            int rightX = static_cast<int>(std::ceil(sourceX));
            int topY = static_cast<int>(std::floor(sourceY));
            int bottomY = static_cast<int>(std::ceil(sourceY));

            double leftTopValue = toResize[topY][leftX];
            double rightTopValue = toResize[topY][rightX];
            double leftBottomValue = toResize[bottomY][leftX];
            double rightBottomValue = toResize[bottomY][rightX];

            double xRatio = sourceX - leftX;
            double yRatio = sourceY - topY;

            double topInterpolation = (1 - xRatio) * leftTopValue + xRatio * rightTopValue;
            double bottomInterpolation = (1 - xRatio) * leftBottomValue + xRatio * rightBottomValue;

            matrix[newY][newX] = (1 - yRatio) * topInterpolation + yRatio * bottomInterpolation;
        }
    }

    return matrix;
}