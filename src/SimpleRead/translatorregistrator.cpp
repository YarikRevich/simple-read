#include "translatorregistrator.h"
#include <iostream>
#include <QApplication>
#include <QTranslator>

void TranslatorRegistrator::setLanguage(QString language){
    QTranslator translator;

    if (translator.load(":/project_" + language)) {
        QApplication::instance()->installTranslator(&translator);
        this->engine->retranslate();
    }else{
        qFatal("Failed to load language pack");
    }
}
