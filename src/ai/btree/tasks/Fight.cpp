#include "Fight.h"
#include "../../../Logger.h"

const Uint32 Fight::AttackDelay = 2000;

Fight::Fight() : BTreeTask() {
    name_ = "fight";
}

BTreeStatus Fight::run(Mob &m) {
    Target *target = m.getTarget().lock().get();
    Mob *mob_target = (Mob *) target;
    if (mob_target->isDead()) return SUCCESS;

    if (!init_) {
        init_ = true;
        attack_time_ = SDL_GetTicks();
        Logger::log("hit target", m);
        mob_target->defend();
    }

    if (SDL_GetTicks() - attack_time_ < AttackDelay) {
        return RUNNING;
    } else {
        attack_time_ = SDL_GetTicks();
        Logger::log("hit target", m);
        mob_target->defend();
    }

    return RUNNING;
}
