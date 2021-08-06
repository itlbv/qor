#include "Fight.h"
#include "../../../Logger.h"

const Uint32 Fight::AttackDelay = 2000;

Fight::Fight() : BTreeTask() {
    name_ = "fight";
}

BTreeStatus Fight::run(Entity &e) {
    if (!init_) {
        init_ = true;
        attack_time_ = SDL_GetTicks();
        hitTarget(e);
    }

    if (e.getTarget()->isDead()) return SUCCESS;

    if (SDL_GetTicks() - attack_time_ < AttackDelay) {
        return RUNNING;
    } else {
        attack_time_ = SDL_GetTicks();
        hitTarget(e);
    }

    return RUNNING;
}

void Fight::hitTarget(Entity &e) {
    Logger::log("hit target", e);
    e.getTarget()->defend();
}
