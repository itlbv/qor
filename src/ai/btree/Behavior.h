#pragma once

#include "BTreeNode.h"
#include "../../Mob.h"

class Mob;

class BTreeNode;

class Behavior {
private:
    const char *name_;
    BTreeNode *root_;
public:
    explicit Behavior(const char *name_a, BTreeNode *root_a);

    BTreeStatus run(Mob &m);

    const char *getName();
};
