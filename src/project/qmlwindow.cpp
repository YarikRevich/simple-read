#include "qmlwindow.h"

void QMLWindow::onOpen(const char * path){
    QQuickWidget *quickWidget = new QQuickWidget();
    quickWidget->setSource(QUrl(path));
    quickWidget->show();
};
