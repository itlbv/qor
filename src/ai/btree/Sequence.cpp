#include "Sequence.h"

namespace btree {
    Sequence::Sequence(std::vector<std::unique_ptr<Node>> children_a)
            : Composite(std::move(children_a)) {}

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
}