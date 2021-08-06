#include "MoveToDestination.h"

MoveToDestination::MoveToDestination()
        : MoveTo(0, 0, 0.1),
          init(false) {
    name_ = "move_to_destination";
}

BTreeStatus MoveToDestination::run(Entity &e) {
    if (!init) {
        destination_.set(*e.getDest());
        init = true;
    }
    return MoveTo::run(e);
}
