#pragma once

#include <SDL_rect.h>

struct RenderShape {
    const double radius;
    SDL_Rect rect;
    SDL_Color color;

    RenderShape(double radius_a, SDL_Color color_a);
};
