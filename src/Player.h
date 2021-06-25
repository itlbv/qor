#ifndef QOR_PLAYER_H
#define QOR_PLAYER_H


#include "Entity.h"

class Player : public Entity {
private:
    void move();

public:
    Vect velocity_player_;

    Player(double x_a, double y_a);

    void update();

    void checkCollisions();
};


#endif //QOR_PLAYER_H
