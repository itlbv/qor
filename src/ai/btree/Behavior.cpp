#include "Behavior.h"

btree::Behavior::Behavior(btree::Node *root_a)
        : root(root_a) {}

btree::Status btree::Behavior::run() {
    return root->run();
}
