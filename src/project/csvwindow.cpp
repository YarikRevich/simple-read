#include "csvwindow.h"
#include "ui_csvwindow.h"

CSVWindow::CSVWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSVWindow)
{
    ui->setupUi(this);
}

CSVWindow::~CSVWindow()
{
    delete ui;
}
