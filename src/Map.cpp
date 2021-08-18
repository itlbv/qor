#include "Map.h"

Map::Map(int w_a, int h_a)
        : w(w_a),
          h(h_a) {
    for (int i = 0; i < h_a; ++i) {
        for (int j = 0; j < w_a; ++j) {
            nodes_.push_back(std::make_unique<MapNode>(j, i));
        }
    }
}

void Map::putToNode(int x, int y, const std::shared_ptr<Item> &item) {
    getNodeFromCoord(x, y)->put(item);
}

MapNode *Map::getNodeFromCoord(int x, int y) {
    return nodes_[y * w + x].get();
}

std::vector<std::unique_ptr<MapNode>> *Map::getNodes() {
    return &nodes_;
}
