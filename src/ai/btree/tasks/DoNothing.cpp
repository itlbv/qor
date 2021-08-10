#include "DoNothing.h"

DoNothing::DoNothing() : BTreeTask() {
    name_ = "do_nothing";
}

BTreeStatus DoNothing::run(Mob &m) {
    return RUNNING;
}
