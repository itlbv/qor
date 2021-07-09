#pragma once

#include "BTreeStatus.h"
#include "../../Entity.h"

class Entity;

class BTreeNode {
protected:
    const char *name_;
public:
    virtual BTreeStatus run(Entity &e) = 0;

    const char *getName() { return name_; }
};
