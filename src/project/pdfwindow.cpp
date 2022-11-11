#include "pdfwindow.h"
#include "ui_pdfwindow.h"

PDFWindow::PDFWindow(QString fileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PDFWindow)
{
    this->fileName = fileName;
    ui->setupUi(this);
}

PDFWindow::~PDFWindow()
{
    delete ui;
}
