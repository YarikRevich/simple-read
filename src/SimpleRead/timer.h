#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

/*!
 * \brief The Timer class is used to measure the time spent reading input files
 */
class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> start;

public:
    static std::string time;

    Timer();

    ~Timer();
};

#endif // TIMER_H
