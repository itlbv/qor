#ifndef QOR_ISTARGETALIVE_H
#define QOR_ISTARGETALIVE_H

#include "../Status.h"
#include "../../../Entity.h"
#include "../Task.h"

namespace btree {
    class IsTargetAlive : public Task {
    public:
        Status run(Entity &e) override {
            if (e.isAlive())
                return SUCCESS;
            else return FAILURE;
        };
    };
}

#endif //QOR_ISTARGETALIVE_H
