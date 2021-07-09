#pragma once

#include "../../../Entity.h"
#include "../BTreeTask.h"

class MoveTo : public BTreeTask {
private:
    static const double DestinationReachedThreshold;
    static const double Speed;
    static Vect velocity_;

    static void move(Entity &e);

    static void checkCollisions(Entity &moving_entity);

    static bool destinationReached(Entity &e);

public:
    MoveTo();

    BTreeStatus run(Entity &e) override;
};
