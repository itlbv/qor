#include "Building.h"

Building::Building(int id_a, int x_a, int y_a, int width_a, int height_a)
        : Entity(id_a, x_a, y_a, 2, {0, 0, 0, 255}, STATIC, width_a, height_a) {}
