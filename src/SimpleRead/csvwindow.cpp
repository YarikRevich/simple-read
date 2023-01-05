#include "csvwindow.h"
#include <rapidcsv.h>

using namespace rapidcsv;

void CSVWindow::onInit(){
    // Implement parse of csv file here

    Document doc(this->fileName.toStdString(), rapidcsv::LabelParams(0, 0));
}

void CSVWindow::onOpen(){
    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::onSave(){

};

void CSVWindow::onWriteText(QString){

};

QString CSVWindow::onRead(){
    return NULL;
};

void CSVWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

