#ifndef QOR_BTREETASK_H
#define QOR_BTREETASK_H

#include "BTreeNode.h"
#include "../../Entity.h"

class BTreeTask : public BTreeNode {
public:
    BTreeTask();

    BTreeStatus run(Entity &e) override;
};

#endif //QOR_BTREETASK_H
