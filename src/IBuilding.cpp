#include "IBuilding.h"
#include "Logger.h"

const IBuilding::BuildingSize IBuilding::HOUSE_SIZE{3, 4};

IBuilding::IBuilding(int id_a, int x_a, int y_a, int width_a, int height_a)
        : Entity(id_a, x_a, y_a, 2, {0, 0, 0, 255}, STATIC, width_a, height_a) {}

IBuilding::BuildingSize IBuilding::getBuildingSize(IBuilding::BuildingType buildingType_a) {
    switch (buildingType_a) {
        case HOUSE:
            return HOUSE_SIZE;
    }
    Logger::error("Can't find building type, returning default building size.");
    return {1, 1};
}
