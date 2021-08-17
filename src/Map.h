#pragma once

#include <vector>
#include <memory>
#include "MapNode.h"

class Map {
public:
    Map(int x, int y);

    std::vector<std::unique_ptr<MapNode>> *getNodes();

private:
    std::vector<std::unique_ptr<MapNode>> nodes_;
};

