#include "Eat.h"
#include "../../../Logger.h"

Eat::Eat() : BTreeTask() {
    name_ = "eat";
}

BTreeStatus Eat::run(Mob &m) {
    if (!m.getInventory()->empty()) {
        Logger::log("eats!", m);
        m.reduceHunger(3);
    }
    return SUCCESS;
}
