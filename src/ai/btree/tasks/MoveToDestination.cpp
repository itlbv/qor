#include "MoveToDestination.h"

MoveToDestination::MoveToDestination()
        : MoveTo(0, 0, 0.1),
          init(false) {
    name_ = "move_to_destination";
}

BTreeStatus MoveToDestination::run(Mob &m) {
    if (!init) {
        destination_.set(*m.getTarget().lock()->getPos());
        init = true;
    }
    return MoveTo::run(m);
}
