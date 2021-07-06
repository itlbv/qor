#ifndef QOR_BEHAVIOR_H
#define QOR_BEHAVIOR_H

#include "BTreeNode.h"
#include "../../Entity.h"

namespace btree {
    class Behavior {
    private:
        BTreeNode *_root;
    public:
        explicit Behavior(BTreeNode *a_root);

        BTreeStatus run(Entity &e);
    };
}

#endif //QOR_BEHAVIOR_H
