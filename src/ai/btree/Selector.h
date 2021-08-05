#pragma once

#include <memory>
#include <vector>
#include "../../Entity.h"
#include "BTreeNode.h"
#include "BTreeComposite.h"

class Selector : public BTreeComposite {
public:
    Selector(const char *name_a, std::vector<BTreeNode *> children_a);

    BTreeStatus run(Entity &e) override;
};
