#pragma once

#include "BTreeNode.h"
#include "../../Entity.h"

class Behavior {
private:
    BTreeNode *_root;
public:
    explicit Behavior(BTreeNode *a_root);

    BTreeStatus run(Entity &e);
};
