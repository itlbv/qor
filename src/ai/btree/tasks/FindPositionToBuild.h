#pragma once

#include "../BTreeTask.h"

class FindPositionToBuild : BTreeTask {
public:
    FindPositionToBuild();

    BTreeStatus run(Mob &m) override;
};

