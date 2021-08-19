#include "Ai.h"

#include "btree/BehaviorTrees.h"
#include "../Logger.h"
#include "../Destination.h"

void Ai::update(Mob &m) {
//    if (m.getHunger() > 3) {
//        m.setBehavior(BehaviorTrees::getNewBehavior("eat"));
//    }
    if (m.getBehavior()->run(m) != RUNNING)
        m.setBehavior(Ai::getDefaultBehavior());
}

std::unique_ptr<Behavior> Ai::getDefaultBehavior() {
    return std::move(BehaviorTrees::getNewBehavior("build"));
}

void Ai::assignAttackBehaviorToMob(Mob &m, const std::shared_ptr<Mob> &target) {
    m.setTarget(target);
    m.setBehavior(BehaviorTrees::getNewBehavior("attack"));
}

void Ai::assignMoveToBehaviorToMob(Mob &m, double x_a, double y_a) {
    m.setTarget(std::make_shared<Destination>(x_a, y_a));
    m.setBehavior(BehaviorTrees::getNewBehavior("move_to"));
}
