#pragma once

#include "Entity.h"

class Player : public Entity {
private:
    void move();

public:
    static const double Speed;

    Player(double x_a, double y_a);

    void update();

    void checkCollisions();
};
