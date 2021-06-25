#ifndef QOR_PLAYER_H
#define QOR_PLAYER_H


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


#endif //QOR_PLAYER_H
