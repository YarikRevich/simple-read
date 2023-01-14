#include "timer.h"

double Timer::time = 0;

Timer::Timer(){
    this->start = std::chrono::system_clock::now();
}

Timer::~Timer(){
    Timer::time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - this->start).count();
}
