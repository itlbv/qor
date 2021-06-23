#include "Ai.h"
#include "../Qor.h"
#include "btree/BehaviorTrees.h"

namespace ai {
    std::map<std::shared_ptr<Entity>, std::shared_ptr<btree::Behavior>> Ai::entitiesBehaviors;

    void ai::Ai::run() {
        assignDefaultBehaviorToNewEntities();

        for (auto &eb : entitiesBehaviors) {
            eb.second->run(*eb.first);
        }
    }

    void Ai::assignDefaultBehaviorToNewEntities() {
        for (auto &e : Qor::entities) {
            auto it = entitiesBehaviors.find(e);
            if (it == entitiesBehaviors.end())
                entitiesBehaviors.insert(std::make_pair(e, btree::BehaviorTrees::behaviors["doNothing"]));
        }
    }

    void Ai::assignBehaviorToEntity(Entity *a_e, const char *behavior) {
        for (auto &eb : entitiesBehaviors) {
            if (eb.first.get() == a_e)
                eb.second = btree::BehaviorTrees::behaviors["moveTo"];
        }
    }
}