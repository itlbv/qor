#pragma once

#include "Entity.h"
#include "ai/btree/Behavior.h"

class Behavior;

class Mob : public Entity {
private:
    bool alive_;
    int health_;
    std::unique_ptr<Vect> dest_;
    std::shared_ptr<Mob> target_;
    std::unique_ptr<Behavior> behavior_;

    Uint32 hungerUpdateInterval_;
    Uint32 previousHungerUpdateTime_;
    double hunger_;

    void updateHunger();

protected:
    std::unique_ptr<Vect> velocity_;
public:
    Mob(int id_a, double x_a, double y_a);

    void update();

    void defend();

    void setBehavior(std::unique_ptr<Behavior> behavior);

    void setDest(double a_x, double a_y);

    Vect *getDest();

    void setTarget(std::shared_ptr<Mob> m);

    Mob *getTarget();

    void setVelocity(Vect &velocity_a);

    Vect *getVelocity();

    double getHunger();

    [[nodiscard]] bool isDead() const;

    Behavior *getBehavior();
};

