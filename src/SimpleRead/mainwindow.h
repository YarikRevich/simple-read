#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QQuickWidget>
#include <QMenuBar>
#include <QObject>

#define QML_MAINWINDOW "qrc:/mainwindow.qml"

class MainWindow : public QObject
{
    Q_OBJECT

public:
    explicit MainWindow (QObject* parent = 0) : QObject(parent) {}

    Q_INVOKABLE void onOpenButton();
    Q_INVOKABLE void onSettingsButton();
};
#endif // MAINWINDOW_H
