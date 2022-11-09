#ifndef CSVWINDOW_H
#define CSVWINDOW_H

#include <QWidget>

namespace Ui {
class CSVWindow;
}

class CSVWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CSVWindow(QWidget *parent = nullptr);
    ~CSVWindow();

private:
    Ui::CSVWindow *ui;
};

#endif // CSVWINDOW_H
