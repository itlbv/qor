#pragma once

#include "../Mob.h"
#include "btree/Behavior.h"

class Ai {
private:
public:
    static void update(Mob &m);

    static std::unique_ptr<Behavior> getDefaultBehavior();

    static void assignAttackBehaviorToMob(Mob &m, const std::shared_ptr<Mob> &target);

    static void assignMoveToBehaviorToMob(Mob &m, double x, double y);
};
