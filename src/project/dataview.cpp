#include "dataview.h"

#include <QLabel>

DataView::DataView(QWidget *parent)
{
  this->parent = parent;
}

void DataView::addParagraph(QString paragraph){
    QLabel label(paragraph, this->parent);
};

void DataView::show(){
    this->parent->show();
};
