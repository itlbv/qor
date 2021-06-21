#include "MoveTo.h"
#include "../../../Qor.h"

btree::Status btree::MoveTo::run() {
    Qor::entities[0]->pos.y++;
    return RUNNING;
}
