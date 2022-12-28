#include "mainwindow.h"
#include "qmltyperegistrator.h"
#include "translatorregistrator.h"
#include "logger.h"

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
    QApplication app(argc, argv);

    Logger logger;
    qInstallMessageHandler(loggingHandler);

    TranslatorRegistrator translatorRegistrator;
    translatorRegistrator.exec();

    QQmlApplicationEngine engine(QML_MAINWINDOW);

    QMLTypeRegistrator qmlTypeRegistrator(engine.rootContext());
    qmlTypeRegistrator.exec();

    return app.exec();
}
