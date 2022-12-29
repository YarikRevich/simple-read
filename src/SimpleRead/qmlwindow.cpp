#include "qmlwindow.h"
#include <QQuickView>

void QMLWindow::onOpen(const char * path){
    QQuickView *view = new QQuickView();
    view->setSource(QUrl(path));
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->show();
};
