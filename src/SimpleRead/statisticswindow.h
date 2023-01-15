#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include "qmlwindow.h"
#include <QObject>


class StatisticsWindow : public QObject, public QMLWindow
{
private:
    Q_OBJECT
public:
    explicit StatisticsWindow(QObject * parent = NULL) : QObject(parent){};


};

#endif // STATISTICSWINDOW_H
