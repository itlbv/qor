#include "MoveTo.h"
#include "../../../Qor.h"

btree::Status btree::MoveTo::run(Entity &e) {
    e.setVelocity(0, 0);
    Vect velocity = e._pos->vectorTo(*e.getDest());
    velocity.normalize();
    velocity.setLength(velocity.length() * Qor::delta * 5);
    e._pos->add(velocity.x, velocity.y);

    if (e._pos->distanceTo(*e.getDest()) <= 0.1) {
        return SUCCESS;
    }

    return RUNNING;
}
