#include "csvwindow.h"

void CSVWindow::exec(){
    // Implement parse of csv file here
}

void CSVWindow::onOpen(){
    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

