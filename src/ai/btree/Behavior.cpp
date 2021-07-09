#include "Behavior.h"

Behavior::Behavior(const char *name_a, BTreeNode *root_a)
        : name_(name_a),
          root_(root_a) {}

BTreeStatus Behavior::run(Entity &e) {
    return root_->run(e);
}

const char *Behavior::getName() {
    return name_;
}
