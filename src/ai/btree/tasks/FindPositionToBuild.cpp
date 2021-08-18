#include "FindPositionToBuild.h"
#include "../../../Qor.h"

FindPositionToBuild::FindPositionToBuild() : BTreeTask() {
    name_ = " find_position_to_build";
}

BTreeStatus FindPositionToBuild::run(Mob &m) {

    int width = 3;
    int height = 4;

    for (auto &node : *Qor::map->getNodes()) {
        bool good = true;
        if (node->isEmpty()) {

            for (int h = 0; h < height; ++h) {
                for (int w = 0; w < width; ++w) {
                    if (!Qor::map->getNodeFromCoord(node->getX() + w, node->getY() + h)->isEmpty()) {
                        good = false;
                    }
                }
            }

        }
    }

    return SUCCESS;
}
