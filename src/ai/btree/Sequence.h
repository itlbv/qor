#ifndef QOR_SEQUENCE_H
#define QOR_SEQUENCE_H

#include "Composite.h"

namespace btree {
    class Sequence : public Composite {
    public:
        Sequence(std::vector<std::unique_ptr<Node>> children_a);

        Status run(Entity &e) override;
    };
}

#endif //QOR_SEQUENCE_H
