#include "FindFood.h"
#include "../../../Item.h"
#include "../../../Qor.h"

FindFood::FindFood() {
    name_ = "find_food";
}

BTreeStatus FindFood::run(Mob &m) {
    if (Qor::items.empty()) return FAILURE;
    m.setTarget(Qor::items[0]);
    return SUCCESS;
}
