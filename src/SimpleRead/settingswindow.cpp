#include "settingswindow.h"
#include "exceptions.h"

#include <QQmlContext>

void SettingsWindow::onOpen(){
    QMLWindow::onOpen(QML_SETTINGSWINDOW);
}

void SettingsWindow::onInit(){
    throw Exceptions::NotImplementedLogic();
}

void SettingsWindow::onSave(){
    throw Exceptions::NotImplementedLogic();
}
