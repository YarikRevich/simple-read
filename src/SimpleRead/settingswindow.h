#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "qmlwindow.h"

#define QML_SETTINGSWINDOW "qrc:/settingswindow.qml"

class SettingsWindow : public QObject, public QMLWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QObject* = 0){};
    Q_INVOKABLE void onOpen();
};

#endif // SETTINGSWINDOW_H
