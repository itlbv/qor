#include <algorithm>
#include "PickUpTarget.h"
#include "../../../Qor.h"

PickUpTarget::PickUpTarget() : BTreeNode() {
    name_ = "pick_up_target";
}

BTreeStatus PickUpTarget::run(Mob &m) {
    std::shared_ptr<Item> target_item = std::static_pointer_cast<Item>(m.getTarget().lock());
    m.getInventory()->push_back(target_item);

    auto it = std::find(Qor::items.begin(), Qor::items.end(), target_item);

    if (it != Qor::items.end()) {
        using std::swap;
        swap(*it, Qor::items.back());
        Qor::items.pop_back();
    }

    return SUCCESS;
}
