#include "Selector.h"
#include "checks/IsTargetClose.h"
#include "tasks/MoveTo.h"

namespace btree {
    Selector::Selector() : BTreeNode() {
        buildGoToTargetSelector();
    }

    Status Selector::run(Entity &e) {
        for (auto &child : children_) {
            Status status = child->run(e);

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
}