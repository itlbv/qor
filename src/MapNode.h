#pragma once

#include <vector>
#include <memory>
#include "Item.h"

class MapNode {
public:
    MapNode(int x_a, int y_a);

    void put(const std::shared_ptr<Item> &item);

    std::vector<std::shared_ptr<Item>> *getItems();

private:
    int x;
    int y;
    std::vector<std::shared_ptr<Item>> items_;
};

