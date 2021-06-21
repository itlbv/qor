#include "Behavior.h"

namespace btree {
    Behavior::Behavior(Node *a_root)
            : _root(a_root) {}

    Status Behavior::run() {
        return _root->run();
    }
}