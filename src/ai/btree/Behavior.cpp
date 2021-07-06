#include "Behavior.h"

namespace btree {
    Behavior::Behavior(BTreeNode *a_root)
            : _root(a_root) {}

    BTreeStatus Behavior::run(Entity &e) {
        return _root->run(e);
    }
}