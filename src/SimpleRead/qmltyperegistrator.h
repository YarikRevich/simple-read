#ifndef QMLTYPEREGISTRATOR_H
#define QMLTYPEREGISTRATOR_H

#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

class QMLTypeRegistrator
{
public:
    QMLTypeRegistrator(QQmlContext * context);

    void exec();
private:
    QQmlContext* context;
};

#endif // QMLTYPEREGISTRATOR_H
