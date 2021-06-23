#ifndef QOR_ENTITY_H
#define QOR_ENTITY_H

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    std::unique_ptr<SDL_Rect> _renderShape;
    Vect dest;

public:
    Vect pos;
    const double radius;

    Entity(double x, double y);

    SDL_Rect *getRenderShape();
};

#endif //QOR_ENTITY_H
