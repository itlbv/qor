#include "MoveCloseToTarget.h"

MoveCloseToTarget::MoveCloseToTarget() : MoveTo(0, 0, 1) {
    name_ = "move_close_to_target";
}

BTreeStatus MoveCloseToTarget::run(Entity &e) {
    destination_.set(*e.getTarget()->pos_);
    return MoveTo::run(e);
}
