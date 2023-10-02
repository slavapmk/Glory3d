#include "Renderable3d.h"

#include <utility>

Renderable3d::Renderable3d(Point3d position, Rotation3d rotation, std::vector<Polygon3d> model) :
        Object3d(position, rotation),
        model(std::move(model)) {}

Renderable3d::Renderable3d(Point3d position, Rotation3d rotation, Scale3d scale, std::vector<Polygon3d> model) :
        Object3d(position, rotation, scale),
        model(std::move(model)) {}

std::vector<Polygon3d> Renderable3d::finalState() {
    std::vector<Polygon3d> result = {};
    result.reserve(model.size());
    for (auto polygon: model)
        result.emplace_back(
                polygon.a.multiply(scale).rotate(rotation, Point3d(0, 0, 0)).add(position),
                polygon.b.multiply(scale).rotate(rotation, Point3d(0, 0, 0)).add(position),
                polygon.c.multiply(scale).rotate(rotation, Point3d(0, 0, 0)).add(position)
        );
    return result;
}
