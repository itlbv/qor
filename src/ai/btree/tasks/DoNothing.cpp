#include "DoNothing.h"

namespace btree {
    BTreeStatus DoNothing::run(Entity &e) {
        return RUNNING;
    }
}