#ifndef TRANSLATORREGISTRATOR_H
#define TRANSLATORREGISTRATOR_H

//#include <QApplication>
//#include <QTranslator>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QTranslator>

class TranslatorRegistrator : public QObject
{
private:
    Q_OBJECT

    QQmlApplicationEngine* engine;
    QTranslator* translator;
public:
    explicit TranslatorRegistrator(QObject* parent = 0) : QObject(parent){};
    TranslatorRegistrator(QQmlApplicationEngine* engine) : engine{engine}{
        this->translator = new QTranslator(engine->rootObjects()[0]);
    };
    Q_INVOKABLE void setLanguage(QString);
};

#endif // TRANSLATORREGISTRATOR_H
