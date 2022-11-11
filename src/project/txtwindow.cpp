#include "txtwindow.h"
#include "ui_txtwindow.h"

TXTWindow::TXTWindow(QString fileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TXTWindow)
{
    this->fileName = fileName;
    ui->setupUi(this);
}

TXTWindow::~TXTWindow()
{
    delete ui;
}
