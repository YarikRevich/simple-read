#include "dataview.h"
#include <stdexcept>

void DataView::appendChar(char c){
    this->text += c;
};

bool DataView::isCharExistAt(unsigned int i){
    try {
        this->text.at(i);
        return true;
    } catch (std::out_of_range& e){
        return false;
    }
}

char DataView::getChar(unsigned int i){
    std::string rawText = this->text;
    rawText.replace(rawText.begin(), rawText.end(), "\n");

    return rawText[i];
}

QString DataView::getTextAsQString(){
    return QString::fromStdString(this->text);
};

DataView::DataView(std::string t){
    this->text = t;
};

void DataView::saveSnapshot() {
    this->snapshot = new DataView(this->text);
}

