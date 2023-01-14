#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> start;

public:
    static double time;

    Timer();

    ~Timer();
};

#endif // TIMER_H
