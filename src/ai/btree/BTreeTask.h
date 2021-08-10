#pragma once

#include "BTreeNode.h"
#include "../../Mob.h"

class BTreeTask : public BTreeNode {
public:
    BTreeStatus run(Mob &m) override = 0;
};
