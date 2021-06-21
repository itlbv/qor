#include "MoveTo.h"

btree::Status btree::MoveTo::run(Entity &e) {
    e.pos.y++;
    return RUNNING;
}
