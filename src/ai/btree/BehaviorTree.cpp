#include "BehaviorTree.h"
#include "Task.h"
#include "Root.h"

void btree::build() {
    Task task;
    Root root(&task);
    root.run();
}