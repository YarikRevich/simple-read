#include "docxwindow.h"
#include <QHash>
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <QString>
#include <duckx.hpp>
#include <iostream>
#include <stdio.h>
#include "exceptions.h"

void DOCXWindow::onInit(){
    this->doc = duckx::Document(this->fileName.toStdString());
    this->doc.open();
}

void DOCXWindow::onOpen(){
    QMLWindow::onOpen(QML_DOCXWINDOW);
}

void DOCXWindow::onWriteText(QString, int, int) {
    throw Exceptions::NotImplementedLogic();
}

QString DOCXWindow::onReadText(int start, int end){
    std::string result;

    for (auto p = this->doc.paragraphs(); p.has_next(); p.next()) {
        for (auto r = p.runs(); r.has_next(); r.next()) {
            for (auto const& text : r.get_text()){
                result += text;
            }
        }
        result += "\n";
    }
    return QString::fromStdString(result);
}

int DOCXWindow::getContentSize(){
    return 0;
}

void DOCXWindow::onSave(){
}

void DOCXWindow::setFileName(QString fileName){
    BaseWindow::setFileName(fileName);
}
