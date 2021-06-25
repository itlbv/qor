#include <memory>
#include "Qor.h"
#include "Input.h"
#include "ai/Ai.h"

#define SCREEN_WIDTH_PXL 1200
#define SCREEN_HEIGHT_PXL 900

bool Qor::quit = false;
double Qor::delta;
std::vector<std::shared_ptr<Entity>> Qor::entities;

std::unique_ptr<Player> Qor::player = std::make_unique<Player>(5, 5);

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createEntities();
}

void Qor::run(unsigned int deltaTime) {
    Qor::delta = (double) deltaTime / 1000;

    Input::processInput();

    player->update();
    ai::Ai::run();

    window.startFrame();
    renderEntities();
    renderPlayer();
    window.showFrame();
}

void Qor::createEntities() {
    entities.push_back(std::make_shared<Entity>(1, 1));
    entities.push_back(std::make_shared<Entity>(3, 4));
}

void Qor::renderEntities() {
    for (auto &e : entities) {
        window.renderEntity(*e.get());
    }
}

void Qor::renderPlayer() {
    window.renderEntity(*player);
}
