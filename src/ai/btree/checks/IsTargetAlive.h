#pragma once

#include "../BTreeStatus.h"
#include "../BTreeTask.h"
#include "../../../Mob.h"

class IsTargetAlive : public BTreeTask {
public:
    BTreeStatus run(Mob &m) override {
        if (!m.isDead())
            return SUCCESS;
        else return FAILURE;
    };
};
