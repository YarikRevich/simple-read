#include "csvwindow.h"

void CSVWindow::exec(){

}

void CSVWindow::onOpen(){
    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

