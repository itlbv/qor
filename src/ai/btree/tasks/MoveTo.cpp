#include "MoveTo.h"
#include "../../../Qor.h"

namespace btree {
    const double MoveTo::DestinationReachedThreshold = 0.1;
    const double MoveTo::Speed = 5;
    Vect MoveTo::velocity_;

    Status MoveTo::run(Entity &e) {
        move(e);
        checkCollisions(e);

        if (destinationReached(e)) {
            return SUCCESS;
        } else return RUNNING;
    }

    void MoveTo::move(Entity &e) {
        velocity_ = e._pos->vectorTo(*e.getDest());
        velocity_.normalize();
        velocity_.setLength(velocity_.length() * Qor::delta * Speed);
        e._pos->add(velocity_.x, velocity_.y);
    }

    void MoveTo::checkCollisions(Entity &e) {
        for (auto &e_ : Qor::entities) {
            if (e_.get() == &e)
                continue;

            double distance_to_entity = e._pos->distanceTo(*e_->_pos);

            if (distance_to_entity < e._radius * 2) {
                double penetration_distance = e._radius * 2 - distance_to_entity;
                Vect collisionNormal = e._pos->vectorTo(*e_->_pos);
                collisionNormal.setLength(penetration_distance);
                e._pos->add(collisionNormal.x, collisionNormal.y);
            }
        }
    }

    bool MoveTo::destinationReached(Entity &e) {
        return e._pos->distanceTo(*e.getDest()) <= DestinationReachedThreshold;
    }
}
