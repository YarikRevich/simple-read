#include "docxwindow.h"
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <duckx.hpp>
#include <iostream>

void DOCXWindow::exec(){
    // Implement parse of docx file here

    duckx::Document doc(this->fileName.toStdString());

    doc.open();


    std::string src;

    bool i = false;
    for (auto p = doc.paragraphs(); p.has_next(); p.next()) {

            for (auto r = p.runs(); r.has_next(); r.next()) {
                if (r.get_text() != "hello"){
                    r.set_text("it works");
                }

//                r.get_text() += "!";
//                src.append(r.get_text());
            }
            if (!i){
                auto new_p = p.insert_paragraph_after("hello");
                /*for (auto r = new_p.runs(); r.has_next(); r.next()){
                    std::cout << r.get_text() << std::endl;

                }*/

                i = true;
            }
    }
    doc.save();

    std::cout << src << std::endl;

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
