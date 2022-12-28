#include "docxwindow.h"
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <duckx.hpp>
#include <iostream>

//DOCXWindow::DOCXWindow(QString fileName, QWidget *parent) :
//    FileWindow(parent),
//    ui(new Ui::DOCXWindow)
//{
//    this->fileName = fileName;
//    this->dataView = new DataView(this);
//    this->process();

//    ui->setupUi(this);
//}

void DOCXWindow::exec(){
    duckx::Document doc(this->fileName.toStdString());

    doc.open();


    std::string src;
    for (auto p = doc.paragraphs(); p.has_next(); p.next()) {
            for (auto r = p.runs(); r.has_next(); r.next()) {
                src.append(r.get_text());
            }
    }

    /*QLabel *label = new QLabel(QString::fromStdString(src).toUtf8(), this);
    label->setGeometry(100, 100, 1280, 500);
    label->show();*/

//    this->dataView->show();

}

void DOCXWindow::onOpen(){
    QMLWindow::onOpen(QML_DOCXWINDOW);
}

void DOCXWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}
