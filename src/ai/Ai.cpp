#include "Ai.h"

#include "btree/BehaviorTrees.h"

std::unique_ptr<Behavior> Ai::getDefaultBehavior() {
    return std::move(BehaviorTrees::getNewBehavior("do_nothing"));
}

void Ai::assignAttackBehaviorToMob(Mob &m, const std::shared_ptr<Mob> &target) {
    m.setTarget(target);
    m.setDest(target->getPos()->x, target->getPos()->y);
    m.setBehavior(BehaviorTrees::getNewBehavior("attack"));
}

void Ai::assignMoveToBehaviorToMob(Mob &m, double x, double y) {
    m.setDest(x, y);
    m.setBehavior(BehaviorTrees::getNewBehavior("move_to"));
}
