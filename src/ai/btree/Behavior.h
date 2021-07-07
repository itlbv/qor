#pragma once

#include "BTreeNode.h"
#include "../../Entity.h"

class Entity;

class BTreeNode;

class Behavior {
private:
    BTreeNode *root_;
public:
    explicit Behavior(BTreeNode *root_a);

    BTreeStatus run(Entity &e);
};
