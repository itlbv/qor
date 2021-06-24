#include "Util.h"

namespace util {
    int worldToScreen(double a_world) {
        return a_world * 50;
    }

    double screenToWorld(int a_screen) {
        return a_screen / 50;
    }
}