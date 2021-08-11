#include "FindFood.h"
#include "../../../Resource.h"
#include "../../../Qor.h"

FindFood::FindFood() {
    name_ = "find_food";
}

BTreeStatus FindFood::run(Mob &m) {
    if (Qor::resources.empty()) return FAILURE;
    return SUCCESS;
}
