#ifndef QOR_TIMER_H
#define QOR_TIMER_H


class Timer {
private:
    unsigned int timeStarted;

public:
    void start();

    [[nodiscard]] unsigned int getTimePassed() const;
};


#endif //QOR_TIMER_H
