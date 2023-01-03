#include "docxwindow.h"
#include "pdfwindow.h"
#include "csvwindow.h"
#include <translatorregistrator.h>
#include "txtwindow.h"

#include "qmltyperegistrator.h"
#include <mainwindow.h>
#include <menubar.h>
#include <filedialogoptions.h>
#include <settingswindow.h>

void QMLTypeRegistrator::exec()
{
    qInfo("QMLTypeRegistrator is initialized!");

    QQmlContext* context = this->engine->rootContext();

    MainWindow *mainWindow = new MainWindow();
    context->setContextProperty("MainWindow", mainWindow);

    DOCXWindow *docxWindow = new DOCXWindow();
    context->setContextProperty("DOCXWindow", docxWindow);

    PDFWindow *pdfWindow = new PDFWindow();
    context->setContextProperty("PDFWindow", pdfWindow);

    TXTWindow *txtWindow = new TXTWindow();
    context->setContextProperty("TXTWindow", txtWindow);

    CSVWindow *csvWindow = new CSVWindow();
    context->setContextProperty("CSVWindow", csvWindow);

    SettingsWindow *settingsWindow = new SettingsWindow();
    context->setContextProperty("SettingsWindow", settingsWindow);

    MenuBar *menuBar = new MenuBar();
    context->setContextProperty("MenuBar", menuBar);

    TranslatorRegistrator *translatorRegistrator = new TranslatorRegistrator(this->engine);
    context->setContextProperty("TranslatorRegistrator", translatorRegistrator);
}
