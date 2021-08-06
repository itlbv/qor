#pragma once

#include "../../../Entity.h"
#include "../BTreeTask.h"

class MoveTo : public BTreeNode {
private:
    static const double Speed;
    const double CLOSE_ENOUGH;

    Vect velocity_;

    void move(Entity &e);

    void checkCollisions(Entity &moving_entity);

    bool destinationReached(Entity &e) const;

protected:
    Vect destination_;

    explicit MoveTo(double x_a, double y_a, double close_enough_a);

    BTreeStatus run(Entity &e) override;
};
