#include "pdfwindow.h"

#define PDFMM_SHARED true
#include <pdfmm/pdfmm.h>
#include <iostream>

using namespace mm;
void PDFWindow::exec(){
    PdfMemDocument document;
    PdfPainter painter;

    document.Load(this->fileName.toStdString());
    painter.AddText("it works");
}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

