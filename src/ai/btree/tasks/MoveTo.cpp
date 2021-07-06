#include "MoveTo.h"
#include "../../../Qor.h"

namespace btree {
    const double MoveTo::DestinationReachedThreshold = 0.1;
    const double MoveTo::Speed = 5;
    Vect MoveTo::velocity_;

    BTreeStatus MoveTo::run(Entity &e) {
        move(e);
        checkCollisions(e);

        if (destinationReached(e)) {
            return SUCCESS;
        } else return RUNNING;
    }

    void MoveTo::move(Entity &e) {
        velocity_ = e.pos_->vectorTo(*e.getDest());
        velocity_.normalize();
        velocity_.setLength(velocity_.length() * Qor::delta * Speed);
        e.pos_->add(velocity_.x, velocity_.y);
    }

    void MoveTo::checkCollisions(Entity &moving_entity) {
        for (auto &e : Qor::entities) {
            if (e.get() == &moving_entity)
                continue;

            double dist_to_entity = moving_entity.pos_->distanceTo(*e->pos_);
            if (dist_to_entity < moving_entity.radius_ * 2) {
                double penetration_dist = moving_entity.radius_ * 2 - dist_to_entity;
                Vect collisionNormal = moving_entity.pos_->vectorTo(*e->pos_);
                collisionNormal.setLength(-penetration_dist);
                moving_entity.pos_->add(collisionNormal.x, collisionNormal.y);
            }
        }
    }

    bool MoveTo::destinationReached(Entity &e) {
        return e.pos_->distanceTo(*e.getDest()) <= DestinationReachedThreshold;
    }
}
