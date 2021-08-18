#include "Body.h"

Body::Body(double x, double y, double w, double h)
        : pos_({x, y}),
          width_(w),
          height_(h) {}

Vect *Body::getPos() {
    return &pos_;
}

double Body::getWidth() {
    return width_;
}

double Body::getHeight() {
    return height_;
}
