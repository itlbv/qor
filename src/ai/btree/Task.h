#ifndef QOR_TASK_H
#define QOR_TASK_H

#include "Node.h"

namespace btree {
    class Task : public Node {
    public:
        Task();

        Status run() override;
    };
}

#endif //QOR_TASK_H
