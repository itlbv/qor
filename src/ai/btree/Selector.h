#ifndef QOR_SELECTOR_H
#define QOR_SELECTOR_H


#include <memory>
#include <vector>
#include "../../Entity.h"
#include "BTreeNode.h"

class Selector : public BTreeNode {
private:
    std::vector<std::unique_ptr<BTreeNode>> children_;

    void buildGoToTargetSelector();

public:
    Selector();

    BTreeStatus run(Entity &e) override;
};

#endif //QOR_SELECTOR_H
