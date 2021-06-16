#include "Entity.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(double x, double y)
        : pos(Vect{x, y}),
          radius(ENTITY_BODY_RADIUS) {
}

SDL_Rect *Entity::getRenderShape() {
    return &renderShape;
}
