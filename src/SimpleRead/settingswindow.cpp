#include "settingswindow.h"
#include <QQmlContext>
#include "exceptions.h"

void SettingsWindow::onOpen(){
    QMLWindow::onOpen(QML_SETTINGSWINDOW);
}

void SettingsWindow::onInit(){
    throw Exceptions::NotImplementedLogic();
};

void SettingsWindow::onSave(){
    throw Exceptions::NotImplementedLogic();
};
