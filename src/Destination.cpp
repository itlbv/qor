#include "Destination.h"

Destination::Destination(double x_a, double y_a)
        : Target(TargetType::STATIC),
          pos_({x_a, y_a}) {}

Vect *Destination::getPos() {
    return &pos_;
}
