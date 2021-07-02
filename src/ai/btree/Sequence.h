#ifndef QOR_SEQUENCE_H
#define QOR_SEQUENCE_H

#include "Composite.h"

namespace btree {
    class Sequence : public Node {
    private:
        std::vector<std::unique_ptr<Node>> children_;

        void buildAttackSequence();

    public:
        Sequence();

        Status run(Entity &e) override;
    };
}

#endif //QOR_SEQUENCE_H
