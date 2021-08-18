#include <iostream>
#include <SDL.h>
#include "RenderWindow.h"
#include "Util.h"
#include "Qor.h"

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
    SDL_RenderClear(renderer_);
}

void RenderWindow::showFrame() {
    SDL_RenderPresent(renderer_);
}

void RenderWindow::renderMap() {
    SDL_SetRenderDrawColor(renderer_, 90, 125, 70, 255);
    SDL_Rect rect;
    for (auto &n : *Qor::map->getNodes()) {
        rect.x = Util::worldToScreen(n->getX());
        rect.y = Util::worldToScreen(n->getY());
        rect.w = Util::worldToScreen(Qor::map->NODE_SIZE);
        rect.h = Util::worldToScreen(Qor::map->NODE_SIZE);
        SDL_RenderFillRect(renderer_, &rect);
    }
    RenderWindow::renderMapGrid();
}

void RenderWindow::renderMapGrid() {
    int mapSize = Util::worldToScreen(Qor::MAP_SIZE);

    //draw horizontal
    for (int i = 0; i < Qor::MAP_SIZE; ++i) {
        int coord = Util::worldToScreen(i);
        renderLine(0, coord, mapSize, coord);
    }

    //draw vertical
    for (int i = 0; i < Qor::MAP_SIZE; ++i) {
        int coord = Util::worldToScreen(i);
        renderLine(coord, 0, coord, mapSize);
    }
}

void RenderWindow::renderLine(int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}

void RenderWindow::renderEntity(Entity &e) {
    SDL_SetRenderDrawColor(renderer_,
                           e.getRenderShape()->color.r,
                           e.getRenderShape()->color.g,
                           e.getRenderShape()->color.b,
                           e.getRenderShape()->color.a);
    SDL_RenderFillRect(renderer_, &e.getRenderShape()->rect);

    //render dot indicating entity's position
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255); // white
    SDL_RenderDrawPoint(renderer_,
                        Util::worldToScreen(e.getPos()->x),
                        Util::worldToScreen(e.getPos()->y));
}
