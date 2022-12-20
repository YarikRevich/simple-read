#include "mainwindow.h"
#include "QtQml/qqmlengine.h"
#include "filedialogoptions.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"
#include <QQuickWidget>
#include <QQmlComponent>

void MainWindow::onOpenButton()
{
    qInfo("'Open' button was pressed");


//    FileDialog *fileDialog = new FileDialog(this);
//    if (!fileDialog->exec()){
//        qFatal("'FileDialog' couldn't find a proper processor for selected type of file");
//    }
}

void MainWindow::onSettingsButton()
{
    qInfo("'Settings' button was pressed");

    SettingsWindow *settingsWindow = new SettingsWindow();
    settingsWindow->onOpen();
}
