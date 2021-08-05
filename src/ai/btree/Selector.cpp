#include "Selector.h"

Selector::Selector(const char *name_a, std::vector<BTreeNode *> children_a)
        : BTreeComposite(std::move(children_a)) {
    name_ = name_a;
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
