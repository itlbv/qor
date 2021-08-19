#include "House.h"

const int House::WIDTH = 3;
const int House::HEIGHT = 4;

House::House(int id_a, int x_a, int y_a)
        : IBuilding(id_a, x_a, y_a, WIDTH, HEIGHT) {}
