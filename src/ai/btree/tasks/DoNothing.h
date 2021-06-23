#ifndef QOR_DONOTHING_H
#define QOR_DONOTHING_H

#include "../../../Entity.h"
#include "../Task.h"

namespace btree {
    class DoNothing : public Task {
    public:
        Status run(Entity &e) override;
    };
}

#endif //QOR_DONOTHING_H
