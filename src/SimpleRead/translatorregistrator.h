#ifndef TRANSLATORREGISTRATOR_H
#define TRANSLATORREGISTRATOR_H

//#include <QApplication>
//#include <QTranslator>
#include <QObject>
#include <QQmlApplicationEngine>

class TranslatorRegistrator : public QObject
{
private:
    Q_OBJECT

    QQmlApplicationEngine* engine;
public:
    explicit TranslatorRegistrator(QObject* parent = 0) : QObject(parent){};
    TranslatorRegistrator(QQmlApplicationEngine* engine) : engine{engine}{};
    Q_INVOKABLE void setLanguage(QString);
};

#endif // TRANSLATORREGISTRATOR_H
