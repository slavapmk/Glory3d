cmake_minimum_required(VERSION 3.26)
project(Glory3d)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-static-libgcc -static-libstdc++")

add_executable(Glory3d src/main.cpp
        src/output/FrameOutput.cpp
        src/output/FrameOutput.h
        src/output/ConsoleFrameOutput.cpp
        src/output/ConsoleFrameOutput.h
        src/utils/matrixUtils.cpp
        src/utils/matrixUtils.h)
