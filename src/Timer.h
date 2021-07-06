#pragma once

class Timer {
private:
    unsigned int timeStarted;

public:
    void start();

    [[nodiscard]] unsigned int getTimePassed() const;
};
