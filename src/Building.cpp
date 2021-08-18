#include "Building.h"

Building::Building(int id_a, double x_a, double y_a, double width_a, double height_a)
        : Entity(id_a, x_a, y_a, 2, {0, 0, 0, 255}, STATIC, width_a, height_a) {}
