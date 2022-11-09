#include "menubarcreator.h"

MenuBarCreator::MenuBarCreator()
{
    this->menuBar = new QMenuBar();
    QMenu *fileMenu=this->menuBar->addMenu("File");
    QAction* openAction=fileMenu->addAction("Open");
    QAction* saveAction=fileMenu->addAction("Save");
    QAction* printAction=fileMenu->addAction("Print");

    QMenu *viewMenu=this->menuBar->addMenu("View");
    QAction* zoomInAction=viewMenu->addAction("Zoom In");
    QAction* zoomOutAction=viewMenu->addAction("Zoom Out");

    QMenu *aboutMenu=this->menuBar->addMenu("About");
    QAction* action=aboutMenu->addAction("Undo");
}

QMenuBar *MenuBarCreator::getMenuBar(){
    return this->menuBar;
}
