#pragma once

#include <vector>
#include "Entity.h"
#include "ai/btree/Behavior.h"
#include "Item.h"

class Behavior;

class Mob : public Entity {
private:
    bool alive_;
    int health_;
    std::shared_ptr<Target> target_;
    std::unique_ptr<Behavior> behavior_;

    Uint32 hungerUpdateInterval_;
    Uint32 previousHungerUpdateTime_;
    double hunger_;

    std::vector<std::unique_ptr<Item>> inventory_;

    void updateHunger();

protected:
    std::unique_ptr<Vect> velocity_;
public:
    Mob(int id_a, double x_a, double y_a);

    void update();

    void defend();

    std::vector<std::unique_ptr<Item>> *getInventory();

    void setTarget(const std::shared_ptr<Target> &t);

    std::weak_ptr<Target> getTarget();

    void setBehavior(std::unique_ptr<Behavior> behavior);

    void setVelocity(Vect &velocity_a);

    Vect *getVelocity();

    double getHunger();

    [[nodiscard]] bool isDead() const;

    Behavior *getBehavior();
};

