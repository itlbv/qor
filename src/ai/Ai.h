#pragma once

#include <map>
#include "../Entity.h"
#include "btree/Behavior.h"

namespace ai {
    class Ai {
    private:
    public:
        static std::map<std::shared_ptr<Entity>, std::shared_ptr<Behavior>> entitiesBehaviors;

        static void run();

        static void runBehavior(const std::pair<std::shared_ptr<Entity> const, std::shared_ptr<Behavior>> &eb);

        static void assignDefaultBehaviorToNewEntities();

        static void assignBehaviorToEntity(Entity *entity, const char *behavior);
    };
}
