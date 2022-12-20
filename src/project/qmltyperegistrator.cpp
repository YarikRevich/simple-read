#include "docxwindow.h"
#include "pdfwindow.h"
#include "csvwindow.h"
#include "txtwindow.h"

#include "qmltyperegistrator.h"
#include <mainwindow.h>
#include <menubar.h>
#include <filedialogoptions.h>
#include <settingswindow.h>

QMLTypeRegistrator::QMLTypeRegistrator(QQmlContext* context){
    this->context = context;
}

void QMLTypeRegistrator::exec()
{
    MainWindow *mainWindow = new MainWindow();
    this->context->setContextProperty("MainWindow", mainWindow);

    DOCXWindow *docxWindow = new DOCXWindow();
    this->context->setContextProperty("DOCXWindow", docxWindow);

    PDFWindow *pdfWindow = new PDFWindow();
    this->context->setContextProperty("PDFWindow", pdfWindow);

    TXTWindow *txtWindow = new TXTWindow();
    this->context->setContextProperty("TXTWindow", txtWindow);

    CSVWindow *csvWindow = new CSVWindow();
    this->context->setContextProperty("CSVWindow", csvWindow);

    SettingsWindow *settingsWindow = new SettingsWindow();
    this->context->setContextProperty("SettingsWindow", settingsWindow);

    MenuBar *menuBar = new MenuBar();
    this->context->setContextProperty("MenuBar", menuBar);


}
