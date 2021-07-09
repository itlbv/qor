#include "Entity.h"
#include "ai/Ai.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(int id_a, double x_a, double y_a)
        : id_(id_a),
          radius_(ENTITY_BODY_RADIUS),
          alive_(true) {
    renderShape_ = std::make_unique<SDL_Rect>();
    pos_ = std::make_unique<Vect>();
    pos_->x = x_a;
    pos_->y = y_a;
    dest_ = std::make_unique<Vect>();
    target_ = nullptr;
    velocity_ = std::make_unique<Vect>();
    behavior_ = Ai::getDefaultBehavior();
}

void Entity::update() {
    if (behavior_->run(*this) != RUNNING)
        setBehavior(Ai::getDefaultBehavior());
}

void Entity::defend() {
    alive_ = false;
}

void Entity::setBehavior(std::unique_ptr<Behavior> behavior_a) {
    behavior_ = std::move(behavior_a);
}

SDL_Rect *Entity::getRenderShape() {
    return renderShape_.get();
}

void Entity::setDest(double a_x, double a_y) {
    dest_->x = a_x;
    dest_->y = a_y;
}

Vect *Entity::getDest() {
    return dest_.get();
}


void Entity::setTarget(std::shared_ptr<Entity> e) {
    target_ = std::move(e);
}

Entity *Entity::getTarget() {
    return target_.get();
}

void Entity::setVelocity(Vect &velocity_a) {
    velocity_->x = velocity_a.x;
    velocity_->y = velocity_a.y;
}

Vect *Entity::getVelocity() {
    return velocity_.get();
}

bool Entity::isAlive() const {
    return alive_;
}
