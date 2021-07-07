#include "Behavior.h"

Behavior::Behavior(BTreeNode *root_a)
        : root_(root_a) {}

BTreeStatus Behavior::run(Entity &e) {
    return root_->run(e);
}