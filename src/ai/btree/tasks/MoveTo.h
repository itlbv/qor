#ifndef QOR_MOVETO_H
#define QOR_MOVETO_H

#include "../../../Entity.h"
#include "../Task.h"

namespace btree {
    class MoveTo : public Task {
    public:
        Status run(Entity &e) override;
    };
}

#endif //QOR_MOVETO_H
