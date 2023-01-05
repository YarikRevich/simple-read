#include "txtwindow.h"
#include <fstream>
#include <sstream>

void TXTWindow::onInit(){
    // Implement parse of txt file here

    std::ifstream file(this->fileName.toStdString());
    if (!file.is_open()){
        qFatal("Couldn't open txt file");
    }
    std::stringstream data;
    data << file.rdbuf();
    file.close();

    for (auto const& d : data.str()){

    }
}

void TXTWindow::onOpen(){
    QMLWindow::onOpen(QML_TXTWINDOW);
}


void TXTWindow::onSave(){

};

void TXTWindow::onWriteText(QString){

};

QString TXTWindow::onRead(){
    return NULL;
};

void TXTWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

