#ifndef QOR_COMPOSITE_H
#define QOR_COMPOSITE_H

#include <vector>
#include <memory>
#include "Node.h"

namespace btree {
    class Composite : public Node {
    protected:
        std::vector<std::unique_ptr<Node>> children_;

        explicit Composite(std::vector<std::unique_ptr<Node>> children_a);

    public:
        Status run(Entity &e) override = 0;
    };
}

#endif //QOR_COMPOSITE_H
