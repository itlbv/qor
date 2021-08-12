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
#include "tasks/FindFood.h"
#include "tasks/PickUpTarget.h"
#include "tasks/Eat.h"

std::unique_ptr<Behavior> BehaviorTrees::getNewBehavior(const std::string &behavior_name_a) {
    if (behavior_name_a == "do_nothing")
        return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
    else if (behavior_name_a == "move_to")
        return std::move(std::make_unique<Behavior>("move_to_destination", new MoveToDestination()));
    else if (behavior_name_a == "attack")
        return std::move(std::make_unique<Behavior>("attack",
                                                    new Sequence(
                                                            "attack_sequence", {
                                                                    new IsTargetAlive(),
                                                                    new Selector("fight_selector", {
                                                                            new IsTargetClose(),
                                                                            new MoveCloseToTarget()}),
                                                                    new Fight()}
                                                    )));
    else if (behavior_name_a == "eat")
        return std::move(std::make_unique<Behavior>("eat",
                                                    new Sequence(
                                                            "eat_sequence", {
                                                                    new FindFood(),
                                                                    new MoveCloseToTarget(),
                                                                    new PickUpTarget(),
                                                                    new Eat()}
                                                    )));

    return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
}
