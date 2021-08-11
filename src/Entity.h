#pragma once

#include <SDL.h>
#include <memory>
#include "Vect.h"
#include "Target.h"

class Entity : public Target {
private:
    const int id_;
    const double radius_;
    std::unique_ptr<Vect> pos_;
    std::unique_ptr<SDL_Rect> render_shape_;
    SDL_Color render_color_;

public:
    Entity(int id_a, double x_a, double y_a, double radius_a, SDL_Color render_color_a, TargetType targetType_a);

    [[nodiscard]] int getId() const;

    Vect *getPos() override;

    [[nodiscard]] double getRadius() const;

    SDL_Rect *getRenderShape();

    SDL_Color *getRenderColor();

    void setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};
