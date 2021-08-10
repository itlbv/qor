#pragma once

#include "Mob.h"

class Player : public Mob {
private:
    void move();

public:
    static const double Speed;

    Player(double x_a, double y_a);

    void update();

    void checkCollisions();
};
