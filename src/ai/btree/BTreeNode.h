#pragma once

#include "BTreeStatus.h"
#include "../../Entity.h"

class Entity;

class BTreeNode {
public:
    virtual BTreeStatus run(Entity &e) = 0;
};
