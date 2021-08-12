#pragma once

#include "../BTreeNode.h"

class PickUpTarget : public BTreeNode {
public:
    PickUpTarget();

    BTreeStatus run(Mob &m) override;
};

