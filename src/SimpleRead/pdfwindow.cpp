#include "pdfwindow.h"
#include "timer.h"

#define PDFMM_SHARED true

#include <pdfmm/pdfmm.h>
#include <iostream>
#include <fstream>

using namespace mm;
void PDFWindow::onInit(){
    PdfMemDocument document;

    {
        Timer timer;
        document.Load(this->fileName.toStdString());

        for (unsigned int i = 0; i < document.GetPages().GetCount(); i++){
            std::vector<PdfTextEntry> entries;
            document.GetPages().GetPageAt(i).ExtractTextTo(entries);
            for (PdfTextEntry entry : entries){
                this->file_in_buffer += entry.Text;
                this->file_in_buffer += "\n";
            };
        };
    }

    this->setLoadTime(Timer::time);

    std::ifstream file(this->fileName.toStdString(), std::ios::in);
    file.seekg(0, std::ios_base::end);
    double size = file.tellg();
    double megabytes = size / (1024.0 * 1024.0);

    this->setFileSize(std::to_string(megabytes) + " MB");
}

void PDFWindow::onOpen(){
    QMLWindow::onOpen(QML_PDFWINDOW);
}

void PDFWindow::onClose() {
    qInfo("PDFWindow was closed");

    QMLWindow::onClose();
}

QString PDFWindow::onReadText(int, int){
    return QString::fromStdString(this->file_in_buffer);
};

int PDFWindow::getContentSize(){
    return this->file_in_buffer.length();
}

void PDFWindow::setFileName(QString fileName){
    QMLWindow::setFileName(fileName);
}

Statistics* PDFWindow::getStatistics(){
    return this;
};
