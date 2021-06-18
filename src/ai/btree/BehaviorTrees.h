#ifndef QOR_BEHAVIORTREES_H
#define QOR_BEHAVIORTREES_H

#include "Behavior.h"

namespace btree {
    class BehaviorTrees {
    public:
        static Behavior moveTo;

        static Behavior buildMoveTo();
    };
}

#endif //QOR_BEHAVIORTREES_H
