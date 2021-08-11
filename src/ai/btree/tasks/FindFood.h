#pragma once

#include "../BTreeTask.h"

class FindFood : public BTreeTask {
public:
    FindFood();

    BTreeStatus run(Mob &m) override;
};

