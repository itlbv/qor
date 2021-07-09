#pragma once

#include "BTreeNode.h"
#include "../../Entity.h"

class Entity;

class BTreeNode;

class Behavior {
private:
    const char *name_;
    BTreeNode *root_;
public:
    explicit Behavior(const char *name_a, BTreeNode *root_a);

    BTreeStatus run(Entity &e);

    const char *getName();
};
