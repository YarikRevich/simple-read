#include "pdfwindow.h"

void PDFWindow::exec(){

}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

