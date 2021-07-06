#include "Sequence.h"
#include "tasks/MoveTo.h"
#include "checks/IsTargetAlive.h"
#include "Selector.h"
#include "tasks/Fight.h"

namespace btree {
    Sequence::Sequence()
            : BTreeNode() {
        buildAttackSequence();
    }

    Status Sequence::run(Entity &e) {
        for (auto &child : children_) {
            Status status = child->run(e);

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
        children_.push_back(std::make_unique<Selector>());
        children_.push_back(std::make_unique<Fight>());
    }
}