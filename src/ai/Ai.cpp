#include "Ai.h"

#include "btree/BehaviorTrees.h"

std::unique_ptr<Behavior> Ai::getDefaultBehavior() {
    return std::move(BehaviorTrees::getNewBehavior("do_nothing"));
}

void Ai::assignAttackBehaviorToEntity(Entity &e, const std::shared_ptr<Entity> &target) {
    e.setTarget(target);
    e.setDest(target->pos_->x, target->pos_->y);
    e.setBehavior(BehaviorTrees::getNewBehavior("attack"));
}

void Ai::assignMoveToBehaviorToEntity(Entity &e, double x, double y) {
    e.setDest(x, y);
    e.setBehavior(BehaviorTrees::getNewBehavior("move_to"));
}
