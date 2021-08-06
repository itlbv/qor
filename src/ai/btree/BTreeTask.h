#pragma once

#include "BTreeNode.h"
#include "../../Entity.h"

class BTreeTask : public BTreeNode {
public:
    BTreeStatus run(Entity &e) override = 0;
};
