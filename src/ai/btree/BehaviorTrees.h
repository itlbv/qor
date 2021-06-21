#ifndef QOR_BEHAVIORTREES_H
#define QOR_BEHAVIORTREES_H

#include <map>
#include "Behavior.h"
#include "../../Entity.h"

namespace btree {
    class BehaviorTrees {
    public:
        static std::map<std::string, std::unique_ptr<Behavior>> behaviors;

        static void initBehaviors();
    };
}

#endif //QOR_BEHAVIORTREES_H
