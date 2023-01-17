#include "statisticswindow.h"

void StatisticsWindow::onInit(){
    qInfo("StatisticsWindow is initialized!");
}

void StatisticsWindow::onOpen(){
    QMLWindow::onOpen(QML_STATISTICSWINDOW);
}

void StatisticsWindow::setStatistics(Statistics *statistics){
    this->statistics = statistics;
}

QString StatisticsWindow::getLoadTime() const{
    return QString::fromStdString(this->statistics->getLoadTime());
}

QString StatisticsWindow::getFileSize() const{
    return QString::fromStdString(this->statistics->getFileSize());
}




