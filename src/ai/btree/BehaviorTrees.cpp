#include "BehaviorTrees.h"
#include "tasks/MoveTo.h"
#include "tasks/DoNothing.h"
#include "Sequence.h"

std::unique_ptr<Behavior> BehaviorTrees::getNewBehavior(const std::string &behavior_name) {
    if (behavior_name == "do_nothing")
        return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
    else if (behavior_name == "move_to")
        return std::move(std::make_unique<Behavior>("move_to", new MoveTo()));
    else if (behavior_name == "attack")
        return std::move(std::make_unique<Behavior>("attack", new Sequence("attack_sequence")));

    return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
}
