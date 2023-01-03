#ifndef QMLTYPEREGISTRATOR_H
#define QMLTYPEREGISTRATOR_H

#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

class QMLTypeRegistrator
{
public:
//    QMLTypeRegistrator(QQmlContext * context);
    QMLTypeRegistrator(QQmlApplicationEngine* engine) : engine{engine}{};

    void exec();
private:
    QQmlApplicationEngine* engine;
};

#endif // QMLTYPEREGISTRATOR_H
