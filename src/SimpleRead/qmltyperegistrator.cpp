#include "docxwindow.h"
#include "pdfwindow.h"
#include "csvwindow.h"
#include "translatorregistrator.h"
#include "txtwindow.h"
#include "statisticswindow.h"
#include "csvwindowmodel.h"
#include "exceptions.h"
#include "qmltyperegistrator.h"
#include "settingswindow.h"

void QMLTypeRegistrator::exec() const
{
    qInfo("QMLTypeRegistrator is initialized!");

    QQmlContext* context = this->engine->rootContext();

    DOCXWindow *docxWindow = new DOCXWindow();
    context->setContextProperty("DOCXWindow", docxWindow);

    PDFWindow *pdfWindow = new PDFWindow();
    context->setContextProperty("PDFWindow", pdfWindow);

    TXTWindow *txtWindow = new TXTWindow();
    context->setContextProperty("TXTWindow", txtWindow);

    CSVWindow *csvWindow = new CSVWindow();
    context->setContextProperty("CSVWindow", csvWindow);

    CSVWindowModel *csvWindowModel = new CSVWindowModel(csvWindow);
    context->setContextProperty("CSVWindowModel", csvWindowModel);

    SettingsWindow *settingsWindow = new SettingsWindow();
    context->setContextProperty("SettingsWindow", settingsWindow);

    StatisticsWindow *statisticsWindow = new StatisticsWindow();
    context->setContextProperty("StatisticsWindow", statisticsWindow);

    Exceptions *exceptions = Exceptions::getInstance();
    context->setContextProperty("Exceptions", exceptions);

    TranslatorRegistrator *translatorRegistrator = new TranslatorRegistrator(this->engine);
    context->setContextProperty("TranslatorRegistrator", translatorRegistrator);
}
