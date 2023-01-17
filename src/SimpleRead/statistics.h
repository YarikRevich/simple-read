#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>

class Statistics
{
private:
    std::string loadTime;

public:
    Statistics();

    std::string getLoadTime() const {
        return this->loadTime;
    }
protected:
    void setLoadTime(std::string loadTime){
        this->loadTime = loadTime;
    }
};

#endif // STATISTICS_H
