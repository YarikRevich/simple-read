#include "docxwindow.h"
#include "ui_docxwindow.h"

DOCXWindow::DOCXWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DOCXWindow)
{
    ui->setupUi(this);
}

DOCXWindow::~DOCXWindow()
{
    delete ui;
}
