#include "BehaviorTrees.h"
#include "tasks/MoveTo.h"

namespace btree {
    std::map<std::string, std::unique_ptr<Behavior>> BehaviorTrees::behaviors;

    void BehaviorTrees::initBehaviors() {
        MoveTo moveTo;
        behaviors.insert(std::make_pair("moveTo", std::make_unique<Behavior>(&moveTo)));
    }
}