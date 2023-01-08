#include "txtwindow.h"
#include "exceptions.h"
#include <fstream>
#include <sstream>

void TXTWindow::onInit(){
    std::ifstream file_in(this->fileName.toStdString(), std::ios_base::in);
    if (!file_in.is_open()){
        qFatal("Couldn't open txt file for input");
    }
    this->file_in_buffer << file_in.rdbuf();
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
};

void TXTWindow::onWriteText(QString text){
    this->file_out_buffer.str(std::string());
    this->file_out_buffer << text.toStdString();
};

QString TXTWindow::onReadText(){
    return QString::fromStdString(this->file_in_buffer.str());
};

void TXTWindow::onWriteTable(QHash<QString, void *>){
    throw Exceptions::NotImplementedLogic();
};

QHash<QString, void *> TXTWindow::onReadTable(){
    throw Exceptions::NotImplementedLogic();
};

void TXTWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

