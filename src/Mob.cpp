#include "Mob.h"
#include "ai/Ai.h"
#include "Logger.h"

const double Mob::BODY_SIZE = 0.49;

Mob::Mob(int id_a, double x_a, double y_a)
        : Entity(id_a, x_a, y_a, BODY_SIZE, {0, 0, 255, 255}, TargetType::DYNAMIC, BODY_SIZE, BODY_SIZE),
          alive_(true),
          health_(3),
          target_(nullptr),
          hunger_(0),
          hungerUpdateInterval_(1000),
          previousHungerUpdateTime_(SDL_GetTicks()) {
    velocity_ = std::make_unique<Vect>();
    behavior_ = Ai::getDefaultBehavior();
}

void Mob::update() {
    if (isDead()) return;
    Ai::update(*this);
    updateHunger();
    updateRenderPosition();
}

void Mob::updateHunger() {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - previousHungerUpdateTime_ > hungerUpdateInterval_) {
        previousHungerUpdateTime_ = currentTime;
        hunger_ += 1;
        Logger::log(std::to_string(hunger_), *this);
    }
}

void Mob::defend() {
    health_--;
    if (health_ < 1) {
        alive_ = false;
        getRenderShape()->color.r = 150;
        getRenderShape()->color.g = 150;
        getRenderShape()->color.b = 150;
        getRenderShape()->color.a = 255;
    }
}

std::vector<std::shared_ptr<Item>> *Mob::getInventory() {
    return &inventory_;
}

std::weak_ptr<Target> Mob::getTarget() {
    return target_;
}

void Mob::setTarget(const std::shared_ptr<Target> &t) {
    target_ = t;
}

void Mob::setBehavior(std::unique_ptr<Behavior> behavior_a) {
//    Logger::log(behavior_a->getName(), *this);
    behavior_ = std::move(behavior_a);
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

int Mob::getHunger() {
    return hunger_;
}

void Mob::reduceHunger(int amount) {
    hunger_ -= amount;
}

Behavior *Mob::getBehavior() {
    return behavior_.get();
}
