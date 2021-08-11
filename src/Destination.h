#pragma once

#include "Target.h"

class Destination : public Target {
public:
    Destination(double x_a, double y_a);

    Vect *getPos() override;

private:
    Vect pos_;
};

