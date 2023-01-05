#include "qmlwindow.h"
#include <QQuickView>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "globalqmlengine.h"
#include <QTranslator>

void QMLWindow::onOpen(const char * path){
    QQuickView *view = new QQuickView(GlobalQMLEngine::engine, 0);

    view->setSource(QUrl(path));
    view->setResizeMode(QQuickView::SizeRootObjectToView);

    QApplication *app = static_cast<QApplication *>(QApplication::instance());
    QScreen * primaryScreen = app->primaryScreen();
    QSize primaryScreenSize = primaryScreen->availableSize();
    view->setMinimumHeight(40 * primaryScreenSize.height() / 100);
    view->setMinimumWidth(40 * primaryScreenSize.width() / 100);

    view->show();
};
