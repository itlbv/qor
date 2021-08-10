#pragma once

#include "../../../Mob.h"
#include "../BTreeTask.h"

class MoveTo : public BTreeNode {
private:
    static const double Speed;
    const double CLOSE_ENOUGH;

    Vect velocity_;

    void move(Mob &m);

    void checkCollisions(Mob &moving_mob);

    bool destinationReached(Mob &m) const;

protected:
    Vect destination_;

    explicit MoveTo(double x_a, double y_a, double close_enough_a);

    BTreeStatus run(Mob &m) override;
};
