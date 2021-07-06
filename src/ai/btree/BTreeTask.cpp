#include "BTreeTask.h"
#include "../../Qor.h"

BTreeTask::BTreeTask() = default;

BTreeStatus BTreeTask::run(Entity &e) {
    Qor::entities[0]->pos_->x++;
    return RUNNING;
}