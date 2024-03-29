#include "csvwindow.h"
#include "timer.h"

#include <rapidcsv.h>
#include <QVariantMap>
#include <fstream>

using namespace rapidcsv;

void CSVWindow::onInit(){
    qInfo("CSVWindow is initialized");

    {
        Timer timer;
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

        this->file_in_buffer = result;
        this->file_out_buffer = result;
        }
    }

    this->setLoadTime(Timer::time);

    std::ifstream file(this->fileName.toStdString(), std::ios::in);
    file.seekg(0, std::ios_base::end);
    double size = file.tellg();
    double megabytes = size / (1024.0 * 1024.0);

    this->setFileSize(std::to_string(megabytes) + " MB");
}

void CSVWindow::onOpen() {
    qInfo("CSVWindow is opened");

    QMLWindow::onOpen(QML_CSVWINDOW);
}

void CSVWindow::onClose() {
    qInfo("CSVWindow was closed");

    QMLWindow::onClose();
}

void CSVWindow::onSave(){
    qInfo("CSVWindow save event happened");

    for (auto column : this->file_out_buffer.keys()){
        int rowIndex = 0;
        for (auto row : this->file_out_buffer[column].toList()){
            this->doc.SetCell(this->doc.GetColumnIdx(column.toStdString()), rowIndex, row.toString().toStdString());
            rowIndex++;
        }
    }
    this->doc.Save();
}

void CSVWindow::onWriteTable(QVariantMap table){
    qInfo("CSVWindow write table event happened");

    this->file_out_buffer = table;
    this->file_in_buffer = table;
}

QVariantMap CSVWindow::onReadTable() const{
    qInfo("CSVWindow read table event happened");

    return this->file_in_buffer;
}

void CSVWindow::setFileName(QString fileName){
    QMLWindow::setFileName(fileName);
}

Statistics* CSVWindow::getStatistics(){
    return this;
}

