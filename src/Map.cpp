#include "Map.h"
#include "Qor.h"
#include "Logger.h"

const double Map::NODE_SIZE = 1;

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
    if (x >= Qor::MAP_SIZE || y >= Qor::MAP_SIZE) {
        std::string message(
                "Trying to get MapNode with coordinates bigger than Map size. Coord are: ["
                + std::to_string(x)
                + ", "
                + std::to_string(y)
                + "]");
        Logger::error(message);
        throw std::out_of_range(message);
    }
    return nodes_[y * w + x].get();
}

std::vector<std::unique_ptr<MapNode>> *Map::getNodes() {
    return &nodes_;
}
