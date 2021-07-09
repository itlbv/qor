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
    pos_->x += velocity_->x;
    pos_->y += velocity_->y;
    velocity_->set(0, 0);
}

void Player::checkCollisions() {
    for (auto &e_ : Qor::entities) {
        double dist_to_entity = pos_->distanceTo(*e_->pos_);

        if (dist_to_entity < radius_ * 2) {
            double penetration_dist = radius_ * 2 - dist_to_entity;
            Vect collisionNormal = pos_->vectorTo(*e_->pos_);
            collisionNormal.setLength(-penetration_dist);
            pos_->add(collisionNormal.x, collisionNormal.y);
        }
    }
}
