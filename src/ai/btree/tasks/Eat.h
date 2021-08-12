#pragma once

#include "../BTreeTask.h"

class Eat : public BTreeTask {
public:
    Eat();

    BTreeStatus run(Mob &m) override;
};

