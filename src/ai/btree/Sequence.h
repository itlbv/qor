#ifndef QOR_SEQUENCE_H
#define QOR_SEQUENCE_H

#include <vector>
#include "BTreeNode.h"

class Sequence : public BTreeNode {
private:
    std::vector<std::unique_ptr<BTreeNode>> children_;

    void buildAttackSequence();

public:
    Sequence();

    BTreeStatus run(Entity &e) override;
};

#endif //QOR_SEQUENCE_H
