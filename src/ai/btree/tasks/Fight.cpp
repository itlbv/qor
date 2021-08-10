#include "Fight.h"
#include "../../../Logger.h"

const Uint32 Fight::AttackDelay = 2000;

Fight::Fight() : BTreeTask() {
    name_ = "fight";
}

BTreeStatus Fight::run(Mob &m) {
    if (!init_) {
        init_ = true;
        attack_time_ = SDL_GetTicks();
        hitTarget(m);
    }

    if (m.getTarget()->isDead()) return SUCCESS;

    if (SDL_GetTicks() - attack_time_ < AttackDelay) {
        return RUNNING;
    } else {
        attack_time_ = SDL_GetTicks();
        hitTarget(m);
    }

    return RUNNING;
}

void Fight::hitTarget(Mob &m) {
    Logger::log("hit target", m);
    m.getTarget()->defend();
}
