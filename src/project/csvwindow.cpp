#include "csvwindow.h"
#include "ui_csvwindow.h"

CSVWindow::CSVWindow(QString fileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSVWindow)
{
    this->fileName = fileName;
    ui->setupUi(this);
}

CSVWindow::~CSVWindow()
{
    delete ui;
}
