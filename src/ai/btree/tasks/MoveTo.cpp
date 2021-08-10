#include "MoveTo.h"
#include "../../../Qor.h"

const double MoveTo::Speed = 5;

MoveTo::MoveTo(double x_a, double y_a, const double close_enough_a)
        : CLOSE_ENOUGH(close_enough_a),
          destination_({x_a, y_a}),
          velocity_({0, 0}) {}

BTreeStatus MoveTo::run(Mob &e) {
    move(e);
    checkCollisions(e);

    if (destinationReached(e)) {
        return SUCCESS;
    } else return RUNNING;
}

void MoveTo::move(Mob &e) {
    velocity_ = e.getPos()->vectorTo(destination_);
    velocity_.normalize();
    velocity_.setLength(velocity_.length() * Qor::delta * Speed);
    e.getPos()->add(velocity_.x, velocity_.y);
}

void MoveTo::checkCollisions(Mob &moving_mob) {
    for (auto &m : Qor::mobs) {
        if (m.get() == &moving_mob)
            continue;

        double dist_to_mob = moving_mob.getPos()->distanceTo(*m->getPos());
        if (dist_to_mob < moving_mob.getRadius() * 2) {
            double penetration_dist = moving_mob.getRadius() * 2 - dist_to_mob;
            Vect collisionNormal = moving_mob.getPos()->vectorTo(*m->getPos());
            collisionNormal.setLength(-penetration_dist);
            moving_mob.getPos()->add(collisionNormal.x, collisionNormal.y);
        }
    }
}

bool MoveTo::destinationReached(Mob &m) const {
    return m.getPos()->distanceTo(destination_) <= CLOSE_ENOUGH;
}
