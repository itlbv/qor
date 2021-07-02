#ifndef QOR_ISTARGETCLOSE_H
#define QOR_ISTARGETCLOSE_H

#include "../Task.h"

namespace btree {
    class IsTargetClose : public Task {
    public:
        Status run(Entity &e) override {
            if (e.pos_->distanceTo(*(e.getTarget())->pos_) < 1)
                return SUCCESS;
            else return FAILURE;
        };
    };
}

#endif //QOR_ISTARGETCLOSE_H
