#include "docxwindow.h"
#include "exceptions.h"
#include "timer.h"

#include <duckx.hpp>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <QHash>
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <QString>

void DOCXWindow::onInit(){
    {
        Timer timer;
        this->doc = duckx::Document(this->fileName.toStdString());
        this->doc.open();

        for (auto p = this->doc.paragraphs(); p.has_next(); p.next()) {
            for (auto r = p.runs(); r.has_next(); r.next()) {
                for (auto const& text : r.get_text()){
                    this->file_in_buffer += text;
                }
            }
            this->file_in_buffer += "\n";
        }
    }
    this->setLoadTime(Timer::time);

    std::ifstream file(this->fileName.toStdString(), std::ios::in);
    file.seekg(0, std::ios_base::end);
    double size = file.tellg();
    double megabytes = size / (1024.0 * 1024.0);

    this->setFileSize(std::to_string(megabytes) + " MB");

    Exceptions::LimitedFunctionality(true);
}

void DOCXWindow::onOpen(){
    QMLWindow::onOpen(QML_DOCXWINDOW);
}

void DOCXWindow::onClose() {
    qInfo("DOCXWindow was closed");

    QMLWindow::onClose();
}

QString DOCXWindow::onReadText(int start, int end){
    return QString::fromStdString(this->file_in_buffer);
}

int DOCXWindow::getContentSize(){
    return this->file_in_buffer.length();
}

void DOCXWindow::setFileName(QString fileName){
    QMLWindow::setFileName(fileName);
}

Statistics* DOCXWindow::getStatistics(){
    return this;
};
