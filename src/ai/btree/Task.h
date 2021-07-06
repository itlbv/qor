#ifndef QOR_TASK_H
#define QOR_TASK_H

#include "BTreeNode.h"
#include "../../Entity.h"

namespace btree {
    class Task : public BTreeNode {
    public:
        Task();

        Status run(Entity &e) override;
    };
}

#endif //QOR_TASK_H
