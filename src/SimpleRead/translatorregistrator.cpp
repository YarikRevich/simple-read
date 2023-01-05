#include "translatorregistrator.h"
#include <iostream>
#include <QApplication>
#include <QTranslator>

void TranslatorRegistrator::setLanguage(QString language){
    if (this->translator->load(":/project_" + language)) {
        QApplication::instance()->installTranslator(this->translator);
        this->engine->retranslate();
    }else{
        qFatal("Failed to load language pack");
    }
}
