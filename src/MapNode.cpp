#include <string>
#include "MapNode.h"

MapNode::MapNode(int x_a, int y_a)
        : x_(x_a),
          y_(y_a),
          passable_(true),
          movement_cost_(1) {}

void MapNode::put(const std::shared_ptr<Item> &item) {
    items_.push_back(item);
}

std::vector<std::shared_ptr<Item>> *MapNode::getItems() {
    return &items_;
}

bool MapNode::isEmpty() const {
    return items_.empty();
}

int MapNode::getX() const {
    return x_;
}

int MapNode::getY() const {
    return y_;
}

bool MapNode::isPassable() const {
    return passable_;
}

void MapNode::setPassable(bool passable_a) {
    passable_ = passable_a;
}

std::string MapNode::getStringCoord() const {
    return std::string("["
           + std::to_string(x_)
           + ", "
           + std::to_string(y_)
           + "]");

}

void MapNode::setMovementCost(double cost_a) {
    movement_cost_ = cost_a;
}

double MapNode::getMovementCost() {
    return movement_cost_;
}
