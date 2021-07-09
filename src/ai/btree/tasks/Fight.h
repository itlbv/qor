#pragma once

#include "../BTreeTask.h"

class Fight : public BTreeTask {
private:
    static const Uint32 AttackDelay;
    bool init_ = false;
    Uint32 attack_time_ = 0;

    static void hitTarget(Entity &e);

public:
    BTreeStatus run(Entity &e) override;
};
