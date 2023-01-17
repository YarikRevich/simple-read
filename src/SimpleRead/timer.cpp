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

    if (std::to_string(minutes).length() < 2){
        stream << "0";
    };
    stream << minutes << ":";
    if (std::to_string(seconds).length() < 2){
        stream << "0";
    };
    stream << seconds << ":";
    if (std::to_string(milliseconds).length() < 2){
        stream << "0";
    };
    stream << milliseconds << ":";
    if (std::to_string(microseconds).length() < 2){
        stream << "0";
    };
    stream << microseconds;

    Timer::time = stream.str();
}
