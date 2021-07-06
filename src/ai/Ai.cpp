#include "Ai.h"
#include "../Qor.h"
#include "btree/BehaviorTrees.h"

namespace ai {
    std::map<std::shared_ptr<Entity>, std::shared_ptr<Behavior>> Ai::entitiesBehaviors;

    void ai::Ai::run() {
        assignDefaultBehaviorToNewEntities();

        for (auto &eb : entitiesBehaviors) {
            runBehavior(eb);
        }
    }

    void Ai::runBehavior(const std::pair<std::shared_ptr<Entity> const, std::shared_ptr<Behavior>> &eb) {
        if (eb.second->run(*eb.first) != RUNNING)
            assignBehaviorToEntity(eb.first.get(), "doNothing");
    }

    void Ai::assignDefaultBehaviorToNewEntities() {
        for (auto &e : Qor::entities) {
            auto it = entitiesBehaviors.find(e);
            if (it == entitiesBehaviors.end())
                entitiesBehaviors.insert(std::make_pair(e, BehaviorTrees::behaviors["doNothing"]));
        }
    }

    void Ai::assignBehaviorToEntity(Entity *a_e, const char *behavior) {
        for (auto &eb : entitiesBehaviors) {
            if (eb.first.get() == a_e)
                eb.second = BehaviorTrees::behaviors[behavior];
        }
    }
}