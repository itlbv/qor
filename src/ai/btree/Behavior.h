#ifndef QOR_BEHAVIOR_H
#define QOR_BEHAVIOR_H

#include "Node.h"

namespace btree {
    class Behavior {
    private:
        Node *root;
    public:
        Behavior(Node *root_a);

        Status run();
    };
}

#endif //QOR_BEHAVIOR_H
