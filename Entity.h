#ifndef QOR_ENTITY_H
#define QOR_ENTITY_H

#include <SDL.h>
#include "Vect.h"

class Entity {
private:
    SDL_Rect renderShape{};
public:
    Vect pos;
    double radius;

    Entity(double x, double y);

    SDL_Rect *getRenderShape();
};


#endif //QOR_ENTITY_H
