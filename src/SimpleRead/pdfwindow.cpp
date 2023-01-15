#include "pdfwindow.h"

#define PDFMM_SHARED true
#include <pdfmm/pdfmm.h>
#include <iostream>

using namespace mm;
void PDFWindow::onInit(){
    PdfMemDocument document;

    document.Load(this->fileName.toStdString());

    for (unsigned int i = 0; i < document.GetPages().GetCount(); i++){
        std::vector<PdfTextEntry> entries;
        document.GetPages().GetPageAt(i).ExtractTextTo(entries);
        for (PdfTextEntry entry : entries){
            this->file_in_buffer += entry.Text;
        };
    };
}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::onSave(){
};

void PDFWindow::onWriteText(QString, int, int){

};

QString PDFWindow::onReadText(int, int){
    return QString::fromStdString(this->file_in_buffer);
};

int PDFWindow::getContentSize(){
    return 0;
}

void PDFWindow::setFileName(QString fileName){
    QMLWindow::setFileName(fileName);
}

