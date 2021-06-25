#include "Entity.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(double a_x, double a_y)
        : radius_(ENTITY_BODY_RADIUS) {
    _renderShape = std::make_unique<SDL_Rect>();
    pos_ = std::make_unique<Vect>();
    pos_->x = a_x;
    pos_->y = a_y;
    _dest = std::make_unique<Vect>();
    velocity_ = std::make_unique<Vect>();
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

void Entity::setVelocity(Vect &velocity_a) {
    velocity_->x = velocity_a.x;
    velocity_->y = velocity_a.y;
}

Vect *Entity::getVelocity() {
    return velocity_.get();
}
