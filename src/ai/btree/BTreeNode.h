#ifndef QOR_BTREENODE_H
#define QOR_BTREENODE_H

#include "BTreeStatus.h"
#include "../../Entity.h"

class BTreeNode {
public:
    virtual BTreeStatus run(Entity &e) = 0;
};

#endif //QOR_BTREENODE_H
