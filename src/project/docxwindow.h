#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include <QWidget>

namespace Ui {
class DOCXWindow;
}

class DOCXWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DOCXWindow(QWidget *parent = nullptr);
    ~DOCXWindow();

private:
    Ui::DOCXWindow *ui;
};

#endif // DOCXWINDOW_H
