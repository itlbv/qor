#include "MoveCloseToTarget.h"

MoveCloseToTarget::MoveCloseToTarget() : MoveTo(0, 0, 1) {
    name_ = "move_close_to_target";
}

BTreeStatus MoveCloseToTarget::run(Mob &m) {
    destination_.set(*m.getTarget()->getPos());
    return MoveTo::run(m);
}
