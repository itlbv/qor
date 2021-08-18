#include "FindFood.h"
#include "../../../Qor.h"

FindFood::FindFood() {
    name_ = "find_food";
}

BTreeStatus FindFood::run(Mob &m) {
    for (auto &node : *Qor::map->getNodes()) {
        if (!node->isEmpty()) {
            auto items = *node->getItems();
            m.setTarget(items[0]);
            return SUCCESS;
        }
    }

    return FAILURE;
//    if (Qor::items.empty()) return FAILURE;
//    m.setTarget(Qor::items[0]);
//    return SUCCESS;
}
