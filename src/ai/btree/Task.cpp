#include "Task.h"
#include "../../Qor.h"

btree::Task::Task() = default;

btree::Status btree::Task::run() {
    Qor::entities[0].pos.x++;
    return btree::RUNNING;
}
