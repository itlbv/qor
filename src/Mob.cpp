#include "Mob.h"
#include "ai/Ai.h"
#include "Logger.h"

Mob::Mob(int id_a, double x_a, double y_a)
        : Entity(id_a, x_a, y_a, 0.49, {0, 0, 255, 255}, TargetType::DYNAMIC),
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
    updateHunger();
    if (behavior_->run(*this) != RUNNING)
        setBehavior(Ai::getDefaultBehavior());
}

void Mob::updateHunger() {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - previousHungerUpdateTime_ > hungerUpdateInterval_) {
        previousHungerUpdateTime_ = currentTime;
        Logger::log("hunger +1", *this);
        hunger_ += 1;
    }
}

void Mob::defend() {
    health_--;
    if (health_ < 1) {
        alive_ = false;
        setRenderColor(150, 150, 150, 255); //gray
    }
}

std::vector<std::unique_ptr<Item>> *Mob::getInventory() {
    return &inventory_;
}

std::weak_ptr<Target> Mob::getTarget() {
    return target_;
}

void Mob::setTarget(const std::shared_ptr<Target> &t) {
    target_ = t;
}

void Mob::setBehavior(std::unique_ptr<Behavior> behavior_a) {
    Logger::log(behavior_a->getName(), *this);
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

double Mob::getHunger() {
    return hunger_;
}

Behavior *Mob::getBehavior() {
    return behavior_.get();
}
