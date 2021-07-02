#ifndef QOR_SELECTOR_H
#define QOR_SELECTOR_H


#include <memory>
#include <vector>
#include "../../Entity.h"
#include "Node.h"

namespace btree {
    class Selector : public Node {
    private:
        std::vector<std::unique_ptr<Node>> children_;

        void buildGoToTargetSelector();

    public:
        Selector();

        Status run(Entity &e) override;
    };
}

#endif //QOR_SELECTOR_H
