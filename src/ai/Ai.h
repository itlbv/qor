#ifndef QOR_AI_H
#define QOR_AI_H

#include <map>
#include "../Entity.h"
#include "btree/Behavior.h"

namespace ai {
    class Ai {
    private:
    public:
        static std::map<std::shared_ptr<Entity>, std::shared_ptr<btree::Behavior>> entitiesBehaviors;

        static void run();
    };
}

#endif //QOR_AI_H
