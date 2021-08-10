#pragma once

#include "MoveTo.h"

class MoveCloseToTarget : public MoveTo {
public:
    MoveCloseToTarget();

    BTreeStatus run(Mob &m) override;
};

