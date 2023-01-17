#include "timer.h"
#include <sstream>
#include <iomanip>
#include <QObject>

std::string Timer::time = "";

Timer::Timer(){
    this->start = std::chrono::system_clock::now();
}

Timer::~Timer(){
    std::chrono::duration delta = std::chrono::system_clock::now() - this->start;
    int microseconds = std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(delta).count();
    int seconds = std::chrono::duration_cast<std::chrono::seconds>(delta).count();
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(delta).count();

    std::stringstream stream;
    stream << minutes << ":";
    stream << seconds << ":";
    stream << milliseconds << ":";
    stream << microseconds;
    Timer::time = stream.str();
}
