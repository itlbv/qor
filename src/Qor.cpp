#include <memory>
#include "Qor.h"
#include "Input.h"

#define SCREEN_WIDTH_PXL 1200
#define SCREEN_HEIGHT_PXL 900

bool Qor::quit = false;
double Qor::delta;
std::vector<std::shared_ptr<Mob>> Qor::mobs;

std::unique_ptr<Player> Qor::player = std::make_unique<Player>(15, 15);

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createEntities();
}

void Qor::run(unsigned int deltaTime) {
    Qor::delta = (double) deltaTime / 1000;

    Input::processInput();

    player->update();
    updateEntities();

    window.startFrame();
    renderMobs();
    renderPlayer();
    window.showFrame();
}

void Qor::createEntities() {
    mobs.push_back(std::make_shared<Mob>(1, 1, 1));
    mobs.push_back(std::make_shared<Mob>(2, 5, 5));
}

void Qor::updateEntities() {
    for (auto &e : mobs) {
        e->update();
    }
}

void Qor::renderMobs() {
    for (auto &m : mobs) {
        window.renderMob(*m.get());
    }
}

void Qor::renderPlayer() {
    window.renderMob(*player);
}
