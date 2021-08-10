#pragma once

#include "BTreeStatus.h"
#include "../../Mob.h"

class Mob;

class BTreeNode {
protected:
    const char *name_;
public:
    virtual BTreeStatus run(Mob &m) = 0;

    const char *getName() { return name_; }
};
