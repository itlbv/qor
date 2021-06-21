#include <memory>
#include "Qor.h"
#include "Input.h"
#include "ai/Ai.h"

#define SCREEN_WIDTH_PXL 1200
#define SCREEN_HEIGHT_PXL 900

bool Qor::quit = false;
std::vector<std::unique_ptr<Entity>> Qor::entities;

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createEntities();
    ai::init();
}

void Qor::run(unsigned int deltaTime) {
    Input::processInput();

    ai::run();

    window.startFrame();
    renderEntities();
    window.showFrame();
}

void Qor::createEntities() {
    entities.push_back(std::make_unique<Entity>(1, 1));
    entities.push_back(std::make_unique<Entity>(3, 4));
}

void Qor::renderEntities() {
    for (auto &e : entities) {
        window.renderEntity(*e.get());
    }
}
