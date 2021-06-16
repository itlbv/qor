#include "Qor.h"
#include "Input.h"

#define SCREEN_WIDTH_PXL 1200
#define SCREEN_HEIGHT_PXL 900

bool Qor::quit = false;

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createEntities();
}

void Qor::run() {
    Input::processInput();

    window.startFrame();
    renderEntities();
    window.showFrame();
}

void Qor::createEntities() {
    Entity e1(1, 1);
    Entity e2(4, 3);
    entities.push_back(e1);
    entities.push_back(e2);
}

void Qor::renderEntities() {
    for (Entity e : entities) {
        window.renderEntity(e);
    }
}
