#ifndef QOR_COMPOSITE_H
#define QOR_COMPOSITE_H

#include <vector>
#include <memory>
#include "BTreeNode.h"

namespace btree {
    class Composite : public BTreeNode {
    protected:
        std::vector<std::unique_ptr<BTreeNode>> children_;

        explicit Composite(std::vector<std::unique_ptr<BTreeNode>> children_a);

    public:
        Status run(Entity &e) override = 0;
    };
}

#endif //QOR_COMPOSITE_H
