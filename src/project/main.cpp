#include "mainwindow.h"
#include "qmltyperegistrator.h"
#include "translatorregistrator.h"

#include <QApplication>
#include <QLocale>
#include <QQmlApplicationEngine>
#include <QTranslator>
#include <QQmlEngine>
#include <QQuickView>
#include <QQuickWindow>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QApplication app(argc, argv);

    TranslatorRegistrator translatorRegistrator;
    translatorRegistrator.exec();

    QQmlApplicationEngine engine(QML_MAINWINDOW);

    QMLTypeRegistrator qmlTypeRegistrator(engine.rootContext());
    qmlTypeRegistrator.exec();

    return app.exec();
}
