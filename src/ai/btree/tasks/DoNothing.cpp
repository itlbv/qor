#include "DoNothing.h"

namespace btree {
    Status DoNothing::run(Entity &e) {
        return RUNNING;
    }
}