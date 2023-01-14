#include "pdfwindow.h"

#define PDFMM_SHARED true
#include <pdfmm/pdfmm.h>
#include <iostream>

using namespace mm;
void PDFWindow::onInit(){
    PdfMemDocument document;
    PdfPainter painter;

    document.Load(this->fileName.toStdString());
    document.GetPages();
}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::onSave(){
};

void PDFWindow::onWriteText(QString, int, int){

};

QString PDFWindow::onReadText(int, int){
    return NULL;
};

int PDFWindow::getContentSize(){
    return 0;
}

void PDFWindow::setFileName(QString fileName){
    BaseWindow::setFileName(fileName);
}

