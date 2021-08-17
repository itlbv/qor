#include "Util.h"

int Util::worldToScreen(double a_world) {
    return a_world * 50;
}

double Util::screenToWorld(int a_screen) {
    return a_screen / (double) 50;
}
