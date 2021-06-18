#ifndef QOR_NODE_H
#define QOR_NODE_H

#include "BehaviorTree.h"

namespace btree {
    class Node {
    public:
        virtual Status run() = 0;
    };
}

#endif //QOR_NODE_H