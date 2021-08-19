#pragma once

#include "../BTreeTask.h"
#include "../../../IBuilding.h"
#include "../../../Destination.h"
#include "../../../MapNode.h"

class FindPositionToBuild : public BTreeTask {
public:
    explicit FindPositionToBuild(IBuilding::BuildingType building_type_a);

    BTreeStatus run(Mob &m) override;

private:
    IBuilding::BuildingSize building_size_;

    bool nodesUnderBuildingAreFine(MapNode *first_node_a) const;

    bool nodesAroundBuildingAreFine(MapNode *first_node_a);

    std::shared_ptr<Destination> getDestinationToClosestAdjacentNode(MapNode *first_node_a);
};

