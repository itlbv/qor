#pragma once

#include <vector>
#include <memory>
#include "Item.h"

class MapNode {
public:
    MapNode(int x_a, int y_a);

    void put(std::shared_ptr<Item> i);

    void pickUp(std::shared_ptr<Item> i);

    std::vector<std::shared_ptr<Item>> *getItems();

    bool isEmpty();

    bool isPassable();

    int x;
    int y;
private:
    bool passable_;
    std::vector<std::shared_ptr<Item>> items_;
};

