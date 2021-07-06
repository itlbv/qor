#ifndef QOR_BTREENODE_H
#define QOR_BTREENODE_H

#include "Status.h"
#include "../../Entity.h"

namespace btree {
    class BTreeNode {
    public:
        virtual Status run(Entity &e) = 0;
    };
}

#endif //QOR_BTREENODE_H
