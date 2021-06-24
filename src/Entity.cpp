#include "Entity.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(double x, double y)
        : _pos({x, y}),
          _radius(ENTITY_BODY_RADIUS) {
    _renderShape = std::make_unique<SDL_Rect>();
    _dest = std::make_unique<Vect>();
}

SDL_Rect *Entity::getRenderShape() {
    return _renderShape.get();
}

void Entity::setDest(double a_x, double a_y) {
    _dest->x = a_x;
    _dest->y = a_y;
}

Vect *Entity::getDest() {
    return _dest.get();
}
