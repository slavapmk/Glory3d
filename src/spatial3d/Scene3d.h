#ifndef GLORY3D_SCENE3D_H
#define GLORY3D_SCENE3D_H

#include <vector>
#include "primitives/Renderable3d.h"
#include "primitives/Camera3d.h"

class Scene3d {
public:
    std::vector<Renderable3d> objects;
    Camera3d camera;

    Scene3d(std::vector<Renderable3d> objects, Camera3d camera);
};

#endif