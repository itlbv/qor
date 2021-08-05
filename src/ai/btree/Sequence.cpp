#include "Sequence.h"

#include "Selector.h"

Sequence::Sequence(const char *name_a, std::vector<BTreeNode *> children_a)
        : BTreeComposite(std::move(children_a)) {
    name_ = name_a;
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
