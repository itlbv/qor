#pragma once

#include "Entity.h"

class IBuilding : public Entity {
public:
    enum BuildingType {
        HOUSE
    };

    struct BuildingSize {
        int width, height;
    };

    static const BuildingSize HOUSE_SIZE;

    IBuilding(int id_a, int x_a, int y_a, int width_a, int height_a);

    static BuildingSize getBuildingSize(BuildingType buildingType_a);
};

