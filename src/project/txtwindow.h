#ifndef TXTWINDOW_H
#define TXTWINDOW_H

#include "filewindow.h"

#include <QWidget>

namespace Ui {
class TXTWindow;
}

class TXTWindow : public FileWindow
{
    Q_OBJECT

public:
    explicit TXTWindow(QString fileName, QWidget *parent = nullptr);
    ~TXTWindow();

private:
    Ui::TXTWindow *ui;

    QString fileName;
};

#endif // TXTWINDOW_H
