#include "Player.h"

Player::Player(double x_a, double y_a)
        : velocity_player_(),
          Entity(x_a, y_a) {}

void Player::update() {
    move();
}

void Player::move() {
    _pos->x += velocity_player_.x;
    _pos->y += velocity_player_.y;
    velocity_player_.set(0, 0);
}

void Player::checkCollisions() {

}
