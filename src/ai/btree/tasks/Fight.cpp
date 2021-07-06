#include "Fight.h"

namespace btree {
    Status Fight::run(Entity &e) {
        SDL_TimerID attackTimer = SDL_AddTimer(1 * 1000, callback, &e);
        return RUNNING;
    }

    Uint32 Fight::callback(Uint32 interval, void *param) {
        auto e = (Entity *) param;
        e->getTarget()->defend();
        return 0;
    }
}
