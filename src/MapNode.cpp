#include "MapNode.h"

MapNode::MapNode(int x_a, int y_a)
        : x(x_a), y(y_a) {}

void MapNode::put(const std::shared_ptr<Item> &item) {
    items_.push_back(item);
}

std::vector<std::shared_ptr<Item>> *MapNode::getItems() {
    return &items_;
}

bool MapNode::isEmpty() {
    return items_.empty();
}

int MapNode::getX() {
    return x;
}

int MapNode::getY() {
    return y;
}
