#include "Entity.h"
#include "Logger.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(int id_a, double x_a, double y_a)
        : id_(id_a),
          radius_(ENTITY_BODY_RADIUS) {
    renderShape_ = std::make_unique<SDL_Rect>();
    pos_ = std::make_unique<Vect>();
    pos_->x = x_a;
    pos_->y = y_a;
}

int Entity::getId() {
    return id_;
}

Vect *Entity::getPos() {
    return pos_.get();
}

double Entity::getRadius() {
    return radius_;
}

SDL_Rect *Entity::getRenderShape() {
    return renderShape_.get();
}
