#include "DoNothing.h"

DoNothing::DoNothing() : BTreeTask() {
    name_ = "do_nothing";
}

BTreeStatus DoNothing::run(Entity &e) {
    return RUNNING;
}
