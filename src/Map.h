#pragma once

#include <vector>
#include <memory>
#include "MapNode.h"

class Map {
public:
    Map(int w_a, int h_a);

    void putToNode(int x, int y, const std::shared_ptr<Item> &item);

    std::vector<std::unique_ptr<MapNode>> *getNodes();

private:
    int w;
    int h;
    std::vector<std::unique_ptr<MapNode>> nodes_;

    MapNode *getNodeFromCoord(int x, int y);
};

