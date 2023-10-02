#include "Renderable3d.h"

#include <utility>

Renderable3d::Renderable3d(Point3d position, Rotation3d rotation, std::vector<Polygon3d> model) :
        Object3d(position, rotation),
        model(std::move(model)) {}

Renderable3d::Renderable3d(Point3d position, Rotation3d rotation, Scale3d scale, std::vector<Polygon3d> model) :
        Object3d(position, rotation, scale),
        model(std::move(model)) {}
