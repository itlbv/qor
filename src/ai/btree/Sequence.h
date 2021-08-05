#pragma once

#include <vector>
#include "BTreeNode.h"
#include "BTreeComposite.h"

class Sequence : public BTreeComposite {
public:
    Sequence(const char *name_a, std::vector<BTreeNode *> children_a);

    BTreeStatus run(Entity &e) override;
};
