#pragma once

#include <vector>
#include <memory>
#include "Item.h"

class MapNode {
public:
    MapNode(int x_a, int y_a);

    void put(const std::shared_ptr<Item> &item);

    std::vector<std::shared_ptr<Item>> *getItems();

    bool isEmpty();

    bool isPassable();

    void setPassable(bool passable_a);

    int getX();

    int getY();

    std::string getStringCoord();

    void setMovementCost(double cost_a);

    double getMovementCost();

private:
    int x_;
    int y_;
    bool passable_;
    double movement_cost_;
    std::vector<std::shared_ptr<Item>> items_;
};

