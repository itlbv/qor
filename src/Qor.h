#pragma once

#include <vector>
#include "RenderWindow.h"
#include "Viewport.h"
#include "Entity.h"
#include "Mob.h"
#include "Player.h"
#include "Resource.h"

class Qor {
private:
    RenderWindow window;
    Viewport viewport;

    static void createResources();

    static void createEntities();

    void renderResources();

    void renderMobs();

    void renderPlayer();

public:
    static bool quit;
    static std::vector<std::unique_ptr<Resource>> resources;
    static std::vector<std::shared_ptr<Mob>> mobs;
    static double delta;

    static std::unique_ptr<Player> player;

    Qor();

    void run(unsigned int deltaTime);

    void updateEntities();
};
