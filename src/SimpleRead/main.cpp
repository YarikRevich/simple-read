#include "mainwindow.h"
#include "qmltyperegistrator.h"
#include "logger.h"
#include "database.h"
#include "docxwindow.h"
#include "settingswindow.h"
#include "globalqmlengine.h"

#include <QApplication>
#include <QLocale>
#include <QQmlApplicationEngine>
#include <QTranslator>
#include <QQmlEngine>
#include <QQuickView>
#include <QQuickWindow>
#include <QString>
#include <QQmlComponent>
#include <QIcon>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QCoreApplication::setApplicationName( QString("SimpleRead") );
    QCoreApplication::setApplicationVersion("1.0");
    QApplication app(argc, argv);

    Logger logger;
    qInstallMessageHandler(loggingHandler);

//    QQmlApplicationEngine* engine = QMLEngineWrapper::instance();
    QQmlApplicationEngine engine(QML_MAINWINDOW);
    GlobalQMLEngine::setEngine(&engine);

    QMLTypeRegistrator qmlTypeRegistrator(&engine);
    qmlTypeRegistrator.exec();

    return app.exec();
}
