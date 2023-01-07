#include "csvwindow.h"
#include "exceptions.h"
#include <rapidcsv.h>

using namespace rapidcsv;

void CSVWindow::onInit(){
    this->doc = Document(this->fileName.toStdString(), rapidcsv::LabelParams(0, -1));
}

void CSVWindow::onOpen(){
    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::onSave(){

};

void CSVWindow::onWriteText(QString){
    throw Exceptions::NotImplementedLogic();
};

QString CSVWindow::onReadText(){
    throw Exceptions::NotImplementedLogic();
};

void CSVWindow::onWriteTable(QHash<QString, void *>){

};

QHash<QString, void *> CSVWindow::onReadTable(){
    for(int cIndex = 0;;cIndex++){
        std::vector<std::string> result;
        try{
            result = this->doc.GetColumn<std::string>(cIndex);
        } catch (std::out_of_range& e){
            break;
        }
        for (auto const& element : result){
            qInfo()  << element.c_str();
        }

    }

    return QHash<QString, void *>();
};

void CSVWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}

