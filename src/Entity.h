#ifndef QOR_ENTITY_H
#define QOR_ENTITY_H

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    const static double BodyRadius;
    std::unique_ptr<SDL_Rect> _renderShape;

public:
    Vect pos;
    double radius;

    Entity(double x, double y);

    SDL_Rect *getRenderShape();
};

#endif //QOR_ENTITY_H
