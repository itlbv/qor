#pragma once

#include "../BTreeTask.h"
#include "../../../Mob.h"

class Fight : public BTreeTask {
private:
    static const Uint32 AttackDelay;
    bool init_ = false;
    Uint32 attack_time_ = 0;

    static void hitTarget(Mob &m);

public:
    Fight();

    BTreeStatus run(Mob &m) override;
};
