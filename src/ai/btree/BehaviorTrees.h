#pragma once

#include <map>
#include "Behavior.h"
#include "../../Entity.h"

class BehaviorTrees {
public:
    static std::map<std::string, std::shared_ptr<Behavior>> behaviors;

    static void initBehaviors();
};
