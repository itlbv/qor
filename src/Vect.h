#pragma once

#include <cmath>

struct Vect {
    double x, y;

    [[nodiscard]] double length() const {
        using namespace std;
        return sqrt(pow(x, 2) + pow(y, 2));
    };

    void normalize() {
        double length = this->length();
        if (length > 0) {
            x /= length;
            y /= length;
        }
    }

    void setLength(double length_a) {
        double length = this->length();
        if (length > 0) {
            double newLength = length_a / length;
            x *= newLength;
            y *= newLength;
        }
    }

    [[nodiscard]] double distanceTo(const Vect &pos_a) const {
        return sqrt(pow(abs(x - pos_a.x), 2) + pow(abs(y - pos_a.y), 2));
    }

    Vect vectorTo(const Vect &pos_a) const {
        return {pos_a.x - x, pos_a.y - y};
    }

    void add(double x_a, double y_a) {
        x += x_a;
        y += y_a;
    }

    void zero() {
        x = 0;
        y = 0;
    }

    void set(Vect &vect_a) {
        x = vect_a.x;
        y = vect_a.y;
    }

    void set(double x_a, double y_a) {
        x = x_a;
        y = y_a;
    }
};
