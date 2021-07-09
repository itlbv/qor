#include "Sequence.h"
#include "tasks/MoveTo.h"
#include "checks/IsTargetAlive.h"
#include "Selector.h"
#include "tasks/Fight.h"

Sequence::Sequence(const char *name_a)
        : BTreeNode() {
    name_ = name_a;
    buildAttackSequence();
}

BTreeStatus Sequence::run(Entity &e) {
    for (auto &child : children_) {
        BTreeStatus status = child->run(e);

        if (status == RUNNING)
            return RUNNING;
        else if (status == SUCCESS)
            continue;
        else return FAILURE;
    }
    return SUCCESS;
}

void Sequence::buildAttackSequence() {
    children_.push_back(std::make_unique<IsTargetAlive>());
    children_.push_back(std::make_unique<Selector>("fight_selector"));
    children_.push_back(std::make_unique<Fight>());
}