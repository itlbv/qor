#pragma once

#include "../BTreeStatus.h"
#include "../../../Entity.h"
#include "../BTreeTask.h"

class IsTargetAlive : public BTreeTask {
public:
    BTreeStatus run(Entity &e) override {
        if (e.isAlive())
            return SUCCESS;
        else return FAILURE;
    };
};
