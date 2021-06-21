#include "BehaviorTrees.h"
#include "tasks/MoveTo.h"

namespace btree {
    Behavior BehaviorTrees::_moveTo = buildMoveTo();

    Behavior BehaviorTrees::buildMoveTo() {
        MoveTo moveToTask;
        return Behavior(&moveToTask);
    }
}