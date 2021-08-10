#include "Mob.h"
#include "ai/Ai.h"
#include "Logger.h"

Mob::Mob(int id_a, double x_a, double y_a)
        : Entity(id_a, x_a, y_a, {0, 0, 255, 255}),
          alive_(true),
          health_(3) {
    dest_ = std::make_unique<Vect>();
    target_ = nullptr;
    velocity_ = std::make_unique<Vect>();
    behavior_ = Ai::getDefaultBehavior();
}

void Mob::update() {
    if (isDead()) return;
    if (behavior_->run(*this) != RUNNING)
        setBehavior(Ai::getDefaultBehavior());
}

void Mob::defend() {
    health_--;
    if (health_ < 1)
        alive_ = false;
}

void Mob::setBehavior(std::unique_ptr<Behavior> behavior_a) {
    Logger::log(behavior_a->getName(), *this);
    behavior_ = std::move(behavior_a);
}

void Mob::setDest(double a_x, double a_y) {
    dest_->x = a_x;
    dest_->y = a_y;
}

Vect *Mob::getDest() {
    return dest_.get();
}

void Mob::setTarget(std::shared_ptr<Mob> m) {
    target_ = std::move(m);
}


Mob *Mob::getTarget() {
    return target_.get();
}

void Mob::setVelocity(Vect &velocity_a) {
    velocity_->x = velocity_a.x;
    velocity_->y = velocity_a.y;
}

Vect *Mob::getVelocity() {
    return velocity_.get();
}

bool Mob::isDead() const {
    return !alive_;
}