#include "pdfwindow.h"

#define PDFMM_SHARED true
#include <pdfmm/pdfmm.h>
#include <iostream>

using namespace mm;
void PDFWindow::exec(){
    PdfMemDocument document;

    document.Load(this->fileName.toStdString());
}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

