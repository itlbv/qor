#pragma once

#include "BTreeNode.h"
#include "../../Entity.h"

class BTreeTask : public BTreeNode {
public:
    BTreeTask();

    BTreeStatus run(Entity &e) override;
};
