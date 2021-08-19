#pragma once

#include "../BTreeTask.h"
#include "../../../IBuilding.h"

class Build : public BTreeTask {
public:
    Build(IBuilding::BuildingType building_type_a);

    BTreeStatus run(Mob &m) override;

private:
    IBuilding::BuildingType building_type_;
};

