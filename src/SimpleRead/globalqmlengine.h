#ifndef GLOBALQMLENGINE_H
#define GLOBALQMLENGINE_H

#include <QQmlApplicationEngine>

/*
 * \brief Global instance of QQmlApplicationEngine for internal usage
*/
class GlobalQMLEngine
{

public:
    static QQmlApplicationEngine* engine;

    static void setEngine(QQmlApplicationEngine* engine){
        GlobalQMLEngine::engine = engine;
    }

    GlobalQMLEngine() = default;
};

#endif // GLOBALQMLENGINE_H
