#include "Task.h"
#include "../../Qor.h"

namespace btree {
    Task::Task() = default;

    Status Task::run(Entity &e) {
        Qor::entities[0]->pos.x++;
        return RUNNING;
    }
}