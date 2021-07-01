#include "Sequence.h"
#include "tasks/MoveTo.h"
#include "checks/IsTargetAlive.h"

namespace btree {
    Sequence::Sequence()
            : Node() {
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
        return RUNNING;
    }

    void Sequence::buildAttackSequence() {
        children_.push_back(std::make_unique<IsTargetAlive>());
        children_.push_back(std::make_unique<MoveTo>());
    }
}