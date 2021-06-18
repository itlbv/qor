#include "BehaviorTrees.h"
#include "Task.h"
#include "tasks/MoveTo.h"

btree::Behavior btree::BehaviorTrees::moveTo = buildMoveTo();

btree::Behavior btree::BehaviorTrees::buildMoveTo() {
    btree::MoveTo moveToTask;
    return btree::Behavior(&moveToTask);
}
