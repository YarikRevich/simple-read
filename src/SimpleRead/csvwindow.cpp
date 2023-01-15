#include "csvwindow.h"
#include <rapidcsv.h>
#include <QVariantMap>

using namespace rapidcsv;

void CSVWindow::onInit(){
    qInfo("CSVWindow is initialized");

    this->doc = Document(this->fileName.toStdString(), rapidcsv::LabelParams(0, -1));

    QVariantMap result;

    for(int cIndex = 0;;cIndex++){
        std::vector<std::string> rawColumnData;
        try{
            rawColumnData = this->doc.GetColumn<std::string>(cIndex);
        } catch (std::out_of_range& e){
            break;
        }
        std::string columnName = this->doc.GetColumnName(cIndex);
        QList<QString> columnData;
        for (auto const& element : rawColumnData){
            columnData.append(QString::fromStdString(element));
        }
        result[QString::fromStdString(columnName)] = columnData;
    }

    this->file_in_buffer = result;
}

void CSVWindow::onOpen() {
    qInfo("CSVWindow is opened");

    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::onSave(){
    qInfo("CSVWindow save event happened");

}

void CSVWindow::onWriteTable(QVariantMap table){
    qInfo("CSVWindow write table event happened");

    this->file_out_buffer = table;
}

QVariantMap CSVWindow::onReadTable() const{
    qInfo("CSVWindow read table event happened");

    return this->file_in_buffer;
}

void CSVWindow::setFileName(QString fileName){
    QMLWindow::setFileName(fileName);
}

