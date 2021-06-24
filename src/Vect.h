#ifndef QOR_VECT_H
#define QOR_VECT_H

#include <cmath>

struct Vect {
    double x, y;

    double length() const {
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

    void setLength(double a_length) {
        double length = this->length();
        if (length > 0) {
            double newLength = a_length / length;
            x *= newLength;
            y *= newLength;
        }
    }

    double distanceTo(const Vect &a_dest) const {
        return sqrt(pow(abs(x - a_dest.x), 2) + pow(abs(y - a_dest.y), 2));
    }

    Vect vectorTo(const Vect &a_dest) const {
        return {a_dest.x - x, a_dest.y - y};
    }

    void add(double a_x, double a_y) {
        x += a_x;
        y += a_y;
    }
};

#endif //QOR_VECT_H
