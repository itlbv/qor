#pragma once

#include "../BTreeTask.h"

#define CLOSE_DISTANCE 1.5

class IsTargetClose : public BTreeTask {
public:
    BTreeStatus run(Mob &m) override {
        if (m.getPos()->distanceTo(*(m.getTarget().lock())->getPos()) < CLOSE_DISTANCE)
            return SUCCESS;
        else return FAILURE;
    };
};
