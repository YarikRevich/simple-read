#include "mainwindow.h"
#include "QtQml/qqmlengine.h"
#include "filedialogoptions.h"
#include "settingswindow.h"
#include <QQuickWidget>
#include <QQmlComponent>

void MainWindow::onOpenButton()
{
    qInfo("'Open' button was pressed");
}

void MainWindow::onSettingsButton()
{
    qInfo("'Settings' button was pressed");

    SettingsWindow *settingsWindow = new SettingsWindow();
    settingsWindow->onOpen();
}
