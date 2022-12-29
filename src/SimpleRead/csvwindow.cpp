#include "csvwindow.h"
#include <rapidcsv.h>

using namespace rapidcsv;

void CSVWindow::exec(){
    // Implement parse of csv file here

    Document doc(this->fileName.toStdString(), rapidcsv::LabelParams(0, 0));
}

void CSVWindow::onOpen(){
    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

