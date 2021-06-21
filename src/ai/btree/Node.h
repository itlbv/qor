#ifndef QOR_NODE_H
#define QOR_NODE_H

#include "Status.h"
#include "../../Entity.h"

namespace btree {
    class Node {
    public:
        virtual Status run(Entity &e) = 0;
    };
}

#endif //QOR_NODE_H
