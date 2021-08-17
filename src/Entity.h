#pragma once

#include <SDL.h>
#include <memory>
#include "Vect.h"
#include "Target.h"
#include "RenderShape.h"

class Entity : public Target {
private:
    const int id_;
    std::unique_ptr<Vect> pos_;
    RenderShape renderShape_;

public:
    Entity(int id_a, double x_a, double y_a, double radius_a, SDL_Color render_color_a, TargetType targetType_a);

    void updateRenderPosition();

    [[nodiscard]] int getId() const;

    Vect *getPos() override;

    RenderShape *getRenderShape();
};
