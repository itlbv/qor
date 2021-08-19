#include "FindPositionToBuild.h"
#include "../../../Qor.h"
#include "../../../Logger.h"

FindPositionToBuild::FindPositionToBuild(IBuilding::BuildingType building_type_a)
        : BTreeTask(),
          building_size_(IBuilding::getBuildingSize(building_type_a)) {
    name_ = " find_position_to_build";
}

BTreeStatus FindPositionToBuild::run(Mob &m) {

    for (auto &node : *Qor::map->getNodes()) {
        if (nodesUnderBuildingAreFine(node.get()) &&
            nodesAroundBuildingAreFine(node.get())) {
            m.setTarget(getDestinationToClosestAdjacentNode(node.get()));
            return SUCCESS;
        }
    }

    Logger::log("can't find place to build.", m);
    return FAILURE;
}

bool FindPositionToBuild::nodesUnderBuildingAreFine(MapNode *first_node_a) const {

    if (!first_node_a->isEmpty() || !first_node_a->isPassable())
        return false;

    for (int h = 0; h < building_size_.height; ++h) {
        int next_node_Y = first_node_a->getY() + h;

        if (next_node_Y >= Qor::MAP_SIZE)
            return false; // Y coord is outside the map which means that there are no nodes left

        for (int w = 0; w < building_size_.width; ++w) {
            int next_node_X = first_node_a->getX() + w;

            if (next_node_X >= Qor::MAP_SIZE)
                continue; // X coord is outside the map, continue to the next Y row

            MapNode *next_node = Qor::map->getNodeFromCoord(next_node_X, next_node_Y);
            if (!next_node->isEmpty() || !next_node->isPassable())
                return false;
        }
    }

    return true;
}

bool FindPositionToBuild::nodesAroundBuildingAreFine(MapNode *first_node_a) {
//    int next_node_Y = first_node_a->getY() - 2;

    return true;
}

std::shared_ptr<Destination> FindPositionToBuild::getDestinationToClosestAdjacentNode(MapNode *first_node_a) {
    return std::make_shared<Destination>(first_node_a->getX() + 0.5,
                                         first_node_a->getY() + building_size_.height + 1.5);
}
