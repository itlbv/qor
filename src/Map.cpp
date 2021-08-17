#include "Map.h"

Map::Map(int x, int y) {
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            nodes_.push_back(std::make_unique<MapNode>(j, i));
        }
    }
}

std::vector<std::unique_ptr<MapNode>> *Map::getNodes() {
    return &nodes_;
}
