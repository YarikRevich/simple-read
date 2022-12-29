#include "txtwindow.h"

void TXTWindow::exec(){
    // Implement parse of txt file here
}

void TXTWindow::onOpen(){
    QMLWindow::onOpen(QML_TXTWINDOW);
}

void TXTWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

