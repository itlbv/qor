#ifndef QOR_TASK_H
#define QOR_TASK_H

#include "Node.h"
#include "../../Entity.h"

namespace btree {
    class Task : public Node {
    public:
        Task();

        Status run(Entity &e) override;
    };
}

#endif //QOR_TASK_H
