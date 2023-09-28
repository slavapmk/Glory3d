cmake_minimum_required(VERSION 3.26)
project(Glory3d)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Glory3d
        src/main.cpp
        src/output/FrameOutput.cpp
        src/output/FrameOutput.h
        src/output/ConsoleFrameOutput.cpp
        src/output/ConsoleFrameOutput.h
        src/utils/matrixUtils.cpp
        src/utils/matrixUtils.h
        src/spatial3d/primitives/Point3d.cpp
        src/spatial3d/primitives/Point3d.h
        src/spatial3d/primitives/Rotation3d.cpp
        src/spatial3d/primitives/Rotation3d.h
        src/spatial3d/primitives/Scale3d.cpp
        src/spatial3d/primitives/Scale3d.h
        src/spatial3d/primitives/Direction3d.cpp
        src/spatial3d/primitives/Direction3d.h
        src/spatial3d/primitives/Vector3d.cpp
        src/spatial3d/primitives/Vector3d.h
        src/spatial3d/primitives/Polygon3d.cpp
        src/spatial3d/primitives/Polygon3d.h
        src/spatial3d/primitives/Object3d.cpp
        src/spatial3d/primitives/Object3d.h
        src/spatial3d/primitives/Light3d.cpp
        src/spatial3d/primitives/Light3d.h
        src/spatial3d/primitives/Renderable3d.cpp
        src/spatial3d/primitives/Renderable3d.h
        src/spatial3d/primitives/Cube3d.cpp
        src/spatial3d/primitives/Cube3d.h
        src/spatial3d/primitives/Camera3d.cpp
        src/spatial3d/primitives/Camera3d.h
        src/spatial3d/primitives/Scene3d.cpp
        src/spatial3d/primitives/Scene3d.h
        src/spatial3d/utils3d.cpp
        src/spatial3d/utils3d.h
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")