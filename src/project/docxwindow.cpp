#include "docxwindow.h"
#include "ui_docxwindow.h"

DOCXWindow::DOCXWindow(QString fileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DOCXWindow)
{
    this->fileName = fileName;
    ui->setupUi(this);
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
