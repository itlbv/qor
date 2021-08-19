#pragma once

#include "IBuilding.h"

class House : public IBuilding {
public:
    static const int WIDTH;
    static const int HEIGHT;

    House(int id_a, int x_a, int y_a);
};

