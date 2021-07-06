#ifndef QOR_ISTARGETALIVE_H
#define QOR_ISTARGETALIVE_H

#include "../BTreeStatus.h"
#include "../../../Entity.h"
#include "../BTreeTask.h"

namespace btree {
    class IsTargetAlive : public BTreeTask {
    public:
        BTreeStatus run(Entity &e) override {
            if (e.isAlive())
                return SUCCESS;
            else return FAILURE;
        };
    };
}

#endif //QOR_ISTARGETALIVE_H
