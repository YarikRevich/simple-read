#include "txtwindow.h"
#include <fstream>
#include <sstream>
#include "timer.h"
#include "exceptions.h"

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

    qInfo("txt file is read");
}

void TXTWindow::onOpen(){
    QMLWindow::onOpen(QML_TXTWINDOW);
}

void TXTWindow::onSave(){
    std::ofstream file_out(this->fileName.toStdString(), std::ios_base::out | std::ios_base::trunc);
    if (!file_out.is_open()){
        qFatal("Couldn't open txt file for output");
    }
    file_out << this->file_out_buffer.str();
}

void TXTWindow::onWriteText(QString text, int start, int end){
//    this->file_out_buffer.str(std::string());
    std::string temp_str = this->file_out_buffer.str();
//    temp_str.insert(1, 2, )

    this->file_out_buffer << text.toStdString();
}

QString TXTWindow::onReadText(int start, int end){
    emit Exceptions::getInstance()->error("it works");
    return QString::fromStdString(this->file_in_buffer.str().substr(start, end));
}

int TXTWindow::getContentSize() {
    return this->file_in_buffer.str().size();
}

void TXTWindow::setFileName(QString fileName){
    BaseWindow::setFileName(fileName);
}
