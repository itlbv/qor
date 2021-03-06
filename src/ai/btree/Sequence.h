#pragma once

#include <vector>
#include "BTreeComposite.h"

class Sequence : public BTreeComposite {
public:
    Sequence(const char *name_a, std::vector<BTreeNode *> children_a);

    BTreeStatus run(Mob &m) override;
};
