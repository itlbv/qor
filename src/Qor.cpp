#include <memory>
#include "Qor.h"
#include "Input.h"

const int Qor::SCREEN_WIDTH_PXL = 1200;
const int Qor::SCREEN_HEIGHT_PXL = 900;
const int Qor::MAP_SIZE = 25;

RenderWindow Qor::window("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL);

bool Qor::quit = false;
double Qor::delta;
std::unique_ptr<Map> Qor::map;
std::vector<std::shared_ptr<Mob>> Qor::mobs;
std::vector<std::shared_ptr<IBuilding>> Qor::buildings;

std::unique_ptr<Player> Qor::player = std::make_unique<Player>(15, 15);

Qor::Qor()
        : viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createMap();
    createMobs();
    createItems();
}

void Qor::run(unsigned int deltaTime) {
    Qor::delta = (double) deltaTime / 1000;

    Input::processInput();

    player->update();
    updateMobs();

    window.startFrame();
    renderMap();
    renderItems();
    renderBuildings();
    renderMobs();
    renderPlayer();
    window.showFrame();
}

void Qor::createMap() {
    map = std::make_unique<Map>(MAP_SIZE, MAP_SIZE);
}

void Qor::createItems() {
    std::shared_ptr<Item> item1 = std::make_shared<Item>(10, 2, 2);
    map->putToNode(2, 2, item1);

    std::shared_ptr<Item> item2 = std::make_shared<Item>(11, 4, 8);
    map->putToNode(4, 8, item2);

    std::shared_ptr<Item> item3 = std::make_shared<Item>(12, 7, 7);
    map->putToNode(7, 7, item3);
}

void Qor::createMobs() {
    mobs.push_back(std::make_shared<Mob>(1, 1, 1));
//    mobs.push_back(std::make_shared<Mob>(2, 8, 8));
}

void Qor::updateMobs() {
    for (auto &e : mobs) {
        e->update();
    }
}

void Qor::renderMap() {
    window.renderMap();
}

void Qor::renderBuildings() {
    for (auto &b : Qor::buildings) {
        window.renderEntity(*b);
    }
}

void Qor::renderItems() {
    for (auto &node : *Qor::map->getNodes()) {
        for (auto &item : *node->getItems()) {
            window.renderEntity(*item);
        }
    }
}

void Qor::renderMobs() {
    for (auto &m : mobs) {
        window.renderEntity(*m);
    }
}

void Qor::renderPlayer() {
    window.renderEntity(*player);
}
