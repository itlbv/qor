#ifndef QOR_FIGHT_H
#define QOR_FIGHT_H

#include "../Task.h"

namespace btree {
    class Fight : public Task {
    public:
        Status run(Entity &e) override;
    };
}

#endif //QOR_FIGHT_H
