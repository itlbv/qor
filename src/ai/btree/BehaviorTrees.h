#pragma once

#include <map>
#include "Behavior.h"
#include "../../Entity.h"

class BehaviorTrees {
public:
    static std::unique_ptr<Behavior> getNewBehavior(const std::string &behavior_name_a);
};
