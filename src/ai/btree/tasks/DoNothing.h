#ifndef QOR_DONOTHING_H
#define QOR_DONOTHING_H

#include "../../../Entity.h"
#include "../BTreeTask.h"

class DoNothing : public BTreeTask {
public:
    BTreeStatus run(Entity &e) override;
};

#endif //QOR_DONOTHING_H
