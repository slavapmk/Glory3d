cmake_minimum_required(VERSION 3.26)
project(Glory3d)

set(CMAKE_CXX_STANDARD 17)

add_executable(Glory3d src/main.cpp
        src/output/FrameOutput.cpp
        src/output/FrameOutput.h
        src/output/ConsoleFrameOutput.cpp
        src/output/ConsoleFrameOutput.h)
