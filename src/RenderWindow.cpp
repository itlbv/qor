#include <iostream>
#include <SDL.h>
#include "RenderWindow.h"

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

void RenderWindow::updateViewport(Viewport *viewport) {
    SDL_RenderSetViewport(renderer, viewport->getViewportRect());
}

void RenderWindow::startFrame() {
    SDL_SetRenderDrawColor(renderer, 90, 125, 70, 255); // set default green
    SDL_RenderClear(renderer);
}

void RenderWindow::showFrame() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::renderEntity(Entity &e) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //blue
    SDL_RenderFillRect(renderer, getEntityRenderShape(&e));

    //render dot indicating entity's position
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    SDL_RenderDrawPoint(renderer,
                        worldToScreen(e._pos.x),
                        worldToScreen(e._pos.y));
}

SDL_Rect *RenderWindow::getEntityRenderShape(Entity *e) {
    SDL_Rect *renderShape = e->getRenderShape();
    renderShape->x = worldToScreen(e->_pos.x - e->_radius);
    renderShape->y = worldToScreen(e->_pos.y - e->_radius);
    renderShape->w = worldToScreen(e->_radius * 2);
    renderShape->h = worldToScreen(e->_radius * 2);
    return renderShape;
}

int RenderWindow::worldToScreen(double a) {
    return a * 50;
}

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(window);
}
