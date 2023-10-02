#include "Object3d.h"

Object3d::Object3d(Point3d position, Rotation3d rotation) : position(position),
                                                            rotation(rotation),
                                                            scale(Scale3d(1, 1, 1)) {}

Object3d::Object3d(Point3d position, Rotation3d rotation, Scale3d scale) : position(position),
                                                                           rotation(rotation),
                                                                           scale(scale) {}
