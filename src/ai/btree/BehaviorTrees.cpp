#include "BehaviorTrees.h"
#include "tasks/MoveTo.h"
#include "tasks/DoNothing.h"
#include "Sequence.h"
#include "checks/IsTargetAlive.h"
#include "Selector.h"
#include "tasks/Fight.h"
#include "checks/IsTargetClose.h"
#include "tasks/MoveToDestination.h"
#include "tasks/MoveCloseToTarget.h"

std::unique_ptr<Behavior> BehaviorTrees::getNewBehavior(const std::string &behavior_name) {
    if (behavior_name == "do_nothing")
        return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
    else if (behavior_name == "move_to")
        return std::move(std::make_unique<Behavior>("move_to_destination", new MoveToDestination()));
    else if (behavior_name == "attack")
        return std::move(std::make_unique<Behavior>("attack",
                                                    new Sequence(
                                                            "attack_sequence",
                                                            {
                                                                    new IsTargetAlive(),
                                                                    new Selector("fight_selector",
                                                                                 {
                                                                                         new IsTargetClose(),
                                                                                         new MoveCloseToTarget()}),
                                                                    new Fight()}
                                                    )));

    return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
}
