#pragma once

#include <vector>
#include <memory>
#include "BTreeNode.h"

class BTreeComposite : public BTreeNode {
protected:
    std::vector<std::unique_ptr<BTreeNode>> children_;

    explicit BTreeComposite(std::vector<BTreeNode *> children_a);

    BTreeStatus run(Mob &m) override = 0;
};
