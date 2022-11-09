#include "pdfwindow.h"
#include "ui_pdfwindow.h"

PDFWindow::PDFWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PDFWindow)
{
    ui->setupUi(this);
}

PDFWindow::~PDFWindow()
{
    delete ui;
}
