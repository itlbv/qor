#pragma once

#include "MoveTo.h"

class MoveToDestination : public MoveTo {
private:
    bool init;
public:
    MoveToDestination();

    BTreeStatus run(Entity &e) override;
};
