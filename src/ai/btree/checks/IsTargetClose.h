#pragma once

#include "../BTreeTask.h"

#define CLOSE_DISTANCE 1.5

class IsTargetClose : public BTreeTask {
public:
    BTreeStatus run(Entity &e) override {
        if (e.pos_->distanceTo(*(e.getTarget())->pos_) < CLOSE_DISTANCE)
            return SUCCESS;
        else return FAILURE;
    };
};
