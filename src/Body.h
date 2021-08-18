#pragma once

#include "Vect.h"
#include "RenderShape.h"

class Body {
public:
    Body(double x, double y, double w, double h);

    Vect *getPos();

    double getWidth();

    double getHeight();

private:
    Vect pos_;
    double width_;
    double height_;
};

