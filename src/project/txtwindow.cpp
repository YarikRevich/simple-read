#include "txtwindow.h"

void TXTWindow::exec(){

}

void TXTWindow::onOpen(){
    QMLWindow::onOpen(QML_TXTWINDOW);
}

void TXTWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

