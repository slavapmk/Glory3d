#include "Scene3d.h"

#include <utility>

Scene3d::Scene3d(std::vector<Renderable3d> objects, Camera3d camera) :
        objects(std::move(objects)), camera(camera) {}

void Scene3d::reset() {

}

void Scene3d::process(double ticks) {

}
