#include "pdfwindow.h"

#define PDFMM_SHARED true
#include <pdfmm/pdfmm.h>
#include <iostream>

using namespace mm;
void PDFWindow::onInit(){
    PdfMemDocument document;
    PdfPainter painter;

    document.Load(this->fileName.toStdString());
    painter.AddText("it works");


}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::onSave(){

};

void PDFWindow::onWriteText(QString){

};

QString PDFWindow::onReadText(){
    return NULL;
};

void PDFWindow::onWriteTable(QHash<QString, void *>){

};

QHash<QString, void *> PDFWindow::onReadTable(){
    return QHash<QString, void *>();
};

void PDFWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

