#include "Build.h"
#include "../../../Qor.h"
#include "../../../House.h"
#include "../../../Logger.h"

Build::Build(IBuilding::BuildingType building_type_a)
        : BTreeTask(),
          building_type_(building_type_a) {
    name_ = "build";
}

BTreeStatus Build::run(Mob &m) {

    Logger::log("build");

    Target *target = m.getTarget().lock().get();

    switch (building_type_) {
        case IBuilding::HOUSE:
            std::shared_ptr<House> house = std::make_shared<House>(100, target->getPos()->x, target->getPos()->y - 4.5);
            Qor::buildings.push_back(house);
            m.home = house;
    }

    return SUCCESS;
}
