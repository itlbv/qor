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
#include "tasks/FindPositionToBuild.h"
#include "tasks/Build.h"

std::unique_ptr<Behavior> BehaviorTrees::getNewBehavior(const char *behavior_name_a) {
    if (std::strcmp(behavior_name_a, "do_nothing") == 0)
        return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
    else if (std::strcmp(behavior_name_a, "move_to") == 0)
        return std::move(std::make_unique<Behavior>("move_to_destination", new MoveToDestination()));
    else if (std::strcmp(behavior_name_a, "attack") == 0)
        return std::move(std::make_unique<Behavior>("attack",
                                                    new Sequence(
                                                            "attack_sequence", {
                                                                    new IsTargetAlive(),
                                                                    new Selector("fight_selector", {
                                                                            new IsTargetClose(),
                                                                            new MoveCloseToTarget()}),
                                                                    new Fight()}
                                                    )));
    else if (std::strcmp(behavior_name_a, "eat") == 0)
        return std::move(std::make_unique<Behavior>("eat",
                                                    new Sequence(
                                                            "eat_sequence", {
                                                                    new FindFood(),
                                                                    new MoveCloseToTarget(),
                                                                    new PickUpTarget(),
                                                                    new Eat()}
                                                    )));
    else if (std::strcmp(behavior_name_a, "build") == 0)
        return std::move(std::make_unique<Behavior>("build",
                                                    new Sequence(
                                                            "build_sequence", {
                                                                    //find resources
                                                                    new FindPositionToBuild(IBuilding::HOUSE),
                                                                    new MoveToDestination(),
                                                                    new Build(IBuilding::HOUSE)
                                                            }
                                                    )));

    return std::move(std::make_unique<Behavior>("do_nothing", new DoNothing()));
}
