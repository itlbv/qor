#ifndef QOR_ENTITY_H
#define QOR_ENTITY_H

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    std::unique_ptr<SDL_Rect> _renderShape;
    Vect _dest;

public:
    Vect _pos;
    const double _radius;

    Entity(double x, double y);

    SDL_Rect *getRenderShape();
};

#endif //QOR_ENTITY_H
