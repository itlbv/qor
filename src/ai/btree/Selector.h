#pragma once

#include <memory>
#include <vector>
#include "BTreeComposite.h"

class Selector : public BTreeComposite {
public:
    Selector(const char *name_a, std::vector<BTreeNode *> children_a);

    BTreeStatus run(Mob &m) override;
};
