#ifndef QOR_FIGHT_H
#define QOR_FIGHT_H

#include "../BTreeTask.h"

class Fight : public BTreeTask {
private:
    static Uint32 callback(Uint32 interval, void *param);

public:
    BTreeStatus run(Entity &e) override;
};

#endif //QOR_FIGHT_H
