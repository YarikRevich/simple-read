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

void DOCXWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);

    DataView *dataView = new DataView();
    dataView->show();
}

DOCXWindow::~DOCXWindow()
{
    delete ui;
}
