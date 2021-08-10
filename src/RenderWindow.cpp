#include <iostream>
#include <SDL.h>
#include "RenderWindow.h"
#include "Util.h"

RenderWindow::RenderWindow(const char *title, int width, int height)
        : window_(nullptr),
          renderer_(nullptr) {
    window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (window_ == nullptr)
        std::cout << "SDL_CreateWindow FAILED. Error: " << SDL_GetError();

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr)
        std::cout << "SDL_CreateRenderer FAILED. Error: " << SDL_GetError();
}

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}

void RenderWindow::updateViewport(Viewport *viewport) {
    SDL_RenderSetViewport(renderer_, viewport->getViewportRect());
}

void RenderWindow::startFrame() {
    SDL_SetRenderDrawColor(renderer_, 90, 125, 70, 255); // set default green
    SDL_RenderClear(renderer_);
    RenderWindow::renderMapGrid();
}

void RenderWindow::renderMapGrid() {
    int mapSize = util::worldToScreen(40);

    //draw horizontal
    for (int i = 0; i < mapSize; ++i) {
        int coord = util::worldToScreen(i);
        renderLine(0, coord, mapSize, coord);
    }

    //draw vertical
    for (int i = 0; i < mapSize; ++i) {
        int coord = util::worldToScreen(i);
        renderLine(coord, 0, coord, mapSize);
    }
}

void RenderWindow::renderLine(int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}

void RenderWindow::showFrame() {
    SDL_RenderPresent(renderer_);
}

void RenderWindow::renderResource(Resource &r) {
    SDL_SetRenderDrawColor(renderer_,
                           r.getRenderColor()->r,
                           r.getRenderColor()->g,
                           r.getRenderColor()->b,
                           r.getRenderColor()->a);
    SDL_RenderFillRect(renderer_, getEntityRenderShape(&r));

    //render dot indicating entity's position
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255); // white
    SDL_RenderDrawPoint(renderer_,
                        util::worldToScreen(r.getPos()->x),
                        util::worldToScreen(r.getPos()->y));
}

void RenderWindow::renderMob(Mob &m) {
    !m.isDead() ? SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255) //blue
                : SDL_SetRenderDrawColor(renderer_, 150, 150, 150, 255); //gray
    SDL_RenderFillRect(renderer_, getEntityRenderShape(&m));

    //render dot indicating entity's position
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255); // white
    SDL_RenderDrawPoint(renderer_,
                        util::worldToScreen(m.getPos()->x),
                        util::worldToScreen(m.getPos()->y));
}

SDL_Rect *RenderWindow::getEntityRenderShape(Entity *e) {
    SDL_Rect *renderShape = e->getRenderShape();
    renderShape->x = util::worldToScreen(e->getPos()->x - e->getRadius());
    renderShape->y = util::worldToScreen(e->getPos()->y - e->getRadius());
    renderShape->w = util::worldToScreen(e->getRadius() * 2);
    renderShape->h = util::worldToScreen(e->getRadius() * 2);
    return renderShape;
}
