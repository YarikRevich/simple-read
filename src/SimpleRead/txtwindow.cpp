#include "txtwindow.h"
#include <fstream>
#include <sstream>
#include "timer.h"

void TXTWindow::onInit(){
    std::ifstream file_in(this->fileName.toStdString(), std::ios_base::in);
    if (!file_in.is_open()){
        qFatal("Couldn't open txt file for input");
    }
    {
        Timer timer;
        char buf[1024 * 1024];
        this->file_in_buffer << file_in.rdbuf()->pubsetbuf(buf, 256 * 1024);
    }

    this->setLoadTime(Timer::time);

    double size = file_in.tellg();
    double megabytes = size / (1024.0 * 1024.0);

    this->setFileSize(std::to_string(megabytes) + " MB");

    qInfo("txt file is read");
}

void TXTWindow::onOpen(){
    QMLWindow::onOpen(QML_TXTWINDOW);
}

void TXTWindow::onClose() {
    qInfo("TXTWindow was closed");

    QMLWindow::onClose();
}

void TXTWindow::onSave(){
    std::ofstream file_out(this->fileName.toStdString(), std::ios_base::out | std::ios_base::trunc);
    if (!file_out.is_open()){
        qFatal("Couldn't open txt file for output");
    }
    file_out << this->file_out_buffer.str();
}

void TXTWindow::onWriteText(QString text, int start, int end){
    this->file_out_buffer.str(std::string());
    this->file_out_buffer << text.toStdString();
}

QString TXTWindow::onReadText(int start, int end){
    return QString::fromStdString(this->file_in_buffer.str().substr(start, end));
}

int TXTWindow::getContentSize() {
    return this->file_in_buffer.str().size();
}

void TXTWindow::setFileName(QString fileName){
    QMLWindow::setFileName(fileName);
}

Statistics* TXTWindow::getStatistics(){
    return this;
}
