#include "BehaviorTrees.h"
#include "tasks/MoveTo.h"
#include "tasks/DoNothing.h"
#include "Sequence.h"

std::unique_ptr<Behavior> BehaviorTrees::getNewBehavior(const std::string &behavior_name) {
    if (behavior_name == "do_nothing")
        return std::move(std::make_unique<Behavior>(new DoNothing()));
    else if (behavior_name == "move_to")
        return std::move(std::make_unique<Behavior>(new MoveTo()));
    else if (behavior_name == "attack")
        return std::move(std::make_unique<Behavior>(new Sequence()));

    return std::move(std::make_unique<Behavior>(new DoNothing()));
}
