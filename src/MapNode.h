#pragma once

#include <vector>
#include <memory>
#include "Item.h"

class MapNode {
public:
    MapNode(int x_a, int y_a);

    void put(const std::shared_ptr<Item> &item);

    std::vector<std::shared_ptr<Item>> *getItems();

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isPassable() const;

    void setPassable(bool passable_a);

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

    [[nodiscard]] std::string getStringCoord() const;

    void setMovementCost(double cost_a);

    double getMovementCost();

private:
    int x_;
    int y_;
    bool passable_;
    double movement_cost_;
    std::vector<std::shared_ptr<Item>> items_;
};

