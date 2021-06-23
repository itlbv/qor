#include "MoveTo.h"

btree::Status btree::MoveTo::run(Entity &e) {
    e._pos.y++;
    return RUNNING;
}
