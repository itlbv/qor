#include "RenderShape.h"
#include "Util.h"

RenderShape::RenderShape(double radius_a, SDL_Color color_a)
        : radius(radius_a),
          rect({0, 0, Util::worldToScreen(radius_a * 2), Util::worldToScreen(radius_a * 2)}),
          color(color_a) {}
