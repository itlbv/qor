#include <algorithm>
#include "PickUpTarget.h"
#include "../../../Qor.h"
#include "../../../Logger.h"

PickUpTarget::PickUpTarget() : BTreeNode() {
    name_ = "pick_up_target";
}

BTreeStatus PickUpTarget::run(Mob &m) {
    std::shared_ptr<Item> target_item = std::static_pointer_cast<Item>(m.getTarget().lock());
    m.getInventory()->push_back(target_item);
    Logger::log("picks up food", m);

    // remove item from MapNode
    auto node_items = Qor::map->getNodeFromCoord((int) target_item->getPos()->x,
                                                 (int) target_item->getPos()->y)->getItems();
    auto it = std::find(node_items->begin(), node_items->end(), target_item);
    if (it != node_items->end()) {
        using std::swap;
        swap(*it, node_items->back());
        node_items->pop_back();
    }

    return SUCCESS;
}

