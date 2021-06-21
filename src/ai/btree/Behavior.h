#ifndef QOR_BEHAVIOR_H
#define QOR_BEHAVIOR_H

#include "Node.h"

namespace btree {
    class Behavior {
    private:
        Node *_root;
    public:
        explicit Behavior(Node *a_root);

        Status run();
    };
}

#endif //QOR_BEHAVIOR_H
