#include "BehaviorTrees.h"
#include "tasks/MoveTo.h"
#include "tasks/DoNothing.h"
#include "Sequence.h"

std::map<std::string, std::shared_ptr<Behavior>> BehaviorTrees::behaviors;

void BehaviorTrees::initBehaviors() {
    behaviors.insert(std::make_pair("moveTo", std::make_shared<Behavior>(new MoveTo())));
    behaviors.insert(std::make_pair("doNothing", std::make_shared<Behavior>(new DoNothing())));
    behaviors.insert(std::make_pair("attack", std::make_shared<Behavior>(new Sequence())));
}