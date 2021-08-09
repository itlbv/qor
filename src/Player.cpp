#include "Player.h"
#include "Qor.h"

const double Player::Speed = 7;

Player::Player(double x_a, double y_a)
        : Entity(999, x_a, y_a) {}

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
    for (auto &e_ : Qor::entities) {
        double dist_to_entity = getPos()->distanceTo(*e_->getPos());

        if (dist_to_entity < getRadius() * 2) {
            double penetration_dist = getRadius() * 2 - dist_to_entity;
            Vect collisionNormal = getPos()->vectorTo(*e_->getPos());
            collisionNormal.setLength(-penetration_dist);
            getPos()->add(collisionNormal.x, collisionNormal.y);
        }
    }
}
