#pragma once

#include <vector>
#include "RenderWindow.h"
#include "Viewport.h"
#include "Entity.h"
#include "Mob.h"
#include "Player.h"
#include "Item.h"

class Qor {
private:
    RenderWindow window;
    Viewport viewport;

    static void createMobs();

    static void createItems();

    static void updateMobs();

    void renderItems();

    void renderMobs();

    void renderPlayer();

public:
    static bool quit;
    static std::vector<std::shared_ptr<Item>> items;
    static std::vector<std::shared_ptr<Mob>> mobs;
    static double delta;

    static std::unique_ptr<Player> player;

    Qor();

    void run(unsigned int deltaTime);
};
