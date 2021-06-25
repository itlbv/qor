#include "Player.h"

const double Player::Speed = 7;

Player::Player(double x_a, double y_a)
        : Entity(x_a, y_a) {}

void Player::update() {
    move();
}

void Player::move() {
    _pos->x += _velocity->x;
    _pos->y += _velocity->y;
    _velocity->set(0, 0);
}

void Player::checkCollisions() {

}
