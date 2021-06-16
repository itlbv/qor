#include "Qor.h"

#define SCREEN_WIDTH_PXL 1200
#define SCREEN_HEIGHT_PXL 900

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
}

void Qor::run() {
    window.startFrame();
    window.showFrame();
}
