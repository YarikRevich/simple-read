#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include "dataview.h"
#include <QWidget>

namespace Ui {
class DOCXWindow;
}

class DOCXWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DOCXWindow(QString fileName, QWidget *parent = nullptr);
    ~DOCXWindow();

    void showEvent(QShowEvent* event);
private:
    void process();

    Ui::DOCXWindow *ui;

    QString fileName;
};

#endif // DOCXWINDOW_H
