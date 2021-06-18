#ifndef QOR_ROOT_H
#define QOR_ROOT_H

#include "Node.h"

namespace btree {
    class Root : public Node {
    private:
        Node *child;
    public:
        explicit Root(Node *child_a);

        Status run() override;
    };
}

#endif //QOR_ROOT_H
