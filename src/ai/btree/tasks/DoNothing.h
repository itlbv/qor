#pragma once

#include "../../../Entity.h"
#include "../BTreeTask.h"

class DoNothing : public BTreeTask {
public:
    DoNothing();

    BTreeStatus run(Entity &e) override;
};
