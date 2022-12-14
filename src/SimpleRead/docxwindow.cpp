#include "docxwindow.h"
#include <QHash>
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <QString>
#include <duckx.hpp>
#include <iostream>
#include <stdio.h>

void DOCXWindow::onInit(){
    this->doc = duckx::Document(this->fileName.toStdString());
    this->doc.open();

    for (auto p = this->doc.tables(); p.has_next(); p.next()){
        for (auto r = p.rows(); r.has_next(); r.next()){
            for (auto c = r.cells(); c.has_next(); c.next()){
                for (auto w = c.paragraphs(); w.has_next(); w.next()){
                    for (auto q = w.runs(); q.has_next(); q.next()) {
                        qInfo() << q.get_text().c_str();
                    }
                }
            }
        }
    }

    for (auto p = this->doc.paragraphs(); p.has_next(); p.next()) {
        for (auto r = p.runs(); r.has_next(); r.next()) {
            for (auto const& text : r.get_text()){
                this->appendChar(text);
            }
        }
        this->appendChar('\n');
    }
//    qInfo() << this->text.c_str();
    this->saveSnapshot();
}

void DOCXWindow::onOpen(){
    QMLWindow::onOpen(QML_DOCXWINDOW);
}

//void DOCXWindow::onSave(){
//}

void DOCXWindow::onWriteText(QString text) {

}

QString DOCXWindow::onReadText(){
    return DataView::getTextAsQString();
}

void DOCXWindow::onWriteTable(QHash<QString, void *>){

};

QHash<QString, void *> DOCXWindow::onReadTable(){
    return QHash<QString, void *>();
};

void DOCXWindow::onSave(){
    int rIndex = 0;
//    for (auto p = this->doc.tables(); p.has_next(); p.next()){
//        for (auto r = p.rows(); r.has_next(); r.next()){
//            for (auto c = r.cells(); r.has_next(); r.next()){
//                for (auto w = c.paragraphs(); c.has_next(); c.next()){
//                    for (auto q = w.runs(); w.has_next(); w.next()) {
//                        qInfo() << q.get_text().c_str();
//                    }
//                }
//            }
//        }
//    }
    for (auto p = this->doc.paragraphs(); p.has_next(); p.next()) {
        for (auto r = p.runs(); r.has_next(); r.next()) {

//            const std::string src = r.get_text();
            for (auto const& text : r.get_text()){
//                qInfo() << text << " " << rIndex << " " << this->text.length();
                rIndex++;
            }
//            qInfo() << r.get_text().at(125);

//                wprintf(L"%ls\n", wtext);
//                  qInfo() << this->isCharExistAt(rIndex);
//                this->getChar(rIndex);
//                qInfo(wtext);


//            qInfo() << rIndex << "TU";
//            rIndex++;
        }
        rIndex++;
    }
    this->doc.save();
}

void DOCXWindow::setFileName(QString fileName){
    FileWindow::setFileName(fileName);
}
