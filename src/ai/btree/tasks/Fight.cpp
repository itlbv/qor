#include "Fight.h"

namespace btree {
    Status Fight::run(Entity &e) {
        e.getTarget()->defend();
        return RUNNING;
    }
}
