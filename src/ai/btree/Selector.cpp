#include "Selector.h"
#include "checks/IsTargetClose.h"
#include "tasks/MoveTo.h"

Selector::Selector() : BTreeNode() {
    buildGoToTargetSelector();
}

BTreeStatus Selector::run(Entity &e) {
    for (auto &child : children_) {
        BTreeStatus status = child->run(e);

        if (status == RUNNING)
            return RUNNING;
        else if (status == FAILURE)
            continue;
        else return SUCCESS;
    }
    return FAILURE;
}

void Selector::buildGoToTargetSelector() {
    children_.push_back(std::make_unique<IsTargetClose>());
    children_.push_back(std::make_unique<MoveTo>());
}