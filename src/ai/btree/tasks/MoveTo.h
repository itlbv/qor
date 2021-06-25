#ifndef QOR_MOVETO_H
#define QOR_MOVETO_H

#include "../../../Entity.h"
#include "../Task.h"

namespace btree {
    class MoveTo : public Task {
    private:
        static const double DestinationReachedThreshold;
        static const double Speed;
        static Vect velocity_;

        static void move(Entity &e);

        static void checkCollisions(Entity &moving_entity);

        static bool destinationReached(Entity &e);

    public:
        Status run(Entity &e) override;
    };
}

#endif //QOR_MOVETO_H
