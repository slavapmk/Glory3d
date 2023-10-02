#ifndef GLORY3D_RENDERABLE3D_H
#define GLORY3D_RENDERABLE3D_H

#include <vector>
#include "Object3d.h"
#include "Polygon3d.h"

class Renderable3d : Object3d {
public:
    std::vector<Polygon3d> model;

    Renderable3d(Point3d position, Rotation3d rotation, std::vector<Polygon3d> model);

    Renderable3d(Point3d position, Rotation3d rotation, Scale3d scale, std::vector<Polygon3d> model);
};

#endif
