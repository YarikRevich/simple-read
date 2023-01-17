#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>

class Statistics
{
private:
    std::string loadTime;
    std::string fileSize;
public:
    std::string getLoadTime() const;

    std::string getFileSize() const;

protected:
    void setLoadTime(std::string loadTime);

    void setFileSize(std::string fileSize);
};

#endif // STATISTICS_H
