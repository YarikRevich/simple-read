#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QObject
{
public:
    explicit MenuBar (QObject* parent = 0) : QObject(parent) {}

    Q_INVOKABLE void onAutoSave();
};

#endif // MENUBAR_H
