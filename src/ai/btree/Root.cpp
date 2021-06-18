#include "Root.h"

btree::Root::Root(btree::Node *child_a)
        : child(child_a) {}

btree::Status btree::Root::run() {
    return child->run();
}
