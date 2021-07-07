#pragma once

#include <map>
#include "../Entity.h"
#include "btree/Behavior.h"

class Ai {
private:
public:
    static std::map<std::shared_ptr<Entity>, std::shared_ptr<Behavior>> entitiesBehaviors;

    static std::unique_ptr<Behavior> getDefaultBehavior();

    static void assignAttackBehaviorToEntity(Entity &e, const std::shared_ptr<Entity> &target);

    static void assignMoveToBehaviorToEntity(Entity &e, double x, double y);
};
