#ifndef MENUBARCREATOR_H
#define MENUBARCREATOR_H

#include <QMenuBar>

class MenuBarCreator
{
public:
    MenuBarCreator();
    QMenuBar *getMenuBar();
private:
    QMenuBar *menuBar;
};

#endif // MENUBARCREATOR_H
