#include "statistics.h"

std::string Statistics::getLoadTime() const {
    return this->loadTime;
}

std::string Statistics::getFileSize() const {
    return this->fileSize;
}

void Statistics::setLoadTime(std::string loadTime){
    this->loadTime = loadTime;
}

void Statistics::setFileSize(std::string fileSize){
    this->fileSize = fileSize;
}
