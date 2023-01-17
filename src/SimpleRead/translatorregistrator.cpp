#include "translatorregistrator.h"

#include <QApplication>
#include <QTranslator>

TranslatorRegistrator::TranslatorRegistrator(QQmlApplicationEngine *engine) : engine{engine}{
    this->translator = new QTranslator(engine->rootObjects()[0]);
}

void TranslatorRegistrator::setLanguage(QString language){
    if (this->translator->load(":/project_" + language)) {
        QApplication::instance()->installTranslator(this->translator);
        this->engine->retranslate();
    }else{
        qFatal("Failed to load language pack");
    }
}
