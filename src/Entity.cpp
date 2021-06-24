#include "Entity.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(double a_x, double a_y)
        : _radius(ENTITY_BODY_RADIUS) {
    _renderShape = std::make_unique<SDL_Rect>();
    _pos = std::make_unique<Vect>();
    _pos->x = a_x;
    _pos->y = a_y;
    _dest = std::make_unique<Vect>();
    _velocity = std::make_unique<Vect>();
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

void Entity::setVelocity(double a_x, double a_y) {
    _velocity->x = a_x;
    _velocity->y = a_y;
}

Vect *Entity::getVelocity() {
    return _velocity.get();
}
