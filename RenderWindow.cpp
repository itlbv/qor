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

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(window);
}
