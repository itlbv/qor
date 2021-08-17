#include "Player.h"
#include "Qor.h"

const double Player::Speed = 7;

Player::Player(double x_a, double y_a)
        : Mob(999, x_a, y_a) {}

void Player::update() {
    move();
    checkCollisions();
}

void Player::move() {
    getPos()->x += velocity_->x;
    getPos()->y += velocity_->y;
    velocity_->set(0, 0);
}

void Player::checkCollisions() {
    for (auto &m : Qor::mobs) {
        double dist_to_entity = getPos()->distanceTo(*m->getPos());

        if (dist_to_entity < getRenderShape()->radius * 2) {
            double penetration_dist = getRenderShape()->radius * 2 - dist_to_entity;
            Vect collisionNormal = getPos()->vectorTo(*m->getPos());
            collisionNormal.setLength(-penetration_dist);
            getPos()->add(collisionNormal.x, collisionNormal.y);
        }
    }
}
