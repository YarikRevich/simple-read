#include "docxwindow.h"
#include "ui_docxwindow.h"

DOCXWindow::DOCXWindow(QString fileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DOCXWindow)
{
    this->fileName = fileName;
    ui->setupUi(this);

}

DOCXWindow::~DOCXWindow()
{
    delete ui;
}
