#include "docxwindow.h"
#include "ui_docxwindow.h"
#include <QScrollArea>
#include <duckx.hpp>
#include <iostream>

DOCXWindow::DOCXWindow(QString fileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DOCXWindow)
{   
    this->fileName = fileName;
    ui->setupUi(this);
    this->process();
}

void DOCXWindow::process(){


    duckx::Document doc(this->fileName.toStdString());

    doc.open();


    for (auto p = doc.paragraphs(); p.has_next(); p.next()) {
            for (auto r = p.runs(); r.has_next(); r.next()) {
                std::cout << r.get_text() << std::endl;
            }
    }

}

DOCXWindow::~DOCXWindow()
{
    delete ui;
}
