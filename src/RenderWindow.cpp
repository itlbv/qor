#include <iostream>
#include <SDL.h>
#include "RenderWindow.h"
#include "Util.h"

RenderWindow::RenderWindow(const char *title, int width, int height)
        : window(nullptr),
          renderer(nullptr) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (window == nullptr)
        std::cout << "SDL_CreateWindow FAILED. Error: " << SDL_GetError();

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
        std::cout << "SDL_CreateRenderer FAILED. Error: " << SDL_GetError();
}

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(window);
}

void RenderWindow::updateViewport(Viewport *viewport) {
    SDL_RenderSetViewport(renderer, viewport->getViewportRect());
}

void RenderWindow::startFrame() {
    SDL_SetRenderDrawColor(renderer, 90, 125, 70, 255); // set default green
    SDL_RenderClear(renderer);
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
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void RenderWindow::showFrame() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::renderEntity(Entity &e) {
    e.isAlive() ? SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255) //blue
                : SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); //gray
    SDL_RenderFillRect(renderer, getEntityRenderShape(&e));

    //render dot indicating entity's position
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    SDL_RenderDrawPoint(renderer,
                        util::worldToScreen(e.pos_->x),
                        util::worldToScreen(e.pos_->y));
}

SDL_Rect *RenderWindow::getEntityRenderShape(Entity *e) {
    SDL_Rect *renderShape = e->getRenderShape();
    renderShape->x = util::worldToScreen(e->pos_->x - e->radius_);
    renderShape->y = util::worldToScreen(e->pos_->y - e->radius_);
    renderShape->w = util::worldToScreen(e->radius_ * 2);
    renderShape->h = util::worldToScreen(e->radius_ * 2);
    return renderShape;
}
