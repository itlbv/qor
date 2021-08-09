#include "MoveTo.h"
#include "../../../Qor.h"

const double MoveTo::Speed = 5;

MoveTo::MoveTo(double x_a, double y_a, const double close_enough_a)
        : CLOSE_ENOUGH(close_enough_a),
          destination_({x_a, y_a}),
          velocity_({0, 0}) {}

BTreeStatus MoveTo::run(Entity &e) {
    move(e);
    checkCollisions(e);

    if (destinationReached(e)) {
        return SUCCESS;
    } else return RUNNING;
}

void MoveTo::move(Entity &e) {
    velocity_ = e.getPos()->vectorTo(destination_);
    velocity_.normalize();
    velocity_.setLength(velocity_.length() * Qor::delta * Speed);
    e.getPos()->add(velocity_.x, velocity_.y);
}

void MoveTo::checkCollisions(Entity &moving_entity) {
    for (auto &e : Qor::entities) {
        if (e.get() == &moving_entity)
            continue;

        double dist_to_entity = moving_entity.getPos()->distanceTo(*e->getPos());
        if (dist_to_entity < moving_entity.getRadius() * 2) {
            double penetration_dist = moving_entity.getRadius() * 2 - dist_to_entity;
            Vect collisionNormal = moving_entity.getPos()->vectorTo(*e->getPos());
            collisionNormal.setLength(-penetration_dist);
            moving_entity.getPos()->add(collisionNormal.x, collisionNormal.y);
        }
    }
}

bool MoveTo::destinationReached(Entity &e) const {
    return e.getPos()->distanceTo(destination_) <= CLOSE_ENOUGH;
}
