#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include "qmlwindow.h"
#include "statistics.h"

#include <QObject>

#define QML_STATISTICSWINDOW "qrc:/statisticswindow.qml"

class StatisticsWindow : public QObject, public QMLWindow
{
private:
    Q_OBJECT

    Statistics *statistics;
public:
    explicit StatisticsWindow(QObject * parent = NULL) : QObject(parent){}

    Q_INVOKABLE void setStatistics(Statistics* statistics);

    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE QString getLoadTime() const;

    Q_INVOKABLE QString getFileSize() const;
};

#endif // STATISTICSWINDOW_H
